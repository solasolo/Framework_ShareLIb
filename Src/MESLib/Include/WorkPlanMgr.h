#pragma once

#include <map>
#include <list>
#include "WorkDB.h"
#include "WorkDataDef.h"
#include "XMLConfig.h"
#include "WorkConfigReader.h"

using namespace std;
using namespace Win32Lib;

class __declspec(dllexport) WorkSchedule
{
	class __declspec(dllexport) ScheduleRule
	{
		friend WorkSchedule;

	private:
		wstring Name;
		time_t ReferenceDay;

		vector<TimeRange> Timing;
		vector<string> Circle;
		vector<char> ShiftCode;
		vector<char> GrewCode;
		//vector<wchar_t> ShiftName;
		//vector<wchar_t> GrewName;

		int CirCleCount;

	public:
		void Load(wstring conf_file);
	};

private:
	ScheduleRule Rule;

	int GetShift(time_t t);
	char GetGroup(int day, int shift);
	
	time_t TimeShift(time_t t);

	time_t ShiftBeginTime(time_t t);
	time_t ShiftEndTime(time_t t);

public:
	static time_t ReadTimeString(wstring str);
	static time_t ReadDateString(wstring str);

	WorkSchedule(wstring conf_file);

	ScheduleItem Get();
	ScheduleItem Get(time_t t);
};

//
//
//

class __declspec(dllexport) WorkPlanMgr
{
public:
	WorkPlanMgr(XMLConfig* xmlConfig);
	~WorkPlanMgr(void);
	
	bool LoadWorkPlanRules(wstring filePath);

	void CreateWorkPlan(wstring rule, int start);
	WorkPlanADay* GetWorkPlan(wstring rule, time_t day);	// cancel
	WorkPlanADay* GetWorkPlanEveryDay(wstring rule, time_t time = time_t(NULL));

private:
	map<wstring, WorkPlanADay*> workPlanDict;	// key: y-m-d, value: WorkItem, 一个月每天的安排
	map<wstring, vector<wstring>> workRuleDict;	// key: rule, read from config
	vector<wstring> workCycle;
	wstring cur_rule;
	int index_cycle;

	WorkADODB* ado;
	WorkConfigReader* configReader;

	WorkItem* CreateWorkItem(WorkPlanADay*, wstring code, time_t time = time_t(NULL));

	wstring GetWorkPlanFromDB(time_t date);

	void GetGroups(vector<wstring>& groups);
};

