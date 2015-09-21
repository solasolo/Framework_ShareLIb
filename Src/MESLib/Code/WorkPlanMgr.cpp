#include "WorkPlanMgr.h"

void WorkSchedule::ScheduleRule::Load(wstring conf_file)
{
	bool ret = false;

	XMLReader reader;

	reader.Load(conf_file);

	MSXML2::IXMLDOMNodePtr root = reader.GetRoot();
	this->Name = reader.GetAttributeString(root, L"Default");


	// groups
	vector<MSXML2::IXMLDOMNodePtr> group_list;
	reader.SelectNodes(wstring(L"Root//Group//Item"), group_list);
	for(int i = 0; i < group_list.size(); i++)
	{
		wstring name = reader.GetNodeString(group_list[i]);
		string code = ~name;
		if(!code.empty())
		{
			this->GrewCode.push_back(code[0]);
		}
	}

	// rules
	vector<MSXML2::IXMLDOMNodePtr> rule_list;
	reader.SelectNodes(wstring(L"Root//Rule"), rule_list);
	for(int i = 0; i < rule_list.size(); i++)
	{
		wstring RuleName = reader.GetAttributeString(rule_list[i], L"Name");

		if(RuleName == this->Name)
		{
			wstring DayString = reader.GetAttributeString(rule_list[i], L"RefDay");
			this->ReferenceDay = ReadDateString(DayString);

			MSXML2::IXMLDOMNodePtr rule_node = rule_list[i];
	
			// Times
			MSXML2::IXMLDOMNodeListPtr time_list = rule_node->selectNodes(L"Time//Item");
			for(int m = 0; m < time_list->length; m++)
			{
				MSXML2::IXMLDOMNodePtr time_node = time_list->item[m];


				wstring name = reader.GetNodeString(time_node);
				string code = ~name;
				wstring text = reader.GetAttributeString(time_node, L"Text");
				
				if(!code.empty())
				{
					this->ShiftCode.push_back(code[0]);
				}

				wstring time_begin = reader.GetAttributeString(time_node, L"Begin");
				wstring time_end = reader.GetAttributeString(time_node, L"End");

				TimeRange tr;
				tr.Start = ReadTimeString(time_begin);
				tr.End = ReadTimeString(time_end);

				this->Timing.push_back(tr);
			}


			// Circles
			MSXML2::IXMLDOMNodeListPtr cycle_list = rule_node->selectNodes(L"Plan//Item");
			for(int m = 0; m < cycle_list->length; m++)
			{
				wstring plan = reader.GetNodeString(cycle_list->item[m]);

				if(!plan.empty())
				{
					this->Circle.push_back(~plan);
				}
			}
		}
	}

	this->CirCleCount = this->Circle.size();
}

//
//
//
 
time_t WorkSchedule::ReadTimeString(wstring str)
{
	time_t Result = 0;

	int hour;
	int minute;

	swscanf_s(str.c_str(), L"%2d:%2d", &hour, &minute);
	Result = hour * HOUR_SEC + minute * 60;

	return Result;
}

time_t WorkSchedule::ReadDateString(wstring str)
{
	time_t Result = 0;

	int year;
	int month;
	int day;

	swscanf_s(str.c_str(), L"%4d-%2d-%2d", &year, &month, &day);
	Result = BuildTime(year, month, day, 0, 0, 0);

	return Result;
}

WorkSchedule::WorkSchedule(wstring conf_file)
{
	this->Rule.Load(conf_file);
}

ScheduleItem WorkSchedule::Get()
{
	//return this->Get(LocalTime());
	return this->Get(time(NULL) + 8 * HOUR_SEC);
}

ScheduleItem WorkSchedule::Get(time_t t)
{
	ScheduleItem Result;
	
	time_t st = this->TimeShift(t);
	Result.Date = GetDatePart(st);

	int shift = this->GetShift(t);
	Result.Shift = this->Rule.ShiftCode[shift];

	char grew = this->GetGroup(Result.Date, shift);
	
	string GrewStr;
	GrewStr = grew;
	Result.Crew = GrewStr;


	return Result;
}

