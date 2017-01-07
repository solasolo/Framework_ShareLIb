#ifndef TELEGRAMSCHEME_H
#define TELEGRAMSCHEME_H

#pragma warning(disable:4786)

#include <vector>
#include <map>
#include <string>
#include <strstream>

#include "CommonDataDef.h" 
#include "msxml3.h"

using namespace std;
using namespace MSXML2; 

struct TelegramDef
{
	int Length;
	bool VariableLength;

	vector<FieldDef> FieldDefs;
	map< string, vector<FieldDef> > RepeatParts;
};

namespace MSXML2
{
	class TelegramScheme
	{
	private:
		map<string, TelegramDef> ProtocolDefs;

		void ReadTelgrams(IXMLDOMNodePtr root);
		void ReadNode(IXMLDOMNodePtr node, FieldDef& Value);
		void ReadTelgram(IXMLDOMNodePtr root, TelegramDef& FieldList);

	public:
		bool IsBig;
		bool IsFix;
		bool PaddingLeft;

		TelegramScheme(wstring& file_name);

		TelegramDef& GetTelgram(string tel_name);
		vector<FieldDef>& GetRepatParts(string tel_name,string Name);
	};
}

#endif