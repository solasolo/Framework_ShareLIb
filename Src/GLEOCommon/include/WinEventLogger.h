#ifndef WINEVENTLOGGER_H
#define WINEVENTLOGGER_H

#include <string>

#include "EventLogger.h"
#include "ThreadWrap.h"

using namespace std; 
using namespace GLEO;

namespace Win32Lib
{
	class __declspec(dllexport) WinEventLogger : public BaseEventLogger
	{
	private:
		HANDLE EventHandle;
		wstring SourceName;

	protected:
		virtual void WriteLog(SYSTEMTIME& time, int Type, wstring Message) throw();

	public:
		WinEventLogger(wstring source_name);
		~WinEventLogger();

		virtual void CleanLogger(time_t last_time);
	};
}

#endif