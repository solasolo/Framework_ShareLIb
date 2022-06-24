//---------------------------------------------------------------------------
#include "stdafx.h"

#include "XMLMultiLanguage.h"

#include "WinException.h"
#include "XMLException.h"

//---------------------------------------------------------------------------
namespace Win32Lib
{
	ML_XML::ML_XML(wstring path)
	{
		DocPath = path;
		Load();
	}

	void ML_XML::LoadModule(MSXML2::IXMLDOMElementPtr& node, string name)
	{
		pair<map<string, TransMap>::iterator, bool> InsPtr;

		TransMap NullMap;

		InsPtr = TransDict.insert(pair<string, TransMap>(name.c_str(), NullMap));
		map<string, TransMap>::iterator CurMap = InsPtr.first;

		int l = node->childNodes->length;
		for(int i = 0; i < l; i++)
		{
			MSXML2::IXMLDOMElementPtr ItemNode = node->childNodes->item[i];
			MSXML2::IXMLDOMNamedNodeMapPtr NodeAttrs = ItemNode->attributes;

			MSXML2::IXMLDOMNodePtr AreaIDAttr, ChaAttr, GUIDAttr,VolAttr;
			VolAttr = NodeAttrs->getNamedItem("Volume");
			ChaAttr = NodeAttrs->getNamedItem("Chanel");
			GUIDAttr = NodeAttrs->getNamedItem("GUID");
			AreaIDAttr = NodeAttrs->getNamedItem("AreaID");

			if((bool)AreaIDAttr && (bool)ChaAttr && (bool)GUIDAttr&&(bool)VolAttr)
			{
				pair<string, string> LangText((char*)GUIDAttr->text, (char*)ChaAttr->text);
				CurMap->second.insert(pair<unsigned int, pair<string, string> >(atoi((char*)AreaIDAttr->text), LangText));
			}
		}
	}

	void ML_XML::Load()
	{
		MSXML2::IXMLDOMDocumentPtr Doc;
		HRESULT hr = Doc.CreateInstance(__uuidof(MSXML2::DOMDocument));
		WinException::COMCheck(hr, L"Create XML Document");

		if(!Doc->load( _variant_t(DocPath.c_str()) ))
		{
			throw XMLParseException(L"Load Lanuage File", Doc);
		}

		MSXML2::IXMLDOMElementPtr Root;
		Root = Doc->documentElement;

		TransDict.clear();
		int l = Root->childNodes->length;
		for(int i = 0; i < l; i++)
		{
			MSXML2::IXMLDOMElementPtr Node = Root->childNodes->item[i];

			MSXML2::IXMLDOMNodePtr ModuleName = Node->attributes->getNamedItem("Name");
			if(ModuleName)
			{
				LoadModule(Node, (char*)ModuleName->text);
			}
		}
	}

	void ML_XML::Save()
	{

	}
}

