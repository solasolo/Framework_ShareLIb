#include "HMIChannel.h"

const int HMIChannel::MSG_STATUS = 9001;
const int HMIChannel::MSG_ALERT = 9002;
const int HMIChannel::MSG_SHIFT_CHANGE = 9003;

HMIChannel::HMIChannel(string ip, int port, BaseEventLogger* log)
	: TCPServerSimpleProtocol()
{
	Logger = log;

	this->Start(ip, port);
}

HMIChannel::~HMIChannel(void)
{
}

void HMIChannel::ProcessCommand(TCPConnection& conn, short cmd, BinaryDecoder& decoder)
{
	switch(cmd)
	{
	case 1:
		break;
	}
}

void HMIChannel::ProcessConnect(TCPConnection& conn)
{
}

void HMIChannel::ProcessNotice(EventType type, const wstring& msg)
{
	this->Logger->Log(etMessage, msg);
}

//2005	服务端换班通知
void HMIChannel::QuitHIM()
{
	string msg =  "QUIT";

	BinaryEncoder Encoder;
	Encoder.Write(msg);

	this->Send(MSG_SHIFT_CHANGE, Encoder);
}

void HMIChannel::SendAlert(string code, wstring param)
{
	BinaryEncoder Encoder;
	Encoder.Write(code);
	Encoder.Write(param);

	this->Send(MSG_ALERT, Encoder);
}

void HMIChannel::SendStatus(wstring msg)
{
	BinaryEncoder Encoder;
	Encoder.Write(msg);

	this->Send(MSG_STATUS, Encoder);
}
