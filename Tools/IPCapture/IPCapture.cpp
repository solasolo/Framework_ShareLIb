// IPCapture.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <conio.h>
#include <winsock2.h>
#include <string>

#include "RawSocket.h"

using namespace std;

string IP = "192.168.1.5";
int Port = 0;
bool Binary = true;

void FormatHex(string& buf)
{
	int l = buf.size();
	for (int i = 0; i < l; i++)
	{
        unsigned char v;
		char d;
		
		v = buf[i];
		d = (v & 0xf0) >> 4;
		d = (d > 9) ? (d + '7') : (d + '0'); 
		cout << d;

		d = v & 0x0f;
		d = (d > 9) ? (d + '7') : (d + '0');
		cout << d;
        
		cout << " ";

        if (i % 16 == 15)
        {
            cout << endl;
        }
    }
}

void FormatPackageData(CaptureData& data)
{
	in_addr addr;

	switch(data.Header.Protocol)
	{
	case IPPROTO_TCP:
		{
			TCPHeader& th = data.ProtocolHeader.TCPPack;

			if(Port == 0 || th.GetDestinPort() == Port)
			{
				cout << ~data.getType();
	
				if(th.Flags != 0)
				{
					cout << "(";
					if(th.Flags & TCPHeader::TH_ACK) cout << "A";
					if(th.Flags & TCPHeader::TH_SYN) cout << "S";
					if(th.Flags & TCPHeader::TH_FIN) cout << "F";
					cout << ")"; 
				}

				addr.S_un.S_addr = data.Header.SourceIP;
				cout << "    <From> " << inet_ntoa(addr) << ":" << th.GetSourcePort();
				addr.S_un.S_addr = data.Header.DestinIP;
				cout << "    <To> " << inet_ntoa(addr) << ":" << th.GetDestinPort();
				cout << endl;

				if(Binary)
				{
					FormatHex(data.Data);
					cout << endl;
				}
				else
				{
					if(data.Data.size() > 0) cout << data.Data << endl; 
				}

				cout << endl;
			}
		}
		break;

	case IPPROTO_UDP:
		break;

	case IPPROTO_ICMP:
		{	
			/*
			cout << ~data.getType();
		
			addr.S_un.S_addr = data.Header.SourceIP;
			cout << "    <From> " << inet_ntoa(addr);
			addr.S_un.S_addr = data.Header.DestinIP;
			cout << "    <To> " << inet_ntoa(addr);
			cout << endl;

			if(data.Data.size() > 0) cout << data.Data << endl; 
			
			cout << endl;
			*/
		}
		break;
	}
}

void ShowPacageData(CaptureData& data)
{

	cout <<  ~data.getType() << data.Data << endl;
}

int _tmain(int argc, _TCHAR* argv[])
{	

	if(argc > 1)
	{
		IP = ~wstring(argv[1]);	
	}

	if(argc > 2)
	{
		Port = _wtoi(argv[2]);
	}

	cout << "Spy on " << IP << ":" << Port << endl << endl;

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