int WorkSchedule::GetShift(time_t t)
{
	int Result = -1;

	time_t TimePart;
	
	TimePart = GetTimePart(t);

	for(int i = 0; i < this->Rule.Timing.size(); i++)
	{
		TimeRange& item = this->Rule.Timing.at(i);

		if(item.Start < item.End)
		{
			if(TimePart >= item.Start && TimePart < item.End)
			{
				Result = i;
				break;
			}
		}
		else
		{
			if(TimePart >= item.Start || TimePart < item.End)
			{
				Result = i;
				break;
			}
		}
	}

	return Result;
}

char WorkSchedule::GetGroup(int day, int shift)
{
	char Result = '\x0';

	int	DateValue = ((day - this->Rule.ReferenceDay) / TIME_A_DAY) % this->Rule.CirCleCount;
	if(DateValue < 0)
	{
		DateValue += this->Rule.CirCleCount; 
	}

	Result = this->Rule.Circle[DateValue][shift];

	return Result;
}

time_t WorkSchedule::TimeShift(time_t t)
{
	time_t Result;

	time_t ts = this->Rule.Timing[0].Start;

	if(ts < 12 * HOUR_SEC)
	{
		Result = t - ts;
	}
	else
	{
		Result = t + 24 * HOUR_SEC - ts;
	}

	return Result;
}

/*
char WorkSchedule::GetGroup24(time_t t)
{
	int Shift;
	int DateValue;
	int GroupValue;
	char Result = ' ';

	Shift = GetShift(t);

	t += 8 * TIME_A_HOUR;
	t += ShiftTime1;
	GroupValue = DateValue  + Shift * 8;

	Result = GroupLookup24[GroupValue];

	return Result;
}

time_t WorkSchedule::ShiftBeginTime(time_t t)
{
	time_t Result;

	int shift = GetShift(t);

	t += ShiftTime1;
	Result = GetDatePart(t);

	switch(shift)
	{
	case 0:
		Result = Result + 0; 
		break;

	case 1:
		Result = Result + ShiftTime2; 
		break;

	case 2:
		Result = Result + ShiftTime3; 
		break;

	}

}

time_t WorkSchedule::ShiftEndTime(time_t t)
{
	time_t Result;

	int shift = GetShift(t);

	t += 8 * TIME_A_HOUR;
	t += ShiftTime1;
	Result = GetDatePart(t);

	switch(shift)
	{
	case 0:
		Result = Result + ShiftTime2; 
		break;

	case 1:
		Result = Result + ShiftTime3; 
		break;

	case 2:
		Result = Result + TIME_A_DAY; 
		break;

	}

	return Result - ShiftTime1 - 8 * TIME_A_HOUR;
}
*/

//
//
//

WorkPlanMgr::WorkPlanMgr(XMLConfig* xmlConfig)
{
	this->index_cycle = 0;
	this->configReader = new WorkConfigReader();

	wstring connstr = xmlConfig->getWString("DB.ConnStr");

	this->ado = new WorkADODB(connstr);
}

WorkPlanMgr::~WorkPlanMgr(void)
{
	map<wstring, WorkPlanADay*>::iterator it;

	for(it = this->workPlanDict.begin(); it != this->workPlanDict.end(); it++)
	{
		delete it->second;
		it->second = NULL;
	}

	this->workPlanDict.clear();

	map<wstring, vector<wstring>>::iterator it_2;
	for(it_2 = this->workRuleDict.begin(); it_2 != this->workRuleDict.end(); it_2++)
	{
		it_2->second.clear();
	}
	this->workRuleDict.clear();

	delete this->configReader;
	this->configReader = NULL;

	if(this->ado)
	{
		delete this->ado;
		this->ado = NULL;
	}
}

