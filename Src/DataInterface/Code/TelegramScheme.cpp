//#include "stdafx.h"

#include "TelegramScheme.h"
#include "WinException.h"
#include "CommonFuncs.h"

using namespace GLEO;
using namespace Win32Lib;

//------------------------------------------------------------------------------------
namespace MSXML2
{
	TelegramScheme::TelegramScheme(wstring& file_name)
	{ 
		IsBig = false;
		IsFix = false;
		PaddingLeft = false;

		IXMLDOMDocumentPtr doc = NULL;

		HRESULT hr = doc.CreateInstance(__uuidof(DOMDocument));
		WinException::COMCheck(hr, "Create XML Document");

		VARIANT_BOOL temp =  doc->load(_variant_t(file_name.c_str()));
		if(temp != -1)
		{
			throw Exception(string("文件加载失败"), "Loading Telegram Scheme File");
		}

		IXMLDOMElementPtr root = NULL;
		root = doc->documentElement;
		if(root == NULL)
		{
			throw Exception(string("Bad File:") + ToNarrowString(file_name), "Loading Telegram Scheme File");
		}
		
		IXMLDOMNamedNodeMapPtr attributeMap = root->attributes;
		for(int j = 0; j < attributeMap->length; j++)
		{
			IXMLDOMNodePtr Attr;
			Attr = attributeMap->item[j];
				
			_bstr_t AttName;
			AttName = Attr->nodeName;
			if (AttName == _bstr_t(L"ByteOrder"))
			{
				string str = Attr->text;
				if(str == "Big")
				{
					IsBig = true;
				}
			}
			else if (AttName == _bstr_t(L"NubmerFormat"))
			{
				string str = Attr->text;
				if (str == "Fix")
				{
					IsFix = true;
				}
			}
			else if (AttName == _bstr_t(L"Padding"))
			{
				string str = Attr->text;
				if (str == "Left")
				{
					PaddingLeft = true;
				}
			}
		}

		ReadTelgrams(root);
	}

	TelegramDef& TelegramScheme::GetTelgram(string tel_name)
	{
		map<string, TelegramDef>::iterator it = ProtocolDefs.find(tel_name);
		if (it == ProtocolDefs.end()) 
		{
			string msg = "Telegram is not exist! Telegram Name: " + tel_name;
			throw exception(msg.c_str());
		}

		return it->second;		
	}

	void TelegramScheme::ReadTelgrams(IXMLDOMNodePtr root)
	{
		IXMLDOMNodeListPtr l;
		l = root->childNodes;
		for(long i = 0;  i < l->length; i++)
		{
			string TableName;
			IXMLDOMNodePtr node;//读取一个表
			node = l->item[i];

			//读属性列表
			IXMLDOMNamedNodeMapPtr attributeMap;
			attributeMap = node->attributes;
			for(int j = 0; j < attributeMap->length; j++)
			{
				IXMLDOMNodePtr Attr;
				Attr = attributeMap->item[j];
				
				_bstr_t AttName;
				AttName = Attr->nodeName;

				if (AttName == _bstr_t(L"Name"))//比较名字是否匹配
				{
					pair<map<string, TelegramDef>::iterator, bool> InsPtr;	

					TelegramDef td;
					td.Length = 0;

					string TelegramName = (char*)(_bstr_t)Attr->nodeValue;
					InsPtr = ProtocolDefs.insert(pair<string, TelegramDef>(TelegramName, td));

					ReadTelgram(node, InsPtr.first->second);
				}	
			}
		}
	}

	void TelegramScheme::ReadNode(IXMLDOMNodePtr node, FieldDef& Value)
	{
		Value.Clear();
		
		//读属性列表
		IXMLDOMNamedNodeMapPtr attributeMap;
		attributeMap = node->attributes;

		// 处理字段中的每一个属性
		for(int j = 0; j < attributeMap->length; j++)
		{
			IXMLDOMNodePtr Attr;
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
			else if(AttName == _bstr_t(L"LengthField"))
			{
				Value.RepeatCountField = (_bstr_t)AttVaule;
				ToUpper(Value.RepeatCountField);
			}
			else if(AttName == _bstr_t(L"Decimal"))
			{
				Value.Dec = (long)AttVaule;
			}
			else if(AttName == _bstr_t(L"Format"))
			{
				Value.Format = (char*)(_bstr_t)AttVaule;
			}
		}
	}

	void TelegramScheme::ReadTelgram(IXMLDOMNodePtr root, TelegramDef& defs)
	{
		FieldDef Value;

		IXMLDOMNodeListPtr l;
		l = root->childNodes;

		for(long i = 0;  i < l->length; i++)
		{
			IXMLDOMNodePtr node = l->item[i];

			ReadNode(node, Value);
			defs.FieldDefs.push_back(Value);

			if(Value.Type == FieldDef::Repeat)
			{	
				string RepeatName = Value.Name;
				int RepeatLength = Value.Length;
				vector<FieldDef> Repeater;

				IXMLDOMNodeListPtr rl;
				rl = node->childNodes;

				int SubLength = 0;
				for(long j = 0; j < rl->length; j++)
				{	
					IXMLDOMNodePtr rnode = rl->item[j];

					ReadNode(rnode, Value);
					Repeater.push_back(Value);

					SubLength += Value.Length;
				}
				
				defs.RepeatParts.insert(pair<string, vector<FieldDef> >(RepeatName, Repeater));

				defs.Length += RepeatLength * SubLength;
			}
			else
			{
				defs.Length += Value.Length;
			}
		}
	}

	vector<FieldDef>& TelegramScheme::GetRepatParts(string tel_name, string Name)
	{
		map< string, vector<FieldDef> >::iterator  v =  GetTelgram(tel_name).RepeatParts.find(Name);
		if(v == GetTelgram(tel_name).RepeatParts.end())
		{
			string msg = "Telegram is not exist! Telegram Name: " + tel_name +"RepeatParts: "+ Name;
			throw exception(msg.c_str());
		}
		return v->second;	
	}
}
