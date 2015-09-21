#pragma once

#pragma warning(disable:4786)

#include <string>
#include <vector>
#include <exception>
//#include "msado15.h"
using namespace std;

struct ODBCError
{
	int Code;
	string State;
	string Message;
};

class ODBCException : public exception
{
};

class ODBCDB
{
public:
	ODBCDB(void);
	~ODBCDB(void);
	void CheckError(char *caFunction, int retcode, SQLSMALLINT sHandleType, SQLHANDLE hHandle);
	void Connect(const wchar_t *ServerName, const wchar_t *UserName, const wchar_t *Password);
	void DisConnect();
	void IsOpen();
	int Select(wstring TableName); 
	int Delete(wstring TableName, wstring Condition);
	int InsertInto(wstring TableName, wstring Value);
	int Update(wstring TableName, wstring Condition);
	
	
private:
	SQLHENV henv;
	SQLHDBC hdbc;
	SQLHSTMT hstmt;
	SQLRETURN retcode;
	wchar_t *ServerName;
	wchar_t *UserName;
	wchar_t *Password;
};

