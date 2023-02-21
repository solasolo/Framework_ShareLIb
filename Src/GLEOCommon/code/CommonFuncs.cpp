
#include "CommonFuncs.h"

#include <ctime>

#include "WinException.h"

bool operator < (GUID const& lhs, GUID const& rhs)
{ 
	return memcmp(&lhs, &rhs, sizeof(GUID)) < 0; 
} 

namespace GLEO
{
	bool IsEmpty(const variant_t& var)
	{
		VARIANT Value;

#if _MSC_VER >= 1300
		Value = ((variant_t)var).GetVARIANT();
#else
		variant_t TempVar = var;
		Value = TempVar.Detach();
#endif

		return Value.vt == VT_EMPTY;
	}

	bool IsNull(const variant_t& var)
	{
		VARIANT Value;

#if _MSC_VER >= 1300
		Value = ((variant_t)var).GetVARIANT();
#else
		variant_t TempVar = var;
		Value = TempVar.Detach();
#endif

		return Value.vt == VT_NULL;
	}

	long ToLong(const variant_t& var)
	{
		long Result = 0;

		if( !(IsEmpty(var) || IsNull(var)) ) Result = long(var);

		return Result;
	}

	double ToFloat(const variant_t& var)
	{
		double Result = 0.0;

		if( !(IsEmpty(var) || IsNull(var)) ) 
			Result = double(var);

		return Result;
	}

	string ToString(const variant_t& var)
	{
		string Result = "";

		if( !(IsEmpty(var) || IsNull(var)) ) 
			Result = (char*)(_bstr_t)var;

		return Result;
	}

	wstring ToWString(const variant_t& var)
	{
		wstring Result = L"";

		if( !(IsEmpty(var) || IsNull(var)) ) 
			Result = (wchar_t*)(_bstr_t)var;

		return Result;
	}

	time_t ToTime(const variant_t& var)
	{
		time_t Result;
		double fd = ToFloat(var);

		Result = (unsigned long)((fd - DB_DATETIME_SHIFT) * DAY_SEC - _timezone);

		return Result;
	}

	variant_t FromTime(time_t t)
	{
		variant_t Result = (double)( (t + _timezone) / DAY_SEC + DB_DATETIME_SHIFT );
		Result.ChangeType(VT_DATE);

		return Result;
	}
}

namespace GLEO
{
	string ToNarrowString(const wstring& str)
	{
		string buf = "";
		int len;
		const wchar_t* pStr;

		pStr = str.c_str();
		len = (int) str.length();

		if (len > 0)
		{
			// figure out how many narrow characters we are going to get 
			int nChars = WideCharToMultiByte(CP_ACP, 0, pStr, len, NULL, 0, NULL, NULL);

			if (nChars > 0)
			{
				buf.resize(nChars);
				WideCharToMultiByte(CP_ACP, 0, pStr, len, const_cast<char*>(buf.c_str()), nChars, NULL, NULL);
			}
		}

		return buf ; 
	}

	wstring ToWideString(const string& str)
	{
		wstring buf = L"";
		int len;
		const char* pStr;

		pStr = str.c_str();
		len = (int) str.length();

		if (len > 0)
		{
			// figure out how many narrow characters we are going to get 
			int nChars = MultiByteToWideChar(CP_ACP, 0, pStr, len, NULL, 0);

			if (nChars > 0)
			{
				buf.resize(nChars);
				MultiByteToWideChar(CP_ACP, 0, pStr, len, const_cast<wchar_t*>(buf.c_str()), nChars);
			}
		}

		return buf ; 
	}

	string ToUTF8String(const wstring& str)
	{
		string buf = "";
		int len;
		const wchar_t* pStr;

		len = (int)str.length();
		pStr = str.c_str();

		if (len > 0)
		{
			// figure out how many narrow characters we are going to get 
			int nChars = WideCharToMultiByte(CP_UTF8, 0, pStr, len, NULL, 0, NULL, NULL);

			if (nChars > 0)
			{
				buf.resize(nChars);
				WideCharToMultiByte(CP_UTF8, 0, pStr, len, const_cast<char*>(buf.c_str()), nChars, NULL, NULL);
			}
		}

		return buf;
	}

