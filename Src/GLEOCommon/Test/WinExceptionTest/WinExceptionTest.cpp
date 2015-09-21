// WinExceptionTest.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>

#include "WinException.h"

using namespace Win32Lib;
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	try
	{
		WinException::COMCheck(-1, "com exception test");
	}
	catch(WinException& ex)
	{
		wcout << ex.GetDescription();
	}
	
	return 0;
}

