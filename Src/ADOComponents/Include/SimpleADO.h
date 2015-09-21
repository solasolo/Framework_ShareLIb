#pragma once

#include <string>

#include "msado15.h"

using namespace std;
using namespace ADO;

namespace GLEO
{
	class _declspec(dllexport) SimpleADO
	{
		static _ConnectionPtr CreateConnection();

	public:
		SimpleADO();
		~SimpleADO();

	protected:
		wstring ConnectionString;

		void Open();
		void Close();

		virtual wstring GetConnectionString() = 0;
		_CommandPtr GetCommand();
		void AddParameter(_bstr_t name, DataTypeEnum dbType, int len, _variant_t value, _CommandPtr cmd);

		int DoExec(_CommandPtr cmd);
		_RecordsetPtr DoQuery(_CommandPtr cmd);

	private:
		string LastSQL;
		_ConnectionPtr Conn;
	};
}