#include "XCOM.h"
#include "CommonFuncs.h"

#include <time.h>
#include <sstream>
#include <stdlib.h>
#include <math.h>
#include <comdef.h>
#include "WinFuncs.h"

using namespace std;

const int MESSAGE_LOGGER_BUFFER_SIZE = 8190;

//------------------------------------------------------------------------------------
XCOMException::XCOMException(char* message) :
	Exception(message)
{
}

//------------------------------------------------------------------------------------
BaseXCOM::XCOMMessage::XCOMMessage(string head, string body)
{
	MessageID = head;
	DataBlock = body;
}

//------------------------------------------------------------------------------------
BaseXCOM::BaseXCOM(wstring name)
	: EventSource()
{
	Init();

	this->Name = name;
	this->CreateLogger();
}

BaseXCOM::~BaseXCOM(void)
{
	this->Quiting = true;

	if(this->WatchDogStart)
	{
		this->WatchDogStart->WaitForShutdown();

		DESTROY(WatchDogStart);
	}

	ClearSocket();

	DESTROY(SendLock);
	DESTROY(ACKEvent);
	DESTROY(ReplyEvent);
	DESTROY(TeleLogger);
}

void BaseXCOM::Init()
{
	TeleLogger = NULL;
	ACKEvent = NULL;
	ReplyEvent = NULL;
	WatchDogStart = NULL;
	Server = NULL;
	Client = NULL;
	Codec = NULL;

	Quiting = false;
	RemoteLive = false;
	InError = true;
	AllowRecCallBack = true;
	AutoACK = false;
	HeartBeatACK = false;
	SwapHearChannel = false;
	CheckHeartBeat = true;
	EnableSendQueue = false;

	ReplyEvent = new ManualEvent(false);
	ACKEvent = new ManualEvent(false);
	SendLock = new long();
	SendQueueLock = new long();
	ReceiveQueueLock = new long();

	LightLocker::Reset(SendLock);
	LightLocker::Reset(SendQueueLock);
	LightLocker::Reset(ReceiveQueueLock);


	ACKOutTime = 10;
	LiveOutTime = 60;
	ConnectOutTime = 60;

	this->WatchDogStart = new ThreadStart(WatchDogThread, this, true);
}

void BaseXCOM::Start()
{
	this->WatchDogStart->Start();
}

void BaseXCOM::Paulse()
{
}

void BaseXCOM::Reset()
{
	ClearSocket();
	InitSocket();
}

void BaseXCOM::ResetHeartbeat()
{
	this->LastLiveRecv = time(NULL);
}

void BaseXCOM::ClearSocket()
{
	if(Server)
	{
		Server->ClearConn();
	}
}

void BaseXCOM::InitSocket()
{
	bool ClientReady = false;
	bool ListenOK = false;

	if(!ListenOK)
	{
		if(Server == NULL)
		{
			Server = new TCPServer(ServerIP, ServerPort,true);
			Server->SetCallBack(this);
		}

		ListenOK = true;
	}

	if(!ClientReady)
	{
		if(Client == NULL)
		{
			Client = new TCPClient(RemoteIP,RemotePort);
				
			//Client->setSleepTimer(500);
			Client->SetCallBack(this);
			Client->setConnTimer(500);
		}

		ClientReady = true;
	}
}

bool BaseXCOM::InnerSend(string& MessageID, string& telegram)
{
	bool Result = false;

	LightLocker Locker(this->SendLock);
	if(!Locker.Lock())
	{
		this->SendNotify(wstring(L"Channel Busy"), etError);

		return false;
	}

	try
	{
		if(getCommStatus())
		{ 
			ACKEvent->Reset();

			this->LastSendMsgID = MessageID;
			Client->Send(telegram);

			this->MessageLog("==> MSG: [%s] %s", MessageID.c_str(), telegram.c_str());
			SendNotify(wstring(L"Send ") + ~MessageID);

			if(this->AutoACK)
			{
				Result = this->WaitACK();

			}
			else
			{
				Result = true;
			}
		}
		else
		{
			this->SendNotify(wstring(L"Channel Not Ready"), etError);
		}
	}
	catch(WinSocketException& )	
	{
		this->InError = true;
		throw;
	}

	Locker.Unlock();

	return Result;
}

