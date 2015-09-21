#ifndef SYNCHRONIZATION_H
#define SYNCHRONIZATION_H

#include <windows.h>
#include <string>

#include "CommonFuncs.h"

using namespace std;

namespace Win32Lib
{
	class __declspec(dllexport) ManualEvent
	{
	private:
		HANDLE Handle;
		void Init(bool state);

	public:
		ManualEvent();
		ManualEvent(bool state);
		ManualEvent(bool state, TString name);

		void Set();
		void Reset();

		bool CheckState(int inerval = 0);
		HANDLE getHandle();
	};

	class __declspec(dllexport) CriticalSection
	{
	private:
		CRITICAL_SECTION InnerSection;

	public:
		CriticalSection();
		~CriticalSection();

		void Enter();
		void Leave();
		bool Try();
	};

	class __declspec(dllexport) CriticalGuard
	{
	private:	
		bool InGuard;
		CriticalSection* Critical;	

	public:	
		CriticalGuard(CriticalSection& cs, bool test = false);
		~CriticalGuard();

		bool IfEnter();
		void Close();
	};

	class __declspec(dllexport) Mutex
	{
	private:	
		HANDLE MutexHandler;

	public:	
		Mutex();
		~Mutex();

		bool Open(TString name);
	};

	class __declspec(dllexport) LightLocker
	{
	private:	
		long* Locker;

	public:	
		LightLocker(long* locker);
		~LightLocker();

		static void Reset(long* locker);

		bool Lock();
		void SpanLock();
		void WaitingLock();
		void Unlock();
	};
}

#endif