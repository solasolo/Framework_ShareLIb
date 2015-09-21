#ifndef MULTILANGUAGE_H
#define MULTILANGUAGE_H

#pragma warning(disable:4786)

#include <vector>
#include <map>
#include <string>
#include <windows.h>

using namespace std;

namespace GLEO
{
	class __declspec(dllexport) EnumTransTextCallBack
	{
	public:
		virtual void LangTrans(unsigned int id, string& text) = 0;
	};

	class __declspec(dllexport) BaseMultiLanguage
	{
	public:
		class Translator;
		friend class Translator;

	public:
		enum TransMode {Read, Write};

		typedef map<unsigned int, pair<string, string> > TransMap;

		class Translator
		{
		private:
			BaseMultiLanguage* Source;	
			string TransModule;

			TransMap* GetTransTable();

			void SetTrans(unsigned int id, string& def_txt);
			string GetTrans(unsigned int id, string& def_txt);
			void SetTrans(string& def_txt);
			string GetTrans(string& def_txt);

		public:
			Translator(BaseMultiLanguage* src, string module_name);
			Translator(const Translator& trans);
			Translator();

			Translator& operator=(Translator& trans);

			string Trans(unsigned int id, string def_txt);
			string Trans(string def_txt);

			void EnumTransText(EnumTransTextCallBack& call_back);
		};

	protected:
		string Language;
		TransMode Mode;

		map<string, TransMap> TransDict;

		Translator GetTranslator(string module_name);	

		virtual void Load() = 0;
		virtual void Save() = 0;

	public:
		BaseMultiLanguage();

		void setLanguage(string lang);
		void setMod(TransMode mod);

		BaseMultiLanguage::Translator GetTextTranslator();
		BaseMultiLanguage::Translator GetResTranslator();
		BaseMultiLanguage::Translator GetDictTranslator();
	};

	typedef BaseMultiLanguage::Translator LanguageTrans;

	class __declspec(dllexport) ResLanguage : public EnumTransTextCallBack
	{
	private:
		HWND Handle;

		void LangTrans(unsigned int id, string& text);

	public:
		void Update(BaseMultiLanguage* lang, HWND handle);
	};
}

#endif