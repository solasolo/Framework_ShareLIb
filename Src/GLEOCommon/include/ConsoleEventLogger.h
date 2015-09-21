#pragma once
#include "EventLogger.h"

using namespace GLEO;

namespace GLEO
{

	enum ConsoleColor
	{
		BLUE = 1,
		GREEN,
		LIGNTBLUE,
		RED,
		PURPLE,
		YELLOW,
		WHITE,
		GRAY
	};


	//控制台日志
	class __declspec(dllexport) ConsoleEventLogger : public BaseEventLogger
	{
	protected:
		virtual void WriteLog(SYSTEMTIME& time, int Type, wstring Message);

	public:
		ConsoleEventLogger();

		virtual ~ConsoleEventLogger();
		virtual void CleanLogger(time_t last_time);
	};

}