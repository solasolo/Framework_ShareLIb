#include "XMLException.h"

namespace Win32Lib
{
	XMLParseException::XMLParseException(TString place, MSXML2::IXMLDOMDocumentPtr doc)
	{
		if(doc)
		{
			MSXML2::IXMLDOMParseErrorPtr err = doc->parseError;
		
			Code = err->errorCode;
			Message = err->reason;
			Where = place;
		}
	}
}