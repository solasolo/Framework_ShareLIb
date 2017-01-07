//#include "stdafx.h"

#include "TelegramBuilder.h"
#include "CommonFuncs.h"
#include "BaseException.h"

#include <sstream>
#include <stdio.h>
#include <string>

using namespace GLEO;

BaseTelegramItemError::BaseTelegramItemError(string item, bool decode)
	: Exception(L"", decode ? L"Decode" : L"Encode")
{
	this->ItemName = ~item;
}

BaseTelegramItemError& BaseTelegramItemError::operator =(const BaseTelegramItemError& ex) throw()
{
	this->ItemName = ex.ItemName;

	return *this;
}

TelegramItemSizeError::TelegramItemSizeError(string item, bool decode)
	: BaseTelegramItemError(item, decode)
{
}

wstring TelegramItemSizeError::GetErrorDescription()
{
	return wstring(L"[") + this->ItemName + L"] Error Size in Telegram";
}

TelegramItemFormatError::TelegramItemFormatError(string item, bool decode)
	: BaseTelegramItemError(item, decode)
{
}

wstring TelegramItemFormatError::GetErrorDescription()
{
	return wstring(L"[") + this->ItemName + L"] Error Format in Telegram";
}

//
//
//

const int BaseTelegramBuilder::MAX_FIELD_LENGTH = 255;

BaseTelegramBuilder::BaseTelegramBuilder(wstring& file_name)
{
	Scheme = NULL; 
	Scheme = new TelegramScheme(file_name);
}

BaseTelegramBuilder::~BaseTelegramBuilder()
{
	DESTROY(Scheme);
}

//
// Class TextTelegramBuilder
//

TextTelegramBuilder::TextTelegramBuilder(wstring& file_name)
	: BaseTelegramBuilder(file_name)
{
	this->BlankChar = ' ';
	this->IsFix = this->Scheme->IsFix;
}

TextTelegramBuilder::~TextTelegramBuilder()
{
}

bool TextTelegramBuilder::IsBlank(string& part)
{
	bool Result = true;

	int l = part.size();
	for(int i = 0; i < l; i++)
	{
		if(part[i] != this->BlankChar)
		{
			Result = false;
			break;
		}
	}

	return Result;
}

void TextTelegramBuilder::FormatPart(string& part, variant_t& data, FieldDef& item)
{
	char Temp[MAX_FIELD_LENGTH + 1];
	char format[20];
	char* format2;

	Temp[MAX_FIELD_LENGTH] = '\x0';
	format[0] = format[19] = '\x0';

	part.clear();
	FieldDef::FieldType Type = item.Type;
	int Length = item.Length;

	double FloatValue;
	string StringValue;
	int InputLength;

	Temp[0] = '\x0';
	switch(Type)
	{
	case FieldDef::Int:
		sprintf_s(format, 19, "%%0%dd", Length);
		sprintf_s(Temp, MAX_FIELD_LENGTH, format, ToLong(data));
		break;

	case FieldDef::String:
		StringValue = ToString(data);
		InputLength = StringValue.size();

		if (Length < MAX_FIELD_LENGTH)
		{
			format2 = (this->Scheme->PaddingLeft) ? "%%-%ds" : "%%%ds";
			sprintf_s(format, 19, format2, Length);

			sprintf_s(Temp, MAX_FIELD_LENGTH, format, StringValue.c_str());
		}
		else
		{
			if (InputLength < Length)
			{
				//part = "";
				//part.resize(Length = InputLength, ' ');
				//part += StringValue;

				part = StringValue;
				PadRight(part, Length, ' ');
			}
			else
			{
				part = StringValue;
			}
		}
		break;

	case FieldDef::Float:
		FloatValue = ToFloat(data);
		
		if (this->IsFix)
		{
			for (int d = 0; d < item.Dec; d++)
			{
				FloatValue *= 10;
			}

			sprintf_s(format, 19, "%%0%dd", Length);
			sprintf_s(Temp, MAX_FIELD_LENGTH, format, int(FloatValue));
		}
		else
		{
			sprintf_s(format, 19, "%%0%d.%df", Length, item.Dec);
			sprintf_s(Temp, MAX_FIELD_LENGTH, format, FloatValue);
		}
		
		break;

	case FieldDef::DateTime:
		part = DateTimeFormatToCTS(ToFloat(data));
		break;

	case FieldDef::Repeat:
		break;
	}

	if(part.empty())
	{
		int l = strlen(Temp);
		part.resize(l, '\x0');
		strncpy((char*)part.c_str(), Temp, l);
	}

	if(part.length() != Length) 
	{
		throw TelegramItemSizeError(item.Name, false);
	}
}

