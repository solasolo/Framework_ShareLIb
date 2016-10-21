#pragma once

#include <string>

#include "StreamBuffer.h"

using namespace std;




//»ù´¡±à½âÂëÆ÷
class __declspec(dllexport)  BaseXCOMCodec
{
public:
	enum MessageDir
	{
		Server,
		Client
	};

	enum MessageType
	{
		MESSAGE_ACK,
		LIVE_ACK,
		DATA_MESSAGE,
		DATA_MESSAGE_REPLY,
		LIVE_MESSAGE,
		LIVE_MESSAGE_REPLY,

		NO_MESSAGE,
		INVALID_MESSAGE
	};

protected:
	string SendHeartID;
	string RecvHeartID;
	wstring ParserError;

public:
	static const char STX = '\02';
	static const char ETX = '\03';

	virtual MessageType Decode(StreamBuffer& stream, MessageDir dir, string& telegram, string& MessageID, string& DataBlock) = 0;
	virtual void Encode(string& message, string& MessageID, string& DataBlock) = 0;
	virtual void EncodeACK(string& Response, string& Request) = 0;
	virtual void EncodeReply(string& message, string& MessageID, string& DataBlock) = 0;
	virtual void EncodeHeartTelgram(string& message) = 0;
	virtual void EncodeHeartReply(string& message) = 0;

	string& getSendHeartID();
	string& getRecvHeartID();
	wstring& getError();
};

