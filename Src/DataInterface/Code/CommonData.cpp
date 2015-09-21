//#include "stdafx.h"

#include "CommonData.h"
#include "CommonFuncs.h"

using namespace GLEO;

//----------------------------------------------------------------------------

bool BaseCommonData::Has(string name)
{
	bool Result = true;

	if( GLEO::IsEmpty(getData(name)) ) 
		Result = false;

	return Result;
}

int BaseCommonData::getInt(string name)
{
	return ToLong(getData(name));
}

double BaseCommonData::getFloat(string name)
{
	return ToFloat(getData(name));
}

string BaseCommonData::getString(string name)
{
	return ToString(getData(name));
}

time_t BaseCommonData::getTime(string name)
{
	return ToTime(getData(name));
}

void BaseCommonData::setInt(string name, int value)
{
	setData(name, variant_t((long)value));
}

void BaseCommonData::setFloat(string name, double value)
{
	setData(name , variant_t(value));
}

void BaseCommonData::setString(string name, string& value)
{
	setData(name, variant_t(value.c_str()));
}

void BaseCommonData::setString(string name, char value)
{
	string tempstr = "";
	tempstr += value;
	setString(name, tempstr);
}

void BaseCommonData::setTime(string name, time_t value)
{
	setData(name, FromTime(value));	
}

void BaseCommonData::setInt(string name, string value)
{
	setInt(name, atoi(value.c_str()));
}

void BaseCommonData::setFloat(string name, string value)
{
	setFloat(name, atof(value.c_str()));
}

//----------------------------------------------------------------------------
CommonData::CommonData()
{
//	InnerIterator = MainData.begin();
}

CommonData& CommonData::operator =(BaseCommonData& data)
{
	Clear();

	if(data.ResetItem())
	{
		do
		{
			setData(data.getName(), data.getData());
		}
		while(data.NextItem());
	}

	return *this;
}

string CommonData::MakeRepeatName(string name, int index)
{
	char Result[50];
	Result[49] = '\x0';

	sprintf_s(Result, 49, "%s[%d]", name.c_str(), index);

	return Result;
}

bool CommonData::ResetItem()
{
	InnerIterator = MainData.begin();
	return InnerIterator != MainData.end();
}

bool CommonData::NextItem()
{
	InnerIterator++;
	return InnerIterator != MainData.end();
}

bool CommonData::ResetRow()
{
	return true;
}

bool CommonData::NextRow()
{
	return false;
}


variant_t CommonData::getData()
{
	variant_t Result;
	if(InnerIterator != MainData.end()) Result = InnerIterator->Value;

	return Result;
}

string CommonData::getName()
{
	string Result = "";
	if(InnerIterator != MainData.end()) 
	{
		Result = InnerIterator->Name;
	}

	return Result;
}

void CommonData::Clear()
{
	MainData.clear();
}

bool CommonData::IsEmpty()
{
	return MainData.empty();
}

variant_t CommonData::getData(string name)
{
	return getRepData(name, -1);
}

void CommonData::setData(string name, variant_t& value)
{
	setRepData(name, -1, value);
}

//----------------------------------------------------------------------------
bool CommonData::getRepeat(int index, BaseCommonData& data)
{
	bool Result = false;
	data.Clear();

	NamedValues::iterator it;
	NamedValues::iterator last = MainData.end();

	for(it = MainData.begin(); it != last; it++)
	{
		if(it->Index == index)
		{
			data.setData(it->Name, it->Value);
			Result = true;
		}
	}

	return Result;
}

void CommonData::setRepeat(int index, BaseCommonData& data)
{
	if(data.ResetItem())
	{
		do
		{
			setRepData(data.getName(), index, data.getData());
		}
		while(data.NextItem());
	}
}

variant_t CommonData::getRepData(string name, int index)
{
	variant_t Result;

	NamedValues::iterator it;
	NamedValues::iterator last = MainData.end();

	for(it = MainData.begin(); it != last; it++)
	{
		if(it->Name == name && it->Index == index)
		{
			Result = it->Value;
			break;
		}
	}

	return Result;
}

int CommonData::getRepInt(string name, int index)
{
	return ToLong(getRepData(name, index));
}

double CommonData::getRepFloat(string name, int index)
{
	return ToFloat(getRepData(name, index));
}

time_t CommonData::getRepTime(string name, int index)
{
	return ToTime(getRepData(name, index));
}

string CommonData::getRepString(string name, int index)
{
	return ToString(getRepData(name, index));
}

void CommonData::setRepData(string name, int index, variant_t& value)
{
	variant_t Result;

	NamedValues::iterator it;
	NamedValues::iterator last = MainData.end();

	for(it = MainData.begin(); it != last; it++)
	{
		if(it->Name == name && it->Index == index)
		{
			break;
		}
	}

	if(it == last)
	{
		DataItem item;

		item.Index = index;
		item.Name = name;
		item.Value = value;

		MainData.push_back(item);
	}
	else
	{
		it->Value = value;
		it->Index = index;
	}
}

void CommonData::setRepInt(string name, int index, int value)
{
	setRepData(name, index,  variant_t((long)value));
}

void CommonData::setRepInt(string name, int index, string value)
{
	setRepInt(name, index, atoi(value.c_str()));
}

void CommonData::setRepFloat(string name, int index, double value)
{
	setRepData(name, index, variant_t(value));
}

void CommonData::setRepFloat(string name, int index, string value)
{
	setRepFloat(name, index, atof(value.c_str()));
}

void CommonData::setRepTime(string name, int index, time_t value)
{
	setRepData(name, index, FromTime(value));
}

void CommonData::setRepString(string name, int index, string& value)
{
	setRepData(name, index, variant_t(value.c_str()));
}
