#include "SimpleProtocol.h"

//
// class: SimpleProtocolDecoder
//
bool SimpleFrameCodec::Decode(StreamBuffer& stream, short& cmd, string& DataBlock)
{
	bool Result = false;

	int BufLen = stream.getSize();
	while(stream.getSize() > 0 && stream.ReadByte(0) != STX)
	{
		stream.PickData(1);
	}

	if(BufLen > 8)
	{
		if(stream.ReadByte(0) == STX)	// Meet Head
		{
			int TelLen = stream.ReadInt(1);
			if(BufLen >= TelLen + 2)
			{
				//cmd = Buffer->ReadByte(3); // Read Command Byte
				cmd = (short)(stream.ReadInt(3)); // Read Command Data
				
				//Buffer->PickData(4);		// 删除cmd及之前的字节
				stream.PickData(5);		// 删除cmd及之前的字节1+2+2
				//Buffer->PickData(2);		// string data length
				//Buffer->PickData(data, TelLen - 3);
				stream.PickData(DataBlock, TelLen - 4);

				if(stream.ReadByte(0) == ETX) Result = true;

				stream.PickData(1);
			}
		}
	}

	return Result;
}


void SimpleFrameCodec::Encode(string& message, short cmd, string& DataBlock)
{
	int l = DataBlock.length() + 4;
	
	message.clear();
	message.append(&STX, 1);
	message.append((char*)&l, 2);
	message.append((char*)&cmd, 2);
	message += DataBlock;
	message.append(&ETX, 1);
}

//
//Class BinaryDecoder
//
BinaryDecoder::BinaryDecoder(const string& buf)
{
	this->Buffer = buf.c_str();
	this->Len = buf.size();
	this->Pos = 0;
}

bool BinaryDecoder::RawRead(void* data, int length)
{
	bool Result = false;
	
	if(this->Pos <= this->Len - length)
	{
		const char* p = this->Buffer + this->Pos;
	
		memcpy(data, p, length);
		this->Pos += length;

		Result = true;
	}

	return Result;
}

bool BinaryDecoder::Read(char* data, int length)
{
	bool Result = false;
	
	if(this->Pos <= this->Len - 2)
	{
		const char* p = this->Buffer + this->Pos;

		int len;
		len = *((short*)p);
		this->Pos += 2;

		if(this->Pos <= this->Len - len)
		{
			memcpy(data, p + 2, len);
			data[len] = 0;
			this->Pos += len;

			Result = true;
		}
	}

	return Result;
}

bool BinaryDecoder::Read(string& data)
{
	bool Result = false;
	
	if(this->Pos <= this->Len - 2)
	{
		const char* p = this->Buffer + this->Pos;

		int len;
		len = *((short*)p);
		this->Pos += 2;

		if(this->Pos <= this->Len - len)
		{
			data.clear();
			data.append(p + 2, len);
			this->Pos += len;

			Result = true;
		}
	}

	return Result;
}

bool BinaryDecoder::Read(string& data, int length)
{
	bool Result = false;
	if(this->Pos + length <= this->Len)
	{
		const char* p = this->Buffer + this->Pos;
		data.clear();
		data.append(p, length);
		data.resize(strlen(data.c_str()));//去除末尾的\x0
		this->Pos += length;
		Result = true;
	}
	return Result;
}

bool BinaryDecoder::Read(int& data)
{
	bool Result = false;
	
	if(this->Pos <= this->Len - 4)
	{
		const char* p = this->Buffer + this->Pos;

		data = *((int*)p);
		this->Pos += 4;

		Result = true;
	}

	return Result;
}

bool BinaryDecoder::Read(short& data)
{
	bool Result = false;
	
	if(this->Pos <= this->Len - 2)
	{
		const char* p = this->Buffer + this->Pos;

		data = *((short*)p);
		this->Pos += 2;

		Result = true;
	}

	return Result;
}

