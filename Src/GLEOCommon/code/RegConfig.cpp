#include "RegConfig.h"
#include "CommonFuncs.h"
#include "WinException.h"

using namespace GLEO;

namespace Win32Lib
{
	RegConfig::RegConfig(wstring path)
	{
		KeyPath = path;
	}

	variant_t RegConfig::getValue(string name)
	{
		wstring ValueName;
		wstring PathName;
		int pos;

		pos = name.rfind('.');
		if(pos == string::npos)
		{
			PathName = KeyPath;
			ValueName = ~name;
		}
		else
		{
			ValueName = ~name.substr(pos + 1);
			name.erase(pos);

			pos = 0;
			while(pos != string::npos)
			{
				pos = name.find(pos, '.');
				if(pos != string::npos)
				{
					name[pos] = '\\';
					pos++;
				}
			}

			PathName = KeyPath + L"\\" + ~name;
		}

		return ReadKeyValue(PathName, ValueName);
	}

	variant_t RegConfig::ReadKeyValue(wstring key_path, wstring value_name)
	{
		LONG rt;
		HKEY Key;
		DWORD ValueLen;
		
		wstring FullPath = wstring(L"SOFTWARE\\") + key_path;

		rt = RegOpenKeyEx(HKEY_LOCAL_MACHINE, FullPath.c_str(), 0, KEY_READ, &Key);
		if(rt != ERROR_SUCCESS)	throw WinException(rt, _T("Open Regstry Key"));

		char ValueBuffer[100];
		DWORD ValueType;
 
		rt = RegQueryValueEx(Key, value_name.c_str(), NULL, &ValueType, (LPBYTE)ValueBuffer, &ValueLen);
		if(rt != ERROR_SUCCESS) throw WinException(rt, _T("Get Regstry Value"));

		variant_t Value;
		Value.Clear();
		switch(ValueType)
		{
		case REG_SZ:
			Value = (wchar_t*)ValueBuffer;
			break;

		case REG_DWORD:
			Value = *((long*)ValueBuffer);
			break;
		}

		return Value;
	}

	wstring RegConfig::getWString(string name)
	{
		variant_t value = getValue(name);
		return ~ToString(value);
	}

	string RegConfig::getString(string name)
	{
		variant_t value = getValue(name);
		return ToString(value);
	}

	int RegConfig::getInt(string name)
	{
		variant_t value = getValue(name);
		return ToLong(value);
	}
}
