// ConfigTest.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "XMLConfig.h"
#include "config.h"


using namespace GLEO;
using namespace Win32Lib;

int _tmain(int argc, _TCHAR* argv[])
{
	XMLConfig c(L"F:\\My Works\\Ungerer L2\\Data\\BaoSteel\\L2Server.config");

	map<string, string>& i = c.getItems();
	map<string, string>::iterator it = i.begin();
	while(it != i.end())
	{
		cout << it->first << ":" << it->second << endl;
		it++;
	}

	BaseConfig& b = c;

	cout << b.getString("XCOM.RemoteIP") << endl;
	cout << b.getString("XCOM.RemotePort") << endl;

	cin.get();

	return 0;
}

