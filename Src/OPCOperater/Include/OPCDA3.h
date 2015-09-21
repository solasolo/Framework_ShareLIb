// Created by Microsoft (R) C/C++ Compiler Version 14.00.50727.762 (89dfebe6).
//
// C:\DOCUME~1\BRETT~1.GLE\LOCALS~1\Temp\opcproxy.tlh
//
// C++ source equivalent of Win32 type library opcproxy.dll
// compiler-generated file created 06/04/08 at 12:52:35 - DO NOT EDIT!

#pragma once
#pragma pack(push, 8)

#include <comdef.h>

namespace OPCDA
{
	typedef DWORD OPCHANDLE;

	

	//
	// Forward references and typedefs
	//

	struct __declspec(uuid("63d5f430-cfe4-11d1-b2c8-0060083ba1fb"))
		/* interface */ CATID_OPCDAServer10;
	struct __declspec(uuid("63d5f432-cfe4-11d1-b2c8-0060083ba1fb"))
		/* interface */ CATID_OPCDAServer20;
	struct __declspec(uuid("cc603642-66d7-48f1-b69a-b625e73652d7"))
		/* interface */ CATID_OPCDAServer30;
	struct __declspec(uuid("3098eda4-a006-48b2-a27f-247453959408"))
		/* interface */ CATID_XMLDAServer10;
	struct __declspec(uuid("39c13a4d-011e-11d0-9675-0020afd8adb3"))
		/* interface */ IOPCServer;

	struct tagOPCSERVERSTATUS;
	enum tagOPCSERVERSTATE;
	enum tagOPCENUMSCOPE;
	struct __declspec(uuid("39c13a4e-011e-11d0-9675-0020afd8adb3"))
		/* interface */ IOPCServerPublicGroups;
	struct __declspec(uuid("39c13a4f-011e-11d0-9675-0020afd8adb3"))
		/* interface */ IOPCBrowseServerAddressSpace;
	enum tagOPCNAMESPACETYPE;
	enum tagOPCBROWSEDIRECTION;
	enum tagOPCBROWSETYPE;
	struct __declspec(uuid("39c13a50-011e-11d0-9675-0020afd8adb3"))
		/* interface */ IOPCGroupStateMgt;
	struct __declspec(uuid("39c13a51-011e-11d0-9675-0020afd8adb3"))
		/* interface */ IOPCPublicGroupStateMgt;
	struct __declspec(uuid("39c13a52-011e-11d0-9675-0020afd8adb3"))
		/* interface */ IOPCSyncIO;
	enum tagOPCDATASOURCE;
	struct tagOPCITEMSTATE;
	struct __declspec(uuid("39c13a53-011e-11d0-9675-0020afd8adb3"))
		/* interface */ IOPCAsyncIO;
	struct __declspec(uuid("39c13a70-011e-11d0-9675-0020afd8adb3"))
		/* interface */ IOPCDataCallback;
	struct __declspec(uuid("39c13a54-011e-11d0-9675-0020afd8adb3"))
		/* interface */ IOPCItemMgt;
	struct tagOPCITEMDEF;
	struct tagOPCITEMRESULT;
	struct __declspec(uuid("39c13a55-011e-11d0-9675-0020afd8adb3"))
		/* interface */ IEnumOPCItemAttributes;
	struct tagOPCITEMATTRIBUTES;
	enum tagOPCEUTYPE;
	struct __declspec(uuid("39c13a71-011e-11d0-9675-0020afd8adb3"))
		/* interface */ IOPCAsyncIO2;
	struct __declspec(uuid("39c13a72-011e-11d0-9675-0020afd8adb3"))
		/* interface */ IOPCItemProperties;
	struct __declspec(uuid("5946da93-8b39-4ec8-ab3d-aa73df5bc86f"))
		/* interface */ IOPCItemDeadbandMgt;
	struct __declspec(uuid("3e22d313-f08b-41a5-86c8-95e95cb49ffc"))
		/* interface */ IOPCItemSamplingMgt;
	struct __declspec(uuid("39227004-a18f-4b57-8b0a-5235670f4468"))
		/* interface */ IOPCBrowse;
	struct tagOPCITEMPROPERTIES;
	struct tagOPCITEMPROPERTY;
	enum tagOPCBROWSEFILTER;
	struct tagOPCBROWSEELEMENT;
	struct __declspec(uuid("85c0b427-2893-4cbc-bd78-e5fc5146f08f"))
		/* interface */ IOPCItemIO;
	struct tagOPCITEMVQT;
	struct __declspec(uuid("730f5f0f-55b1-4c81-9e18-ff8a0904e1fa"))
		/* interface */ IOPCSyncIO2;
	struct __declspec(uuid("0967b97b-36ef-423e-b6f8-6bff1e40d39d"))
		/* interface */ IOPCAsyncIO3;
	struct __declspec(uuid("8e368666-d72e-4f78-87ed-647611c61c9f"))
		/* interface */ IOPCGroupStateMgt2;

	//
	// Smart pointer typedef declarations
	//

	_COM_SMARTPTR_TYPEDEF(CATID_OPCDAServer10, __uuidof(CATID_OPCDAServer10));
	_COM_SMARTPTR_TYPEDEF(CATID_OPCDAServer20, __uuidof(CATID_OPCDAServer20));
	_COM_SMARTPTR_TYPEDEF(CATID_OPCDAServer30, __uuidof(CATID_OPCDAServer30));
	_COM_SMARTPTR_TYPEDEF(CATID_XMLDAServer10, __uuidof(CATID_XMLDAServer10));
	_COM_SMARTPTR_TYPEDEF(IOPCServer, __uuidof(IOPCServer));
	_COM_SMARTPTR_TYPEDEF(IOPCServerPublicGroups, __uuidof(IOPCServerPublicGroups));
	_COM_SMARTPTR_TYPEDEF(IOPCBrowseServerAddressSpace, __uuidof(IOPCBrowseServerAddressSpace));
	_COM_SMARTPTR_TYPEDEF(IOPCGroupStateMgt, __uuidof(IOPCGroupStateMgt));
	_COM_SMARTPTR_TYPEDEF(IOPCPublicGroupStateMgt, __uuidof(IOPCPublicGroupStateMgt));
	_COM_SMARTPTR_TYPEDEF(IOPCSyncIO, __uuidof(IOPCSyncIO));
	_COM_SMARTPTR_TYPEDEF(IOPCAsyncIO, __uuidof(IOPCAsyncIO));
	_COM_SMARTPTR_TYPEDEF(IOPCDataCallback, __uuidof(IOPCDataCallback));
	_COM_SMARTPTR_TYPEDEF(IOPCItemMgt, __uuidof(IOPCItemMgt));
	_COM_SMARTPTR_TYPEDEF(IEnumOPCItemAttributes, __uuidof(IEnumOPCItemAttributes));
	_COM_SMARTPTR_TYPEDEF(IOPCAsyncIO2, __uuidof(IOPCAsyncIO2));
	_COM_SMARTPTR_TYPEDEF(IOPCItemProperties, __uuidof(IOPCItemProperties));
	_COM_SMARTPTR_TYPEDEF(IOPCItemDeadbandMgt, __uuidof(IOPCItemDeadbandMgt));
	_COM_SMARTPTR_TYPEDEF(IOPCItemSamplingMgt, __uuidof(IOPCItemSamplingMgt));
	_COM_SMARTPTR_TYPEDEF(IOPCBrowse, __uuidof(IOPCBrowse));
	_COM_SMARTPTR_TYPEDEF(IOPCItemIO, __uuidof(IOPCItemIO));
	_COM_SMARTPTR_TYPEDEF(IOPCSyncIO2, __uuidof(IOPCSyncIO2));
	_COM_SMARTPTR_TYPEDEF(IOPCAsyncIO3, __uuidof(IOPCAsyncIO3));
	_COM_SMARTPTR_TYPEDEF(IOPCGroupStateMgt2, __uuidof(IOPCGroupStateMgt2));

