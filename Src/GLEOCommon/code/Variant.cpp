#include <comdef.h>
#include "Variant.h"
#include "CommonFuncs.h"
#include "WinException.h"

#include <stdlib.h>

using namespace Win32Lib;

VariantArray::VariantArray()
{
	this->Handle = NULL;
	this->IsOwner = true;
}

VariantArray::VariantArray(variant_t& var)
{
	this->Handle = var.parray;
	this->IsOwner = false;
}

VariantArray::~VariantArray()
{
	if(this->IsOwner) 
	{
		if(this->Handle)
		{
			SafeArrayDestroy(this->Handle);
		}
	}
}

VariantArray& VariantArray::Create(VARTYPE  vt, unsigned int dims, int bounds[])  
{
	VariantArray* me = new VariantArray();

	if(me)
	{
		SAFEARRAYBOUND* ArrayBounds;
		ArrayBounds = new SAFEARRAYBOUND[dims];

		if(ArrayBounds)
		{
			try
			{
				for(int i = 0; i < dims; i++)
				{
					ArrayBounds[i].lLbound = bounds[i * 2];
					ArrayBounds[i].cElements = bounds[i * 2 + 1];
				}

				me->Handle = SafeArrayCreate(vt, dims, ArrayBounds);
			}
			catch(...)
			{
				DESTROY(ArrayBounds); 
			}

			DESTROY(ArrayBounds); 
		}
	}
	else
	{
	}

	return *me;
}

void VariantArray::PutElement(variant_t var, long dim, ...)
{
	HRESULT rs;
	va_list argptr;
	va_start(argptr, dim);

	rs = SafeArrayPutElement(this->Handle, &va_arg(argptr, long), var.GetAddress());
	WinException::Check(rs, L"Put SafeArray Element");
}

variant_t VariantArray::GetElement(long dim, ...)
{
	HRESULT rs;
	variant_t Result;

	va_list argptr;
	va_start(argptr, dim);

	rs = SafeArrayGetElement(this->Handle, &va_arg(argptr, long), Result.GetAddress());
	WinException::Check(rs, L"Get SafeArray Element");

	return Result;
}

long VariantArray::LowBound(long dim)
{
	long Result;
	HRESULT rs;

	rs = SafeArrayGetLBound(this->Handle, dim, &Result);
	WinException::Check(rs, L"Get SafeArray Lower Bound");

	return Result;
}

long VariantArray::UpperBound(long dim)
{
	long Result;
	HRESULT rs;

	rs = SafeArrayGetUBound(this->Handle, dim, &Result);
	WinException::Check(rs, L"Get SafeArray Upper Bound");

	return Result;
}

VariantArray::operator bool()
{
	return (this->Handle);
}

VariantArray::operator variant_t()
{
	return variant_t(this->Handle);
}
