#ifdef __BORLANDC__
#include <vcl.h>
#else
#include <nonvcl.h>
#endif

#pragma hdrstop

#include "Serial.h"
#include "std_Unicode.h"
#include "WinException.h"


//---------------------------------------------------------------------------
#ifdef __BORLANDC__
#pragma package(smart_init)
#endif

//---------------------------------------------------------------------------
//
// 	class CommParam
//
CommParam::CommParam()
{
	memset(this, 0, sizeof(*this));

	_DCB.DCBlength = sizeof(_DCB);

	_DCB.fBinary = true;
	_DCB.BaudRate = CBR_115200;
	_DCB.ByteSize = 8;
	_DCB.StopBits = ONESTOPBIT;
	_DCB.Parity = NOPARITY;
	_DCB.fBinary = true;
	_DCB.fParity = false;
	_DCB.XonChar = 13;
	_DCB.XoffChar = 11;
	_DCB.XoffLim = 500;
	_DCB.XonLim = 500;
	_DCB.ErrorChar = 0;
	_DCB.fDtrControl = true;
	_DCB.fRtsControl = true;


	OutTimes.ReadIntervalTimeout = 100;

	ReadBufferLen = 4096;
	WriteBufferLen = 4096;
}

DCB* CommParam::getDCB()
{
	return &_DCB;
}

COMMTIMEOUTS* CommParam::getTimes()
{
	return &OutTimes;
}

DWORD CommParam::getReadBufferLen()
{
	return ReadBufferLen;
}

DWORD CommParam::getWriteBufferLen()
{
	return WriteBufferLen;
}

//------------------------------------------------------------------------------------
//
// 	class CommExctption
//
CommExctption::CommExctption(TString place)
: WinException(place)
{
}

//------------------------------------------------------------------------------------
//
// 	class Serial::SerialOperator
//
Serial::SerialOperator::SerialOperator(Serial* ser)
: OperSection()
{
	Port = ser;
	OverLapedEvent = new ManualEvent(false);

	memset(&OverLapped, 0, sizeof(OverLapped));
	OverLapped.hEvent = OverLapedEvent->getHandle();
}

Serial::SerialOperator::~SerialOperator()
{
	DESTROY(OverLapedEvent);
}

void Serial::SerialOperator::Reset()
{
	OverLapedEvent->Reset();
}

HANDLE Serial::SerialOperator::getEventHandle()
{
	return OverLapedEvent->getHandle();
}

void Serial::SerialOperator::CheckPeddingError(DWORD result, wstring where)
{
	if(!result)
	{
		int ErrorCode = GetLastError();
		if(ErrorCode != ERROR_IO_PENDING)
		{
			Win32Lib::WinException(ErrorCode, where);
		}
	}
}

int  Serial::SerialOperator::CheckPeddingStatus(wstring where)
{
	bool HResult;
	DWORD NumofBytes;

	HResult = GetOverlappedResult(Port->PortHandle, &OverLapped, &NumofBytes, false);
	if(!HResult)
	{
		throw Win32Lib::WinException(where);
	}

	return NumofBytes;
}

//------------------------------------------------------------------------------------
//
// 	class Serial::SerialState
//
Serial::SerialState::SerialState(Serial* ser)
: SerialOperator(ser)
{
}

Serial::SerialState::~SerialState()
{
}

void Serial::SerialState::SetupEvent()
{
	bool HResult;

	HResult = WaitCommEvent(Port->PortHandle, &EventMask, &OverLapped);
	CheckPeddingError(HResult, L"Check Port State");
}

void Serial::SerialState::HandleEvent()
{
	CheckPeddingStatus(L"Get Port State");

	Port->ComStateEvent->Set();
}

//------------------------------------------------------------------------------------
//
// 	class Serial::SerialReader
//
Serial::SerialReader::SerialReader(Serial* ser)
: SerialOperator(ser), READ_DATA_LEN(256), ReadBuffer()
{
	ReadData = new char[READ_DATA_LEN];

	DataReadyEvent = new ManualEvent(false);
}

Serial::SerialReader::~SerialReader()
{
	DESTROY(ReadData);
}

void Serial::SerialReader::SetupEvent()
{
	bool HResult;

	CriticalGuard CG(OperSection);

	ReadDataLen = 0;

	HResult = ReadFile(Port->PortHandle, ReadData, READ_DATA_LEN, &ReadDataLen, &OverLapped);
	CheckPeddingError(HResult, L"Read Port");

	CG.Close();
}

