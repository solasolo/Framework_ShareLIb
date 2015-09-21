#include "Registry.h"

#include "WinException.h"

using namespace Win32Lib;

Registry::Registry(HKEY key)
{
	this->CurrentKey = this->RootKey = key;
}

void Registry::OpenKey(wstring key)
{
	LONG rs;

	rs = RegOpenKeyEx(this->RootKey, key.c_str(), NULL, KEY_WRITE | KEY_READ, &this->CurrentKey);
	WinException::Check(rs, L"Open Registry");
}

bool Registry::ValueExists(wstring key)
{
	bool Result = false;
	DWORD Size = 65535;
	DWORD Type;

	long rs = RegQueryValueEx(this->CurrentKey, key.c_str(), NULL, &Type, NULL, &Size);
	Result = (rs == ERROR_SUCCESS); 

	return Result;
}

wstring Registry::ReadString(wstring key)
{
	wstring Result = L"";

	long rs;

	DWORD Type = REG_SZ;
	DWORD Size = 65535;

	rs = RegQueryValueEx(this->CurrentKey, key.c_str(), NULL, &Type, NULL, &Size);
	WinException::Check(rs, L"Registry Check String");

	if( Size > 0 && (Type == REG_SZ || Type == REG_MULTI_SZ || Type == REG_EXPAND_SZ) )
	{
		wchar_t* buf = new wchar_t[ Size / 2 + 1];

		rs = RegQueryValueEx(this->CurrentKey, key.c_str(), NULL, &Type, (LPBYTE)buf, &Size);
		if(rs == ERROR_SUCCESS)
		{
			Result = buf;
			delete buf;
		}
		else
		{
			delete buf;
			WinException::Check(rs, L"Registry Read String");
		}
	}

	return Result;
}

void Registry::WriteString(wstring key, wstring value)
{
	LONG rs;

	rs = RegSetValueEx(this->CurrentKey, key.c_str(), NULL, REG_SZ, (LPBYTE)value.c_str(), value.size() * 2 + 2);
	WinException::Check(rs, L"Registry Write String");
}

int Registry::ReadInteger(wstring key)
{
	int Result;
	long rs;

	DWORD Type = REG_DWORD;
	DWORD Size = sizeof(Result);

	rs = RegQueryValueEx(this->CurrentKey, key.c_str(), NULL, &Type, NULL, &Size);
	WinException::Check(rs, L"Registry Check Integer");

	if( Size > 0 && (Type == REG_DWORD) )
	{
		rs = RegQueryValueEx(this->CurrentKey, key.c_str(), NULL, &Type, (LPBYTE)&Result, &Size);
		WinException::Check(rs, L"Registry Write Integer");
	}

	return Result;
}

void Registry::WriteInteger(wstring key, int value)
{
	LONG rs;

	rs = RegSetValueEx(this->CurrentKey, key.c_str(), NULL, REG_DWORD, (LPBYTE)&value, sizeof(DWORD));
	WinException::Check(rs, L"Registry Write Integer");
}
