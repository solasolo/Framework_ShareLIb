#pragma hdrstop

#include "RawSocket.h"

//#include <Mstcpip.h>

#define SIO_RCVALL _WSAIOW(IOC_VENDOR, 1)

//---------------------------------------------------------------------------
RawSocket::RawSocket(string addr)
: ReadDataEventSource()
{
	this->RecvBuffer = NULL;
	this->Terminated = false;

	this->LocalAddress = inet_addr(addr.c_str());
	this->RecvBuffer = new unsigned char[MAX_PACK_LEN];

	this->RecvEvent = new ManualEvent(false);
	this->CaptureThreadStart = new ThreadStart(&CaptureThread, this);
}

RawSocket::~RawSocket()
{
	this->Terminated = true;
	this->CaptureThreadStart->WaitForShutdown();

	if(this->RecvBuffer) delete this->RecvBuffer;
}

void RawSocket::Clear()
{
	CriticalGuard CG(this->PoolGuard);

	this->CapturePool.clear();

	CG.Close();
}

bool RawSocket::Read(CaptureData& msg)
{
	bool Result = false;

	CriticalGuard CG(this->PoolGuard);

	if(!this->CapturePool.empty())
	{
		msg = this->CapturePool.front();
		this->CapturePool.pop_front();

		Result = true;
	}
	else
	{
		this->RecvEvent->Reset();
	}

	CG.Close();

	return Result;
}

wstring RawSocket::getLastError()
{
	return this->LastError;
}

DWORD WINAPI RawSocket::CaptureThread(LPVOID lpParame)
{
	RawSocket* me = (RawSocket*) lpParame;

	WSADATA wsaData;
	DWORD ErrorCode = WSAStartup(MAKEWORD(2, 1),&wsaData);

	try
	{
		me->CreateSocket();

		while(!me->Terminated)
		{
			try
			{
				me->DoCapture();
			}
			catch(GLEO::Exception& ex)
			{
				me->LastError = ex.GetDescription();
				Sleep(100);
			}
			catch(...)
			{
				me->LastError = L"Unknow Error";
				Sleep(100);
			}
		}
	}
	catch(GLEO::Exception& ex)
	{
		me->LastError = ex.GetDescription();
		Sleep(100);
	}


	return 0;
}

void RawSocket::CreateSocket()
{
	SOCKADDR_IN sa;
	sa.sin_family = AF_INET;
	sa.sin_port = htons(0);
	sa.sin_addr.S_un.S_addr = this->LocalAddress;

	this->InterceptSocket = socket(AF_INET, SOCK_RAW, IPPROTO_IP);
	if(this->InterceptSocket == INVALID_SOCKET)
	{
		WinSocketException::Check("socket");
	}

	bind(this->InterceptSocket, (sockaddr*)&sa, sizeof(sa));
	WinSocketException::Check("bind");

	DWORD InBuffer;
	DWORD OutBuffer[10];
	DWORD ReturnBytes;

	InBuffer = 1;
	ReturnBytes = 0;
	WSAIoctl(this->InterceptSocket, SIO_RCVALL, &InBuffer, sizeof(InBuffer), OutBuffer, sizeof(OutBuffer), &ReturnBytes, NULL, NULL);
	WinSocketException::Check("Ioct");
}

void RawSocket::DoCapture()
{
	sockaddr* SourceIP;
	int SourceIPLen = sizeof(SourceIP);

//			int DataLen = recvfrom(me->InterceptSocket, (char*)me->RecvBuffer, sizeof(me->RecvBuffer), 0, SourceIP, &SourceIPLen);
	int DataLen = recv(this->InterceptSocket, (char*)this->RecvBuffer, MAX_PACK_LEN, 0);
	if(DataLen == SOCKET_ERROR)
	{
		WinSocketException::Check("recv");
	}
	else
	{
		if(DataLen >= sizeof(IPHeader))
		{
			CaptureData Data;
			memcpy(&Data.Header, this->RecvBuffer, sizeof(IPHeader));

			int HeaderLen = Data.Header.HeadLength();

			if(Data.Header.SourceIP == this->LocalAddress)
			{
				Data.OutDir = true;
			}
			else if(Data.Header.DestinIP == this->LocalAddress)
			{
				Data.OutDir = false;
			}

			switch(Data.Header.Protocol)
			{
			case IPPROTO_TCP:
				memcpy(&Data.ProtocolHeader.TCPPack, this->RecvBuffer + HeaderLen, sizeof(TCPHeader));
				HeaderLen += Data.ProtocolHeader.TCPPack.Length();
			break;

			case IPPROTO_UDP:
				memcpy(&Data.ProtocolHeader.UDPPack, this->RecvBuffer + HeaderLen, sizeof(UDPHeader));
				HeaderLen += 8;
			break;

			case IPPROTO_ICMP:
				memcpy(&Data.ProtocolHeader.ICMPPack, this->RecvBuffer + HeaderLen, sizeof(ICMPHeader));
			break;

			default:
			break;
			}

			Data.Data.clear();
			Data.Data.append((char*)this->RecvBuffer + HeaderLen, DataLen - HeaderLen);

			CriticalGuard CG(this->PoolGuard);

			if(this->callbackHandle)
			{
				this->callbackHandle->ReceiveFunc(Data);
			}
			else
			{
				this->CapturePool.push_back(Data);
			}

			this->RecvEvent->Set();

			CG.Close();
		}
		else
		{
		}
	}
}

ReadDataEventSource::ReadDataEventSource()
{
	this->callbackHandle = NULL;
}

void ReadDataEventSource::SetCallBack(ReadDataCallBack *handle)
{
	this->callbackHandle = handle;
}