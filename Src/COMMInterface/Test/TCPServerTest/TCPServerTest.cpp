// TCPServerTest.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "WinTCP.h"

#include <iostream>
#include <string>
#include <ctime>
#include <conio.h>

using namespace std;

class TCPCB : public TCPCallBack
{
public:
	void NotifyFunc(string& msg, EventType type);

	virtual void OnReceived(TCPConnection& conn);
	virtual void NotifyFunc(void* sender, wstring& msg, EventType type = etMessage);
};

void TCPCB::NotifyFunc(void* sender, wstring& msg, EventType type)
{
	wcout<<msg<<endl;
}

void TCPCB::NotifyFunc(string& msg, EventType type)
{
	cout << msg << endl;
}

void TCPCB::OnReceived(TCPConnection& conn)
{
	string data;
	StreamBuffer& s = conn.GetData();
	s.PickData(data, s.getSize());

	cout << "Server Got: " << data << endl;
}

int _tmain(int argc, _TCHAR* argv[])
{
	char buf[20];

	string ip = "127.0.0.1";
	int port = 4444;

	if(argc >=3)
	{
		ip = argv[1];
		port = atoi(argv[2]);
	}

	TCPServer  Server (ip, port);
	cout << "server Socket has created!" << endl;

	TCPCB cb;
	Server.SetCallBack(&cb);

	while(!kbhit())
	{
		try
		{
			//Server.SendAll(string("ab123fghi"));
			Server.SendAll(string("afrom server ") + _strtime(buf));
			Sleep(1000);
		}
		catch(WinSocketException e)
		{
			wcout << e.where() << L":" << e.why() << L":" << e.what() << endl;
		}
		catch(WinException e)
		{
			wcout << e.where() << L":" << e.why() << L":" << e.what() << endl;
		}

	};

	return 0;
}
