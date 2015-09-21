//#include "stdafx.h"

#include "SmartADODB.h"

#include "CommonFuncs.h"
#include "WinException.h"
#include "WinEventLogger.h"

#include <stdlib.h>

using namespace Win32Lib;

SimpleADODB::SimpleADODB(wstring con_str)
{
	ConnectionString = con_str;
	Conn = NULL;

	try
	{
		Open();
	}
	catch(...)
	{
		
	}
}

SimpleADODB::~SimpleADODB(void)
{
	Close();
	Conn = NULL;
}

void SimpleADODB::CreateConnection()
{
	Conn = NULL;

	HRESULT hr = Conn.CreateInstance(__uuidof(Connection));
	WinException::COMCheck(hr, "Create ADO Connection");
	
	Conn->ConnectionString = ConnectionString.c_str();
}

void SimpleADODB::Open()
{
	// Close();

	if(Conn == NULL)
	{
		CreateConnection();
	}
	
	if(Conn != NULL)
	{
		if( (Conn->State & adStateOpen) != adStateOpen ) 
		{
			try
			{  
				Conn->Open(Conn->ConnectionString, "", "", adConnectUnspecified);
			}
			catch(_com_error& ex)
			{
				Conn = NULL;
				throw Exception(ex.Description(), "Open DB Connection", ex.Error());
			}
		}
	}
	else
	{
		throw Exception("Connection Object NOT Created", "Open DB Connection");
	}
}

void SimpleADODB::Close()
{
	if(Conn) 
	{
		if( Conn->State != adStateClosed )
		{
			try
			{
				Conn->Close();
			}
			catch(_com_error& ex)
			{
				throw Exception(ex.Description(), "Close DB Connection", ex.Error());
			}
		}
	}
}

variant_t SimpleADODB::Read(_RecordsetPtr& ds, wchar_t* field)
{
	return ds->Fields->Item[field]->Value;
}

bool SimpleADODB::First(_RecordsetPtr& ds)
{
	bool Result = false;

	if( !(ds->adoEOF && ds->BOF) )
	{
		ds->MoveFirst();

		Result = !(ds->adoEOF);
	}

	return Result;
}

int SimpleADODB::Exec()
{
	variant_t Rows;

	Open();
	
	try
	{
		Conn->Execute(LastSQL.c_str(), &Rows, adCmdText | adExecuteNoRecords);
	}
	catch(_com_error&)
	{
		//Close();

		Conn = NULL;
		DoCallBack(LastSQL, etRecord);
		throw;
	}catch(...)
	{
		throw;
	}

	return (long)Rows;
}

_RecordsetPtr SimpleADODB::Query()
{
	variant_t Rows;
	_RecordsetPtr Rs;
	
	Open();

	HRESULT hr = Rs.CreateInstance(__uuidof(Recordset));
	WinException::COMCheck(hr, "Create ADO Recordset");

	Rs->CursorLocation = adUseClient;

	variant_t TheCommand(LastSQL.c_str());

	IUnknown* inf = (IUnknown*)Conn;
	if(!inf) throw WinException("Extract Interface from Connection");

	variant_t TheConnection(inf, true);

	try
	{
		Rs->Open(TheCommand, TheConnection, adOpenStatic, adLockReadOnly, adCmdText);
//		Rs = Conn->Execute(LastSQL.c_str(), &Rows, adCmdText);
	}
	catch(_com_error& ex)
	{
		Close();
		DoCallBack(LastSQL, etRecord);
		throw;
	}

	return Rs;//SmartADOData(new ADOData(Rs));
}

_RecordsetPtr SimpleADODB::DoQuery(wstring sql)
{
	LastSQL = sql;
	return Query();
}

int SimpleADODB::DoNonQuery(string sql)
{
	return this->DoNonQuery(~sql);
}

int SimpleADODB::DoNonQuery(wstring sql)
{
	LastSQL = sql;
	return Exec();
}

wstring& SimpleADODB::getLastSQL()
{
	return LastSQL;
}

//----------------------------------------------------------------------------
ADODB::ADODB(wstring con_str, SmartPointer<SQLBuilder> builder) 
	: SimpleADODB(con_str)
{
	this->DBType = builder->getType();
	SchemeBuilder = builder;
}

ADODB::ADODB(wstring con_str, DbType dbtype, wstring scheme_path) 
	: SimpleADODB(con_str)
{
	this->DBType = dbtype;
	SchemeBuilder = new SQLBuilder(dbtype, scheme_path);
}

ADODB::~ADODB(void)
{
}

bool ADODB::Exist(string table_name, string field_name, variant_t value)
{
	bool IsEmpty = false;
	CommonData2 cond;
	cond.setData(field_name, value);
	LastSQL = SchemeBuilder->MakeNullSelect(table_name, cond);

	CommonDataList list = getResultSet(Query());

	return !list.IsEmpty();
}

bool ADODB::Exist(wstring sql)
{
	_RecordsetPtr ds = this->DoQuery(sql);

	bool ret = !(ds->adoEOF && ds->BOF);

	return ret;
}

CommonDataList ADODB::Select(string table_name)
{
	CommonData2 cond;

	wstring sql = SchemeBuilder->MakeSelect(table_name, cond);

	return SelectBySql(sql);
}

CommonDataList ADODB::Select(string table_name, string condition)
{
	CommonData2 dump;

	wstring sql = SchemeBuilder->MakeSelect(table_name, dump);
	sql = sql + L" where " + ~condition;

	return SelectBySql(sql);
}

CommonDataList ADODB::Select(string table_name, string field_name, variant_t value)
{
	CommonData2 cond;
	cond.setData(field_name, value);

	wstring sql = SchemeBuilder->MakeSelect(table_name, cond);

	return SelectBySql(sql);
}

