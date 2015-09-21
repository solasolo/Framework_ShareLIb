#ifndef COMMONDB_H
#define COMMONDB_H

#include "CommonData.h"

class CommonDB
{
public:
	virtual bool Exist() = 0;

	virtual CommonData Select(string table_name) = 0;
	virtual CommonData Select(string table, string condition) = 0;
	virtual CommonData Select(string table, string field_name, variant_t value) = 0;

	virtual int Update(string talbe, CommonData& data) = 0;
	virtual int Update(string talbe, CommonData& data, string field_name, variant_t value) = 0;
	
	virtual int Insert(string talbe, CommonData& data) = 0; 

	virtual int Delete(string talbe, CommonData& data) = 0;
	virtual int Delete(string talbe, string field_name, variant_t value) = 0;
};

#endif