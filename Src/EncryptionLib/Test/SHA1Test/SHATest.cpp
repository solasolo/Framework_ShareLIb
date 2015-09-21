#include "stdafx.h"

#include "SHA.h"

using namespace System::Security::Cryptography; 
using namespace System;


int _tmain(int argc, _TCHAR* argv[])
{
	GLEO::SHA1 sha;

	SHA1^ sha1 = gcnew SHA1CryptoServiceProvider(); 
	
	array<unsigned char>^ data = gcnew array<unsigned char>(6){0x31, 0x32, 0x33, 0x34, 0x35, 0x36};
	array<unsigned char>^  result = sha1->ComputeHash(data);

	unsigned char Result[20];

	sha.Input((unsigned char*)"123456", 6);
	sha.Result(Result);
}