bool BinaryDecoder::Read(float& data)
{
	bool Result = false;
	
	if(this->Pos <= this->Len - 4)
	{
		const char* p = this->Buffer + this->Pos;

		data = *((float*)p);
		this->Pos += 4;

		Result = true;
	}

	return Result;
}

bool BinaryDecoder::Read(char& data)
{
	bool Result = false;
	
	if(this->Pos <= this->Len - 1)
	{
		const char* p = this->Buffer + this->Pos;

		data = *((char*)p);
		this->Pos += 1;

		Result = true;
	}

	return Result;
}

bool BinaryDecoder::ReadReverse(int& data)
{
	bool Result = false;
	
	if(this->Pos <= this->Len - 4)
	{
		const char* p = this->Buffer + this->Pos;
		
		char* content = (char*)&data;
		for(int i = 3; i >= 0; i--)
		{
			content[i] = *p;
			p += 1;
		}

		this->Pos += 4;

		Result = true;
	}

	return Result;
}

bool BinaryDecoder::ReadReverse(short& data)
{
	bool Result = false;
	
	if(this->Pos <= this->Len - 2)
	{
		const char* p = this->Buffer + this->Pos;
		
		char* content = (char*)&data;
		for(int i = 1; i >= 0; i--)
		{
			content[i] = *p;
			p += 1;
		}

		this->Pos += 2;

		Result = true;
	}

	return Result;
}

bool BinaryDecoder::ReadReverse(float& data)
{
	bool Result = false;
	
	if(this->Pos <= this->Len - 4)
	{
		const char* p = this->Buffer + this->Pos;
		
		char* content = (char*)&data;
		for(int i = 3; i >= 0; i--)
		{
			content[i] = *p;
			p += 1;
		}

		this->Pos += 4;

		Result = true;
	}

	return Result;
}

bool BinaryDecoder::Read(wstring& data)
{
	bool Result = false;
	
	if(this->Pos <= this->Len - 2)
	{
		const char* p = this->Buffer + this->Pos;

		int len;
		len = *((short*)p);
		this->Pos += 2;

		if(this->Pos <= this->Len - len)
		{
			data.clear();
			data.append( (wchar_t*)(p + 2), len);
			this->Pos += len * 2;

			Result = true;
		}
	}

	return Result;
}

//bool BinaryDecoder::Read(wstring& data, int length)
//{
//	return this->Read(~data, length * 2);
//}

//
// Class BinaryEncoder
// 

BinaryEncoder::BinaryEncoder()
{
	this->Clean();
}

void BinaryEncoder::Clean()
{
	this->Buffer.clear();
}

void BinaryEncoder::AppendZero(string& Buffer, int count)
{
	for(int i = 0; i < count; i++)
	{
		Buffer.append("\x0", 1);
	}
}

void BinaryEncoder::RawWrite(const void* data, int length)
{
	Buffer.append((char*)data, length);
}

void BinaryEncoder::Write(const char* data, int length)
{
	int actLen = strlen(data);
	
	if(actLen > length)
	{
		actLen = length;
	}

	Buffer.append((char*)&actLen, 2);
	Buffer.append(data, actLen);

	if(actLen < length)
	{
		AppendZero(Buffer,length - actLen);
	}
}

void BinaryEncoder::Write(char data)
{
	Buffer.append(&data, 1);
}

void BinaryEncoder::Write(int data)
{
	Buffer.append((char*)&data, 4);
}

void BinaryEncoder::Write(short data)
{
	Buffer.append((char*)&data, 2);
}

void BinaryEncoder::Write(float data)
{
	Buffer.append((char*)&data, 4);
}

void BinaryEncoder::Write(const string& data)
{
	int len = data.length();	// 字符串型数据在数据前增加2位长度
	Buffer.append((char*)&len, 2);
	Buffer.append(data.c_str(), len);
}

void BinaryEncoder::Write(const string& data,int length)
{
	int actLen = data.length();
	
	if(actLen > length)
	{
		actLen = length;
	}

	Buffer.append(data.c_str(), actLen);

	if(actLen < length)
	{
		AppendZero(Buffer,length - actLen);
	}
}

