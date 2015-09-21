// LogMonitor.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <Winsock2.h>
#include <Windows.h>
#include <conio.h>
#include <iostream>

#include "EventLogger.h"
#include "WinTCP.h"

using namespace GLEO;
using namespace std;

class Monitor : public TCPCallBack
{
private:
	TCPClient* Client;

public:
	Monitor(string ip, int port)
	{
		this->Client = new TCPClient(ip, port);
		this->Client->SetCallBack(this);

		wcout.imbue(locale("chs"));
	}

	virtual void ReceiveFunc(TCPConnection& conn)
	{
		StreamBuffer& buff = conn.GetData();

		int len = buff.getSize();

		while(len > 0)
		{
			string msg;
			buff.PickData(msg, len);

			wcout << ~msg;

			len = buff.getSize();
		}
	}

	virtual void NotifyFunc(void* sender, wstring& msg, EventType type = etMessage)
	{
		wcout << msg << endl;	
	}
};


int _tmain(int argc, _TCHAR* argv[])
{
	int port = 4444;

	if(argc >= 2)
	{
		port = _wtoi(argv[1]);
	}

	Monitor* m = new Monitor("127.0.0.1", port);

	while(true)
	{
		if(kbhit())
		{
			if(getch() == 27) break;
		}
		
		Sleep(100);
	}

	delete m;

	return 0;
}

