#ifndef COMMONDATA_H
#define COMMONDATA_H

#pragma warning(disable:4786)

#include <comutil.h>
#include <vector>
#include <string>

using namespace std;

class BaseCommonData
{
public:
	virtual void Clear() = 0;
	virtual bool IsEmpty() = 0;

	virtual bool ResetItem() = 0;
	virtual bool NextItem() = 0;

	virtual bool ResetRow() = 0;
	virtual bool NextRow() = 0;

	virtual variant_t getData(string name) = 0;
	virtual void setData(string name, variant_t& value) = 0;
	virtual variant_t getData() = 0;
	virtual string getName() = 0;

	bool Has(string name);

	int getInt(string name);
	double getFloat(string name);
	time_t getTime(string name);
	string getString(string name);

	void setInt(string name, int value);
	void setInt(string name, string value);
	void setFloat(string name, double value);
	void setFloat(string name, string value);
	void setTime(string name, time_t value);
	void setString(string name, string& value);
	void setString(string name, char value);
};

class CommonData : public BaseCommonData
{
private:
	struct DataItem
	{
		string Name;
		variant_t Value;
		int Index;
	};

	typedef vector<DataItem> NamedValues;

	NamedValues MainData;
	NamedValues::iterator InnerIterator;
	
	string MakeRepeatName(string name, int index); 

public:
	CommonData();

	void Clear();
	bool IsEmpty();

	bool ResetItem();
	bool NextItem();

	bool ResetRow();
	bool NextRow();

	variant_t getData();
	string getName();

	// Data Access
	variant_t getData(string name);
	void setData(string name, variant_t& value);

	CommonData& operator =(BaseCommonData& data);

	// Repeat Data Access
	bool getRepeat(int index, BaseCommonData& data);
	variant_t getRepData(string name, int index);
	void setRepData(string name, int index, variant_t& value);
	void setRepeat(int index, BaseCommonData& data);

	int getRepInt(string name, int index);
	double getRepFloat(string name, int index);
	time_t getRepTime(string name, int index);
	string getRepString(string name, int index);

	void setRepInt(string name, int index, int value);
	void setRepInt(string name, int index, string value);
	void setRepFloat(string name, int index, double value);
	void setRepFloat(string name, int index, string value);
	void setRepTime(string name, int index, time_t value);
	void setRepString(string name, int index, string& value);
};

#endif