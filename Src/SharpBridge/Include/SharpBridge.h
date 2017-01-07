// ShareBridge.h

#pragma once

#include <string>

#include "CommonFuncs.h"

using namespace std;

using namespace ::System;
using namespace Runtime::InteropServices;

namespace GLEO {

	class TypeBridge
	{
	private:

	public:
		static void MarshalString(String^ s, wstring& os); 
		static String^ MarshalToString(wstring& os);
		static time_t MarshalToTime(DateTime t);
		static DateTime MarshalFromTime(time_t t);
		static double MarshalToDateTime(DateTime t);
		static DateTime MarshalFromDateTime(double t);
	};

	inline void TypeBridge::MarshalString(String^ s, wstring& os) 
	{
		const wchar_t* chars = (const wchar_t*)(Marshal::StringToHGlobalUni(s)).ToPointer();
		os.append(chars, s->Length);

		Marshal::FreeHGlobal(IntPtr((void*)chars));
	}

	inline String^ TypeBridge::MarshalToString(wstring& os) 
	{
		::System::IntPtr inptr((void *)os.c_str());
		String ^ s = Marshal::PtrToStringUni(inptr, os.size());

		return s;
	}

	inline time_t  TypeBridge::MarshalToTime(DateTime t)
	{
		DateTime BaseTime = DateTime(1970, 1, 1, 0, 0, 0);
		return (t - BaseTime).TotalSeconds;
	}

	inline DateTime TypeBridge::MarshalFromTime(time_t t)
	{
		DateTime BaseTime = DateTime(1970, 1, 1, 0, 0, 0);
		return BaseTime.AddSeconds(t);
	}
	
	inline double  TypeBridge::MarshalToDateTime(DateTime t)
	{
		DateTime BaseTime = DateTime(1900, 1, 1, 0, 0, 0);
		TimeSpan dif = t - BaseTime;
		long secs = dif.TotalSeconds;

		return double(secs) / DAY_SEC;
	}

	inline DateTime  TypeBridge::MarshalFromDateTime(double t)
	{
		DateTime BaseTime = DateTime(1900, 1, 1, 0, 0, 0);
		return BaseTime.AddSeconds(t * DAY_SEC);
	}
}
