#include "MESBaseADODB.h"

#include "CoilCalculator.h"


MesBaseADO::MesBaseADO(wstring con_str, DbType dbtype, wstring scheme_path)
	: ADODB(con_str, dbtype, scheme_path)
{
}

MesBaseADO::MesBaseADO(wstring con_str, SmartPointer<SQLBuilder> builder)
	: ADODB(con_str, builder)
{
}

MesBaseADO::~MesBaseADO()
{
}

void MesBaseADO::LoadAlarmDefines(map<string, AlarmDefine>& defs)
{
	wstring sql = L"select * from ALERT_INFO";
	defs.clear();

	_RecordsetPtr rs = this->DoQuery(sql);
	if( !(rs->adoEOF && rs->BOF) )
	{
		rs->MoveFirst();
		while(!rs->adoEOF)
		{			
			FieldsPtr all = rs->Fields;

			AlarmDefine def;

			def.Code = ToString(all->Item[L"ALERT_NO"]->Value);
			variant_t msg = all->Item[L"FORMAT_INFO_ENGLISH"]->Value;
			def.Message = ToWString(msg);
			def.Type = (AlarmType)ToLong(all->Item[L"ALERT_TYPE"]->Value);

			defs.insert(pair<string, AlarmDefine>(def.Code, def));

			rs->MoveNext();
		}
	}
}

void MesBaseADO::RecordAlarm(string code, wstring param)
{
	wchar_t buf[500];

	switch(this->DBType)
	{
	case DbType::MSQL:
		swprintf_s(buf, L"insert into ALERT_HISTORY(ALERT_NO, ALERT_PARA, ALERT_TIME) values('%s', '%s', getdate())",  (~code).c_str(), param.c_str());
		break;

	case DbType::Oracle:
		swprintf_s(buf, L"insert into ALERT_HISTORY(ALERT_NO, ALERT_PARA, ALERT_TIME) values('%s', '%s', sysdate)",  (~code).c_str(), param.c_str());
		break;
	}

	this->DoNonQuery(wstring(buf));
}

//-------------------------------------------------------------------------------------

#pragma region 

wstring UngererADO::DBString = L"";
SmartPointer<SQLBuilder> UngererADO::DBScheme = NULL;

string UngererADO::weight[10] = {"dblKom_Gewicht_1", "dblKom_Gewicht_2", "dblKom_Gewicht_3", "dblKom_Gewicht_4", "dblKom_Gewicht_5", "dblKom_Gewicht_6", "dblKom_Gewicht_7", "dblKom_Gewicht_8", "dblKom_Gewicht_9", "dblKom_Gewicht_10"};
string UngererADO::length[10] = {"dblKom_Laenge_1", "dblKom_Laenge_2", "dblKom_Laenge_3", "dblKom_Laenge_4", "dblKom_Laenge_5", "dblKom_Laenge_6", "dblKom_Laenge_7", "dblKom_Laenge_8", "dblKom_Laenge_9", "dblKom_Laenge_10"};

string UngererADO::DefaultSetup = "Default";
string UngererADO::DefaultMaterial = "Default";


void UngererADO::Init(wstring conn_str, wstring scheme_path, string setup, string material)
{
	UngererADO::DBString = conn_str;
	UngererADO::DBScheme = new SQLBuilder(DbType::MSQL, scheme_path);
	UngererADO::DefaultMaterial = material;
	UngererADO::DefaultSetup = setup;
}

UngererADO::UngererADO()
	: ADODB(UngererADO::DBString, UngererADO::DBScheme)
{
	this->SetCallBack(this);
}

void UngererADO::MakeUngererData(CommonData2& data, BaseCoilParams& params)
{
}

int UngererADO::GetQueuedJobNumber()
{
	int Result = 0;

	CommonDataList data = this->SelectBySql(L"select count(lngPosition) as c from tblAuftrag where lngPosition >= 0");
	if (data.NextRow())
	{
		Result = data.getInt("c");
	}

	Result = (Result < 0) ? 0 : Result + 1;

	return Result;
}

bool UngererADO::CheckAuftragUndo(string coilid) 
{
	bool Result;

	wstring sql = L"select null from tblAuftrag where lngPosition >= 0 and strCoilnummer='" + ~coilid + L"'";
	CommonDataList data = this->SelectBySql(sql);

	Result = !data.IsEmpty();

	return Result;
}

