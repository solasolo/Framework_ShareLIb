//---------------------------------------------------------------------------

#ifndef XMLMultiLanguageH
#define XMLMultiLanguageH

#include <string>

#include "MultiLanguage.h"
#include "msxml3.h"

using namespace std;
using namespace GLEO;

//---------------------------------------------------------------------------
namespace Win32Lib
{
    class ML_XML : public BaseMultiLanguage
	{
	private:
		wstring DocPath;

		void LoadModule(MSXML2::IXMLDOMElementPtr& root, string name);

	protected:
		void Load();
		void Save();

	public:
		ML_XML(wstring path);
	};
}

#endif