	//
	// Type library items
	//

	struct __declspec(uuid("63d5f430-cfe4-11d1-b2c8-0060083ba1fb"))
CATID_OPCDAServer10 : IUnknown
	{};

	struct __declspec(uuid("63d5f432-cfe4-11d1-b2c8-0060083ba1fb"))
CATID_OPCDAServer20 : IUnknown
	{};

	struct __declspec(uuid("cc603642-66d7-48f1-b69a-b625e73652d7"))
CATID_OPCDAServer30 : IUnknown
	{};

	struct __declspec(uuid("3098eda4-a006-48b2-a27f-247453959408"))
CATID_XMLDAServer10 : IUnknown
	{};
	const LPWSTR OPC_CATEGORY_DESCRIPTION_DA10 = (wchar_t*) L"OPC Data Access Servers Version 1.0";
	const LPWSTR OPC_CATEGORY_DESCRIPTION_DA20 = (wchar_t*) L"OPC Data Access Servers Version 2.0";
	const LPWSTR OPC_CATEGORY_DESCRIPTION_DA30 = (wchar_t*) L"OPC Data Access Servers Version 3.0";
	const LPWSTR OPC_CATEGORY_DESCRIPTION_XMLDA10 = (wchar_t*) L"OPC XML Data Access Servers Version 1.0";
	const unsigned long OPC_READABLE = 1;
	const unsigned long OPC_WRITEABLE = 2;
	const unsigned long OPC_BROWSE_HASCHILDREN = 1;
	const unsigned long OPC_BROWSE_ISITEM = 2;
	const LPWSTR OPC_TYPE_SYSTEM_OPCBINARY = (wchar_t*) L"OPCBinary";
	const LPWSTR OPC_TYPE_SYSTEM_XMLSCHEMA = (wchar_t*) L"XMLSchema";
	const LPWSTR OPC_CONSISTENCY_WINDOW_UNKNOWN = (wchar_t*) L"Unknown";
	const LPWSTR OPC_CONSISTENCY_WINDOW_NOT_CONSISTENT = (wchar_t*) L"Not Consistent";
	const LPWSTR OPC_WRITE_BEHAVIOR_BEST_EFFORT = (wchar_t*) L"Best Effort";
	const LPWSTR OPC_WRITE_BEHAVIOR_ALL_OR_NOTHING = (wchar_t*) L"All or Nothing";
	const unsigned short OPC_QUALITY_MASK = 192;
	const unsigned short OPC_STATUS_MASK = 252;
	const unsigned short OPC_LIMIT_MASK = 3;
	const unsigned short OPC_QUALITY_BAD = 0;
	const unsigned short OPC_QUALITY_UNCERTAIN = 64;
	const unsigned short OPC_QUALITY_GOOD = 192;
	const unsigned short OPC_QUALITY_CONFIG_ERROR = 4;
	const unsigned short OPC_QUALITY_NOT_CONNECTED = 8;
	const unsigned short OPC_QUALITY_DEVICE_FAILURE = 12;
	const unsigned short OPC_QUALITY_SENSOR_FAILURE = 16;
	const unsigned short OPC_QUALITY_LAST_KNOWN = 20;
	const unsigned short OPC_QUALITY_COMM_FAILURE = 24;
	const unsigned short OPC_QUALITY_OUT_OF_SERVICE = 28;
	const unsigned short OPC_QUALITY_WAITING_FOR_INITIAL_DATA = 32;
	const unsigned short OPC_QUALITY_LAST_USABLE = 68;
	const unsigned short OPC_QUALITY_SENSOR_CAL = 80;
	const unsigned short OPC_QUALITY_EGU_EXCEEDED = 84;
	const unsigned short OPC_QUALITY_SUB_NORMAL = 88;
	const unsigned short OPC_QUALITY_LOCAL_OVERRIDE = 216;
	const unsigned short OPC_LIMIT_OK = 0;
	const unsigned short OPC_LIMIT_LOW = 1;
	const unsigned short OPC_LIMIT_HIGH = 2;
	const unsigned short OPC_LIMIT_CONST = 3;
	const unsigned long OPC_PROPERTY_DATATYPE = 1;
	const unsigned long OPC_PROPERTY_VALUE = 2;
	const unsigned long OPC_PROPERTY_QUALITY = 3;
	const unsigned long OPC_PROPERTY_TIMESTAMP = 4;
	const unsigned long OPC_PROPERTY_ACCESS_RIGHTS = 5;
	const unsigned long OPC_PROPERTY_SCAN_RATE = 6;
	const unsigned long OPC_PROPERTY_EU_TYPE = 7;
	const unsigned long OPC_PROPERTY_EU_INFO = 8;
	const unsigned long OPC_PROPERTY_EU_UNITS = 100;
	const unsigned long OPC_PROPERTY_DESCRIPTION = 101;
	const unsigned long OPC_PROPERTY_HIGH_EU = 102;
	const unsigned long OPC_PROPERTY_LOW_EU = 103;
	const unsigned long OPC_PROPERTY_HIGH_IR = 104;
	const unsigned long OPC_PROPERTY_LOW_IR = 105;
	const unsigned long OPC_PROPERTY_CLOSE_LABEL = 106;
	const unsigned long OPC_PROPERTY_OPEN_LABEL = 107;
	const unsigned long OPC_PROPERTY_TIMEZONE = 108;
	const unsigned long OPC_PROPERTY_CONDITION_STATUS = 300;
	const unsigned long OPC_PROPERTY_ALARM_QUICK_HELP = 301;
	const unsigned long OPC_PROPERTY_ALARM_AREA_LIST = 302;
	const unsigned long OPC_PROPERTY_PRIMARY_ALARM_AREA = 303;
	const unsigned long OPC_PROPERTY_CONDITION_LOGIC = 304;
	const unsigned long OPC_PROPERTY_LIMIT_EXCEEDED = 305;
	const unsigned long OPC_PROPERTY_DEADBAND = 306;
	const unsigned long OPC_PROPERTY_HIHI_LIMIT = 307;
	const unsigned long OPC_PROPERTY_HI_LIMIT = 308;
	const unsigned long OPC_PROPERTY_LO_LIMIT = 309;
	const unsigned long OPC_PROPERTY_LOLO_LIMIT = 310;
	const unsigned long OPC_PROPERTY_CHANGE_RATE_LIMIT = 311;
	const unsigned long OPC_PROPERTY_DEVIATION_LIMIT = 312;
	const unsigned long OPC_PROPERTY_SOUND_FILE = 313;
	const unsigned long OPC_PROPERTY_TYPE_SYSTEM_ID = 600;
	const unsigned long OPC_PROPERTY_DICTIONARY_ID = 601;
	const unsigned long OPC_PROPERTY_TYPE_ID = 602;
	const unsigned long OPC_PROPERTY_DICTIONARY = 603;
	const unsigned long OPC_PROPERTY_TYPE_DESCRIPTION = 604;
	const unsigned long OPC_PROPERTY_CONSISTENCY_WINDOW = 605;
	const unsigned long OPC_PROPERTY_WRITE_BEHAVIOR = 606;
	const unsigned long OPC_PROPERTY_UNCONVERTED_ITEM_ID = 607;
	const unsigned long OPC_PROPERTY_UNFILTERED_ITEM_ID = 608;
	const unsigned long OPC_PROPERTY_DATA_FILTER_VALUE = 609;
	const LPWSTR OPC_PROPERTY_DESC_DATATYPE = (wchar_t*) L"Item Canonical Data Type";
	const LPWSTR OPC_PROPERTY_DESC_VALUE = (wchar_t*) L"Item Value";
	const LPWSTR OPC_PROPERTY_DESC_QUALITY = (wchar_t*) L"Item Quality";
	const LPWSTR OPC_PROPERTY_DESC_TIMESTAMP = (wchar_t*) L"Item Timestamp";
	const LPWSTR OPC_PROPERTY_DESC_ACCESS_RIGHTS = (wchar_t*) L"Item Access Rights";
	const LPWSTR OPC_PROPERTY_DESC_SCAN_RATE = (wchar_t*) L"Server Scan Rate";
	const LPWSTR OPC_PROPERTY_DESC_EU_TYPE = (wchar_t*) L"Item EU Type";
	const LPWSTR OPC_PROPERTY_DESC_EU_INFO = (wchar_t*) L"Item EU Info";
	const LPWSTR OPC_PROPERTY_DESC_EU_UNITS = (wchar_t*) L"EU Units";
	const LPWSTR OPC_PROPERTY_DESC_DESCRIPTION = (wchar_t*) L"Item Description";
	const LPWSTR OPC_PROPERTY_DESC_HIGH_EU = (wchar_t*) L"High EU";
	const LPWSTR OPC_PROPERTY_DESC_LOW_EU = (wchar_t*) L"Low EU";
	const LPWSTR OPC_PROPERTY_DESC_HIGH_IR = (wchar_t*) L"High Instrument Range";
	const LPWSTR OPC_PROPERTY_DESC_LOW_IR = (wchar_t*) L"Low Instrument Range";
	const LPWSTR OPC_PROPERTY_DESC_CLOSE_LABEL = (wchar_t*) L"Contact Close Label";
	const LPWSTR OPC_PROPERTY_DESC_OPEN_LABEL = (wchar_t*) L"Contact Open Label";
	const LPWSTR OPC_PROPERTY_DESC_TIMEZONE = (wchar_t*) L"Item Timezone";
	const LPWSTR OPC_PROPERTY_DESC_CONDITION_STATUS = (wchar_t*) L"Condition Status";
	const LPWSTR OPC_PROPERTY_DESC_ALARM_QUICK_HELP = (wchar_t*) L"Alarm Quick Help";
	const LPWSTR OPC_PROPERTY_DESC_ALARM_AREA_LIST = (wchar_t*) L"Alarm Area List";
	const LPWSTR OPC_PROPERTY_DESC_PRIMARY_ALARM_AREA = (wchar_t*) L"Primary Alarm Area";
	const LPWSTR OPC_PROPERTY_DESC_CONDITION_LOGIC = (wchar_t*) L"Condition Logic";
	const LPWSTR OPC_PROPERTY_DESC_LIMIT_EXCEEDED = (wchar_t*) L"Limit Exceeded";
	const LPWSTR OPC_PROPERTY_DESC_DEADBAND = (wchar_t*) L"Deadband";
	const LPWSTR OPC_PROPERTY_DESC_HIHI_LIMIT = (wchar_t*) L"HiHi Limit";
	const LPWSTR OPC_PROPERTY_DESC_HI_LIMIT = (wchar_t*) L"Hi Limit";
	const LPWSTR OPC_PROPERTY_DESC_LO_LIMIT = (wchar_t*) L"Lo Limit";
	const LPWSTR OPC_PROPERTY_DESC_LOLO_LIMIT = (wchar_t*) L"LoLo Limit";
	const LPWSTR OPC_PROPERTY_DESC_CHANGE_RATE_LIMIT = (wchar_t*) L"Rate of Change Limit";
	const LPWSTR OPC_PROPERTY_DESC_DEVIATION_LIMIT = (wchar_t*) L"Deviation Limit";
	const LPWSTR OPC_PROPERTY_DESC_SOUND_FILE = (wchar_t*) L"Sound File";
	const LPWSTR OPC_PROPERTY_DESC_TYPE_SYSTEM_ID = (wchar_t*) L"Type System ID";
	const LPWSTR OPC_PROPERTY_DESC_DICTIONARY_ID = (wchar_t*) L"Dictionary ID";
	const LPWSTR OPC_PROPERTY_DESC_TYPE_ID = (wchar_t*) L"Type ID";
	const LPWSTR OPC_PROPERTY_DESC_DICTIONARY = (wchar_t*) L"Dictionary";
	const LPWSTR OPC_PROPERTY_DESC_TYPE_DESCRIPTION = (wchar_t*) L"Type Description";
	const LPWSTR OPC_PROPERTY_DESC_CONSISTENCY_WINDOW = (wchar_t*) L"Consistency Window";
	const LPWSTR OPC_PROPERTY_DESC_WRITE_BEHAVIOR = (wchar_t*) L"Write Behavior";
	const LPWSTR OPC_PROPERTY_DESC_UNCONVERTED_ITEM_ID = (wchar_t*) L"Unconverted Item ID";
	const LPWSTR OPC_PROPERTY_DESC_UNFILTERED_ITEM_ID = (wchar_t*) L"Unfiltered Item ID";
	const LPWSTR OPC_PROPERTY_DESC_DATA_FILTER_VALUE = (wchar_t*) L"Data Filter Value";

