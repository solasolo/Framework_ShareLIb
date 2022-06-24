#include <Winsock2.h>
#include <comdef.h>

#include "WinTCP.h"
#include "CommonFuncs.h"
#include "WinException.h"


using namespace GLEO;
using namespace Win32Lib;

//---------------------------------------------------------------------------
namespace GLEO
{
	void TCPCallBack::OnConnected(TCPConnection& conn)
	{
	}
}

namespace GLEO
{
	bool TCPConnection::Debug = false;

	void TCPConnection::SetDebug(bool enable)
	{
		TCPConnection::Debug = enable;
	}

	TCPConnection::TCPConnection()
		: SimpleThread(L"Connection", true)
	{
		this->SleepTimer = 0;
		this->Connected = false;
		this->Socket= new WinSocket();
		this->Start();
	}

	TCPConnection::TCPConnection(SOCKET socket)
		: SimpleThread(L"Connection", true)
	{
		this->Socket = new WinSocket(socket);
		this->Start();
	}

	TCPConnection::~TCPConnection()
	{	
		this->Shutdown();

		DESTROY(Socket);	
	}

	string TCPConnection::GetLocalIP()
	{
		return this->LocalIP;
	}

	int TCPConnection::GetLocalPort()
	{
		return this->LocalPort;
	}

	bool TCPConnection::IsOnline()
	{
		return this->Connected;
	}

	bool TCPConnection::Available()
	{
		return (this->Socket != NULL && this->Connected);
	}

	bool TCPConnection::CheckReceiveData()
	{
		bool Result = false;

		if(this->Socket)
		{
			string Data;
			Result = Socket->CanReceive();

			if(Result)
			{
				Socket->Receive(Data);
				if(Data.length() > 0)
				{
					Buffer << Data;
				}
				else
				{
					Result = false;
				}
			}	
		}
		else
		{
			throw WinSocketNoConnection(*this->Socket, L"Check Receive Data");
		}

		return Result;
	}

	void TCPConnection::Send(const string& msg)
	{
		if(this->Socket)
		{
			this->Socket->Send(msg);
		}
		else
		{
			throw WinSocketNoConnection(*this->Socket, L"Send Data");
		}
	}

	StreamBuffer& TCPConnection::GetData()
	{
		return Buffer;
	}

	void TCPConnection::Connect(string ip, int port)
	{
		if(this->Socket) 
		{
			this->Socket->Connect(ip.c_str(), port);

			this->Connected = true;
		}
	}

	void TCPConnection::RunTask()
	{
		try
		{
			if(this->Socket)
			{
				if(this->CheckReceiveData())
				{
					this->DoReceived(*this);
				}
			}
		}
		catch(WinSocketException& ex)
		{
			DESTROY(this->Socket);	

			throw ex;
		}
	}
}

//---------------------------------------------------------------------------
namespace GLEO
{
	TCPEventSource::TCPEventSource()
	{
		CallBackHandle = NULL;
	}

	void TCPEventSource::SetCallBack(TCPCallBack* handle)
	{
		CallBackHandle = handle;
	}

	void TCPEventSource::DoReceived(TCPConnection& conn)
	{
		if(CallBackHandle)
		{
			((TCPCallBack*)CallBackHandle)->OnReceived(conn);
		}
	}

	void TCPEventSource::DoConnected(TCPConnection& conn)
	{
		if(CallBackHandle)
		{
			((TCPCallBack*)CallBackHandle)->OnConnected(conn);
		}
	}
}

//---------------------------------------------------------------------------
namespace GLEO
{
	SimpleProtocolEventSource::SimpleProtocolEventSource()
	{
		CallBackHandle = NULL;
	}

	void SimpleProtocolEventSource::SetCallBack(SimpleProtocolCallBack* handle)
	{
		CallBackHandle = handle;
	}

	void SimpleProtocolEventSource::DataReady(string& cmd, string& msg)
	{
		if(CallBackHandle)
			((SimpleProtocolCallBack*)CallBackHandle)->ReceiveFunc(cmd, msg);
	}
}

//---------------------------------------------------------------------------
namespace GLEO
{
	TCPClient::TCPClient(string ip, int port)
		: TCPConnection()
	{
		ConnectionRetryTime = 100;

		this->PeerIP = ip;
		this->PeerPort = port;
	}

