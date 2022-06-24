#include "StreamBuffer.h"
#include "WinException.h"

using namespace GLEO;

//---------------------------------------------------------------------------
StreamBuffer::~StreamBuffer()
{
	this->Clear();
}

StreamBuffer& StreamBuffer::operator <<(string data)
{
	CriticalGuard CG(BufferGate);
	
	Buffer.push_back(data);

	CG.Close();

	return *this;
}

void StreamBuffer::Clear()
{
	CriticalGuard CG(BufferGate);

	Buffer.clear();

	CG.Close();
}

unsigned int StreamBuffer::InnerGetSize()
{
	unsigned int Result = 0;

	StringList::iterator it = Buffer.begin();
	while(it != Buffer.end())
	{
		Result += it->size();
		it++;
	}

	return Result;
}

unsigned int StreamBuffer::getSize()
{
	unsigned int Result = 0;

	CriticalGuard CG(BufferGate);

	Result = this->InnerGetSize();

	CG.Close();

	return Result;
}

bool StreamBuffer::Locate(unsigned int pos, Cursor& cur)
{
	cur.it = Buffer.begin();
	cur.pos = 0;
	while(cur.it != Buffer.end() && pos > 0)
	{
		int n = cur.it->size();
		if(pos >= n)
		{
			pos -= n;
		}
		else
		{
			cur.pos = pos;
			pos = 0;
			break;
		}

		cur.it++;
	}

	return (pos == 0);
}

bool StreamBuffer::ReadData(void* data, unsigned int pos, unsigned int len)
{
	bool Result = false;

	CriticalGuard CG(BufferGate);

	Cursor cur;
	Result = Locate(pos, cur);

	if(Result)
	{
		int c = 0;

		while(cur.it != Buffer.end() && c < len)
		{
			int n = cur.it->size();
			n -= cur.pos;			
			if(len - c < n) n = len - c;

			memcpy((char*)data + c, cur.it->c_str() + cur.pos, n);

			cur.it++;
			c += n;
			cur.pos = 0;
		}
	
		if(len != c) Result = false;	
	}
	
	CG.Close();

	return Result;
}

bool StreamBuffer::ReadData(string& data, unsigned int len)
{
	int c = 0;
	bool Result = false;

#if _MSC_VER < 1300
	data = "";
#else
	data.clear();
#endif

	CriticalGuard CG(BufferGate);
	
	if(InnerGetSize() >= len)
	{
		StringList::iterator it = Buffer.begin();
		while(it != Buffer.end() && c < len)
		{
			int n = it->size();
			if(len - c < n) n = len - c;
			data += it->substr(0, n);

			it++;
			c += n;
		}

		Result = true;
	}

	CG.Close();

	return Result;
}

bool StreamBuffer::PickData(string& data, unsigned int len)
{
	bool Result = ReadData(data, len);

	if(Result) PickData(len);

	return Result;
}

bool StreamBuffer::PickData(unsigned int len)
{
	bool Result = false;

	CriticalGuard CG(BufferGate);

	if(InnerGetSize() >= len)
	{
		int c = 0;
		StringList::iterator it = Buffer.begin();
		while(it != Buffer.end() && c < len)
		{
			int n = it->size();
			if(len - c < n) 
			{
				n = len - c;
				it->erase(0, n);

				break;
			}
			else
			{
				it = Buffer.erase(it); 
			}

			c += n;
		}

		Result = true;
	}

	CG.Close();

	return Result;
}

bool StreamBuffer::ReadData(void* data, unsigned int len)
{
	return this->ReadData(data, 0, len);
}

char StreamBuffer::ReadByte(unsigned int pos)
{
	char Result;

	CriticalGuard CG(BufferGate);

	Cursor cur;
	if(Locate(pos, cur))
	{
		Result = (*cur.it)[cur.pos];
	}
	else
	{
		throw Exception("Execced Index", "Read Stream Byte");
	}

	CG.Close();


	return Result;
}

short StreamBuffer::ReadShort(unsigned int pos)
{
	short Result = 0;

	if (!ReadData(&Result, pos, 2))
	{
		throw Exception("Execced Index", "Read Stream Byte");
	}

	return Result;
}

int StreamBuffer::ReadInt(unsigned int pos)
{
	int Result = 0;
	
	if(!ReadData(&Result, pos, 4))
	{
		throw Exception("Execced Index", "Read Stream Byte");
	}
		
	return Result;
}

int StreamBuffer::ScanData(char ch)
{
	int Result = -1;

	CriticalGuard CG(BufferGate);

	StringList::iterator it = Buffer.begin();
	while(it != Buffer.end())
	{
		unsigned int pos = 0;

		int n = it->find(ch);
		if(n > -1)
		{
			Result = pos + n; 	
			break;
		}
		else
		{
			pos += it->size();
		}

		it++;
	}

	CG.Close();

	return Result;
}