	enum tagOPCSERVERSTATE
	{
		OPC_STATUS_RUNNING = 1,
		OPC_STATUS_FAILED = 2,
		OPC_STATUS_NOCONFIG = 3,
		OPC_STATUS_SUSPENDED = 4,
		OPC_STATUS_TEST = 5,
		OPC_STATUS_COMM_FAULT = 6
	};

#pragma pack(push, 4)

	struct tagOPCSERVERSTATUS
	{
		struct _FILETIME ftStartTime;
		struct _FILETIME ftCurrentTime;
		struct _FILETIME ftLastUpdateTime;
		enum tagOPCSERVERSTATE dwServerState;
		unsigned long dwGroupCount;
		unsigned long dwBandWidth;
		unsigned short wMajorVersion;
		unsigned short wMinorVersion;
		unsigned short wBuildNumber;
		unsigned short wReserved;
		LPWSTR szVendorInfo;
	};

#pragma pack(pop)

	enum tagOPCENUMSCOPE
	{
		OPC_ENUM_PRIVATE_CONNECTIONS = 1,
		OPC_ENUM_PUBLIC_CONNECTIONS = 2,
		OPC_ENUM_ALL_CONNECTIONS = 3,
		OPC_ENUM_PRIVATE = 4,
		OPC_ENUM_PUBLIC = 5,
		OPC_ENUM_ALL = 6
	};

	struct __declspec(uuid("39c13a4d-011e-11d0-9675-0020afd8adb3"))
IOPCServer : IUnknown
	{
		//
		// Wrapper methods for error-handling
		//

		IOPCItemMgtPtr AddGroup(LPWSTR szName, 
			long bActive, 
			unsigned long dwRequestedUpdateRate, 
			unsigned long hClientGroup, 
			long * pTimeBias, 
			float * pPercentDeadband, 
			unsigned long dwLCID,
			unsigned long * phServerGroup,
			unsigned long * pRevisedUpdateRate
			);
		HRESULT GetErrorString(HRESULT dwError, unsigned long dwLocale, LPWSTR * ppString);
		IOPCItemMgtPtr GetGroupByName(LPWSTR szName);
		HRESULT GetStatus(struct tagOPCSERVERSTATUS * * ppServerStatus);
		HRESULT RemoveGroup(unsigned long hServerGroup, long bForce);
		IUnknownPtr CreateGroupEnumerator(enum tagOPCENUMSCOPE dwScope );

		//
		// Raw methods provided by interface
		//

		virtual HRESULT __stdcall raw_AddGroup (
			/*[in]*/ LPWSTR szName,
			/*[in]*/ long bActive,
			/*[in]*/ unsigned long dwRequestedUpdateRate,
			/*[in]*/ unsigned long hClientGroup,
			/*[in]*/ long * pTimeBias,
			/*[in]*/ float * pPercentDeadband,
			/*[in]*/ unsigned long dwLCID,
			/*[out]*/ unsigned long * phServerGroup,
			/*[out]*/ unsigned long * pRevisedUpdateRate,
			/*[in]*/ GUID * riid,
			/*[out]*/ IUnknown * * ppUnk ) = 0;
		virtual HRESULT __stdcall raw_GetErrorString (
			/*[in]*/ HRESULT dwError,
			/*[in]*/ unsigned long dwLocale,
			/*[out]*/ LPWSTR * ppString ) = 0;
		virtual HRESULT __stdcall raw_GetGroupByName (
			/*[in]*/ LPWSTR szName,
			/*[in]*/ GUID * riid,
			/*[out]*/ IUnknown * * ppUnk ) = 0;
		virtual HRESULT __stdcall raw_GetStatus (
		/*[out]*/ struct tagOPCSERVERSTATUS * * ppServerStatus ) = 0;
		virtual HRESULT __stdcall raw_RemoveGroup (
			/*[in]*/ unsigned long hServerGroup,
			/*[in]*/ long bForce ) = 0;
		virtual HRESULT __stdcall raw_CreateGroupEnumerator (
			/*[in]*/ enum tagOPCENUMSCOPE dwScope,
			/*[in]*/ GUID * riid,
			/*[out]*/ IUnknown * * ppUnk ) = 0;
	};

