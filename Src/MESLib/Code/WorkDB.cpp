#include "WorkDB.h"
#include "WinException.h"


using namespace Win32Lib;
using namespace GLEO;

WorkADODB::WorkADODB(wstring connstr)
	: SimpleADODB(connstr)
{
}

WorkADODB::~WorkADODB()
{
}

vector<wstring> WorkADODB::QueryWorkGroups(wstring sql)
{
	vector<wstring> groups;

	_RecordsetPtr ds = this->DoQuery(sql);

	while(!ds->adoEOF)
	{
		bstr_t name = ds->GetCollect("code");

		groups.push_back((wstring)(wchar_t*)name);

		ds->MoveNext();
	}

	return groups;
}

wstring WorkADODB::GetWorkPlan(time_t date)
{
	tm tm_date;
	wstring plan = L"";

	localtime_s(&tm_date, &date);

	wchar_t buf[100];
	wsprintf(buf, L"select work_plan from workplan where work_date ='%d-%d-%d'", tm_date.tm_year+1900, tm_date.tm_mon+1, tm_date.tm_mday);

	//cmd->CommandText = L"select work_plan from workplan where work_date = :workdate";

	//this->AddParameter(_bstr_t("workdate"), DataTypeEnum::adVarChar, 10, (_bstr_t)date_s.c_str(), cmd);	// ÎÞÐ§???

	_RecordsetPtr ds = this->DoQuery(wstring(buf));

	if(!ds->adoEOF)
	{
		_variant_t  _plan = ds->GetCollect("Work_Plan");

		bstr_t b_plan = (bstr_t)_plan;

		//bstr_t b_plan = ds->Fields->Item["Work_Plan"]->Value;

		plan = (wstring)(wchar_t*)b_plan;
	}

	return plan;
}