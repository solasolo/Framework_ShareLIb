// TCPClientTest.cpp : Defines the entry point for the console application.
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
protected:
	virtual void OnReceived(TCPConnection& conn);
	virtual void NotifyFunc(void* sender, const wstring& msg, EventType type = etMessage);

public:
	void NotifyFunc(string& msg, EventType type);
};

void TCPCB::NotifyFunc(void* sender, const wstring& msg, EventType type)
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
	s.PickData(data,s.getSize());

	cout << "Client Got: " << data << endl;
}

int _tmain(int argc, _TCHAR* argv[])
{
	wstring ip = L"127.0.0.1";
	int port = 4444;

	if(argc >=3)
	{
		ip = argv[1];
		port = _wtoi(argv[2]);
	}

	char buf[20];
	TCPClient Client(~ip, port);
	cout << "client Socket has created!" << endl;
	
	TCPCB  cb;
	Client.SetCallBack(&cb);
	//while(!Client.IsOnline())
	//{
	//	try
	//	{
	//		Client.Connect((char*)IP.c_str(), 4444);
	//	}
	//	catch(WinSocketException e)
	//	{
	//		wcout << e.where() << L":" << e.why() << L":" << e.what() << endl;
	//	}
	//	catch(WinException e)
	//	{
	//		wcout << e.where() << L":" << e.why() << L":" << e.what() << endl;
	//	}
	//}
	

	while(!kbhit())
	{
		try
		{
			while(Client.IsOnline())
			{
				Client.Send(string("from client ") + _strtime(buf));
				Sleep(1000);
			}

			Sleep(100);
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

