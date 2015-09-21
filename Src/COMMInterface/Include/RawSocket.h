//---------------------------------------------------------------------------

#ifndef RawSocketH
#define RawSocketH

#include <Winsock2.h>
#include <string>
#include <deque>

#include "WinException.h"
#include "Synchronization.h"
#include "ThreadWrap.h"
#include "WinSocket.h"
#include "EventLogger.h"

using namespace std;
using namespace Win32Lib;

//---------------------------------------------------------------------------

#pragma pack(push, 1)

struct EthernetHeader
{
	static const int ETHER_ADDR_LEN = 6;

	unsigned char DestinMAC[ETHER_ADDR_LEN];    /* destination host address */
	unsigned char SourceMAC[ETHER_ADDR_LEN];    /* source host address */
	unsigned Type;                     					/* IP? ARP? RARP? etc */
};

/* IP header */
struct IPHeader
{
	unsigned char VHL;                 /* version << 4 | header length >> 2 */
	unsigned char TOS;
	unsigned short Length;
	unsigned short ID;
	unsigned short Offset;
	unsigned char TTL;
	unsigned char Protocol;
	unsigned short CheckSum;
	unsigned long SourceIP;
	unsigned long DestinIP;

	static const unsigned short IP_RF = 0x8000;            /* reserved fragment flag */
	static const unsigned short IP_DF = 0x4000;            /* dont fragment flag */
	static const unsigned short IP_MF = 0x2000;            /* more fragments flag */
	static const unsigned short IP_OFFMASK = 0x1fff;       /* mask for fragmenting bits */

	inline int Version()
	{
		return (this->VHL >> 4);
	}

	inline int HeadLength()
	{
		return (this->VHL & 0x0f) * 4;
	}

	inline int Size()
	{
		return ntohs(this->Length);
	}
};

struct UDPHeader
{
	unsigned short SourcePort;               /* source port */
	unsigned short DestinPort;               /* destination port */
	unsigned short Length;                 /* sequence number */
	unsigned short CheckSum;                 /* checksum */

	inline int Size()
	{
		return ntohs(this->Length);
	}

	inline unsigned short GetSourcePort()
	{
		return htons(this->SourcePort); 
	}
	
	inline unsigned short GetDestinPort()
	{
		return htons(this->DestinPort); 
	}
};

struct TCPHeader
{
	static const unsigned char TH_FIN = 0x01;
	static const unsigned char TH_SYN = 0x02;
	static const unsigned char TH_RST = 0x04;
	static const unsigned char TH_PUSH = 0x08;
	static const unsigned char TH_ACK = 0x10;
	static const unsigned char TH_URG = 0x20;
	static const unsigned char TH_ECE = 0x40;
	static const unsigned char TH_CWR = 0x80;

	unsigned short SourcePort;               
	unsigned short DestinPort;              
	unsigned long Sequence;                
	unsigned long Ack;               
	unsigned char Offset;             
	unsigned char Flags;
	unsigned short Window;                
	unsigned short CheckSum;             
	unsigned short Urgent;               

	inline int Length()
	{
		return ( (this->Offset & 0xf0) >> 4 ) * 4;
	}

	inline unsigned short GetSourcePort()
	{
		return htons(this->SourcePort); 
	}
	
	inline unsigned short GetDestinPort()
	{
		return htons(this->DestinPort); 
	}
};

struct ICMPHeader
{
	unsigned char Type;
	unsigned char Code;
	unsigned short CheckSum;
	unsigned short ID;
	unsigned short Sequence;
};

#pragma pack(pop)

struct CaptureData
{
	bool OutDir;

	IPHeader Header;
	union
	{
		TCPHeader TCPPack;
		UDPHeader UDPPack;
		ICMPHeader ICMPPack;
	} ProtocolHeader;

	string Data;

	wstring getType()
	{
		switch(Header.Protocol)
		{
				case IPPROTO_TCP:
					return L" TCP";
				break;

				case IPPROTO_UDP:
					return L" UDP";
				break;

				case IPPROTO_ICMP:
					return L"ICMP";
				break;
		}
	}
};

class ReadDataCallBack : public EventCallBack
{
public: 
	virtual void ReceiveFunc(CaptureData& data) = 0;
};

class __declspec(dllexport) ReadDataEventSource
{
protected:
	ReadDataCallBack* callbackHandle;

public:
	ReadDataEventSource();
	void SetCallBack(ReadDataCallBack* handle);
};

class __declspec(dllexport) RawSocket : public ReadDataEventSource
{
	static const int MAX_PACK_LEN = 65535;

public:
	RawSocket(string addr);
	~RawSocket();

	void Clear();
	bool Read(CaptureData& msg);
	wstring getLastError();

protected:
	static DWORD WINAPI CaptureThread(LPVOID lpParame);

	ThreadStart* CaptureThreadStart;
	ManualEvent* RecvEvent;

private:
	bool Terminated;
	unsigned long LocalAddress;
	wstring LastError;

	CriticalSection PoolGuard;

	unsigned char* RecvBuffer;
	SOCKET InterceptSocket;
	deque<CaptureData> CapturePool;

	void CreateSocket();
	void DoCapture();
};

#endif