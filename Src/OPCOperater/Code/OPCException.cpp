#include "stdafx.h"

#include "OPCException.h"
#include "WinException.h"

OPCException::MassageMap OPCException::MessageDict[] =
{
	{OPC_E_INVALIDHANDLE, "The value of the handle is invalid."},
	{OPC_E_BADTYPE, "The server cannot convert the data between the specified format and/or requested data type and the canonical data type."},
	{OPC_E_PUBLIC, "The requested operation cannot be done on a public group."},
	{OPC_E_BADRIGHTS, "The item's access rights do not allow the operation."},
	{OPC_E_UNKNOWNITEMID, "The item ID is not defined in the server address space or no longer exists in the server address space."},
	{OPC_E_INVALIDITEMID, "The item ID does not conform to the server's syntax."},
	{OPC_E_INVALIDFILTER, "The filter string was not valid."},
	{OPC_E_UNKNOWNPATH, "The item's access path is not known to the server."},
	{OPC_E_RANGE, "The value was out of range."},
	{OPC_E_DUPLICATENAME, "Duplicate name not allowed."},
	{OPC_S_UNSUPPORTEDRATE, "The server does not support the requested data rate but will use the closest available rate."},
	{OPC_S_CLAMP, "A value passed to write was accepted but the output was clamped."},
	{OPC_S_INUSE, "The operation cannot be performed because the object is bering referenced."},
	{OPC_E_NOTFOUND, "The requested object (e.g. a public group) was not found."},
	{OPC_E_INVALIDCONFIGFILE, "The server's configuration file is an invalid format."},
	{OPC_E_INVALID_PID, "The specified property ID is not valid for the item."},
	{OPC_E_DEADBANDNOTSET, "The item deadband has not been set for this item."},
	{OPC_E_DEADBANDNOTSUPPORTED, "The item does not support deadband."},
	{OPC_E_NOBUFFERING, "The server does not support buffering of data items that are collected at a faster rate than the group update rate."},
	{OPC_E_INVALIDCONTINUATIONPOINT, "The continuation point is not valid."},
	{OPC_S_DATAQUEUEOVERFLOW, "Not every detected change has been returned since the server's buffer reached its limit and had to purge out the oldest data."},
	{OPC_E_RATENOTSET, "There is no sampling rate set for the specified item."},
	{OPC_E_NOTSUPPORTED, "The server does not support writing of quality and/or timestamp."},
	{0, ""}
};

void OPCException::Check(HRESULT hr, string place)
{
	HRESULT HitCode = 0;
	string Message = "";

	if(hr != S_OK)
	{
		for(int index = 0; (HitCode = MessageDict[index].Code) != 0; index++)
		{
			if(hr == HitCode)
			{
				HitCode = hr;
				Message = MessageDict[index].Message;

				throw OPCException(Message, place, hr);
			}
		}
		
		if(HitCode == 0)
		{
			throw Win32Lib::WinException(hr, place);		
		}
	}
}

OPCException::	OPCException(string msg, string place, int code)
	: Exception(msg, place, code)
{

}
