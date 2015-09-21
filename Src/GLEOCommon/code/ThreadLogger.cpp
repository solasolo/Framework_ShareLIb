#include "ThreadLogger.h"

namespace GLEO
{
	ThreadEventLogger::ThreadEventLogger()
		: BaseEventLogger(), SimpleThread(L"ThreadEventLogger")
	{
		this->MessageQueue = NULL;
		this->MessageQueue = new list<LogMessage>();

		Log(etMessage, L"****************日志服务启动(Thread Log Start)******************");
	}

	ThreadEventLogger::~ThreadEventLogger()
	{
		Log(etMessage, L"***************日志服务中止(Thread Log End)******************");

		if(this->MessageQueue)
		{
			this->WriteAll(this->MessageQueue);
		}

		DESTROY(this->MessageQueue);
	}

	void ThreadEventLogger::CleanLogger(time_t last_time)
	{
		for(int i = 0; i < this->LoggerList.size(); i++)
		{
			LoggerList[i]->CleanLogger(last_time);
		}
	}

	void ThreadEventLogger::WriteAll(list<LogMessage>* msgs) throw()
	{
		for(int i = 0; i < this->LoggerList.size(); i++)
		{
			LoggerList[i]->BatchLog(msgs);
		}
	}

	void ThreadEventLogger::RunTask()
	{
		list<LogMessage>* OldBuffer;

		CriticalGuard CG(this->BufferGuard);

		OldBuffer = this->MessageQueue;
		this->MessageQueue = new list<LogMessage>();

		CG.Close();

		if(OldBuffer)
		{
			LogMessage Msg;

			this->WriteAll(OldBuffer);

			delete OldBuffer;
		}
	}

	void ThreadEventLogger::AddLoggerObject(IEventLogger* obj)
	{
		LoggerList.push_back(obj);
	}

	void ThreadEventLogger::CleanLoggerList()
	{
		this->LoggerList.clear();
	}

	void ThreadEventLogger::WriteLog(SYSTEMTIME& time, int Type, wstring Message)
	{
	
		if(this->MessageQueue)
		{
			LogMessage Msg;

			Msg.Time = time;
			Msg.Type = Type;
			Msg.Message = Message;

			this->MessageQueue->push_back(Msg);
		}
	}
}