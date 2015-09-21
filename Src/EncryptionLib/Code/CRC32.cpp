#include "stdafx.h"
#include "CRC32.h"

namespace GLEO 
{
	CRC16::CRC16()
		: CRCRev(0xa001)
	{
	}


	CRC32::CRC32()
		: CRCRev(0x4c11db7)
	{
	}
}