void Serial::SerialReader::HandleEvent()
{
	try
	{
		int DataLen = CheckPeddingStatus(L"Check Read Status");

		CriticalGuard CG(OperSection);

		CG.Close();


		if(DataLen > 0)
		{
			ReadBuffer.getWriter()->Push((unsigned char*)ReadData, DataLen);
		}

		if(ReadBuffer.IsEmpty())
		{
			DataReadyEvent->Reset();
		}
		else
		{
			DataReadyEvent->Set();
		}
	}
	catch(GLEO::Exception ex)
	{
		Port->Errors->Push(ex.GetDescription());
	}
}

bool Serial::SerialReader::IsEmpty()
{
	return ReadBuffer.IsEmpty();
}

bool Serial::SerialReader::getData(string& data)
{
	bool Result;

	CriticalGuard CG(OperSection);

	Result =  ReadBuffer.getReader()->Pop(data);

	if(ReadBuffer.IsEmpty())
	{
		DataReadyEvent->Reset();
	}
	else
	{
		DataReadyEvent->Set();
	}

	CG.Close();

	return Result;
}

ManualEvent* Serial::SerialReader::getDataReadyEvent()
{
	return DataReadyEvent;
}

void Serial::SerialReader::Reset()
{
	SerialOperator::Reset();

	DataReadyEvent->Reset();

	ReadBuffer.Clear();
}

//------------------------------------------------------------------------------------
//
// 	class Serial::SerialWriter
//
Serial::SerialWriter::SerialWriter(Serial* ser)
: SerialOperator(ser), WriteBuffer()
{
	this->Idle = true;
}

Serial::SerialWriter::~SerialWriter()
{
}

void Serial::SerialWriter::InnerWrite(const char* data, int len)
{
	bool HResult;

	memset(&this->OverLapped, 0, sizeof(this->OverLapped));
	this->OverLapped.hEvent = this->getEventHandle();
	HResult = WriteFile(Port->PortHandle, data, len, &WriteDataLen, &OverLapped);
	CheckPeddingError(HResult, L"Write Port");

	this->Idle = false;
}

void Serial::SerialWriter::Write(string& data)
{
	CriticalGuard CG(OperSection);

	if(this->Idle)
	{
		InnerWrite(data.c_str(), data.length());
	}
	else
	{
		WriteBuffer.getWriter()->Push((unsigned char*)data.c_str(), data.length());
	}

	CG.Close();
}

void Serial::SerialWriter::SetupEvent()
{
	CriticalGuard CG(OperSection);

	if(!WriteBuffer.IsEmpty())
	{
		string s;

		if(WriteBuffer.getReader()->Pop(s))
		{
			InnerWrite(s.c_str(), s.length());
		}
	}
	else
	{
		this->OverLapedEvent->Reset();
		Idle = true;
	}

	CG.Close();
}


void Serial::SerialWriter::HandleEvent()
{
	CriticalGuard CG(OperSection);

//	CheckPeddingStatus(L"Check Write Status");

	CG.Close();
}

//------------------------------------------------------------------------------------
//
//	class Serial::MessageQueue
//
Serial::MessageQueue::MessageQueue()
: OperSection(), Messages()
{
	MessageEvent = new ManualEvent(false);
}

Serial::MessageQueue::~MessageQueue()
{
	delete MessageEvent;
}

bool Serial::MessageQueue::Pop(wstring& data)
{
	bool Result = false;

	CriticalGuard CG(OperSection);

	if(!Messages.empty())
	{
		data = Messages.front();

		Messages.pop_front();
		if(Messages.empty())
		{
			MessageEvent->Reset();
		}

		Result = true;
	}

	CG.Close();

	return Result;
}

bool Serial::MessageQueue::Push(wstring data)
{
	bool Result = true;

	CriticalGuard CG(OperSection);

	Messages.push_back(data);
	MessageEvent->Set();

	CG.Close();

	return Result;
}

HANDLE Serial::MessageQueue::getEventHandle()
{
	return MessageEvent->getHandle();
}

