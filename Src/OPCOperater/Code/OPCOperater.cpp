#include "stdafx.h"

#include "OPCOperater.h"
#include "BaseException.h"
#include "CommonFuncs.h"
#include "WinException.h"
#include "OPCEventHandle.h"

#include <vector>

using namespace GLEO;
using namespace Win32Lib;

//
//	OPCHandleList
//

OPCOperater::OPCOperater(const wstring& ServerName)
{
	HRESULT hr = pServer.CreateInstance(ServerName.c_str(), NULL,CLSCTX_LOCAL_SERVER);

	if(hr == S_OK)
	{
		GroupManager = new OPCGroupsManager(pServer);
	}
	else
	{
		throw Exception("Error in Create OPC Server");
	}
}

OPCOperater::OPCOperater(const wstring& ServerName, const wstring& HostName)
{
	HRESULT hr;

	COSERVERINFO ServerInfo;
	ServerInfo.dwReserved1 = 0;
	ServerInfo.dwReserved2 = 0;
	ServerInfo.pAuthInfo = NULL;
	ServerInfo.pwszName = (wchar_t*)HostName.c_str();

	MULTI_QI qi;
	qi.hr = 0;
	qi.pIID = &pServer.GetIID();
	qi.pItf = NULL;

	CLSID CLSID_Server;
	
	hr= CLSIDFromString((wchar_t*)ServerName.c_str(), &CLSID_Server);
	WinException::COMCheck(hr, L"");

	hr = CoCreateInstanceEx(CLSID_Server, NULL, CLSCTX_REMOTE_SERVER, &ServerInfo, 1, &qi);

	if(hr == S_OK)
	{
		pServer = qi.pItf;
		GroupManager = new OPCGroupsManager(pServer);
	}
	else
	{
		WinException::COMCheck(hr, "Error in Create OPC Server");
	}
}

OPCOperater::~OPCOperater()
{
	if(GroupManager) delete GroupManager;
}

void OPCOperater::GetServerList(vector<wstring>& ServerList)
{
	HRESULT hr;

	ServerList.clear();

	ICatInformationPtr Cats;
	Cats.CreateInstance(CLSID_StdComponentCategoriesMgr, NULL, CLSCTX_SERVER);

	IEnumCLSID* pEnum;
	CATID catids[1];
	
	catids[0] = __uuidof(CATID_OPCDAServer20Ptr);
	hr = Cats->EnumClassesOfCategories(1, catids, 0,  NULL, &pEnum);

	if(hr == S_OK)
	{
		GUID guid;
		ULONG fetched;
		while((hr = pEnum->Next(1, &guid, &fetched)) == S_OK)
		{
			wchar_t* ProgID;
			hr = ProgIDFromCLSID(guid, &ProgID);

			ServerList.push_back(ProgID);

			CoTaskMemFree(ProgID);
		}

		pEnum->Release();
	}
	else
	{
		throw Exception("Error in Enumerate OPC Server");
	}
}

OPCGroupClass* OPCOperater::CreateGroup(wstring group_name, int update_rate)
{
	return GroupManager->CreateGroup(group_name, update_rate);
}

void OPCOperater::Browse(LPWSTR Key) 
{
	tagOPCBROWSEELEMENT* ppBrowseElements;
	long pbMoreElements;
	DWORD pdwCount;
	unsigned long x = 0;
	unsigned long w = 0;
	LPWSTR lpstr  = L"";

	//HRESULT	hr = browse->Browse(Key, &lpstr,10,OPC_BROWSE_FILTER_ALL,L"",L"",false,false,x,&w,&pbMoreElements,&pdwCount,&ppBrowseElements);
	//this->ResultMap.clear();

	//for(int i = 0; i< pdwCount;i++)
	//{
	//	if(ppBrowseElements[i].dwFlagValue == 1)
	//	{
	//		this->m_Browse(ppBrowseElements[i].szItemID);
	//	}
	//	else
	//	{
	//		List.push_back(ppBrowseElements[i].szItemID);

	//		//vector<wstring>::iterator iter;
	//		//iter = find(this->ItemList.begin(),this->ItemList.end(),(wstring)ppBrowseElements[i].szItemID);

	//		//if(iter != this->ItemList.end())
	//		//{
	//		//	//this->Read(*iter);
	//		//}

	//	}
	//}
}


