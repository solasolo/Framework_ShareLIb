#include "CommonData2.h"

#include <vector>
#include <sstream>
#include <comutil.h>

#include "CommonFuncs.h"
#include "BaseException.h"
#include "CommonDatadef.h"

using namespace GLEO;

/////////////////////////////////////////////////////////////////////////////////////////////
CommonData2::DataItem::DataItem()
{
	this->Type = DataItemTypes::Type_NULL;
	this->Value.PointValue = NULL;
}

CommonData2::DataItem::DataItem(const DataItem& item)
{
	Copy(item);
}

CommonData2::DataItem::~DataItem()
{
	if(this->Type == DataItemTypes::Type_STRING || this->Type == DataItemTypes::Type_VECTOR)
	{
		DESTROY(Value.PointValue)
	}
}

void CommonData2::DataItem::Copy(const DataItem& other)
{
	this->Name = other.Name;
	this->Type = other.Type;

	if(this->Type == DataItemTypes::Type_STRING)
	{
		string* temp = new string();
		*temp = *(string*)other.Value.PointValue;
		DESTROY(this->Value.PointValue);
		this->Value.PointValue = temp;
	}
	else if(this->Type == DataItemTypes::Type_VECTOR)
	{
		CommonDataList* temp = new CommonDataList();
		*temp = *(CommonDataList*)other.Value.PointValue;
		DESTROY(this->Value.PointValue);
		this->Value.PointValue = temp;
	}
	else
	{
		this->Value = other.Value;
	}
}

bool CommonData2::DataItem::IsNull()
{
	return this->Type == Type_NULL;
}

variant_t CommonData2::DataItem::getData()
{
	variant_t value = NULL;
	value.vt = VT_NULL;
	string* s = NULL;

	switch (this->Type)
	{
	case Type_INT:
		value = this->Value.IntValue;
		value.vt = VT_I4;
		break;

	case Type_FLOAT:
		value = this->Value.FloatValue;
		value.vt = VT_R8;
		break;

	case Type_STRING: 
		s = (string*)this->Value.PointValue;
		if(s)
		{
			value = _com_util::ConvertStringToBSTR(s->c_str()); //(variant_t)(s->c_str());
			value.vt = VT_BSTR;
		}
		break;

	default:
		break;
	}

	return value;
}

int CommonData2::DataItem::getInt()
{
	int Result = 0;

	if(this->Type == DataItemTypes::Type_INT)
	{
		Result = this->Value.IntValue;
	}
	else if(this->Type == DataItemTypes::Type_STRING)
	{
		string s = *(string*)this->Value.PointValue;
		Result = atoi(s.c_str());
	}
	else if(this->Type == DataItemTypes::Type_FLOAT)
	{
		Result = int(this->Value.FloatValue);
	}
	else
	{
		string str = "Type UnMacth Int:" + this->Name;
		throw Exception(str.c_str());
	}

	return Result;
}

double CommonData2::DataItem::getFloat()
{
	double Result;

	if(this->Type == DataItemTypes::Type_FLOAT)
	{
		Result = this->Value.FloatValue;
	}
	else if(this->Type == DataItemTypes::Type_STRING)
	{
		string s = *(string*)this->Value.PointValue;
		Result = atof(s.c_str());
	}
	else if(this->Type == DataItemTypes::Type_INT)
	{
		Result = double(this->Value.IntValue);
	}
	else
	{
		string str = "Type UnMacth Float:" + this->Name;
		throw Exception(str.c_str());
	}

	return Result;
}

string CommonData2::DataItem::getString()
{
	string Result;
	char temp[50];
	temp[49] = '\x0';

	if(this->Type == DataItemTypes::Type_STRING)
	{
		Result = *(string*)(this->Value.PointValue);
	}
	else if(this->Type == DataItemTypes::Type_INT)
	{
		itoa(this->Value.IntValue,temp,10);
		Result = temp;
	}
	else if(this->Type == DataItemTypes::Type_FLOAT)
	{
		sprintf_s(temp, 49, "%f", this->Value.FloatValue);
		Result = temp;
	}
	else if(this->Type == DataItemTypes::Type_NULL)
	{
		Result = "";
	}
	else
	{
		string str = "Type UnMacth String:" + Name;
		throw Exception(str.c_str());
	}

	return Result;
}

wstring CommonData2::DataItem::getWString()
{
	return ~(this->getString());
}

CommonData2::DataItem& CommonData2::DataItem::operator =(const DataItem& other)
{
	Copy(other);
	return *this;
}

