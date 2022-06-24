#include "stdafx.h"

#include "XMLReader.h"

using namespace GLEO;
using namespace Win32Lib;

namespace GLEO
{
	XMLReader::XMLReader()
	{
	}

	XMLReader::XMLReader(wstring file_path)
	{
		this->Load(file_path); 
	}

	void XMLReader::Load(wstring file_path)
	{
		HRESULT hr = this->Doc.CreateInstance(__uuidof(MSXML2::DOMDocument));
		WinException::COMCheck(hr, L"Create XML Document");

		if(!this->Doc->load(_variant_t(file_path.c_str())))
		{
			throw XMLParseException(wstring(L"Load XML:") + file_path, this->Doc);
		}

		this->RootNode = this->Doc->documentElement;
		if(this->RootNode == NULL)
		{
			throw Exception(L"Bad File:" + file_path, L"Loading XML File");
		}
	}

	void XMLReader::LoadXML(wstring doc_str)
	{
		if(!doc_str.empty())
		{
			HRESULT hr = this->Doc.CreateInstance(__uuidof(MSXML2::DOMDocument));
			WinException::COMCheck(hr, L"Create XmlDocument");
			this->Doc->loadXML((bstr_t)doc_str.c_str());

			RootNode = this->Doc->documentElement;
			if(RootNode == NULL)
			{
				throw Exception(L"Config Content is NULL", L"LoadXML Configuration Content");
			}
		}
		else
		{
			throw Exception(L"Empty Doc Content", L"Load XML"); 
		}
	} 

	void XMLReader::Load(MSXML2::IXMLDOMNodePtr node)
	{
		if(node)
		{
			this->RootNode = node;
			this->Doc = node->ownerDocument;
		}
		else
		{
			this->RootNode = NULL;
			this->Doc = NULL;
		}
	}

	MSXML2::IXMLDOMNodePtr XMLReader::GetRoot()
	{
		return this->RootNode; 
	}

	MSXML2::IXMLDOMAttributePtr XMLReader::GetAttribute(MSXML2::IXMLDOMNodePtr node, wstring name)
	{
		MSXML2::IXMLDOMAttributePtr Result;

		Result = node->attributes->getNamedItem(bstr_t(name.c_str()));

		return Result;
	}

	wstring XMLReader::GetNodeString(MSXML2::IXMLDOMNodePtr node)
	{
		return (wchar_t*)node->text;
	}

	int XMLReader::GetNodeInt(MSXML2::IXMLDOMNodePtr node)
	{
		wstring AttText = GetNodeString(node);

		return _wtoi(AttText.c_str());
	}

	double XMLReader::GetNodeFloat(MSXML2::IXMLDOMNodePtr node)
	{
		wstring AttText = GetNodeString(node);

		return _wtof(AttText.c_str());
	}

	wstring XMLReader::GetNodeString(wstring path)
	{
		MSXML2::IXMLDOMNodePtr Node = this->SelectNode(path);

		return (wchar_t*)Node->text;
	}

	int XMLReader::GetNodeInt(wstring path)
	{
		wstring AttText = this->GetNodeString(path);

		return _wtoi(AttText.c_str());
	}

	double XMLReader::GetNodeFloat(wstring path)
	{
		wstring AttText = this->GetNodeString(path);

		return _wtof(AttText.c_str());
	}

	wstring XMLReader::GetAttributeString(MSXML2::IXMLDOMNodePtr node, wstring name)
	{
		wstring Result;

		MSXML2::IXMLDOMAttributePtr Attr = NULL;

		Attr = node->attributes->getNamedItem(bstr_t(name.c_str()));
		if(Attr)
		{
			Result = (wchar_t*)(bstr_t)Attr->value;
		}
		else
		{
			throw Exception(wstring(L"NO XML Attribute:") + name, L"Get XML Attribute");
		}

		return Result;
	}

	wstring XMLReader::ReadAttributeString(MSXML2::IXMLDOMNodePtr node, wstring name)
	{
		wstring Result;

		MSXML2::IXMLDOMAttributePtr Attr = NULL;

		Attr = node->attributes->getNamedItem(bstr_t(name.c_str()));
		if (Attr)
		{
			Result = (wchar_t*)(bstr_t)Attr->value;
		}

		return Result;
	}

	int XMLReader::GetAttributeInt(MSXML2::IXMLDOMNodePtr node, wstring name)
	{
		wstring AttText = XMLReader::GetAttributeString(node, name);

		return _wtoi(AttText.c_str());
	}

	double XMLReader::GetAttributeFloat(MSXML2::IXMLDOMNodePtr node, wstring name)
	{
		wstring AttText = XMLReader::GetAttributeString(node, name);

		return _wtof(AttText.c_str());
	}

	wstring XMLReader::GetAttributeString(wstring path, wstring name)
	{
		MSXML2::IXMLDOMNodePtr Node = this->SelectNode(path);

		return this->GetAttributeString(Node, name);
	}

	int XMLReader::GetAttributeInt(wstring path, wstring name)
	{
		wstring AttText = this->GetAttributeString(path, name);

		return _wtoi(AttText.c_str());
	}

	double XMLReader::GetAttributeFloat(wstring path, wstring name)
	{
		wstring AttText = this->GetAttributeString(path, name);

		return _wtof(AttText.c_str());
	}

	void XMLReader::GetChildNodes(wstring nodePath, vector<MSXML2::IXMLDOMNodePtr>& list)
	{
		MSXML2::IXMLDOMNodePtr parent = this->SelectNode(nodePath);

		if(parent && parent->hasChildNodes())
		{
			int len = parent->childNodes->length;
			for(int i = 0; i < len; i++)
			{
				MSXML2::IXMLDOMNodePtr node = parent->childNodes->item[i];
				list.push_back(node);
			}
		}
	}

	void XMLReader::GetChildNodes(MSXML2::IXMLDOMNodePtr parentNode, vector<MSXML2::IXMLDOMNodePtr>& list)
	{
		if(parentNode->hasChildNodes())
		{
			int len = parentNode->childNodes->length;
			for(int i = 0; i < len; i++)
			{
				MSXML2::IXMLDOMNodePtr node = parentNode->childNodes->item[i];
				list.push_back(node);
			}
		}
	}

	MSXML2::IXMLDOMNodePtr XMLReader::SelectNode(wstring nodePath)
	{
		MSXML2::IXMLDOMNodePtr node;
		_bstr_t path = (bstr_t)nodePath.c_str();

		node = this->Doc->selectSingleNode(path); 

		return node;
	}

	void XMLReader::SelectNodes(wstring nodePath, vector<MSXML2::IXMLDOMNodePtr>& list)
	{
		list.clear();

		_bstr_t path = (bstr_t)nodePath.c_str();
		MSXML2::IXMLDOMNodeListPtr nodes = this->Doc->selectNodes(path);

		for(int i = 0; i < nodes->length; i++)
		{
			list.push_back(nodes->item[i]); 
		}
	}

	MSXML2::IXMLDOMNodePtr XMLReader::SelectNode(MSXML2::IXMLDOMNodePtr target, wstring nodePath)
	{
		MSXML2::IXMLDOMNodePtr node;
		if(target)
		{
			_bstr_t path = (bstr_t)nodePath.c_str();
			node = (MSXML2::IXMLDOMNodePtr)target->selectSingleNode(path);
		}
		return node;
	}
}
