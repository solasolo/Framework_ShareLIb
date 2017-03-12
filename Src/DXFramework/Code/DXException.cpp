#include "stdafx.h"

#include "DXException.h"
//#include <DxErr.h>

namespace GLEO
{
	DXException::DXException(string place)
		: WinException(place)
	{
	}

	DXException::DXException(wstring place)
		: WinException(place)
	{
	}

	DXException::DXException(int code, string place)
		: WinException(code, place)
	{
		//DXTrace(place.c_str(), 0, code, L"", true); 
	}

	DXException::DXException(int code, wstring place)
		: WinException(code, place)
	{
		//DXTrace((~place).c_str(), 0, code, L"", true); 
	}

	void DXException::Check(HRESULT hr, string place)
	{
		if(hr != 0) throw DXException(hr, place);
	}

	void DXException::Check(HRESULT hr, wstring place)
	{
		if(hr != 0) throw DXException(hr, place);
	}
}