bool WorkPlanMgr::LoadWorkPlanRules(wstring filePath)
{
	bool ret = false;

	//wstring rule1 = L"PLAN_AABBCCDD";
	//vector<wstring> cycle_1;
	//cycle_1.push_back(L"ABCD");
	//cycle_1.push_back(L"ABCD");
	//cycle_1.push_back(L"BCDA");
	//cycle_1.push_back(L"BCDA");
	//cycle_1.push_back(L"CDAB");
	//cycle_1.push_back(L"CDAB");
	//cycle_1.push_back(L"DABC");
	//cycle_1.push_back(L"DABC");
	//this->workRuleDict[rule1] = cycle_1;

	ret = this->configReader->ReadWorkConfig(filePath);

	return ret;
}

void WorkPlanMgr::CreateWorkPlan(wstring rule, int start)
{
	tm tm_now;
	this->cur_rule = rule;
	time_t time_now = time(NULL);// + _timezone;

	//time_now

	localtime_s(&tm_now, &time_now);
	int today = tm_now.tm_mday;
	int week = tm_now.tm_wday;
	int firstDay_week = ((week == 0) ? 7 : week)  - (today - 1) % 7;	//  当月一号是星期几
	int daysOf35 = today + firstDay_week;

	time_t time_everyDay= time_now - (1 * (today -1)) * Seconds_Of_Day - (1 * firstDay_week) * Seconds_Of_Day;

	tm tm_first_full;
	localtime_s(&tm_first_full, &time_everyDay);
	//
	for(int i = 1; i < daysOf35; i++)
	{
		tm tm_everyDay;
		localtime_s(&tm_everyDay, &time_everyDay);

		wchar_t date[20];
		swprintf(date, 20, L"%d-%d-%d", tm_everyDay.tm_year + 1900, tm_everyDay.tm_mon + 1, tm_everyDay.tm_mday);

		WorkPlanADay* workPlanADay = new WorkPlanADay();

		workPlanADay->rule = this->cur_rule;
		for(int j = 0; j < 4; j++)
		{
			workPlanADay->AddItem(new WorkItem());
		}

		this->workPlanDict[wstring(date)] = workPlanADay;

		time_everyDay += Seconds_Of_Day;
	}

	WorkPlanADay* dayModel = this->configReader->GetWorkPlanModel(cur_rule);

	int n = 0;
	do
	{
		tm tm_everyDay;
		localtime_s(&tm_everyDay, &time_everyDay);
		wchar_t date[20];
		swprintf(date, 20, L"%d-%d-%d", tm_everyDay.tm_year + 1900, tm_everyDay.tm_mon + 1, tm_everyDay.tm_mday);

		//wstring plan = this->workRuleDict[cur_rule][n];
		wstring plan = this->workCycle[n];

		WorkPlanADay* workPlanADay = new WorkPlanADay();
		workPlanADay->rule = this->cur_rule;

		for(int i = 0; i < plan.length(); i++)
		{
			wstring ss = L"";
			ss.append(1,plan[i]);
			WorkItem* item = this->CreateWorkItem(dayModel, ss);
			workPlanADay->AddItem(item);
		}

		this->workPlanDict[wstring(date)] = workPlanADay;

		if(n == this->workCycle.size())
		{
			n = 0;
		}

		daysOf35++;
		time_everyDay += Seconds_Of_Day;

	}
	while (daysOf35 <= DAYS_COUNT);

}

WorkPlanADay* WorkPlanMgr::GetWorkPlan(wstring rule, time_t date_t)
{
	WorkPlanADay* plan = NULL;

	tm tm_date;
	localtime_s(&tm_date, &date_t);

	wchar_t date[20];
	swprintf(date, 20, L"%d-%d-%d", tm_date.tm_year + 1900, tm_date.tm_mon + 1, tm_date.tm_mday);

	map<wstring, WorkPlanADay*>::iterator it;

	for(it = this->workPlanDict.begin(); it != this->workPlanDict.end(); it++)
	{
		if(it->first == date)
		{
			plan = it->second;

			break;
		}
	}

	return plan;
}