void TextTelegramBuilder::ExtractPart(string& part, FieldDef& item, CommonData2& values)
{
	variant_t data;
	char format[20];
	format[19] = '\x0';

	int i;
	int IntData;
	double FloatData;
	FieldDef::FieldType Type = item.Type;
	short Length = item.Length;

	if(IsBlank(part))
	{
		values.setNull(item.Name);
	}
	else
	{
		switch(Type)
		{
		case FieldDef::Int: 
			//		data = (long)atoi(part.c_str());

			sprintf_s(format, 19, "%%%dd", Length);
			if(sscanf(part.c_str(), format, &IntData) == 1)
			{
				data = (long)IntData;
				values.setData(item.Name, data);
			}
			else
			{
				throw TelegramItemFormatError(item.Name, true);
			}
			break;

		case FieldDef::Float: 
			for(i = 0; i < part.size(); i++)
			{
				if(part[i] == ' ') part[i] = '0';
			}

			if (!this->IsFix)
			{
				sprintf_s(format, 19, "%%%dlf", Length);
				if (sscanf(part.c_str(), format, &FloatData) == 1)
				{
					data = FloatData;
				}
				else
				{
					throw TelegramItemFormatError(item.Name, true);
				}
			}
			else
			{
				sprintf_s(format, 19, "%%%dd", Length);
				if (sscanf(part.c_str(), format, &IntData) == 1)
				{
					FloatData = (double)IntData;
				}
				else
				{
					throw TelegramItemFormatError(item.Name, true);
				}

				for (int d = 0; d < item.Dec; d++)
				{
					FloatData /= 10;
				}

				data = FloatData;
			}

			values.setData(item.Name, data);
			break;

		case FieldDef::String: 
			part = Trim(part);

			data = (_bstr_t)part.c_str();
			values.setData(item.Name, data);
			break;
		}
	}
}

void TextTelegramBuilder::EmptyPart(string& part, FieldDef& item)
{
	char Temp[MAX_FIELD_LENGTH + 1];
	char format[20];

	Temp[MAX_FIELD_LENGTH] = '\x0';
	format[19] = '\x0';

	FieldDef::FieldType Type = item.Type;
	int Length = item.Length;

	switch(Type)
	{
	case FieldDef::Int:
		sprintf_s(format, 19, "%%0%dd", Length);
		sprintf_s(Temp, MAX_FIELD_LENGTH, format, 0);
		break;

	case FieldDef::String:
		sprintf_s(format, 19, "%%%ds", Length);
		sprintf_s(Temp, MAX_FIELD_LENGTH, format, " ");
		break;

	case FieldDef::Float:
		sprintf_s(format, 19, "%%0%d.%df", Length, item.Dec);
		sprintf_s(Temp, MAX_FIELD_LENGTH, format, 0);
		break;
	}

	if (strlen(Temp) != Length)
	{
		throw TelegramItemSizeError(item.Name, false);
	}

	part = "";
	part.resize(Length, 0x0);
	strncpy((char*)part.c_str(), Temp, Length);
}

void TextTelegramBuilder::EncodeItem(ostringstream& buffer, FieldDef& item, CommonData2& values, string& tel_name)
{
	string part;
	unsigned short Length = item.Length;
	string FieldName = item.Name;

	if(item.Type != FieldDef::Repeat)
	{
		variant_t Value = values.getData(FieldName);

		FormatPart(part, Value, item);
	}
	else
	{
		vector<FieldDef>& fds = Scheme->GetRepatParts(tel_name,item.Name);
		CommonDataList& V  = values.getVector(FieldName);

		V.ResetRow();
		while(V.NextRow())
		{
			vector<FieldDef>::iterator itr = fds.begin();
			CommonData2& row = V.Get();

			while(itr != fds.end())
			{
				EncodeItem(buffer, *itr, row, tel_name);
				itr++;
			}
		}

		//补齐不足的部分
		int difference  = (int)Length - V.RowCount();
		string temp;

		for(;difference > 0;difference--)
		{
			vector<FieldDef>::iterator itr = fds.begin();
			while(itr != fds.end())
			{
				EmptyPart(temp, *itr);
				buffer << temp;
				itr++;
			}
		}
	}

	buffer << part;
}

