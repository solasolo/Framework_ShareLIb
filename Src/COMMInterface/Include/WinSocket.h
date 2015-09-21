#pragma once

#ifndef _WINSOCKET_H
#define _WINSOCKET_H


#include <Winsock2.h>
#include <Windows.h>

#include <exception>
#include <string>

#include "WinException.h"

using namespace std;
using namespace Win32Lib;

#pragma warning(disable:4786)

class BaseSocket;	

class __declspec(dllexport) WinSocketException : public WinException
{
protected:
	SOCKET Handle;

public:
	WinSocketException(BaseSocket& socket, const wchar_t* where);

	wstring GetDescription();
	SOCKET getHandle();
};

class __declspec(dllexport) WinSocketNoConnection : public WinSocketException
{
public:
	WinSocketNoConnection(BaseSocket& socket, const wchar_t* where);

	wstring GetDescription();
};

class __declspec(dllexport) BaseSocket
{
public:	
	BaseSocket();		
	BaseSocket(SOCKET s);		

	virtual void Bind(char* IP, unsigned int Port);
	virtual SOCKET Accept();

	SOCKET getHandle();
	sockaddr_in getLocalAddress();
	int getLocalPort();
	sockaddr_in getRemoteAddress();
	int getRemotePort();

	static void Startup();
	static void Cleanup();

protected:	
	int SocketVersion;					
	SOCKET InnerHandle;	

	struct sockaddr_in m_sockaddr;		
	struct sockaddr_in m_rsockaddr;		
	int m_port;
	int m_rport;

	void Name2Addr( char* IP, unsigned int Port, sockaddr_in* addr);
	virtual void CheckError(const wchar_t* Function, int ret_code);
};

class __declspec(dllexport) WinSocket	: public BaseSocket
{
public:	
	WinSocket();		
	WinSocket(SOCKET s);		
	~WinSocket();		

	void Connect(const char* RemoteIP, unsigned int RemotePort);
	void Listen();
	bool CanReceive();

	void Send(const char* data, unsigned int len);
	void Send(string& data);
	int Receive( char* data, unsigned int len);
	int Receive(string& data);

private:	
	static const int RECEIVE_BUFFER_LEN;
	char* ReceiveBuffer;

	void Create();				
	void Close();				
};

#endif