/////////////////////////////////////////////////////////////////////////////////////////////
CommonData2::CommonData2(void)
{
	MainData.clear();
}

CommonData2::CommonData2(const CommonData2& value)
{
	MainData.clear();
	Copy(value);
}

CommonData2::~CommonData2(void)
{
	Clear();
}

bool CommonData2::IsEmpty()
{
	return this->MainData.empty();
}

bool CommonData2::Has(string name)
{
	bool Result = true;
	ToUpper(name);

	/*if( GLEO::IsEmpty(getData(name)) ) 
		Result = false;*/
	map<string, CommonData2::DataItem*> :: iterator  itr;
	itr = this->MainData.find(name);
	if(itr == this->MainData.end())
	{
		Result = false;
	}

	return Result;
}

bool CommonData2::IsNull(string name)
{
	bool Result = true;
	ToUpper(name);

	/*if( GLEO::IsEmpty(getData(name)) ) 
		Result = false;*/
	map<string, CommonData2::DataItem*> :: iterator  itr;
	itr = this->MainData.find(name);
	if(itr != this->MainData.end())
	{
		Result = itr->second->IsNull();
	}

	return Result;
}

vector<string> CommonData2::getFiledNames()
{
	vector<string> temp;
	map<string, CommonData2::DataItem*> :: iterator  itr;
	for(itr =  MainData.begin(); itr != MainData.end(); itr++)
	{
		temp.push_back(itr->first);
	}
	return temp;
}

variant_t CommonData2::getData(string name)
{
	CommonData2::DataItem* Temp = getDataItem(name);

	return Temp->getData();
}

int CommonData2::getInt(string name)
{
	CommonData2::DataItem* Temp = getDataItem(name);

	return Temp->getInt();
}

double CommonData2::getFloat(string name)
{
	CommonData2::DataItem* Temp = getDataItem(name);

	return Temp->getFloat();
}

double CommonData2::getDate(string name)
{
	return getFloat(name);
}

string CommonData2::getStringDate(string name)
{
	return getString(name);
}

string CommonData2::getString(string name)
{
	CommonData2::DataItem* Temp = getDataItem(name);

	return Temp->getString();
}

wstring CommonData2::getWString(string name)
{
	CommonData2::DataItem* Temp = getDataItem(name);

	return Temp->getWString();
}

CommonDataList& CommonData2::getVector(string name)
{
	CommonDataList* T;
	ToUpper(name);
	
	map<string, DataItem*>::iterator itr = this->MainData.find(name);
	if(itr != this->MainData.end())
	{
		T = (CommonDataList*)itr->second->Value.PointValue;
	}
	else
	{
		throw Exception(wstring(L"No DataItem: ") + ~name, L"Get Vector");
	}

	return *T;
}

//time_t CommonData2::getTime(string name)
//{
//	return getInt(name);
//}

void CommonData2::setData(CommonData2& Data)
{
	map<string, DataItem*>::iterator itr = Data.MainData.begin();
	for(itr; itr != Data.MainData.end(); itr++)
	{
		this->setDataItem((itr)->first, (itr)->second);
	}
}

void CommonData2::setData(string name, variant_t& value)
{
	char* str = NULL;
	wchar_t* wstr = NULL;

	VARTYPE type = value.vt;
	switch (type)
	{
	case VT_NULL://数据库查出NULL
		setNull(name);
		break;

	case VT_R8:
		setFloat(name, value);
		break;

	case VT_DATE:
		setDate(name, value);
		break;

	case VT_INT:
	case VT_I4:
		setInt(name, value);
		break;

	case VT_LPSTR:
		str = (char*)value.ulVal;
		setString(name, str);
		break;

	case VT_BSTR:
	case VT_LPWSTR:
		wstr = (wchar_t*)value.ulVal;
		setString(name, ~wstring(wstr));
		//setString(name, (_com_util::ConvertBSTRToString((BSTR)value.ulVal)) );
		break;

	case VT_DECIMAL:
		setFloat(name,value);
		break;

	/*case VT_VECTOR:
		setVector(name, (vector<CommonData2>*)value);
		break;*/
	default:
		break;
	}
	//MainData.insert(map<string, DataItem>::value_type(name, item));
}

void CommonData2::setDataItem(string name, DataItem* value)
{
	ToUpper(name);
	value->Name = name;

	//寻找当前要插入的key是否存在 存在则先删除再插入
	map<string, CommonData2::DataItem*> :: iterator  itr;
	itr = this->MainData.find(name);

	if(itr != this->MainData.end())
	{
		//找到了
		DESTROY(itr->second);
		itr->second = value;
	}
	else
	{
		MainData.insert(pair<string,DataItem*>(name,value));
	}
}

