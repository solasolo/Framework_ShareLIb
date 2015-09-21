// TestWorkPlan.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <windows.h>

#include "WorkConfigReader.h"
#include "WorkPlanMgr.h"
#include "WinFuncs.h"

using namespace Win32Lib;

void Test1()
{
	WorkConfigReader* configReader = new WorkConfigReader();
	wstring filePath = L"d:\\project\\BAOTACHI\\BaoTouSteel\\bin\\workrule.xml";

	bool ret = configReader->ReadWorkConfig(filePath);

	wprintf(ret == true ? L"read success!" : L"read fail!");
}

void Test2()
{
	wstring rule_1 = L"PLAN_AABBCCDD";
	wstring rule_2 = L"PLAN_AADDCCDD";

	wstring BasePath = GetStartupPath();
	wstring filePath = BasePath + L"..\\Data\\workrule.xml";

	WorkPlanMgr* mgr;

	//mgr = new WorkPlanMgr();

	bool ret = mgr->LoadWorkPlanRules(filePath);

	//mgr->CreateWorkPlan(rule_1, 0);
	

	time_t t1 = time(NULL);// + _timezone;;
	setlocale(LC_CTYPE, "");

	//WorkPlanADay* plan = mgr->GetWorkPlan(rule_1, t1);

	WorkPlanADay* plan = mgr->GetWorkPlanEveryDay(rule_2, t1);
	 

	if(plan == NULL)
	{
		wprintf(L"create plan fail");
	}
	else
	{
		wprintf(L"success\n");

		wprintf(L"rule: %s\n", plan->rule.c_str());

		for(int i = 0; i < plan->workitems.size(); i++)
		{
			WorkItem* item = plan->workitems[i];

			tm* t = localtime(&(item->begin_time));

			wprintf(L"%s : %s %d-%d-%d %d:%d -- ", item->name.c_str(), item->group.c_str(), t->tm_year + 1900, t->tm_mon + 1, t->tm_mday, t->tm_hour, t->tm_min);

			tm* end = localtime(&(item->end_time));

			wprintf(L"%s : %s %d-%d-%d %d:%d\n", item->name.c_str(), item->group.c_str(), end->tm_year + 1900, end->tm_mon + 1, end->tm_mday, end->tm_hour, end->tm_min);
		}
	}

	//wchar_t s[] = L"°à´Î";
	//wprintf(L"%s", s);

	delete mgr;
	mgr = NULL;

	//delete plan;
	//plan = NULL;

}

void Test3()
{
	wstring BasePath = GetStartupPath();
	WorkSchedule Schedule(BasePath + L"..\\Data\\workrule.xml");

	ofstream f(BasePath +  L"..\\SGTest.txt");

	time_t endt = time(NULL) + 8 * HOUR_SEC;
	time_t t = CTSToTime("20141105000000");

	do
	{
		ScheduleItem item = Schedule.Get(t);
		
		f << TimeToString(t) << "  " << item.Crew.c_str() << item.Shift.c_str() << "    " << TimeToString(item.Date) << endl;

		t += 60 * 60;
	}
	while(t < endt);

	long zonediff;
	_get_timezone(&zonediff);

	time_t tt = time(NULL) + zonediff;
	f << zonediff << "    " << TimeToString(tt) << endl;	

	ScheduleItem item = Schedule.Get();
	f << endl;	
	f << TimeToString(endt) << "  " << item.Crew.c_str() << item.Shift.c_str() << "    " << TimeToString(item.Date) << endl;

	item = Schedule.Get(time(NULL));
	f << endl;	
	f << TimeToString(time(NULL)) << "  " << item.Crew.c_str() << item.Shift.c_str() << "    " << TimeToString(item.Date) << endl;
}

int _tmain(int argc, _TCHAR* argv[])
{
	CoInitialize(NULL);

	Test3();

	CoUninitialize();

	return 0;
}

