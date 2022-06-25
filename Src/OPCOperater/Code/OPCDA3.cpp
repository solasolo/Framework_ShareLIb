// Created by Microsoft (R) C/C++ Compiler Version 14.00.50727.762 (d06abf43).
//
// e:\test\opcserver\debug\opcproxy.tli
//
// Wrapper implementations for Win32 type library c:\WINDOWS\system32\opcproxy.dll
// compiler-generated file created 06/04/08 at 13:23:06 - DO NOT EDIT!

#include "stdafx.h"

#include "OPCDA3.h"
#include "OPCException.h"
#include "CommonFuncs.h"

//
// interface IOPCServer wrapper method implementations
//
using namespace OPCDA;

IOPCItemMgtPtr IOPCServer::AddGroup ( LPWSTR szName, long bActive, unsigned long dwRequestedUpdateRate, unsigned long hClientGroup, long * pTimeBias, float * pPercentDeadband, unsigned long dwLCID, unsigned long * phServerGroup, unsigned long * pRevisedUpdateRate) 
{
	IOPCItemMgtPtr Result;
	IUnknown* pUnk;

	HRESULT _hr = raw_AddGroup(szName, bActive, dwRequestedUpdateRate, hClientGroup, pTimeBias, pPercentDeadband, dwLCID, phServerGroup, pRevisedUpdateRate, (GUID*)&__uuidof(IOPCItemMgtPtr), &pUnk);
	if(_hr != OPC_S_UNSUPPORTEDRATE)
	{
		OPCException::Check(_hr, "IOPCServer.AddGroup");
	}

	Result = pUnk;
	pUnk->Release();

	return pUnk;
}

HRESULT IOPCServer::GetErrorString ( HRESULT dwError, unsigned long dwLocale, LPWSTR * ppString ) 
{
	HRESULT _hr = raw_GetErrorString(dwError, dwLocale, ppString);
	OPCException::Check(_hr, "IOPCServer.GetErrorString");
	
	return _hr;
}

IOPCItemMgtPtr IOPCServer::GetGroupByName ( LPWSTR szName) 
{
	IOPCItemMgtPtr Result;
	IUnknown* pUnk;

	HRESULT _hr = raw_GetGroupByName(szName, (GUID*)&__uuidof(IOPCItemMgtPtr), &pUnk);
	OPCException::Check(_hr, "IOPCServer.GetGroupByName");

	Result = pUnk;
	pUnk->Release();

	return Result;
}

HRESULT IOPCServer::GetStatus ( struct tagOPCSERVERSTATUS * * ppServerStatus ) 
{
	HRESULT _hr = raw_GetStatus(ppServerStatus);
	OPCException::Check(_hr, "IOPCServer.GetStatus");

	return _hr;
}

HRESULT IOPCServer::RemoveGroup ( unsigned long hServerGroup, long bForce ) 
{
	HRESULT _hr = raw_RemoveGroup(hServerGroup, bForce);
	OPCException::Check(_hr, "IOPCServer.RemoveGroup");

	return _hr;
}

IUnknownPtr IOPCServer::CreateGroupEnumerator ( enum tagOPCENUMSCOPE dwScope ) 
{
	IUnknownPtr Result;
	IUnknown* pUnk;

	HRESULT _hr = raw_CreateGroupEnumerator(dwScope, (GUID*)&IID_IEnumUnknown, &pUnk);
	OPCException::Check(_hr, "IOPCServer.CreateGroupEnumerator");

	Result = pUnk;
	pUnk->Release();

	return Result;
}

//
// interface IOPCServerPublicGroups wrapper method implementations
//

HRESULT IOPCServerPublicGroups::GetPublicGroupByName ( LPWSTR szName, GUID * riid, IUnknown * * ppUnk ) {
	HRESULT _hr = raw_GetPublicGroupByName(szName, riid, ppUnk);
	if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(this));
	return _hr;
}

HRESULT IOPCServerPublicGroups::RemovePublicGroup ( unsigned long hServerGroup, long bForce ) {
	HRESULT _hr = raw_RemovePublicGroup(hServerGroup, bForce);
	if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(this));
	return _hr;
}

