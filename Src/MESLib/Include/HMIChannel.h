#pragma once

#include "WinTCP.h"
#include "XMLConfig.h"
#include "ISender.h"

class __declspec(dllexport) HMIChannel : public TCPServerSimpleProtocol, public IAlarmSender
{
private:
	static const int MSG_STATUS;
	static const int MSG_ALERT;
	static const int MSG_SHIFT_CHANGE;

	//2005	服务端换班响应
	void QuitHIM();
	
protected:
	BaseEventLogger* Logger; 

	virtual void ProcessCommand(TCPConnection& conn, short cmd, BinaryDecoder& decoder);
	virtual void ProcessConnect(TCPConnection& conn);
	virtual void ProcessNotice(EventType type, const wstring& msg);

public:
	HMIChannel(string ip, int port, BaseEventLogger* log);
	~HMIChannel(void);

	virtual void SendAlert(string code, wstring param);
	virtual void SendStatus(wstring msg);

	//测试用方法
	//void SetCallBack(TCPCallBack* CB);
};