	TCPClient::~TCPClient()
	{
		//Shutdown();
	}

	void TCPClient::setConnTimer(int timer)
	{
		ConnectionRetryTime = timer;
	}

	void TCPClient::Send(string& msg)
	{
		if(IsOnline() && this->Socket != NULL)
		{
			try
			{
				this->Socket->Send(msg);
			}
			catch(...)
			{
				this->Connected = false;
				throw;
			}
		}
		else
		{
			this->Connected = false;

			throw WinSocketNoConnection(*(this->Socket), L"TCP Send");
		}
	}

	void  TCPClient::Reset()
	{
		this->Connected = false;

		if (this->Socket)
		{
			DESTROY(this->Socket);
			StreamBuffer& buf = this->GetData();
			buf.Clear();
		}
	}

	void TCPClient::RunTask()
	{
		if(!this->IsOnline())
		{
			try
			{
				long WaitTime = this->ConnectionRetryTime + (long(rand()) * this->ConnectionRetryTime / 100000);
				wchar_t TimeStr[10];

				if(TCPConnection::Debug) 
				{
					this->Notify(wstring(L"Try to Connect to Server After ") + _itow(WaitTime, TimeStr, 10) + L"ms", etDebug);
				}

				Sleep(WaitTime);

				this->Reset(); // Renew Socket Object
				if(!this->Socket) 
				{
					this->Socket = new WinSocket();	
				}

				if(this->Socket)
				{
					this->Connect(this->PeerIP, this->PeerPort);
					this->DoConnected(*this);

					this->DoNotify(EventType::etMessage, L"Connected to %s:%d", (~this->PeerIP).c_str(), this->PeerPort);
				}
			}
			catch(WinSocketException& ex)
			{
				this->Notify(ex.GetDescription(), etError);
			}
		}

		if(this->IsOnline() && this->Socket != NULL)
		{
			try
			{
				if(this->CheckReceiveData())
				{
					this->DoReceived(*this);
				}
			}
			catch(WinSocketException& ex)
			{
				this->Notify(ex.GetDescription(), etError);
				this->Connected = false;
			}
		}
	}
}

//---------------------------------------------------------------------------
namespace GLEO
{
	TCPServer::TCPServer(string ip, int port, bool Single)
		: SimpleThread(L"TCP Server", true)
	{
		Quiting = false;
		this->Listener = NULL;
		this->Single = Single;

		Address = ip;
		Port = port;

		this->Listener = new WinSocket();
		this->Listener->Bind((char*)ip.c_str(), port);
		this->Start();
	}

	TCPServer::~TCPServer()
	{
		this->Shutdown();
		this->ClearConn();

		if(this->Listener)
		{
			this->Shutdown();
		}
		DESTROY(Listener);
	}

	int TCPServer::GetClientsCount()
	{
		return (unsigned int) Connections.size();
	}

	void TCPServer::Send(unsigned int i, const string& msg)
	{
		CriticalGuard CG(ClientsGuard);

		if(i > 0 && i <= Connections.size())
		{
			Connections[i-1]->Send(msg);
		}

		CG.Close();
	}

	void TCPServer::SendAll(const string& msg)
	{
		CriticalGuard CG(ClientsGuard);

		vector<TCPConnection*>::iterator it = Connections.begin();
		while(it != Connections.end())
		{
			try
			{
				(*it)->Send(msg);

				it++;
			}
			catch(WinSocketException& ex)
			{
				(*it)->Shutdown();
				delete(*it);
				it = Connections.erase(it);

				Notify(ex.GetDescription(), etError);
			}
		}

		CG.Close();
	}

	void TCPServer::Init()
	{
		this->Listener->Listen();
	}

	void TCPServer::RunTask()
	{
		SOCKET cnt;
		cnt = this->Listener->Accept();				
		TCPConnection* conn = new TCPConnection(cnt);
		conn->SetCallBack(this);

		this->DoNotify(EventType::etMessage, L"Client Linked %s:%d", (~this->Address).c_str(), this->Port);

		CriticalGuard CG(this->ClientsGuard);

		if(this->Single)
		{
			ClearConn();
		}
		this->Connections.push_back(conn);

		CG.Close();

		this->OnConnected(*conn);
	}

	void TCPServer::OnReceived(TCPConnection& conn)
	{
		this->DoReceived(conn);
	}