	struct __declspec(uuid("39c13a4e-011e-11d0-9675-0020afd8adb3"))
IOPCServerPublicGroups : IUnknown
	{
		//
		// Wrapper methods for error-handling
		//

		HRESULT GetPublicGroupByName (
			LPWSTR szName,
			GUID * riid,
			IUnknown * * ppUnk );
		HRESULT RemovePublicGroup (
			unsigned long hServerGroup,
			long bForce );

		//
		// Raw methods provided by interface
		//

		virtual HRESULT __stdcall raw_GetPublicGroupByName (
			/*[in]*/ LPWSTR szName,
			/*[in]*/ GUID * riid,
			/*[out]*/ IUnknown * * ppUnk ) = 0;
		virtual HRESULT __stdcall raw_RemovePublicGroup (
			/*[in]*/ unsigned long hServerGroup,
			/*[in]*/ long bForce ) = 0;
	};

	enum tagOPCNAMESPACETYPE
	{
		OPC_NS_HIERARCHIAL = 1,
		OPC_NS_FLAT = 2
	};

	enum tagOPCBROWSEDIRECTION
	{
		OPC_BROWSE_UP = 1,
		OPC_BROWSE_DOWN = 2,
		OPC_BROWSE_TO = 3
	};

	enum tagOPCBROWSETYPE
	{
		OPC_BRANCH = 1,
		OPC_LEAF = 2,
		OPC_FLAT = 3
	};

	struct __declspec(uuid("39c13a4f-011e-11d0-9675-0020afd8adb3"))
IOPCBrowseServerAddressSpace : IUnknown
	{
		//
		// Wrapper methods for error-handling
		//

		HRESULT QueryOrganization (
			enum tagOPCNAMESPACETYPE * pNameSpaceType );
		HRESULT ChangeBrowsePosition (
			enum tagOPCBROWSEDIRECTION dwBrowseDirection,
			LPWSTR szString );
		HRESULT BrowseOPCItemIDs (
			enum tagOPCBROWSETYPE dwBrowseFilterType,
			LPWSTR szFilterCriteria,
			unsigned short vtDataTypeFilter,
			unsigned long dwAccessRightsFilter,
		struct IEnumString * * ppIEnumString );
		HRESULT GetItemID (
			LPWSTR szItemDataID,
			LPWSTR * szItemID );
		HRESULT BrowseAccessPaths (
			LPWSTR szItemID,
		struct IEnumString * * ppIEnumString );

		//
		// Raw methods provided by interface
		//

		virtual HRESULT __stdcall raw_QueryOrganization (
			/*[out]*/ enum tagOPCNAMESPACETYPE * pNameSpaceType ) = 0;
		virtual HRESULT __stdcall raw_ChangeBrowsePosition (
			/*[in]*/ enum tagOPCBROWSEDIRECTION dwBrowseDirection,
			/*[in]*/ LPWSTR szString ) = 0;
		virtual HRESULT __stdcall raw_BrowseOPCItemIDs (
			/*[in]*/ enum tagOPCBROWSETYPE dwBrowseFilterType,
			/*[in]*/ LPWSTR szFilterCriteria,
			/*[in]*/ unsigned short vtDataTypeFilter,
			/*[in]*/ unsigned long dwAccessRightsFilter,
		/*[out]*/ struct IEnumString * * ppIEnumString ) = 0;
		virtual HRESULT __stdcall raw_GetItemID (
			/*[in]*/ LPWSTR szItemDataID,
			/*[out]*/ LPWSTR * szItemID ) = 0;
		virtual HRESULT __stdcall raw_BrowseAccessPaths (
			/*[in]*/ LPWSTR szItemID,
		/*[out]*/ struct IEnumString * * ppIEnumString ) = 0;
	};

	struct __declspec(uuid("39c13a50-011e-11d0-9675-0020afd8adb3"))
IOPCGroupStateMgt : IUnknown
	{
		//
		// Wrapper methods for error-handling
		//

		HRESULT GetState (
			unsigned long * pUpdateRate,
			long * pActive,
			LPWSTR * ppName,
			long * pTimeBias,
			float * pPercentDeadband,
			unsigned long * pLCID,
			unsigned long * phClientGroup,
			unsigned long * phServerGroup );
		HRESULT SetState (
			unsigned long * pRequestedUpdateRate,
			unsigned long * pRevisedUpdateRate,
			long * pActive,
			long * pTimeBias,
			float * pPercentDeadband,
			unsigned long * pLCID,
			unsigned long * phClientGroup );
		HRESULT SetName (
			LPWSTR szName );
		HRESULT CloneGroup (
			LPWSTR szName,
			GUID * riid,
			IUnknown * * ppUnk );

		//
		// Raw methods provided by interface
		//

		virtual HRESULT __stdcall raw_GetState (
			/*[out]*/ unsigned long * pUpdateRate,
			/*[out]*/ long * pActive,
			/*[out]*/ LPWSTR * ppName,
			/*[out]*/ long * pTimeBias,
			/*[out]*/ float * pPercentDeadband,
			/*[out]*/ unsigned long * pLCID,
			/*[out]*/ unsigned long * phClientGroup,
			/*[out]*/ unsigned long * phServerGroup ) = 0;
		virtual HRESULT __stdcall raw_SetState (
			/*[in]*/ unsigned long * pRequestedUpdateRate,
			/*[out]*/ unsigned long * pRevisedUpdateRate,
			/*[in]*/ long * pActive,
			/*[in]*/ long * pTimeBias,
			/*[in]*/ float * pPercentDeadband,
			/*[in]*/ unsigned long * pLCID,
			/*[in]*/ unsigned long * phClientGroup ) = 0;
		virtual HRESULT __stdcall raw_SetName (
			/*[in]*/ LPWSTR szName ) = 0;
		virtual HRESULT __stdcall raw_CloneGroup (
			/*[in]*/ LPWSTR szName,
			/*[in]*/ GUID * riid,
			/*[out]*/ IUnknown * * ppUnk ) = 0;
	};

	struct __declspec(uuid("39c13a51-011e-11d0-9675-0020afd8adb3"))
IOPCPublicGroupStateMgt : IUnknown
	{
		//
		// Wrapper methods for error-handling
		//

		HRESULT GetState (
			long * pPublic );
		HRESULT MoveToPublic ( );

		//
		// Raw methods provided by interface
		//

		virtual HRESULT __stdcall raw_GetState (
			/*[out]*/ long * pPublic ) = 0;
		virtual HRESULT __stdcall raw_MoveToPublic ( ) = 0;
	};

	enum tagOPCDATASOURCE
	{
		OPC_DS_CACHE = 1,
		OPC_DS_DEVICE = 2
	};

#pragma pack(push, 8)

	struct tagOPCITEMSTATE
	{
		unsigned long hClient;
		struct _FILETIME ftTimeStamp;
		unsigned short wQuality;
		unsigned short wReserved;
		VARIANT vDataValue;
	};

#pragma pack(pop)

