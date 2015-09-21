//#include "stdafx.h"
#include <Windows.h>
#include <sqlext.h>

#include "SmartODBCDB.h"

ODBCDB::ODBCDB(void)
{
	hdbc = NULL;
	henv = NULL;
	hstmt = NULL;
	retcode = 0;
}

ODBCDB::~ODBCDB(void)
{
	DisConnect();
}

void ODBCDB::CheckError(char *caFunction, int retcode, SQLSMALLINT sHandleType, SQLHANDLE hHandle)
{
	SQLWCHAR caSqlState[6], caMsg[SQL_MAX_MESSAGE_LENGTH];
	SQLINTEGER iNativeError;
	SQLSMALLINT i, iMsgLen;
	char caHandleType[20];

	switch (sHandleType)
	{
		case SQL_HANDLE_ENV:
			strcpy(caHandleType,"Environment Handle");
			break;

		case SQL_HANDLE_DBC:
			strcpy(caHandleType,"Connect Handle");
			break;

		case SQL_HANDLE_STMT:
			strcpy(caHandleType,"Statement Handle");
			break;
	}

	if(hHandle == 0)
	{
		throw exception("Handle is Null!");
	}

	else 
	{
		if((retcode == SQL_ERROR) || (retcode == SQL_SUCCESS_WITH_INFO))
		{
			i=1;
																
			while((retcode = SQLGetDiagRec(sHandleType, hHandle, i, caSqlState, &iNativeError, caMsg, SQL_MAX_MESSAGE_LENGTH, &iMsgLen)) != SQL_NO_DATA)
			{
				i++;
			}
			throw ODBCException();
		}
		else if(retcode == SQL_ERROR)
			throw ODBCException();
	}
}

void ODBCDB::Connect(const wchar_t *cpServerName, const wchar_t *cpUserName, const wchar_t *cpPassword)
{
	//分配环境句柄
	retcode = SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &henv);
	CheckError("分配环境句柄失败!", retcode, SQL_HANDLE_ENV, henv);
	
	
	// Set the ODBC version environment attribute 
	retcode = SQLSetEnvAttr(henv, SQL_ATTR_ODBC_VERSION, (void*)SQL_OV_ODBC3, 0); 
	CheckError("设置odbc版本号时失败!", retcode, SQL_HANDLE_ENV, henv);
	
	
	//分配连接句柄
	retcode = SQLAllocHandle(SQL_HANDLE_DBC, henv, &hdbc); 
	CheckError("分配连接句柄失败!", retcode, SQL_HANDLE_DBC, hdbc);
	
	
	// 连接数据库
	retcode = SQLConnect(hdbc, (SQLWCHAR*) cpServerName, SQL_NTS, (SQLWCHAR*) cpUserName, SQL_NTS, (SQLWCHAR*) cpPassword, SQL_NTS);
	CheckError("连接数据库失败!", retcode, SQL_HANDLE_DBC, hdbc);
	
	
	return;
}




int ODBCDB::Select(wstring TableName) //执行SQL查询语句
{
	Connect(ServerName,NULL,NULL);

	SQLHSTMT hstmt;
	if(hdbc == NULL)
	{
		throw ODBCException();
	}
	else
	{
		retcode = SQLAllocHandle(SQL_HANDLE_STMT, hdbc, &hstmt);

		wstring cpSqlStmt = L"select * from ";
		cpSqlStmt = cpSqlStmt + TableName;
	
		retcode = SQLExecDirect(hstmt, (wchar_t*)cpSqlStmt.c_str(), SQL_NTS);
		CheckError("执行sql语句失败,不能执行", retcode, SQL_HANDLE_STMT, hstmt);
	}
	return 0;
}


int ODBCDB::Delete(wstring TableName, wstring Condition) //执行SQL删除语句

{
	Connect(ServerName,NULL,NULL);

	SQLHSTMT hstmt;
	if(hdbc == NULL)
	{
		throw ODBCException();
	}
	else
	{
		retcode = SQLAllocHandle(SQL_HANDLE_STMT, hdbc, &hstmt);

		wstring cpSqlStmt = L"Delete from ";
		cpSqlStmt = cpSqlStmt + TableName +  L" Where " + Condition;
	
		retcode = SQLExecDirect(hstmt, (wchar_t*)cpSqlStmt.c_str(), SQL_NTS);
		CheckError("执行sql语句失败,不能执行", retcode, SQL_HANDLE_STMT, hstmt);
	}
	return 0;
}


//TODO:deal with wstring Value
int ODBCDB::InsertInto(wstring TableName, wstring Value) //执行SQL插入语句
{
	Connect(ServerName,NULL,NULL);

	SQLHSTMT hstmt;
	if(hdbc == NULL)
	{
		throw ODBCException();
	}
	else
	{
		retcode = SQLAllocHandle(SQL_HANDLE_STMT, hdbc, &hstmt);

		wstring cpSqlStmt = L"Insert Into ";
		cpSqlStmt = cpSqlStmt + TableName +  L" Values " + Value;
	
		retcode = SQLExecDirect(hstmt, (wchar_t*)cpSqlStmt.c_str(), SQL_NTS);
		CheckError("执行sql语句失败,不能执行", retcode, SQL_HANDLE_STMT, hstmt);
	}
	return 0;
}

int ODBCDB::Update(wstring TableName, wstring Condition) //执行SQL更新语句
{
	Connect(ServerName,NULL,NULL);

	SQLHSTMT hstmt;
	if(hdbc == NULL)
	{
		throw ODBCException();
	}
	else
	{
		retcode = SQLAllocHandle(SQL_HANDLE_STMT, hdbc, &hstmt);

		wstring cpSqlStmt = L"Update ";
		cpSqlStmt = cpSqlStmt + TableName +  L" Where " + Condition;
	
		retcode = SQLExecDirect(hstmt, (wchar_t *)cpSqlStmt.c_str(), SQL_NTS);
		CheckError("执行sql语句失败,不能执行", retcode, SQL_HANDLE_STMT, hstmt);
	}
	return 0;
}


void ODBCDB::DisConnect()
{
	if(hstmt != NULL)
	{
		SQLFreeHandle(SQL_HANDLE_STMT, hstmt);
		hstmt = NULL;
	}

	if(hdbc != NULL)
	{
		SQLDisconnect(hdbc);
		SQLFreeHandle(SQL_HANDLE_DBC, hdbc);
		hdbc = NULL;
	}
	
	if(henv != NULL)
	{
		SQLFreeHandle(SQL_HANDLE_ENV, henv);
		henv = NULL;
	}

	return;
}

void ODBCDB::IsOpen()
{
	if(henv == NULL)
	{
		return;
	}

	if(hdbc == NULL)
	{
		return;
	}

	return;
}
