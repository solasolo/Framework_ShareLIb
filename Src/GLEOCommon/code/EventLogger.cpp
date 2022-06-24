
#include <ctime>
#include <vector>
#include <sstream>
#include <io.h>
#include <windows.h>
#include <stdarg.h>

#include "EventLogger.h"

using namespace std;

namespace GLEO
{
	// const int EVENT_LOGGER_BUFFER_SIZE = 1023;
	// __declspec(thread) wchar_t EventLoggerBuffer[EVENT_LOGGER_BUFFER_SIZE + 1];
}

namespace GLEO
{
	EventSource::EventSource()
	{
		this->CallBackHandle = NULL;
	}

	bool EventSource::ValidHandle()
	{
		return (this->CallBackHandle != NULL);
	}

	void EventSource::SetCallBack(IEventCallBack* callback)
	{
		CallBackHandle = callback;
	}

	IEventCallBack* EventSource::getHandle()
	{
		return CallBackHandle;
	}

	void EventSource::DoCallBack(const wstring& msg, EventType type)
	{
		IEventCallBack* Handle = getHandle();//(EventCallBack*)
		if (Handle)
		{
			Handle->NotifyFunc(this, msg, type);
		}
	}
}

namespace GLEO
{
	wchar_t const* BaseEventLogger::EventTypeString[] =
	{
		L"-WDG",
		L"-RCD",
		L"-MSG",
		L"-WRN",
		L"-ERR",
		L"-DBG"
	};

	BaseEventLogger::BaseEventLogger()
	{
	}

	wstring BaseEventLogger::FormatDate(SYSTEMTIME& t)
	{
		wchar_t buf[20];

		buf[19] = L'\x0';
		swprintf_s(buf, 19, L"%04d%02d%02d", t.wYear, t.wMonth, t.wDay);

		return buf;
	}

	wstring BaseEventLogger::FormatDate(time_t t)
	{
		wchar_t buf[20];

		buf[19] = L'\x0';
		tm* NowStruct = localtime(&t);

		swprintf_s(buf, 19, L"%02d%02d%02d", NowStruct->tm_year - 100, NowStruct->tm_mon + 1, NowStruct->tm_mday);

		return buf;
	}

	wstring BaseEventLogger::FormatTime(SYSTEMTIME& t)
	{
		wchar_t buf[20];

		buf[19] = L'\x0';

		swprintf_s(buf, 19, L"%02d:%02d:%02d.%03d", t.wHour, t.wMinute, t.wSecond, t.wMilliseconds);

		return buf;
	}

	const wchar_t* BaseEventLogger::getTypeString(EventType Type)
	{
		const wchar_t* Result;
		
		if(Type < EventType_Count)
		{
			Result = EventTypeString[Type];
		}
		else
		{
			Result = L"UKN";
		}

		return Result;
	}
	
	void BaseEventLogger::Log(int Type)
	{
		//Buffer[1023] = '\x0';
		//wstring Message = BaseEventLogger::Buffer;

		//this->Log(Type, Message);
	}

	void BaseEventLogger::Log(int Type, string Message) throw()
	{
		SYSTEMTIME time;
		GetLocalTime(&time);

		this->Log(time, Type, ~Message);
	}

	void BaseEventLogger::Log(int Type, wstring Message) throw()
	{
		SYSTEMTIME time;
		GetLocalTime(&time);

		this->Log(time, Type, Message);
	}

	void BaseEventLogger::Log(SYSTEMTIME& time, int Type, string Message) throw()
	{
		CriticalGuard CG(Gate);

		try
		{
			this->WriteLog(time, Type, ~Message);
		}
		catch(...)
		{
		}

		CG.Close();
	}

	void BaseEventLogger::Log(SYSTEMTIME& time, int Type, wstring Message)
	{
		CriticalGuard CG(Gate);

		try
		{
			this->WriteLog(time, Type, Message);
		}
		catch(...)
		{
		}

		CG.Close();
	}

	void BaseEventLogger::BatchLog(list<LogMessage>* msgs) throw()
	{
		CriticalGuard CG(Gate);

		try
		{
			for(list<LogMessage>::iterator it = msgs->begin(); it != msgs->end(); it++)
			{
				LogMessage Msg = *it;
				this->WriteLog(Msg.Time, Msg.Type, Msg.Message);
			}
		}
		catch(...)
		{
		}

		CG.Close();
	}
}

