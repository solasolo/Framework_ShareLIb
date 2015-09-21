//---------------------------------------------------------------------------
#pragma hdrstop

#include "XMLConfig.h"
#include "WinException.h"
#include "XMLException.h"

using namespace Win32Lib;

//---------------------------------------------------------------------------
namespace Win32Lib
{
	XMLConfig::XMLConfig(wstring path)
		: XMLReader()
	{
		Load(path);
	}

	void XMLConfig::Load(wstring path)
	{
		XMLReader::Load(path);

		this->Items.clear();
		this->Load(this->RootNode, "");
	}

	void XMLConfig::Load(MSXML2::IXMLDOMElementPtr node, string prefix)
	{
		if(node->hasChildNodes())
		{
			int l = node->childNodes->length;
			for(int i = 0; i < l; i++)
			{
				MSXML2::IXMLDOMElementPtr SubNode = node->childNodes->item[i];

				if(SubNode)
				{
					if(SubNode->childNodes->length > 0)
					{
						string Name;
						if(prefix == "")
							Name = SubNode->tagName;
						else
							Name = prefix + "." + (char*)SubNode->tagName;

						Load(SubNode, Name);
					}
					else
					{
						Items.insert(pair<string, string>((char*)SubNode->tagName, (char*)SubNode->text));
					}
				}
				else
				{
					Items.insert(pair<string, string>(prefix, (char*)node->text));
				}
			}
		}
		else
			Items.insert(pair<string, string>(prefix, (char*)node->text));

	}


	string XMLConfig::getString(string name)
	{
		string Result = "";

		map<string, string>::iterator it;
		map<string, string>::iterator last;

		it = Items.find((string)name);
		last = Items.end();

		if(it != last) Result = it->second;

		return Result;
	}

	wstring XMLConfig::getWString(string name)
	{
		return ToWideString(getString(name));
	}

	int XMLConfig::getInt(string name)
	{
		int Result = 0;

		string s = getString(name);
		if(s != "") Result = atoi(s.c_str());

		return Result;
	}

	map<string, string>& XMLConfig::getItems()
	{
		return Items;
	}
}