//------------------------------------------------------------------------------------
//
//	class Serial
//
Serial::Serial(void)
{
	PortHandle = INVALID_HANDLE_VALUE;

	QuittingEvent = new ManualEvent(false);
	SuppendEvent = new ManualEvent(true);

	ComStateEvent = new ManualEvent(false);
	ComErrorEvent = new ManualEvent(false);

	Reader = new SerialReader(this);
	Writer = new SerialWriter(this);
	State = new SerialState(this);
	Errors = new MessageQueue();

	HandleThreadStart = new ThreadStart(HandleThread, this);
	ProcessThreadStart = new ThreadStart(ProcessThread, this);
}

Serial::~Serial(void)
{
	Close();
	QuittingEvent->Set();

	HandleThreadStart->WaitForShutdown();
	ProcessThreadStart->WaitForShutdown();

	DESTROY(QuittingEvent);
	DESTROY(SuppendEvent);
	DESTROY(ComStateEvent);
	DESTROY(ComErrorEvent);
	DESTROY(Errors);
	DESTROY(State);
	DESTROY(Writer);
	DESTROY(Reader);

	DESTROY(HandleThreadStart);
	DESTROY(ProcessThreadStart);
}

void Serial::SetCommParam(CommParam& param)
{
	if(!SetupComm(PortHandle, param.getReadBufferLen(), param.getWriteBufferLen()))
	{
		throw Win32Lib::WinException(L"Setup Buffer");
	}

	if(!SetCommTimeouts(PortHandle, param.getTimes()))
	{
		throw Win32Lib::WinException(L"Setup Comm Timeouts");
	}

	if(!SetCommState(PortHandle, param.getDCB()))
	{
		throw Win32Lib::WinException(L"Setup Status");
	}

	if(!PurgeComm(PortHandle, PURGE_TXABORT | PURGE_RXABORT | PURGE_TXCLEAR | PURGE_RXCLEAR))
	{
		throw Win32Lib::WinException(L"Purge Comm");
	}
}

DWORD Serial::GetModemState()
{
	DWORD Status;

	if(PortHandle == INVALID_HANDLE_VALUE) throw CommExctption(L"Port Not Opened");

	if(!GetCommModemStatus(PortHandle, &Status))
	{
		throw Win32Lib::WinException(L"Get Mode Status");
	}

	return Status;
}

void Serial::Open(wstring port_name, CommParam& param)
{
	PortName = wstring(L"\\\\.\\") + port_name;

	this->Close();
	
	PortHandle = CreateFile(PortName.c_str(), GENERIC_READ | GENERIC_WRITE, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL | FILE_FLAG_OVERLAPPED, 0);
	if(PortHandle == INVALID_HANDLE_VALUE)
	{
		throw Win32Lib::WinException(L"Open Port");
	}

	try
	{
		SetCommParam(param);

		Writer->Reset();
		Reader->Reset();

		Reader->SetupEvent();

		SuppendEvent->Reset();
	}
	catch(...)
	{
		CloseHandle(PortHandle);
		PortHandle = INVALID_HANDLE_VALUE;
		SuppendEvent->Set();

		throw;
	}
}

void Serial::Close()
{
	SuppendEvent->Set();

	if(PortHandle != INVALID_HANDLE_VALUE)
	{
		PurgeComm(PortHandle, 0);
		CloseHandle(PortHandle);

		PortHandle = INVALID_HANDLE_VALUE;
	}
}

bool Serial::HasOpened()
{
	return (PortHandle != INVALID_HANDLE_VALUE);
}

bool Serial::getCTS()
{
	return (GetModemState() & MS_CTS_ON);
}

bool Serial::getDSR()
{
	return (GetModemState() & MS_DSR_ON);
}

bool Serial::getRING()
{
	return (GetModemState() & MS_RING_ON);
}

bool Serial::getRLSD()
{
	return (GetModemState() & MS_RLSD_ON);
}

void Serial::Write(string data)
{
	Writer->Write(data);
}

void Serial::Write(char* data, int len)
{
	string Data;
	Data.clear();

	Data.append(data, len);
	Writer->Write(Data);
}

void Serial::DoRecieveData()
{
	string Data;

	if(Reader->getData(Data))
	{
		if(ValidHandle())
		{
			((SerialCallBack*)getHandle())->OnData(Data);
		}
	}
}
void Serial::DoStateChange()
{
}

void Serial::DoCommError()
{
}

