#ifndef CONGIF_H
#define CONGIF_H

#pragma warning(disable:4786)

#include <string>
#include <map>

#include "std_unicode.h"

using namespace std;

namespace GLEO
{
	class BaseConfig
	{
	public:
		virtual string getString(string name) = 0;
		virtual wstring getWString(string name) = 0;
		virtual int getInt(string name) = 0;
	};
}

#endif