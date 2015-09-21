#ifndef BASEEXCEPTION_H
#define BASEEXCEPTION_H

#include <exception>
#include <string>

#include "CommonFuncs.h"

using namespace std;

namespace GLEO
{
	class _declspec(dllexport) Exception
	{
	protected:
		int Code;
		wstring Where;
		wstring Message;

		virtual wstring GetErrorDescription();

	public:
		Exception();
		Exception(const Exception& ex) throw();

		Exception(const char* msg, const char* place = "", int code = -1);
		Exception(const wchar_t* msg, const wchar_t* place = L"", int code = -1);
		Exception(wstring msg, wstring place, int code = -1);
		Exception(string msg, string place, int code = -1);

		Exception& operator =(const Exception& ex) throw();

		int why();
		const wstring what() throw();
		const wstring where();

		virtual wstring GetDescription() throw();
	};

	_declspec(dllexport) wstring FormatException(exception& ex);
	_declspec(dllexport) wstring FormatException(Exception& ex);

#ifndef __BORLANDC__
	_declspec(dllexport) wstring FormatException(_com_error& ex);
#endif

	_declspec(dllexport) wstring FormatException(wstring env, exception& ex);
	_declspec(dllexport) wstring FormatException(wstring env, Exception& ex);

#ifndef __BORLANDC__
	_declspec(dllexport) wstring FormatException(wstring env, _com_error& ex);
#endif
}

#endif