void BaseXCOM::DoDataReceive(string& MessageID, string& DataBlock)
{
	if (!this->SwapHearChannel)
	{
		this->ResetHeartbeat();
	}

	if(this->CallBackHandle != NULL)
	{
		if(this->AllowRecCallBack)
			((XCOMCallBack*)this->CallBackHandle)->OnReceived(MessageID, DataBlock);
		else
			this->MessageQueue.push_front(BaseXCOM::XCOMMessage(MessageID, DataBlock));
	}
}

bool BaseXCOM::RawSend(string& MessageID, string& telegram)
{
	bool Result = false;

	if(this->EnableSendQueue)
	{
		LightLocker lock(this->SendQueueLock);
		lock.WaitingLock();

		if(SendMessageQueue.size() > 0)
		{
			SendMessageQueue.push_back(BaseXCOM::XCOMMessage(MessageID, telegram));
		}
		else
		{
			try
			{
				Result = this->InnerSend(MessageID, telegram);

				if(!Result)
				{
					SendMessageQueue.push_back(BaseXCOM::XCOMMessage(MessageID, telegram));
				}
			}
			catch(...)
			{
				SendMessageQueue.push_back(BaseXCOM::XCOMMessage(MessageID, telegram));
				throw;
			}
		}

		lock.Unlock();
	}
	else
	{
		Result = this->InnerSend(MessageID, telegram);	
	}

	return Result;
}

bool BaseXCOM::Send(string& MessageID, string& DataBlock)
{
	bool Result = false;

	string SendData;
	this->Codec->Encode(SendData, MessageID, DataBlock);

	Result = this->RawSend(MessageID, SendData);

	return Result;
}

bool BaseXCOM::SendReply(string& MessageID, string& DataBlock)
{
	string Temp;
	this->Codec->EncodeReply(Temp, MessageID, DataBlock);

	return this->RawSend(MessageID, Temp);
}

bool BaseXCOM::WaitACK()
{
	bool Result = false;

	time_t t = time(NULL) + ACKOutTime; 	
	while(time(NULL) < t)
	{
		if(ACKEvent->CheckState(10))
		{
			Result = true;
			break;
		}
	}

	if(!Result) 
	{
		throw XCOMException("ACK Timeout"); 
	}

	return Result;
}

bool BaseXCOM::WaitReply()
{
	bool Result = false;

	time_t t = time(NULL) + ReplyOutTime; 	
	while(time(NULL) < t)
	{
		if(ReplyEvent->CheckState(10))
		{
			Result = true;
			break;
		}
	}

	if(!Result) 
	{
		throw XCOMException("Reply Time Out"); //直接超时
	}

	return Result;
}

bool BaseXCOM::Read(string& MessageID, string& DataBlock)
{
	bool Result = !MessageQueue.empty();

	if(Result)
	{
		MessageID = MessageQueue.back().MessageID;
		DataBlock = MessageQueue.back().DataBlock;

		MessageQueue.pop_back();
	}
	else
	{
		MessageID = "";
		DataBlock = "";
	}

	return Result;
}

void BaseXCOM::Record(wstring& message)
{
	this->RecordTelegram(~message);
}

void BaseXCOM::SetCallBack(XCOMCallBack* callback)
{
	this->CallBackHandle = callback;
}

void BaseXCOM::SendNotify(const wstring& msg, EventType type)
{
	try
	{
		this->DoCallBack(L"[" + this->Name + L"]" + msg, type);
	}
	catch(...)
	{
	}
}

void BaseXCOM::RecordTelegram(string& msg)
{
	if (this->TeleLogger)
	{
		this->TeleLogger->Log(EventType::etMessage, msg);
	}
}

void BaseXCOM::MessageLog(char* fmt, ...)
{
	char buf[MESSAGE_LOGGER_BUFFER_SIZE + 1];
	buf[MESSAGE_LOGGER_BUFFER_SIZE] = '\x0';

	va_list args;
	va_start(args, fmt);

	_vsnprintf_s(buf, MESSAGE_LOGGER_BUFFER_SIZE, fmt, args);

	string Message = buf;
	this->RecordTelegram(Message);
}

bool BaseXCOM::getCommStatus()
{
	bool Result = true;
	
	Result &= (this->Client != NULL);
	Result &= (this->Server != NULL);

	if(Result)
	{
		Result &= this->Client->IsOnline();
		Result &= (this->Server->GetClientsCount() == 1);
	}

	return Result;
}

//心跳电文
void BaseXCOM::SendHeartbeat()
{
	string Temp;
	this->Codec->EncodeHeartTelgram(Temp);

	if (this->SwapHearChannel)
	{
		Server->SendAll(Temp);
	}
	else
	{
		Client->Send(Temp);
	}

	//this->MessageLog("==> LIV: %s", Temp.c_str());
} 