//
//	OPCHandleList
//

OPCHandleList::OPCHandleList()
{
	HandleNum = 0;
	Handles = NULL;
}

OPCHandleList::~OPCHandleList()
{
	if(Handles) delete Handles;
}

int OPCHandleList::getCount()
{
	return HandleNum;
}

const OPCHANDLE* OPCHandleList::getHandles()
{
	return Handles;
}

const OPCHANDLE OPCHandleList::getHandleByAddr(wstring addr)
{
	OPCHANDLE handle = 0;
	vector<OPCItemAttrib>::iterator itor = Items.begin();
	for(unsigned int i = 0; (i < Items.size()) && (itor != Items.end()); i++, itor++)
	{
		if(addr == itor->ItemID)
		{
			handle = itor->ServerHandle;
			break;
		}
	}
	return handle;
}

wstring OPCHandleList::getName(int index)
{
	wstring Result = L"";

	if(index < this->HandleNum)
	{
		Result = this->Items[index].ItemID;
	}

	return Result;
}

int OPCHandleList::getType(int index)
{
	int Result = VT_EMPTY;

	if(index < this->HandleNum)
	{
		Result = this->Items[index].Type;
	}

	return Result;

}

void OPCHandleList::EnumlateFromGroup(IOPCItemMgtPtr group)
{
	HRESULT hr;

	unsigned long Num;
	tagOPCITEMATTRIBUTES* ItemAtt;	

	
	if(Handles) delete Handles;
	Items.clear();

	IEnumOPCItemAttributesPtr Enum;
	Enum = group->CreateEnumerator();

	Enum->Reset();

	while( (hr = Enum->Next(1, &ItemAtt, &Num)) == S_OK )
	{
		OPCItemAttrib Attr;

		Attr.ItemID = ItemAtt->szItemID;
		Attr.ServerHandle = ItemAtt->hServer;
		Attr.Type = ItemAtt->vtRequestedDataType;

		Items.push_back(Attr);
		
		CoTaskMemFree(ItemAtt);
	}

	HandleNum = Items.size();
	Handles = new OPCHANDLE[HandleNum];

	vector<OPCItemAttrib>::iterator itor = Items.begin();
	for(unsigned int i = 0; (i < Items.size()) && (itor != Items.end()); i++, itor++)
	{
		Handles[i] = itor->ServerHandle;	
	}
}

//
//	OPCGroupsManager
//

OPCGroupsManager::OPCGroupsManager(IOPCServerPtr server)
{
	Server = server;
}

OPCGroupsManager::~OPCGroupsManager()
{
}

bool OPCGroupsManager::HasGroup(wstring group_name)
{
	bool Result = false;
	
	return Result;
}

OPCGroupClass* OPCGroupsManager::CreateGroup(wstring group_name, int update_rate)
{
	DeleteGroup(group_name);	

	unsigned long GroupServerHandle;
	LONG TimeBias = 1;
	FLOAT PercDeadband;
	DWORD RevUpRate;

	IOPCItemMgtPtr Group = Server->AddGroup((wchar_t*)group_name.c_str(), true, update_rate, 1, &TimeBias, NULL, 1031, &GroupServerHandle, &RevUpRate);
	OPCGroupClass* NewGroup = new OPCGroupClass(Group);
	
	GroupInfo gi;
	gi.ServerHandle = GroupServerHandle;
	gi.Group = NewGroup;

	GroupList.insert(pair<wstring, GroupInfo>(group_name, gi));

	return NewGroup;
}

