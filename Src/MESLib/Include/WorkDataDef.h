#pragma once

#include <string>
#include <vector>
#include <time.h>

using namespace std;

#define Seconds_Of_Day 86400
#define DAYS_COUNT 35

//
//
//

struct TimeRange
{
	time_t Start;
	time_t End;
};

struct ScheduleItem
{
	time_t Date;
	string Shift;
	string Crew;
};


//
//
//


class __declspec(dllexport) WorkItem
{
public:
	//wchar_t code;
	wstring code;
	wstring name;
	wstring group;

	time_t begin_time;
	time_t end_time;

	int begin_hour;
	int begin_minute;
	int end_hour;
	int end_minute;
	bool expire;

	WorkItem(void);
	//WorkItem(wchar_t code, wstring name);
	WorkItem(wstring code, wstring name);
	~WorkItem(void);

	void SetTime(wstring begin, wstring end);

private:
	wstring begin_time_str;
	wstring end_time_str;

	//bool expire;
};

class __declspec(dllexport) WorkPlanADay
{
public:
	WorkPlanADay();
	~WorkPlanADay();

	wstring rule;

	void AddItem(WorkItem*);
	//WorkItem* GetItem(wchar_t code);
	WorkItem* GetItem(wstring code);
	WorkItem* GetItem(time_t now);
	WorkItem* GetNext();
	void WorkOff();
	bool IsFinish();

	vector<WorkItem*> workitems;

private:
	int cur_index;

	bool expire;
};

