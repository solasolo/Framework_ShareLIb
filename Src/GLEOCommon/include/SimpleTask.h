#pragma once

#include "ThreadWrap.h"
#include <vector>

using namespace std;

namespace GLEO
{
	class SimpleTask;

	class __declspec(dllexport) SimpleTask : public SimpleThread
	{
	public:
		struct TaskResult
		{
			int NewIdleTime;
		};

		typedef void(SimpleTask::*Task)(TaskResult& result);

		class __declspec(dllexport) TaskDispatch
		{
		private:
			wstring Description;
			unsigned int IdelTime;
			time_t LastRunTime;

			Task f;

		public:
			TaskDispatch();
			TaskDispatch(SimpleTask::Task task, wstring desc, unsigned int time);

			bool OnTime();
			wstring& getDescription();
			Task getFunc();
			unsigned int getTimer();
			void setTimer(unsigned int  value);
		};

	private:
		int Step;
		unsigned int ThreadLoopCounter;

	    CriticalSection OperateGate;
		vector<TaskDispatch> DispatchTable;

	protected:
		BaseEventLogger* Logger;

		void AddTask(Task task, wstring desc, unsigned int time);
		virtual void RuningInfo(wstring task); 

	public:
		SimpleTask(wstring name);
		virtual ~SimpleTask(void);

		virtual void RunTask();
		virtual void Notify(wstring& msg, EventType type = etMessage);

		int ExceptionWrap(wstring task, Task f, TaskResult& result);
	};
}
