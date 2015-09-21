#pragma once

#include <stdlib.h>
#include <string>
#include <list>
#include <windows.h>

using namespace std;
/**
*���ܷ�����/������
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
		int Size;		// �����С(����)
		bool Enabled;
		double* Buffer;	// ��¼����
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
	*���ܷ���������
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