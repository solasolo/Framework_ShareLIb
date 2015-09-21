#pragma once

#pragma warning(disable:4786)

#include <string>

#include "CommonData2.h"
#include "CommonDB.h"
#include "SQLBuilder.h"
#include "EventLogger.h"

#include "SmartPointer.h"
//#include "SmartPtr.h"
#include "msado15.h"

using namespace std;
using namespace ADO;
using namespace GLEO;


//typedef SmartPointer<ADOData> SmartADOData;

class __declspec(dllexport) SimpleADODB : public EventSource
{
protected:
	wstring ConnectionString;
	wstring LastSQL;

	_ConnectionPtr Conn;

	void CreateConnection();
	_RecordsetPtr Query();
	int Exec();

	bool First(_RecordsetPtr& ds);
	variant_t Read(_RecordsetPtr& ds, wchar_t* field);

public:
	SimpleADODB(wstring con_str);
	~SimpleADODB();

	_RecordsetPtr DoQuery(wstring sql);
	int DoNonQuery(string sql);
	int DoNonQuery(wstring sql);

	void Open();
	void Close();
	wstring& getLastSQL();
};

class __declspec(dllexport) ADODB : public SimpleADODB
{
private:
	SmartPointer<SQLBuilder> SchemeBuilder;

	CommonDataList getResultSet(_RecordsetPtr m_RecordSet);
	vector<CommonData2> getResult_v(_RecordsetPtr m_RecordSet);

protected:
	DbType DBType;

public:
	ADODB(wstring con_str, DbType dbtype, wstring scheme_path);
	ADODB(wstring con_str, SmartPointer<SQLBuilder> builder);
	~ADODB();

	bool Exist(string table_name, string field_name, variant_t value);
	bool Exist(wstring sql);

	CommonDataList Select(string table_name);
	CommonDataList Select(string table_name, string condition);
	CommonDataList Select(string table_name, string field_name, variant_t value);
	CommonDataList Select(string table_name, CommonData2& cond);
	CommonDataList SelectBySql(wstring Sql);

	CommonData2 SelectTop(string table_name);
	CommonData2 SelectTop(string table_name, string condition);
	CommonData2 SelectTop(string table_name, string field_name, variant_t value);
	CommonData2 SelectTop(string table_name, CommonData2& cond);
	CommonData2 SelectTopBySql(wstring Sql);

	vector<CommonData2> Select_v(string table_name);
	vector<CommonData2> Select_v(string table_name, string condition);
	vector<CommonData2> Select_v(string table_name, string field_name, variant_t value);
	vector<CommonData2> Select_v(string table_name, CommonData2& cond);
	vector<CommonData2> SelectBySql_v(wstring Sql);

	int Update(string table_name, CommonData2& data, CommonData2& cond);
	int Update(string table_name, CommonData2& data, string field_name, variant_t value);
	int Insert(string table_name, CommonData2& data); 

	int Add(string table_name, string key_field, CommonData2& data);
	int Delete(string table_name, CommonData2& data);
	int Delete(string table_name, string field_name, variant_t value);
 };