	wstring FromUTF8String(const string& str)
	{
		wstring buf = L"";
		int len;
		const char* pStr;

		len = (int)str.length();
		pStr = str.c_str();

		if (len > 0)
		{
			// figure out how many narrow characters we are going to get 
			int nChars = MultiByteToWideChar(CP_UTF8, 0, pStr, len, NULL, 0);

			if (nChars > 0)
			{
				buf.resize(nChars);
				MultiByteToWideChar(CP_UTF8, 0, pStr, len, const_cast<wchar_t*>(buf.c_str()), nChars);
			}
		}

		return buf;
	}

	wstring ExtractFilePath(wstring path)
	{
		wstring Result;

		size_t p = path.find_last_of( _T('\\'));
		if(p == wstring::npos)
		{
			Result = _T(".");
		}
		else
		{
			Result = path.substr(0, p);
		}

		return Result;
	}

	double Now()
	{
		double Result = 0;

		SYSTEMTIME ts;
		GetLocalTime(&ts);

		SystemTimeToVariantTime(&ts, &Result);
		//Result = BuildDateTime(ts.wYear, ts.wMonth, ts.wDay, ts.wHour, ts.wMinute, ts.wSecond, ts.wMilliseconds);

		return Result;
	}

	time_t LocalTime()
	{
		time_t rt;

		long zonediff;
		_get_timezone(&zonediff);
		rt = time(NULL) + zonediff;

		return rt;
	}

/*
	time_t LocalTime()
	{
		time_t utc;
		time_t local;
		tm local_tm;

		utc = time(NULL);
		localtime_s(&local_tm, &utc);
		local = _mkgmtime(&local_tm);

		return local;
	}
*/

	time_t GetTimePart(time_t t)
	{
		time_t Result;
		Result = t % TIME_A_DAY;

		return Result;
	}

	time_t GetDatePart(time_t t)
	{
		time_t Result;
		Result = t / TIME_A_DAY;
		Result = Result * TIME_A_DAY;

		return Result;
	}

	time_t SetTimePart(time_t t, int time_value)
	{
		time_t Result;
		Result = GetDatePart(t) + time_value;

		return Result;
	}

	time_t GetDateValue(time_t t)
	{
		time_t Result;
		Result = t / TIME_A_DAY;

		return Result;
	}

	time_t CTSToTime(string time_str)
	{
		time_t Result = 0;

		if(time_str.size() == 14)
		{
			tm T;
			sscanf(time_str.c_str(), "%04d%02d%02d%02d%02d%02d", &T.tm_year, &T.tm_mon, &T.tm_mday, &T.tm_hour, &T.tm_min, &T.tm_sec);

			Result = BuildTime(T);
		}
		else if(time_str.size() == 8)
		{
			tm T;
			T.tm_year = 1900;
			T.tm_mon = 1;
			T.tm_mday = 1;

			sscanf(time_str.c_str(), "%02d:%02d:%02d", &T.tm_hour, &T.tm_min, &T.tm_sec);

			Result = BuildTime(T);
		}

		return Result;
	}

	double CTSToDateTime(string time_str)
	{
		double Result = 0;

		if(time_str.size() == 14)
		{
			SYSTEMTIME T;
			sscanf(time_str.c_str(), "%04d%02d%02d%02d%02d%02d", &T.wYear, &T.wMonth, &T.wDay, &T.wHour, &T.wMinute, &T.wSecond);

			if(!SystemTimeToVariantTime(&T, &Result))
			{
				throw Win32Lib::WinException(_T("Trans CTS to DateTime"));
			}
		}

		return Result;
	}

	time_t BuildTime(tm& t)
	{
		t.tm_year -= 1900; 
		t.tm_mon -= 1;

		return mktime(&t);
	}

	time_t BuildTime(int year, int month, int day, int hour, int minute, int second)
	{
		tm T;

		T.tm_year = year; 
		T.tm_mon = month;
		T.tm_mday = day; 
		T.tm_hour = hour; 
		T.tm_min = minute; 
		T.tm_sec = second;

		return BuildTime(T);
	}

	double BuildDateTime(int year, int month, int day, int hour, int minute, int second, int m_sec)
	{
		double Result;
		SYSTEMTIME T;

		T.wYear = year;
		T.wMonth = month;
		T.wDay = day;
		T.wHour = hour;
		T.wMinute = minute;
		T.wSecond = second;
		T.wMilliseconds = m_sec;

		SystemTimeToVariantTime(&T, &Result);

		return Result;
	}

	void DecodeDate(time_t time, int& year, int& month, int& day)
	{
	}

