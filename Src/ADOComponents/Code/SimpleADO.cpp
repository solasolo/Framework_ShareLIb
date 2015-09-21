#include "stdafx.h"

#include "SimpleADO.h"
#include "WinException.h"

using namespace Win32Lib;

namespace GLEO
{
	SimpleADO::SimpleADO()
	{
		this->Conn = NULL;
	}

	SimpleADO::~SimpleADO()
	{
		this->Conn = NULL;
	}

	_ConnectionPtr SimpleADO::CreateConnection()
	{
		_ConnectionPtr Result;

		HRESULT hr = Result.CreateInstance(__uuidof(Connection));
		WinException::COMCheck(hr, L"Create Connection");
	
		return Result;
	}

	void SimpleADO::Open()
	{
		if(!this->Conn)
		{
			this->Conn = CreateConnection();
		}

		if(this->Conn->State & adStateOpen == adStateOpen)
		{
			this->Conn->Close();
		}

		if(this->ConnectionString == L"")
		{
			this->ConnectionString = this->GetConnectionString();
		}

		this->Conn->Open(this->ConnectionString.c_str(), "", "", ConnectOptionEnum::adConnectUnspecified);
	}

	void SimpleADO::Close()
	{
	}

	_CommandPtr SimpleADO::GetCommand()
	{
		_CommandPtr cmd;

		HRESULT hr = cmd.CreateInstance(__uuidof(Command));
		WinException::COMCheck(hr, L"Create Connection");
		
		this->Open();	
		cmd->ActiveConnection = this->Conn;

		return cmd;
	}

	void SimpleADO::AddParameter(_bstr_t name, DataTypeEnum dbType, int len, _variant_t value, _CommandPtr cmd)
	{
		_ParameterPtr param = cmd->CreateParameter(name, dbType, ParameterDirectionEnum::adParamInput, len);
		param->Value = value;
		cmd->Parameters->Append(param);
	}

	int SimpleADO::DoExec(_CommandPtr cmd)
	{
		variant_t Rows;

		Open();
		
		try
		{
			this->Conn->Execute(LastSQL.c_str(), &Rows, adCmdText | adExecuteNoRecords);
		}
		catch(_com_error&)
		{
			Conn = NULL;
			throw;
		}
	
		return (long)Rows;
	}

	_RecordsetPtr SimpleADO::DoQuery(_CommandPtr cmd)
	{
		Open();
		
		_RecordsetPtr ds;
			
		try
		{
			ds = cmd->Execute(NULL, NULL, CommandTypeEnum::adCmdText);
		}
		catch(_com_error&)
		{
			Conn = NULL;
			throw;
		}

		return ds;
	}
}
