// LogMonitor.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <Winsock2.h>
#include <Windows.h>
#include <conio.h>
#include <iostream>

#include "EventLogger.h"
#include "WinTCP.h"
#include "SimpleProtocol.h"
#include "ConsoleEventLogger.h"

using namespace GLEO;
using namespace std;

void WriteConsole(wstring s)
{
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hOut, ConsoleColor::GRAY);
	
	wcout << s << endl;
}

class Monitor : public TCPCallBack
{
private:
	bool InClear;	

	TCPClient* Client;
	ConsoleEventLogger logger;

protected:
	virtual void OnReceived(TCPConnection& conn);
	virtual void NotifyFunc(void* sender, wstring& msg, EventType type = etMessage);

public:
	Monitor(string ip, int port);

	void Check();
	void Clean();
};

Monitor::Monitor(string ip, int port)
{
	this->InClear = false;

	this->Client = new TCPClient(ip, port);
	this->Client->SetCallBack(this);

	wcout.imbue(locale("chs"));
}

void Monitor::Check()
{
	string s = ".";
	this->Client->Send(s);
}

void Monitor::Clean()
{
	this->InClear = true;
}

void Monitor::OnReceived(TCPConnection& conn)
{
	StreamBuffer& buff = conn.GetData();

	short cmd;
	string Data;
	SimpleFrameCodec sfdc;

	while(sfdc.Decode(buff, cmd, Data))
	{
		SimpleProtocolDecoder spd(Data);

		int Type;
		SYSTEMTIME Time;
		wstring Message;

		spd.Read(Type);
		spd.RawRead(&Time, sizeof(Time));
		spd.Read(Message);

		this->logger.Log(Time, Type, Message);
	}

	this->InClear = false;
}

void Monitor::NotifyFunc(void* sender, wstring& msg, EventType type)
{
	WriteConsole(msg);
}

int _tmain(int argc, _TCHAR* argv[])
{
	string ip = "127.0.0.1";
	int port = 4444;

	if(argc >= 2)
	{
		ip = ~wstring(argv[1]);
	}

	if(argc >= 3)
	{
		port = _wtoi(argv[2]);
	}

	Monitor* m = new Monitor(ip, port);

	int c = 0;
	while(true)
	{
		int k = 0;

		try
		{
			if(kbhit())
			{
				k = getch();
			}

			if(k == 27) break;
			if(k = 'c') 

			Sleep(100);

			c++;
			if(c > 20)
			{
				c = 0;
				m->Check();
			}
		}
		catch(Exception& ex)
		{
			WriteConsole(ex.GetDescription());
		}
		catch(exception& ex)
		{
			WriteConsole(~string(ex.what()));
		}
		catch(...)
		{
			WriteConsole(L"Unknown Error");
		}
	}

	delete m;

	return 0;
}