void BaseXCOM::SendHeartbeatACK(TCPConnection& conn)
{
	string Temp;

	this->Codec->EncodeHeartReply(Temp);
	conn.Send(Temp);
	this->MessageLog("==> LRP: %s", Temp.c_str());
}

void BaseXCOM::SendACK(TCPConnection& conn, string& telegram)
{
	string Temp;
	this->Codec->EncodeACK(Temp, telegram);

	conn.Send(Temp);
	this->MessageLog("==> ACK: %s", Temp.c_str());
}

void BaseXCOM::OnReceived(TCPConnection& conn)
{
	StreamBuffer& s= (&conn)->GetData();

	string telegram;//电文
	string MID;//电文编号
	string DataBlock;//电文数据
	wstring Err;
	bool ack;
	char tmp[10];

	BaseXCOMCodec::MessageDir Dir = (&conn == (TCPConnection*)this->Client) ? BaseXCOMCodec::MessageDir::Client : BaseXCOMCodec::MessageDir::Server;

	while(true)
	{
		BaseXCOMCodec::MessageType MsgType = this->Codec->Decode(s, Dir, telegram, MID, DataBlock);
		if(MsgType == BaseXCOMCodec::MessageType::NO_MESSAGE) break;

		string TypeString;
		switch (MsgType)
		{
		case BaseXCOMCodec::MessageType::LIVE_MESSAGE:
			TypeString = "LIV";
			break;
		
		case BaseXCOMCodec::MessageType::MESSAGE_ACK:
		case BaseXCOMCodec::MessageType::MESSAGE_NAK:
			TypeString = "ACK";
			break;

		default:
			TypeString = "MSG";
		}

		if (MsgType != BaseXCOMCodec::MessageType::LIVE_MESSAGE)
		{
			this->MessageLog("<== %s:[%s](%d)%s", TypeString.c_str(), MID.c_str(), telegram.size(), telegram.c_str());
		}

		switch (MsgType)
		{
		case BaseXCOMCodec::MessageType::DATA_MESSAGE:
			this->SendNotify(wstring(L"Receive a Data Message!"), etDebug);

			if(this->AutoACK)
			{
				SendACK(conn, telegram);//发送应答电文
			}

			this->DoDataReceive(MID, DataBlock);

			break;

		case BaseXCOMCodec::MessageType::DATA_MESSAGE_REPLY:
			SendNotify(wstring(L"DATA_REPLY"));

			if(this->AutoACK)
			{
				SendACK(conn, telegram);//发送应答电文
			}

			this->DoDataReceive(MID, DataBlock);

			break;

		case BaseXCOMCodec::MessageType::LIVE_MESSAGE:
			//this->SendNotify(wstring(L"Receive a Live Message!"), etDebug);

			this->ResetHeartbeat();

			if(this->HeartBeatACK)
			{
				SendACK(conn, telegram);
			}

			break;

		case BaseXCOMCodec::MessageType::MESSAGE_ACK:
		case BaseXCOMCodec::MessageType::MESSAGE_NAK:
			ack = (MsgType == BaseXCOMCodec::MessageType::MESSAGE_ACK);
			if(this->CheckACK(ack, telegram, MID, DataBlock))
			{
				ReplyEvent->Set();
				this->LastSendMsgID.empty();

				ACKEvent->Set();
			}
			else
			{
				SendNotify(wstring(L"Error ACK"));
			}
			break;

		case BaseXCOMCodec::MessageType::INVALID_MESSAGE:
			Err = Codec->getError();
			if(!Err.empty())
			{
				this->SendNotify(wstring(L"Receive Error:") + Err, etDebug);
				this->MessageLog("<== ERR: [%s][%s](%d) %s", (~Err).c_str(), MID.c_str(), telegram.size(), telegram.c_str()); //收到的电文
			}
			break;

		default:
			SendNotify(wstring(L"ERROR_DATA") + ~MID);
			break;
		}
	}
}

void BaseXCOM::OnConnected(TCPConnection& conn)
{
	this->ResetHeartbeat();
}

void BaseXCOM::NotifyFunc(void* sender, const wstring& msg, EventType type)
{
	this->SendNotify(msg, type);
}