//
// interface IOPCBrowseServerAddressSpace wrapper method implementations
//

HRESULT IOPCBrowseServerAddressSpace::QueryOrganization ( enum tagOPCNAMESPACETYPE * pNameSpaceType ) {
	HRESULT _hr = raw_QueryOrganization(pNameSpaceType);
	if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(this));
	return _hr;
}

HRESULT IOPCBrowseServerAddressSpace::ChangeBrowsePosition ( enum tagOPCBROWSEDIRECTION dwBrowseDirection, LPWSTR szString ) {
	HRESULT _hr = raw_ChangeBrowsePosition(dwBrowseDirection, szString);
	if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(this));
	return _hr;
}

HRESULT IOPCBrowseServerAddressSpace::BrowseOPCItemIDs ( enum tagOPCBROWSETYPE dwBrowseFilterType, LPWSTR szFilterCriteria, unsigned short vtDataTypeFilter, unsigned long dwAccessRightsFilter, struct IEnumString * * ppIEnumString ) {
	HRESULT _hr = raw_BrowseOPCItemIDs(dwBrowseFilterType, szFilterCriteria, vtDataTypeFilter, dwAccessRightsFilter, ppIEnumString);
	if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(this));
	return _hr;
}

HRESULT IOPCBrowseServerAddressSpace::GetItemID ( LPWSTR szItemDataID, LPWSTR * szItemID ) {
	HRESULT _hr = raw_GetItemID(szItemDataID, szItemID);
	if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(this));
	return _hr;
}

HRESULT IOPCBrowseServerAddressSpace::BrowseAccessPaths ( LPWSTR szItemID, struct IEnumString * * ppIEnumString ) {
	HRESULT _hr = raw_BrowseAccessPaths(szItemID, ppIEnumString);
	if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(this));
	return _hr;
}

//
// interface IOPCGroupStateMgt wrapper method implementations
//

HRESULT IOPCGroupStateMgt::GetState ( unsigned long * pUpdateRate, long * pActive, LPWSTR * ppName, long * pTimeBias, float * pPercentDeadband, unsigned long * pLCID, unsigned long * phClientGroup, unsigned long * phServerGroup ) {
	HRESULT _hr = raw_GetState(pUpdateRate, pActive, ppName, pTimeBias, pPercentDeadband, pLCID, phClientGroup, phServerGroup);
	if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(this));
	return _hr;
}

HRESULT IOPCGroupStateMgt::SetState ( unsigned long * pRequestedUpdateRate, unsigned long * pRevisedUpdateRate, long * pActive, long * pTimeBias, float * pPercentDeadband, unsigned long * pLCID, unsigned long * phClientGroup ) {
	HRESULT _hr = raw_SetState(pRequestedUpdateRate, pRevisedUpdateRate, pActive, pTimeBias, pPercentDeadband, pLCID, phClientGroup);
	if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(this));
	return _hr;
}

HRESULT IOPCGroupStateMgt::SetName ( LPWSTR szName ) {
	HRESULT _hr = raw_SetName(szName);
	if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(this));
	return _hr;
}

HRESULT IOPCGroupStateMgt::CloneGroup ( LPWSTR szName, GUID * riid, IUnknown * * ppUnk ) {
	HRESULT _hr = raw_CloneGroup(szName, riid, ppUnk);
	if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(this));
	return _hr;
}

//
// interface IOPCPublicGroupStateMgt wrapper method implementations
//

HRESULT IOPCPublicGroupStateMgt::GetState ( long * pPublic ) {
	HRESULT _hr = raw_GetState(pPublic);
	if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(this));
	return _hr;
}

HRESULT IOPCPublicGroupStateMgt::MoveToPublic ( ) {
	HRESULT _hr = raw_MoveToPublic();
	if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(this));
	return _hr;
}

//
// interface IOPCSyncIO wrapper method implementations
//

HRESULT IOPCSyncIO::Read ( enum tagOPCDATASOURCE dwSource, unsigned long dwCount, unsigned long * phServer, struct tagOPCITEMSTATE * * ppItemValues, HRESULT * * ppErrors ) 
{
	HRESULT _hr = raw_Read(dwSource, dwCount, phServer, ppItemValues, ppErrors);
	//OPCException::Check(_hr, "IOPCSyncIO.Read");

	return _hr;
}

