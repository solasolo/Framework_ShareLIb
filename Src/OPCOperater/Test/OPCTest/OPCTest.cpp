// OPCTest.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "OPCOperater.h"
#include "WinException.h"

using namespace Win32Lib;

int _tmain(int argc, _TCHAR* argv[])
{
	CoInitialize(NULL);

	try
	{
		OPCOperater OPC(/*L"192.168.1.19"*/L"dev-srv", L"{F8582D2E-88FB-11D0-B850-00C0F0104305}");
	}
	catch(WinException& ex)
	{
		wprintf(L"%s", ex.GetDescription().c_str());
	}

	CoUninitialize();

	return 0;


}

