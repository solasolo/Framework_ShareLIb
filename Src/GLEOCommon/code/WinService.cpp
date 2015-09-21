#include "WinService.h"
#include "WinException.h"
#include "WinFuncs.h"
#include "WinEventLogger.h"
#include "CommonFuncs.h"

#include <winsvc.h>
#include <shellapi.h>
#include <comutil.h>

#include <algorithm>

namespace Win32Lib
{
	SystemConsoleManager::SystemConsoleManager()
	{
		Handle = 0;

		Handle = OpenSCManager(NULL, NULL, SC_MANAGER_ALL_ACCESS);
		if(Handle == 0) 
		{
			throw WinException(_T("Creating System Console Manager"));
		}
	}

	SystemConsoleManager::~SystemConsoleManager()
	{
		if(Handle != 0)
		{
			CloseServiceHandle(Handle);
		}
	}

	SC_HANDLE SystemConsoleManager::GetHandle()
	{
		return Handle;
	}
}

namespace Win32Lib
{
	ServiceManager::ServiceManager(WinService* service)
	{
		Service = service;
		ServiceName = Service->getName();	
		Handle = 0;
	}

	ServiceManager::ServiceManager(wstring service_name)
	{
		Service = NULL;
		ServiceName = service_name;
		OpenHandle();
	}

	ServiceManager::~ServiceManager()
	{
		CloseHandle();
	}

	void ServiceManager:: OpenHandle()
	{
		CloseHandle();

		Handle = OpenService(SCM.GetHandle(), ServiceName.c_str(), SERVICE_ALL_ACCESS);
		if (Handle==0) 
		{
			throw WinException(wstring(L"Open Service") + ServiceName);
		}
	}

	void ServiceManager::CloseHandle()
	{
		if(Handle != 0)
		{
			if(!CloseServiceHandle(Handle))
			{
				throw WinException(L"Close Service Handle");
			}

			Handle = 0;
		}
	}

	void ServiceManager::Uninstall()
	{
		OpenHandle();

		if(!DeleteService(Handle)) 
		{
			throw WinException(_T("Uninstall Service ") + ServiceName);
		}
	}

	void ServiceManager::Install(wstring Path)
	{  
		CloseHandle();

		Handle = CreateService
		( 
			SCM.GetHandle(),	
			ServiceName.c_str(),			
			ServiceName.c_str(),			
			SERVICE_ALL_ACCESS,       
			SERVICE_WIN32_OWN_PROCESS | SERVICE_INTERACTIVE_PROCESS ,
			SERVICE_AUTO_START,     
			SERVICE_ERROR_NORMAL,      
			Path.c_str(),			
			NULL,                     
			NULL,                     
			NULL,                     
			NULL,                     
			NULL
		);               

		if (Handle == 0) 
		{
			throw WinException(_T("Install Service ") + ServiceName);
		}
	}

	void ServiceManager::Install() 
	{  
		if(Service)
		{
			CloseHandle();

			Handle = CreateService
			( 
				SCM.GetHandle(),	
				Service->getName().c_str(),			
				Service->getDisplayName().c_str(),			
				SERVICE_ALL_ACCESS,       
				SERVICE_WIN32_OWN_PROCESS | SERVICE_INTERACTIVE_PROCESS ,
				SERVICE_AUTO_START,     
				SERVICE_ERROR_NORMAL,      
				GetCurrentExecPath().c_str(),			
				NULL,                     
				NULL,                     
				NULL,
				NULL,                     
				NULL
			);

			if (Handle == 0) 
			{
				throw WinException(_T("Install Service ") + Service->getName());
			}
		}
		else
			throw Exception(_T("NO Service"), _T("Install Service"));
	}

	void ServiceManager::Stop() 
	{ 
		if(Handle != 0)
		{
			SERVICE_STATUS status;

			if(!ControlService(Handle, SERVICE_CONTROL_STOP, &status))
			{			
				throw WinException(_T("Stoping Service") + ServiceName);
			}
		}
		else
		{
		}
	}

	void ServiceManager::Start(int nArg, LPTSTR* pArg)
	{
		if(Handle != 0)
		{
			if(!StartService(Handle, nArg, (const TChar**)pArg))
			{
				throw WinException(_T("Stoping Service ") + ServiceName);
			}
		}
		else
		{
		}
	}

	void ServiceManager::RegisterService()
	{
		class Entries 
		{
		public:		
			SERVICE_TABLE_ENTRY* ServiceEntries;
			wstring* ServiceNames;

			Entries(int count)
			{
				ServiceEntries = NULL;
				ServiceNames = NULL;

				ServiceEntries = new SERVICE_TABLE_ENTRY[count + 1];
				ServiceNames = new wstring[count];
				memset((void*)ServiceEntries, 0, sizeof(SERVICE_TABLE_ENTRY) * (count + 1)); 
			};

			~Entries()
			{
				if(ServiceNames) delete[] ServiceNames;
				if(ServiceEntries) delete[] ServiceEntries;
			};

			void Add(int pos, WinService* svc)
			{
				ServiceNames[pos] = svc->getName();
				ServiceEntries[pos].lpServiceName = (TChar*)ServiceNames[pos].c_str();
				ServiceEntries[pos].lpServiceProc = WinService::ServiceMain;
			};
		};

		int ServiceCount = WinService::ServiceList->size();
		if(ServiceCount >0)
		{
			Entries TheEntries(ServiceCount);

			for(int i = 0; i < ServiceCount; i++)
			{
				WinService* svc = (*WinService::ServiceList)[i];
				TheEntries.Add(i, svc);	
			}

			if(!StartServiceCtrlDispatcher(TheEntries.ServiceEntries))
			{
				throw WinException(_T("Starting Services Control Dispatcher"));
			}
		}
	}
}