void CommonData2::setNull(string name)
{
	DataItem* item = new DataItem();
	item->Type = DataItemTypes::Type_NULL;
	item->Value.PointValue = NULL;
	setDataItem(name, item);
}

void CommonData2::setInt(string name, int value)
{
	DataItem* item = new DataItem();
	item->Type = DataItemTypes::Type_INT;
	//int* i = new int();
	//*i = value;
	item->Value.IntValue = value;
	setDataItem(name, item);
}

void CommonData2::setInt(string name, string value)
{
	DataItem* item = new DataItem();
	item->Type = DataItemTypes::Type_INT;
	//int* i = new int();
	//*i = atoi(value.c_str());
	item->Value.IntValue = atoi(value.c_str());
	setDataItem(name, item);
}

void CommonData2::setFloat(string name, double value)
{
	DataItem* item = new DataItem();
	item->Type = DataItemTypes::Type_FLOAT;
	item->Value.FloatValue = value;
	setDataItem(name, item);
}

void CommonData2::setFloat(string name, string value)
{
	DataItem* item = new DataItem();
	item->Type = DataItemTypes::Type_FLOAT;
	item->Value.FloatValue = atof(value.c_str());
	setDataItem(name, item);
}

void CommonData2::setDate(string name, string value)
{
	//double t = GLEO::CTSToDateTime(value);
	//setFloat(name, t);
	setString(name, value);
}

void CommonData2::setDate(string name, DATE value)
{
	setFloat(name, value);
}

void CommonData2::setString(string name, string value)
{
	DataItem* item = new DataItem();
	item->Type = DataItemTypes::Type_STRING;
	string* str = new string();
	*str = value;
	item->Value.PointValue = str;
	setDataItem(name, item);
}

void CommonData2::setString(string name, wstring value)
{
	DataItem* item = new DataItem();
	item->Type = DataItemTypes::Type_STRING;
	item->Value.PointValue = &(~value);
	setDataItem(name, item);
}

void CommonData2::setVector(string name, CommonDataList& values)
{
	ToUpper(name);

	DataItem* item = new DataItem();
	item->Type = DataItemTypes::Type_VECTOR;

	CommonDataList* NewValue = new CommonDataList();
	*NewValue = values;
	item->Value.PointValue = NewValue;
	setDataItem(name, item);
}

//void CommonData2::setTime(string name, string value)
//{
//	setInt(name, value);
//}
//
//void CommonData2::setTime(string name, time_t value)
//{
//	setInt(name, value);
//}

void CommonData2::Clear()
{
	NamedValues::iterator itr = this->MainData.begin();
	while(itr != this->MainData.end())
	{
		if(itr->second)
		delete itr->second;

		itr++;
	}

	this->MainData.clear();
}

CommonData2& CommonData2::operator = (const CommonData2& other)
{
	Clear();
	Copy(other);
	return *this;
}

CommonData2& CommonData2::Copy(const CommonData2& other)
{
	NamedValues::const_iterator it =  other.MainData.begin();
	while(it != other.MainData.end())
	{
		string name = it->first;
		DataItem* item = new DataItem();
		DataItem* otheritem = (it->second);
		*item = *otheritem;
		this->setDataItem(name, item);
		it++;
	}
	return *this;
}

CommonData2::DataItem* CommonData2::getDataItem(string name)
{
	CommonData2::DataItem* Result = NULL;
	ToUpper(name);

	map<string, CommonData2::DataItem*> :: iterator  itr;
	itr = this->MainData.find(name);
	if(itr != this->MainData.end())
	{
		Result = itr->second;
	}
	else
	{
		throw Exception(wstring(L"No DataItem: ") + ~name, L"Get Data Item");
	}

	return Result;
}

void CommonData2::WriteItemInfo(wstringstream& stream, const string& name, DataItem* item)
{
	wstring ItemName = ~name;

	if (item->Type == Type_VECTOR)
	{
		CommonDataList* v = (CommonDataList*) item->Value.PointValue;

		stream << L"----<" << ItemName << L">[" << v->RowCount() << L"]----" << endl;
		this->WriteVectorInfo(stream, "  ", *v);
	}
	else
	{
		stream << ItemName  << L"(" << item->Type << L")" << L"=" << item->getWString() << endl;
	}
}

