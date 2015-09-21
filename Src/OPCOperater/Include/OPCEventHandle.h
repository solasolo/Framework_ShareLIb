#pragma once

#include <atlbase.h>
#include <atlcom.h>

#include "OPCDA3.h"

using namespace OPCDA;

class OPCEvnetHandler : public IOPCDataCallback
{
private:
	unsigned int m_dwRef;

public:
	OPCEvnetHandler();

	HRESULT STDMETHODCALLTYPE QueryInterface(REFIID riid, void** ppv);
	ULONG STDMETHODCALLTYPE AddRef(void);
	ULONG STDMETHODCALLTYPE Release(void);

	HRESULT STDMETHODCALLTYPE raw_OnDataChange ( unsigned long dwTransid, unsigned long hGroup, HRESULT hrMasterquality, HRESULT hrMastererror, unsigned long dwCount, unsigned long * phClientItems, VARIANT * pvValues, unsigned short * pwQualities, struct _FILETIME * pftTimeStamps, HRESULT * pErrors);
	HRESULT STDMETHODCALLTYPE raw_OnReadComplete ( unsigned long dwTransid, unsigned long hGroup, HRESULT hrMasterquality, HRESULT hrMastererror, unsigned long dwCount, unsigned long * phClientItems, VARIANT * pvValues, unsigned short * pwQualities, struct _FILETIME * pftTimeStamps, HRESULT * pErrors);
	HRESULT STDMETHODCALLTYPE raw_OnWriteComplete ( unsigned long dwTransid, unsigned long hGroup, HRESULT hrMastererr, unsigned long dwCount, unsigned long * pClienthandles, HRESULT * pErrors);
	HRESULT STDMETHODCALLTYPE raw_OnCancelComplete ( unsigned long dwTransid, unsigned long hGroup);
};