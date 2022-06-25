#include "WorkConfigReader.h"
#include "CommonFuncs.h"

WorkConfigReader::WorkConfigReader(void)
{
	this->xmlReader = new XMLReader();
}

WorkConfigReader::~WorkConfigReader(void)
{
	DESTROY(this->xmlReader);

	map<wstring, WorkPlanADay*>::iterator it_1 = this->work_times.begin();
	while(it_1 != this->work_times.end())
	{
		DESTROY(it_1->second);
		it_1++;
	}

	this->work_times.clear();

	map<wstring, vector<wstring>>::iterator it_2 = this->work_rules.begin();
	while(it_2 != this->work_rules.end())
	{
		it_2->second.clear();
		it_2++;
	}

	this->work_rules.clear();

	map<wstring, map<wchar_t, wstring>>::iterator it_3 = this->work_plan_shift.begin();
	while(it_3 != this->work_plan_shift.end())
	{
		it_3->second.clear();
		it_3++;
	}

	this->work_plan_shift.clear();
}

WorkPlanADay* WorkConfigReader::GetWorkPlanModel(wstring rule)
{
	map<wstring, WorkPlanADay*>::iterator it;
	it = this->work_times.find(rule);
	if(it != this->work_times.end())
	{
		return it->second;
	}
	else
	{
		return NULL;
	}
}

vector<wstring> WorkConfigReader::GetWorkCycle(wstring rule)
{
	vector<wstring> buf;

	map<wstring, vector<wstring>>::iterator it;
	it = this->work_rules.find(rule);
	if(it != this->work_rules.end())
	{
		for(int i = 0; i < it->second.size(); i++)
		{
			buf.push_back(it->second[i]);
		}
	}

	return buf;
}

wstring WorkConfigReader::GetShiftName(wstring rule, wchar_t code)
{
	wstring name = L"";

	map<wstring, map<wchar_t, wstring>>::iterator it = this->work_plan_shift.find(rule);

	if(it != this->work_plan_shift.end())
	{
		map<wchar_t, wstring>::iterator it_t = it->second.find(code);

		if(it_t != it->second.end())
		{
			name = it_t->second;
		}
	}

	return name;
}

bool WorkConfigReader::ReadWorkConfig(wstring filepath)
{
	bool ret = false;

	try
	{
		this->xmlReader->Load(filepath);

		ret = true;
	}
	catch(Exception & e)
	{
		// log error
		throw e;
	}
	catch(_com_error &e)
	{
		throw new Exception((char*)e.Description());
	}

	vector<MSXML2::IXMLDOMNodePtr> group_list;

	this->xmlReader->GetChildNodes(wstring(L"Root//Group"), group_list);

	// groups
	for(int i = 0; i < group_list.size(); i++)
	{
		wstring group_code = this->xmlReader->GetNodeString(group_list[i]->childNodes->item[0]);
	}

	vector<MSXML2::IXMLDOMNodePtr> rule_list;

	this->xmlReader->GetChildNodes(wstring(L"Root"), rule_list);

	// rules
	for(int i = 1; i < rule_list.size(); i++)
	{
		wstring ruleName = this->xmlReader->GetAttributeString(rule_list[i], L"Name");

		//
		MSXML2::IXMLDOMNodePtr rule_time = rule_list[i]->childNodes->item[0];
		MSXML2::IXMLDOMNodeListPtr times = rule_time->childNodes;

		WorkPlanADay* planADay = new WorkPlanADay();

		for(int m = 0; m < times->length; m++)
		{
			wstring code = this->xmlReader->GetNodeString(times->item[m]);
			wstring text = this->xmlReader->GetAttributeString(times->item[m], L"Text");
			wstring time_begin = this->xmlReader->GetAttributeString(times->item[m], L"Begin");
			wstring time_end = this->xmlReader->GetAttributeString(times->item[m], L"End");

			WorkItem* workitem = new WorkItem(code, text);
			workitem->SetTime(time_begin, time_end);

			planADay->AddItem(workitem);
		}

		this->work_times[ruleName] = planADay;

		//
		MSXML2::IXMLDOMNodePtr rule_plan = rule_list[i]->childNodes->item[1];
		MSXML2::IXMLDOMNodeListPtr plans = rule_plan->childNodes;

		vector<wstring> cycle;
		for(int m = 0; m < plans->length; m++)
		{
			wstring plan = this->xmlReader->GetNodeString(plans->item[m]);
			cycle.push_back(plan);
		}

		this->work_rules[ruleName] = cycle;
	}

	return ret;
}