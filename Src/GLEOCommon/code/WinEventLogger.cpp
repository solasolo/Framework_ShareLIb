#include <ctime>
#include <fstream>

#include "WinEventLogger.h" 
#include "CommonFuncs.h"

namespace Win32Lib
{
	WinEventLogger::WinEventLogger(wstring source_name)
	{
		EventHandle = 0;
		SourceName = source_name;
	}

	WinEventLogger::~WinEventLogger()
	{
		if(EventHandle != 0)
		{
			DeregisterEventSource(EventHandle);
		}
	}

	void WinEventLogger::WriteLog(SYSTEMTIME& time, int Type, wstring Message) throw()
	{
		if(EventHandle == 0)
			EventHandle = RegisterEventSource(NULL, (SourceName).c_str());
		
		LPCWSTR Msg = (Message).c_str(); 
		
		int	ReportType;
		switch(Type)
		{
		case etError:
			ReportType = EVENTLOG_ERROR_TYPE;
			break;

		case etWarrining:
			ReportType = EVENTLOG_WARNING_TYPE;
			break;

		default:
			ReportType = EVENTLOG_INFORMATION_TYPE;
		}

		ReportEvent(EventHandle, ReportType, 0, 0, NULL, 1, 0, &Msg, NULL);
	}

	void WinEventLogger::CleanLogger(time_t last_time)
	{
	}
}