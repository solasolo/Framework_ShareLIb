#ifndef SQLBUILDER_H
#define SQLBUILDER_H

#include "DBScheme.h"
#include "CommonData2.h"

using namespace MSXML2;

class __declspec(dllexport) SQLBuilder
{
private:
	DBScheme* Scheme; 
	DbType DBType;//数据库类型

	wstring MakeCondition(string table_name, CommonData2& values);
	wstring MakeValue(FieldDef& fd, CommonData2& values);

public:
	SQLBuilder(DbType dbtype, wstring file_name);
	~SQLBuilder();

	static wstring MakeOracleDate(double time);

	wstring MakeNullSelect(string table_name, CommonData2& conds);
	wstring MakeSelect(string table_name, CommonData2& conds);
	wstring MakeInsert(string table_name, CommonData2& values);
	wstring MakeDelete(string table_name, CommonData2& conds);
	wstring MakeUpdate(string table_name, CommonData2& values, CommonData2& conds);

	DbType getType();
};


#endif