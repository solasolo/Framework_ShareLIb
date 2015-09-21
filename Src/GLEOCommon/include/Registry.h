#ifndef REGISTRY_H
#define REGISTRY_H

#include <string>
#include <windows.h>

using namespace std;

class __declspec(dllexport) Registry
{
private:
	HKEY RootKey;
	HKEY CurrentKey;

	

public:
	Registry(HKEY key);

	void OpenKey(wstring key);
	bool ValueExists(wstring key);
	wstring ReadString(wstring key);
	void WriteString(wstring key, wstring value);
	int ReadInteger(wstring key);
	void WriteInteger(wstring key, int value);
};

#ifndef __BORLANDC__

typedef Registry TRegistry;
	
#endif

#endif