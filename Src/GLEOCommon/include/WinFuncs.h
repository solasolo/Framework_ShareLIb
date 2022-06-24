#ifndef WINFUNCS_H
#define WINFUNCS_H

#include "std_Unicode.h"
#include "SmartPointer.h"
#include "WinException.h"

#include <string>

using namespace std;
using namespace GLEO;

namespace Win32Lib
{
	__declspec(dllexport) wstring GetStartupPath();
	__declspec(dllexport) wstring GetCurrentExecPath();
	__declspec(dllexport) wstring GetWindowsFolder();

	__declspec(dllexport) HWND CreateHiddenWindow();
	__declspec(dllexport) LRESULT CALLBACK HiddenWinProc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam);

	template<class T>
	COMSmartPointer<T> CreateCOMObject(string& name, wstring& host);
}


namespace Win32Lib
{
	template<class T>
	COMSmartPointer<T> CreateCOMObject(string name, wstring host)
	{
		HRESULT hr;

		COSERVERINFO ServerInfo;
		ServerInfo.dwReserved1 = 0;
		ServerInfo.dwReserved2 = 0;
		ServerInfo.pAuthInfo = NULL;
		ServerInfo.pwszName = (wchar_t*)host.c_str();

		MULTI_QI qi;
		qi.hr = 0;
		qi.pIID = __uuidof(T);
		qi.pItf = NULL;

		CLSID ClassID;

		hr = CLSIDFromString((wchar_t*)name.c_str(), &ClassID);
		WinException::COMCheck(hr, L"");

		hr = CoCreateInstanceEx(ClassID, NULL, CLSCTX_REMOTE_SERVER, &ServerInfo, 1, &qi);
		WinException::COMCheck(hr, L"Create Remote COM Object");

		return COMSmartPointer<T>(qi.pItf);
	}

	template<class T>
	COMSmartPointer<T> CreateCOMObject(wstring name)
	{
		T* pResult = NULL;
		HRESULT hr;

		CLSID ClassID;

		hr= CLSIDFromString((wchar_t*)name.c_str(), &ClassID);
		WinException::COMCheck(hr, L"Get CLSID");

		hr = CoCreateInstance(ClassID, NULL, CLSCTX_INPROC_SERVER, __uuidof(T), (void**)&pResult);
		WinException::COMCheck(hr, L"Create COM Object");

		COMSmartPointer<T> Result;
		Result << pResult;

		return Result;
	}
}


#endif