	void TCPServer::OnConnected(TCPConnection& conn)
	{
		this->DoConnected(conn);
	}

	void TCPServer::NotifyFunc(void *sender, const wstring &msg, EventType type)
	{
		this->DoCallBack(msg, type);
	}

	void TCPServer::ClearConn()
	{
		CriticalGuard CG(ClientsGuard);

		vector<TCPConnection*>::iterator it = Connections.begin();
		while(it != Connections.end())
		{
			try
			{
				if(*it)
				{
					(*it)->Shutdown();
				}

				delete(*it);
				it = Connections.erase(it);
			}
			catch(Exception& ex)
			{
				Notify(ex.GetDescription(), etError);
			}
		}
		CG.Close();
	}


	TCPConnection* TCPServer::GetConns()
	{
		return this->Connections[0];
	}
}


//---------------------------------------------------------------------------
namespace GLEO
{		
	CommandProcessor::CommandProcessor(ICommandExtend* extend)
	{
		this->Extender = extend;
	}

	bool CommandProcessor::BuildPack(short& cmd, string& msg, string& telegraph)
	{
		bool Result = true;

		this->Framer.Encode(telegraph, cmd, msg);

		return Result;
	}

	void CommandProcessor::OnReceived(TCPConnection& conn)
	{
		StreamBuffer& s = conn.GetData();
	
		string data;
		short cmd = 0;

		while(this->Framer.Decode(s, cmd, data))
		{
			BinaryDecoder pd(data);

			this->Extender->ProcessCommand(conn, cmd, pd);
		}
	}

	void CommandProcessor::OnConnected(TCPConnection& conn)
	{
		this->Extender->ProcessConnect(conn);
	}

	void CommandProcessor::NotifyFunc(void* sender, const wstring& msg, EventType type)
	{
		this->Extender->ProcessNotice(type, msg);
	}
}

//---------------------------------------------------------------------------
namespace GLEO
{
	TCPClientSimpleProtocol::TCPClientSimpleProtocol(string ip, int port)
	{
		this->Processor = NULL;
		this->InnerClient = NULL;

		this->Processor = new CommandProcessor(this);
		this->InnerClient = new TCPClient(ip, port);

		this->InnerClient->SetCallBack(this->Processor);
	}

	TCPClientSimpleProtocol::~TCPClientSimpleProtocol()
	{
		DESTROY(InnerClient);
		DESTROY(Processor);
	}

	bool TCPClientSimpleProtocol::Send(short cmd, string msg)
	{
		bool Result;
		string str;

		Result = this->Processor->BuildPack(cmd, msg, str);
		if(Result)
		{
			this->InnerClient->Send(str);
		}

		return Result;
	}

	bool TCPClientSimpleProtocol::IsOnline()
	{
		return this->InnerClient->IsOnline();
	}
}

//--------------------------------TCPServerSimpleProtocol-------------------------------------------
namespace GLEO
{
	TCPServerSimpleProtocol::TCPServerSimpleProtocol()
	{
		this->Processor = NULL;
		this->InnerServer = NULL;
	}

	TCPServerSimpleProtocol::~TCPServerSimpleProtocol()
	{
		if(this->InnerServer)
		{
			this->InnerServer->SetCallBack(NULL);
			this->InnerServer->Shutdown();
		}

		DESTROY(this->InnerServer);
		DESTROY(this->Processor);
	}

	void  TCPServerSimpleProtocol::Start(string ip, int port)
	{
		this->InnerServer = new TCPServer(ip, port);
		this->Processor = new CommandProcessor(this);
		this->InnerServer->SetCallBack(this->Processor);
	}

	void TCPServerSimpleProtocol::Send(string msg)
	{
		this->InnerServer->SendAll(msg);
	}

	bool TCPServerSimpleProtocol::Send(short cmd, string msg)
	{
		bool Result;
		string str;

		Result = this->Processor->BuildPack(cmd, msg, str);
		if(Result)
		{
			this->InnerServer->SendAll(str);
		}

		return Result;
	}

	bool TCPServerSimpleProtocol::Send(short cmd, BinaryEncoder& encoder)
	{
		bool Result;
		string str;

		Result = this->Processor->BuildPack(cmd, encoder.GetData(), str);
		if(Result)
		{
			this->InnerServer->SendAll(str);
		}

		return Result;
	}
}