void Serial::DoError()
{
	wstring ErrorMsg;

	if(Errors->Pop(ErrorMsg))
	{
		if(ValidHandle())
		{
			((SerialCallBack*)getHandle())->OnError(ErrorMsg);
		}
	}
}

DWORD WINAPI Serial::ProcessThread(void* param)
{
	Win32Lib::SException::Install();

	Serial* TheSerial = static_cast<Serial*>(param);

	HANDLE Events[6];

	Events[0] = TheSerial->QuittingEvent->getHandle();
	Events[1] = TheSerial->SuppendEvent->getHandle();
	Events[2] = TheSerial->ComStateEvent->getHandle();
	Events[3] = TheSerial->Reader->getDataReadyEvent()->getHandle();
	Events[4] = TheSerial->ComErrorEvent->getHandle();
	Events[5] = TheSerial->Errors->getEventHandle();

	while(true)
	{
		try
		{
			DWORD WResult;

			while(TheSerial->SuppendEvent->CheckState())
			{
				if(TheSerial->QuittingEvent->CheckState()) break;
				Sleep(10);
			};

			WResult = WaitForMultipleObjects(6, Events, false, INFINITE);

			switch(WResult)
			{
			case WAIT_OBJECT_0:
				goto EndThread;

			case WAIT_OBJECT_0 + 1:
				break;

			case WAIT_OBJECT_0 + 2:
				TheSerial->DoStateChange();
				break;

			case WAIT_OBJECT_0 + 3:
				TheSerial->DoRecieveData();
				break;

			case WAIT_OBJECT_0 + 4:
					TheSerial->DoCommError();
				break;

			default:
				TheSerial->DoError();
				break;
			}
		}

#ifdef __BORLANDC__
		catch(Sysutils::Exception& ex)
		{
			TheSerial->Errors->Push(WideString(ex.Message).c_bstr());
		}
#endif
		catch(GLEO::Exception& ex)
		{
			TheSerial->Errors->Push(ex.GetDescription());
		}
		catch(std::exception& ex)
		{
			TheSerial->Errors->Push(~string(ex.what()));
		}
		catch(...)
		{
			TheSerial->Errors->Push(L"Unknow Exception");
		}
	};

EndThread:
	return 0;
}

DWORD WINAPI Serial::HandleThread(void* param)
{
	Win32Lib::SException::Install();

	Serial* TheSerial = static_cast<Serial*>(param);

	HANDLE Events[5];

	Events[0] = TheSerial->QuittingEvent->getHandle();
	Events[1] = TheSerial->SuppendEvent->getHandle();
	Events[2] = TheSerial->State->getEventHandle();
	Events[3] = TheSerial->Reader->getEventHandle();
	Events[4] = TheSerial->Writer->getEventHandle();

	while(true)
	{
		DWORD WResult;

		while(TheSerial->SuppendEvent->CheckState())
		{
			if(TheSerial->QuittingEvent->CheckState()) break;
			Sleep(10);
		};

		try
		{
			WResult = WaitForMultipleObjects(5, Events, false, INFINITE);

			switch(WResult)
			{
			case WAIT_OBJECT_0:
				goto EndThread;

			case WAIT_OBJECT_0 + 1:
				break;

			case WAIT_OBJECT_0 + 2:
				TheSerial->State->HandleEvent();
				TheSerial->State->SetupEvent();
				break;

			case WAIT_OBJECT_0 + 3:
				TheSerial->Reader->HandleEvent();
				TheSerial->Reader->SetupEvent();
				break;

			case WAIT_OBJECT_0 + 4:
				try
				{
					TheSerial->Writer->HandleEvent();
				}	
				catch(...)
				{
					TheSerial->Writer->SetupEvent();
					throw;
				}

				TheSerial->Writer->SetupEvent();
				break;
			}
		}
#ifdef __BORLANDC__
		catch(Sysutils::Exception& ex)
		{
			TheSerial->Errors->Push(WideString(ex.Message).c_bstr());
		}
#endif
		catch(GLEO::Exception& ex)
		{
			TheSerial->Errors->Push(ex.GetDescription());
		}
		catch(std::exception& ex)
		{
			TheSerial->Errors->Push(~string(ex.what()));
		}
		catch(...)
		{
			TheSerial->Errors->Push(L"Unknow Exception");
		}
	};

EndThread:
	return 0;
}

