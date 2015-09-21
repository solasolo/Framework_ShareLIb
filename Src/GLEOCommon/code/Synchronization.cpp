#include "Synchronization.h"
#include "WinException.h"

namespace Win32Lib
{
	ManualEvent::ManualEvent()
	{
		this->Init(false);
	}

	ManualEvent::ManualEvent(bool state)
	{
		this->Init(state);
	}

	ManualEvent::ManualEvent(bool state, TString name)
	{
		Handle = NULL;

		Handle = CreateEvent(NULL, true, state, name.c_str()); 
		if(Handle == INVALID_HANDLE_VALUE)
		{
		  throw WinException(_T("Create Event Object"));
		}
	}

	void ManualEvent::Set()
	{
		if(!SetEvent(Handle))
		{
			throw WinException(_T("Set Event"));
		}
	}

	void ManualEvent::Reset()
	{
		if(!ResetEvent(Handle))
		{
			throw WinException(_T("Reset Event"));
		}
	}

	bool ManualEvent::CheckState(int inerval)
	{
		DWORD State = WaitForSingleObject(Handle, inerval);
		if(State == WAIT_FAILED)
		{
			throw WinException(_T("Wait for Event"));
		}

		return (State == WAIT_OBJECT_0);
	}

	HANDLE ManualEvent::getHandle()
	{
		return Handle;
	}

	void ManualEvent::Init(bool state)
	{
		Handle = NULL;

		Handle = CreateEvent(NULL, true, state, NULL);
		if(Handle == INVALID_HANDLE_VALUE)
		{
		  throw WinException(_T("Create Event Object"));
		}
	}

//------------------------------------------------------------------------------------
	CriticalSection::CriticalSection()
	{
#if _WIN32_WINNT >= 0x0400
		if(!InitializeCriticalSectionAndSpinCount(&InnerSection, 0x80000400))
			throw WinException(_T("Create CriticalSection"));
#else
		InitializeCriticalSection(&InnerSection);
#endif
	}

	CriticalSection::~CriticalSection()
	{
	    DeleteCriticalSection(&InnerSection);
	}

	void CriticalSection::Enter()
	{
		EnterCriticalSection(&InnerSection); 
	}

	void CriticalSection::Leave()
	{
	    LeaveCriticalSection(&InnerSection);
	}

	bool CriticalSection::Try()
	{
#if _WIN32_WINNT >= 0x0400
		return TryEnterCriticalSection(&InnerSection);
#else
		return TRUE;			
#endif
	}

//------------------------------------------------------------------------------------
	CriticalGuard::CriticalGuard(CriticalSection& cs, bool test)
	{
		this->InGuard = false;
		this->Critical = &cs;

		if(!test)
		{
			this->Critical->Enter();
			this->InGuard = true;
		}
		else
		{
			this->InGuard = this->Critical->Try();
		}
	}

	CriticalGuard::~CriticalGuard()
	{
		Close();
	}

	bool CriticalGuard::IfEnter()
	{
		return this->InGuard;
	}

	void CriticalGuard::Close()
	{
		if(InGuard)
		{
			Critical->Leave();
			InGuard = false;
		}
	}

//------------------------------------------------------------------------------------
	Mutex::Mutex()
	{
		this->MutexHandler = NULL;
	}

	Mutex::~Mutex()
	{
		if(this->MutexHandler != NULL)
		{
			CloseHandle(this->MutexHandler);
		}
	}

	bool Mutex::Open(TString name)
	{
		bool Result = true;

		this->MutexHandler = CreateMutex(NULL, false, name.c_str());
		if(this->MutexHandler == NULL)
		{
			DWORD e_value = GetLastError();
			if(e_value == ERROR_ALREADY_EXISTS)
			{
				Result = false;
			}
			else
			{
				throw WinException(_T("Open Mutex"));
			}
		}

		return Result;
	}

//------------------------------------------------------------------------------------
	LightLocker::LightLocker(long* lock)
	{
		this->Locker = lock;
	}

	LightLocker::~LightLocker()
	{
		this->Unlock();
	}

	void LightLocker::Reset(long* locker)
	{
		*locker = 0;
	}

	bool LightLocker::Lock()
	{
		long value = false;

		if(this->Locker)
		{
			value = InterlockedCompareExchange(this->Locker, -1, 0);
		}

		return (value == 0);
	}

	void LightLocker::SpanLock()
	{
		while(!Lock())
		{
		}
	}

	void LightLocker::WaitingLock()
	{
		while(!Lock())
		{
			Sleep(1);
		}
	}

	void LightLocker::Unlock()
	{
		if(this->Locker)
		{
			InterlockedCompareExchange(this->Locker, 0, -1);
		}
	}
}