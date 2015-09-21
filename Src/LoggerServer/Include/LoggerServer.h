#ifndef LOGGERSERVER_H
#define LOGGERSERVER_H

#include <Winsock2.h>
#include <Windows.h>

#include "EventLogger.h"
#include "WinTCP.h"
#include "ThreadWrap.h"
#include "Synchronization.h"

#include <deque>

using namespace std;
using namespace Win32Lib;
/*
本项目配合LogMonitor项目使用
*/
namespace GLEO
{
	class __declspec(dllexport) LoggerServer : public BaseEventLogger, public SimpleThread 
	{
	protected:
		TCPServer* MessageServer;
		deque<LogMessage>* MessageQueue;
		CriticalSection BufferGuard;

		virtual void WriteAll(deque<LogMessage>* msgs);

	protected:
		virtual void WriteLog(SYSTEMTIME& time, int Type, wstring Message) throw();
		virtual void RunTask();
		virtual void Notify(wstring msg, EventType type);

	public:
		LoggerServer(string ip, int port, wstring name = L"LoggerServer");	
		virtual ~LoggerServer();	

		virtual void CleanLogger(time_t last_time);
		void setSleepTime(int timer);
	};

	class __declspec(dllexport) FaultListener : public LoggerServer
	{
		private:
		//TCPServer* MessageServer;
		//deque<LogMessage>* MessageQueue;
		//CriticalSection BufferGuard;

		virtual void WriteAll(deque<LogMessage>* msg);

	public:
		FaultListener(wstring path, wstring prefix, string ip, int port, wstring name = L"FaultListener");	
		virtual ~FaultListener();	
	};
}

#endif