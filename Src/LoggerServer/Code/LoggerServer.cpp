#include "LoggerServer.h"

#include "SimpleProtocol.h"

namespace GLEO
{
	LoggerServer::LoggerServer(string ip, int port, wstring name)
		: SimpleThread(name)
	{
		this->MessageServer = NULL;
		this->MessageQueue = NULL;

		this->MessageQueue = new deque<LogMessage>();
		this->MessageServer = new TCPServer(ip, port);

		Log(etMessage, L"**************日志服务启动(Log Started)**************");
	}

	LoggerServer::~LoggerServer()
	{

		Log(etMessage, L"**************日志服务中止(Log End)**************");

		if(this->MessageQueue)
		{
			this->WriteAll(this->MessageQueue);
		}

		this->Shutdown();

		DESTROY(this->MessageQueue);
		DESTROY(this->MessageServer);
	}

	void LoggerServer::WriteAll(deque<LogMessage>* msgs) throw()
	{
		wstring MsgString;
		LogMessage Msg;

		try
		{
			while(!msgs->empty())
			{
				Msg = msgs->front();

				if(MessageServer)
				{
					SimpleProtocolEncoder spe(1);

					spe << Msg.Type;
					spe.RawWrite(&Msg.Time, sizeof(Msg.Time));
					spe << Msg.Message;

					try
					{
						MessageServer->SendAll(spe.GetData());
					}
					catch(...)
					{
					}
				}

				msgs->pop_front();
			}
		}
		catch(...)
		{
		}
	}

	void LoggerServer::WriteLog(SYSTEMTIME& time, int Type, wstring Message) throw()
	{
		if(MessageServer->GetClientsCount() < 1)
		{
			return;
		}

		CriticalGuard CG(this->BufferGuard);

		if(this->MessageQueue)
		{
			LogMessage Msg;

			GetLocalTime(&Msg.Time);
			Msg.Type = Type;
			Msg.Message = Message;

			this->MessageQueue->push_back(Msg);
		}

		CG.Close();
	}

	void LoggerServer::Notify(wstring msg, EventType type)
	{
	}

	void LoggerServer::CleanLogger(time_t last_time)
	{

	}

	void LoggerServer::RunTask()
	{
		deque<LogMessage>* OldBuffer;

		CriticalGuard CG(this->BufferGuard);

		deque<LogMessage>* NewBuffer = new deque<LogMessage>();
		OldBuffer = this->MessageQueue;
		this->MessageQueue = NewBuffer;

		//OldBuffer = new deque<LogMessage>();
		//InterlockedExchangePointer(this->MessageQueue, OldBuffer);

		CG.Close();


		if(OldBuffer)
		{
			LogMessage Msg;

			this->WriteAll(OldBuffer);

			delete OldBuffer;
		}
	}

	void LoggerServer::setSleepTime(int timer)
	{
		this->SleepTimer = timer;
	}


	

	//
	//
	//

	FaultListener::FaultListener(wstring path, wstring prefix, string ip, int port, wstring name)
		: LoggerServer(ip, port, name)
	{
		//this->MessageServer = NULL;
		//this->MessageQueue = NULL;

		//this->MessageQueue = new deque<LogMessage>();
		//this->MessageServer = new TCPServer(ip, port);

		//Log(etMessage, L"********************故障服务端启动(FaultListener Started)********************");
	}

	FaultListener::~FaultListener()
	{
		//Log(etMessage, L"********************故障服务端中止(FaultListener End)********************");

		if(this->MessageQueue)
		{
			this->WriteAll(this->MessageQueue);
		}

		this->Shutdown();

		DESTROY(this->MessageQueue);
		DESTROY(this->MessageServer);
	}

	void FaultListener::WriteAll(deque<LogMessage>* msgs) throw()
	{
		wstring MsgString;
		LogMessage Msg;

		try
		{
			while(!msgs->empty())
			{
				Msg = msgs->front();
				//this->WriteLog(Msg.Time, Msg.Type, Msg.Message);

				if(MessageServer)
				{
					try
					{
						MessageServer->SendAll(~Msg.Message);
						MessageServer->SendAll(string("<EOF>"));
					}
					catch(...)
					{
					}
				}

				msgs->pop_front();
			}

			//this->CloseLog();
		}
		catch(...)
		{
		}
	}
} 