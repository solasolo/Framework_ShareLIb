#include "stdafx.h"

#include "OPCEventHandle.h"

OPCEvnetHandler::OPCEvnetHandler()
{
	this->m_dwRef = 0;
}

STDMETHODIMP OPCEvnetHandler::QueryInterface(REFIID riid, void** ppv)
{
	if (riid == IID_IUnknown)
	{
		*ppv = (IUnknown*)this;
	}
	else if (riid == __uuidof(IOPCDataCallback))
	{
		*ppv = (IOPCDataCallback*)this;
	}
	else
	{
		return (*ppv = 0), E_NOINTERFACE;
	}

	((IUnknown*)*ppv)->AddRef();

   return S_OK; 
}

ULONG STDMETHODCALLTYPE OPCEvnetHandler::AddRef(void)
{
	return ++m_dwRef;
}

ULONG STDMETHODCALLTYPE OPCEvnetHandler::Release(void)
{
   ULONG result = --m_dwRef;

   if (result == 0)
   {
     delete this;
   }

   return result;
}

STDMETHODIMP OPCEvnetHandler::raw_OnDataChange ( unsigned long dwTransid, unsigned long hGroup, HRESULT hrMasterquality, HRESULT hrMastererror, unsigned long dwCount, unsigned long * phClientItems, VARIANT * pvValues, unsigned short * pwQualities, struct _FILETIME * pftTimeStamps, HRESULT * pErrors)
{
	return S_OK;
}

STDMETHODIMP OPCEvnetHandler::raw_OnReadComplete ( unsigned long dwTransid, unsigned long hGroup, HRESULT hrMasterquality, HRESULT hrMastererror, unsigned long dwCount, unsigned long * phClientItems, VARIANT * pvValues, unsigned short * pwQualities, struct _FILETIME * pftTimeStamps, HRESULT * pErrors)
{
	return S_OK;
}

STDMETHODIMP OPCEvnetHandler::raw_OnWriteComplete ( unsigned long dwTransid, unsigned long hGroup, HRESULT hrMastererr, unsigned long dwCount, unsigned long * pClienthandles, HRESULT * pErrors)
{
	return S_OK;
}

STDMETHODIMP OPCEvnetHandler::raw_OnCancelComplete ( unsigned long dwTransid, unsigned long hGroup)
{
	return S_OK;
}

