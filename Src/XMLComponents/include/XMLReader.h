#pragma once

#include "string"
#include "msxml3.h"
#include <vector>

#include "BaseException.h"
#include "WinException.h"
#include "XMLException.h"

using namespace std;

namespace GLEO
{
	class _declspec(dllexport) XMLReader
	{
	protected:
		MSXML2::IXMLDOMDocumentPtr Doc;
		MSXML2::IXMLDOMNodePtr RootNode;

		static MSXML2::IXMLDOMAttributePtr GetAttribute(MSXML2::IXMLDOMNodePtr node, wstring name);

	public:
		static wstring GetAttributeString(MSXML2::IXMLDOMNodePtr node, wstring name);
		static int GetAttributeInt(MSXML2::IXMLDOMNodePtr node, wstring name);
		static double GetAttributeFloat(MSXML2::IXMLDOMNodePtr node, wstring name);

		static wstring GetNodeString(MSXML2::IXMLDOMNodePtr node);
		static int GetNodeInt(MSXML2::IXMLDOMNodePtr node);
		static double GetNodeFloat(MSXML2::IXMLDOMNodePtr node);

		static void GetChildNodes(MSXML2::IXMLDOMNodePtr parentNode, vector<MSXML2::IXMLDOMNodePtr>& list);
		static MSXML2::IXMLDOMNodePtr SelectNode(MSXML2::IXMLDOMNodePtr node, wstring nodePath);

		XMLReader();
		XMLReader(wstring file_path);

		void Load(wstring file_path);
		void Load(MSXML2::IXMLDOMNodePtr node);
		void LoadXML(wstring doc_str);

		MSXML2::IXMLDOMNodePtr GetRoot();

		wstring GetNodeString(wstring path);
		int GetNodeInt(wstring path);
		double GetNodeFloat(wstring path);

		wstring GetAttributeString(wstring path, wstring name);
		int GetAttributeInt(wstring path, wstring name);
		double GetAttributeFloat(wstring path, wstring name);

		MSXML2::IXMLDOMNodePtr SelectNode(wstring nodePath);
		void SelectNodes(wstring nodePath, vector<MSXML2::IXMLDOMNodePtr>& list);

		void GetChildNodes(wstring nodePath, vector<MSXML2::IXMLDOMNodePtr>& list);
	};
}