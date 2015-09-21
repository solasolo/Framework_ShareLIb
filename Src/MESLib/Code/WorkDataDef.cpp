#include "WorkDataDef.h"

WorkItem::WorkItem(void)
{
	code = L'D';	// 休息
	name = L"休息";	//休息

	begin_time = time_t(NULL);
	end_time = time_t(NULL);
	expire = false;	// 没过期
}

WorkItem::WorkItem(wstring _code, wstring _name)
{
	code = _code;
	name = _name;
	expire = false;
}

WorkItem::~WorkItem(void)
{

}

void WorkItem::SetTime(wstring begin, wstring end)
{
	this->begin_time_str = begin;
	this->end_time_str = end;

	int sp = begin.find(L':');

	if(sp > 0)
	{
		wstring hour_s = begin.substr(0, sp);
		wstring minute_s = begin.substr(sp + 1);

		begin_hour = _wtoi(hour_s.c_str());
		begin_minute = _wtoi(minute_s.c_str());
	}

	sp = end.find(L':');

	if(sp > 0)
	{
		wstring hour_s = end.substr(0, sp);
		wstring minute_s = end.substr(sp + 1);

		end_hour = _wtoi(hour_s.c_str());
		end_minute = _wtoi(minute_s.c_str());
	}
}

//
WorkPlanADay::WorkPlanADay()
{
	cur_index = -1;
	expire = false;
}

WorkPlanADay::~WorkPlanADay()
{
	for(int i = 0; i < this->workitems.size(); i++)
	{
		if(this->workitems[i] != NULL)
		{
			delete this->workitems[i];
		}
	}
	if(this->workitems.size() > 0)
	{
		this->workitems.clear();
	}
}

void WorkPlanADay::AddItem(WorkItem* item)
{
	this->workitems.push_back(item);
}

WorkItem* WorkPlanADay::GetItem(wstring code)
{
	WorkItem* item = NULL;

	for(int i = 0; i < this->workitems.size(); i++)
	{
		if(this->workitems[i]->code == code)
		{
			item = new WorkItem(code, this->workitems[i]->name);
			item->begin_hour = this->workitems[i]->begin_hour;
			item->begin_minute = this->workitems[i]->begin_minute;
			item->end_hour = this->workitems[i]->end_hour;
			item->end_minute = this->workitems[i]->end_minute;

			break;
		}
	}

	return item;
}

WorkItem* WorkPlanADay::GetItem(time_t now)
{
	tm tm_now;
	WorkItem* item = NULL;

	localtime_s(&tm_now, &now);

	for(int i = 0; i < this->workitems.size(); i++)
	{
		if(this->workitems[i]->begin_hour <= tm_now.tm_hour && this->workitems[i]->end_hour >= tm_now.tm_hour
			&& this->workitems[i]->begin_minute <= tm_now.tm_min && this->workitems[i]->end_minute > tm_now.tm_min)
		{
			item = new WorkItem(this->workitems[i]->code, this->workitems[i]->name);
			item->begin_hour = this->workitems[i]->begin_hour;
			item->begin_minute = this->workitems[i]->begin_minute;
			item->end_hour = this->workitems[i]->end_hour;
			item->end_minute = this->workitems[i]->end_minute;

			this->cur_index = i;
			break;
		}
	}

	return item;
}

WorkItem* WorkPlanADay::GetNext()
{
	WorkItem* item = NULL;
	
	this->cur_index++;

	while(this->cur_index < this->workitems.size())
	{
		if(this->workitems[cur_index]->code != L"D")
		{
			item = this->workitems[cur_index];
			break;
		}
		else
		{
			this->cur_index++;
		}
	}

	return item;
}

void WorkPlanADay::WorkOff()
{
	this->workitems[cur_index]->expire = true;

	//this->cur_index++;
}

bool WorkPlanADay::IsFinish()
{
	for(int i = 0; i < this->workitems.size(); i++)
	{
		if(this->workitems[i]->code != L"D")
		{
			this->expire = this->expire & this->workitems[i]->expire;
		}
	}

	return this->expire;
}