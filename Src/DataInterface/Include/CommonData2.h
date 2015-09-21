#pragma once

#include <Windows.h>
#include <comutil.h>
#include <string>
#include <map>
#include <list>
#include <vector>

#include "CommonDataDef.h"
#include "SmartPointer.h"

using namespace std;
using namespace GLEO;

struct __declspec(dllexport) DateItem;

enum DataItemTypes
{
	Type_NULL = 0,
	Type_INT,
	Type_FLOAT,
	Type_STRING,
	Type_VECTOR
};


class CommonDataList;

class __declspec(dllexport) CommonData2 : public ICommonData 
{
private :
	CommonData2& Copy(const CommonData2& other);

protected:
	union values
	{
		void* PointValue;
		int IntValue;
		double FloatValue;

		values()
		{
			PointValue = NULL;
			IntValue = 0;
			FloatValue = 0.0f;
		}
	};

	struct DataItem
	{
		string Name;
		DataItemTypes Type;
		values Value;

		DataItem();
		DataItem(const DataItem& item);

		~DataItem();

		void Copy(const DataItem& other);

		bool IsNull();

		variant_t getData();
		int getInt();
		double getFloat();
		double getDate();
		string getStringDate();
		string getString();
		wstring getWString();
		CommonDataList& getVector();
		//time_t getTime();

		DataItem& operator =(const DataItem& other);
	};

	typedef map<string, DataItem*> NamedValues;

	NamedValues MainData;

	void setDataItem(string name, DataItem* value);
	DataItem* getDataItem(string Name);
	void WriteItemInfo(wstringstream& stream, const string& name, DataItem* item);
	void WriteVectorInfo(wstringstream& stream, string space, CommonDataList& item);

public:
	CommonData2(void);
	CommonData2(const CommonData2& value);
	~CommonData2(void);

	bool Has(string name);
	bool IsEmpty();
	bool IsNull(string Name);
	vector<string> getFiledNames();

	variant_t getData(string Name);
	int getInt(string name);
	double getFloat(string name);
	DATE getDate(string name);
	string getStringDate(string name);
	string getString(string name);
	wstring getWString(string name);
	CommonDataList& getVector(string name);
	//time_t getTime(string name);

	void setNull(string name);
	void setData(CommonData2& Data);
	void setData(string name, variant_t& value);

	void setInt(string name, int value);
	void setFloat(string name, double value);
	void setDate(string name, DATE value);
	void setVector(string name, CommonDataList& values);

	void setInt(string name, string value);
	void setFloat(string name, string value);
	void setDate(string name, string value);
	void setString(string name, string value);
	void setString(string name, wstring value);

	//void setTime(string name, string value);
	//void setTime(string name, time_t value);

	void Clear();
	wstring ToDebugString();

	CommonData2& operator = (const CommonData2& other);
};

class __declspec(dllexport) CommonDataList : public ICommonData 
{
	typedef SmartPointer<CommonData2> DataPtr;

private:
	int CurrentIndex;
	vector<DataPtr> DataContainer;

	CommonData2* GetCurrentData();
	SmartPointer<CommonData2> CommonDataList::AddNewRow();

public:
	CommonDataList();
	CommonDataList(const CommonDataList& data);

	void Add(CommonData2& data);	
	void Add(SmartPointer<CommonData2>& data);
	CommonData2& Get();

	virtual void Clear();
	virtual bool IsEmpty();
	virtual bool Has(string name);

	virtual variant_t getData(string name);
	virtual void setData(string name, variant_t& value);

	virtual int getInt(string name);
	virtual double getFloat(string name);
	virtual DATE getDate(string name);
	virtual string getString(string name);

	virtual void setInt(string name, int value);
	virtual void setFloat(string name, double value);
	virtual void setDate(string name, DATE value);
	virtual void setString(string name, string value);

	virtual bool ResetRow();
	virtual bool NextRow();
	virtual void NewRow();
	virtual int RowCount();

	CommonDataList& operator = (const CommonDataList& other);
};

#pragma make_public(CommonData2)
