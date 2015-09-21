#pragma once

#include "SmartADODB.h"
#include "WorkDataDef.h"

#include <vector>

using namespace ADO;
using namespace GLEO;

namespace GLEO
{
	class WorkADODB : public SimpleADODB
	{
	public:
		WorkADODB(wstring connstr);
		~WorkADODB(void);

		vector<wstring> QueryWorkGroups(wstring sql);
		wstring GetWorkPlan(time_t date);
	};
}