#pragma once

enum AlarmType
{
	Message = 1,
	Warning = 2,
	Error = 3
};

struct AlarmDefine
{
	AlarmType Type;
	string Code;
	wstring Message;
};

class __declspec(dllexport) IAlarmSender
{
public:
	virtual void SendAlert(string code, wstring param) = 0;
	virtual void SendStatus(wstring msg) = 0;
};

class __declspec(dllexport) IAlarmDB
{
public:
	virtual void LoadAlarmDefines(map<string, AlarmDefine>& defs) = 0;
	virtual void RecordAlarm(string code, wstring param) = 0;
};