#include "AlarmSender.h"

AlarmSender::AlarmSender(IAlarmDB* dba, IAlarmSender* sender, IEventLogger* logger)
	: SimpleThread(L"Alert", true)
{
	this->Dba = NULL;
	this->Sender = NULL;
	this->Logger = NULL;

	this->Dba = dba;
	this->Sender = sender;
	this->Logger = logger;

	this->Dba->LoadAlarmDefines(this->AlarmList);

	this->Start();
}

AlarmSender::~AlarmSender(void)
{
}

void AlarmSender::SendAlert(string code)
{
	this->Record(code, L"");

	AlarmDefine* def = this->GetAlarm(code);
	if(def)
	{
		wstring message = def->Message;

		this->Log(def, message);
	}
}

void AlarmSender::SendAlert(string code, wstring param)
{
	this->Record(code, param);

	AlarmDefine* def = this->GetAlarm(code);
	if(def)
	{
		wstring message = this->ReplaceParam(def->Message, 0, param);

		this->Log(def, message);
	}
}

void AlarmSender::SendAlert(string code, wstring param0, wstring param1)
{
	wstring param = param0 + L"`" + param1;
	this->Record(code, param);

	AlarmDefine* def = this->GetAlarm(code);
	if(def)
	{
		wstring message = def->Message;
		message = this->ReplaceParam(message, 0, param0);
		message = this->ReplaceParam(message, 1, param1);

		this->Log(def, message);
	}
}

void AlarmSender::SendAlert(string code, wstring param0, wstring param1, wstring param2)
{
	wstring param = param0 + L"`" + param1 + L"`" + param2;
	this->Record(code, param);
	
	AlarmDefine* def = this->GetAlarm(code);
	if(def)
	{
		wstring message = def->Message;
		message = this->ReplaceParam(message, 0, param0);
		message = this->ReplaceParam(message, 1, param1);
		message = this->ReplaceParam(message, 2, param2);

		this->Log(def, message);
	}
}

void AlarmSender::LoadDefines()
{
}

AlarmDefine* AlarmSender::GetAlarm(string code)
{
	AlarmDefine* Result = NULL;

	map<string, AlarmDefine>::iterator it = this->AlarmList.find(code);
	if(it != this->AlarmList.end())
	{
		Result = &(it->second);
	}

	return Result;
}

wstring AlarmSender::ReplaceParam(wstring& msg, int index, wstring param)
{
	wstring Result = L"";

	wchar_t buf[10];
	swprintf_s(buf, 10, L"{%d}", index);
	
	int pos = msg.find(buf);
	if(pos >= 0)
	{
		if(pos > 0)
		{
			Result = msg.substr(0, pos);
		}

		Result += param;
		Result += msg.substr(pos + 3);
	}

	return Result;
}

void AlarmSender::Record(string code, wstring param)
{
	AlertMessage msg;
	msg.Code = code;
	msg.Message = param;

	CriticalGuard CG(this->BufferGuarder);

	this->AlertBuffer.push(msg);

	CG.Close();
}

void AlarmSender::Log(AlarmDefine* def, wstring& message)
{
	if(this->Logger)
	{
		EventType LogType = EventType::etMessage;

		switch(def->Type)
		{
		case AlarmType::Message:
			LogType = EventType::etMessage;
			break;

		case AlarmType::Warning:
			LogType = EventType::etWarrining;
			break;

		case AlarmType::Error:
			LogType = EventType::etError;
			break;

		default:
			LogType = EventType::etMessage;
			break;
		}

		this->Logger->Log(LogType, message);
	}
}

void AlarmSender::RunTask()
{
	bool HasMessage = false;
	AlertMessage msg;

	do
	{
		CriticalGuard CG(this->BufferGuarder);

		HasMessage = this->AlertBuffer.size() > 0;

		if(HasMessage)
		{
			msg = this->AlertBuffer.front();
			this->AlertBuffer.pop();
		}

		CG.Close();

		if(HasMessage)
		{
			if(this->Dba)
			{
				this->Dba->RecordAlarm(msg.Code, Replace(msg.Message, wstring(L"'"), wstring(L"''")));
			}

			if(this->Sender)
			{
				Sender->SendAlert(msg.Code, msg.Message);
			}
		}
	}
	while(HasMessage);
}

void AlarmSender::Notify(wstring& msg, EventType type)
{
	this->Logger->Log(type, msg);
}
