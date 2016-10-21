#pragma once

#ifndef WINTCP_H
#define WINTCP_H

#pragma warning(disable:4786)

#include "WinSocket.h"
#include "ThreadWrap.h"
#include "EventLogger.h"
#include "StreamBuffer.h"
#include "ThreadWrap.h"
#include "SimpleProtocol.h"

using namespace GLEO;

namespace GLEO
{
	class TCPConnection;

	class __declspec(dllexport) TCPCallBack : public EventCallBack
	{
	public:
		virtual void OnReceived(TCPConnection& conn) = 0;
		virtual void OnConnected(TCPConnection& conn);
	};

	class __declspec(dllexport) TCPEventSource : virtual public EventSource
	{
	private:

	public:
		TCPEventSource();

		void SetCallBack(TCPCallBack* handle);
		void DoReceived(TCPConnection& conn);
		void DoConnected(TCPConnection& conn);
	};

	class SimpleProtocolCallBack : public EventCallBack
	{
	public:
		virtual void ReceiveFunc(string& cmd, string& msg) = 0;
	};

	class __declspec(dllexport) SimpleProtocolEventSource : virtual public EventSource
	{
	private:

	public:
		SimpleProtocolEventSource();

		void SetCallBack(SimpleProtocolCallBack* handle);
		void DataReady(string& cmd, string& msg);
	};

	class __declspec(dllexport) TCPConnection : public TCPEventSource, public SimpleThread
	{
	private:
		StreamBuffer Buffer;

	protected:
		string LocalIP;
		int LocalPort;
		string PeerIP;
		int PeerPort;

		bool Connected;
		WinSocket* Socket;

	public:
		TCPConnection();
		TCPConnection(SOCKET socket);
		~TCPConnection();

		static bool Debug;

		int GetLocalPort();
		string GetLocalIP();
		bool IsOnline();
		bool Available();

		void Connect(string ip, int port);
		bool CheckReceiveData();

		StreamBuffer& GetData();
		void Send(string& msg);

		virtual void RunTask(); 
	};

	class __declspec(dllexport) TCPClient : public TCPConnection
	{
	protected:
		int ConnectionRetryTime;

	public:
		TCPClient(string ip, int port);
		~TCPClient();

		virtual void RunTask();

		void setConnTimer(int timer);
		void Send(string& msg);
	};

	class __declspec(dllexport) TCPServer : public TCPEventSource, public TCPCallBack, public SimpleThread
	{
	private:
		bool Quiting;
		bool Single;

		string Address;
		int Port;

		CriticalSection ClientsGuard;
		WinSocket* Listener;
		vector<TCPConnection*> Connections;

	public:
		TCPServer(string ip, int port, bool Single = false);
		~TCPServer();

		virtual void RunTask();
		virtual void Init();

		void OnReceived(TCPConnection& conn);
		void OnConnected(TCPConnection& conn);
		void NotifyFunc(void* sender, wstring& msg, EventType type = etMessage);

		int GetClientsCount();
		TCPConnection* GetConns();

		void Send(unsigned int i, string msg);
		void SendAll(string& msg);

		void ClearConn();
	};

	class ICommandExtend
	{
	private:
		friend class CommandProcessor;

	protected:
		virtual void ProcessCommand(TCPConnection& conn, short cmd, BinaryDecoder& decoder) = 0;
		virtual void ProcessConnect(TCPConnection& conn) = 0;
		virtual void ProcessNotice(EventType type, wstring& msg) = 0;
	};

	class CommandProcessor : public TCPCallBack
	{
	private:
		ICommandExtend* Extender;
		SimpleFrameCodec Framer;

	public:
		CommandProcessor(ICommandExtend* extend);
		bool BuildPack(short& cmd, string& msg, string& telegraph);

		virtual void OnReceived(TCPConnection& conn);
		virtual void OnConnected(TCPConnection& conn);
		virtual void NotifyFunc(void* sender, wstring& msg, EventType type = etMessage);
	};

	class __declspec(dllexport) TCPClientSimpleProtocol : public ICommandExtend
	{
	private:
		TCPClient* InnerClient;
		CommandProcessor* Processor;

	protected:

	public:
		TCPClientSimpleProtocol(string ip, int port);
		virtual ~TCPClientSimpleProtocol();

		bool Send(short cmd, string msg);
		bool IsOnline();
	};

	class __declspec(dllexport) TCPServerSimpleProtocol : public ICommandExtend
	{
	private:
		TCPServer* InnerServer;
		CommandProcessor* Processor;

	protected:
		bool Send(short cmd, BinaryEncoder& encoder);
		void Send(string msg);

		void Start(string ip, int port);

	public:
		TCPServerSimpleProtocol();
		virtual ~TCPServerSimpleProtocol();

		bool Send(short cmd, string msg);
	};
}
#endif