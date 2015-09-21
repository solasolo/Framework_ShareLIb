//#include "stdafx.h"

#include "SQLBuilder.h"
#include "CommonFuncs.h"
#include <sstream>

//生成SQL语句

using namespace GLEO;

SQLBuilder::SQLBuilder(DbType dbtype, wstring file_name)
{
	Scheme = NULL; 
	Scheme = new DBScheme(file_name);

	this->DBType = dbtype;
}

SQLBuilder::~SQLBuilder()
{
	DESTROY(Scheme);
}

DbType SQLBuilder::getType()
{
	return this->DBType;
}

wstring SQLBuilder::MakeValue(FieldDef& fd, CommonData2& values)
{
	wstring Result;
	string FieldName = fd.Name;

	FieldDef::FieldType Type = fd.Type;

	if(values.IsNull(FieldName))
	{
		Result = L"null";
	}
	else
	{
		variant_t v = values.getData(FieldName);
		wchar_t temp[100];
	
		switch(Type)
		{
		case FieldDef::String:
			Result = Result + L"'" + values.getWString(FieldName) + L"'";
		break;

		case FieldDef::DateTime:
			
			if(this->DBType == DbType::Oracle)
			{
				double t = values.getFloat(FieldName);
				
				Result = SQLBuilder::MakeOracleDate(t);
			}
			else if(this->DBType == DbType::MSQL)
			{			
				//转换为时间
				//wstring str = ~DateTimeFormatToCTS(t);
				//swprintf(temp, L"'%s'", str.c_str());
	
				swprintf(temp, L"%f", values.getFloat(FieldName) - 2); // DBTime = SysTime - 2 
				Result = temp;
			}			
		break;
		
		case FieldDef::Float:
			swprintf(temp, L"%f", values.getFloat(FieldName));
			Result = temp;
		break;	

		case FieldDef::Int:
			swprintf(temp, L"%d", values.getInt(FieldName));
			Result = temp;
		break;

		default:
			Result = values.getWString(FieldName);
		break;
		}
	}

	return Result;
}

wstring SQLBuilder::MakeCondition(string table_name, CommonData2& values)
{
	bool IsFound = false;;
	bool First = true;
	wostringstream buffer;

	if(&values == NULL)
	{
		return buffer.str();
	}

	vector<string> temp = values.getFiledNames();
	int FiledIndex = 0;

	if(temp.size() > 0)
	{
		buffer << " where ";

		do
		{
  			if(!First) buffer << " and ";

			string FieldName = temp[FiledIndex];
			FieldDef& fd = Scheme->GetFieldDef(table_name, FieldName, IsFound);

			if(IsFound == false)
			{
				FiledIndex = FiledIndex + 1;
				continue;
			}

			variant_t v = values.getData(FieldName);
			if(GLEO::IsEmpty(v) || GLEO::IsNull(v))
			{
				buffer << ~FieldName << L" is null";
			}
			else
			{
				buffer << ~FieldName << L"=" << MakeValue(fd, values);
			}
			FiledIndex = FiledIndex + 1;
			First = false;
		}
		while(FiledIndex < temp.size());//(values.NextItem());
	}

	return buffer.str();
}

wstring SQLBuilder::MakeNullSelect(string table_name, CommonData2& conds)
{
	wostringstream buffer;
    
	list<FieldDef>& fds = Scheme->GetTable(table_name);
	list<FieldDef>::iterator b = fds.begin();

	buffer << L"select NULL ";
	buffer << L"from " << ~table_name;
	buffer << MakeCondition(table_name, conds);

	return buffer.str();	
}

wstring SQLBuilder::MakeSelect(string table_name, CommonData2& conds)       
{
	wostringstream buffer;
    
	list<FieldDef>& fds = Scheme->GetTable(table_name);
	list<FieldDef>::iterator b = fds.begin();

	buffer << "select ";
	while(b != fds.end())
	{
        if(b != fds.begin()) buffer << ",";
        buffer << b->Name.c_str();
		b++;
	}
	buffer << L" from " << ~table_name;
	buffer << MakeCondition(table_name, conds);

	return buffer.str();	
}


wstring SQLBuilder::MakeInsert(string table_name, CommonData2& values)       
{
	bool FirstItem;

	list<FieldDef>& fds = Scheme->GetTable(table_name);
	
	FirstItem = true;
	wstring FieldsBuffer = L"";
	list<FieldDef>::iterator b;
	b = fds.begin();    
    while(b != fds.end())
	{
		string FielsdName = b->Name;
		if(values.Has(FielsdName))
		{
			if(!FirstItem) FieldsBuffer += L",";
			FieldsBuffer += ~b->Name;
			
			FirstItem = false;
		}

		b++;
	}

	FirstItem = true;
  	wstring ValueBuffer = L"";
	b = fds.begin();    
	while(b != fds.end())
	{
		string FielsdName = b->Name;

		if(values.Has(FielsdName))
		{
			wstring ValueString = MakeValue(*b, values);	
			if(ValueString != L"")
			{
				if(!FirstItem)
				{
					ValueBuffer += L",";
				}

				ValueBuffer += ValueString;
	
				FirstItem = false;
			}
			else
			{
				ValueBuffer += L"null";
			}
		}

		b++;
	}

	wostringstream buffer;
    buffer << L"insert into "<< table_name.c_str() << L" (" << FieldsBuffer << L") values (" << ValueBuffer << L")";
	
	return buffer.str();	
}

wstring SQLBuilder::MakeDelete(string table_name, CommonData2& conds)        // Delete
{
	wostringstream buffer;

	buffer << L"delete from " << ~table_name;
	buffer << MakeCondition(table_name, conds);
 
	return buffer.str();	
}


wstring SQLBuilder::MakeUpdate(string table_name, CommonData2& values, CommonData2& conds)         // Update
{
	bool FirstItem;
	wostringstream buffer;

	buffer << L"update ";
	buffer << ~table_name;
    buffer << L" set ";

	FirstItem = true;
	list<FieldDef>& fds = Scheme->GetTable(table_name);
	list<FieldDef>::iterator b = fds.begin();
	while(b != fds.end())
	{
		string FielsdName = b->Name;

		if(values.Has(FielsdName))
		{
			if(!FirstItem) buffer << ",";

			buffer << b->Name.c_str() << "=";
			buffer << MakeValue(*b, values);      

			FirstItem = false;
		}

		b++;
	}
	
	buffer << MakeCondition(table_name, conds);

	return buffer.str();	
}

wstring SQLBuilder::MakeOracleDate(double time)
{
	wstring Result;

	//转换为时间
	wstring str = ~DateTimeToCTS(time);
	
	Result = L"to_date('" + str + L"', 'yyyyMMddhh24miss')";

	return Result;
}