	struct __declspec(uuid("39c13a52-011e-11d0-9675-0020afd8adb3"))
IOPCSyncIO : IUnknown
	{
		//
		// Wrapper methods for error-handling
		//

		HRESULT Read (
			enum tagOPCDATASOURCE dwSource,
			unsigned long dwCount,
			unsigned long * phServer,
		struct tagOPCITEMSTATE * * ppItemValues,
			HRESULT * * ppErrors );
		HRESULT Write (
			unsigned long dwCount,
			unsigned long * phServer,
			VARIANT * pItemValues,
			HRESULT * * ppErrors );

		//
		// Raw methods provided by interface
		//

		virtual HRESULT __stdcall raw_Read (
			/*[in]*/ enum tagOPCDATASOURCE dwSource,
			/*[in]*/ unsigned long dwCount,
			/*[in]*/ unsigned long * phServer,
		/*[out]*/ struct tagOPCITEMSTATE * * ppItemValues,
			/*[out]*/ HRESULT * * ppErrors ) = 0;
		virtual HRESULT __stdcall raw_Write (
			/*[in]*/ unsigned long dwCount,
			/*[in]*/ unsigned long * phServer,
			/*[in]*/ VARIANT * pItemValues,
			/*[out]*/ HRESULT * * ppErrors ) = 0;
	};

	struct __declspec(uuid("39c13a53-011e-11d0-9675-0020afd8adb3"))
IOPCAsyncIO : IUnknown
	{
		//
		// Wrapper methods for error-handling
		//

		HRESULT Read (
			unsigned long dwConnection,
			enum tagOPCDATASOURCE dwSource,
			unsigned long dwCount,
			unsigned long * phServer,
			unsigned long * pTransactionID,
			HRESULT * * ppErrors );
		HRESULT Write (
			unsigned long dwConnection,
			unsigned long dwCount,
			unsigned long * phServer,
			VARIANT * pItemValues,
			unsigned long * pTransactionID,
			HRESULT * * ppErrors );
		HRESULT Refresh (
			unsigned long dwConnection,
			enum tagOPCDATASOURCE dwSource,
			unsigned long * pTransactionID );
		HRESULT Cancel (
			unsigned long dwTransactionID );

		//
		// Raw methods provided by interface
		//

		virtual HRESULT __stdcall raw_Read (
			/*[in]*/ unsigned long dwConnection,
			/*[in]*/ enum tagOPCDATASOURCE dwSource,
			/*[in]*/ unsigned long dwCount,
			/*[in]*/ unsigned long * phServer,
			/*[out]*/ unsigned long * pTransactionID,
			/*[out]*/ HRESULT * * ppErrors ) = 0;
		virtual HRESULT __stdcall raw_Write (
			/*[in]*/ unsigned long dwConnection,
			/*[in]*/ unsigned long dwCount,
			/*[in]*/ unsigned long * phServer,
			/*[in]*/ VARIANT * pItemValues,
			/*[out]*/ unsigned long * pTransactionID,
			/*[out]*/ HRESULT * * ppErrors ) = 0;
		virtual HRESULT __stdcall raw_Refresh (
			/*[in]*/ unsigned long dwConnection,
			/*[in]*/ enum tagOPCDATASOURCE dwSource,
			/*[out]*/ unsigned long * pTransactionID ) = 0;
		virtual HRESULT __stdcall raw_Cancel (
			/*[in]*/ unsigned long dwTransactionID ) = 0;
	};

	struct __declspec(uuid("39c13a70-011e-11d0-9675-0020afd8adb3"))
IOPCDataCallback : IUnknown
	{
		//
		// Wrapper methods for error-handling
		//

		HRESULT OnDataChange (
			unsigned long dwTransid,
			unsigned long hGroup,
			HRESULT hrMasterquality,
			HRESULT hrMastererror,
			unsigned long dwCount,
			unsigned long * phClientItems,
			VARIANT * pvValues,
			unsigned short * pwQualities,
		struct _FILETIME * pftTimeStamps,
			HRESULT * pErrors );
		HRESULT OnReadComplete (
			unsigned long dwTransid,
			unsigned long hGroup,
			HRESULT hrMasterquality,
			HRESULT hrMastererror,
			unsigned long dwCount,
			unsigned long * phClientItems,
			VARIANT * pvValues,
			unsigned short * pwQualities,
		struct _FILETIME * pftTimeStamps,
			HRESULT * pErrors );
		HRESULT OnWriteComplete (
			unsigned long dwTransid,
			unsigned long hGroup,
			HRESULT hrMastererr,
			unsigned long dwCount,
			unsigned long * pClienthandles,
			HRESULT * pErrors );
		HRESULT OnCancelComplete (
			unsigned long dwTransid,
			unsigned long hGroup );

		//
		// Raw methods provided by interface
		//

		virtual HRESULT __stdcall raw_OnDataChange (
			/*[in]*/ unsigned long dwTransid,
			/*[in]*/ unsigned long hGroup,
			/*[in]*/ HRESULT hrMasterquality,
			/*[in]*/ HRESULT hrMastererror,
			/*[in]*/ unsigned long dwCount,
			/*[in]*/ unsigned long * phClientItems,
			/*[in]*/ VARIANT * pvValues,
			/*[in]*/ unsigned short * pwQualities,
		/*[in]*/ struct _FILETIME * pftTimeStamps,
			/*[in]*/ HRESULT * pErrors ) = 0;
		virtual HRESULT __stdcall raw_OnReadComplete (
			/*[in]*/ unsigned long dwTransid,
			/*[in]*/ unsigned long hGroup,
			/*[in]*/ HRESULT hrMasterquality,
			/*[in]*/ HRESULT hrMastererror,
			/*[in]*/ unsigned long dwCount,
			/*[in]*/ unsigned long * phClientItems,
			/*[in]*/ VARIANT * pvValues,
			/*[in]*/ unsigned short * pwQualities,
		/*[in]*/ struct _FILETIME * pftTimeStamps,
			/*[in]*/ HRESULT * pErrors ) = 0;
		virtual HRESULT __stdcall raw_OnWriteComplete (
			/*[in]*/ unsigned long dwTransid,
			/*[in]*/ unsigned long hGroup,
			/*[in]*/ HRESULT hrMastererr,
			/*[in]*/ unsigned long dwCount,
			/*[in]*/ unsigned long * pClienthandles,
			/*[in]*/ HRESULT * pErrors ) = 0;
		virtual HRESULT __stdcall raw_OnCancelComplete (
			/*[in]*/ unsigned long dwTransid,
			/*[in]*/ unsigned long hGroup ) = 0;
	};

#pragma pack(push, 4)

	struct tagOPCITEMDEF
	{
		LPWSTR szAccessPath;
		LPWSTR szItemID;
		long bActive;
		unsigned long hClient;
		unsigned long dwBlobSize;
		unsigned char * pBlob;
		unsigned short vtRequestedDataType;
		unsigned short wReserved;
	};

#pragma pack(pop)

#pragma pack(push, 4)

	struct tagOPCITEMRESULT
	{
		unsigned long hServer;
		unsigned short vtCanonicalDataType;
		unsigned short wReserved;
		unsigned long dwAccessRights;
		unsigned long dwBlobSize;
		unsigned char * pBlob;
	};

#pragma pack(pop)

