// LoggerServerTest.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "LoggerServer.h"

int _tmain(int argc, _TCHAR* argv[])
{
	try
	{
		LoggerServer* remotelog = new LoggerServer("127.0.0.1", 4444);
		while(1)
		{
			remotelog->Log(etDebug, "Test");
		}
	}catch(Exception& ex)
	{
		MessageBox(GetDesktopWindow(), ex.GetDescription().c_str(), L"Error", MB_OK);
	}
	getchar();
	return 0;
}

