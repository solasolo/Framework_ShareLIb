#ifndef STD_UNICODE_H
#define STD_UNICODE_H

#include <string>
#include <iostream>
#include <sstream>

#include <io.h>
#include <tchar.h>

using namespace std;
//{

#ifdef _UNICODE
typedef wstring TString;
typedef wchar_t TChar;

typedef wofstream OFStream;
typedef wifstream IFStream;
typedef wfstream FStream;

typedef wstringstream StringStream;
typedef wistringstream IStringStream;
typedef wostringstream OStringStream;
#else
typedef string TString;
typedef char TChar;

typedef ofstream Ofstream;
typedef ifstream Ifstream;
typedef fstream FStream;

typedef stringstream StringStream;
typedef istringstream IStringStream;
typedef ostringstream OStringStream;
#endif

#if !(defined(__TCHAR_H) || defined(_INC_TCHAR))

#ifdef _UNICODE
#define _T(s) L ## s
#else
#define _T(s) s
#endif

#endif // NOT Defined _T

#ifdef _UNICODE
#define T_finddata_t _wfinddata_t

#ifdef __BORLANDC__
#define T_findfirst __wfindfirst
#define T_findnext __wfindnext
#else
#define T_findfirst _wfindfirst
#define T_findnext _wfindnext
#endif

#define Fopen _wfopen
#define Remove _wremove
#define _Access _waccess

#else
#define T_finddata_t _finddata_t
#define T_findfirst _findfirst
#define T_findnext _findnext

#define Fopen fopen
#define Remove remove
#define Access _access

#endif

//}

#endif
