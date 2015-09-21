#ifndef XMLEXCEPTION_H
#define XMLEXCEPTION_H

#include <Windows.h>

#include <exception>
#include <string>

#include "BaseException.h"
#include "msxml3.h"

using namespace std;
using namespace GLEO;
using namespace MSXML2;

namespace Win32Lib
{
	class _declspec(dllexport) XMLParseException : public GLEO::Exception
	{
	public:
		XMLParseException(TString place, MSXML2::IXMLDOMDocumentPtr doc);	
	};
}

#endif