HRESULT IOPCSyncIO::Write ( unsigned long dwCount, unsigned long * phServer, VARIANT * pItemValues, HRESULT * * ppErrors ) 
{
	HRESULT _hr = raw_Write(dwCount, phServer, pItemValues, ppErrors);
	OPCException::Check(_hr, "IOPCSyncIO.Write");

	return _hr;
}

//
// interface IOPCAsyncIO wrapper method implementations
//

HRESULT IOPCAsyncIO::Read ( unsigned long dwConnection, enum tagOPCDATASOURCE dwSource, unsigned long dwCount, unsigned long * phServer, unsigned long * pTransactionID, HRESULT * * ppErrors ) {
	HRESULT _hr = raw_Read(dwConnection, dwSource, dwCount, phServer, pTransactionID, ppErrors);
	if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(this));
	return _hr;
}

HRESULT IOPCAsyncIO::Write ( unsigned long dwConnection, unsigned long dwCount, unsigned long * phServer, VARIANT * pItemValues, unsigned long * pTransactionID, HRESULT * * ppErrors ) {
	HRESULT _hr = raw_Write(dwConnection, dwCount, phServer, pItemValues, pTransactionID, ppErrors);
	if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(this));
	return _hr;
}

HRESULT IOPCAsyncIO::Refresh ( unsigned long dwConnection, enum tagOPCDATASOURCE dwSource, unsigned long * pTransactionID ) {
	HRESULT _hr = raw_Refresh(dwConnection, dwSource, pTransactionID);
	if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(this));
	return _hr;
}

HRESULT IOPCAsyncIO::Cancel ( unsigned long dwTransactionID ) {
	HRESULT _hr = raw_Cancel(dwTransactionID);
	if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(this));
	return _hr;
}

//
// interface IOPCDataCallback wrapper method implementations
//

HRESULT IOPCDataCallback::OnDataChange ( unsigned long dwTransid, unsigned long hGroup, HRESULT hrMasterquality, HRESULT hrMastererror, unsigned long dwCount, unsigned long * phClientItems, VARIANT * pvValues, unsigned short * pwQualities, struct _FILETIME * pftTimeStamps, HRESULT * pErrors ) {
	HRESULT _hr = raw_OnDataChange(dwTransid, hGroup, hrMasterquality, hrMastererror, dwCount, phClientItems, pvValues, pwQualities, pftTimeStamps, pErrors);
	OPCException::Check(_hr, "IOPCDataCallback.OnDataChange");

	return _hr;
}

HRESULT IOPCDataCallback::OnReadComplete ( unsigned long dwTransid, unsigned long hGroup, HRESULT hrMasterquality, HRESULT hrMastererror, unsigned long dwCount, unsigned long * phClientItems, VARIANT * pvValues, unsigned short * pwQualities, struct _FILETIME * pftTimeStamps, HRESULT * pErrors ) {
	HRESULT _hr = raw_OnReadComplete(dwTransid, hGroup, hrMasterquality, hrMastererror, dwCount, phClientItems, pvValues, pwQualities, pftTimeStamps, pErrors);
	OPCException::Check(_hr, "IOPCDataCallback.OnReadComplete");

	return _hr;
}

HRESULT IOPCDataCallback::OnWriteComplete ( unsigned long dwTransid, unsigned long hGroup, HRESULT hrMastererr, unsigned long dwCount, unsigned long * pClienthandles, HRESULT * pErrors ) {
	HRESULT _hr = raw_OnWriteComplete(dwTransid, hGroup, hrMastererr, dwCount, pClienthandles, pErrors);
	OPCException::Check(_hr, "IOPCDataCallback.OnWriteComplete");

	return _hr;
}

HRESULT IOPCDataCallback::OnCancelComplete ( unsigned long dwTransid, unsigned long hGroup ) {
	HRESULT _hr = raw_OnCancelComplete(dwTransid, hGroup);
	OPCException::Check(_hr, "IOPCDataCallback.OnCancelComplete");

	return _hr;
}

