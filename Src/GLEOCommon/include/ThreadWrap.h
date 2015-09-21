#ifndef THREADWRAP_H
#define THREADWRAP_H

#include "EventLogger.h"

#include <windows.h>
#include <string>

using namespace std;
using namespace GLEO;

namespace Win32Lib
{
	class __declspec(dllexport) ThreadStart
	{
	private:
		HANDLE ExitEvent;
		HANDLE ThreadHandle;
		DWORD ThreadID;

	public:
		ThreadStart(LPTHREAD_START_ROUTINE entry, void* param, bool suspend = false);
		~ThreadStart();


		HANDLE getHandle();
		bool IsRuning();
		void Start();
		void Pause();
		void Terminate();
		void WaitForShutdown();
	};

	class __declspec(dllexport) SimpleThread : virtual public EventSource
	{
	private:
		static DWORD WINAPI ThreadLoop(void* param);	

		bool Quiting;
		ThreadStart* Starter; 

		void DoThread();
		void ExceptionWrap(void(SimpleThread::*fn)());

	protected:
		wstring Name;
		int SleepTimer;

		bool IsQuitting();

		virtual void RunTask() = 0;
		virtual void Init()  {;};
		virtual void Destory()  {;};
		
		virtual void Notify(wstring& msg, EventType type = etMessage);
		
	public:
		SimpleThread(wstring Name, bool suspend = false, IEventCallBack* callback = NULL);		
		virtual ~SimpleThread();	

		void Start();
		void Shutdown();
	};
}

#endif