void CommonData2::WriteVectorInfo(wstringstream& stream, string space, CommonDataList& item)
{
	int count = 1;
	char temp[10];

	item.ResetRow();
	while(item.NextRow())
	{
		CommonData2& row = item.Get();

		for (map<string, DataItem*>::iterator item = row.MainData.begin(); item != row.MainData.end(); item++)  
		{  
			this->WriteItemInfo(stream, item->first, item->second);
		}  
		
		stream << "end of " << count++ << L"----------------------------------" << endl;
	}
}

wstring CommonData2::ToDebugString()
{
	wstringstream stream;

	stream << endl;

	for (map<string, DataItem*>::iterator it = MainData.begin(); it != MainData.end(); it++)  
    {  
		this->WriteItemInfo(stream, it->first, it->second); 
    }  

	return stream.str();
}

/////////////////////////////////////////////////////////////////////////////////////////////
CommonDataList::CommonDataList()
{
	this->Clear();
}

CommonDataList::CommonDataList(const CommonDataList& data)
{
	this->Clear();

	this->DataContainer = data.DataContainer;
}

CommonDataList& CommonDataList::operator = (const CommonDataList& other)
{
	this->Clear();

	this->DataContainer = other.DataContainer;

	return *this;
}

CommonData2* CommonDataList::GetCurrentData()
{
	CommonData2* Result = NULL;

	if(this->CurrentIndex < this->DataContainer.size())
	{
		Result = &(this->DataContainer[CurrentIndex]);
	}
	else
	{
		throw Exception(L"Out of Range", L"CommonDataList");
	}

	return Result;
}

SmartPointer<CommonData2> CommonDataList::AddNewRow()
{
	SmartPointer<CommonData2> Row = new CommonData2();
	this->DataContainer.push_back(Row);

	this->CurrentIndex = this->DataContainer.size() - 1;

	return Row;
}

void CommonDataList::Add(CommonData2& data)		
{
	this->NewRow();
	this->Get() = data;
}

void CommonDataList::Add(SmartPointer<CommonData2>& data)		
{
	SmartPointer<CommonData2> row = this->AddNewRow();
	row = data;
}


CommonData2& CommonDataList::Get()
{
	CommonData2* data = this->GetCurrentData();

	return *data;
}

void CommonDataList::Clear()
{
	this->DataContainer.clear();
	this->CurrentIndex = -1;
}

bool CommonDataList::IsEmpty()
{
	return this->DataContainer.empty();
}

bool CommonDataList::Has(string name)
{
	bool Result = false;

	CommonData2* data = this->GetCurrentData();

	Result = data->Has(name);

	return Result;
}

variant_t CommonDataList::getData(string name)
{
	variant_t Result;

	CommonData2* data = this->GetCurrentData();

	Result = data->getData(name);

	return Result;
}

void CommonDataList::setData(string name, variant_t& value)
{
	CommonData2* data = this->GetCurrentData();
	data->setData(name, value);
}

int CommonDataList::getInt(string name)
{
	int Result;

	CommonData2* data = this->GetCurrentData();
	Result = data->getInt(name);

	return Result;
}

double CommonDataList::getFloat(string name)
{
	double Result;

	CommonData2* data = this->GetCurrentData();
	Result = data->getFloat(name);

	return Result;
}

DATE CommonDataList::getDate(string name)
{
	DATE Result;

	CommonData2* data = this->GetCurrentData();
	Result = data->getDate(name);

	return Result;
}

string CommonDataList::getString(string name)
{
	string Result;

	CommonData2* data = this->GetCurrentData();
	Result = data->getString(name);

	return Result;
}

void CommonDataList::setInt(string name, int value)
{
	CommonData2* data = this->GetCurrentData();
	data->setInt(name, value);
}

void CommonDataList::setFloat(string name, double value)
{
	CommonData2* data = this->GetCurrentData();
	data->setFloat(name, value);
}

void CommonDataList::setDate(string name, DATE value)
{
	CommonData2* data = this->GetCurrentData();
	data->setDate(name, value);
}

void CommonDataList::setString(string name, string value)
{
	CommonData2* data = this->GetCurrentData();
	data->setString(name, value);
}

bool CommonDataList::ResetRow()
{
	bool Result = false;

	this->CurrentIndex = -1;
	if(this->CurrentIndex < this->DataContainer.size())
	{
		Result = true;
	}

	return Result;
}

bool CommonDataList::NextRow()
{
	bool Result = false;

	this->CurrentIndex++;
	if(this->CurrentIndex < this->DataContainer.size())
	{
		Result = true;
	}

	return Result;
}

void CommonDataList::NewRow()
{
	this->AddNewRow();
}

int CommonDataList::RowCount()
{
	return this->DataContainer.size();
}

