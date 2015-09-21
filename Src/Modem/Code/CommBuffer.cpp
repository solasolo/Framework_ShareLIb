#ifdef __BORLANDC__
	#include <vcl.h>
#else
	#include <nonvcl.h>
#endif

#pragma hdrstop

#include <string.h>

#include "CommBuffer.h"
#include "BaseException.h"

//---------------------------------------------------------------------------
#ifdef __BORLANDC__
#pragma package(smart_init)
#endif

using namespace GLEO;

//---------------------------------------------------------------------------
BufferCore::BufferChain::BufferChain(const unsigned char* data, unsigned int size)
{
	Buffer = NULL;
  Next = NULL;
  Prev = NULL;
  Length = 0;
  Offset = 0;

	Buffer = new char[size];
	if(!Buffer) throw GLEO::Exception(L"Alloc BufferChain's Buffer");

	memcpy(Buffer, data, size);
  Length = size;

  Next = this;
  Prev = this;
}

BufferCore::BufferChain::~BufferChain()
{
	if(Buffer) delete Buffer;
}

unsigned int BufferCore::BufferChain::Size()
{
	return Length - Offset;
}

void BufferCore::BufferChain::Erase(unsigned int size)
{
	if(size <= Size())
  {
  	Offset += size;
  }
}

unsigned char BufferCore::BufferChain::operator [](unsigned int pos)
{
  unsigned char Result = '\x0';

	if(pos < Size())
  {
  	Result = Buffer[Offset + pos];
  }

  return Result;
}


//------------------------------------------------------------------------------------
BufferCore::BufferCore()
	: BufferGate()
{
	InnerBuffer = NULL;
}

BufferCore::~BufferCore()
{
	Clear();
}

bool BufferCore::IsEmpty()
{
	return (!InnerBuffer);
}

void BufferCore::Clear()
{
	CriticalGuard CG(BufferGate);

	BufferChain* Head = InnerBuffer;
	BufferChain* BufPtr = Head;

	while((BufPtr != Head) && (BufPtr != NULL))
	{
		InnerBuffer = BufPtr->Next;
		delete BufPtr;

		BufPtr = InnerBuffer;
	}

	InnerBuffer = NULL;

  CG.Close();
}

unsigned int BufferCore::getSize()
{
	unsigned int Result = 0;

	CriticalGuard CG(BufferGate);

	BufferChain* Head = InnerBuffer;
	BufferChain* BufPtr = Head;

	while((BufPtr != Head) && (BufPtr != NULL))
	{
		Result += BufPtr->Length - BufPtr->Offset;
		BufPtr = BufPtr->Next;
	}

	CG.Close();

	return Result;
}

void BufferCore::AddBefore(BufferChain* node, BufferChain* ref_node)
{
  if(ref_node)
  {
	  BufferChain* prev_node = ref_node->Prev;

    node->Prev = prev_node;
    node->Next = ref_node;
    prev_node->Next = node;
    ref_node->Prev = node;
  }
}

BufferCore::BufferChain* BufferCore::Remove(BufferChain* node)
{
	BufferChain* ReturnNode = NULL;

	if(node)
	{
    BufferChain* prev_node = node->Prev;

    if(node == prev_node)
    {
      ReturnNode = NULL;
    }
    else
    {
      prev_node->Next = node->Next;
      node->Next->Prev = prev_node;

      ReturnNode = prev_node;
    }

    delete node;
	}

	return ReturnNode;
}

//------------------------------------------------------------------------------------
CommBuffer::CommBuffer(void)
	: BufferWrap()
{
	Reader = new BufferReader(Core);
	Writer = new BufferWriter(Core);
}

CommBuffer::~CommBuffer(void)
{
	DESTROY(Core);
}

BufferReader* CommBuffer::getReader()
{
	return Reader;
}

BufferWriter* CommBuffer::getWriter()
{
	return Writer;
}

//------------------------------------------------------------------------------------
BufferWrap::BufferWrap(BufferCore* buf)
{
	Core = buf;
}

BufferWrap::BufferWrap()
{
	Core = new BufferCore();
}

void BufferWrap::Clear()
{
  Core->Clear();
}

bool BufferWrap::IsEmpty()
{
	return Core->IsEmpty();
}

unsigned int BufferWrap::getSize()
{
	return Core->getSize();
}

//------------------------------------------------------------------------------------
BufferWriter::BufferWriter(BufferCore* buf)
	: BufferWrap(buf)
{
}

void BufferWriter::Push(const unsigned char* chs, unsigned int len)
{
	CriticalGuard CG(Core->BufferGate);

  BufferCore::BufferChain* NewNode;
  NewNode = new BufferCore::BufferChain(chs, len);

  Core->AddBefore(NewNode, Core->InnerBuffer);

  Core->InnerBuffer = NewNode;

	CG.Close();
}

//------------------------------------------------------------------------------------
BufferReader::BufferReader(BufferCore* buf)
	: BufferWrap(buf)
{
}

bool BufferReader::Pop(string& data, unsigned int len)
{
	bool Result = false;
	data.clear();

	CriticalGuard CG(Core->BufferGate);

  BufferCore::BufferChain* Head = Core->InnerBuffer;

	if(Head)
	{
		if(len == -1)
		{
      BufferCore::BufferChain* Last = Head->Prev;

			data.append(Last->Buffer + Last->Offset, Last->Length - Last->Offset);

      if(!Core->Remove(Last)) Core->InnerBuffer = NULL;

			Result = true;
		}
	}

  CG.Close();

	return Result;
}

bool BufferReader::Pop(unsigned int len)
{
	bool Result = false;

	CriticalGuard CG(Core->BufferGate);

  int c = 0;

  BufferCore::BufferChain* Head = Core->InnerBuffer;
  BufferCore::BufferChain* TempPtr = Head;

  if(TempPtr)
  {
    do
    {
      int n = TempPtr->Size();

      if(len - c < n)
      {
        n = len - c;
        TempPtr->Erase(n);

			  Result = true;
        break;
      }
      else
      {
      	TempPtr = Core->Remove(TempPtr);

        if(len - c == n)
        {
        	Result = true;
          break;
        }
      }

      c += n;
    }
    while((TempPtr != NULL) && (TempPtr != Head));
  }


	CG.Close();

	return Result;
}

bool BufferReader::ReadData(string& data, unsigned int len)
{
	return true;
}

bool BufferReader::ReadByte(unsigned char& data, unsigned int pos)
{
	bool Result;

	CriticalGuard CG(Core->BufferGate);

  int c = 0;

  BufferCore::BufferChain* Head = Core->InnerBuffer;
  BufferCore::BufferChain* TempPtr = Head->Prev;

  if(TempPtr)
  {
    do
    {
      int n = TempPtr->Size();

      if(pos - c <= n)
      {
        n = pos - c;

        data = (*TempPtr)[n];

			  Result = true;
        break;
      }
      else
      {
      	TempPtr = TempPtr->Prev;
      }

      c += n;
    }
    while((TempPtr != NULL) && (TempPtr != Head));
  }


	CG.Close();

	return Result;
}

bool BufferReader::ReadInt16(int& data, unsigned int pos)
{
	return true;
}

bool BufferReader::ReadInt32(int& data, unsigned int pos)
{
	return true;
}
