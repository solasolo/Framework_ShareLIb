#pragma once

#ifndef VARIANT_H
#define VARIANT_H

#include <windows.h>


class __declspec(dllexport) VariantArray
{
private:
	SAFEARRAY* Handle;
	bool IsOwner;

	VariantArray();

public:
	static VariantArray& Create(VARTYPE  vt, unsigned int dims, int bounds[]);

	VariantArray(variant_t& var);
	~VariantArray();

	void PutElement(variant_t var, long dim, ...);
	variant_t GetElement(long dim, ...);
	
	long LowBound(long dim);
	long UpperBound(long dim);
	
	operator variant_t();
	operator bool();
};

#endif