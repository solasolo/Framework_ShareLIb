#ifndef WINSERVICE_H
#define WINSERVICE_H

#pragma warning(disable:4786)

#include <windows.h>

#include <string>
#include <vector>

#include "CommonFuncs.h"
#include "EventLogger.h"

using namespace std;
using namespace GLEO;

namespace Win32Lib
{
	class ServiceManager;

	class _declspec(dllexport) SystemConsoleManager
	{
		friend ServiceManager;

	private:
		SC_HANDLE Handle;	

	protected:
		SC_HANDLE GetHandle();

	public:
		SystemConsoleManager();
		~SystemConsoleManager();
	};

	class _declspec(dllexport) WinService : public EventSource
	{
		friend class ServiceManager;

#if _MSC_VER < 1300
	public:
#endif
		static void WINAPI ServiceMain(DWORD dwArgc, LPTSTR* lpszArgv);

	private:
		static vector<WinService*>* ServiceList;

		SERVICE_STATUS Status;
		SERVICE_STATUS_HANDLE StatusHandle;
		
		LPHANDLER_FUNCTION ServiceProc;

		void Regist();
		void UnRegist();

		void Debug(wstring msg, EventType type);

	protected:
		wstring Name;
		wstring DisplayName;

	public:
		WinService();

		void SetDispatchHandle(LPHANDLER_FUNCTION proc);

		void Main(DWORD dwArgc, LPTSTR* lpszArgv);
		void ServiceDispatch(int code);

		void setName(wstring name);
		void setDisplayName(wstring name);

		wstring getName();
		wstring getDisplayName();
		
		virtual bool Run() { return true; };
		virtual bool Stop() { return true; };
		virtual bool Pause() { return true; };
		virtual bool Resume() { return true; };
		virtual bool Shutdown() { return true; };
	};

	class _declspec(dllexport) ServiceManager
	{
	public:
		static void RegisterService();

	private:
		SystemConsoleManager SCM;
		SC_HANDLE Handle;
		wstring ServiceName;
		WinService* Service;

		void OpenHandle();
		void CloseHandle();

	public:
		ServiceManager(WinService* service);
		ServiceManager(wstring service_name);

		~ServiceManager();

		void Install(wstring path);
		void Install();
		void Uninstall();
		void Start(int nArg, LPTSTR* pArg);
		void Stop();
	};
}

#endif
