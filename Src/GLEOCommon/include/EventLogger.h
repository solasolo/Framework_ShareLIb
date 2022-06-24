#ifndef EVENTLOGGER_H
#define EVENTLOGGER_H

#include <string>
#include <fstream>
#include <windows.h>
#include <list>

#include "Synchronization.h"

using namespace std;
using namespace Win32Lib;

namespace GLEO
{
	const int EVENT_LOGGER_BUFFER_SIZE = 1023;
	static __declspec(thread) wchar_t EventLoggerBuffer[EVENT_LOGGER_BUFFER_SIZE + 1];

	enum EventType
	{
		etWatchdog = 0,
		etRecord,
		etMessage,
		etWarrining,
		etError,
		etDebug,

		EventType_Count
	};

	class IEventCallBack
	{
	public:
		virtual void NotifyFunc(void* sender, const wstring& msg, EventType type = etMessage) = 0;
	};

	class __declspec(dllexport) IEventSource
	{
	public:
		virtual void SetCallBack(IEventCallBack* callback) = 0;
		virtual IEventCallBack* getHandle() = 0;
	};

	class EventCallBack : public IEventCallBack
	{
	};

	class __declspec(dllexport) EventSource : public IEventSource
	{
	protected:	
		IEventCallBack* CallBackHandle;
		bool ValidHandle();

		void DoCallBack(const wstring& msg, EventType type = etMessage);

		template<typename... Args>
		void DoNotify(EventType type, const wchar_t* fmt, Args... args);

	public:
		EventSource();

		virtual void SetCallBack(IEventCallBack* callback);
		virtual IEventCallBack* getHandle();
	};

	class IEventLogger
	{
	public:
		struct LogMessage
		{
			SYSTEMTIME Time;
			int Type;
			wstring Message;
		};

		virtual void Log(int Type, string Message) = 0;
		virtual void Log(int Type, wstring Message) = 0;
		virtual void BatchLog(list<LogMessage>* msgs) = 0;

		virtual void CleanLogger(time_t last_time) = 0;
	};

	class __declspec(dllexport) BaseEventLogger : public IEventLogger
	{
	private:

	protected:
		struct TimeStamp
		{
			time_t T;
			int MT;
		};

		static wchar_t const* EventTypeString[];

		CriticalSection Gate;

		BaseEventLogger();

		virtual void WriteLog(SYSTEMTIME& time, int Type, wstring Message) = 0;

	public:
		static wstring FormatDate(time_t t);
		static wstring FormatDate(SYSTEMTIME& t);
		static wstring FormatTime(SYSTEMTIME& t);
		static const wchar_t* getTypeString(EventType Type);

		virtual ~BaseEventLogger() {};

		void Log(int Type);

		template<typename... Args>
		void Log(int Type, wchar_t* fmt, Args... args);

		virtual void Log(int Type, string Message) throw();
		virtual void Log(int Type, wstring Message) throw();
		virtual void BatchLog(list<LogMessage>* msgs) throw();

		void Log(SYSTEMTIME& time, int Type, string Message) throw();
		void Log(SYSTEMTIME& time, int Type, wstring Message) throw();

		virtual void CleanLogger(time_t last_time) = 0;
	};

	class __declspec(dllexport) BaseTextLogger: public BaseEventLogger
	{
	private:
		

	protected:
		wofstream* LogFile;//原先私有
		wstring LastFileName;//原先私有

		wstring Path;
		wstring Prefix;

		static wstring MakeFileName(wstring prefix, wstring DateStr);

		void OpenLog(wstring file);
		void CloseLog();

	public:
		BaseTextLogger(){};
		BaseTextLogger(wstring path, wstring prefix);
		~BaseTextLogger();

		static void CleanLogger(wstring path, wstring prefix, time_t last_time);

		virtual void CleanLogger(time_t last_time);
	};

	class __declspec(dllexport) TextEventLogger : public BaseTextLogger
	{
	protected:
		virtual void WriteLog(SYSTEMTIME& time, int Type, wstring Message);

	public:
		TextEventLogger(wstring path, wstring prefix);
		virtual ~TextEventLogger();

		virtual void BatchLog(list<LogMessage>* msgs) throw();				
	};


	template<typename... Args>
	void EventSource::DoNotify(EventType type, const wchar_t* fmt, Args... args)
	{
		wchar_t* buf = EventLoggerBuffer;
		// wchar_t buf[EVENT_LOGGER_BUFFER_SIZE + 1];

		_snwprintf(buf, EVENT_LOGGER_BUFFER_SIZE, fmt, args...);

		this->DoCallBack(buf, type);
	}


	template<typename... Args>
	void BaseEventLogger::Log(int Type, wchar_t* fmt, Args... args)
	{
		wchar_t* buf = EventLoggerBuffer;
		// wchar_t buf[EVENT_LOGGER_BUFFER_SIZE + 1];

		_snwprintf(buf, EVENT_LOGGER_BUFFER_SIZE, fmt, args...);

		this->Log(Type, wstring(buf));
	}
}

#endif