#pragma once

#include "SmartADODB.h"
#include "ISender.h"


class __declspec(dllexport) MesBaseADO : public ADODB, public IAlarmDB
{
protected:
	virtual void LoadAlarmDefines(map<string, AlarmDefine>& defs);
	virtual void RecordAlarm(string code, wstring param);

public:
	MesBaseADO(wstring con_str, DbType dbtype, wstring scheme_path);
	MesBaseADO(wstring con_str, SmartPointer<SQLBuilder> builder);
	~MesBaseADO();
};

class __declspec(dllexport) UngererADO : public ADODB, public EventCallBack
{
private:
	int GetLastSn();
	bool CheckMateral(string name);
	bool CheckRichtplan(string name);

protected:
	struct BaseCoilParams
	{
		string CoilID;
		string MateralName;
		int CoilCount;

		float SpecWeight; 
		float EntryLength;
		float EntryWidth;
		float EntryThickness;
		float EntryWeight;
		float ExitWidth;
		float ExitThickness;
		int OuterDiameter;
		int InnerDiameter;

		float ExitWeight[10];
		float ExitLength[10];
	};

	static string weight[10];
	static string length[10];

	static wstring DBString;
	static SmartPointer<SQLBuilder> DBScheme;
	static string DefaultSetup;
	static string DefaultMaterial;

	virtual void MakeUngererData(CommonData2& data, BaseCoilParams& params);
	bool CheckAuftragUndo(string coilid);

public:

	static void Init(wstring conn_str, wstring scheme_path, string setup = "Default", string material = "Default");

	UngererADO();

	int GetQueuedJobNumber();
	void SaveTblAuftrag(CommonData2& data);
	CommonDataList GetFinishedJob();
	string GetRunningCoilID();
	void RemoveAuftrag(wstring coilid);
};
