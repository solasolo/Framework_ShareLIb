#pragma once

#include "WinException.h"

using namespace GLEO;
using namespace Win32Lib;

namespace GLEO
{
	class __declspec(dllexport) DXException : public WinException
	{
	public:
		DXException(string place);
		DXException(wstring place);
		DXException(int code, string place);
		DXException(int code, wstring place);

		static void Check(HRESULT hr, string place);
		static void Check(HRESULT hr, wstring place);

	protected:
		virtual wstring GetErrorDescription();
	};
}
