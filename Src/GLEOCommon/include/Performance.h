#pragma once

#include <stdlib.h>
#include <string>
#include <list>
#include <windows.h>

using namespace std;
/**
*性能分析器/计数器
*/

namespace GLEO
{
	enum StopWatchType
	{
		TimeWatch,
		CountWatch
	};

	struct CounterStatistics 
	{
		double Max;
		double Min;
		double Sum;
		double Avg;
	};

	class _declspec(dllexport) PerformanceTimer
	{
	private:
		static LARGE_INTEGER Frequency;

		static LARGE_INTEGER ReadFrequency();

		LARGE_INTEGER StartTime;
		LARGE_INTEGER StopTime;

	public:
		void Start();
		double Stop();
	};

	class _declspec(dllexport) StopWatch
	{
	private:
		wstring ModuleName;	

	protected:
		int Size;		// 链表大小(常量)
		bool Enabled;
		double* Buffer;	// 记录数据
		int CurrentIndex;

		PerformanceTimer Counter;

		virtual void Analysis(CounterStatistics& cs);

	public:
		StopWatch(wstring module, int len);
		~StopWatch();
		
		int GetSize();

		wstring FormatString();
	};

	class _declspec(dllexport) TimeStopWatch : public StopWatch
	{
	public:
		TimeStopWatch(wstring module, int len);
		~TimeStopWatch();

		virtual void Start();
		virtual bool Stop();
	};

	/**
	*性能分析器管理
	*/
	class _declspec(dllexport) PerformanceAnalysis
	{
	private:
		static PerformanceAnalysis* instance;

		list<TimeStopWatch*> WatchList;

	public:
		static PerformanceAnalysis* GetInstance();
		static void Destroy();

		PerformanceAnalysis();
		virtual ~PerformanceAnalysis();

		TimeStopWatch* Register(wstring module, int len = 500);
	};
}