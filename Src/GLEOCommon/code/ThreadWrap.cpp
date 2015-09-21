#include "ThreadWrap.h"

#include <windows.h>
#include <comdef.h>

#include "WinException.h"

namespace Win32Lib
{
	ThreadStart::ThreadStart(LPTHREAD_START_ROUTINE entry, void* param, bool suspend)
	{
		ThreadHandle = NULL;
		ExitEvent = NULL;
		ThreadID = 0;

		DWORD Flags = 0;
		if(suspend) Flags |= CREATE_SUSPENDED;

		ThreadHandle = CreateThread(NULL, 0, entry, param, Flags, &ThreadID);
		if(ThreadHandle == NULL) throw WinException(L"Create Thread");

		ExitEvent = CreateEvent(NULL, true, true, NULL);
		if(ExitEvent == NULL) 
		{
			CloseHandle(ThreadHandle);
			ThreadHandle = NULL;

			throw WinException(L"Create Thread Exit Event");
		}
	}

	ThreadStart::~ThreadStart()
	{
		if(this->ThreadHandle) CloseHandle(ThreadHandle);
		if(this->ExitEvent) CloseHandle(ExitEvent);
	}

	HANDLE ThreadStart::getHandle()
	{
		return this->ThreadHandle;
	}

	bool ThreadStart::IsRuning()
	{
		bool Result;
		Result = (WaitForSingleObject(ThreadHandle, 0) != WAIT_OBJECT_0);
		
		return Result;
	}

	void ThreadStart::Start()
	{
		if(this->ThreadHandle) 
		{
			if(-1 == ResumeThread(this->ThreadHandle))
			{
				throw WinException(L"Resume Thread");
			}
		}
	}

	void ThreadStart::Pause()
	{
		if(this->ThreadHandle) 
		{
			if(-1 == SuspendThread(this->ThreadHandle))
			{
				throw WinException(L"Suspend Thread");
			}
		}
	}

	void ThreadStart::Terminate()
	{
		if(this->ThreadHandle) 
		{
			if(!TerminateThread(this->ThreadHandle, -1));
			{
				//throw WinException(L"Terminate Thread");
			}
		}
	}

	void ThreadStart::WaitForShutdown()
	{
		int WaitCount = 0;
		bool ThreadState = true;
		while(ThreadState)
		{
			WaitCount++;
			if(WaitCount > 10 * 60)
			{
				this->Terminate();
				WaitCount = 0;
			}

			DWORD ThreadResult = STILL_ACTIVE;

			ThreadState = this->IsRuning();
			if(ThreadState)
			{
			    GetExitCodeThread(ThreadHandle, &ThreadResult);
				ThreadState = (ThreadResult == STILL_ACTIVE);
			}
		}
	}
}


namespace Win32Lib
{
	SimpleThread::SimpleThread(wstring name, bool suspend, IEventCallBack* callback)
	{
		this->Name = name;
		this->Quiting = false;
		this->Starter = NULL;
		this->SleepTimer = 50;	
	
		this->SetCallBack(callback);

		this->Starter = new ThreadStart(ThreadLoop, this, suspend);
	}

	SimpleThread::~SimpleThread()
	{
	}

	void SimpleThread::Start()
	{
		this->Starter->Start();
	}

	void SimpleThread::Shutdown()
	{
		Quiting = true;
		
		if(this->Starter)
		{
			this->Starter->WaitForShutdown();
			
			DESTROY(this->Starter);
		}
	}

	bool SimpleThread::IsQuitting()
	{
		return this->Quiting;
	}

	void SimpleThread::Notify(wstring& msg, EventType type)
	{
		DoCallBack(msg, type);
	}

	void SimpleThread::ExceptionWrap(void(SimpleThread::*fn)())
	{
		try
		{
			(this->*fn)();
		}
		catch(Exception& ex)
		{
			this->Notify(FormatException(this->Name, ex), etError);
		}
		catch(exception& ex)
		{
			this->Notify(FormatException(this->Name,ex), etError);
		}
#ifndef __BORLANDC__
		catch(_com_error& ex)
		{
			this->Notify(FormatException(this->Name,ex), etError);
		}
#endif
		catch (...)
		{
			this->Notify(L"[" + this->Name + L"] Unknown Exception Occurred in Thread", etError);
		}
	}

	void SimpleThread::DoThread()
	{
		this->Notify(wstring(L"Thread [") + this->Name + L"] Starting......", etDebug);
		
		this->Init();

		while(!this->Quiting)
		{
			this->ExceptionWrap(&SimpleThread::RunTask);

			if(this->SleepTimer > 0)
			{
				Sleep(this->SleepTimer);  
			}
		}

		this->Destory();

		this->Notify(wstring(L"Thread [") + this->Name + L"] Quit", etDebug);
	}

	DWORD WINAPI SimpleThread::ThreadLoop(void* param)
	{
		SException::Install();
		CoInitialize(NULL);

		SimpleThread* me = static_cast<SimpleThread*>(param);
	
		me->ExceptionWrap(&SimpleThread::DoThread);

		CoUninitialize();

		return 0;
	}
}