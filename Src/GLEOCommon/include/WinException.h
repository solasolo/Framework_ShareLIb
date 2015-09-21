#ifndef WINEXCEPTION_H
#define WINEXCEPTION_H

#include "BaseException.h"

#include <Windows.h>

#include <exception>
#include <string>

using namespace std;
using namespace GLEO;

namespace Win32Lib
{
	class _declspec(dllexport) SException : public GLEO::Exception
	{
	private:
		SException(unsigned int Code, EXCEPTION_POINTERS* SE);

	public:	
		static void SEHandle(unsigned int Code, EXCEPTION_POINTERS* se);
		static void Install();

//		NEHandle(size_t c);
	};

	class _declspec(dllexport) WinException : public GLEO::Exception
	{
	public:
		static void Check(string place);
		static void Check(wstring place);
		static void Check(DWORD hr, string place);
		static void Check(DWORD hr, wstring place);
		static void COMCheck(HRESULT hr, string place);
		static void COMCheck(HRESULT hr, wstring place);

		WinException(string place);
		WinException(wstring place);
		WinException(int code, string place);
		WinException(int code, wstring place);
		WinException(const WinException& ex) throw();

		WinException& operator =(const WinException& ex) throw();

	protected:
		void SetErrorCode(int code);

		virtual wstring GetErrorDescription();
	};
}

#endif