void OPCGroupsManager::DeleteGroup(wstring group_name)
{
	map<wstring, GroupInfo>::iterator it = GroupList.find(group_name);
	
	if(it != GroupList.end())
	{
		OPCHANDLE GroupHandle = it->second.ServerHandle;
		
		delete it->second.Group;
		GroupList.erase(it);
		
		Server->RemoveGroup(GroupHandle, true);
	}
	else
	{
		// TODO:
	}
}

//
//	OPCGroupClass
//

OPCGroupClass::OPCGroupClass(IOPCItemMgtPtr intf)
{
	GroupIntf = intf;

	IOPCDataCallback* cb = NULL;
	cb = new OPCEvnetHandler();
	cb->AddRef();

	IConnectionPointContainerPtr cpc = intf;

	IConnectionPointPtr cp = intf;	
	if(cpc)
	{
		IConnectionPoint* icp = NULL;
		HRESULT hr = cpc->FindConnectionPoint(__uuidof(IOPCDataCallback), &icp);
		WinException::COMCheck(hr, L"Get Call Back Connection Point");
		cp = icp;
	}

	if(cp) cp->Advise(cb, 0);
}

void OPCGroupClass::SetItemList(vector<wstring>& item_list, unsigned short type)
{
	ItemIDs = item_list;
	int Len = item_list.size();
	this->Size = Len;
	tagOPCITEMDEF* pItems = new tagOPCITEMDEF[Len]; 
	HRESULT* pErrors = NULL;
	tagOPCITEMRESULT* pResult = NULL;

	try
	{
		this->RemoveAll();

		if(Len > 0)
		{
			for(int n = 0; n < Len; n++)
			{
				pItems[n].bActive = true;
				pItems[n].szAccessPath = NULL;
				pItems[n].dwBlobSize = 0;
				pItems[n].hClient = n;
				pItems[n].pBlob = NULL;
				pItems[n].szItemID =(LPWSTR)item_list[n].c_str();
				pItems[n].vtRequestedDataType = type;
				pItems[n].wReserved = 0;
			}

			GroupIntf->AddItems((unsigned long)Len, pItems, &pResult, &pErrors);
			
			ServerHandles.EnumlateFromGroup(this->GroupIntf);

			Data.resize(Len);
		}
		else
		{
			//TODO: 
		}
	}
	catch(...)
	{
		if(pItems) delete[] pItems;
		if(pResult) CoTaskMemFree(pResult);
		if(pErrors) CoTaskMemFree(pErrors);

		throw;
	}

	if(pItems) delete[] pItems;
	if(pResult) CoTaskMemFree(pResult);
	if(pErrors) CoTaskMemFree(pErrors);
}

void OPCGroupClass::SetItemList(vector<OPCItemDef>& item_list)
{
	int Len = item_list.size();

	tagOPCITEMDEF* pItems = new tagOPCITEMDEF[Len]; 
	HRESULT* pErrors = NULL;
	tagOPCITEMRESULT* pResult = NULL;

	try
	{
		this->RemoveAll();

		ItemIDs.clear();
		if(Len > 0)
		{
			for(int n = 0; n < Len; n++)
			{
				pItems[n].bActive = true;
				pItems[n].szAccessPath = NULL;
				pItems[n].dwBlobSize = 0;
				pItems[n].hClient = n;
				pItems[n].pBlob = NULL;
				pItems[n].szItemID =(LPWSTR)item_list[n].ItemID.c_str();
				pItems[n].vtRequestedDataType = item_list[n].Type;
				pItems[n].wReserved = 0;

				ItemIDs.push_back(item_list[n].ItemID);
			}

			GroupIntf->AddItems((unsigned long)Len, pItems, &pResult, &pErrors);
			
			ServerHandles.EnumlateFromGroup(this->GroupIntf);

			Data.resize(Len);
		}
		else
		{
			//TODO: 
		}
	}
	catch(...)
	{
		if(pItems) delete[] pItems;
		if(pResult) CoTaskMemFree(pResult);
		if(pErrors) CoTaskMemFree(pErrors);

		throw;
	}

	if(pItems) delete[] pItems;
	if(pResult) CoTaskMemFree(pResult);
	if(pErrors) CoTaskMemFree(pErrors);
}

