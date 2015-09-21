#ifndef COMMONFUNCS_H
#define COMMONFUNCS_H

#pragma warning(disable:4786)

#include <comutil.h>
#include <string>
#include <vector>
#include <algorithm>

#include "std_Unicode.h"

using namespace std;

typedef unsigned char byte;

#define DESTROY(obj)	\
	if(obj)             \
{						\
	delete obj;     	\
	obj = NULL;     	\
}

#define DESTROY_ARRAY(obj)		\
	if(obj)						\
{								\
	delete[] obj;           	\
	obj = NULL;             	\
}

__declspec(dllexport) bool operator < (GUID const& lhs, GUID const& rhs);

#define DllAPI extern  __declspec(dllexport)

namespace GLEO
{
	const int HOUR_SEC = 60 * 60;
	const int DAY_SEC = HOUR_SEC * 24;
	const double DB_DATETIME_SHIFT = 70.0 * 365.0 + 19.0;

	__declspec(dllexport) void ToLower(string &str);
	__declspec(dllexport) void ToUpper(string &str);

	__declspec(dllexport) bool IsEmpty(variant_t& var);
	__declspec(dllexport) bool IsNull(variant_t& var);

	__declspec(dllexport) long ToLong(variant_t& var);
	__declspec(dllexport) double ToFloat(variant_t& var);
	__declspec(dllexport) string ToString(variant_t& var);
	__declspec(dllexport) wstring ToWString(variant_t& var);
	__declspec(dllexport) time_t ToTime(variant_t& var);
	__declspec(dllexport) variant_t FromTime(time_t t);

	__declspec(dllexport) string ToNarrowString(const wstring& str);
	__declspec(dllexport) wstring ToWideString(const string& str);
	__declspec(dllexport) TString ToString(const string& str);
	__declspec(dllexport) TString ToString(const wstring& str);

	inline void SafeDestroy(void* &pointer)
	{
		if(pointer)						
		{								
			delete pointer;           	
			pointer = NULL;             	
		}
	}

	inline string operator ~(const wstring& str)
	{
		return ToNarrowString(str);
	}

	inline wstring operator ~(const string& str)
	{
		return ToWideString(str);
	}

	_inline void ToLower(string &str)
	{
		transform (str.begin(),str.end(), str.begin(), tolower);
	};

	_inline void ToUpper(string &str)
	{
		transform (str.begin(),str.end(), str.begin(), ::toupper);
	};

	template<typename _Elem, typename _Traits, typename _Ax>
	basic_string<_Elem,_Traits,_Ax> Trim(basic_string<_Elem,_Traits,_Ax>& str);

	template<typename _Elem, typename _Traits, typename _Ax> 
	basic_string<_Elem,_Traits,_Ax> TrimLeft(basic_string<_Elem,_Traits,_Ax>& str);

	template<typename _Elem, typename _Traits, typename _Ax> 
	basic_string<_Elem,_Traits,_Ax> TrimRight(basic_string<_Elem,_Traits,_Ax>& str);

	template<typename _Elem, typename _Traits, typename _Ax> 
	basic_string<_Elem,_Traits,_Ax> PadRight(basic_string<_Elem,_Traits,_Ax>& str, unsigned int len, _Elem ch);

	__declspec(dllexport) TString ExtractFilePath(TString path);

	const time_t TIME_A_HOUR = 60 * 60;
	const time_t TIME_A_DAY = 24 * TIME_A_HOUR;

	__declspec(dllexport) double Now();
	__declspec(dllexport) time_t LocalTime();

	__declspec(dllexport) time_t GetTimePart(time_t t);
	__declspec(dllexport) time_t GetDatePart(time_t t);
	__declspec(dllexport) time_t GetDateValue(time_t t);

	__declspec(dllexport) time_t CTSToTime(string time_str);
	__declspec(dllexport) double CTSToDateTime(string time_str);
	__declspec(dllexport) time_t BuildTime(int year, int month, int day, int hour, int minute, int second);
	__declspec(dllexport) time_t BuildTime(tm& t);
	__declspec(dllexport) double BuildDateTime(int year, int month, int day, int hour, int minute, int second, int m_sec = 0);

	__declspec(dllexport) void DecodeDate(time_t time, int& year, int& month, int& day);
	__declspec(dllexport) void DecodeTime(time_t time, int& hour, int& minute, int& second);