namespace GLEO
{
	wstring BaseTextLogger::MakeFileName(wstring prefix, wstring DateStr)
	{
		wstring Result = L"";

		Result.append(prefix);
		Result.append(DateStr);
		Result.append(L".log");

		return Result;
	}

	BaseTextLogger::BaseTextLogger(wstring path, wstring prefix)
	{
		this->Path = path;
		this->Prefix = prefix;

		this->LogFile = NULL;
		this->LastFileName.clear();
	}

	BaseTextLogger::~BaseTextLogger()
	{
	}

	void BaseTextLogger::OpenLog(wstring file)
	{
		if(this->LogFile)
		{
			if(this->LastFileName != file)
			{
				this->CloseLog();
			}
		}
		else
		{
			this->CloseLog();
		}

		if(!this->LogFile)
		{
			this->LogFile = new wofstream(file.c_str(), ios::app | ios::binary);

			try
			{
				locale loc("chs");
				this->LogFile->imbue(loc);
			}
			catch(std::runtime_error& err)
			{
				*(this->LogFile) << endl << err.what() << endl;
			}
		}

		this->LastFileName = file;
	}

	void BaseTextLogger::CloseLog()
	{
		if(this->LogFile)
		{
			//this->LogFile.flush();
			//this->LogFile.close();

			delete this->LogFile;
			this->LogFile = NULL;
		}

		this->LastFileName.clear();
	}

	void BaseTextLogger::CleanLogger(time_t last_time)
	{
		CleanLogger(Path, Prefix, last_time);
	}

	void BaseTextLogger::CleanLogger(wstring path, wstring prefix, time_t last_time)
	{
		vector<wstring> FileList;
		FileList.clear();

		T_finddata_t FindData;
		intptr_t FindHandle;
		wstring FileName = path + prefix + _T("*.log");

		wstring LastFile = path + MakeFileName(prefix, FormatDate(last_time));

		FindHandle	= T_findfirst((TChar*)FileName.c_str(), &FindData);
		int rt = FindHandle;
		while(rt != -1)
		{
			TString FindFile;
			FindFile = FindData.name;
			if(FindFile < LastFile)
			{
				FileList.push_back(FindFile);
			}
			rt = T_findnext(FindHandle, &FindData);
		}
		_findclose(FindHandle);

		vector<TString>::iterator it;
		for(it = FileList.begin(); it != FileList.end(); it++)
		{
			_wremove((path + *it).c_str());
		}
	}
}

//文本日志
namespace GLEO
{
	TextEventLogger::TextEventLogger(wstring path, wstring prefix)
		: BaseTextLogger(path, prefix)
	{
		Log(etMessage, L"************************************日志服务启动(Log Started)*************************************");
	}

	TextEventLogger::~TextEventLogger()
	{
		Log(etMessage, L"************************************日志服务中止(Log End)*************************************");
	}

	void TextEventLogger::WriteLog(SYSTEMTIME& time, int Type, wstring Message)
	{
		wstring sTime = FormatTime(time);
		wstring sType = getTypeString((EventType)Type);

		wstring LogFileName = Path + MakeFileName(Prefix, FormatDate(time));
		this->OpenLog(LogFileName);

		if(this->LogFile)
		{
			(*this->LogFile) << sTime << L"\t" << sType << L"\t" << Message << endl;

			(*this->LogFile).flush();
		}
	}

	void TextEventLogger::BatchLog(list<LogMessage>* msgs) throw()
	{
		CriticalGuard CG(Gate);

		try
		{
			if(this->LogFile)
			{
				for(list<LogMessage>::iterator it = msgs->begin(); it != msgs->end(); it++)
				{
					LogMessage Msg = *it;

					wstring sTime = FormatTime(Msg.Time);
					wstring sType = getTypeString((EventType)Msg.Type);

					wstring LogFileName = Path + MakeFileName(Prefix, FormatDate(Msg.Time));
					this->OpenLog(LogFileName);

					(*this->LogFile) << sTime << L"\t" << sType << L"\t" <<Msg. Message << endl;
				}

				(*this->LogFile).flush();
			}
		}
		catch(...)
		{
		}

		CG.Close();
	}
}