namespace Win32Lib
{
	vector<WinService*>* WinService::ServiceList = NULL;

	WinService::WinService()
	{
		Status.dwServiceType        = SERVICE_WIN32; 
		Status.dwCurrentState       = SERVICE_START_PENDING; 
		Status.dwControlsAccepted   = SERVICE_ACCEPT_STOP | SERVICE_ACCEPT_SHUTDOWN | SERVICE_ACCEPT_PAUSE_CONTINUE; 
		Status.dwWin32ExitCode      = 0; 
		Status.dwServiceSpecificExitCode = 0; 
		Status.dwCheckPoint         = 0; 
		Status.dwWaitHint           = 0; 

		ServiceProc = NULL;

		Regist();
	}

	void WinService::ServiceDispatch(int code)
	{
		switch(code) 
		{
			case SERVICE_CONTROL_STOP:
				if(Stop())
				{
					Status.dwWin32ExitCode = 0; 
					Status.dwCurrentState  = SERVICE_STOPPED; 
					Status.dwCheckPoint    = 0; 
					Status.dwWaitHint      = 0;
				}
				break;

			case SERVICE_CONTROL_SHUTDOWN:
				if(Shutdown())
				{
					Status.dwWin32ExitCode = 0; 
					Status.dwCurrentState  = SERVICE_STOPPED; 
					Status.dwCheckPoint    = 0; 
					Status.dwWaitHint      = 0;
				}
				break;

			case SERVICE_CONTROL_PAUSE:
				if(Pause())
					Status.dwCurrentState = SERVICE_PAUSED; 
				break;

			case SERVICE_CONTROL_CONTINUE:
				if(Resume())
				{
					Status.dwCurrentState = SERVICE_RUNNING; 
				}
				break;

			case SERVICE_CONTROL_INTERROGATE:
				break;

			default: 
				break;
		};

		if (!SetServiceStatus(StatusHandle,  &Status)) 
		{ 
			throw WinException(_T("Set Service Status"));
		} 
	}

	void WinService::Main(DWORD dwArgc, LPTSTR* lpszArgv)
	{
		try
		{
			DWORD code = 0; 
			DWORD specificError = 0xfffffff; 
		 
			StatusHandle = RegisterServiceCtrlHandler(Name.c_str(), ServiceProc); 
			if(StatusHandle == (SERVICE_STATUS_HANDLE)0) 
			{
				throw WinException(_T("Register Service Controller Handler"));
			} 

			Status.dwCheckPoint = 0; 
			Status.dwWaitHint = 0;  
			Status.dwCurrentState = SERVICE_STOPPED; 
			Status.dwWin32ExitCode = code; 
			Status.dwServiceSpecificExitCode = specificError; 

			try
			{
				if(Run())
				{
					Status.dwCurrentState = SERVICE_RUNNING; 
				}
			}
			catch(Exception& ex)
			{
				Debug(ex.GetDescription(), etError);
			}

			if(!SetServiceStatus(StatusHandle, &Status)) 
			{ 
				throw WinException(_T("Error in Set Service Status"));
			} 
		}
		catch(Exception& ex)
		{
			//Debug(ex.GetDescription(), etError);
		}
	}

	void WinService::Debug(wstring msg, EventType type)
	{
		DoCallBack(msg, type);
	}

	void WinService::SetDispatchHandle(LPHANDLER_FUNCTION proc)
	{
		ServiceProc = proc;
	}

	void WinService::Regist()
	{
		if(!ServiceList) ServiceList = new vector<WinService*>;

		ServiceList->push_back(this);
	}

	void WinService::UnRegist()
	{
		if(ServiceList)
		{	
			vector<WinService*>::iterator it = ServiceList->begin();
			vector<WinService*>::iterator last = ServiceList->end();
			while(it != last)
			{
				if(*it == this)
				{
					ServiceList->erase(it);
				}
			}

			if(ServiceList->size() == 0) delete ServiceList;
		}
	}

	void WinService::setName(wstring name)
	{
		Name = name;
	}

	void WinService::setDisplayName(wstring name)
	{
		DisplayName = name;
	}

	wstring WinService::getDisplayName()
	{
		return DisplayName;
	}

	wstring WinService::getName()
	{
		return Name;
	}

	void WINAPI WinService::ServiceMain(DWORD dwArgc, LPTSTR* lpszArgv)
	{
		vector<WinService*>::iterator it = ServiceList->begin();
		while(it != ServiceList->end())
		{
			(*it)->Main(dwArgc, lpszArgv);
			it++;
		}
	}
}