//
// interface IOPCItemMgt wrapper method implementations
//

HRESULT IOPCItemMgt::AddItems ( unsigned long dwCount, struct tagOPCITEMDEF * pItemArray, struct tagOPCITEMRESULT * * ppAddResults, HRESULT * * ppErrors ) 
{
	HRESULT _hr = raw_AddItems(dwCount, pItemArray, ppAddResults, ppErrors);

	if(_hr != S_OK)
	{
		wstring FirstItemName = L"";

		for(int i = 0; i < dwCount; i++)
		{
			if((*ppErrors)[i] != S_OK)
			{
				FirstItemName = pItemArray[i].szItemID;
				break;
			}
		}
		OPCException::Check(_hr, "IOPCItemMgt::AddItems First=>" + ~FirstItemName);
	}

	return _hr;
}

HRESULT IOPCItemMgt::ValidateItems ( unsigned long dwCount, struct tagOPCITEMDEF * pItemArray, long bBlobUpdate, struct tagOPCITEMRESULT * * ppValidationResults, HRESULT * * ppErrors ) 
{
	HRESULT _hr = raw_ValidateItems(dwCount, pItemArray, bBlobUpdate, ppValidationResults, ppErrors);
	OPCException::Check(_hr, "IOPCItemMgt::ValidateItems");

	return _hr;
}

HRESULT IOPCItemMgt::RemoveItems ( unsigned long dwCount, unsigned long * phServer, HRESULT * * ppErrors ) 
{
	HRESULT _hr = raw_RemoveItems(dwCount, phServer, ppErrors);
	OPCException::Check(_hr, "IOPCItemMgt::RemoveItems");

	return _hr;
}

HRESULT IOPCItemMgt::SetActiveState ( unsigned long dwCount, unsigned long * phServer, long bActive, HRESULT * * ppErrors ) 
{
	HRESULT _hr = raw_SetActiveState(dwCount, phServer, bActive, ppErrors);
	OPCException::Check(_hr, "IOPCItemMgt::SetActiveState");

	return _hr;
}

HRESULT IOPCItemMgt::SetClientHandles ( unsigned long dwCount, unsigned long * phServer, unsigned long * phClient, HRESULT * * ppErrors ) 
{
	HRESULT _hr = raw_SetClientHandles(dwCount, phServer, phClient, ppErrors);
	OPCException::Check(_hr, "IOPCItemMgt::SetClientHandles");

	return _hr;
}

HRESULT IOPCItemMgt::SetDatatypes ( unsigned long dwCount, unsigned long * phServer, unsigned short * pRequestedDatatypes, HRESULT * * ppErrors ) 
{
	HRESULT _hr = raw_SetDatatypes(dwCount, phServer, pRequestedDatatypes, ppErrors);
	OPCException::Check(_hr, "IOPCItemMgt::SetDatatypes");

	return _hr;
}

IEnumOPCItemAttributesPtr IOPCItemMgt::CreateEnumerator ( ) 
{
	IEnumOPCItemAttributesPtr Result;
	IUnknown* pUnk;

	HRESULT _hr = raw_CreateEnumerator((GUID*)&__uuidof(IEnumOPCItemAttributesPtr), &pUnk);
	OPCException::Check(_hr, "IOPCItemMgt::CreateEnumerator");

	Result = pUnk;
	pUnk->Release();

	return Result;
}

//
// interface IEnumOPCItemAttributes wrapper method implementations
//

HRESULT IEnumOPCItemAttributes::Next ( unsigned long celt, struct tagOPCITEMATTRIBUTES * * ppItemArray, unsigned long * pceltFetched ) 
{
	HRESULT _hr = raw_Next(celt, ppItemArray, pceltFetched);
	if(_hr != S_OK && _hr != S_FALSE)
	{
		OPCException::Check(_hr, "IEnumOPCItemAttributes::Next");
	}

	return _hr;
}

