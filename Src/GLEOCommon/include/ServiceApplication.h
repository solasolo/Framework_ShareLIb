#pragma once

#include "WinService.h"
#include "WinEventLogger.h"
#include "ConsoleEventLogger.h"

using namespace Win32Lib;

namespace GLEO
{
	class _declspec(dllexport) ServiceModule : public WinService, public EventCallBack
	{
	protected:
		wstring BasePath;
		BaseEventLogger* Logger;

		void StartLog();
	
		virtual void StartProcess() = 0;
		virtual void StopProcess() = 0;
		
		virtual void NotifyFunc(void* sender, const wstring& msg, EventType type = etMessage);
		
		virtual BaseEventLogger* BuildLogger();

	public:
		ServiceModule(wstring name, wstring disp_name);
		~ServiceModule();

		bool InConsole();

		virtual bool Run();
		virtual bool Stop();
		virtual bool Pause();
	
		virtual void Log(EventType type, wstring msg);
	};

	class _declspec(dllexport) ServiceApplication : public EventCallBack
	{
		static ServiceModule* AService;
		static void WINAPI ServiceHandler(DWORD fdwControl);

	public:
		static bool RunAsConsole;
		static bool InConsole();

		ServiceApplication(ServiceModule* module);
		~ServiceApplication();
		
		int Run(int argc, wchar_t* argv[]);

		virtual void NotifyFunc(void* sender, const wstring& msg, EventType type = etMessage);

	protected:
		void InstallService();
		void UninstallService();
		void RunConsole();
		void RunService();

	private:
		WinEventLogger* winlog;
	};
}