	struct __declspec(uuid("39c13a54-011e-11d0-9675-0020afd8adb3"))
IOPCItemMgt : IUnknown
	{
		//
		// Wrapper methods for error-handling
		//

		HRESULT AddItems(unsigned long dwCount, struct tagOPCITEMDEF* pItemArray, struct tagOPCITEMRESULT** ppAddResults, HRESULT** ppErrors);
		HRESULT ValidateItems(unsigned long dwCount, struct tagOPCITEMDEF* pItemArray, long bBlobUpdate, struct tagOPCITEMRESULT** ppValidationResults, HRESULT** ppErrors);
		HRESULT RemoveItems(unsigned long dwCount, unsigned long* phServer, HRESULT** ppErrors);
		HRESULT SetActiveState(unsigned long dwCount, unsigned long* phServer, long bActive, HRESULT** ppErrors);
		HRESULT SetClientHandles(unsigned long dwCount, unsigned long* phServer, unsigned long* phClient, HRESULT** ppErrors);
		HRESULT SetDatatypes(unsigned long dwCount, unsigned long* phServer, unsigned short* pRequestedDatatypes, HRESULT** ppErrors);
		IEnumOPCItemAttributesPtr CreateEnumerator();

		//
		// Raw methods provided by interface
		//

		virtual HRESULT __stdcall raw_AddItems (
			/*[in]*/ unsigned long dwCount,
		/*[in]*/ struct tagOPCITEMDEF * pItemArray,
		/*[out]*/ struct tagOPCITEMRESULT * * ppAddResults,
			/*[out]*/ HRESULT * * ppErrors ) = 0;
		virtual HRESULT __stdcall raw_ValidateItems (
			/*[in]*/ unsigned long dwCount,
		/*[in]*/ struct tagOPCITEMDEF * pItemArray,
			/*[in]*/ long bBlobUpdate,
		/*[out]*/ struct tagOPCITEMRESULT * * ppValidationResults,
			/*[out]*/ HRESULT * * ppErrors ) = 0;
		virtual HRESULT __stdcall raw_RemoveItems (
			/*[in]*/ unsigned long dwCount,
			/*[in]*/ unsigned long * phServer,
			/*[out]*/ HRESULT * * ppErrors ) = 0;
		virtual HRESULT __stdcall raw_SetActiveState (
			/*[in]*/ unsigned long dwCount,
			/*[in]*/ unsigned long * phServer,
			/*[in]*/ long bActive,
			/*[out]*/ HRESULT * * ppErrors ) = 0;
		virtual HRESULT __stdcall raw_SetClientHandles (
			/*[in]*/ unsigned long dwCount,
			/*[in]*/ unsigned long * phServer,
			/*[in]*/ unsigned long * phClient,
			/*[out]*/ HRESULT * * ppErrors ) = 0;
		virtual HRESULT __stdcall raw_SetDatatypes (
			/*[in]*/ unsigned long dwCount,
			/*[in]*/ unsigned long * phServer,
			/*[in]*/ unsigned short * pRequestedDatatypes,
			/*[out]*/ HRESULT * * ppErrors ) = 0;
		virtual HRESULT __stdcall raw_CreateEnumerator (
			/*[in]*/ GUID * riid,
			/*[out]*/ IUnknown * * ppUnk ) = 0;
	};

	enum tagOPCEUTYPE
	{
		OPC_NOENUM = 0,
		OPC_ANALOG = 1,
		OPC_ENUMERATED = 2
	};

#pragma pack(push, 8)

	struct tagOPCITEMATTRIBUTES
	{
		LPWSTR szAccessPath;
		LPWSTR szItemID;
		long bActive;
		unsigned long hClient;
		unsigned long hServer;
		unsigned long dwAccessRights;
		unsigned long dwBlobSize;
		unsigned char * pBlob;
		unsigned short vtRequestedDataType;
		unsigned short vtCanonicalDataType;
		enum tagOPCEUTYPE dwEUType;
		VARIANT vEUInfo;
	};

#pragma pack(pop)

	struct __declspec(uuid("39c13a55-011e-11d0-9675-0020afd8adb3"))
IEnumOPCItemAttributes : IUnknown
	{
		//
		// Wrapper methods for error-handling
		//

		HRESULT Next (
			unsigned long celt,
		struct tagOPCITEMATTRIBUTES * * ppItemArray,
			unsigned long * pceltFetched );
		HRESULT Skip (
			unsigned long celt );
		HRESULT Reset ( );
		HRESULT Clone (
		struct IEnumOPCItemAttributes * * ppEnumItemAttributes );

		//
		// Raw methods provided by interface
		//

		virtual HRESULT __stdcall raw_Next (
			/*[in]*/ unsigned long celt,
		/*[out]*/ struct tagOPCITEMATTRIBUTES * * ppItemArray,
			/*[out]*/ unsigned long * pceltFetched ) = 0;
		virtual HRESULT __stdcall raw_Skip (
			/*[in]*/ unsigned long celt ) = 0;
		virtual HRESULT __stdcall raw_Reset ( ) = 0;
		virtual HRESULT __stdcall raw_Clone (
		/*[out]*/ struct IEnumOPCItemAttributes * * ppEnumItemAttributes ) = 0;
	};

	struct __declspec(uuid("39c13a71-011e-11d0-9675-0020afd8adb3"))
IOPCAsyncIO2 : IUnknown
	{
		//
		// Wrapper methods for error-handling
		//

		HRESULT Read (
			unsigned long dwCount,
			unsigned long * phServer,
			unsigned long dwTransactionID,
			unsigned long * pdwCancelID,
			HRESULT * * ppErrors );
		HRESULT Write (
			unsigned long dwCount,
			unsigned long * phServer,
			VARIANT * pItemValues,
			unsigned long dwTransactionID,
			unsigned long * pdwCancelID,
			HRESULT * * ppErrors );
		HRESULT Refresh2 (
			enum tagOPCDATASOURCE dwSource,
			unsigned long dwTransactionID,
			unsigned long * pdwCancelID );
		HRESULT Cancel2 (
			unsigned long dwCancelID );
		HRESULT SetEnable (
			long bEnable );
		HRESULT GetEnable (
			long * pbEnable );

		//
		// Raw methods provided by interface
		//

		virtual HRESULT __stdcall raw_Read (
			/*[in]*/ unsigned long dwCount,
			/*[in]*/ unsigned long * phServer,
			/*[in]*/ unsigned long dwTransactionID,
			/*[out]*/ unsigned long * pdwCancelID,
			/*[out]*/ HRESULT * * ppErrors ) = 0;
		virtual HRESULT __stdcall raw_Write (
			/*[in]*/ unsigned long dwCount,
			/*[in]*/ unsigned long * phServer,
			/*[in]*/ VARIANT * pItemValues,
			/*[in]*/ unsigned long dwTransactionID,
			/*[out]*/ unsigned long * pdwCancelID,
			/*[out]*/ HRESULT * * ppErrors ) = 0;
		virtual HRESULT __stdcall raw_Refresh2 (
			/*[in]*/ enum tagOPCDATASOURCE dwSource,
			/*[in]*/ unsigned long dwTransactionID,
			/*[out]*/ unsigned long * pdwCancelID ) = 0;
		virtual HRESULT __stdcall raw_Cancel2 (
			/*[in]*/ unsigned long dwCancelID ) = 0;
		virtual HRESULT __stdcall raw_SetEnable (
			/*[in]*/ long bEnable ) = 0;
		virtual HRESULT __stdcall raw_GetEnable (
			/*[out]*/ long * pbEnable ) = 0;
	};