HRESULT IEnumOPCItemAttributes::Skip ( unsigned long celt ) 
{
	HRESULT _hr = raw_Skip(celt);
	OPCException::Check(_hr, "IEnumOPCItemAttributes::Next");

	return _hr;
}

HRESULT IEnumOPCItemAttributes::Reset ( ) 
{
	HRESULT _hr = raw_Reset();
	OPCException::Check(_hr, "IEnumOPCItemAttributes::Reset");

	return _hr;
}

HRESULT IEnumOPCItemAttributes::Clone ( struct IEnumOPCItemAttributes * * ppEnumItemAttributes ) 
{
	HRESULT _hr = raw_Clone(ppEnumItemAttributes);
	OPCException::Check(_hr, "IEnumOPCItemAttributes::Clone");

	return _hr;
}

//
// interface IOPCAsyncIO2 wrapper method implementations
//

HRESULT IOPCAsyncIO2::Read ( unsigned long dwCount, unsigned long * phServer, unsigned long dwTransactionID, unsigned long * pdwCancelID, HRESULT * * ppErrors ) {
	HRESULT _hr = raw_Read(dwCount, phServer, dwTransactionID, pdwCancelID, ppErrors);
	if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(this));
	return _hr;
}

HRESULT IOPCAsyncIO2::Write ( unsigned long dwCount, unsigned long * phServer, VARIANT * pItemValues, unsigned long dwTransactionID, unsigned long * pdwCancelID, HRESULT * * ppErrors ) {
	HRESULT _hr = raw_Write(dwCount, phServer, pItemValues, dwTransactionID, pdwCancelID, ppErrors);
	if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(this));
	return _hr;
}

HRESULT IOPCAsyncIO2::Refresh2 ( enum tagOPCDATASOURCE dwSource, unsigned long dwTransactionID, unsigned long * pdwCancelID ) {
	HRESULT _hr = raw_Refresh2(dwSource, dwTransactionID, pdwCancelID);
	if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(this));
	return _hr;
}

HRESULT IOPCAsyncIO2::Cancel2 ( unsigned long dwCancelID ) {
	HRESULT _hr = raw_Cancel2(dwCancelID);
	if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(this));
	return _hr;
}

HRESULT IOPCAsyncIO2::SetEnable ( long bEnable ) {
	HRESULT _hr = raw_SetEnable(bEnable);
	if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(this));
	return _hr;
}

HRESULT IOPCAsyncIO2::GetEnable ( long * pbEnable ) {
	HRESULT _hr = raw_GetEnable(pbEnable);
	if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(this));
	return _hr;
}

//
// interface IOPCItemProperties wrapper method implementations
//

HRESULT IOPCItemProperties::QueryAvailableProperties ( LPWSTR szItemID, unsigned long * pdwCount, unsigned long * * ppPropertyIDs, LPWSTR * * ppDescriptions, unsigned short * * ppvtDataTypes ) {
	HRESULT _hr = raw_QueryAvailableProperties(szItemID, pdwCount, ppPropertyIDs, ppDescriptions, ppvtDataTypes);
	if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(this));
	return _hr;
}

HRESULT IOPCItemProperties::GetItemProperties ( LPWSTR szItemID, unsigned long dwCount, unsigned long * pdwPropertyIDs, VARIANT * * ppvData, HRESULT * * ppErrors ) {
	HRESULT _hr = raw_GetItemProperties(szItemID, dwCount, pdwPropertyIDs, ppvData, ppErrors);
	if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(this));
	return _hr;
}

HRESULT IOPCItemProperties::LookupItemIDs ( LPWSTR szItemID, unsigned long dwCount, unsigned long * pdwPropertyIDs, LPWSTR * * ppszNewItemIDs, HRESULT * * ppErrors ) {
	HRESULT _hr = raw_LookupItemIDs(szItemID, dwCount, pdwPropertyIDs, ppszNewItemIDs, ppErrors);
	if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(this));
	return _hr;
}

//
// interface IOPCItemDeadbandMgt wrapper method implementations
//

HRESULT IOPCItemDeadbandMgt::SetItemDeadband ( unsigned long dwCount, unsigned long * phServer, float * pPercentDeadband, HRESULT * * ppErrors ) {
	HRESULT _hr = raw_SetItemDeadband(dwCount, phServer, pPercentDeadband, ppErrors);
	if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(this));
	return _hr;
}

