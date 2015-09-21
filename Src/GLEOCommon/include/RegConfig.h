#ifndef REGCONFIG_H
#define REGCONFIG_H

#include "Config.h"

#include <comutil.h>

using namespace GLEO;

namespace Win32Lib
{
	class __declspec(dllexport) RegConfig : public BaseConfig
	{
	private:
		wstring KeyPath; 
		
		variant_t getValue(string name);
		variant_t ReadKeyValue(wstring key_path, wstring value_name);

	public:
		RegConfig(wstring path);

		wstring getWString(string name);
		string getString(string name);
		int getInt(string name);
	};
}

#endif