void TextTelegramBuilder::DecodeItem(string& telegram, unsigned int& pos, FieldDef& item, CommonData2& values, string& tel_name)
{
	string part;
	variant_t data;
	string FieldName = item.Name;
	unsigned short Length = item.Length;

	if(item.Type != FieldDef::Repeat)
	{
		if(telegram.length() >= pos + Length)
		{
			string part = telegram.substr(pos, Length);
		
			ExtractPart(part, item, values);

			pos += Length;
		}
		else
		{
			throw TelegramItemSizeError(item.Name, true);
		}
	}
	else
	{
		CommonDataList T;

		vector<FieldDef>& fds = Scheme->GetRepatParts(tel_name,item.Name);
		vector<FieldDef>::iterator itr = fds.begin();
		int RepeatTimes = item.Length;

		for(int K = 0; K < RepeatTimes; K++)
		{
			CommonData2 Temp;

			itr = fds.begin();
			while(itr != fds.end())
			{
				DecodeItem(telegram, pos, *itr, Temp, tel_name);
				itr++;
			} 

			T.Add(Temp);
		}

		values.setVector(FieldName, T);
	}
}

//对象-->电文
void TextTelegramBuilder::Encode(string& tel_name, string& telegram, CommonData2& values)
{
	ostringstream buffer;

	TelegramDef& fds = Scheme->GetTelgram(tel_name);
	vector<FieldDef>::iterator FieldIterator = fds.FieldDefs.begin();
	while(FieldIterator != fds.FieldDefs.end())
	{
		EncodeItem(buffer, *FieldIterator, values, tel_name);

		FieldIterator++;
	}

	telegram = buffer.str();	
}

//电文->对象
void TextTelegramBuilder::Decode(string& tel_name, string& telegram, CommonData2& values)
{
	TelegramDef& fds = Scheme->GetTelgram(tel_name);
	vector<FieldDef>::iterator FieldIterator = fds.FieldDefs.begin();

	if (fds.Length != telegram.size())
	{
		wchar_t s[100];
		swprintf(s, L"Telegram size Not Match: %d/%d", fds.Length, telegram.size());
		throw Exception(wstring(s), L"Telegram Decode");
	}

	unsigned int Position = 0;//位置初始化

	while(FieldIterator != fds.FieldDefs.end())
	{
		DecodeItem(telegram, Position, *FieldIterator, values, tel_name);

		FieldIterator++;
	}

	if(Position != telegram.size())
	{
		wchar_t s[100];
		swprintf(s, L"Telegram size Error:%d/%d", Position, telegram.size());
		throw Exception(wstring(s), L"Telegram Decode");
	}
}

//
// Class DelimiterTelegramBuilder
//

DelimiterTelegramBuilder::DelimiterTelegramBuilder(wstring& file_name, string delimiter)
	: TextTelegramBuilder(file_name)
{
	this->Delimiter = delimiter;
}

DelimiterTelegramBuilder::~DelimiterTelegramBuilder()
{
}

void DelimiterTelegramBuilder::FormatPart(string& part, variant_t& data, FieldDef& item)
{
	if(item.Type != FieldDef::FieldType::String)
	{
		TextTelegramBuilder::FormatPart(part, data, item);
	}
	else
	{
		part.clear();
		part = ToString(data);
		part = Trim(part);

		while(part.length() < item.Length)
		{
			part += '~';
		}

		if(part.length() > item.Length) part.resize(item.Length);
	}
}

void DelimiterTelegramBuilder::ExtractPart(string& part, FieldDef& item, CommonData2& values)
{
	TextTelegramBuilder::ExtractPart(part, item, values);
}

void DelimiterTelegramBuilder::EncodeItem(ostringstream& stream, FieldDef& item, CommonData2& values,string& tel_name)
{
	TextTelegramBuilder::EncodeItem(stream, item, values, tel_name);

	if(item.Type != FieldDef::FieldType::Repeat)
	{
		stream << this->Delimiter;
	}
}

