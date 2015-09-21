#pragma once

#include "EventLogger.h"
#include "ThreadWrap.h"

#include <list>

namespace GLEO
{
	class __declspec(dllexport) ThreadEventLogger : public BaseEventLogger, public SimpleThread
	{
	private:
		vector<IEventLogger*> LoggerList;
		list<LogMessage>* MessageQueue;
		CriticalSection BufferGuard;

		void WriteAll(list<LogMessage>* msgs);

	protected:
		virtual void RunTask();
		virtual void WriteLog(SYSTEMTIME& time, int Type, wstring Message);

	public:
		ThreadEventLogger();
		virtual ~ThreadEventLogger();

		void AddLoggerObject(IEventLogger* obj);
		void CleanLoggerList();
		virtual void CleanLogger(time_t last_time);
	};
}