	void DecodeTime(time_t time, int& hour, int& minute, int& second)
	{
	}

	string TimeToCTS(time_t t)
	{
		char buf[20];
		buf[19] = '\x0';

		tm* NowStruct = gmtime(&t);

		sprintf_s(buf, 19, "%04d%02d%02d%02d%02d%02d"
			, NowStruct->tm_year + 1900
			, NowStruct->tm_mon + 1
			, NowStruct->tm_mday
			, NowStruct->tm_hour
			, NowStruct->tm_min
			, NowStruct->tm_sec
			);

		return string(buf);
	}

	string TimeToString(time_t t)
	{
		char buf[30];
		buf[29] = '\x0';

		tm* NowStruct = gmtime(&t);

		if(NowStruct)
		{
			sprintf_s(buf, 29, "%04d-%02d-%02d %02d:%02d:%02d"
				, NowStruct->tm_year + 1900
				, NowStruct->tm_mon + 1
				, NowStruct->tm_mday
				, NowStruct->tm_hour
				, NowStruct->tm_min
				, NowStruct->tm_sec
				);
		}
		else
		{
		}

		return string(buf);
	}

	string TimeToLocalCTS(time_t t)
	{
		char buf[20];
		buf[19] = '\x0';

		tm* NowStruct = localtime(&t);

		sprintf_s(buf, 19, "%04d%02d%02d%02d%02d%02d"
			, NowStruct->tm_year + 1900
			, NowStruct->tm_mon + 1
			, NowStruct->tm_mday
			, NowStruct->tm_hour
			, NowStruct->tm_min
			, NowStruct->tm_sec
			);

		return string(buf);
	}

	string TimeToLocalString(time_t t)
	{
		char buf[30];
		buf[29] = '\x0';

		tm* NowStruct = localtime(&t);

		if(NowStruct)
		{
			sprintf_s(buf, 29, "%04d-%02d-%02d %02d:%02d:%02d"
				, NowStruct->tm_year + 1900
				, NowStruct->tm_mon + 1
				, NowStruct->tm_mday
				, NowStruct->tm_hour
				, NowStruct->tm_min
				, NowStruct->tm_sec
				);
		}
		else
		{
		}

		return string(buf);
	}

	string TimeToLocalShortString(time_t t)
	{
		char buf[20];
		buf[19] = '\x0';

		tm* NowStruct = localtime(&t);

		if(NowStruct)
		{
			sprintf_s(buf, 19, "%04d-%02d-%02d"
				, NowStruct->tm_year + 1900
				, NowStruct->tm_mon + 1
				, NowStruct->tm_mday
				);
		}
		else
		{
		}

		return string(buf);
	}

	string DateTimeToCTS(double t)
	{
		char buf[20];
		buf[19] = '\x0';
		SYSTEMTIME NowStruct;

		if(VariantTimeToSystemTime(t, &NowStruct))
		{
			sprintf_s(buf, 19, "%04d%02d%02d%02d%02d%02d"
				, NowStruct.wYear
				, NowStruct.wMonth
				, NowStruct.wDay
				, NowStruct.wHour
				, NowStruct.wMinute
				, NowStruct.wSecond
				);
		}
		else
		{
			buf[0] = '\x0';
		}

		return string(buf);
	}

	string DateTimeFormatToCTS(double t)
	{
		char buf[30];
		buf[29] = '\x0';
		SYSTEMTIME NowStruct;

		if(VariantTimeToSystemTime(t, &NowStruct))
		{
			sprintf_s(buf, 29, "%04d-%02d-%02d %02d:%02d:%02d"
				, NowStruct.wYear
				, NowStruct.wMonth
				, NowStruct.wDay
				, NowStruct.wHour
				, NowStruct.wMinute
				, NowStruct.wSecond
				);
		}
		else
		{
			buf[0] = '\x0';
		}

		return string(buf);
	}

	string TimeToCTS()
	{
		return TimeToCTS(time(NULL));
	}

	double TimeToDateTime(time_t t)
	{
		return (double(t) / DAY_SEC + DB_DATETIME_SHIFT);
	}

	time_t TimeFromDateTime(double time)
	{
		return int((time - DB_DATETIME_SHIFT) * DAY_SEC);
	}

