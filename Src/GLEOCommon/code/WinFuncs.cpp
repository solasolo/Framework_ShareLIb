#include "WinFuncs.h"

#include <comutil.h>
#include <windows.h>
#include <shellapi.h>

#include "CommonFuncs.h"
#include "WinException.h"

using namespace GLEO;

namespace Win32Lib
{
	wstring GetStartupPath()
	{
		return ExtractFilePath(GetCurrentExecPath()) + L"\\";
	}

	wstring GetCurrentExecPath()
	{
		static wchar_t ExecPath[512];

		if(!GetModuleFileName(NULL, ExecPath, 512))
		{
			throw WinException(L"Get Startup Path");
		}

		return ExecPath;
	}

	wstring GetWindowsFolder()
	{
		static wchar_t WindowPath[512];

		if(!GetSystemDirectory(WindowPath, 512))
		{
			throw WinException(L"Get Windows Path");
		}

		return WindowPath;
	}

	HWND CreateHiddenWindow()
	{
		wstring Name = L"_Hidden_";

		HWND WinHandle;
		MSG msg;
		WNDCLASSEX winclass;

		winclass.cbSize = sizeof(WNDCLASSEX);
		winclass.cbClsExtra= 0;
		winclass.cbWndExtra = 0;
		winclass.lpfnWndProc = HiddenWinProc;
		winclass.style = CS_VREDRAW | CS_HREDRAW | CS_OWNDC | CS_DBLCLKS;
		winclass.hInstance = NULL;
		winclass.hCursor = LoadCursor(NULL, IDC_ARROW);
		winclass.hIcon = LoadIcon(NULL, IDI_APPLICATION); 
		winclass.hIconSm = LoadIcon(NULL, IDI_APPLICATION);
		winclass.lpszMenuName = NULL;
		winclass.hbrBackground =(HBRUSH) GetStockObject(BLACK_BRUSH);
		winclass.lpszClassName = Name.c_str();

		if(RegisterClassEx(&winclass))
		{
			WinHandle = CreateWindowEx(NULL, Name.c_str(), Name.c_str(), WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, 0, 0, 0, NULL, NULL, NULL, NULL);
			if(WinHandle == INVALID_HANDLE_VALUE)
			{
				throw WinException("Create Hiden Window");
			}
		}
		else
		{
			throw WinException("Register Hidden Window");
		}

		return WinHandle;
	}

	LRESULT CALLBACK HiddenWinProc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam)
	{
		return DefWindowProc(hwnd, msg, wparam, lparam);
	}
}