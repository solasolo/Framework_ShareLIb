#ifndef DBSCHEME_H
#define DBSCHEME_H

#pragma warning(disable:4786)

#include <list>
#include <map>
#include <string>
#include <strstream>

#include "CommonDataDef.h"
#include "msxml3.h"

using namespace std;

typedef list<FieldDef> TableDef;

namespace MSXML2
{
	class DBScheme
	{
	private:
		map<string, TableDef> TableDefs;

		void ReadTables(IXMLDOMNodePtr root);
		void ReadTable(IXMLDOMNodePtr root, TableDef& FieldList);

	public:
		DBScheme(wstring file_name);

		TableDef& GetTable(string table_name);
		FieldDef& GetFieldDef(string table_name, string field_name,bool& IsFound);
	};
}

#endif