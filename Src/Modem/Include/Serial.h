#ifndef SERIAL_H
#define SERIAL_H

#include <string>
#include <deque>
#include <windows.h>

#include "CommonFuncs.h"
#include "WinException.h"
#include "Synchronization.h"
#include "CommBuffer.h"
#include "ThreadWrap.h"

using namespace std;
using namespace Win32Lib;

class _declspec(dllexport) CommParam
{
private:
	DCB _DCB;
	COMMTIMEOUTS OutTimes;
	DWORD ReadBufferLen;
	DWORD WriteBufferLen;

public:
	CommParam();

	DCB* getDCB();
	COMMTIMEOUTS* getTimes();
	DWORD getReadBufferLen();
	DWORD getWriteBufferLen();
};

class _declspec(dllexport) CommExctption : WinException
{
public:
	CommExctption(TString place);
};

class SerialCallBack : public IEventCallBack
{
public:
	virtual void OnData(string& data) = 0;
	virtual void OnState(int state) = 0;
	virtual void OnCommError(int code) = 0;
	virtual void OnError(wstring& error) = 0;
};

class _declspec(dllexport) Serial : public EventSource
{
	class SerialOperator
	{
	protected:
		Serial* Port;

		ManualEvent* OverLapedEvent;
		OVERLAPPED OverLapped;
		CriticalSection OperSection;

		void CheckPeddingError(DWORD result, wstring where);
		int CheckPeddingStatus(wstring where);

	public:
		SerialOperator(Serial* ser);
		~SerialOperator();

		HANDLE getEventHandle();

		virtual void Reset();

		virtual void SetupEvent() = 0;
		virtual void HandleEvent() = 0;
	};

	class SerialState : public SerialOperator
	{
	private:
		DWORD EventMask;

	public:
		SerialState(Serial* ser);
		~SerialState();

		virtual void SetupEvent();
		virtual void HandleEvent();
	};

	class SerialReader : public SerialOperator
	{
		const DWORD READ_DATA_LEN;

	private:
		char* ReadData;
		DWORD ReadDataLen;
		CommBuffer ReadBuffer;

		ManualEvent* DataReadyEvent;

		void InnerRead();

	public:
		SerialReader(Serial* ser);
		~SerialReader();

		void Read(string& data);
		bool IsEmpty();
		bool getData(string& data);
		ManualEvent* getDataReadyEvent();

		virtual void Reset();

		virtual void SetupEvent();
		virtual void HandleEvent();
	};

	class SerialWriter : public SerialOperator
	{
	private:
		DWORD WriteDataLen;
		bool Idle;
		CommBuffer WriteBuffer;

		void InnerWrite(const char* data, int len);

	public:
		SerialWriter(Serial* ser);
		~SerialWriter();

		void Write(string& data);

		virtual void SetupEvent();
		virtual void HandleEvent();
	};

	class MessageQueue
	{
	private:
		ManualEvent* MessageEvent;
		CriticalSection OperSection;

		deque<wstring>Messages;

	public:
		MessageQueue();
		~MessageQueue();

		HANDLE getEventHandle();

		bool Pop(wstring& data);
		bool Push(wstring data);
	};

	friend SerialOperator;
	friend SerialReader;
	friend SerialWriter;
	friend SerialState;

private:
	SerialReader* Reader;
	SerialWriter* Writer;
	SerialState* State;

	MessageQueue* Errors;

	wstring PortName;
	HANDLE PortHandle;

	ManualEvent* QuittingEvent;
	ManualEvent* SuppendEvent;

	ManualEvent* ComStateEvent;
	ManualEvent* ComErrorEvent;

	ThreadStart* HandleThreadStart;
	ThreadStart* ProcessThreadStart;

	static DWORD WINAPI HandleThread(void* param);
	static DWORD WINAPI ProcessThread(void* param);

	void SetCommParam(CommParam& param);
	DWORD GetModemState();

	void DoRecieveData();
	void DoStateChange();
	void DoCommError();
	void DoError();

public:
	Serial(void);
	~Serial(void);

	void Open(wstring port_name, CommParam& param);
	void Close();

	void Write(string data);
	void Write(char* data, int len);
	void Break(bool state);

	bool getCTS();
	bool getDSR();
	bool getRING();
	bool getRLSD();

	void setDTR(bool state);
	void setRTS(bool state);

	void ClearBuffer();

	bool IsSendBufferEmpty();
	bool IsReceiveBufferEmpty();
	bool HasOpened();
};

#endif