	struct __declspec(uuid("39c13a72-011e-11d0-9675-0020afd8adb3"))
IOPCItemProperties : IUnknown
	{
		//
		// Wrapper methods for error-handling
		//

		HRESULT QueryAvailableProperties (
			LPWSTR szItemID,
			unsigned long * pdwCount,
			unsigned long * * ppPropertyIDs,
			LPWSTR * * ppDescriptions,
			unsigned short * * ppvtDataTypes );
		HRESULT GetItemProperties (
			LPWSTR szItemID,
			unsigned long dwCount,
			unsigned long * pdwPropertyIDs,
			VARIANT * * ppvData,
			HRESULT * * ppErrors );
		HRESULT LookupItemIDs (
			LPWSTR szItemID,
			unsigned long dwCount,
			unsigned long * pdwPropertyIDs,
			LPWSTR * * ppszNewItemIDs,
			HRESULT * * ppErrors );

		//
		// Raw methods provided by interface
		//

		virtual HRESULT __stdcall raw_QueryAvailableProperties (
			/*[in]*/ LPWSTR szItemID,
			/*[out]*/ unsigned long * pdwCount,
			/*[out]*/ unsigned long * * ppPropertyIDs,
			/*[out]*/ LPWSTR * * ppDescriptions,
			/*[out]*/ unsigned short * * ppvtDataTypes ) = 0;
		virtual HRESULT __stdcall raw_GetItemProperties (
			/*[in]*/ LPWSTR szItemID,
			/*[in]*/ unsigned long dwCount,
			/*[in]*/ unsigned long * pdwPropertyIDs,
			/*[out]*/ VARIANT * * ppvData,
			/*[out]*/ HRESULT * * ppErrors ) = 0;
		virtual HRESULT __stdcall raw_LookupItemIDs (
			/*[in]*/ LPWSTR szItemID,
			/*[in]*/ unsigned long dwCount,
			/*[in]*/ unsigned long * pdwPropertyIDs,
			/*[out]*/ LPWSTR * * ppszNewItemIDs,
			/*[out]*/ HRESULT * * ppErrors ) = 0;
	};

	struct __declspec(uuid("5946da93-8b39-4ec8-ab3d-aa73df5bc86f"))
IOPCItemDeadbandMgt : IUnknown
	{
		//
		// Wrapper methods for error-handling
		//

		HRESULT SetItemDeadband (
			unsigned long dwCount,
			unsigned long * phServer,
			float * pPercentDeadband,
			HRESULT * * ppErrors );
		HRESULT GetItemDeadband (
			unsigned long dwCount,
			unsigned long * phServer,
			float * * ppPercentDeadband,
			HRESULT * * ppErrors );
		HRESULT ClearItemDeadband (
			unsigned long dwCount,
			unsigned long * phServer,
			HRESULT * * ppErrors );

		//
		// Raw methods provided by interface
		//

		virtual HRESULT __stdcall raw_SetItemDeadband (
			/*[in]*/ unsigned long dwCount,
			/*[in]*/ unsigned long * phServer,
			/*[in]*/ float * pPercentDeadband,
			/*[out]*/ HRESULT * * ppErrors ) = 0;
		virtual HRESULT __stdcall raw_GetItemDeadband (
			/*[in]*/ unsigned long dwCount,
			/*[in]*/ unsigned long * phServer,
			/*[out]*/ float * * ppPercentDeadband,
			/*[out]*/ HRESULT * * ppErrors ) = 0;
		virtual HRESULT __stdcall raw_ClearItemDeadband (
			/*[in]*/ unsigned long dwCount,
			/*[in]*/ unsigned long * phServer,
			/*[out]*/ HRESULT * * ppErrors ) = 0;
	};

	struct __declspec(uuid("3e22d313-f08b-41a5-86c8-95e95cb49ffc"))
IOPCItemSamplingMgt : IUnknown
	{
		//
		// Wrapper methods for error-handling
		//

		HRESULT SetItemSamplingRate (
			unsigned long dwCount,
			unsigned long * phServer,
			unsigned long * pdwRequestedSamplingRate,
			unsigned long * * ppdwRevisedSamplingRate,
			HRESULT * * ppErrors );
		HRESULT GetItemSamplingRate (
			unsigned long dwCount,
			unsigned long * phServer,
			unsigned long * * ppdwSamplingRate,
			HRESULT * * ppErrors );
		HRESULT ClearItemSamplingRate (
			unsigned long dwCount,
			unsigned long * phServer,
			HRESULT * * ppErrors );
		HRESULT SetItemBufferEnable (
			unsigned long dwCount,
			unsigned long * phServer,
			long * pbEnable,
			HRESULT * * ppErrors );
		HRESULT GetItemBufferEnable (
			unsigned long dwCount,
			unsigned long * phServer,
			long * * ppbEnable,
			HRESULT * * ppErrors );

		//
		// Raw methods provided by interface
		//

		virtual HRESULT __stdcall raw_SetItemSamplingRate (
			/*[in]*/ unsigned long dwCount,
			/*[in]*/ unsigned long * phServer,
			/*[in]*/ unsigned long * pdwRequestedSamplingRate,
			/*[out]*/ unsigned long * * ppdwRevisedSamplingRate,
			/*[out]*/ HRESULT * * ppErrors ) = 0;
		virtual HRESULT __stdcall raw_GetItemSamplingRate (
			/*[in]*/ unsigned long dwCount,
			/*[in]*/ unsigned long * phServer,
			/*[out]*/ unsigned long * * ppdwSamplingRate,
			/*[out]*/ HRESULT * * ppErrors ) = 0;
		virtual HRESULT __stdcall raw_ClearItemSamplingRate (
			/*[in]*/ unsigned long dwCount,
			/*[in]*/ unsigned long * phServer,
			/*[out]*/ HRESULT * * ppErrors ) = 0;
		virtual HRESULT __stdcall raw_SetItemBufferEnable (
			/*[in]*/ unsigned long dwCount,
			/*[in]*/ unsigned long * phServer,
			/*[in]*/ long * pbEnable,
			/*[out]*/ HRESULT * * ppErrors ) = 0;
		virtual HRESULT __stdcall raw_GetItemBufferEnable (
			/*[in]*/ unsigned long dwCount,
			/*[in]*/ unsigned long * phServer,
			/*[out]*/ long * * ppbEnable,
			/*[out]*/ HRESULT * * ppErrors ) = 0;
	};

#pragma pack(push, 8)

	struct tagOPCITEMPROPERTY
	{
		unsigned short vtDataType;
		unsigned short wReserved;
		unsigned long dwPropertyID;
		LPWSTR szItemID;
		LPWSTR szDescription;
		VARIANT vValue;
		HRESULT hrErrorID;
		unsigned long dwReserved;
	};

#pragma pack(pop)

#pragma pack(push, 4)

	struct tagOPCITEMPROPERTIES
	{
		HRESULT hrErrorID;
		unsigned long dwNumProperties;
		struct tagOPCITEMPROPERTY * pItemProperties;
		unsigned long dwReserved;
	};

#pragma pack(pop)

	enum tagOPCBROWSEFILTER
	{
		OPC_BROWSE_FILTER_ALL = 1,
		OPC_BROWSE_FILTER_BRANCHES = 2,
		OPC_BROWSE_FILTER_ITEMS = 3
	};

#pragma pack(push, 4)

	struct tagOPCBROWSEELEMENT
	{
		LPWSTR szName;
		LPWSTR szItemID;
		unsigned long dwFlagValue;
		unsigned long dwReserved;
		struct tagOPCITEMPROPERTIES ItemProperties;
	};

#pragma pack(pop)

