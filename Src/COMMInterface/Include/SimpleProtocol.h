#pragma once

#ifndef SIMPLEPROTOCOL_H
#define SIMPLEPROTOCOL_H

//#include "WinTCP.h"
#include "StreamBuffer.h"

class __declspec(dllexport) BaseCmdCodec
{
public:
	static const char STX = '\x02';
	static const char ETX = '\x03';

	virtual bool Decode(StreamBuffer& stream, short& cmd, string& DataBlock) = 0;
	virtual void Encode(string& message, short cmd, string& DataBlock) = 0;
};

class __declspec(dllexport) SimpleFrameCodec : public BaseCmdCodec
{
public:
	virtual bool Decode(StreamBuffer& stream, short& cmd, string& DataBlock);
	virtual void Encode(string& message, short cmd, string& DataBlock);
};

class __declspec(dllexport) BinaryDecoder
{
protected:
	int Len;
	int Pos;
	const char* Buffer;

public:
	BinaryDecoder(const string& buf);

	bool RawRead(void* data, int length);
	bool Read(char* data, int length);
	bool Read(string& data);
	bool Read(string& data, int length);
	bool Read(int& data);
	bool Read(short& data);
	bool Read(char& data);
	bool Read(float& data);

	bool ReadReverse(int& data);
	bool ReadReverse(short& data);
	bool ReadReverse(float& data);

	bool Read(wstring& data);
	//bool Read(wstring& data, int length);
};

class __declspec(dllexport) BinaryEncoder
{
private:
	void AppendZero(string& Buffer, int count);
protected:
	string Buffer;

public:
	BinaryEncoder();

	void Clean();

	void RawWrite(const void* data, int length);
	void Write(const char* data, int length);
	void Write(const string& data);
	void Write(const string& data, int length);
	void Write(const char* data);
	void Write(char data);
	void Write(int data);
	void Write(short data);
	void Write(float data);

	void WriteReverse(int data);
	void WriteReverse(short data);
	void WriteReverse(float data);

	void Write(const wstring& data);
	//void Write(const wstring& data, int length);

	virtual string& GetData();
};

class __declspec(dllexport) SimpleProtocolDecoder : public BinaryDecoder
{
public:
	SimpleProtocolDecoder(const string& buf);

	SimpleProtocolDecoder& operator>> (char& data);
	SimpleProtocolDecoder& operator>> (short& data);
	SimpleProtocolDecoder& operator>> (int& data);
	SimpleProtocolDecoder& operator>> (string& data);
	SimpleProtocolDecoder& operator>> (wstring& data);
};

class __declspec(dllexport) SimpleProtocolEncoder : public BinaryEncoder
{
private:
	bool FullFrame;

public:
	SimpleProtocolEncoder(short cmd);
	SimpleProtocolEncoder();

	SimpleProtocolEncoder& operator<< (char data);
	SimpleProtocolEncoder& operator<< (short data);
	SimpleProtocolEncoder& operator<< (int data);
	SimpleProtocolEncoder& operator<< (char* data);
	SimpleProtocolEncoder& operator<< (string& data);
	SimpleProtocolEncoder& operator<< (wstring& data);

	virtual string& GetData();
};

#endif