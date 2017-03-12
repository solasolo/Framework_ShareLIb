#include <Windows.h>

#include "WinException.h"
#include "CommonFuncs.h"

namespace Win32Lib
{
	SException::SException(unsigned int Code, EXCEPTION_POINTERS* se)
	{
		void* ExecuteAddress = se->ExceptionRecord->ExceptionAddress;
		void* DataAddress = NULL;

		Code = se->ExceptionRecord->ExceptionCode;
		wstring TypeString;

		switch(Code)
		{
		case EXCEPTION_ACCESS_VIOLATION:
			TypeString = L"EXCEPTION_ACCESS_VIOLATION";
			DataAddress = (void*)se->ExceptionRecord->ExceptionInformation[1];
			break;

		case EXCEPTION_DATATYPE_MISALIGNMENT:     
			TypeString = L"EXCEPTION_DATATYPE_MISALIGNMENT";
			break;

		case EXCEPTION_BREAKPOINT:                
			TypeString = L"EXCEPTION_BREAKPOINT";
			break;

		case EXCEPTION_SINGLE_STEP:               
			TypeString = L"EXCEPTION_SINGLE_STEP";
			break;

		case EXCEPTION_ARRAY_BOUNDS_EXCEEDED:     
			TypeString = L"EXCEPTION_ARRAY_BOUNDS_EXCEEDED";
			break;

		case EXCEPTION_FLT_DENORMAL_OPERAND:      
			TypeString = L"EXCEPTION_FLT_DENORMAL_OPERAND";
			break;

		case EXCEPTION_FLT_DIVIDE_BY_ZERO:        
			TypeString = L"EXCEPTION_FLT_DIVIDE_BY_ZERO";
			break;

		case EXCEPTION_FLT_INEXACT_RESULT:       
			TypeString = L"EXCEPTION_FLT_INEXACT_RESULT";
			break;

		case EXCEPTION_FLT_INVALID_OPERATION:     
			TypeString = L"EXCEPTION_FLT_INVALID_OPERATION";
			break;

		case EXCEPTION_FLT_OVERFLOW:              
			TypeString = L"EXCEPTION_FLT_OVERFLOW";
			break;

		case EXCEPTION_FLT_STACK_CHECK:           
			TypeString = L"EXCEPTION_FLT_STACK_CHECK";
			break;

		case EXCEPTION_FLT_UNDERFLOW:             
			TypeString = L"EXCEPTION_FLT_UNDERFLOW";
			break;

		case EXCEPTION_INT_DIVIDE_BY_ZERO:        
			TypeString = L"EXCEPTION_INT_DIVIDE_BY_ZERO";
			break;

		case EXCEPTION_INT_OVERFLOW:              
			TypeString = L"EXCEPTION_INT_OVERFLOW";
			break;

		case EXCEPTION_PRIV_INSTRUCTION:          
			TypeString = L"EXCEPTION_PRIV_INSTRUCTION";
			break;

		case EXCEPTION_IN_PAGE_ERROR:             
			TypeString = L"EXCEPTION_IN_PAGE_ERROR";
			break;

		case EXCEPTION_ILLEGAL_INSTRUCTION:       
			TypeString = L"EXCEPTION_ILLEGAL_INSTRUCTION";
			break;

		case EXCEPTION_NONCONTINUABLE_EXCEPTION:  
			TypeString = L"EXCEPTION_NONCONTINUABLE_EXCEPTION";
			break;

		case EXCEPTION_STACK_OVERFLOW:            
			TypeString = L"EXCEPTION_STACK_OVERFLOW";
			break;

		case EXCEPTION_INVALID_DISPOSITION:       
			TypeString = L"EXCEPTION_INVALID_DISPOSITION";
			break;

		case EXCEPTION_GUARD_PAGE:                
			TypeString = L"EXCEPTION_GUARD_PAGE";
			break;

		case EXCEPTION_INVALID_HANDLE:            
			TypeString = L"EXCEPTION_INVALID_HANDLE";
			break;

		case CONTROL_C_EXIT:                      
			TypeString = L"CONTROL_C_EXIT";
			break;

		default:
			TypeString = L"EXCEPTION_UNKNOWN";
		}

		wchar_t buf[100];
		buf[99] = L'\x0';

		if(DataAddress)
		{
			swprintf_s(buf, 99, L"%S @ 0x%p R/W: 0x%p", TypeString.c_str(), ExecuteAddress, DataAddress);
		}
		else
		{
			swprintf_s(buf, 99, L"%S @ 0x%p", TypeString.c_str(), ExecuteAddress);
		}
		
		Message = buf;
	}

	void SException::SEHandle(unsigned int Code, EXCEPTION_POINTERS* SE)
	{
		throw SException(Code, SE);
	}

	void SException::Install()
	{
#ifndef __BORLANDC__
		_set_se_translator(SException::SEHandle);
#endif
	}
}


namespace Win32Lib
{
	WinException::WinException(wstring place)
	{
		Where = place;
		SetErrorCode(GetLastError());
	}

	WinException::WinException(string place)
	{
		Where = ~place;
		SetErrorCode(GetLastError());
	}

	WinException::WinException(int code, wstring place)
	{
		Where = place;
		SetErrorCode(code);
	}

	WinException::WinException(int code, string place)
	{
		Where = ~place;
		SetErrorCode(code);
	}

	WinException::WinException(const WinException& ex) throw()
		: Exception(ex)
	{
	}

	WinException& WinException::operator =(const WinException& ex) throw()
	{
		this->Code = ex.Code;
		this->Where = ex.Where;
		this->Message = ex.Message;

		return *this;
	}

	void WinException::SetErrorCode(int code)
	{
		this->Code = code;
		this->Message = this->GetErrorDescription();
	}

	wstring WinException::GetErrorDescription()
	{
		wstring ErrString;
		LPVOID lpMsgBuf = NULL;

		FormatMessageW(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS, NULL, Code, MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), (LPTSTR)&lpMsgBuf, 0, NULL);

		if(lpMsgBuf) 
		{
			ErrString = (wchar_t*)lpMsgBuf;
			LocalFree( lpMsgBuf );
		}
		else
		{
			ErrString = _T("No Error Description!");
		}

		return ErrString;
	}

	void WinException::Check(string place)
	{
		WinException::Check(~place);
	}

	void WinException::Check(wstring place)
	{
		DWORD ECode;

		ECode = GetLastError();
		if(ECode != 0)
		{
			throw WinException(ECode, place);
		}
	}

	void WinException::Check(DWORD hr, string place)
	{
		WinException::Check(hr, ~place);
	}

	void WinException::Check(DWORD hr, wstring place)
	{
		DWORD ECode;

		ECode = hr;
		if(ECode != 0)
		{
			throw WinException(ECode, place);
		}
	}

	void WinException::COMCheck(HRESULT hr, wstring place)
	{
		if(hr < 0)
		{
			throw WinException(hr, place);
		}
	}

	void WinException::COMCheck(HRESULT hr, string place)
	{
		WinException::COMCheck(hr, ~place);
	}
}