void DelimiterTelegramBuilder::DecodeItem(string& telegram, unsigned int& pos, FieldDef& item, CommonData2& values, string& tel_name)
{
	string part;
	variant_t data;
	string FieldName = item.Name;
	unsigned short Length = item.Length;

	if(item.Type != FieldDef::Repeat)
	{
		if(telegram.length() >= pos + Length)
		{
			int p = telegram.find(this->Delimiter, pos);
			if(p != string::npos)
			{
				part = telegram.substr(pos, p - pos);

				for(int i = 0; i < part.size(); i++)
				{
					if(part[i] == '~')
					{
						part[i] = ' ';
					}
				}
			}

			ExtractPart(part, item, values);

			pos = p + 1;
		}
		else
		{
			throw TelegramItemSizeError(item.Name, true);
		}
	}
	else
	{
		CommonDataList T;

		vector<FieldDef>& fds = Scheme->GetRepatParts(tel_name, item.Name);
		vector<FieldDef>::iterator itr = fds.begin();
		int RepeatTimes = item.Length;
		if(RepeatTimes == 0 && item.RepeatCountField != "")
		{
			RepeatTimes = values.getInt(item.RepeatCountField);
		}

		for(int K = 0; K < RepeatTimes; K++)
		{
			CommonData2 Temp;

			itr = fds.begin();
			while(itr != fds.end())
			{
				DecodeItem(telegram, pos, *itr, Temp, tel_name);
				itr++;
			} 

			T.Add(Temp);
		}

		values.setVector(FieldName, T);
	}
}

void DelimiterTelegramBuilder::Encode(string& tel_name, string& telegram, CommonData2& values)
{
	TextTelegramBuilder::Encode(tel_name, telegram, values);
}

void DelimiterTelegramBuilder::Decode(string& tel_name, string& telegram, CommonData2& values)
{
	TextTelegramBuilder::Decode(tel_name, telegram, values);
}

//
// Class BinaryTelegramBuilder
//

#pragma region 

BinaryTelegramBuilder::BinaryTelegramBuilder(wstring& file_name)
	: BaseTelegramBuilder(file_name)
{
	IsBig = this->Scheme->IsBig;
}

BinaryTelegramBuilder::~BinaryTelegramBuilder()
{
}

//对象-->电文
void BinaryTelegramBuilder::Encode(string& tel_name, string& telegram, CommonData2& values)
{
	BinaryEncoder buffer;

	TelegramDef& fds = Scheme->GetTelgram(tel_name);
	vector<FieldDef>::iterator FieldIterator = fds.FieldDefs.begin();
	while(FieldIterator != fds.FieldDefs.end())
	{
		EncodeItem( buffer, *FieldIterator, values, tel_name);

		FieldIterator++;
	}

	telegram = buffer.GetData();
}

//电文->对象
void BinaryTelegramBuilder::Decode(string& tel_name, string& telegram, CommonData2& values)
{
	TelegramDef& fds = Scheme->GetTelgram(tel_name);
	vector<FieldDef>::iterator FieldIterator = fds.FieldDefs.begin();

	BinaryDecoder decoder(telegram);
	while(FieldIterator != fds.FieldDefs.end())
	{
		DecodeItem(decoder, *FieldIterator, values, tel_name);

		FieldIterator++;
	}
}

//电文->对象
void BinaryTelegramBuilder::Decode(short pos, string& telegram, CommonData2& values)
{
	char temp[20];
	itoa(pos, temp, 10);

	string str(temp);
	this->Decode(str, telegram, values);
}

//对象-->电文
void BinaryTelegramBuilder::Encode(short pos, string& telegram, CommonData2& values)
{
	char temp[20];
	itoa(pos, temp, 10);

	string str(temp);
	this->Encode(str, telegram, values);
}

void BinaryTelegramBuilder::DecodeItem(BinaryDecoder& decoder, FieldDef& item, CommonData2& values,string& tel_name)
{
	if(item.Type != FieldDef::Repeat)
	{
		if(!IsBig)
		{
			ExtractPart(decoder, item, values);
		}
		else
		{
			ExtractPartReverse(decoder, item, values);
		}
	}
	else
	{
		CommonDataList T;

		int repeatLen = 0;
		vector<FieldDef>& fds = Scheme->GetRepatParts(tel_name,item.Name);
		vector<FieldDef>::iterator itr = fds.begin();

		for(int K = 0; K < item.Length; K++)
		{
			CommonData2 Temp;
			itr = fds.begin();
			while(itr != fds.end())
			{
				DecodeItem(decoder, *itr, Temp, tel_name);
				itr++;
			}

			T.Add(Temp);
		}

		values.setVector(item.Name, T);
	}
}

