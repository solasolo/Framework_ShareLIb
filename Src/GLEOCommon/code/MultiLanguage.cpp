#include "MultiLanguage.h"
#include "WinException.h"

#include<Windows.h>

using namespace Win32Lib;

namespace GLEO
{
	BaseMultiLanguage::Translator::Translator()
	{
		Source = NULL;
		TransModule = "";
	}

	BaseMultiLanguage::Translator::Translator(BaseMultiLanguage* src, string module_name)
	{
		Source = src;
		TransModule = module_name;
	}

	BaseMultiLanguage::Translator::Translator(const BaseMultiLanguage::Translator& trans)
	{
		Source = trans.Source;
		TransModule = trans.TransModule;
	}

	BaseMultiLanguage::Translator& BaseMultiLanguage::Translator::operator=(BaseMultiLanguage::Translator& trans)
	{
		Source = trans.Source;
		TransModule = trans.TransModule;

		return *this;
	}

	BaseMultiLanguage::TransMap* BaseMultiLanguage::Translator::GetTransTable()
	{
		TransMap* Result = NULL;

		if(Source)
		{
			map<string, TransMap>::iterator it;
			it = Source->TransDict.find(TransModule);
			if(it != Source->TransDict.end())
			{
				Result = &(it->second);
			}
		}

		return Result;
	}

	string BaseMultiLanguage::Translator::Trans(unsigned int id, string def_txt)
	{
		string Result;

		switch(Source->Mode)
		{
		case BaseMultiLanguage::Read:
			Result = GetTrans(id, def_txt);	
		break;

		case BaseMultiLanguage::Write:
			SetTrans(id, def_txt);
			Result = def_txt;
		break;
		}

		return Result; 
	}

	string BaseMultiLanguage::Translator::Trans(string def_txt)
	{
		string Result;

		switch(Source->Mode)
		{
		case BaseMultiLanguage::Read:
			Result = GetTrans(def_txt);	
		break;

		case BaseMultiLanguage::Write:
			SetTrans(def_txt);
			Result = def_txt;
		break;
		}

		return Result; 
	}

	void BaseMultiLanguage::Translator::SetTrans(unsigned int id, string& def_txt)
	{
		TransMap* TransTable;

		TransTable = GetTransTable();
		if(TransTable)
		{
			TransMap::iterator it;
			it = TransTable->find(id);
			if(it != TransTable->end())
			{
				it->second.second = def_txt;
			}
			else
			{
				TransTable->insert( pair<int, pair<string, string> >(id, pair<string, string>(def_txt, "")) );
			}
		}
	}

	string BaseMultiLanguage::Translator::GetTrans(unsigned int id, string& def_txt)
	{
		string Result;
		TransMap* TransTable;

		TransTable = GetTransTable();
		if(TransTable)
		{
			TransMap::iterator it;
			it = TransTable->find(id);
			if(it != TransTable->end())
			{
				Result = it->second.second;
			}
			else
			{
				Result = def_txt;
			}
		}
		else
		{
			Result = def_txt;
		}

		return Result;
	}

	void BaseMultiLanguage::Translator::SetTrans(string& def_txt)
	{
//		TransMap* TransTable;
//
//		TransTable = GetTransTable();
//		if(TransTable)
//		{
//			TransMap::iterator it = TransTable->begin();
//			while(it != TransTable->end())
//			{
//				if(it->second.first == def_txt) break;
//				it++;
//			}
//
//			if(it != TransTable->end())
//			{
//				it->second.second = def_txt;
//			}
//			else
//			{
//				TransTable->insert( pair<int, pair<string, string> >(id, pair<string, string>(def_txt, "")) );
//			}
//		}
	}

	string BaseMultiLanguage::Translator::GetTrans(string& def_txt)
	{
		string Result;
		TransMap* TransTable;

		TransTable = GetTransTable();
		if(TransTable)
		{
			TransMap::iterator it = TransTable->begin();
			while(it != TransTable->end())
			{
				if(it->second.first == def_txt) break;
				it++;
			}

			if(it != TransTable->end())
			{
				Result = it->second.second;
			}
			else
			{
				Result = def_txt;
			}
		}
		else
		{
			Result = def_txt;
		}

		return Result;
	}

	void BaseMultiLanguage::Translator::EnumTransText(EnumTransTextCallBack& call_back)
	{
		TransMap* TransTable;
		TransTable = GetTransTable();

		if(TransTable)
		{
			TransMap::iterator it;
			it = TransTable->begin();
			while(it != TransTable->end())
			{
				call_back.LangTrans(it->first, it->second.second);

				it++;
			}
		}
	}

	//----------------------------------------------------------------------------
	// BaseMultiLanguage
	//
	BaseMultiLanguage::BaseMultiLanguage()
	{
		Language = "Default";
		Mode = Read;
	}

	void BaseMultiLanguage::setLanguage(string lang)
	{
		Language = lang;
		Load();
	}

	void BaseMultiLanguage::setMod(TransMode mod)
	{
		Mode = mod;
	}

	BaseMultiLanguage::Translator BaseMultiLanguage::GetTranslator(string module_name)
	{
		return Translator(this, module_name);
	}

	BaseMultiLanguage::Translator BaseMultiLanguage::GetTextTranslator()
	{
		return GetTranslator("Text");
	}

	BaseMultiLanguage::Translator BaseMultiLanguage::GetResTranslator()
	{
		return GetTranslator("Resource");
	}

	BaseMultiLanguage::Translator BaseMultiLanguage::GetDictTranslator()
	{
		return GetTranslator("Dictionary");
	}
}


//----------------------------------------------------------------------------
namespace GLEO
{
	void ResLanguage::Update(BaseMultiLanguage* lang, HWND handle)
	{
		Handle = handle;

		LanguageTrans trans = lang->GetResTranslator();
		trans.EnumTransText(*this);
	}

	void ResLanguage::LangTrans(unsigned int id, string& text)
	{
		SendDlgItemMessage(Handle, id, WM_SETTEXT, 0, (LPARAM)text.c_str());
	}
}