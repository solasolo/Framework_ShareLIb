//---------------------------------------------------------------------------

#ifndef XMLConfigH
#define XMLConfigH

#include "Config.h"
#include "msxml3.h"
#include "XMLReader.h"

using namespace GLEO;

//---------------------------------------------------------------------------
namespace Win32Lib
{
	class _declspec(dllexport) XMLConfig : public BaseConfig, public XMLReader
	{
	private:
		map<string, string> Items;

		void Load(wstring path);
		void Load(MSXML2::IXMLDOMElementPtr node, string prefix);

	public:
		XMLConfig(wstring path);

		wstring getWString(string name);
		string getString(string name);
		int getInt(string name);

		map<string, string>& getItems();
	};
}

#endif