vector<OPCData>& OPCGroupClass::GetData()
{
	return Data;
}

void OPCGroupClass::ReadAll()
{
	OPCDA::IOPCSyncIOPtr Reader;

	Reader = GroupIntf;

	if(!Reader)
	{
		throw Exception("NO Interface IOPCSyncIO");	
	}	

	//Data.clear();

	tagOPCDATASOURCE dwSource = OPC_DS_CACHE;
	tagOPCITEMSTATE *pValues = NULL;
	HRESULT* pErrors = NULL;
	int ItemsCount = ServerHandles.getCount();

	try
	{
		if(ItemsCount > 0)
		{
			HRESULT _hr = Reader->Read(dwSource, ItemsCount, (unsigned long*)ServerHandles.getHandles(), &pValues, &pErrors);
			if(_hr != S_OK)
			{
				if(!pErrors)
				{
					throw Exception("OPCGroupClass pErrors is NULL", "OPCGroupClass ReadAll");
				}

				wstring ErrorItemNames = L"";
				for(int i = 0; i < ItemsCount; i++)
				{
					if((pErrors)[i] != S_OK)
					{
						ErrorItemNames += ServerHandles.getName(i) +L";";
					}
				}
				throw Exception(L"OPCGroupClass::ReadAll ErrorItemNames: " + ErrorItemNames, L"OPCGroupClass ReadAll");
			}

			if(!pErrors)
			{
				throw Exception("OPCGroupClass pErrors is NULL", "OPCGroupClass ReadAll");
			}

			for(int i = 0; i < ItemsCount; i++)
			{
				if(pErrors[i] == S_OK)
				{
					OPCData TempData;

					TempData.ItemID = ItemIDs[pValues[i].hClient];
					TempData.Quality = pValues[i].wQuality;
					TempData.Value = pValues[i].vDataValue;
					TempData.Index = pValues[i].hClient;

					SYSTEMTIME SysTime;
					if(!FileTimeToSystemTime(&pValues[i].ftTimeStamp, &SysTime))
						throw Exception("FileTimeToSystemTime");

					double FloatTime;
					if(!SystemTimeToVariantTime(&SysTime, &FloatTime))
						throw Exception("SystemTimeToVariantTime");

					TempData.TimeStamp = ToTime(variant_t(FloatTime));

					Data[i] = TempData;
				}
				else
				{
					// TODO: Error Handle
				}
			}
		}
	}
	catch(...)
	{
		if (pErrors) CoTaskMemFree(pErrors);
		if (pValues) 
		{
			VariantClear(&pValues[0].vDataValue);
			CoTaskMemFree(pValues); 
		}

		throw;
	}

	if (pErrors) CoTaskMemFree(pErrors);
	if (pValues) 
	{
		for(int i = 0; i < ItemsCount; i++)
		{
			VariantClear(&pValues[i].vDataValue);
		}

		CoTaskMemFree(pValues); 
	}
}

void OPCGroupClass::Write(map<wstring, VARIANT>& Data)
{
	OPCDA::IOPCSyncIOPtr Writer;

	Writer = GroupIntf;

	if(!Writer)
	{
		throw Exception("NO Interface IOPCSyncIO");	
	}	

	VARIANT *pValues = NULL;
	HRESULT* pErrors = NULL;
	int ItemsCount = Data.size();

	try
	{
		if(ItemsCount > 0)
		{
			pValues = new VARIANT[ItemsCount];
			OPCHANDLE* Handles = new OPCHANDLE[ItemsCount];

			for(int i = 0, j = 0; i < Size; i++)
			{
				wstring ItemID = this->ServerHandles.getName(i);

				map<wstring, VARIANT>::iterator hint = Data.find(ItemID);
				if(hint != Data.end())
				{
					//pValues[i].vt = this->ServerHandles.getType(i);
					//pValues[i] = hint->second;
					pValues[j].vt = this->ServerHandles.getType(i);
					pValues[j] = hint->second;
					Handles[j++] = this->ServerHandles.getHandleByAddr(hint->first);
				}
			}

			//Writer->Write(ItemsCount,(unsigned long*)this->ServerHandles.getHandles(), pValues, &pErrors);
			Writer->Write(ItemsCount,(unsigned long*)Handles, pValues, &pErrors);
		}
	}
	catch(...)
	{
		if (pErrors) CoTaskMemFree(pErrors);
		if (pValues) delete pValues;

		throw;
	}

	if (pErrors) CoTaskMemFree(pErrors);
	if (pValues) delete pValues;
}