	__declspec(dllexport) string TimeToString(time_t t);
	__declspec(dllexport) string TimeToCTS(time_t t);
	__declspec(dllexport) string TimeToLocalString(time_t t);
	__declspec(dllexport) string TimeToLocalShortString(time_t t);
	__declspec(dllexport) string TimeToLocalCTS(time_t t);
	__declspec(dllexport) string DateTimeToCTS(double t);
	__declspec(dllexport) string DateTimeFormatToCTS(double t);
	__declspec(dllexport) string TimeToCTS();
	__declspec(dllexport) double TimeToDateTime(time_t t);
	__declspec(dllexport) time_t TimeFromDateTime(double time);

	__declspec(dllexport) string GUIDToSting(GUID guid);
	__declspec(dllexport) GUID GUIDFromString(string str);
}


namespace GLEO
{
	template<typename _Elem, typename _Traits, typename _Ax> 
	basic_string<_Elem,_Traits,_Ax> Trim(basic_string<_Elem,_Traits,_Ax>& str)
	{
		basic_string<_Elem,_Traits,_Ax> Result;

		Result = TrimRight(str);
		Result = TrimLeft(Result);

		return Result;
	}

	template<typename _Elem, typename _Traits, typename _Ax> 
	basic_string<_Elem,_Traits,_Ax> TrimRight(basic_string<_Elem,_Traits,_Ax>& str)
	{
		basic_string<_Elem,_Traits,_Ax> Result = str;

		if(Result.size() > 0)
		{
			int findspace = Result.find_last_not_of(' ');

			if(findspace != (Result.size() - 1))
				Result = Result.substr(0, findspace + 1);
			else if(findspace >= Result.size())
				throw Exception("Length Excced", "TString RightTrim");
		}

		return Result;
	}

	template<typename _Elem, typename _Traits, typename _Ax> 
	basic_string<_Elem,_Traits,_Ax> TrimLeft(basic_string<_Elem,_Traits,_Ax>& str)
	{
		basic_string<_Elem,_Traits,_Ax> Result = str;
		int findspace = Result.find_first_not_of(' ');
		if(findspace == -1)
		{
			Result ="";
		}
		else if(findspace != 0)
			Result = Result.substr(findspace, Result.size() - findspace);
		else if(findspace >= Result.size())
			throw Exception("Length Excced", "TString LeftTrim");

		return Result;
	}


	template<typename _Elem, typename _Traits, typename _Ax> 
	basic_string<_Elem,_Traits,_Ax> PadRight(basic_string<_Elem,_Traits,_Ax>& str, unsigned int len, _Elem ch)
	{
		basic_string<_Elem,_Traits,_Ax> Result = str;

		if(Result.size() < len) 
			Result.resize(len, ch);
		else if(Result.size() > len)
			throw Exception("Length Excced", "TString Pad Right");

		return Result;
	}

	template<typename _Elem, typename _Traits, typename _Ax> 
	basic_string<_Elem,_Traits,_Ax> Split(vector<basic_string<_Elem,_Traits,_Ax> >& v, basic_string<_Elem, _Traits,_Ax> str, _Elem c)
	{
		const _Elem s = str.c_str();

		v.clear();
		while (true) 
		{
			const _Elem* begin = s;

			while (*s != c && *s) 
			{
				++s; 
			}

			v.push_back(basic_string<_Elem, _Traits,_Ax>(begin, s));

			if (!*s) 
			{
				break;
			}

			if (!*++s) 
			{
				v.push_back("");
				break;
			}
		}

		return v.size();
	}

	template <class T>
	T ByteReverse(T value)
	{
		T Result;

		for(int i = 0; i < sizeof(T); i++)
		{
			*( ((char*)&Result) + i ) = *( ((char*)&value) + sizeof(T) - 1 - i );
		}

		return Result;
	}
}

namespace GLEO
{
	__declspec(dllexport) int split(vector<string>& v, const string& str, char c);
	__declspec(dllexport) int split(vector<string>& v, const char* s, char c);

	__declspec(dllexport) int split(vector<wstring>& v, const wstring& str, wchar_t c);
	__declspec(dllexport) int split(vector<wstring>& v, const wchar_t* s, wchar_t c);
}

// io
namespace GLEO
{
	__declspec(dllexport) bool CreateDir(wstring path_str);	// path_str : "d:\\aa\\bb\\cc\\"


}

#endif