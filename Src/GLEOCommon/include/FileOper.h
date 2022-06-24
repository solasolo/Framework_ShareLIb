#ifndef FILEOPER_H 
#define FILEOPER_H 

#include "std_Unicode.h"
#include "BaseException.h"

namespace GLEO
{
	class __declspec(dllexport) FileException : public Exception
	{
	private:
		struct ErrMap
		{
			int No;
			const wchar_t* Message;
		};

		static const ErrMap ErrorTable[];
		void SetError();

	public:
		FileException(wstring where);
		FileException(const FileException& ex) throw();
	};


	class __declspec(dllexport) FileOper
	{
	public:
		enum OpenMode {omRead = 0, omWrite, omAppend};

	private:
		OpenMode Mode;
		TString FilePath;	
		FILE * FileHandle;

		static const wchar_t* ModeStr[3];

		void Open();

	public:
		FileOper();
		FileOper(TString path);
		FileOper(TString path, OpenMode mode);
		~FileOper();

		inline static void Delete(TString path);
		inline static bool Exist(TString path);

		void Open(TString path, OpenMode mode);
		void Close();
		void Delete();
		bool Exist();

		void Write(TString& data);
		void ReadLine(TString& data, int len);
	};
}

#endif