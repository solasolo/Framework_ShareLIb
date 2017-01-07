#ifndef TELEGRAMBUILDER_H
#define TELEGRAMBUILDER_H

#include "TelegramScheme.h"
#include "CommonData2.h"
#include "msxml3.h"
#include "SimpleProtocol.h"

using namespace MSXML2;

class BaseTelegramItemError : public Exception
{
protected:
	wstring ItemName;

public:
	BaseTelegramItemError(string item, bool decode);

	BaseTelegramItemError& operator =(const BaseTelegramItemError& ex) throw();
};

class TelegramItemSizeError : public BaseTelegramItemError
{
protected:
	virtual wstring GetErrorDescription();

public:
	TelegramItemSizeError(string item, bool decode);
};

class TelegramItemFormatError : public BaseTelegramItemError
{
protected:
	virtual wstring GetErrorDescription();

public:
	TelegramItemFormatError(string item, bool decode);
};

class ITelegramBuilder
{
public:
	virtual void Encode(string& tel_name, string& telegram, CommonData2& values) = 0;
	virtual void Decode(string& tel_name, string& telegram, CommonData2& values) = 0;
};

class __declspec(dllexport) BaseTelegramBuilder
{
protected:
	static const int MAX_FIELD_LENGTH;

	TelegramScheme* Scheme; 

public:
	BaseTelegramBuilder(wstring& file_name);
	virtual ~BaseTelegramBuilder();
};

class __declspec(dllexport) TextTelegramBuilder : public BaseTelegramBuilder, public ITelegramBuilder
{
private:
	bool IsFix;
	char BlankChar;

protected:
	virtual void EncodeItem(ostringstream& stream, FieldDef& item, CommonData2& values, string& tel_name);
	virtual void DecodeItem(string& telegram, unsigned int& pos, FieldDef& item, CommonData2& values, string& tel_name);

	void EmptyPart(string& part, FieldDef& item);
	bool IsBlank(string& part);

	virtual void FormatPart(string& part, variant_t& data, FieldDef& item);
	virtual void ExtractPart(string& part, FieldDef& item, CommonData2& values);

public:
	TextTelegramBuilder(wstring& file_name);
	virtual ~TextTelegramBuilder(); 

	//对象-->电文
	virtual void Encode(string& tel_name, string& telegram, CommonData2& values);
	//电文->对象
	virtual void Decode(string& tel_name, string& telegram, CommonData2& values);
};

class __declspec(dllexport) DelimiterTelegramBuilder : public TextTelegramBuilder
{
private:
	string Delimiter;

protected:
	virtual void EncodeItem(ostringstream& stream, FieldDef& item, CommonData2& values,string& tel_name);
	virtual void DecodeItem(string& telegram, unsigned int& pos, FieldDef& item, CommonData2& values, string& tel_name);

	virtual void FormatPart(string& part, variant_t& data, FieldDef& item);
	virtual void ExtractPart(string& part, FieldDef& item, CommonData2& values);

public:
	DelimiterTelegramBuilder(wstring& file_name, string delimiter = ";"); 
	virtual ~DelimiterTelegramBuilder();

	//对象-->电文
	virtual void Encode(string& tel_name, string& telegram, CommonData2& values);
	//电文->对象
	virtual void Decode(string& tel_name, string& telegram, CommonData2& values);
};

class __declspec(dllexport) BinaryTelegramBuilder : public BaseTelegramBuilder, public ITelegramBuilder
{
private:
	bool IsBig;

	void EncodeItem(BinaryEncoder& encoder, FieldDef& item, CommonData2& values,string& tel_name);
	void DecodeItem(BinaryDecoder& decoder, FieldDef& item, CommonData2& values,string& tel_name);
	
protected:
	virtual void FormatPart(BinaryEncoder& encoder, variant_t& data, FieldDef& item);
	virtual void ExtractPart(BinaryDecoder& decoder, FieldDef& item, CommonData2& values);
	virtual void FormatPartReverse(BinaryEncoder& encoder, variant_t& data, FieldDef& item);
	virtual void ExtractPartReverse(BinaryDecoder& decoder, FieldDef& item, CommonData2& values);

public:
	BinaryTelegramBuilder(wstring& file_name); 
	virtual ~BinaryTelegramBuilder(); 

	//对象-->电文
	virtual void Encode(string& tel_name, string& telegram, CommonData2& values);
	//电文->对象
	virtual void Decode(string& tel_name, string& telegram, CommonData2& values);

	//对象-->电文
	void Encode(short tel_num, string& telegram, CommonData2& values);
	//电文->对象
	void Decode(short tel_num, string& telegram, CommonData2& values);
};
#endif