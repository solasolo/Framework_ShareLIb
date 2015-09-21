#include "WinSocket.h"

//---------------------------------------------------------------------------

WinSocketException::WinSocketException(BaseSocket& socket, const wchar_t* where)
	:  WinException(WSAGetLastError(), where)
{
	if(&socket)
	{
		Handle = socket.getHandle();
	}
}

SOCKET WinSocketException::getHandle()
{
	return Handle;
}

wstring WinSocketException::GetDescription()
{
	wstring ErrDescription;
	wchar_t hs[15];
	
	if(Handle == INVALID_SOCKET)
	{
		ErrDescription = L"Connection NOT Available";
	}
	else
	{
		ErrDescription = Exception::GetDescription() + L"[Socket Handle:" + _itow((unsigned int)getHandle(), hs, 10) + L"]";
	}

	return ErrDescription;
}


WinSocketNoConnection::WinSocketNoConnection(BaseSocket& socket, const wchar_t* where)
	: WinSocketException(socket, where)
{
}

wstring WinSocketNoConnection::GetDescription()
{
	wstring ErrDescription;
	wchar_t hs[15];
	
	if(Handle == INVALID_SOCKET)
	{
		ErrDescription = L"SOCKET NOT Available";
	}
	else
	{
		ErrDescription = L"Connection NOT Available";
	}

	return ErrDescription;
}

//---------------------------------------------------------------------------
BaseSocket::BaseSocket()
{	
}

BaseSocket::BaseSocket(SOCKET s)
{
	if(s == INVALID_SOCKET)
	{
		throw Exception(L"Invalid Socket Handle");
	}

	InnerHandle = s; 
}

void BaseSocket::Startup()
{	
	WORD wVersionRequested = MAKEWORD( 2, 2 );
	WSADATA wsaData;

	int err;
	err =  WSAStartup(wVersionRequested, &wsaData);
	if (err != 0) throw WinException(err, "Initiates Socket");
}

void BaseSocket::Cleanup()
{
	WSACleanup();
}

void BaseSocket::Bind( char* strIP, unsigned int iPort )
{	
	if( strlen( strIP ) == 0 || iPort == 0 )
		throw Exception(L"IP address or port number is not correct!");

	memset( &m_sockaddr,0, sizeof( m_sockaddr ) );
	m_sockaddr.sin_family = AF_INET;
	m_sockaddr.sin_addr.s_addr = inet_addr( strIP );
	m_sockaddr.sin_port = htons( iPort );

	int ret_code = bind( InnerHandle, (SOCKADDR*)&m_sockaddr, sizeof( m_sockaddr)); 
	CheckError(L"Socket Bind", ret_code);
}

SOCKET BaseSocket::Accept()
{	
	int Len = sizeof( m_rsockaddr );

	memset( &m_rsockaddr, 0, sizeof( m_rsockaddr ) );

	SOCKET S;
	S = accept(InnerHandle, (SOCKADDR*)&m_rsockaddr, &Len);

	if(S == INVALID_SOCKET )
	{
		CheckError(L"Socket Accept", SOCKET_ERROR);
	}

    return S;
}

SOCKET BaseSocket::getHandle()
{
	return InnerHandle;
}

sockaddr_in BaseSocket::getLocalAddress()
{
	return m_sockaddr;
}

int BaseSocket::getLocalPort()
{
	return m_port;
}

void BaseSocket::CheckError(const wchar_t* Function, int ret_code )
{
	if( ret_code == SOCKET_ERROR )
		throw WinSocketException(*this, Function);
}

