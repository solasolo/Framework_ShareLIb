#include "ConsoleEventLogger.h"

namespace GLEO
{

	ConsoleEventLogger::ConsoleEventLogger(void)
		: BaseEventLogger()
	{
	}


	ConsoleEventLogger::~ConsoleEventLogger(void)
	{
	}


	void ConsoleEventLogger::WriteLog(SYSTEMTIME& time, int Type, wstring Message)
	{
		wstring sTime;
		sTime = FormatTime(time);

		wstring sType;
		if(Type < EventType_Count)
		{
			sType = EventTypeString[Type];
		}
		else
		{
			sType = Type;
		}

		HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);

		//setlocale( LC_CTYPE, "" );
		//setlocale(LC_ALL, "chinese");
		setlocale(LC_ALL, "chs");
		wcout.imbue(locale("chs"));
		
		//SetConsoleTextAttribute(hOut, FOREGROUND_GREEN);
		switch(Type)
		{
		case EventType::etWatchdog:
			SetConsoleTextAttribute(hOut, ConsoleColor::PURPLE);
			break;
		case EventType::etRecord:
			SetConsoleTextAttribute(hOut, ConsoleColor::GRAY);
			break;
		case EventType::etMessage:
			SetConsoleTextAttribute(hOut, ConsoleColor::WHITE);
			break;
		case EventType::etWarrining:
			SetConsoleTextAttribute(hOut, ConsoleColor::YELLOW);
			break;
		case EventType::etError:
			SetConsoleTextAttribute(hOut, ConsoleColor::RED);
			break;
		case EventType::etDebug:
			//system("color 07");
			SetConsoleTextAttribute(hOut, ConsoleColor::GREEN);
			break;
		}
		//cout << ~sTime << "\t" << ~sType << "\t" << ~Message << endl;
		wcout << sTime << L"\t" << sType << L"\t" << Message << endl;
	}

	void ConsoleEventLogger::CleanLogger(time_t last_time)
	{

	}

}