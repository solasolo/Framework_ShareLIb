#include "SimpleTask.h"

#include "BaseException.h"
#include <comdef.h>
#include <time.h>

namespace GLEO
{
	SimpleTask::TaskDispatch::TaskDispatch()
	{
		f = NULL;
		Description = L"";
		IdelTime = 0;
		LastRunTime = 0;
	}

	SimpleTask::TaskDispatch::TaskDispatch(SimpleTask::Task task, wstring desc, unsigned int time)
	{
		f = task;
		Description = desc;
		IdelTime = time;
		LastRunTime = 0;
	}

	bool SimpleTask::TaskDispatch::OnTime()
	{
		bool Result = false;

		time_t now = time(NULL);
		if(LastRunTime == 0 || (now - LastRunTime) > IdelTime)
		{
			LastRunTime = now;

			Result = true;
		}

		return Result;
	}

	wstring& SimpleTask::TaskDispatch::getDescription()
	{
		return this->Description;
	}

	SimpleTask::Task SimpleTask::TaskDispatch::getFunc()
	{
		return this->f;
	}

	unsigned int SimpleTask::TaskDispatch::getTimer()
	{
		return this->IdelTime;
	}

	void SimpleTask::TaskDispatch::setTimer(unsigned int  value)
	{
		this->IdelTime = value;
	}
}

namespace GLEO
{
	SimpleTask::SimpleTask(wstring name)
		: SimpleThread(name, true)
	{
		Step = -1;

		this->Logger = NULL;
	}


	SimpleTask::~SimpleTask(void)
	{
	}

	void SimpleTask::RuningInfo(wstring task)
	{
	}


	void SimpleTask::RunTask()
	{
		this->Step++;

		if(this->Step >= this->DispatchTable.size())
		{
			this-> Step = 0;
		}

		if(this->Step < this->DispatchTable.size())
		{
			TaskDispatch& disp = this->DispatchTable[this->Step];

			this->Name = disp.getDescription();

			Task f = disp.getFunc();
			if(f && disp.OnTime())
			{
				CriticalGuard CG(OperateGate);

				this->RuningInfo(this->Name); 

				TaskResult Result;
				Result.NewIdleTime = disp.getTimer();

				(this->*f)(Result);
				disp.setTimer(Result.NewIdleTime);

				CG.Close();

				//this->ExceptionWrap(disp.getDescription(), f);
			}
		}
	}

	void SimpleTask::Notify(wstring& msg, EventType type)
	{
		if(Logger) Logger->Log(type, msg);
	}

	int SimpleTask::ExceptionWrap(wstring task, Task f, TaskResult& result)
	{
		int Result = -1;

		try
		{
			CriticalGuard CG(OperateGate);

			(this->*f)(result);

			CG.Close();

			Result = 0;
		}
		catch(Exception& ex)
		{
			if(Logger) Logger->Log(etError, FormatException(task, ex));
		}
		catch(exception& ex)
		{
			if(Logger) Logger->Log(etError, FormatException(task, ex));
		}
		catch(_com_error& ex)
		{
			if(Logger) Logger->Log(etError, FormatException(task, ex));
		}
		catch(...)
		{
			if(Logger) Logger->Log(etError, L"[" + task + L"] Unkown Exception!");
		}

		return Result;
	}

	void SimpleTask::AddTask(Task task, wstring desc, unsigned int time)
	{
		TaskDispatch ATask(task, desc, time);

		this->DispatchTable.push_back(ATask);
	}
}