HRESULT IOPCItemDeadbandMgt::GetItemDeadband ( unsigned long dwCount, unsigned long * phServer, float * * ppPercentDeadband, HRESULT * * ppErrors ) {
	HRESULT _hr = raw_GetItemDeadband(dwCount, phServer, ppPercentDeadband, ppErrors);
	if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(this));
	return _hr;
}

HRESULT IOPCItemDeadbandMgt::ClearItemDeadband ( unsigned long dwCount, unsigned long * phServer, HRESULT * * ppErrors ) {
	HRESULT _hr = raw_ClearItemDeadband(dwCount, phServer, ppErrors);
	if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(this));
	return _hr;
}

//
// interface IOPCItemSamplingMgt wrapper method implementations
//

HRESULT IOPCItemSamplingMgt::SetItemSamplingRate ( unsigned long dwCount, unsigned long * phServer, unsigned long * pdwRequestedSamplingRate, unsigned long * * ppdwRevisedSamplingRate, HRESULT * * ppErrors ) {
	HRESULT _hr = raw_SetItemSamplingRate(dwCount, phServer, pdwRequestedSamplingRate, ppdwRevisedSamplingRate, ppErrors);
	if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(this));
	return _hr;
}

HRESULT IOPCItemSamplingMgt::GetItemSamplingRate ( unsigned long dwCount, unsigned long * phServer, unsigned long * * ppdwSamplingRate, HRESULT * * ppErrors ) {
	HRESULT _hr = raw_GetItemSamplingRate(dwCount, phServer, ppdwSamplingRate, ppErrors);
	if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(this));
	return _hr;
}

HRESULT IOPCItemSamplingMgt::ClearItemSamplingRate ( unsigned long dwCount, unsigned long * phServer, HRESULT * * ppErrors ) {
	HRESULT _hr = raw_ClearItemSamplingRate(dwCount, phServer, ppErrors);
	if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(this));
	return _hr;
}

HRESULT IOPCItemSamplingMgt::SetItemBufferEnable ( unsigned long dwCount, unsigned long * phServer, long * pbEnable, HRESULT * * ppErrors ) {
	HRESULT _hr = raw_SetItemBufferEnable(dwCount, phServer, pbEnable, ppErrors);
	if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(this));
	return _hr;
}

HRESULT IOPCItemSamplingMgt::GetItemBufferEnable ( unsigned long dwCount, unsigned long * phServer, long * * ppbEnable, HRESULT * * ppErrors ) {
	HRESULT _hr = raw_GetItemBufferEnable(dwCount, phServer, ppbEnable, ppErrors);
	if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(this));
	return _hr;
}

//
// interface IOPCBrowse wrapper method implementations
//

HRESULT IOPCBrowse::GetProperties ( unsigned long dwItemCount, LPWSTR * pszItemIDs, long bReturnPropertyValues, unsigned long dwPropertyCount, unsigned long * pdwPropertyIDs, struct tagOPCITEMPROPERTIES * * ppItemProperties ) {
	HRESULT _hr = raw_GetProperties(dwItemCount, pszItemIDs, bReturnPropertyValues, dwPropertyCount, pdwPropertyIDs, ppItemProperties);
	if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(this));
	return _hr;
}

HRESULT IOPCBrowse::Browse ( LPWSTR szItemID, LPWSTR * pszContinuationPoint, unsigned long dwMaxElementsReturned, enum tagOPCBROWSEFILTER dwBrowseFilter, LPWSTR szElementNameFilter, LPWSTR szVendorFilter, long bReturnAllProperties, long bReturnPropertyValues, unsigned long dwPropertyCount, unsigned long * pdwPropertyIDs, long * pbMoreElements, unsigned long * pdwCount, struct tagOPCBROWSEELEMENT * * ppBrowseElements ) {
	HRESULT _hr = raw_Browse(szItemID, pszContinuationPoint, dwMaxElementsReturned, dwBrowseFilter, szElementNameFilter, szVendorFilter, bReturnAllProperties, bReturnPropertyValues, dwPropertyCount, pdwPropertyIDs, pbMoreElements, pdwCount, ppBrowseElements);
	if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(this));
	return _hr;
}