void BinaryTelegramBuilder::ExtractPart(BinaryDecoder& decoder, FieldDef& item, CommonData2& values)
{
	FieldDef::FieldType Type = item.Type;

	switch(Type)
	{
	case FieldDef::Int: 
		if(item.Length == 2)
		{
			short temp;
			decoder.Read(temp);
			values.setInt(item.Name, temp);
		}
		else
		{
			int value;
			decoder.Read(value);
			values.setInt(item.Name, value);
		}
		break;

	case FieldDef::Float: 
		float temp;
		decoder.Read(temp);
		values.setFloat(item.Name, temp);
		break;

	case FieldDef::String: 
		string str;

		if(item.Length > 0)
		{
			decoder.Read(str, item.Length);
		}
		else
		{
			decoder.Read(str);
		}
		values.setString(item.Name, str);
		break;
	}
}

void BinaryTelegramBuilder::EncodeItem(BinaryEncoder& buffer, FieldDef& item, CommonData2& values,string& tel_name)
{
	unsigned short Length = item.Length;
	string FieldName = item.Name;

	if(item.Type != FieldDef::Repeat)
	{
		variant_t Value = values.getData(FieldName);
		if(!IsBig)
		{
			FormatPart(buffer, Value, item);
		}
		else
		{
			FormatPartReverse(buffer, Value, item);
		}
	}
	else
	{
		vector<FieldDef>& fds = Scheme->GetRepatParts(tel_name,item.Name);
		vector<FieldDef>::iterator itr = fds.begin();

		CommonDataList& V  = values.getVector(FieldName);
		V.ResetRow();
		while(V.NextRow())
		{
			CommonData2& row = V.Get();

			while(itr != fds.end())
			{
				EncodeItem(buffer, *itr, row, tel_name);
				itr++;
			}
		}
	}
}

void BinaryTelegramBuilder::FormatPart(BinaryEncoder& buffer, variant_t& data, FieldDef& item)
{
	char Temp[1000];
	char format[20];
	int Length = item.Length;
	FieldDef::FieldType Type = item.Type;

	switch(Type)
	{
	case FieldDef::Int:
		if(item.Length == 2)
		{
			short t = (short)ToLong(data);
			buffer.Write(t);
		}else
		{
			buffer.Write(ToLong(data));
		}

		break;

	case FieldDef::String:
		if(item.Length > 0)
		{
			buffer.Write(ToString(data),item.Length);
		}
		else
		{
			buffer.Write(ToString(data));
		}
		break;

	case FieldDef::Float:
		buffer.Write((float)ToFloat(data));
		break;
	}
}

void BinaryTelegramBuilder::FormatPartReverse(BinaryEncoder& buffer, variant_t& data, FieldDef& item)
{
	char Temp[1000];
	char format[20];
	int Length = item.Length;
	FieldDef::FieldType Type = item.Type;

	switch(Type)
	{
	case FieldDef::Int:
		if(item.Length == 2)
		{
			buffer.WriteReverse((short)ToLong(data));
		}
		else
		{
			buffer.WriteReverse(ToLong(data));
		}

		break;

	case FieldDef::String:
		if(item.Length > 0)
		{
			buffer.Write(ToString(data),item.Length);
		}
		else
		{
			buffer.Write(ToString(data));
		}
		break;

	case FieldDef::Float:
		buffer.WriteReverse((float)ToFloat(data));
		break;
	}
}

void BinaryTelegramBuilder::ExtractPartReverse(BinaryDecoder& decoder, FieldDef& item, CommonData2& values)
{
	FieldDef::FieldType Type = item.Type;

	switch(Type)
	{
	case FieldDef::Int: 
		if(item.Length == 2)
		{
			short value;
			decoder.ReadReverse(value);
			values.setInt(item.Name, value);
		}
		else
		{
			int value;
			decoder.ReadReverse(value);
			values.setInt(item.Name, value);
		}

		break;

	case FieldDef::Float: 
		float temp;
		decoder.ReadReverse(temp);
		values.setFloat(item.Name, temp);
		break;

	case FieldDef::String: 
		string str;
		if(item.Length > 0)
		{
			decoder.Read(str,item.Length);
		}
		else
		{
			decoder.Read(str);
		}

		values.setString(item.Name, str);
		break;
	}
}

#pragma endregion Class BinaryTelegramBuilder