void OPCGroupClass::RemoveAll()
{
	int ItemsCount = this->ServerHandles.getCount();
	HRESULT* pErrors = NULL;

	try
	{
		if(ItemsCount > 0)
		{
			this->GroupIntf->RemoveItems(ItemsCount,(unsigned long*)this->ServerHandles.getHandles(), &pErrors);
		}
	}
	catch(...)
	{
		if (pErrors) CoTaskMemFree(pErrors);

		throw;
	}

	if (pErrors) CoTaskMemFree(pErrors);
}


//void OPCOperater::Write(int lngNo, string strData)
//{
	//DWORD dwIndex  = 0;
	//OPCHANDLE *phServer = &lngNo;
	//VARIANT *pValues = NULL;
	//HRESULT *pErrors = NULL;
	//HRESULT hr   = E_FAIL;
	//DWORD cdwItems=1;

	//pValues = (VARIANT *) CoTaskMemAlloc (cdwItems * sizeof (VARIANT));

	//if (phServer == NULL || pValues == NULL)
	//{
	//}
	//   
	//::Sleep(0);
	//
	//try
	//{
	//       //同步写数据
	//       
	// //数据转换 
	// //Str2Variant(strData,pValues[0],arrItemType.GetAt(lngNo));

	// hr = pSyncIO->Write (
	//   1,             // Item count
	//   phServer,  // Array of server handles for items
	//   pValues,  // Array of values
	//   &pErrors);  // Array of errors

	// if(FAILED(hr))
	// {
	//  if (phServer) CoTaskMemFree (phServer);
	//     if (pValues) CoTaskMemFree (pValues); 
	//     if (pErrors) CoTaskMemFree (pErrors);
	//  VariantClear (&pValues[0]);
	//  //return 2;   //同步读数据时出错
	// }
	//
	// VariantClear (&pValues[0]);
	//}
	//
	//catch (...)
	//{
	//    //return 3;
	//}

	//if(phServer)CoTaskMemFree (phServer);
	//if (pValues)CoTaskMemFree (pValues);
	//if (pErrors) CoTaskMemFree (pErrors);
//}

//void OPCGroupClass::AsyncIORead(LPWSTR Key) //异步读
//{
	//HRESULT r;
	//IUnknown* uk;
	//IConnectionPointContainerPtr con;
	//IConnectionPointPtr c;
	//con =m_pItemMgt;

	//r = con->FindConnectionPoint(IOPCDataCallbackPtr::GetIID(),(IConnectionPoint**)&uk);
	//c = uk;

	//if (r != S_OK) _com_issue_errorex(r, con, __uuidof(con));

	//CLSID clsid1;
	////
	//r = CLSIDFromProgID(Key,&clsid1);//L"OpcData.CallRead"

	//IUnknown* unk1;
	//r = CoCreateInstance(clsid1,NULL,CLSCTX_INPROC,IID_IUnknown,(void**)&unk1);

	//IOPCDataCallback* back;
	//r = unk1->QueryInterface(IOPCDataCallbackPtr::GetIID(),(void**)&back);

	//DWORD dd;

	//c->Advise( (IUnknown*)back,&dd);

	//IOPCAsyncIO2* Asy;
	//r=m_pItemMgt->QueryInterface(IOPCAsyncIO2Ptr::GetIID(),(void**)&Asy);

	//unsigned long ID;
	//HRESULT error[10];
	//r = Asy->Read(1,&m_pItResult[0].hServer,0,&ID,(HRESULT**)&error);
//}
