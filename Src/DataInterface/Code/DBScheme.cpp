//#include "stdafx.h"
#include "msxml3.h"
#include "DBScheme.h"
#include "WinException.h"
#include "CommonFuncs.h"


using namespace GLEO;
using namespace Win32Lib;

namespace MSXML2
{
	DBScheme::DBScheme(wstring file_name)
	{   
		IXMLDOMDocumentPtr doc;

		HRESULT hr = doc.CreateInstance(__uuidof(DOMDocument));
		WinException::COMCheck(hr, "Create XML Document");

		doc->load(_variant_t(file_name.c_str()));

		IXMLDOMElementPtr root;
		root = doc->documentElement;
		if(root == NULL)
			throw Exception(L"Bad File(" + file_name + L")", L"Loading Database Scheme File");

		ReadTables(root);
	}

	TableDef& DBScheme::GetTable(string table_name)
	{
		ToUpper(table_name);
		map<string, TableDef>::iterator it = TableDefs.find(table_name);
		
		if (it == TableDefs.end()) 
			throw Exception(L"Table(" + ~table_name + L") is NOT in the Database Schmem!", L"Get Table");

 		return it->second;		
	}

	FieldDef& DBScheme::GetFieldDef(string table_name, string field_name,bool& IsFound)
	{
		ToUpper(field_name);
		ToUpper(table_name);

		TableDef& td = GetTable(table_name);
		list<FieldDef>::iterator it = td.begin();		
		list<FieldDef>::iterator last = td.end();
		while(it != last)
		{
			if(it->Name == field_name) 
			{
				IsFound = true;
				break;
			}
			it++;
		}

		if(it == last) 
		{
			IsFound = false;
			throw Exception(string("Field(") + field_name + ")Not Found in Database Scheme!", "Get Field");
		}

		return *it;
	}

	void DBScheme::ReadTables(IXMLDOMNodePtr root)
	{
		MSXML2::IXMLDOMNodeListPtr l;
		l = root->childNodes;
		for(long i = 0;  i < l->length; i++)
		{
			wstring TableName;
			MSXML2::IXMLDOMNodePtr node;//读取一个表
			node = l->item[i];

			//读属性列表
			MSXML2::IXMLDOMNamedNodeMapPtr attributeMap;
			attributeMap = node->attributes;
			for(int j = 0; j < attributeMap->length; j++)
			{
				IXMLDOMNodePtr Attr;
				Attr = attributeMap->item[j];
				
				_bstr_t AttName;
				AttName = Attr->nodeName;

				if (AttName == _bstr_t(L"Name"))//比较名字是否匹配
				{
					pair<map<string, TableDef>::iterator, bool> InsPtr;	

					TableDef td;
					string TableName = (char*)(_bstr_t)Attr->nodeValue;
					ToUpper(TableName);

					InsPtr = TableDefs.insert(pair<string, TableDef>(TableName, td));

					ReadTable(node, InsPtr.first->second);
				}	
			}
		}
	}

	void DBScheme::ReadTable(MSXML2::IXMLDOMNodePtr root, list<FieldDef>& FieldList)
	{
		IXMLDOMNodeListPtr l;
		l = root->childNodes;

		//处理每一个字段
		for(long i = 0;  i < l->length; i++)
		{
			IXMLDOMNodePtr node;
			node = l->item[i];
			
			FieldDef Value;
			Value.Clear();

			//读属性列表
			IXMLDOMNamedNodeMapPtr attributeMap;
			attributeMap = node->attributes;

			// 处理字段中的每一个属性
			for(int j = 0; j < attributeMap->length; j++)
			{
				MSXML2::IXMLDOMNodePtr Attr;
				_bstr_t AttName;
				_variant_t AttVaule;

				//读第J个属性
				Attr = attributeMap->item[j];

				//读出属性的名字
				AttName = Attr->nodeName;
				AttVaule = Attr->nodeValue;

				if (AttName == _bstr_t(L"Name"))//比较名字是否匹配
				{
					Value.Name = (_bstr_t)AttVaule;
					ToUpper(Value.Name);
				}	
				else if(AttName == _bstr_t(L"Type"))
				{
					Value.SetType((char*)(_bstr_t)AttVaule);
				}
				else if(AttName == _bstr_t(L"Length"))
				{
					Value.Length = (long)AttVaule;
				}

			}
			FieldList.push_back(Value);
		} 
	}
}
