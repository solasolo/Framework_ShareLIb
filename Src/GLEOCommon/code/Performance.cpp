#include "Performance.h"

#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <limits>

#include "WinException.h"
#include "CommonFuncs.h"

//#define toString(x) #x

using namespace Win32Lib;
using namespace std;

namespace GLEO
{
	LARGE_INTEGER PerformanceTimer::ReadFrequency()
	{
		LARGE_INTEGER Result;

		bool res = QueryPerformanceFrequency(&Result);
		if(!res)
		{
			throw WinException(L"Query Performance Frequency");
		}

		return Result;
	}

	void PerformanceTimer::Start()
	{
		bool res = QueryPerformanceCounter(&this->StartTime);
		if(!res)
		{
			throw WinException(L"Query Performance Counter");
		}
	}

	double PerformanceTimer::Stop()
	{
		double Result;

		bool res = QueryPerformanceCounter(&this->StopTime);
		if(!res)
		{
			throw WinException(L"Query Performance Counter");
		}

		long long diff = this->StopTime.QuadPart - this->StartTime.QuadPart;

		LARGE_INTEGER Freq = this->ReadFrequency();

		Result = (double)(diff) / Freq.QuadPart * 1000;		//milliseconds 

		return Result;
	}
}

namespace GLEO
{
	StopWatch::StopWatch(wstring module, int len)
	{
		this->Size = len;	
		this->Buffer = new double[this->Size];
		this->ModuleName = module;

		this->CurrentIndex = 0;

		this->Enabled = true;
	}

	StopWatch::~StopWatch()
	{
		DESTROY(this->Buffer);
	}

	void StopWatch::Analysis(CounterStatistics& cs)
	{
		cs.Max = this->Buffer[0];
		cs.Min = this->Buffer[0];
		cs.Sum = this->Buffer[0];
		cs.Avg = 0;

		for(int i = 1; i < this->Size ; i++)
		{
			if(this->Buffer[i] > cs.Max)
			{
				cs.Max = this->Buffer[i];
			}
			else if(this->Buffer[i] < cs.Min)
			{
				cs.Min = this->Buffer[i];
			}

			cs.Sum += this->Buffer[i];
		}

		cs.Avg = cs.Sum / this->Size;
	}

	int StopWatch::GetSize()
	{
		return this->Size;
	}

	wstring StopWatch::FormatString()
	{
		CounterStatistics cs;
		this->Analysis(cs);

		wchar_t buf[100];
		buf[99] = L'\x0';

		swprintf_s(buf, 99, L"[%s] Timer(ms): Max:%5.2f Min:%5.2f Avg:%5.2f", this->ModuleName.c_str(), cs.Max, cs.Min, cs.Avg);

		return buf;
	}
}

namespace GLEO
{
	TimeStopWatch::TimeStopWatch(wstring module, int len)
		: StopWatch(module, len)
	{
	}

	void TimeStopWatch::Start()
	{
		if(this->Enabled)
		{
			this->Counter.Start();
		}
	}

	bool TimeStopWatch::Stop()
	{
		bool Result = false;

		if(this->Enabled)
		{
			double timeCount = this->Counter.Stop();	

			this->Buffer[this->CurrentIndex ++] = timeCount;

			if(this->CurrentIndex >= this->Size)
			{
				Result = true;

				this->CurrentIndex = 0;
			}
		}

		return Result;
	}
}

namespace GLEO
{
	//性能分析器管理//
	PerformanceAnalysis* PerformanceAnalysis::instance;

	PerformanceAnalysis::PerformanceAnalysis()
	{

	}

	PerformanceAnalysis::~PerformanceAnalysis()
	{
		while(!this->WatchList.empty())
		{
			TimeStopWatch* timer = this->WatchList.front();
			this->WatchList.pop_front();
		}
	}

	PerformanceAnalysis* PerformanceAnalysis::GetInstance()
	{
		if(!instance)
		{
			instance = new PerformanceAnalysis();
		}

		return instance;
	}

	void PerformanceAnalysis::Destroy()
	{
		DESTROY(instance);
	}

	TimeStopWatch* PerformanceAnalysis::Register(wstring module, int len)
	{
		TimeStopWatch* watcher = new TimeStopWatch(module, len);

		this->WatchList.push_back(watcher);

		return watcher;
	}
}
//string DoubleToString(double value, int decplaces=3)
//{
//	ostringstream out;
//	int prec = numeric_limits<double>::digits10; // 18
//	out.precision(prec); //覆盖默认精度
//	out << value;
//	string str = out.str(); //从流中取出字符串
//	char DECIMAL_POINT = '.'; // 欧洲用法为','
//	size_t n = str.find(DECIMAL_POINT);
//	if ((n != string::npos) && (str.size() > n + decplaces)) //有小数点吗？//后面至少还有decplaces位吗？
//	{
//		str[n+decplaces] = '\0';//覆盖第一个多余的数
//	}
//	str.swap(string(str.c_str()));//删除null之后的多余字符
//	return str;
//}