#include <io.h>
#include <errno.h>

#include "FileOper.h"

namespace GLEO
{
	const FileException::ErrMap FileException::ErrorTable[] =
	{
		{E2BIG, L"Argument list too long"}, 
		{EACCES, L"Permission denied"},
		{EAGAIN, L"No more processes or not enough memory or maximum nesting level reached"},
		{EBADF, L"Bad file number"},
		{ECHILD, L"No spawned processes"},
		{EDEADLOCK, L"Resource deadlock would occur"},
		{EDOM, L"Math argument"},
		{EEXIST, L"File exists"},
		{EINVAL, L"Invalid argument"},
		{EMFILE, L"Too many open files"},
		{ENOENT, L"No such file or directory"},
		{ENOEXEC, L"Exec format error"},
		{ENOMEM, L"Not enough memory"},
		{ENOSPC, L"No space left on device"},
		{ERANGE, L"Result too large"},
		{EXDEV, L"Cross-device link"},
		{-1, L"Unknow File Erroe"}
	};

	void FileException::SetError()
	{
		Code = errno;
		for(int i = 0; i < 17; i++)
		{
			int no = ErrorTable[i].No;
			if(no == errno || no == -1)
			{
				Message = ErrorTable[i].Message;
				break;
			}
		}
	}

	FileException::FileException(TString where)
		: Exception()
	{
		SetError();
		Where = where;
	}

	FileException::FileException(const FileException& ex) throw()
  	: Exception(ex)
	{
	}
}

namespace GLEO
{
	const wchar_t* FileOper::ModeStr[3] = {L"r", L"w", L"w+"};


	FileOper::FileOper()
	{
		FileHandle = NULL;
		FilePath = L"";
	}

	FileOper::FileOper(wstring path)
	{
		FileHandle = NULL;
		FilePath = path;
	}

	FileOper::FileOper(wstring path, OpenMode mode)
	{
		FileHandle = NULL;
		Open(path, mode);
	}

	FileOper::~FileOper()
	{
		Close();
	}

	void FileOper::Open()
	{
		FileHandle = Fopen(FilePath.c_str(), ModeStr[Mode]);
		if(FileHandle == NULL)
		{
			throw FileException(wstring(L"Open File:") + FilePath );
		}
	}

	void FileOper::Open(TString path, OpenMode mode)
	{
		FilePath = path;
		Mode = mode;

		Open();
	}

	void FileOper::Close()
	{
		if(FileHandle != NULL)
		{
			fclose(FileHandle);
			FileHandle = NULL;
		}
	}

	void FileOper::Delete()
	{
		Delete(FilePath);
	}

	bool FileOper::Exist()
	{
		return Exist(FilePath);
	}

	void FileOper::Write(TString& data)
	{
		if(FileHandle != NULL)
		{
			fwrite(data.c_str(), sizeof(char), data.size(), FileHandle); 
		}
	}

	void FileOper::ReadLine(TString& data, int len)
	{
		int ReadLen;
		TChar* Buffer;
	
		if(FileHandle != NULL)
		{
			Buffer = new TChar[len + 1];

			try
			{
				ReadLen = fread(Buffer, sizeof(char), len, FileHandle);		
				data.resize(ReadLen);
//				data.clear();
				data = _T("");
				data.append(Buffer, ReadLen);
			}
			catch(...)
			{
				delete Buffer;
				throw;
			}

			delete Buffer;
		}
	}

	void FileOper::Delete(TString path)
	{
		if(Exist(path))
		{
			if(Remove(path.c_str()) != 0)
			{
				throw FileException(TString(_T("Delete File")) + path );
			}
		}
	}

	bool FileOper::Exist(TString path)
	{
		return (_Access(path.c_str(), 0) == 0);
	}
}