void BinaryEncoder::Write(const char* data)
{
	int len = strlen(data);	// 字符串型数据在数据前增加2位长度
	Buffer.append((char*)&len, 2);
	Buffer.append(data, len);
}

void BinaryEncoder::WriteReverse(int data)
{
	for(int i = 3; i >= 0; i--)
	{
		Buffer.append((char*)&data + i, 1);
	}
}

void BinaryEncoder::WriteReverse(short data)
{
	for(int i = 1; i >= 0; i--)
	{
		Buffer.append((char*)&data + i, 1);
	}
}

void BinaryEncoder::WriteReverse(float data)
{
	for(int i = 3; i >= 0; i--)
	{
		Buffer.append((char*)&data + i, 1);
	}
}

string& BinaryEncoder::GetData()
{
	return Buffer;
}

void BinaryEncoder::Write(const wstring& data)
{
	int len = data.length();
	Buffer.append((char*)&len, 2);
	Buffer.append((char*)data.c_str(), len * 2);
}

//void BinaryEncoder::Write(const wstring& data, int length)
//{
//	int actLen = strlen((char*)data.c_str());
//	
//	if(actLen > length * 2)
//	{
//		actLen = length * 2;
//	}
//
//	Buffer.append((char*)data.c_str(), actLen);
//
//	if(actLen < length * 2)
//	{
//		AppendZero(Buffer,(length - actLen) * 2);
//	}
//}

//
// Class SimpleProtocolEncoder
//
SimpleProtocolDecoder::SimpleProtocolDecoder(const string& buf)
	: BinaryDecoder(buf)
{
}

SimpleProtocolDecoder& SimpleProtocolDecoder::operator>> (char& data)
{
	this->Read(data);

	return *this;
}

SimpleProtocolDecoder& SimpleProtocolDecoder::operator>> (short& data)
{
	this->Read(data);

	return *this;
}

SimpleProtocolDecoder& SimpleProtocolDecoder::operator>> (int& data)
{
	this->Read(data);

	return *this;
}

SimpleProtocolDecoder& SimpleProtocolDecoder::operator>> (string& data)
{
	this->Read(data);

	return *this;
}

SimpleProtocolDecoder& SimpleProtocolDecoder::operator>> (wstring& data)
{
	this->Read(data);
	return *this;
}

//
// Class SimpleProtocolEncoder
//

SimpleProtocolEncoder::SimpleProtocolEncoder()
	: BinaryEncoder()
{
	this->FullFrame = false;
}

SimpleProtocolEncoder::SimpleProtocolEncoder(short cmd)
	: BinaryEncoder()
{
	this->FullFrame = true;

	this->Write(BaseCmdCodec::STX);
	this->Write((short)0);
	this->Write(cmd);
}

SimpleProtocolEncoder& SimpleProtocolEncoder::operator<< (char data)
{
	this->Write(data);

	return *this;
}

SimpleProtocolEncoder& SimpleProtocolEncoder::operator<< (int data)
{
	this->Write(data);

	return *this;
}

SimpleProtocolEncoder& SimpleProtocolEncoder::operator<< (short data)
{
	this->Write(data);

	return *this;
}

SimpleProtocolEncoder& SimpleProtocolEncoder::operator<< (string& data)
{
	this->Write(data);

	return *this;
}

SimpleProtocolEncoder& SimpleProtocolEncoder::operator<< (char* data)
{
	this->Write(data);

	return *this;
}

string& SimpleProtocolEncoder::GetData()
{
	if(this->FullFrame)
	{
		int l = Buffer.length() - 1;

		this->Write(BaseCmdCodec::ETX);
		Buffer[1] = *((char*)&l);
		Buffer[2] = *((char*)&l + 1);
	}

	return Buffer;
}

SimpleProtocolEncoder& SimpleProtocolEncoder::operator<< (wstring& data)
{
	this->Write(data);
	return *this;
}
