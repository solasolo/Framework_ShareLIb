#ifndef COMM_BUFFER_H
#define COMM_BUFFER_H

#include "Synchronization.h"

using namespace Win32Lib;


class BufferCore
{
friend class BufferWrap;
friend class BufferReader;
friend class BufferWriter;
friend class CommBuffer;

private:
	struct BufferChain
	{
		char* Buffer;
		unsigned int Length;
    unsigned int Offset;

		BufferChain* Next;
    BufferChain* Prev;

		BufferChain(const unsigned char* data, unsigned int size);
		~BufferChain();

    unsigned int Size();
    void Erase(unsigned int size);

    unsigned char operator [](unsigned int pos);
	};

	CriticalSection BufferGate;
	BufferChain* InnerBuffer;

protected:
	BufferCore();
	~BufferCore();

	void Clear();
	bool IsEmpty();
	unsigned int getSize();

  void AddBefore(BufferChain* node, BufferChain* ref_node);
  BufferChain* Remove(BufferChain* node);

public:
};

class _declspec(dllexport) BufferWrap
{
protected:
	BufferCore* Core;

public:
  BufferWrap(BufferCore* buf);
  BufferWrap();

	void Clear();
	bool IsEmpty();
	unsigned int getSize();
};

class _declspec(dllexport) BufferReader : public BufferWrap
{
public:
  BufferReader(BufferCore* buf);

	bool Pop(string& data, unsigned int len = -1);
	bool Pop(unsigned int len);

	bool ReadData(string& data, unsigned int len = 0);
	bool ReadByte(unsigned char& data, unsigned int pos = 0);
	bool ReadInt16(int& data, unsigned int pos = 0);
	bool ReadInt32(int& data, unsigned int pos = 0);

	int FindData(char ch);
};

class _declspec(dllexport) BufferWriter : public BufferWrap
{
public:
  BufferWriter(BufferCore* buf);

	void Push(const unsigned char* chs, unsigned int len);
	void Push(string& data);
};

class _declspec(dllexport) CommBuffer : public BufferWrap
{
private:
	BufferReader* Reader;
	BufferWriter* Writer;

public:
	CommBuffer(void);
	~CommBuffer(void);

	BufferReader* getReader();
	BufferWriter* getWriter();
};

#endif