void BaseSocket::Name2Addr(char* strRemote, unsigned int iPort, sockaddr_in* addr)
{
	if( strlen( strRemote ) == 0 || iPort == 0 )
		throw Exception(L"Name is not correct!");

	hostent *hostEnt = NULL;
	long lIPAddress = 0;

	hostEnt = gethostbyname( strRemote );

	if( hostEnt != NULL )
	{
		lIPAddress = ((in_addr*)hostEnt->h_addr)->s_addr;
		addr->sin_addr.s_addr = lIPAddress;
	}
	else
	{
		addr->sin_addr.s_addr = inet_addr( strRemote );
	}

	addr->sin_family = AF_INET;
	addr->sin_port = htons(iPort);
}

//---------------------------------------------------------------------------

const int WinSocket::RECEIVE_BUFFER_LEN = 4096;

WinSocket::WinSocket()
{	
	this->ReceiveBuffer = NULL;
	this->ReceiveBuffer = new char[RECEIVE_BUFFER_LEN];

	Startup();
	Create();
}

WinSocket::WinSocket(SOCKET s)
	: BaseSocket(s) 
{
	this->ReceiveBuffer = NULL;
	this->ReceiveBuffer = new char[RECEIVE_BUFFER_LEN];

	Startup();
}

WinSocket::~WinSocket()
{
	Close();
	Cleanup();

	DESTROY(this->ReceiveBuffer);
}

void WinSocket::Create()
{
	if((InnerHandle = socket( AF_INET, SOCK_STREAM, IPPROTO_TCP )) == INVALID_SOCKET)
	{
        CheckError(L"Create Socket", SOCKET_ERROR);
	}
}

void WinSocket::Close()
{
	int ret_code;
	
	if(InnerHandle != INVALID_SOCKET)
	{
		ret_code = shutdown( InnerHandle, SD_BOTH );
//		CheckError(L"Shutdown Socket", ret_code);

		ret_code = closesocket( InnerHandle );
		CheckError(L"Close Socket", ret_code);
	}
}

void WinSocket::Connect(const char* strRemote, unsigned int iPort)
{
    Name2Addr((char*)strRemote, iPort, &m_sockaddr);

	int ret_code = connect( InnerHandle, (SOCKADDR*)&m_sockaddr, sizeof( m_sockaddr ));
	
    CheckError(L"Socket Connect", ret_code);
}

void WinSocket::Listen()
{
	int ret_code = listen(InnerHandle, SOMAXCONN); 
	
    CheckError(L"Socket Listen", ret_code);
}


void WinSocket::Send(const char* strData, unsigned int len )
{	
	int ret_code = 0;

	if( strData == NULL)
		throw Exception(L"Data or data length is not correct!");
	
	if(len > 0)	ret_code = send( InnerHandle, strData, len, 0 );

	CheckError(L"Socket Send", ret_code);
}

void WinSocket::Send(string& Data )
{
	Send(Data.c_str(), Data.length());
}

bool WinSocket::CanReceive()
{
	TIMEVAL tv = {0, 0};
	int ret_code; 
	fd_set fdr = {1, InnerHandle}; 

	ret_code = select(0, &fdr, NULL, NULL, &tv);//¼ì²é¿É¶Á×´Ì¬ 
	CheckError(L"Check Readable", ret_code);

	return ret_code  > 0 ? true : false;
}

// Return Value: the number of bytes received
int WinSocket::Receive( char* data, unsigned int len )
{
	if(data == NULL)
		throw Exception(L"Data or data length is not correct!");
	
	int RecvLen = 0;
	
	if(CanReceive())
	{
		RecvLen = recv( InnerHandle, data, len, 0 );
		CheckError(L"Soceket Receive", RecvLen);
	}
   
	return RecvLen;
}

int WinSocket::Receive(string& Data)
{
	int c;

	if(CanReceive())
	{

#if _MSC_VER < 1300
		Data = "";
#else
		Data.clear();
#endif

		c = recv(InnerHandle, this->ReceiveBuffer, RECEIVE_BUFFER_LEN, 0);
		CheckError(L"Soceket Receive", c);
		if(c > 0)
		{
			Data.append(this->ReceiveBuffer, c);
		}
	}

	return c;
}

