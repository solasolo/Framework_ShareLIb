#pragma once

#include <map>
#include "XMLReader.h"
#include "WorkDataDef.h"

using namespace GLEO;
using namespace std;

class __declspec(dllexport) WorkConfigReader
{
public:
	WorkConfigReader(void);
	~WorkConfigReader(void);

	bool ReadWorkConfig(wstring filepath);

	WorkPlanADay* GetWorkPlanModel(wstring rule);

	vector<wstring> GetWorkCycle(wstring rule);

	wstring GetShiftName(wstring rule, wchar_t code);

private:

	XMLReader* xmlReader;

	map<wstring, WorkPlanADay*> work_times;	// key: rule, value: times of a day
	map<wstring, vector<wstring>> work_rules;	// key: rule, value: plan for a cycle
	map<wstring, map<wchar_t, wstring>> work_plan_shift;
};