WorkItem* WorkPlanMgr::CreateWorkItem(WorkPlanADay* model, wstring code, time_t time)
{
	WorkItem* item = NULL;

	for(int i = 0; i < model->workitems.size(); i++)
	{
		if(model->workitems[i]->code == code)
		{
			item = new WorkItem(code, model->workitems[i]->name);
			item->begin_hour = model->workitems[i]->begin_hour;
			item->begin_minute = model->workitems[i]->begin_minute;

			item->end_hour = model->workitems[i]->end_hour;
			item->end_minute = model->workitems[i]->end_minute;

			tm tm_now;
			localtime_s(&tm_now, &time);

			time_t time_zero = time - tm_now.tm_hour * 3600 - tm_now.tm_min * 60 - tm_now.tm_sec;

			item->begin_time = time_zero;
			item->begin_time += item->begin_hour * 3600 + item->begin_minute * 60;

			item->end_time = time_zero;
			if(item->begin_hour > item->end_hour)
			{
				item->end_time += Seconds_Of_Day;
			}

			item->end_time += item->end_hour * 3600 + item->end_minute * 60;

			break;
		}
	}

	if(item == NULL)
	{
		item = new WorkItem();
	}

	return item;
}

WorkPlanADay* WorkPlanMgr::GetWorkPlanEveryDay(wstring rule, time_t time)
{
	WorkPlanADay* workPlanADay = NULL;

	vector<wstring> groups;
	this->GetGroups(groups);

	if(groups.size() == 0)
	{
		return NULL;
	}

	wstring work_plan_today =  this->GetWorkPlanFromDB(time);

	wstring temp_rule = rule;
	if(rule == L"")
	{
		temp_rule = this->cur_rule;
	}

	workPlanADay = new WorkPlanADay();
	workPlanADay->rule = temp_rule;

	this->workCycle = this->configReader->GetWorkCycle(temp_rule);

	if(work_plan_today == L"")
	{
		if(this->workCycle.size() > 0 && this->index_cycle < this->workCycle.size())
		{
			work_plan_today = this->workCycle[this->index_cycle];

			this->index_cycle++;
			if(this->index_cycle == this->workCycle.size())
			{
				this->index_cycle = 0;
			}
		}
	}

	if(work_plan_today == L"")
	{
		//throw Exception(L"获得指定日期的排班计划失败");
		return NULL;
	}

	WorkPlanADay* dayModel = this->configReader->GetWorkPlanModel(temp_rule);

	for(int i = 0; i < work_plan_today.length(); i++)
	{
		wstring ss = L"";
		ss.append(1,work_plan_today[i]);
		WorkItem* item = this->CreateWorkItem(dayModel, ss, time);	// 设置上下班时间为绝对时间

		if(i < groups.size())
		{
			item->group = groups[i];
		}

		workPlanADay->AddItem(item);
	}

	//delete dayModel;	// 此处delete会导this->configReader致析构函数出错
	//dayModel = NULL;

	this->index_cycle++;
	if(this->index_cycle == this->workCycle.size())
	{
		this->index_cycle = 0;
	}

	return workPlanADay;
}

wstring WorkPlanMgr::GetWorkPlanFromDB(time_t date)
{
	wstring workPlanADay = L"DDAC";

	workPlanADay = this->ado->GetWorkPlan(date);

	return workPlanADay;
}

void WorkPlanMgr::GetGroups(vector<wstring>& groups)
{
	vector<wstring> rs = this->ado->QueryWorkGroups(L"select code from WorkGroup order by id");

	for(int i = 0; i < rs.size(); i++)
	{
		groups.push_back(rs[i]);
	}

	//groups.push_back(L"甲");
	//groups.push_back(L"乙");
	//groups.push_back(L"丙");
	//groups.push_back(L"丁");
}