void UngererADO::SaveTblAuftrag(CommonData2& data)
{
	char buf[50];

	DATE now = Now();
	string MateralName = DefaultMaterial;
	CommonData2 UNGERdata;
	BaseCoilParams Params;

	for(int i = 0; i < 10; i++)
	{
		Params.ExitWeight[i] = 0;
		Params.ExitLength[i] = 0;
	}
	this->MakeUngererData(data, Params);

	if(!this->CheckMateral(MateralName)) MateralName = DefaultMaterial;

	SYSTEMTIME NowStruct;
	GetSystemTime(&NowStruct);
	sprintf_s(buf, 30, "%04d%02d%02d%02d%02d%02d%03d"
			, NowStruct.wYear
			, NowStruct.wMonth
			, NowStruct.wDay
			, NowStruct.wHour
			, NowStruct.wMinute
			, NowStruct.wSecond
			, NowStruct.wMilliseconds
			);
	string Name = buf;

	//sprintf_s(buf, 50, "%fx%d", Params.EntryThickness, (int)Params.EntryWidth);
	stringstream ss;
	ss << Params.EntryThickness << "x" << (int)Params.EntryWidth;
	string Ricip = ss.str();

	if(!this->CheckRichtplan(Ricip)) Ricip = DefaultSetup;

	UNGERdata.setString("strMaterialname", MateralName);
	UNGERdata.setString("strCoilnummer", Params.CoilID);
	UNGERdata.setFloat("dblDicke", Params.ExitThickness);
	UNGERdata.setInt("dblCoilbreite", Params.EntryWidth);
	UNGERdata.setInt("dblMaterialbreite", Params.ExitWidth);
	UNGERdata.setInt("dblHuelsenDMABH", Params.InnerDiameter);
	UNGERdata.setInt("dblHuelsenDMAUFH", Params.OuterDiameter);
	UNGERdata.setInt("binBesaeumen", Params.EntryWidth - Params.ExitWidth >= 10);
	UNGERdata.setString("strKunde", "Default");
	UNGERdata.setString("strRichtplanname", Ricip);
	UNGERdata.setInt("dblLaenge", Params.EntryLength);

	UNGERdata.setInt("binPapierABH", 0);
	UNGERdata.setInt("binPapierAUFH", 0);
	UNGERdata.setFloat("binAbwickelnVonUnten", 0);
	UNGERdata.setFloat("dtmAuftragseingabe", now);
	UNGERdata.setNull("dtmAuftragsstart");
	UNGERdata.setNull("dtmAuftragsende");
	UNGERdata.setInt("strBediener", 0);
	UNGERdata.setInt("lngGesamtstueckzahl", 0);
	UNGERdata.setInt("lngStueckProStapel", 0);
	UNGERdata.setInt("lngGesamtgewicht", 0);
	UNGERdata.setInt("lngGewichtProStapel", 0);
	UNGERdata.setInt("lngAnzPaletten", 0);
	UNGERdata.setInt("lngStoppmodus", 0);
	UNGERdata.setInt("binEinblockmodus", 0);
	UNGERdata.setInt("binAufwickelnVonUnten", 0);
	UNGERdata.setInt("bin2A_Aussortieren", 0);
	UNGERdata.setInt("binUeberlaenge", 0);

	UNGERdata.setInt("binKommissionieren", Params.CoilCount);

	for (int i = 0; i < 10; i++)
	{
		UNGERdata.setInt(weight[i], Params.ExitWeight[i]);
		UNGERdata.setInt(length[i], Params.ExitLength[i]);
	}

	CommonData2 cond;
	cond.setString("strCoilnummer", Params.CoilID);

	if (!this->CheckAuftragUndo(Params.CoilID))
	{
		UNGERdata.setString("strName", Name);
		UNGERdata.setInt("lngPosition", this->GetLastSn());
		this->Insert("tblAuftrag", UNGERdata);
	}
	else
	{
		if (!this->Update("tblAuftrag", UNGERdata, cond))
		{
			UNGERdata.setString("strName", Name);
			UNGERdata.setInt("lngPosition", this->GetLastSn());
			this->Insert("tblAuftrag", UNGERdata);
		}
	}

}

void UngererADO::RemoveAuftrag(wstring coilid)
{
	wstring sql = L"delete from tblAuftrag where lngPosition >= 0 and strCoilnummer='" + coilid + L"'";

	this->DoNonQuery(sql);	
}

CommonDataList UngererADO::GetFinishedJob()
{
	return this->SelectBySql(L"select strCoilnummer from tblAuftrag where lngPosition = -4096"); 
}

string UngererADO::GetRunningCoilID()
{
	string Result = "";

	CommonData2 data = this->SelectTopBySql(L"select strCoilnummer from tblAuftrag where lngPosition = -1024");
	if (!data.IsEmpty())
	{
		Result = data.getString("strCoilnummer");
	}

	return Result;
}

int UngererADO::GetLastSn()
{
	int Result = 0;

	CommonDataList data = this->SelectBySql(L"select max(lngPosition) as max from tblAuftrag");
	if(data.NextRow())
	{
		Result = data.getInt("max");
	}

	Result = (Result < 0) ? 0 : Result + 1;

	return Result;
}

bool UngererADO::CheckMateral(string name)
{
	bool Result = false;

	CommonDataList data = this->SelectBySql(L"select NULL from tblMaterial where strName='" + ~name + L"'");
	if(data.NextRow())
	{
		Result = true;
	}

	return Result;
}

bool UngererADO::CheckRichtplan(string name)
{
	bool Result = false;

	CommonDataList data = this->SelectBySql(L"select NULL from tblRichtplan where strName='" + ~name + L"'");
	if(data.NextRow())
	{
		Result = true;
	}

	return Result;
}

#pragma endregion