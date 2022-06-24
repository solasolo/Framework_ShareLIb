#pragma once

#ifndef STREAMBUFFER_H
#define STREAMBUFFER_H

#pragma warning(disable:4786)

#include "ThreadWrap.h"

#include <list>

using namespace std;
using namespace Win32Lib;

class __declspec(dllexport) StreamBuffer
{
	typedef list<string> StringList;

private:
	struct Cursor
	{
		StringList::iterator it;
		int pos;
	};
	
	CriticalSection BufferGate;
	StringList Buffer;

	unsigned int InnerGetSize();
	bool ReadData(void* data, unsigned int pos, unsigned int len);	
	bool Locate(unsigned int pos, Cursor& cur);

public:
	~StreamBuffer();

	StreamBuffer& operator <<(string data);

	void Clear();
	unsigned int getSize();

	bool ReadData(string& data, unsigned int len = 0);
	bool ReadData(void* data, unsigned int len);	
	bool PickData(string& data, unsigned int len = 0);
	bool PickData(unsigned int len);

	int ScanData(char ch);

	char ReadByte(unsigned int pos);
	short ReadShort(unsigned int pos);
	int ReadInt(unsigned int pos);
};

#endif