#include <comdef.h>

#include "CommonFuncs.h"
#include "BaseException.h"

namespace GLEO
{
	Exception::Exception()
	{
		Message = L"";
		Where = L"";
		Code = 0;
	}

	Exception::Exception(const Exception& ex) throw()
	{
		Message = ex.Message;
		Where = ex.Where;
		Code = ex.Code;
	}

	Exception::Exception(const wchar_t* msg, const wchar_t* place, int code)
	{
		Message = msg;
		Where = place;
		Code = code;
	}

	Exception::Exception(const char* msg, const char* place, int code)
	{
		string temp_str;

		temp_str = msg;
		Message = ~temp_str;
		temp_str = place;
		Where = ~temp_str;
		Code = code;
	}

	Exception::Exception(wstring msg, wstring place, int code)
	{
		Message = msg;
		Where = place;
		Code = code;
	}

	Exception::Exception(string msg, string place, int code)
	{
		Message = ~msg;
		Where = ~place;
		Code = code;
	}

	Exception& Exception::operator = (const Exception& ex) throw()
	{
		Code = ex.Code;
		Message = ex.Message;
		Where = ex.Where;

		return *this;
	}

	int Exception::why()
	{
		return Code;
	}

	const wstring Exception::where()
	{
		return Where;
	}

	const wstring Exception::what() throw()
	{
		return Message;
	}

	wstring Exception::GetErrorDescription()
	{
		return Message;	
	}

	wstring Exception::GetDescription() throw()
	{
		TString ErrDescription;

		ErrDescription = Where.empty() ?  GetErrorDescription() :  wstring(L"[") + Where + L"] " + GetErrorDescription();

		return ErrDescription;
	}
}

namespace GLEO
{
	wstring FormatException(exception& ex)
	{
		return ~(string(ex.what()));
	}

	wstring FormatException(Exception& ex)
	{
		return ex.GetDescription();
	}
	
#ifndef __BORLANDC__
	wstring FormatException(_com_error& ex)
	{
		wstring Result = ex.ErrorMessage();

		wchar_t* desc = ex.Description();
		if(desc)
		{
			Result = Result + L"(" + desc + L")";
		}

		return Result;
	}
#endif

	wstring FormatException(wstring env, exception& ex)
	{
		return wstring(L"[") + env + L"]" + ~(string(ex.what()));
	}

	wstring FormatException(wstring env, Exception& ex)
	{
		return wstring(L"[") + env + L"]" + ex.GetDescription();
	}

#ifndef __BORLANDC__
	wstring FormatException(wstring env, _com_error& ex)
	{
		wstring Result = wstring(L"[") + env + L"]" + ex.ErrorMessage();

		wchar_t* desc = ex.Description();
		if(desc)
		{
			Result = Result + L"(" + desc + L")";
		}

		return Result;
	}
#endif
}