DWORD WINAPI BaseXCOM::WatchDogThread(void* param)
{
	SException::Install();
	CoInitialize(NULL);

	int WaitCount = 0;

	BaseXCOM* me = static_cast<BaseXCOM*>(param);  

	while(!me->Quiting)
	{
		try
		{
			while(!me->Quiting && (me->InError || (!me->RemoteLive && me->CheckHeartBeat)) )//重置客户端连接
			{
				me->SendNotify(wstring(L"BaseXCOM Reset!"), EventType::etWarrining);
				try
				{
					me->Reset();
					WaitCount = me->LiveOutTime * 5;

					me->InError = true;
					time_t OutTime = time(NULL) + me->ConnectOutTime;
					while (time(NULL) < OutTime)
					{
						if (me->Client->IsOnline() && me->Server->GetClientsCount() > 0)
						{
							me->LastLiveSend = 0;
							me->InError = false;
							me->RemoteLive = true;

							me->ResetHeartbeat();

							me->SendNotify(wstring(L"Connection established!"));

							break;
						}

						Sleep(100);
					}
				}
				catch(WinSocketException& ex)
				{
					me->SendNotify(wstring(L"Error in Reset BaseXCOM:") + ex.GetDescription(), EventType::etError);
				}
				catch(Exception& ex)
				{
					me->SendNotify(wstring(L"Error in Reset BaseXCOM:") + ex.GetDescription(), EventType::etError);
				}

				srand(time(NULL));
				Sleep(500 + rand() % 1000);	
			}

			int Timedifference;

			Timedifference = time(NULL) - me->LastLiveSend;
			if(Timedifference > me->LiveOutTime) //每隔T1时间发送心跳电文
			{
				WaitCount = 0;
				//me->SendNotify(wstring(L"Send Live Telegram!"), etDebug);
				me->SendHeartbeat();  
				me->LastLiveSend = time(NULL);
			}

			//2*T1时间没有收到心跳电文
			if(me->CheckHeartBeat)
			{
				Timedifference = time(NULL) - me->LastLiveRecv;
				if (Timedifference > 3 * me->LiveOutTime)  
				{
					me->RemoteLive = false;
					me->SendNotify(wstring(L"BaseXCOM Watch Dog Time Out!"), EventType::etWarrining);
					me->SendHeartbeat();
				}
			}

			// Queued Send
			LightLocker lock(me->SendQueueLock);
			lock.WaitingLock();

			if(me->SendMessageQueue.size() > 0)
			{
				XCOMMessage Msg = me->SendMessageQueue.front(); 
				bool rt = me->InnerSend(Msg.MessageID, Msg.DataBlock);
				if(rt)
				{
					me->SendMessageQueue.pop_front();
				}
			}

			lock.Unlock();
		}
		catch(WinSocketException& ex)
		{
			me->InError = true;

			me->SendNotify(ex.GetDescription(), etError);
		}
		catch(Exception& ex)
		{
			me->SendNotify(ex.GetDescription(), etError);
		}
		catch(exception& ex)
		{
			me->SendNotify(~string((ex.what())), etError);
		}
		catch (...)
		{
			me->SendNotify(wstring(L"Unknown Exception Occurred in BaseXCOM Watchdog Thread"), etError);
		}

		Sleep(100);
	}

	CoUninitialize();

	return 0;
}

bool BaseXCOM::CheckACK(bool ACK, string& telegram, string& MessageID, string& DataBlock)
{
	return (MessageID == this->LastSendMsgID);
}

void BaseXCOM::CreateLogger()
{
	wstring BasePath = ExtractFilePath(GetCurrentExecPath()) + L"\\";
	TeleLogger = new TextEventLogger(BasePath + L"..\\LOG\\", this->Name + L"-");
}

//------------------------------------------------------------------------------------
XCOM::XCOM(wstring name, string sip, unsigned int sport, string rip, unsigned int rport)
	: BaseXCOM(name)
{
	ServerIP = sip;
	ServerPort = sport;
	RemoteIP = rip;
	RemotePort = rport;
}

void XCOM::setReplyHeartBeat(bool flag)
{
	this->HeartBeatACK = flag;
}

void XCOM::setCheckHeartBeat(bool flag)
{
	this->CheckHeartBeat = flag;
}

void XCOM::setACK(bool flag)
{
	this->AutoACK = flag;
}

void XCOM::SetLiveTimer(int time)
{
	this->LiveOutTime = time;
}

void XCOM::setCodec(BaseXCOMCodec* bc)
{
	this->Codec = bc;
}