	GUID GUIDFromString(string guid)
	{
		GUID Result;

		//int n = sscanf(guid.c_str(), "{%08X-%04X-%04X-%02X%02X-%02X%02X%02X%02X%02X%02X}", &Result.Data1, &Result.Data2, &Result.Data3, &Result.Data4[0], &Result.Data4[1], &Result.Data4[2], &Result.Data4[3], &Result.Data4[4], &Result.Data4[5], &Result.Data4[6], &Result.Data4[7]);

		Result.Data1 = strtoul(guid.substr(1,8).c_str(),NULL,16)/*3178092314*/;
		Result.Data2 = (unsigned short)strtol(guid.substr(10,4).c_str(),NULL,16);
		Result.Data3 = (unsigned short)strtol(guid.substr(15,4).c_str(),NULL,16);
		Result.Data4[0] = (unsigned char)strtol(guid.substr(20,2).c_str(),NULL,16);
		Result.Data4[1] = (unsigned char)strtol(guid.substr(22,2).c_str(),NULL,16);
		Result.Data4[2] = (unsigned char)strtol(guid.substr(25,2).c_str(),NULL,16);
		Result.Data4[3] = (unsigned char)strtol(guid.substr(27,2).c_str(),NULL,16);
		Result.Data4[4] = (unsigned char)strtol(guid.substr(29,2).c_str(),NULL,16);
		Result.Data4[5] = (unsigned char)strtol(guid.substr(31,2).c_str(),NULL,16);
		Result.Data4[6] = (unsigned char)strtol(guid.substr(33,2).c_str(),NULL,16);
		Result.Data4[7] = (unsigned char)strtol(guid.substr(35,2).c_str(),NULL,16);

		return Result;
	}

	string GUIDToSting(GUID guid)
	{
		char Result[50];
		Result[49] = '\x0';

		int n = sprintf_s(Result, 49, "{%08X-%04X-%04X-%02X%02X-%02X%02X%02X%02X%02X%02X}",guid.Data1, guid.Data2, guid.Data3, guid.Data4[0], guid.Data4[1], guid.Data4[2], guid.Data4[3], guid.Data4[4], guid.Data4[5], guid.Data4[6], guid.Data4[7]);

		return Result;
	}

	int split(vector<string>& v, const string& str, char c)
	{
		v.clear();
		if(str.size() > 0) 
		{
			string::const_iterator s = str.begin();
			while (true) 
			{
				string::const_iterator begin = s;

				while (s != str.end() && *s != c) 
				{ 
					++s; 
				}

				v.push_back(string(begin, s));

				if (s == str.end()) 
				{
					break;
				}

				if (++s == str.end()) 
				{
					v.push_back("");
					break;
				}
			}
		}

		return v.size();
	}

	int split(vector<string>& v, const char* s, char c)
	{
		v.clear();
		while (true) 
		{
			const char* begin = s;

			while (*s != c && *s) 
			{
				++s; 
			}

			v.push_back(string(begin, s));

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

	int split(vector<wstring>& v, const wstring& str, wchar_t c)
	{
		v.clear();

		if(str.size() > 0) 
		{
			wstring::const_iterator s = str.begin();
			while (true) 
			{
				wstring::const_iterator begin = s;

				while (s != str.end() && *s != c) 
				{ 
					++s; 
				}

				v.push_back(wstring(begin, s));

				if (s == str.end()) 
				{
					break;
				}

				if (++s == str.end()) 
				{
					v.push_back(L"");
					break;
				}
			}
		}

		return v.size();
	}

	int split(vector<wstring>& v, const wchar_t* s, wchar_t c)
	{
		v.clear();
		while (true) 
		{
			const wchar_t* begin = s;

			while (*s != c && *s)
			{
				++s;
			}

			v.push_back(wstring(begin, s));

			if (!*s)
			{
				break;
			}

			if (!*++s)
			{
				v.push_back(L"");
				break;
			}
		}

		return v.size();
	}
}

namespace GLEO
{
	bool CreateDir(wstring path_str)
	{
		bool bRet = true;

		int index = 0; 
		int i = 0; 
		while(1) 
		{ 
			wstring::size_type pos = path_str.find(L"\\",index);
			wstring str1;

			str1 = path_str.substr(0,pos);
			if( pos != -1 && i > 0 )
			{ 
				_wmkdir(str1.c_str());
			}

			if( pos == -1 )
			{
				bRet = false;
				break;
			}

			i ++;
			index = pos+1;
		}

		return bRet;
	}
}