#pragma once
#include <algorithm>
#include <vector>
#include <map>
#include <string>

#include "OPCDA3.h"
#include "OPCEventHandle.h"
#include "EventLogger.h"

using namespace std;
using namespace OPCDA;
using namespace GLEO;

struct OPCData
{
	wstring ItemID;
	time_t TimeStamp;
	unsigned short Quality;
	variant_t Value;
	int Index;
};

struct OPCItemDef
{
	wstring ItemID;
	int	Type;
};

struct OPCItemAttrib
{
	wstring ItemID;
	OPCHANDLE ServerHandle;
	int Type;
};

class __declspec(dllexport) OPCHandleList
{
private:
	int HandleNum;
	vector<OPCItemAttrib> Items;
	OPCHANDLE* Handles;

public: 
	OPCHandleList();
	~OPCHandleList();

	int getCount();
	const OPCHANDLE* getHandles();
	const OPCHANDLE getHandleByAddr(wstring addr);
	wstring getName(int index);
	int getType(int index);

	void EnumlateFromGroup(IOPCItemMgtPtr group);
};

class __declspec(dllexport) OPCGroupClass
{
private:
	IOPCItemMgtPtr GroupIntf;

	OPCHandleList ServerHandles;
	vector<wstring> ItemIDs;
	vector<OPCData> Data;
	int Size;

	void RemoveAll();

public:
	OPCGroupClass(IOPCItemMgtPtr intf);

	void SetItemList(vector<wstring>& item_list, unsigned short type = VT_EMPTY);
	void SetItemList(vector<OPCItemDef>& item_list);
	void ReadAll();
	void Write(map<wstring, VARIANT>& Data);
	
	vector<OPCData>& GetData();
};

class __declspec(dllexport) OPCGroupsManager : EventSource
{
	struct GroupInfo
	{
		OPCHANDLE ServerHandle;
		OPCGroupClass* Group;
	};

private:
	IOPCServerPtr Server;
	map<wstring, GroupInfo> GroupList;

public:
	OPCGroupsManager(IOPCServerPtr server);
	~OPCGroupsManager();

	OPCGroupClass* CreateGroup(wstring group_name, int update_rate = 1000);
	OPCGroupClass* GetGroup(wstring group_name);
	void DeleteGroup(wstring group_name);
	bool HasGroup(wstring group_name);
};

class __declspec(dllexport) OPCOperater : EventSource
{
private:
	OPCGroupsManager* GroupManager;

public:
	IOPCServerPtr pServer;
	
	OPCOperater(const wstring& ServerName);
	OPCOperater(const wstring& ServerName, const wstring& HostName);
	~OPCOperater();
	
	void Browse(LPWSTR Key); 

	static void GetServerList(vector<wstring>& ServerList);
	OPCGroupClass* CreateGroup(wstring group_name, int update_rate = 1000);
};

