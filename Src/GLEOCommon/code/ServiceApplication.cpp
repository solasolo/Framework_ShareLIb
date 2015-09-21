#include "ServiceApplication.h"

#include "WinException.h"
#include "WinFuncs.h"

#include <comdef.h>
#include <conio.h>

using namespace Win32Lib;

namespace GLEO
{
	ServiceModule::ServiceModule(wstring name, wstring disp_name)
	{
		this->Name = name;
		this->DisplayName = disp_name;

		this->BasePath = GetStartupPath();
		this->Logger = NULL;
	}

	ServiceModule::~ServiceModule()
	{
	}

	bool ServiceModule::InConsole()
	{
		return ServiceApplication::RunAsConsole;
	}

	bool ServiceModule::Run()
	{
		SException::Install();
		CoInitialize(NULL);

		bool Result = false;

		if(true)
		{
			try
			{
				this->StartLog();

				if(this->Logger)
				{
					this->StartProcess();
	
					Result = true;			
				}
			}
			catch(Exception& ex)
			{
				this->Log(etError, FormatException(L"StartProcess", ex));
			}
			catch(_com_error& ex)
			{
				this->Log(etError, FormatException(L"StartProcess", ex));
			}
			catch(exception& ex)
			{
				this->Log(etError, FormatException(L"StartProcess", ex));
			}
		}

		CoUninitialize();

		return Result;
	}

	bool ServiceModule::Stop()
	{
		bool Result = false;

		try
		{
			this->StopProcess();

			Result = true;
		}
		catch(Exception& ex)
		{
			this->Log(etError, FormatException(L"StopProcess", ex));
		}
		catch(exception& ex)
		{
			this->Log(etError, FormatException(L"StopProcess", ex));
		}
		catch(_com_error& ex)
		{
			this->Log(etError, FormatException(L"StopProcess", ex));
		}

		return Result;
	}

	bool ServiceModule::Pause()
	{
		bool Result = true;

		return Result;
	}

	void ServiceModule::Log(EventType type, wstring msg)
	{
		if(Logger) Logger->Log(type, msg);
	}

	void ServiceModule::StartLog()
	{
		this->Logger = this->BuildLogger();
	}

	void ServiceModule::NotifyFunc(void* sender, wstring& msg, EventType type)
	{
		if(this->Logger)
		{
			this->Logger->Log(etMessage, msg);
		}
	}

	BaseEventLogger* ServiceModule::BuildLogger()
	{
		BaseEventLogger* logger;

		if(this->InConsole())
		{
			logger = new ConsoleEventLogger();
		}
		else
		{
			logger = new WinEventLogger(this->Name);
		}

		return logger;
	}
}

namespace GLEO
{
	//
	//
	//
	bool ServiceApplication::RunAsConsole;
	ServiceModule* ServiceApplication::AService;

	bool ServiceApplication::InConsole()
	{
		return RunAsConsole;
	}

	void WINAPI ServiceApplication::ServiceHandler(DWORD fdwControl)
	{
		try
		{
			ServiceApplication::AService->ServiceDispatch(fdwControl);
		}
		catch(Exception& ex)
		{
			ServiceApplication::AService->Log(etError, ex.GetDescription());
		}
	}

	ServiceApplication::ServiceApplication(ServiceModule* module)
	{
		winlog = new WinEventLogger(module->getName());

		ServiceApplication::AService = module;
		ServiceApplication::AService->SetCallBack(this);
	}

	ServiceApplication::~ServiceApplication()
	{
	}

	int ServiceApplication::Run(int argc, wchar_t* argv[])
	{
		wchar_t* param = NULL; 

		if(argc > 1)
		{
			param = argv[1];
			if(param[0] == L'/' || param[0] == L'-')
			{
				param += 1;
			}
		}

		ServiceApplication::AService->SetDispatchHandle(ServiceApplication::ServiceHandler);

		if(param != NULL)
		{
			if(_wcsicmp(param, L"install") == 0)
			{
				this->InstallService();
			}
			else if(_wcsicmp(param, L"uninstall") == 0)
			{
				this->UninstallService();
			}
			else if(_wcsicmp(param, L"standalone") == 0 || _wcsicmp(param, L"console") == 0)
			{
				this->RunConsole();
			}
		}
		else
		{
			this->RunService();
		}

		return 0;
	}

	void ServiceApplication::InstallService()
	{
		try
		{
			ServiceManager SMC(ServiceApplication::AService);

			SMC.Install();
			MessageBox(GetDesktopWindow(), L"Service Install OK!", L"Message", MB_OK);
		}
		catch(Exception& ex)
		{
			MessageBox(GetDesktopWindow(), ex.GetDescription().c_str(), L"Error", MB_OK);
		}
	}

	void ServiceApplication::UninstallService()
	{
		try
		{
			ServiceManager SMC(ServiceApplication::AService);

			SMC.Uninstall();
			MessageBox(GetDesktopWindow(), L"Service Unnstall OK!", L"Message", MB_OK);
		}
		catch(Exception& ex)
		{
			ServiceApplication::AService->Log(EventType::etError, ex.GetDescription());
			MessageBox(GetDesktopWindow(), ex.GetDescription().c_str(), L"Error", MB_OK);
		}
	}

	void ServiceApplication::RunConsole()
	{
		ServiceApplication::RunAsConsole = true;

		try
		{
			if(ServiceApplication::AService->Run())
			{
				while(!_kbhit())
				{
					Sleep(100);
				}
			}

			ServiceApplication::AService->Stop();
		}
		catch(Exception& ex)
		{
			MessageBox(GetDesktopWindow(), FormatException(ex).c_str(), L"Error", MB_OK);
		}
		catch(exception& ex)
		{
			MessageBox(GetDesktopWindow(), FormatException(ex).c_str(), L"Error", MB_OK);
		}
		catch(_com_error& ex)
		{
			MessageBox(GetDesktopWindow(), FormatException(ex).c_str(), L"Error", MB_OK);
		}
		catch(...)
		{					
			MessageBox(GetDesktopWindow(), L"未知错误，程序异常退出", L"Error", MB_OK);
		}				
	}

	void ServiceApplication::RunService()
	{
		ServiceApplication::RunAsConsole = false;

		try
		{
			ServiceManager::RegisterService();
		}
		catch(Exception& ex)
		{
			MessageBox(GetDesktopWindow(), ex.GetDescription().c_str(), L"Error", MB_OK);
		}
	}

	void ServiceApplication::NotifyFunc(void* sender, wstring& msg, EventType type)
	{
		this->winlog->Log(etMessage, msg);
	}
}
