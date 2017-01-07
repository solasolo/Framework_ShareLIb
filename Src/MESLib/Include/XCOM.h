#pragma once

#include "WinSocket.h"
#include "ThreadWrap.h"
#include "EventLogger.h"
#include "WinTCP.h"
#include "BaseCodec.h"

#include <exception>
#include <string>
#include <deque>

using namespace GLEO;
using namespace std;
using namespace Win32Lib;

class __declspec(dllexport)  XCOMException : public GLEO::Exception
{
public:
	XCOMException(char* message);

private:
};

class __declspec(dllexport) XCOMCallBack : public EventCallBack
{
public:
	virtual void OnReceived(string& MessageID, string& DataBlock) = 0;
};

class  __declspec(dllexport) BaseXCOM : virtual public EventSource, public TCPCallBack
{
private:
	static DWORD WINAPI WatchDogThread(void* param);

	struct XCOMMessage
	{
		string MessageID;
		string DataBlock;

		XCOMMessage(string head, string body);
	};

	wstring Name;

private:
	bool Quiting;
	bool InError;
	
	time_t LastLiveRecv;
	time_t LastLiveSend;

	//string Buffer;
	//string ReplyBuffer;
	int BufferLen;

	ManualEvent* ReplyEvent;
	ManualEvent*ACKEvent;
	long* SendLock;
	long* SendQueueLock;
	long* ReceiveQueueLock;

	TCPServer* Server;
	TCPClient* Client;
	ThreadStart* WatchDogStart;

	deque<XCOMMessage> MessageQueue;
	deque<XCOMMessage> SendMessageQueue;

	void Init();
	void Reset();
	void InitSocket();
	void ClearSocket();
	void ResetHeartbeat();

	void SendHeartbeat();
	void SendHeartbeatACK(TCPConnection& conn);

	void SendACK(TCPConnection& conn, string& telegram);
	bool WaitACK();

	void SendNotify(wstring& msg, EventType type = etMessage);
	void MessageLog(char* fmt, ...);

protected:
	string ServerIP; 
	string RemoteIP;
	unsigned int ServerPort;
	unsigned int RemotePort;

	bool EnableSendQueue;
	bool AutoACK;
	bool HeartBeatACK;
	bool SwapHearChannel;
	bool RemoteLive;
	bool AllowRecCallBack;
	bool CheckHeartBeat;

	int ReConnectTime;
	int ACKOutTime; 
	int ReplyOutTime;
	int LiveOutTime;
	int ConnectOutTime;

	string LastSendMsgID;
	BaseXCOMCodec* Codec;

	BaseEventLogger* TeleLogger;

	bool InnerSend(string& MessageID, string& telegram);
	void DoDataReceive(string& MessageID, string& DataBlock);

	virtual void CreateLogger();
	virtual bool CheckACK(bool ACK, string& telegram, string& MessageID, string& DataBlock);
	virtual void RecordTelegram(string& msg);
	virtual void RecordTelegram(string& msg);

	virtual void OnReceived(TCPConnection& conn);
	virtual void OnConnected(TCPConnection& conn);
	virtual void NotifyFunc(void* sender, wstring& msg, EventType type);

public:
	BaseXCOM(wstring name);
	virtual ~BaseXCOM(void);

	bool RawSend(string& MessageID, string& telegram);
	bool Send(string& MessageID, string& DataBlock);
	bool SendReply(string& MessageID, string& DataBlock);
	bool WaitReply();
	bool Read(string& MessageID, string& DataBlock);
	void Record(wstring& message);

	void SetCallBack(XCOMCallBack* callback);

	void Start();
	void Paulse();

	bool getCommStatus();
};

class  __declspec(dllexport) XCOM : public BaseXCOM
{
public:
	XCOM(wstring name, string sip, unsigned int sport, string rip, unsigned int rport);

	void SetLiveTimer(int time);
	void setReplyHeartBeat(bool flag);
	void setCheckHeartBeat(bool flag);
	void setACK(bool flag);
	void setCodec(BaseXCOMCodec* bc);
};