	struct __declspec(uuid("39227004-a18f-4b57-8b0a-5235670f4468"))
IOPCBrowse : IUnknown
	{
		//
		// Wrapper methods for error-handling
		//

		HRESULT GetProperties (
			unsigned long dwItemCount,
			LPWSTR * pszItemIDs,
			long bReturnPropertyValues,
			unsigned long dwPropertyCount,
			unsigned long * pdwPropertyIDs,
		struct tagOPCITEMPROPERTIES * * ppItemProperties );
		HRESULT Browse (
			LPWSTR szItemID,
			LPWSTR * pszContinuationPoint,
			unsigned long dwMaxElementsReturned,
			enum tagOPCBROWSEFILTER dwBrowseFilter,
			LPWSTR szElementNameFilter,
			LPWSTR szVendorFilter,
			long bReturnAllProperties,
			long bReturnPropertyValues,
			unsigned long dwPropertyCount,
			unsigned long * pdwPropertyIDs,
			long * pbMoreElements,
			unsigned long * pdwCount,
		struct tagOPCBROWSEELEMENT * * ppBrowseElements );

		//
		// Raw methods provided by interface
		//

		virtual HRESULT __stdcall raw_GetProperties (
			/*[in]*/ unsigned long dwItemCount,
			/*[in]*/ LPWSTR * pszItemIDs,
			/*[in]*/ long bReturnPropertyValues,
			/*[in]*/ unsigned long dwPropertyCount,
			/*[in]*/ unsigned long * pdwPropertyIDs,
		/*[out]*/ struct tagOPCITEMPROPERTIES * * ppItemProperties ) = 0;
		virtual HRESULT __stdcall raw_Browse (
			/*[in]*/ LPWSTR szItemID,
			/*[in,out]*/ LPWSTR * pszContinuationPoint,
			/*[in]*/ unsigned long dwMaxElementsReturned,
			/*[in]*/ enum tagOPCBROWSEFILTER dwBrowseFilter,
			/*[in]*/ LPWSTR szElementNameFilter,
			/*[in]*/ LPWSTR szVendorFilter,
			/*[in]*/ long bReturnAllProperties,
			/*[in]*/ long bReturnPropertyValues,
			/*[in]*/ unsigned long dwPropertyCount,
			/*[in]*/ unsigned long * pdwPropertyIDs,
			/*[out]*/ long * pbMoreElements,
			/*[out]*/ unsigned long * pdwCount,
		/*[out]*/ struct tagOPCBROWSEELEMENT * * ppBrowseElements ) = 0;
	};

#pragma pack(push, 8)

	struct tagOPCITEMVQT
	{
		VARIANT vDataValue;
		long bQualitySpecified;
		unsigned short wQuality;
		unsigned short wReserved;
		long bTimeStampSpecified;
		unsigned long dwReserved;
		struct _FILETIME ftTimeStamp;
	};

#pragma pack(pop)

	struct __declspec(uuid("85c0b427-2893-4cbc-bd78-e5fc5146f08f"))
IOPCItemIO : IUnknown
	{
		//
		// Wrapper methods for error-handling
		//

		HRESULT Read (
			unsigned long dwCount,
			LPWSTR * pszItemIDs,
			unsigned long * pdwMaxAge,
			VARIANT * * ppvValues,
			unsigned short * * ppwQualities,
		struct _FILETIME * * ppftTimeStamps,
			HRESULT * * ppErrors );
		HRESULT WriteVQT (
			unsigned long dwCount,
			LPWSTR * pszItemIDs,
		struct tagOPCITEMVQT * pItemVQT,
			HRESULT * * ppErrors );

		//
		// Raw methods provided by interface
		//

		virtual HRESULT __stdcall raw_Read (
			/*[in]*/ unsigned long dwCount,
			/*[in]*/ LPWSTR * pszItemIDs,
			/*[in]*/ unsigned long * pdwMaxAge,
			/*[out]*/ VARIANT * * ppvValues,
			/*[out]*/ unsigned short * * ppwQualities,
		/*[out]*/ struct _FILETIME * * ppftTimeStamps,
			/*[out]*/ HRESULT * * ppErrors ) = 0;
		virtual HRESULT __stdcall raw_WriteVQT (
			/*[in]*/ unsigned long dwCount,
			/*[in]*/ LPWSTR * pszItemIDs,
		/*[in]*/ struct tagOPCITEMVQT * pItemVQT,
			/*[out]*/ HRESULT * * ppErrors ) = 0;
	};

	struct __declspec(uuid("730f5f0f-55b1-4c81-9e18-ff8a0904e1fa"))
IOPCSyncIO2 : IOPCSyncIO
	{
		//
		// Wrapper methods for error-handling
		//

		HRESULT ReadMaxAge (
			unsigned long dwCount,
			unsigned long * phServer,
			unsigned long * pdwMaxAge,
			VARIANT * * ppvValues,
			unsigned short * * ppwQualities,
		struct _FILETIME * * ppftTimeStamps,
			HRESULT * * ppErrors );
		HRESULT WriteVQT (
			unsigned long dwCount,
			unsigned long * phServer,
		struct tagOPCITEMVQT * pItemVQT,
			HRESULT * * ppErrors );

		//
		// Raw methods provided by interface
		//

		virtual HRESULT __stdcall raw_ReadMaxAge (
			/*[in]*/ unsigned long dwCount,
			/*[in]*/ unsigned long * phServer,
			/*[in]*/ unsigned long * pdwMaxAge,
			/*[out]*/ VARIANT * * ppvValues,
			/*[out]*/ unsigned short * * ppwQualities,
		/*[out]*/ struct _FILETIME * * ppftTimeStamps,
			/*[out]*/ HRESULT * * ppErrors ) = 0;
		virtual HRESULT __stdcall raw_WriteVQT (
			/*[in]*/ unsigned long dwCount,
			/*[in]*/ unsigned long * phServer,
		/*[in]*/ struct tagOPCITEMVQT * pItemVQT,
			/*[out]*/ HRESULT * * ppErrors ) = 0;
	};

	struct __declspec(uuid("0967b97b-36ef-423e-b6f8-6bff1e40d39d"))
IOPCAsyncIO3 : IOPCAsyncIO2
	{
		//
		// Wrapper methods for error-handling
		//

		HRESULT ReadMaxAge (
			unsigned long dwCount,
			unsigned long * phServer,
			unsigned long * pdwMaxAge,
			unsigned long dwTransactionID,
			unsigned long * pdwCancelID,
			HRESULT * * ppErrors );
		HRESULT WriteVQT (
			unsigned long dwCount,
			unsigned long * phServer,
		struct tagOPCITEMVQT * pItemVQT,
			unsigned long dwTransactionID,
			unsigned long * pdwCancelID,
			HRESULT * * ppErrors );
		HRESULT RefreshMaxAge (
			unsigned long dwMaxAge,
			unsigned long dwTransactionID,
			unsigned long * pdwCancelID );

		//
		// Raw methods provided by interface
		//

		virtual HRESULT __stdcall raw_ReadMaxAge (
			/*[in]*/ unsigned long dwCount,
			/*[in]*/ unsigned long * phServer,
			/*[in]*/ unsigned long * pdwMaxAge,
			/*[in]*/ unsigned long dwTransactionID,
			/*[out]*/ unsigned long * pdwCancelID,
			/*[out]*/ HRESULT * * ppErrors ) = 0;
		virtual HRESULT __stdcall raw_WriteVQT (
			/*[in]*/ unsigned long dwCount,
			/*[in]*/ unsigned long * phServer,
		/*[in]*/ struct tagOPCITEMVQT * pItemVQT,
			/*[in]*/ unsigned long dwTransactionID,
			/*[out]*/ unsigned long * pdwCancelID,
			/*[out]*/ HRESULT * * ppErrors ) = 0;
		virtual HRESULT __stdcall raw_RefreshMaxAge (
			/*[in]*/ unsigned long dwMaxAge,
			/*[in]*/ unsigned long dwTransactionID,
			/*[out]*/ unsigned long * pdwCancelID ) = 0;
	};

	struct __declspec(uuid("8e368666-d72e-4f78-87ed-647611c61c9f"))
IOPCGroupStateMgt2 : IOPCGroupStateMgt
	{
		//
		// Wrapper methods for error-handling
		//

		HRESULT SetKeepAlive (
			unsigned long dwKeepAliveTime,
			unsigned long * pdwRevisedKeepAliveTime );
		HRESULT GetKeepAlive (
			unsigned long * pdwKeepAliveTime );

		//
		// Raw methods provided by interface
		//

		virtual HRESULT __stdcall raw_SetKeepAlive (
			/*[in]*/ unsigned long dwKeepAliveTime,
			/*[out]*/ unsigned long * pdwRevisedKeepAliveTime ) = 0;
		virtual HRESULT __stdcall raw_GetKeepAlive (
			/*[out]*/ unsigned long * pdwKeepAliveTime ) = 0;
	};


} // namespace OPC

#pragma pack(pop)