CommonDataList ADODB::Select(string table_name,CommonData2& cond)
{
	wstring sql = SchemeBuilder->MakeSelect(table_name, cond);

	return SelectBySql(sql);
}

CommonDataList ADODB::SelectBySql(wstring Sql)
{
	LastSQL = Sql;

	return getResultSet(Query());
}


CommonData2 ADODB::SelectTop(string table_name)
{
	CommonData2 cond;

	wstring sql = SchemeBuilder->MakeSelect(table_name, cond);

	return SelectTopBySql(sql);
}

CommonData2 ADODB::SelectTop(string table_name, string condition)
{
	CommonData2 dump;

	wstring sql = SchemeBuilder->MakeSelect(table_name, dump);
	sql = sql + L" where " + ~condition;

	return SelectTopBySql(sql);
}

CommonData2 ADODB::SelectTop(string table_name, string field_name, variant_t value)
{
	CommonData2 cond;
	cond.setData(field_name, value);

	wstring sql = SchemeBuilder->MakeSelect(table_name, cond);

	return SelectTopBySql(sql);
}

CommonData2 ADODB::SelectTop(string table_name,CommonData2& cond)
{
	wstring sql = SchemeBuilder->MakeSelect(table_name, cond);

	return SelectTopBySql(sql);
}

CommonData2 ADODB::SelectTopBySql(wstring Sql)
{
	CommonData2 Result;

	LastSQL = Sql;

	CommonDataList& ret = getResultSet(Query());

	if(ret.NextRow())
	{
		Result = ret.Get();
	}

	return Result;
}

vector<CommonData2> ADODB::Select_v(string table_name)
{
	CommonData2 cond;

	LastSQL = SchemeBuilder->MakeSelect(table_name, cond);

	return getResult_v(Query());
}

vector<CommonData2> ADODB::Select_v(string table_name, string condition)
{
	CommonData2 dump;

	LastSQL = SchemeBuilder->MakeSelect(table_name, dump);
	LastSQL = LastSQL + L" where " + ~condition;

	return getResult_v(Query());
}

vector<CommonData2> ADODB::Select_v(string table_name, string field_name, variant_t value)
{
	CommonData2 cond;
	cond.setData(field_name, value);

	LastSQL = SchemeBuilder->MakeSelect(table_name, cond);

	return getResult_v(Query());
}

vector<CommonData2> ADODB::Select_v(string table_name, CommonData2& cond)
{
	LastSQL = SchemeBuilder->MakeSelect(table_name, cond);

	return getResult_v(Query());
}

vector<CommonData2> ADODB::SelectBySql_v(wstring Sql)
{
	LastSQL = Sql;

	return getResult_v(Query());
}

int ADODB::Update(string table_name, CommonData2& data, string field_name, variant_t value)
{
	CommonData2 Cond;
	Cond.setData(field_name, value);
	LastSQL = SchemeBuilder->MakeUpdate(table_name, data, Cond);

	return Exec();
}

int ADODB::Update(string table_name, CommonData2& data, CommonData2& cond)
{
	LastSQL = SchemeBuilder->MakeUpdate(table_name, data, cond);

	return Exec();
}

int ADODB::Insert(string table_name, CommonData2& data)
{
	LastSQL = SchemeBuilder->MakeInsert(table_name, data);

	return Exec();
}

int ADODB::Add(string table_name, string key_field, CommonData2& data)
{
	int Result = 0;

	vector<string> fields;
	split(fields, key_field, ';');

	CommonData2 cond;
	for(vector<string>::iterator it = fields.begin(); it != fields.end(); it++)
	{
		cond.setData(*it, data.getData(*it));
	}

	if(!Update(table_name, data, cond))
	{		
		Result = Insert(table_name, data);
	}

	return Result;
}

int ADODB::Delete(string table_name, CommonData2& data)
{
	LastSQL = SchemeBuilder->MakeDelete(table_name, data);

	return Exec();
}

int ADODB::Delete(string table_name, string field_name, variant_t value)
{ 
	CommonData2 Cond;
	Cond.setData(field_name, value);
	LastSQL = SchemeBuilder->MakeDelete(table_name, Cond);

	return Exec();
}

CommonDataList ADODB::getResultSet(_RecordsetPtr m_RecordSet)
{
	CommonDataList List;

	if( !(m_RecordSet->adoEOF && m_RecordSet->BOF) )
	{
		m_RecordSet->MoveFirst();
		while(!m_RecordSet->adoEOF)
		{
			List.NewRow();
			
			FieldsPtr all = m_RecordSet->Fields;
			for(long i = 0; i < all->GetCount(); i++)
			{
				_bstr_t  Name = all->Item[i]->Name;
				 char* name  = Name;
				variant_t Value = all->Item[i]->Value;
				List.setData(name, Value);
			}

			m_RecordSet->MoveNext();
		}
	}

	List.ResetRow();

	return List;
}

vector<CommonData2> ADODB::getResult_v(_RecordsetPtr m_RecordSet)
{
	vector<CommonData2>  DV;

	if( !(m_RecordSet->adoEOF && m_RecordSet->BOF) )
	{
		m_RecordSet->MoveFirst();
		while(!m_RecordSet->adoEOF)
		{
			CommonData2* comdata = new CommonData2();
			
			FieldsPtr all = m_RecordSet->Fields;
			for(long i = 0; i < all->GetCount(); i++)
			{
				_bstr_t  Name = all->Item[i]->Name;
				 char* name  = Name;
				variant_t Value = all->Item[i]->Value;
				comdata->setData(name, Value);
			}
			DV.push_back(*comdata);

			m_RecordSet->MoveNext();
		}
	}

	return DV;
}