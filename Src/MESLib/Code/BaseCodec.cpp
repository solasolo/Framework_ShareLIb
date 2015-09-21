#include "BaseCodec.h"

string& BaseXCOMCodec::getSendHeartID()
{
	return this->SendHeartID;
}

string& BaseXCOMCodec::getRecvHeartID()
{
	return this->RecvHeartID;
}

wstring& BaseXCOMCodec::getError()
{
	return this->ParserError;
}
