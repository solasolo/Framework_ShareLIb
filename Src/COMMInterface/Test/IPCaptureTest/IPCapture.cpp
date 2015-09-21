// IPCapture.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <conio.h>
#include <winsock2.h>
#include <string>

#include "RawSocket.h"

using namespace std;

void FormatPackageData(CaptureData& data)
{
	in_addr addr;

	cout << ~data.getType();
	addr.S_un.S_addr = data.Header.SourceIP;
	cout << "    <From> " << inet_ntoa(addr);
	addr.S_un.S_addr = data.Header.DestinIP;
	cout << "    <To> " << inet_ntoa(addr);

	cout << endl;
	cout << data.Data << endl << endl;
}

void ShowPacageData(CaptureData& data)
{

	cout <<  ~data.getType() << data.Data << endl;
}

int _tmain(int argc, _TCHAR* argv[])
{	
	string IP = "127.0.0.1";

	if(argc > 1)
	{
		IP = ~wstring(argv[1]);	
	}

	cout << "Spy on " << IP << endl << endl;

	RawSocket Spy(IP.c_str());

	CaptureData Data;

	while(!kbhit())
	{
		if(Spy.Read(Data))
		{
			FormatPackageData(Data);
		}
	}

	getch();

	return 0;
}

