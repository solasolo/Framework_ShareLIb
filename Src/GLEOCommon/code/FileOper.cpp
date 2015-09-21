#include <io.h>
#include <errno.h>

#include "FileOper.h"

namespace GLEO
{
	const FileException::ErrMap FileException::ErrorTable[] =
	{
		{E2BIG, _T("Argument list too long")}, 
		{EACCES, _T("Permission denied")},
		{EAGAIN, _T("No more processes or not enough memory or maximum nesting level reached")},
		{EBADF, _T("Bad file number")},
		{ECHILD, _T("No spawned processes")},
		{EDEADLOCK, _T("Resource deadlock would occur")},
		{EDOM, _T("Math argument")},
		{EEXIST, _T("File exists")},
		{EINVAL, _T("Invalid argument")},
		{EMFILE, _T("Too many open files")},
		{ENOENT, _T("No such file or directory")},
		{ENOEXEC, _T("Exec format error")},
		{ENOMEM, _T("Not enough memory")},
		{ENOSPC, _T("No space left on device")},
		{ERANGE, _T("Result too large")},
		{EXDEV, _T("Cross-device link")},
		{-1, _T("Unknow File Erroe")}
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
	TChar* FileOper::ModeStr[3] = {_T("r"), _T("w"), _T("w+")};


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