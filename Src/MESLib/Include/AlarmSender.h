#pragma once

#include "SmartADODB.h"
#include "ISender.h"
#include "ThreadWrap.h"

#include <map>
#include <queue>

using namespace std;
using namespace GLEO;

class __declspec(dllexport) AlarmSender : public SimpleThread
{
	struct AlertMessage
	{
		string Code;
		wstring Message;
	};

private:
	map<string, AlarmDefine> AlarmList;
	queue<AlertMessage> AlertBuffer;

	DbType DBType;
	IEventLogger* Logger; 
	IAlarmSender* Sender;
	IAlarmDB* Dba;

	CriticalSection BufferGuarder;

	void LoadDefines();
	AlarmDefine* GetAlarm(string code); 
	wstring MakeAlarmMessage(string code);
	void Record(string code, wstring param);
	void Log(AlarmDefine* def, wstring& message);
	wstring ReplaceParam(wstring& msg, int index, wstring param); 

protected:
		virtual void RunTask();
		virtual void Notify(wstring& msg, EventType type = etMessage);

public:
	AlarmSender(IAlarmDB* dba, IAlarmSender* sender, IEventLogger* logger);
	virtual ~AlarmSender(void);
	
	void SendAlert(string code);
	void SendAlert(string code, wstring param);
	void SendAlert(string code, wstring param0, wstring param1);
	void SendAlert(string code, wstring param0, wstring param1, wstring param2);
};