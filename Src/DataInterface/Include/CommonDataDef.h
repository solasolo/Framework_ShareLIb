#ifndef COMMONDATADEF_H
#define COMMONDATADEF_H

#include <string>
#include <algorithm>
#include <CommonFuncs.h>

using namespace GLEO;
using namespace std;

struct FieldDef
{
	enum FieldType
	{
		Unknow,
		String,
		Int,
		Float,
		DateTime,

		Repeat = 100
	};

	short No;
	string Name;
	FieldType Type;
	short Length;
	short Dec;
    string Format;
	string RepeatCountField;

	void Clear()
	{
		No = 0;
		Length = 0;
		Dec = 0;
		Name = "";
		Type = Unknow;
		Format = "";
	};

	void SetType(string name)
	{
		ToLower(name);

		if(name == "string")
		{
			Type = String;
		}
		else if(name == "int")
		{
			Type = Int;
		}
		else if(name == "float")
		{
			Type = Float;
			this->Dec = 2;
		}
		else if(name == "datetime")
		{
			Type = DateTime;
		}
		else if(name == "repeat")
		{	
			Type = Repeat;
		}
		else
		{
			Type = Unknow;
		}
	};
};

class ICommonData
{
public:
	virtual void Clear() = 0;
	virtual bool IsEmpty() = 0;
	virtual bool Has(string name) = 0;

	virtual variant_t getData(string name) = 0;
	virtual void setData(string name, variant_t& value) = 0;

	virtual int getInt(string name) = 0;
	virtual double getFloat(string name) = 0;
	virtual DATE getDate(string name) = 0;
	virtual string getString(string name) = 0;

	virtual void setInt(string name, int value) = 0;
	virtual void setFloat(string name, double value) = 0;
	virtual void setDate(string name, DATE value) = 0;
	virtual void setString(string name, string value) = 0;
};

class ICommonDataList : public ICommonData
{
public:
	virtual bool ResetRow() = 0;
	virtual bool NextRow() = 0;
	virtual void NewRow() = 0;
	virtual int RowCount() = 0;
};

/////
//此处添加数据库类型 SQLBuilder::MakeValue 补齐代码
////
enum DbType
{
	Oracle,
	MSQL
};


#endif