//
// interface IOPCItemIO wrapper method implementations
//

HRESULT IOPCItemIO::Read ( unsigned long dwCount, LPWSTR * pszItemIDs, unsigned long * pdwMaxAge, VARIANT * * ppvValues, unsigned short * * ppwQualities, struct _FILETIME * * ppftTimeStamps, HRESULT * * ppErrors ) {
	HRESULT _hr = raw_Read(dwCount, pszItemIDs, pdwMaxAge, ppvValues, ppwQualities, ppftTimeStamps, ppErrors);
	if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(this));
	return _hr;
}

HRESULT IOPCItemIO::WriteVQT ( unsigned long dwCount, LPWSTR * pszItemIDs, struct tagOPCITEMVQT * pItemVQT, HRESULT * * ppErrors ) {
	HRESULT _hr = raw_WriteVQT(dwCount, pszItemIDs, pItemVQT, ppErrors);
	if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(this));
	return _hr;
}

//
// interface IOPCSyncIO2 wrapper method implementations
//

HRESULT IOPCSyncIO2::ReadMaxAge ( unsigned long dwCount, unsigned long * phServer, unsigned long * pdwMaxAge, VARIANT * * ppvValues, unsigned short * * ppwQualities, struct _FILETIME * * ppftTimeStamps, HRESULT * * ppErrors ) {
	HRESULT _hr = raw_ReadMaxAge(dwCount, phServer, pdwMaxAge, ppvValues, ppwQualities, ppftTimeStamps, ppErrors);
	if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(this));
	return _hr;
}

HRESULT IOPCSyncIO2::WriteVQT ( unsigned long dwCount, unsigned long * phServer, struct tagOPCITEMVQT * pItemVQT, HRESULT * * ppErrors ) {
	HRESULT _hr = raw_WriteVQT(dwCount, phServer, pItemVQT, ppErrors);
	if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(this));
	return _hr;
}

//
// interface IOPCAsyncIO3 wrapper method implementations
//

HRESULT IOPCAsyncIO3::ReadMaxAge ( unsigned long dwCount, unsigned long * phServer, unsigned long * pdwMaxAge, unsigned long dwTransactionID, unsigned long * pdwCancelID, HRESULT * * ppErrors ) {
	HRESULT _hr = raw_ReadMaxAge(dwCount, phServer, pdwMaxAge, dwTransactionID, pdwCancelID, ppErrors);
	if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(this));
	return _hr;
}

HRESULT IOPCAsyncIO3::WriteVQT ( unsigned long dwCount, unsigned long * phServer, struct tagOPCITEMVQT * pItemVQT, unsigned long dwTransactionID, unsigned long * pdwCancelID, HRESULT * * ppErrors ) {
	HRESULT _hr = raw_WriteVQT(dwCount, phServer, pItemVQT, dwTransactionID, pdwCancelID, ppErrors);
	if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(this));
	return _hr;
}

HRESULT IOPCAsyncIO3::RefreshMaxAge ( unsigned long dwMaxAge, unsigned long dwTransactionID, unsigned long * pdwCancelID ) {
	HRESULT _hr = raw_RefreshMaxAge(dwMaxAge, dwTransactionID, pdwCancelID);
	if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(this));
	return _hr;
}

//
// interface IOPCGroupStateMgt2 wrapper method implementations
//

HRESULT IOPCGroupStateMgt2::SetKeepAlive ( unsigned long dwKeepAliveTime, unsigned long * pdwRevisedKeepAliveTime ) {
	HRESULT _hr = raw_SetKeepAlive(dwKeepAliveTime, pdwRevisedKeepAliveTime);
	if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(this));
	return _hr;
}

HRESULT IOPCGroupStateMgt2::GetKeepAlive ( unsigned long * pdwKeepAliveTime ) {
	HRESULT _hr = raw_GetKeepAlive(pdwKeepAliveTime);
	if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(this));
	return _hr;
}
