﻿// Created by Microsoft (R) C/C++ Compiler Version 15.00.21022.08 (d5824154).
// C++ source equivalent of Win32 type library 2A75196C-D9EB-4129-B803-931327F72D5C
// compiler-generated file created 05/07/09 at 11:19:06 - DO NOT EDIT!

#pragma once
#pragma pack(push, 8)

#include <comdef.h>

#include "Compatibility.h"

namespace ADO {

//
// Forward references and typedefs
//

struct __declspec(uuid("2a75196c-d9eb-4129-b803-931327f72d5c"))
/* LIBID */ __ADODB;
TagENUM CursorTypeEnum;
TagENUM CursorOptionEnum;
TagENUM LockTypeEnum;
TagENUM ExecuteOptionEnum;
TagENUM ConnectOptionEnum;
TagENUM ObjectStateEnum;
TagENUM CursorLocationEnum;
TagENUM DataTypeEnum;
TagENUM FieldAttributeEnum;
TagENUM EditModeEnum;
TagENUM RecordStatusEnum;
TagENUM GetRowsOptionEnum;
TagENUM PositionEnum;
TagENUM BookmarkEnum;
TagENUM MarshalOptionsEnum;
TagENUM AffectEnum;
TagENUM ResyncEnum;
TagENUM CompareEnum;
TagENUM FilterGroupEnum;
TagENUM SearchDirectionEnum;
TagENUM PersistFormatEnum;
TagENUM StringFormatEnum;
TagENUM ConnectPromptEnum;
TagENUM ConnectModeEnum;
TagENUM RecordCreateOptionsEnum;
TagENUM RecordOpenOptionsEnum;
TagENUM IsolationLevelEnum;
TagENUM XactAttributeEnum;
TagENUM PropertyAttributesEnum;
TagENUM ErrorValueEnum;
TagENUM ParameterAttributesEnum;
TagENUM ParameterDirectionEnum;
TagENUM CommandTypeEnum;
TagENUM EventStatusEnum;
TagENUM EventReasonEnum;
TagENUM SchemaEnum;
TagENUM FieldStatusEnum;
TagENUM SeekEnum;
TagENUM ADCPROP_UPDATECRITERIA_ENUM;
TagENUM ADCPROP_ASYNCTHREADPRIORITY_ENUM;
TagENUM ADCPROP_AUTORECALC_ENUM;
TagENUM ADCPROP_UPDATERESYNC_ENUM;
TagENUM MoveRecordOptionsEnum;
TagENUM CopyRecordOptionsEnum;
TagENUM StreamTypeEnum;
TagENUM LineSeparatorEnum;
TagENUM StreamOpenOptionsEnum;
TagENUM StreamWriteEnum;
TagENUM SaveOptionsEnum;
TagENUM FieldEnum;
TagENUM StreamReadEnum;
TagENUM RecordTypeEnum;
struct __declspec(uuid("00000512-0000-0010-8000-00aa006d2ea4"))
/* dual interface */ _Collection;
struct __declspec(uuid("00000513-0000-0010-8000-00aa006d2ea4"))
/* dual interface */ _DynaCollection;
struct __declspec(uuid("00000534-0000-0010-8000-00aa006d2ea4"))
/* dual interface */ _ADO;
struct __declspec(uuid("00000504-0000-0010-8000-00aa006d2ea4"))
/* dual interface */ Properties;
struct __declspec(uuid("00000503-0000-0010-8000-00aa006d2ea4"))
/* dual interface */ Property;
struct __declspec(uuid("00000500-0000-0010-8000-00aa006d2ea4"))
/* dual interface */ Error;
struct __declspec(uuid("00000501-0000-0010-8000-00aa006d2ea4"))
/* dual interface */ Errors;
struct __declspec(uuid("00000508-0000-0010-8000-00aa006d2ea4"))
/* dual interface */ Command15;
struct __declspec(uuid("00000550-0000-0010-8000-00aa006d2ea4"))
/* dual interface */ _Connection;
struct __declspec(uuid("00000515-0000-0010-8000-00aa006d2ea4"))
/* dual interface */ Connection15;
struct __declspec(uuid("00000556-0000-0010-8000-00aa006d2ea4"))
/* dual interface */ _Recordset;
struct __declspec(uuid("00000555-0000-0010-8000-00aa006d2ea4"))
/* dual interface */ Recordset21;
struct __declspec(uuid("0000054f-0000-0010-8000-00aa006d2ea4"))
/* dual interface */ Recordset20;
struct __declspec(uuid("0000050e-0000-0010-8000-00aa006d2ea4"))
/* dual interface */ Recordset15;
struct __declspec(uuid("00000564-0000-0010-8000-00aa006d2ea4"))
/* dual interface */ Fields;
struct __declspec(uuid("0000054d-0000-0010-8000-00aa006d2ea4"))
/* dual interface */ Fields20;
struct __declspec(uuid("00000506-0000-0010-8000-00aa006d2ea4"))
/* dual interface */ Fields15;
struct __declspec(uuid("00000569-0000-0010-8000-00aa006d2ea4"))
/* dual interface */ Field;
struct __declspec(uuid("0000054c-0000-0010-8000-00aa006d2ea4"))
/* dual interface */ Field20;
struct __declspec(uuid("0000050c-0000-0010-8000-00aa006d2ea4"))
/* dual interface */ _Parameter;
struct __declspec(uuid("0000050d-0000-0010-8000-00aa006d2ea4"))
/* dual interface */ Parameters;
struct __declspec(uuid("0000054e-0000-0010-8000-00aa006d2ea4"))
/* dual interface */ Command25;
struct __declspec(uuid("b08400bd-f9d1-4d02-b856-71d5dba123e9"))
/* dual interface */ _Command;
struct __declspec(uuid("00000402-0000-0010-8000-00aa006d2ea4"))
/* interface */ ConnectionEventsVt;
struct __declspec(uuid("00000403-0000-0010-8000-00aa006d2ea4"))
/* interface */ RecordsetEventsVt;
struct __declspec(uuid("00000400-0000-0010-8000-00aa006d2ea4"))
/* dispinterface */ ConnectionEvents;
struct __declspec(uuid("00000266-0000-0010-8000-00aa006d2ea4"))
/* dispinterface */ RecordsetEvents;
struct __declspec(uuid("00000516-0000-0010-8000-00aa006d2ea4"))
/* interface */ ADOConnectionConstruction15;
struct __declspec(uuid("00000551-0000-0010-8000-00aa006d2ea4"))
/* interface */ ADOConnectionConstruction;
struct /* coclass */ Connection;
struct __declspec(uuid("00000562-0000-0010-8000-00aa006d2ea4"))
/* dual interface */ _Record;
struct /* coclass */ Record;
struct __declspec(uuid("00000565-0000-0010-8000-00aa006d2ea4"))
/* dual interface */ _Stream;
struct /* coclass */ Stream;
struct __declspec(uuid("00000567-0000-0010-8000-00aa006d2ea4"))
/* interface */ ADORecordConstruction;
struct __declspec(uuid("00000568-0000-0010-8000-00aa006d2ea4"))
/* interface */ ADOStreamConstruction;
struct __declspec(uuid("00000517-0000-0010-8000-00aa006d2ea4"))
/* interface */ ADOCommandConstruction;
struct /* coclass */ Command;
struct /* coclass */ Recordset;
struct __declspec(uuid("00000283-0000-0010-8000-00aa006d2ea4"))
/* interface */ ADORecordsetConstruction;
struct __declspec(uuid("00000505-0000-0010-8000-00aa006d2ea4"))
/* dual interface */ Field15;
struct /* coclass */ Parameter;
typedef enum PositionEnum PositionEnum_Param;
typedef enum SearchDirectionEnum SearchDirection;
typedef long ADO_LONGPTR;

//
// Smart pointer typedef declarations
//

_COM_SMARTPTR_TYPEDEF(_Collection, __uuidof(_Collection));
_COM_SMARTPTR_TYPEDEF(_DynaCollection, __uuidof(_DynaCollection));
_COM_SMARTPTR_TYPEDEF(Property, __uuidof(Property));
_COM_SMARTPTR_TYPEDEF(Properties, __uuidof(Properties));
_COM_SMARTPTR_TYPEDEF(_ADO, __uuidof(_ADO));
_COM_SMARTPTR_TYPEDEF(Error, __uuidof(Error));
_COM_SMARTPTR_TYPEDEF(Errors, __uuidof(Errors));
_COM_SMARTPTR_TYPEDEF(Field20, __uuidof(Field20));
_COM_SMARTPTR_TYPEDEF(Field, __uuidof(Field));
_COM_SMARTPTR_TYPEDEF(Fields15, __uuidof(Fields15));
_COM_SMARTPTR_TYPEDEF(Fields20, __uuidof(Fields20));
_COM_SMARTPTR_TYPEDEF(Fields, __uuidof(Fields));
_COM_SMARTPTR_TYPEDEF(_Parameter, __uuidof(_Parameter));
_COM_SMARTPTR_TYPEDEF(Parameters, __uuidof(Parameters));
_COM_SMARTPTR_TYPEDEF(ConnectionEvents, __uuidof(ConnectionEvents));
_COM_SMARTPTR_TYPEDEF(RecordsetEvents, __uuidof(RecordsetEvents));
_COM_SMARTPTR_TYPEDEF(ADOConnectionConstruction15, __uuidof(ADOConnectionConstruction15));
_COM_SMARTPTR_TYPEDEF(ADOConnectionConstruction, __uuidof(ADOConnectionConstruction));
_COM_SMARTPTR_TYPEDEF(_Stream, __uuidof(_Stream));
_COM_SMARTPTR_TYPEDEF(ADORecordConstruction, __uuidof(ADORecordConstruction));
_COM_SMARTPTR_TYPEDEF(ADOStreamConstruction, __uuidof(ADOStreamConstruction));
_COM_SMARTPTR_TYPEDEF(ADOCommandConstruction, __uuidof(ADOCommandConstruction));
_COM_SMARTPTR_TYPEDEF(ADORecordsetConstruction, __uuidof(ADORecordsetConstruction));
_COM_SMARTPTR_TYPEDEF(Field15, __uuidof(Field15));
_COM_SMARTPTR_TYPEDEF(Command15, __uuidof(Command15));
_COM_SMARTPTR_TYPEDEF(Command25, __uuidof(Command25));
_COM_SMARTPTR_TYPEDEF(_Command, __uuidof(_Command));
_COM_SMARTPTR_TYPEDEF(Connection15, __uuidof(Connection15));
_COM_SMARTPTR_TYPEDEF(_Connection, __uuidof(_Connection));
_COM_SMARTPTR_TYPEDEF(Recordset15, __uuidof(Recordset15));
_COM_SMARTPTR_TYPEDEF(Recordset20, __uuidof(Recordset20));
_COM_SMARTPTR_TYPEDEF(Recordset21, __uuidof(Recordset21));
_COM_SMARTPTR_TYPEDEF(_Recordset, __uuidof(_Recordset));
_COM_SMARTPTR_TYPEDEF(ConnectionEventsVt, __uuidof(ConnectionEventsVt));
_COM_SMARTPTR_TYPEDEF(RecordsetEventsVt, __uuidof(RecordsetEventsVt));
_COM_SMARTPTR_TYPEDEF(_Record, __uuidof(_Record));

//
// Type library items
//

TagENUM __declspec(uuid("0000051b-0000-0010-8000-00aa006d2ea4"))
CursorTypeEnum
{
    adOpenUnspecified = -1,
    adOpenForwardOnly = 0,
    adOpenKeyset = 1,
    adOpenDynamic = 2,
    adOpenStatic = 3
};

TagENUM __declspec(uuid("0000051c-0000-0010-8000-00aa006d2ea4"))
CursorOptionEnum
{
    adHoldRecords = 256,
    adMovePrevious = 512,
    adAddNew = 16778240,
    adDelete = 16779264,
    adUpdate = 16809984,
    adBookmark = 8192,
    adApproxPosition = 16384,
    adUpdateBatch = 65536,
    adResync = 131072,
    adNotify = 262144,
    adFind = 524288,
    adSeek = 4194304,
    adIndex = 8388608
};

TagENUM __declspec(uuid("0000051d-0000-0010-8000-00aa006d2ea4"))
LockTypeEnum
{
    adLockUnspecified = -1,
    adLockReadOnly = 1,
    adLockPessimistic = 2,
    adLockOptimistic = 3,
    adLockBatchOptimistic = 4
};

TagENUM __declspec(uuid("0000051e-0000-0010-8000-00aa006d2ea4"))
ExecuteOptionEnum
{
    adOptionUnspecified = -1,
    adAsyncExecute = 16,
    adAsyncFetch = 32,
    adAsyncFetchNonBlocking = 64,
    adExecuteNoRecords = 128,
    adExecuteStream = 1024,
    adExecuteRecord = 2048
};

TagENUM __declspec(uuid("00000541-0000-0010-8000-00aa006d2ea4"))
ConnectOptionEnum
{
    adConnectUnspecified = -1,
    adAsyncConnect = 16
};

TagENUM __declspec(uuid("00000532-0000-0010-8000-00aa006d2ea4"))
ObjectStateEnum
{
    adStateClosed = 0,
    adStateOpen = 1,
    adStateConnecting = 2,
    adStateExecuting = 4,
    adStateFetching = 8
};

TagENUM __declspec(uuid("0000052f-0000-0010-8000-00aa006d2ea4"))
CursorLocationEnum
{
    adUseNone = 1,
    adUseServer = 2,
    adUseClient = 3,
    adUseClientBatch = 3
};

TagENUM __declspec(uuid("0000051f-0000-0010-8000-00aa006d2ea4"))
DataTypeEnum
{
    adEmpty = 0,
    adTinyInt = 16,
    adSmallInt = 2,
    adInteger = 3,
    adBigInt = 20,
    adUnsignedTinyInt = 17,
    adUnsignedSmallInt = 18,
    adUnsignedInt = 19,
    adUnsignedBigInt = 21,
    adSingle = 4,
    adDouble = 5,
    adCurrency = 6,
    adDecimal = 14,
    adNumeric = 131,
    adBoolean = 11,
    adError = 10,
    adUserDefined = 132,
    adVariant = 12,
    adIDispatch = 9,
    adIUnknown = 13,
    adGUID = 72,
    adDate = 7,
    adDBDate = 133,
    adDBTime = 134,
    adDBTimeStamp = 135,
    adBSTR = 8,
    adChar = 129,
    adVarChar = 200,
    adLongVarChar = 201,
    adWChar = 130,
    adVarWChar = 202,
    adLongVarWChar = 203,
    adBinary = 128,
    adVarBinary = 204,
    adLongVarBinary = 205,
    adChapter = 136,
    adFileTime = 64,
    adPropVariant = 138,
    adVarNumeric = 139,
    adArray = 8192
};

TagENUM __declspec(uuid("00000525-0000-0010-8000-00aa006d2ea4"))
FieldAttributeEnum
{
    adFldUnspecified = -1,
    adFldMayDefer = 2,
    adFldUpdatable = 4,
    adFldUnknownUpdatable = 8,
    adFldFixed = 16,
    adFldIsNullable = 32,
    adFldMayBeNull = 64,
    adFldLong = 128,
    adFldRowID = 256,
    adFldRowVersion = 512,
    adFldCacheDeferred = 4096,
    adFldIsChapter = 8192,
    adFldNegativeScale = 16384,
    adFldKeyColumn = 32768,
    adFldIsRowURL = 65536,
    adFldIsDefaultStream = 131072,
    adFldIsCollection = 262144
};

TagENUM __declspec(uuid("00000526-0000-0010-8000-00aa006d2ea4"))
EditModeEnum
{
    adEditNone = 0,
    adEditInProgress = 1,
    adEditAdd = 2,
    adEditDelete = 4
};

TagENUM __declspec(uuid("00000527-0000-0010-8000-00aa006d2ea4"))
RecordStatusEnum
{
    adRecOK = 0,
    adRecNew = 1,
    adRecModified = 2,
    adRecDeleted = 4,
    adRecUnmodified = 8,
    adRecInvalid = 16,
    adRecMultipleChanges = 64,
    adRecPendingChanges = 128,
    adRecCanceled = 256,
    adRecCantRelease = 1024,
    adRecConcurrencyViolation = 2048,
    adRecIntegrityViolation = 4096,
    adRecMaxChangesExceeded = 8192,
    adRecObjectOpen = 16384,
    adRecOutOfMemory = 32768,
    adRecPermissionDenied = 65536,
    adRecSchemaViolation = 131072,
    adRecDBDeleted = 262144
};

TagENUM __declspec(uuid("00000542-0000-0010-8000-00aa006d2ea4"))
GetRowsOptionEnum
{
    adGetRowsRest = -1
};

TagENUM __declspec(uuid("00000528-0000-0010-8000-00aa006d2ea4"))
PositionEnum
{
    adPosUnknown = -1,
    adPosBOF = -2,
    adPosEOF = -3
};

TagENUM BookmarkEnum
{
    adBookmarkCurrent = 0,
    adBookmarkFirst = 1,
    adBookmarkLast = 2
};

TagENUM __declspec(uuid("00000540-0000-0010-8000-00aa006d2ea4"))
MarshalOptionsEnum
{
    adMarshalAll = 0,
    adMarshalModifiedOnly = 1
};

TagENUM __declspec(uuid("00000543-0000-0010-8000-00aa006d2ea4"))
AffectEnum
{
    adAffectCurrent = 1,
    adAffectGroup = 2,
    adAffectAll = 3,
    adAffectAllChapters = 4
};

TagENUM __declspec(uuid("00000544-0000-0010-8000-00aa006d2ea4"))
ResyncEnum
{
    adResyncUnderlyingValues = 1,
    adResyncAllValues = 2
};

TagENUM __declspec(uuid("00000545-0000-0010-8000-00aa006d2ea4"))
CompareEnum
{
    adCompareLessThan = 0,
    adCompareEqual = 1,
    adCompareGreaterThan = 2,
    adCompareNotEqual = 3,
    adCompareNotComparable = 4
};

TagENUM __declspec(uuid("00000546-0000-0010-8000-00aa006d2ea4"))
FilterGroupEnum
{
    adFilterNone = 0,
    adFilterPendingRecords = 1,
    adFilterAffectedRecords = 2,
    adFilterFetchedRecords = 3,
    adFilterPredicate = 4,
    adFilterConflictingRecords = 5
};

TagENUM __declspec(uuid("00000547-0000-0010-8000-00aa006d2ea4"))
SearchDirectionEnum
{
    adSearchForward = 1,
    adSearchBackward = -1
};

TagENUM __declspec(uuid("00000548-0000-0010-8000-00aa006d2ea4"))
PersistFormatEnum
{
    adPersistADTG = 0,
    adPersistXML = 1
};

TagENUM __declspec(uuid("00000549-0000-0010-8000-00aa006d2ea4"))
StringFormatEnum
{
    adClipString = 2
};

TagENUM __declspec(uuid("00000520-0000-0010-8000-00aa006d2ea4"))
ConnectPromptEnum
{
    adPromptAlways = 1,
    adPromptComplete = 2,
    adPromptCompleteRequired = 3,
    adPromptNever = 4
};

TagENUM __declspec(uuid("00000521-0000-0010-8000-00aa006d2ea4"))
ConnectModeEnum
{
    adModeUnknown = 0,
    adModeRead = 1,
    adModeWrite = 2,
    adModeReadWrite = 3,
    adModeShareDenyRead = 4,
    adModeShareDenyWrite = 8,
    adModeShareExclusive = 12,
    adModeShareDenyNone = 16,
    adModeRecursive = 4194304
};

TagENUM __declspec(uuid("00000570-0000-0010-8000-00aa006d2ea4"))
RecordCreateOptionsEnum
{
    adCreateCollection = 8192,
    adCreateStructDoc = 0x80000000,
    adCreateNonCollection = 0,
    adOpenIfExists = 33554432,
    adCreateOverwrite = 67108864,
    adFailIfNotExists = -1
};

TagENUM __declspec(uuid("00000571-0000-0010-8000-00aa006d2ea4"))
RecordOpenOptionsEnum
{
    adOpenRecordUnspecified = -1,
    adOpenSource = 8388608,
    adOpenOutput = 8388608,
    adOpenAsync = 4096,
    adDelayFetchStream = 16384,
    adDelayFetchFields = 32768,
    adOpenExecuteCommand = 65536
};

TagENUM __declspec(uuid("00000523-0000-0010-8000-00aa006d2ea4"))
IsolationLevelEnum
{
    adXactUnspecified = -1,
    adXactChaos = 16,
    adXactReadUncommitted = 256,
    adXactBrowse = 256,
    adXactCursorStability = 4096,
    adXactReadCommitted = 4096,
    adXactRepeatableRead = 65536,
    adXactSerializable = 1048576,
    adXactIsolated = 1048576
};

TagENUM __declspec(uuid("00000524-0000-0010-8000-00aa006d2ea4"))
XactAttributeEnum
{
    adXactCommitRetaining = 131072,
    adXactAbortRetaining = 262144,
    adXactAsyncPhaseOne = 524288,
    adXactSyncPhaseOne = 1048576
};

TagENUM __declspec(uuid("00000529-0000-0010-8000-00aa006d2ea4"))
PropertyAttributesEnum
{
    adPropNotSupported = 0,
    adPropRequired = 1,
    adPropOptional = 2,
    adPropRead = 512,
    adPropWrite = 1024
};

TagENUM __declspec(uuid("0000052a-0000-0010-8000-00aa006d2ea4"))
ErrorValueEnum
{
    adErrProviderFailed = 3000,
    adErrInvalidArgument = 3001,
    adErrOpeningFile = 3002,
    adErrReadFile = 3003,
    adErrWriteFile = 3004,
    adErrNoCurrentRecord = 3021,
    adErrIllegalOperation = 3219,
    adErrCantChangeProvider = 3220,
    adErrInTransaction = 3246,
    adErrFeatureNotAvailable = 3251,
    adErrItemNotFound = 3265,
    adErrObjectInCollection = 3367,
    adErrObjectNotSet = 3420,
    adErrDataConversion = 3421,
    adErrObjectClosed = 3704,
    adErrObjectOpen = 3705,
    adErrProviderNotFound = 3706,
    adErrBoundToCommand = 3707,
    adErrInvalidParamInfo = 3708,
    adErrInvalidConnection = 3709,
    adErrNotReentrant = 3710,
    adErrStillExecuting = 3711,
    adErrOperationCancelled = 3712,
    adErrStillConnecting = 3713,
    adErrInvalidTransaction = 3714,
    adErrNotExecuting = 3715,
    adErrUnsafeOperation = 3716,
    adwrnSecurityDialog = 3717,
    adwrnSecurityDialogHeader = 3718,
    adErrIntegrityViolation = 3719,
    adErrPermissionDenied = 3720,
    adErrDataOverflow = 3721,
    adErrSchemaViolation = 3722,
    adErrSignMismatch = 3723,
    adErrCantConvertvalue = 3724,
    adErrCantCreate = 3725,
    adErrColumnNotOnThisRow = 3726,
    adErrURLDoesNotExist = 3727,
    adErrTreePermissionDenied = 3728,
    adErrInvalidURL = 3729,
    adErrResourceLocked = 3730,
    adErrResourceExists = 3731,
    adErrCannotComplete = 3732,
    adErrVolumeNotFound = 3733,
    adErrOutOfSpace = 3734,
    adErrResourceOutOfScope = 3735,
    adErrUnavailable = 3736,
    adErrURLNamedRowDoesNotExist = 3737,
    adErrDelResOutOfScope = 3738,
    adErrPropInvalidColumn = 3739,
    adErrPropInvalidOption = 3740,
    adErrPropInvalidValue = 3741,
    adErrPropConflicting = 3742,
    adErrPropNotAllSettable = 3743,
    adErrPropNotSet = 3744,
    adErrPropNotSettable = 3745,
    adErrPropNotSupported = 3746,
    adErrCatalogNotSet = 3747,
    adErrCantChangeConnection = 3748,
    adErrFieldsUpdateFailed = 3749,
    adErrDenyNotSupported = 3750,
    adErrDenyTypeNotSupported = 3751,
    adErrProviderNotSpecified = 3753,
    adErrConnectionStringTooLong = 3754
};

TagENUM __declspec(uuid("0000052b-0000-0010-8000-00aa006d2ea4"))
ParameterAttributesEnum
{
    adParamSigned = 16,
    adParamNullable = 64,
    adParamLong = 128
};

TagENUM __declspec(uuid("0000052c-0000-0010-8000-00aa006d2ea4"))
ParameterDirectionEnum
{
    adParamUnknown = 0,
    adParamInput = 1,
    adParamOutput = 2,
    adParamInputOutput = 3,
    adParamReturnValue = 4
};

TagENUM __declspec(uuid("0000052e-0000-0010-8000-00aa006d2ea4"))
CommandTypeEnum
{
    adCmdUnspecified = -1,
    adCmdUnknown = 8,
    adCmdText = 1,
    adCmdTable = 2,
    adCmdStoredProc = 4,
    adCmdFile = 256,
    adCmdTableDirect = 512
};

TagENUM __declspec(uuid("00000530-0000-0010-8000-00aa006d2ea4"))
EventStatusEnum
{
    adStatusOK = 1,
    adStatusErrorsOccurred = 2,
    adStatusCantDeny = 3,
    adStatusCancel = 4,
    adStatusUnwantedEvent = 5
};

TagENUM __declspec(uuid("00000531-0000-0010-8000-00aa006d2ea4"))
EventReasonEnum
{
    adRsnAddNew = 1,
    adRsnDelete = 2,
    adRsnUpdate = 3,
    adRsnUndoUpdate = 4,
    adRsnUndoAddNew = 5,
    adRsnUndoDelete = 6,
    adRsnRequery = 7,
    adRsnResynch = 8,
    adRsnClose = 9,
    adRsnMove = 10,
    adRsnFirstChange = 11,
    adRsnMoveFirst = 12,
    adRsnMoveNext = 13,
    adRsnMovePrevious = 14,
    adRsnMoveLast = 15
};

TagENUM __declspec(uuid("00000533-0000-0010-8000-00aa006d2ea4"))
SchemaEnum
{
    adSchemaProviderSpecific = -1,
    adSchemaAsserts = 0,
    adSchemaCatalogs = 1,
    adSchemaCharacterSets = 2,
    adSchemaCollations = 3,
    adSchemaColumns = 4,
    adSchemaCheckConstraints = 5,
    adSchemaConstraintColumnUsage = 6,
    adSchemaConstraintTableUsage = 7,
    adSchemaKeyColumnUsage = 8,
    adSchemaReferentialContraints = 9,
    adSchemaReferentialConstraints = 9,
    adSchemaTableConstraints = 10,
    adSchemaColumnsDomainUsage = 11,
    adSchemaIndexes = 12,
    adSchemaColumnPrivileges = 13,
    adSchemaTablePrivileges = 14,
    adSchemaUsagePrivileges = 15,
    adSchemaProcedures = 16,
    adSchemaSchemata = 17,
    adSchemaSQLLanguages = 18,
    adSchemaStatistics = 19,
    adSchemaTables = 20,
    adSchemaTranslations = 21,
    adSchemaProviderTypes = 22,
    adSchemaViews = 23,
    adSchemaViewColumnUsage = 24,
    adSchemaViewTableUsage = 25,
    adSchemaProcedureParameters = 26,
    adSchemaForeignKeys = 27,
    adSchemaPrimaryKeys = 28,
    adSchemaProcedureColumns = 29,
    adSchemaDBInfoKeywords = 30,
    adSchemaDBInfoLiterals = 31,
    adSchemaCubes = 32,
    adSchemaDimensions = 33,
    adSchemaHierarchies = 34,
    adSchemaLevels = 35,
    adSchemaMeasures = 36,
    adSchemaProperties = 37,
    adSchemaMembers = 38,
    adSchemaTrustees = 39,
    adSchemaFunctions = 40,
    adSchemaActions = 41,
    adSchemaCommands = 42,
    adSchemaSets = 43
};

TagENUM __declspec(uuid("0000057e-0000-0010-8000-00aa006d2ea4"))
FieldStatusEnum
{
    adFieldOK = 0,
    adFieldCantConvertValue = 2,
    adFieldIsNull = 3,
    adFieldTruncated = 4,
    adFieldSignMismatch = 5,
    adFieldDataOverflow = 6,
    adFieldCantCreate = 7,
    adFieldUnavailable = 8,
    adFieldPermissionDenied = 9,
    adFieldIntegrityViolation = 10,
    adFieldSchemaViolation = 11,
    adFieldBadStatus = 12,
    adFieldDefault = 13,
    adFieldIgnore = 15,
    adFieldDoesNotExist = 16,
    adFieldInvalidURL = 17,
    adFieldResourceLocked = 18,
    adFieldResourceExists = 19,
    adFieldCannotComplete = 20,
    adFieldVolumeNotFound = 21,
    adFieldOutOfSpace = 22,
    adFieldCannotDeleteSource = 23,
    adFieldReadOnly = 24,
    adFieldResourceOutOfScope = 25,
    adFieldAlreadyExists = 26,
    adFieldPendingInsert = 65536,
    adFieldPendingDelete = 131072,
    adFieldPendingChange = 262144,
    adFieldPendingUnknown = 524288,
    adFieldPendingUnknownDelete = 1048576
};

TagENUM __declspec(uuid("00000552-0000-0010-8000-00aa006d2ea4"))
SeekEnum
{
    adSeekFirstEQ = 1,
    adSeekLastEQ = 2,
    adSeekAfterEQ = 4,
    adSeekAfter = 8,
    adSeekBeforeEQ = 16,
    adSeekBefore = 32
};

TagENUM __declspec(uuid("0000054a-0000-0010-8000-00aa006d2ea4"))
ADCPROP_UPDATECRITERIA_ENUM
{
    adCriteriaKey = 0,
    adCriteriaAllCols = 1,
    adCriteriaUpdCols = 2,
    adCriteriaTimeStamp = 3
};

TagENUM __declspec(uuid("0000054b-0000-0010-8000-00aa006d2ea4"))
ADCPROP_ASYNCTHREADPRIORITY_ENUM
{
    adPriorityLowest = 1,
    adPriorityBelowNormal = 2,
    adPriorityNormal = 3,
    adPriorityAboveNormal = 4,
    adPriorityHighest = 5
};

TagENUM __declspec(uuid("00000554-0000-0010-8000-00aa006d2ea4"))
ADCPROP_AUTORECALC_ENUM
{
    adRecalcUpFront = 0,
    adRecalcAlways = 1
};

TagENUM __declspec(uuid("00000553-0000-0010-8000-00aa006d2ea4"))
ADCPROP_UPDATERESYNC_ENUM
{
    adResyncNone = 0,
    adResyncAutoIncrement = 1,
    adResyncConflicts = 2,
    adResyncUpdates = 4,
    adResyncInserts = 8,
    adResyncAll = 15
};

TagENUM __declspec(uuid("00000573-0000-0010-8000-00aa006d2ea4"))
MoveRecordOptionsEnum
{
    adMoveUnspecified = -1,
    adMoveOverWrite = 1,
    adMoveDontUpdateLinks = 2,
    adMoveAllowEmulation = 4
};

TagENUM __declspec(uuid("00000574-0000-0010-8000-00aa006d2ea4"))
CopyRecordOptionsEnum
{
    adCopyUnspecified = -1,
    adCopyOverWrite = 1,
    adCopyAllowEmulation = 4,
    adCopyNonRecursive = 2
};

TagENUM __declspec(uuid("00000576-0000-0010-8000-00aa006d2ea4"))
StreamTypeEnum
{
    adTypeBinary = 1,
    adTypeText = 2
};

TagENUM __declspec(uuid("00000577-0000-0010-8000-00aa006d2ea4"))
LineSeparatorEnum
{
    adLF = 10,
    adCR = 13,
    adCRLF = -1
};

TagENUM __declspec(uuid("0000057a-0000-0010-8000-00aa006d2ea4"))
StreamOpenOptionsEnum
{
    adOpenStreamUnspecified = -1,
    adOpenStreamAsync = 1,
    adOpenStreamFromRecord = 4
};

TagENUM __declspec(uuid("0000057b-0000-0010-8000-00aa006d2ea4"))
StreamWriteEnum
{
    adWriteChar = 0,
    adWriteLine = 1,
    stWriteChar = 0,
    stWriteLine = 1
};

TagENUM __declspec(uuid("0000057c-0000-0010-8000-00aa006d2ea4"))
SaveOptionsEnum
{
    adSaveCreateNotExist = 1,
    adSaveCreateOverWrite = 2
};

TagENUM FieldEnum
{
    adDefaultStream = -1,
    adRecordURL = -2
};

TagENUM StreamReadEnum
{
    adReadAll = -1,
    adReadLine = -2
};

TagENUM __declspec(uuid("0000057d-0000-0010-8000-00aa006d2ea4"))
RecordTypeEnum
{
    adSimpleRecord = 0,
    adCollectionRecord = 1,
    adStructDoc = 2
};

struct __declspec(uuid("00000512-0000-0010-8000-00aa006d2ea4"))
_Collection : IDispatch
{
    //
    // Property data
    //

    __declspec(property(get=GetCount))
    long Count;

    //
    // Wrapper methods for error-handling
    //

    long GetCount ( );
    IUnknownPtr _NewEnum ( );
    HRESULT Refresh ( );

    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_Count (
        /*[out,retval]*/ long * c ) = 0;
      virtual HRESULT __stdcall raw__NewEnum (
        /*[out,retval]*/ IUnknown * * ppvObject ) = 0;
      virtual HRESULT __stdcall raw_Refresh ( ) = 0;
};

struct __declspec(uuid("00000513-0000-0010-8000-00aa006d2ea4"))
_DynaCollection : _Collection
{
    //
    // Wrapper methods for error-handling
    //

    HRESULT Append (
        IDispatch * Object );
    HRESULT Delete (
        const _variant_t & Index );

    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall raw_Append (
        /*[in]*/ IDispatch * Object ) = 0;
      virtual HRESULT __stdcall raw_Delete (
        /*[in]*/ VARIANT Index ) = 0;
};

struct __declspec(uuid("00000503-0000-0010-8000-00aa006d2ea4"))
Property : IDispatch
{
    //
    // Property data
    //

    __declspec(property(get=GetValue,put=PutValue))
    _variant_t Value;
    __declspec(property(get=GetName))
    _bstr_t Name;
    __declspec(property(get=GetType))
    TagENUM DataTypeEnum Type;
    __declspec(property(get=GetAttributes,put=PutAttributes))
    long Attributes;

    //
    // Wrapper methods for error-handling
    //

    _variant_t GetValue ( );
    void PutValue (
        const _variant_t & pval );
    _bstr_t GetName ( );
    TagENUM DataTypeEnum GetType ( );
    long GetAttributes ( );
    void PutAttributes (
        long plAttributes );

    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_Value (
        /*[out,retval]*/ VARIANT * pval ) = 0;
      virtual HRESULT __stdcall put_Value (
        /*[in]*/ VARIANT pval ) = 0;
      virtual HRESULT __stdcall get_Name (
        /*[out,retval]*/ BSTR * pbstr ) = 0;
      virtual HRESULT __stdcall get_Type (
        /*[out,retval]*/ TagENUM DataTypeEnum * ptype ) = 0;
      virtual HRESULT __stdcall get_Attributes (
        /*[out,retval]*/ long * plAttributes ) = 0;
      virtual HRESULT __stdcall put_Attributes (
        /*[in]*/ long plAttributes ) = 0;
};

struct __declspec(uuid("00000504-0000-0010-8000-00aa006d2ea4"))
Properties : _Collection
{
    //
    // Property data
    //

    __declspec(property(get=GetItem))
    PropertyPtr Item[];

    //
    // Wrapper methods for error-handling
    //

    PropertyPtr GetItem (
        const _variant_t & Index );

    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_Item (
        /*[in]*/ VARIANT Index,
        /*[out,retval]*/ struct Property * * ppvObject ) = 0;
};

struct __declspec(uuid("00000534-0000-0010-8000-00aa006d2ea4"))
_ADO : IDispatch
{
    //
    // Property data
    //

    __declspec(property(get=GetProperties))
    PropertiesPtr Properties;

    //
    // Wrapper methods for error-handling
    //

    PropertiesPtr GetProperties ( );

    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_Properties (
        /*[out,retval]*/ struct Properties * * ppvObject ) = 0;
};

struct __declspec(uuid("00000500-0000-0010-8000-00aa006d2ea4"))
Error : IDispatch
{
    //
    // Property data
    //

    __declspec(property(get=GetDescription))
    _bstr_t Description;
    __declspec(property(get=GetNumber))
    long Number;
    __declspec(property(get=GetSource))
    _bstr_t Source;
    __declspec(property(get=GetHelpFile))
    _bstr_t HelpFile;
    __declspec(property(get=GetHelpContext))
    long HelpContext;
    __declspec(property(get=GetSQLState))
    _bstr_t SQLState;
    __declspec(property(get=GetNativeError))
    long NativeError;

    //
    // Wrapper methods for error-handling
    //

    long GetNumber ( );
    _bstr_t GetSource ( );
    _bstr_t GetDescription ( );
    _bstr_t GetHelpFile ( );
    long GetHelpContext ( );
    _bstr_t GetSQLState ( );
    long GetNativeError ( );

    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_Number (
        /*[out,retval]*/ long * pl ) = 0;
      virtual HRESULT __stdcall get_Source (
        /*[out,retval]*/ BSTR * pbstr ) = 0;
      virtual HRESULT __stdcall get_Description (
        /*[out,retval]*/ BSTR * pbstr ) = 0;
      virtual HRESULT __stdcall get_HelpFile (
        /*[out,retval]*/ BSTR * pbstr ) = 0;
      virtual HRESULT __stdcall get_HelpContext (
        /*[out,retval]*/ long * pl ) = 0;
      virtual HRESULT __stdcall get_SQLState (
        /*[out,retval]*/ BSTR * pbstr ) = 0;
      virtual HRESULT __stdcall get_NativeError (
        /*[out,retval]*/ long * pl ) = 0;
};

struct __declspec(uuid("00000501-0000-0010-8000-00aa006d2ea4"))
Errors : _Collection
{
    //
    // Property data
    //

    __declspec(property(get=GetItem))
    ErrorPtr Item[];

    //
    // Wrapper methods for error-handling
    //

    ErrorPtr GetItem (
        const _variant_t & Index );
    HRESULT Clear ( );

    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_Item (
        /*[in]*/ VARIANT Index,
        /*[out,retval]*/ struct Error * * ppvObject ) = 0;
      virtual HRESULT __stdcall raw_Clear ( ) = 0;
};

struct __declspec(uuid("0000054c-0000-0010-8000-00aa006d2ea4"))
Field20 : _ADO
{
    //
    // Property data
    //

    __declspec(property(get=GetValue,put=PutValue))
    _variant_t Value;
    __declspec(property(get=GetName))
    _bstr_t Name;
    __declspec(property(get=GetType,put=PutType))
    TagENUM DataTypeEnum Type;
    __declspec(property(get=GetDefinedSize,put=PutDefinedSize))
    ADO_LONGPTR DefinedSize;
    __declspec(property(get=GetOriginalValue))
    _variant_t OriginalValue;
    __declspec(property(get=GetUnderlyingValue))
    _variant_t UnderlyingValue;
    __declspec(property(get=GetActualSize))
    ADO_LONGPTR ActualSize;
    __declspec(property(get=GetPrecision,put=PutPrecision))
    unsigned char Precision;
    __declspec(property(get=GetNumericScale,put=PutNumericScale))
    unsigned char NumericScale;
    __declspec(property(get=GetAttributes,put=PutAttributes))
    long Attributes;
    __declspec(property(get=GetDataFormat,put=PutRefDataFormat))
    IUnknownPtr DataFormat;

    //
    // Wrapper methods for error-handling
    //

    ADO_LONGPTR GetActualSize ( );
    long GetAttributes ( );
    ADO_LONGPTR GetDefinedSize ( );
    _bstr_t GetName ( );
    TagENUM DataTypeEnum GetType ( );
    _variant_t GetValue ( );
    void PutValue (
        const _variant_t & pvar );
    unsigned char GetPrecision ( );
    unsigned char GetNumericScale ( );
    HRESULT AppendChunk (
        const _variant_t & Data );
    _variant_t GetChunk (
        long Length );
    _variant_t GetOriginalValue ( );
    _variant_t GetUnderlyingValue ( );
    IUnknownPtr GetDataFormat ( );
    void PutRefDataFormat (
        IUnknown * ppiDF );
    void PutPrecision (
        unsigned char pbPrecision );
    void PutNumericScale (
        unsigned char pbNumericScale );
    void PutType (
        TagENUM DataTypeEnum pDataType );
    void PutDefinedSize (
        ADO_LONGPTR pl );
    void PutAttributes (
        long pl );

    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_ActualSize (
        /*[out,retval]*/ ADO_LONGPTR * pl ) = 0;
      virtual HRESULT __stdcall get_Attributes (
        /*[out,retval]*/ long * pl ) = 0;
      virtual HRESULT __stdcall get_DefinedSize (
        /*[out,retval]*/ ADO_LONGPTR * pl ) = 0;
      virtual HRESULT __stdcall get_Name (
        /*[out,retval]*/ BSTR * pbstr ) = 0;
      virtual HRESULT __stdcall get_Type (
        /*[out,retval]*/ TagENUM DataTypeEnum * pDataType ) = 0;
      virtual HRESULT __stdcall get_Value (
        /*[out,retval]*/ VARIANT * pvar ) = 0;
      virtual HRESULT __stdcall put_Value (
        /*[in]*/ VARIANT pvar ) = 0;
      virtual HRESULT __stdcall get_Precision (
        /*[out,retval]*/ unsigned char * pbPrecision ) = 0;
      virtual HRESULT __stdcall get_NumericScale (
        /*[out,retval]*/ unsigned char * pbNumericScale ) = 0;
      virtual HRESULT __stdcall raw_AppendChunk (
        /*[in]*/ VARIANT Data ) = 0;
      virtual HRESULT __stdcall raw_GetChunk (
        /*[in]*/ long Length,
        /*[out,retval]*/ VARIANT * pvar ) = 0;
      virtual HRESULT __stdcall get_OriginalValue (
        /*[out,retval]*/ VARIANT * pvar ) = 0;
      virtual HRESULT __stdcall get_UnderlyingValue (
        /*[out,retval]*/ VARIANT * pvar ) = 0;
      virtual HRESULT __stdcall get_DataFormat (
        /*[out,retval]*/ IUnknown * * ppiDF ) = 0;
      virtual HRESULT __stdcall putref_DataFormat (
        /*[in]*/ IUnknown * ppiDF ) = 0;
      virtual HRESULT __stdcall put_Precision (
        /*[in]*/ unsigned char pbPrecision ) = 0;
      virtual HRESULT __stdcall put_NumericScale (
        /*[in]*/ unsigned char pbNumericScale ) = 0;
      virtual HRESULT __stdcall put_Type (
        /*[in]*/ TagENUM DataTypeEnum pDataType ) = 0;
      virtual HRESULT __stdcall put_DefinedSize (
        /*[in]*/ ADO_LONGPTR pl ) = 0;
      virtual HRESULT __stdcall put_Attributes (
        /*[in]*/ long pl ) = 0;
};

struct __declspec(uuid("00000569-0000-0010-8000-00aa006d2ea4"))
Field : Field20
{
    //
    // Property data
    //

    __declspec(property(get=GetStatus))
    long Status;

    //
    // Wrapper methods for error-handling
    //

    long GetStatus ( );

    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_Status (
        /*[out,retval]*/ long * pFStatus ) = 0;
};

struct __declspec(uuid("00000506-0000-0010-8000-00aa006d2ea4"))
Fields15 : _Collection
{
    //
    // Property data
    //

    __declspec(property(get=GetItem))
    FieldPtr Item[];

    //
    // Wrapper methods for error-handling
    //

    FieldPtr GetItem (
        const _variant_t & Index );

    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_Item (
        /*[in]*/ VARIANT Index,
        /*[out,retval]*/ struct Field * * ppvObject ) = 0;
};

struct __declspec(uuid("0000054d-0000-0010-8000-00aa006d2ea4"))
Fields20 : Fields15
{
    //
    // Wrapper methods for error-handling
    //

    HRESULT _Append (
        _bstr_t Name,
        TagENUM DataTypeEnum Type,
        ADO_LONGPTR DefinedSize,
        TagENUM FieldAttributeEnum Attrib );
    HRESULT Delete (
        const _variant_t & Index );

    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall raw__Append (
        /*[in]*/ BSTR Name,
        /*[in]*/ TagENUM DataTypeEnum Type,
        /*[in]*/ ADO_LONGPTR DefinedSize,
        /*[in]*/ TagENUM FieldAttributeEnum Attrib ) = 0;
      virtual HRESULT __stdcall raw_Delete (
        /*[in]*/ VARIANT Index ) = 0;
};

struct __declspec(uuid("00000564-0000-0010-8000-00aa006d2ea4"))
Fields : Fields20
{
    //
    // Wrapper methods for error-handling
    //

    HRESULT Append (
        _bstr_t Name,
        TagENUM DataTypeEnum Type,
        ADO_LONGPTR DefinedSize,
        TagENUM FieldAttributeEnum Attrib,
        const _variant_t & FieldValue = vtMissing );
    HRESULT Update ( );
    HRESULT Resync (
        TagENUM ResyncEnum ResyncValues );
    HRESULT CancelUpdate ( );

    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall raw_Append (
        /*[in]*/ BSTR Name,
        /*[in]*/ TagENUM DataTypeEnum Type,
        /*[in]*/ ADO_LONGPTR DefinedSize,
        /*[in]*/ TagENUM FieldAttributeEnum Attrib,
        /*[in]*/ VARIANT FieldValue = vtMissing ) = 0;
      virtual HRESULT __stdcall raw_Update ( ) = 0;
      virtual HRESULT __stdcall raw_Resync (
        /*[in]*/ TagENUM ResyncEnum ResyncValues ) = 0;
      virtual HRESULT __stdcall raw_CancelUpdate ( ) = 0;
};

struct __declspec(uuid("0000050c-0000-0010-8000-00aa006d2ea4"))
_Parameter : _ADO
{
    //
    // Property data
    //

    __declspec(property(get=GetValue,put=PutValue))
    _variant_t Value;
    __declspec(property(get=GetName,put=PutName))
    _bstr_t Name;
    __declspec(property(get=GetType,put=PutType))
    TagENUM DataTypeEnum Type;
    __declspec(property(get=GetDirection,put=PutDirection))
    TagENUM ParameterDirectionEnum Direction;
    __declspec(property(get=GetPrecision,put=PutPrecision))
    unsigned char Precision;
    __declspec(property(get=GetNumericScale,put=PutNumericScale))
    unsigned char NumericScale;
    __declspec(property(get=GetSize,put=PutSize))
    ADO_LONGPTR Size;
    __declspec(property(get=GetAttributes,put=PutAttributes))
    long Attributes;

    //
    // Wrapper methods for error-handling
    //

    _bstr_t GetName ( );
    void PutName (
        _bstr_t pbstr );
    _variant_t GetValue ( );
    void PutValue (
        const _variant_t & pvar );
    TagENUM DataTypeEnum GetType ( );
    void PutType (
        TagENUM DataTypeEnum psDataType );
    void PutDirection (
        TagENUM ParameterDirectionEnum plParmDirection );
    TagENUM ParameterDirectionEnum GetDirection ( );
    void PutPrecision (
        unsigned char pbPrecision );
    unsigned char GetPrecision ( );
    void PutNumericScale (
        unsigned char pbScale );
    unsigned char GetNumericScale ( );
    void PutSize (
        ADO_LONGPTR pl );
    ADO_LONGPTR GetSize ( );
    HRESULT AppendChunk (
        const _variant_t & Val );
    long GetAttributes ( );
    void PutAttributes (
        long plParmAttribs );

    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_Name (
        /*[out,retval]*/ BSTR * pbstr ) = 0;
      virtual HRESULT __stdcall put_Name (
        /*[in]*/ BSTR pbstr ) = 0;
      virtual HRESULT __stdcall get_Value (
        /*[out,retval]*/ VARIANT * pvar ) = 0;
      virtual HRESULT __stdcall put_Value (
        /*[in]*/ VARIANT pvar ) = 0;
      virtual HRESULT __stdcall get_Type (
        /*[out,retval]*/ TagENUM DataTypeEnum * psDataType ) = 0;
      virtual HRESULT __stdcall put_Type (
        /*[in]*/ TagENUM DataTypeEnum psDataType ) = 0;
      virtual HRESULT __stdcall put_Direction (
        /*[in]*/ TagENUM ParameterDirectionEnum plParmDirection ) = 0;
      virtual HRESULT __stdcall get_Direction (
        /*[out,retval]*/ TagENUM ParameterDirectionEnum * plParmDirection ) = 0;
      virtual HRESULT __stdcall put_Precision (
        /*[in]*/ unsigned char pbPrecision ) = 0;
      virtual HRESULT __stdcall get_Precision (
        /*[out,retval]*/ unsigned char * pbPrecision ) = 0;
      virtual HRESULT __stdcall put_NumericScale (
        /*[in]*/ unsigned char pbScale ) = 0;
      virtual HRESULT __stdcall get_NumericScale (
        /*[out,retval]*/ unsigned char * pbScale ) = 0;
      virtual HRESULT __stdcall put_Size (
        /*[in]*/ ADO_LONGPTR pl ) = 0;
      virtual HRESULT __stdcall get_Size (
        /*[out,retval]*/ ADO_LONGPTR * pl ) = 0;
      virtual HRESULT __stdcall raw_AppendChunk (
        /*[in]*/ VARIANT Val ) = 0;
      virtual HRESULT __stdcall get_Attributes (
        /*[out,retval]*/ long * plParmAttribs ) = 0;
      virtual HRESULT __stdcall put_Attributes (
        /*[in]*/ long plParmAttribs ) = 0;
};

struct __declspec(uuid("0000050d-0000-0010-8000-00aa006d2ea4"))
Parameters : _DynaCollection
{
    //
    // Property data
    //

    __declspec(property(get=GetItem))
    _ParameterPtr Item[];

    //
    // Wrapper methods for error-handling
    //

    _ParameterPtr GetItem (
        const _variant_t & Index );

    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_Item (
        /*[in]*/ VARIANT Index,
        /*[out,retval]*/ struct _Parameter * * ppvObject ) = 0;
};

struct __declspec(uuid("00000400-0000-0010-8000-00aa006d2ea4"))
ConnectionEvents : IDispatch
{
    //
    // Wrapper methods for error-handling
    //

    // Methods:
    HRESULT InfoMessage (
        struct Error * pError,
        TagENUM EventStatusEnum * adStatus,
        struct _Connection * pConnection );
    HRESULT BeginTransComplete (
        long TransactionLevel,
        struct Error * pError,
        TagENUM EventStatusEnum * adStatus,
        struct _Connection * pConnection );
    HRESULT CommitTransComplete (
        struct Error * pError,
        TagENUM EventStatusEnum * adStatus,
        struct _Connection * pConnection );
    HRESULT RollbackTransComplete (
        struct Error * pError,
        TagENUM EventStatusEnum * adStatus,
        struct _Connection * pConnection );
    HRESULT WillExecute (
        BSTR * Source,
        TagENUM CursorTypeEnum * CursorType,
        TagENUM LockTypeEnum * LockType,
        long * Options,
        TagENUM EventStatusEnum * adStatus,
        struct _Command * pCommand,
        struct _Recordset * pRecordset,
        struct _Connection * pConnection );
    HRESULT ExecuteComplete (
        long RecordsAffected,
        struct Error * pError,
        TagENUM EventStatusEnum * adStatus,
        struct _Command * pCommand,
        struct _Recordset * pRecordset,
        struct _Connection * pConnection );
    HRESULT WillConnect (
        BSTR * ConnectionString,
        BSTR * UserID,
        BSTR * Password,
        long * Options,
        TagENUM EventStatusEnum * adStatus,
        struct _Connection * pConnection );
    HRESULT ConnectComplete (
        struct Error * pError,
        TagENUM EventStatusEnum * adStatus,
        struct _Connection * pConnection );
    HRESULT Disconnect (
        TagENUM EventStatusEnum * adStatus,
        struct _Connection * pConnection );
};

struct __declspec(uuid("00000266-0000-0010-8000-00aa006d2ea4"))
RecordsetEvents : IDispatch
{
    //
    // Wrapper methods for error-handling
    //

    // Methods:
    HRESULT WillChangeField (
        long cFields,
        const _variant_t & Fields,
        TagENUM EventStatusEnum * adStatus,
        struct _Recordset * pRecordset );
    HRESULT FieldChangeComplete (
        long cFields,
        const _variant_t & Fields,
        struct Error * pError,
        TagENUM EventStatusEnum * adStatus,
        struct _Recordset * pRecordset );
    HRESULT WillChangeRecord (
        TagENUM EventReasonEnum adReason,
        long cRecords,
        TagENUM EventStatusEnum * adStatus,
        struct _Recordset * pRecordset );
    HRESULT RecordChangeComplete (
        TagENUM EventReasonEnum adReason,
        long cRecords,
        struct Error * pError,
        TagENUM EventStatusEnum * adStatus,
        struct _Recordset * pRecordset );
    HRESULT WillChangeRecordset (
        TagENUM EventReasonEnum adReason,
        TagENUM EventStatusEnum * adStatus,
        struct _Recordset * pRecordset );
    HRESULT RecordsetChangeComplete (
        TagENUM EventReasonEnum adReason,
        struct Error * pError,
        TagENUM EventStatusEnum * adStatus,
        struct _Recordset * pRecordset );
    HRESULT WillMove (
        TagENUM EventReasonEnum adReason,
        TagENUM EventStatusEnum * adStatus,
        struct _Recordset * pRecordset );
    HRESULT MoveComplete (
        TagENUM EventReasonEnum adReason,
        struct Error * pError,
        TagENUM EventStatusEnum * adStatus,
        struct _Recordset * pRecordset );
    HRESULT EndOfRecordset (
        VARIANT_BOOL * fMoreData,
        TagENUM EventStatusEnum * adStatus,
        struct _Recordset * pRecordset );
    HRESULT FetchProgress (
        long Progress,
        long MaxProgress,
        TagENUM EventStatusEnum * adStatus,
        struct _Recordset * pRecordset );
    HRESULT FetchComplete (
        struct Error * pError,
        TagENUM EventStatusEnum * adStatus,
        struct _Recordset * pRecordset );
};

struct __declspec(uuid("00000516-0000-0010-8000-00aa006d2ea4"))
ADOConnectionConstruction15 : IUnknown
{
    //
    // Property data
    //

    __declspec(property(get=GetDSO))
    IUnknownPtr DSO;
    __declspec(property(get=GetSession))
    IUnknownPtr Session;

    //
    // Wrapper methods for error-handling
    //

    IUnknownPtr GetDSO ( );
    IUnknownPtr GetSession ( );
    HRESULT WrapDSOandSession (
        IUnknown * pDSO,
        IUnknown * pSession );

    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_DSO (
        /*[out,retval]*/ IUnknown * * ppDSO ) = 0;
      virtual HRESULT __stdcall get_Session (
        /*[out,retval]*/ IUnknown * * ppSession ) = 0;
      virtual HRESULT __stdcall raw_WrapDSOandSession (
        /*[in]*/ IUnknown * pDSO,
        /*[in]*/ IUnknown * pSession ) = 0;
};

struct __declspec(uuid("00000551-0000-0010-8000-00aa006d2ea4"))
ADOConnectionConstruction : ADOConnectionConstruction15
{};

struct __declspec(uuid("00000514-0000-0010-8000-00aa006d2ea4"))
Connection;
    // [ default ] interface _Connection
    // [ default, source ] dispinterface ConnectionEvents

struct __declspec(uuid("00000560-0000-0010-8000-00aa006d2ea4"))
Record;
    // [ default ] interface _Record

struct __declspec(uuid("00000565-0000-0010-8000-00aa006d2ea4"))
_Stream : IDispatch
{
    //
    // Property data
    //

    __declspec(property(get=GetSize))
    ADO_LONGPTR Size;
    __declspec(property(get=GetEOS))
    VARIANT_BOOL EOS;
    __declspec(property(get=GetPosition,put=PutPosition))
    ADO_LONGPTR Position;
    __declspec(property(get=GetType,put=PutType))
    TagENUM StreamTypeEnum Type;
    __declspec(property(get=GetLineSeparator,put=PutLineSeparator))
    TagENUM LineSeparatorEnum LineSeparator;
    __declspec(property(get=GetState))
    TagENUM ObjectStateEnum State;
    __declspec(property(get=GetMode,put=PutMode))
    TagENUM ConnectModeEnum Mode;
    __declspec(property(get=GetCharset,put=PutCharset))
    _bstr_t Charset;

    //
    // Wrapper methods for error-handling
    //

    ADO_LONGPTR GetSize ( );
    VARIANT_BOOL GetEOS ( );
    ADO_LONGPTR GetPosition ( );
    void PutPosition (
        ADO_LONGPTR pPos );
    TagENUM StreamTypeEnum GetType ( );
    void PutType (
        TagENUM StreamTypeEnum ptype );
    TagENUM LineSeparatorEnum GetLineSeparator ( );
    void PutLineSeparator (
        TagENUM LineSeparatorEnum pLS );
    TagENUM ObjectStateEnum GetState ( );
    TagENUM ConnectModeEnum GetMode ( );
    void PutMode (
        TagENUM ConnectModeEnum pMode );
    _bstr_t GetCharset ( );
    void PutCharset (
        _bstr_t pbstrCharset );
    _variant_t Read (
        long NumBytes );
    HRESULT Open (
        const _variant_t & Source,
        TagENUM ConnectModeEnum Mode,
        TagENUM StreamOpenOptionsEnum Options,
        _bstr_t UserName,
        _bstr_t Password );
    HRESULT Close ( );
    HRESULT SkipLine ( );
    HRESULT Write (
        const _variant_t & Buffer );
    HRESULT SetEOS ( );
    HRESULT CopyTo (
        struct _Stream * DestStream,
        ADO_LONGPTR CharNumber );
    HRESULT Flush ( );
    HRESULT SaveToFile (
        _bstr_t FileName,
        TagENUM SaveOptionsEnum Options );
    HRESULT LoadFromFile (
        _bstr_t FileName );
    _bstr_t ReadText (
        long NumChars );
    HRESULT WriteText (
        _bstr_t Data,
        TagENUM StreamWriteEnum Options );
    HRESULT Cancel ( );

    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_Size (
        /*[out,retval]*/ ADO_LONGPTR * pSize ) = 0;
      virtual HRESULT __stdcall get_EOS (
        /*[out,retval]*/ VARIANT_BOOL * pEOS ) = 0;
      virtual HRESULT __stdcall get_Position (
        /*[out,retval]*/ ADO_LONGPTR * pPos ) = 0;
      virtual HRESULT __stdcall put_Position (
        /*[in]*/ ADO_LONGPTR pPos ) = 0;
      virtual HRESULT __stdcall get_Type (
        /*[out,retval]*/ TagENUM StreamTypeEnum * ptype ) = 0;
      virtual HRESULT __stdcall put_Type (
        /*[in]*/ TagENUM StreamTypeEnum ptype ) = 0;
      virtual HRESULT __stdcall get_LineSeparator (
        /*[out,retval]*/ TagENUM LineSeparatorEnum * pLS ) = 0;
      virtual HRESULT __stdcall put_LineSeparator (
        /*[in]*/ TagENUM LineSeparatorEnum pLS ) = 0;
      virtual HRESULT __stdcall get_State (
        /*[out,retval]*/ TagENUM ObjectStateEnum * pState ) = 0;
      virtual HRESULT __stdcall get_Mode (
        /*[out,retval]*/ TagENUM ConnectModeEnum * pMode ) = 0;
      virtual HRESULT __stdcall put_Mode (
        /*[in]*/ TagENUM ConnectModeEnum pMode ) = 0;
      virtual HRESULT __stdcall get_Charset (
        /*[out,retval]*/ BSTR * pbstrCharset ) = 0;
      virtual HRESULT __stdcall put_Charset (
        /*[in]*/ BSTR pbstrCharset ) = 0;
      virtual HRESULT __stdcall raw_Read (
        /*[in]*/ long NumBytes,
        /*[out,retval]*/ VARIANT * pval ) = 0;
      virtual HRESULT __stdcall raw_Open (
        /*[in]*/ VARIANT Source,
        /*[in]*/ TagENUM ConnectModeEnum Mode,
        /*[in]*/ TagENUM StreamOpenOptionsEnum Options,
        /*[in]*/ BSTR UserName,
        /*[in]*/ BSTR Password ) = 0;
      virtual HRESULT __stdcall raw_Close ( ) = 0;
      virtual HRESULT __stdcall raw_SkipLine ( ) = 0;
      virtual HRESULT __stdcall raw_Write (
        /*[in]*/ VARIANT Buffer ) = 0;
      virtual HRESULT __stdcall raw_SetEOS ( ) = 0;
      virtual HRESULT __stdcall raw_CopyTo (
        /*[in]*/ struct _Stream * DestStream,
        /*[in]*/ ADO_LONGPTR CharNumber ) = 0;
      virtual HRESULT __stdcall raw_Flush ( ) = 0;
      virtual HRESULT __stdcall raw_SaveToFile (
        /*[in]*/ BSTR FileName,
        /*[in]*/ TagENUM SaveOptionsEnum Options ) = 0;
      virtual HRESULT __stdcall raw_LoadFromFile (
        /*[in]*/ BSTR FileName ) = 0;
      virtual HRESULT __stdcall raw_ReadText (
        /*[in]*/ long NumChars,
        /*[out,retval]*/ BSTR * pbstr ) = 0;
      virtual HRESULT __stdcall raw_WriteText (
        /*[in]*/ BSTR Data,
        /*[in]*/ TagENUM StreamWriteEnum Options ) = 0;
      virtual HRESULT __stdcall raw_Cancel ( ) = 0;
};

struct __declspec(uuid("00000566-0000-0010-8000-00aa006d2ea4"))
Stream;
    // [ default ] interface _Stream

struct __declspec(uuid("00000567-0000-0010-8000-00aa006d2ea4"))
ADORecordConstruction : IDispatch
{
    //
    // Property data
    //

    __declspec(property(get=GetRow,put=PutRow))
    IUnknownPtr Row;
    __declspec(property(put=PutParentRow))
    IUnknownPtr ParentRow;

    //
    // Wrapper methods for error-handling
    //

    IUnknownPtr GetRow ( );
    void PutRow (
        IUnknown * ppRow );
    void PutParentRow (
        IUnknown * _arg1 );

    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_Row (
        /*[out,retval]*/ IUnknown * * ppRow ) = 0;
      virtual HRESULT __stdcall put_Row (
        /*[in]*/ IUnknown * ppRow ) = 0;
      virtual HRESULT __stdcall put_ParentRow (
        /*[in]*/ IUnknown * _arg1 ) = 0;
};

struct __declspec(uuid("00000568-0000-0010-8000-00aa006d2ea4"))
ADOStreamConstruction : IDispatch
{
    //
    // Property data
    //

    __declspec(property(get=GetStream,put=PutStream))
    IUnknownPtr Stream;

    //
    // Wrapper methods for error-handling
    //

    IUnknownPtr GetStream ( );
    void PutStream (
        IUnknown * ppStm );

    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_Stream (
        /*[out,retval]*/ IUnknown * * ppStm ) = 0;
      virtual HRESULT __stdcall put_Stream (
        /*[in]*/ IUnknown * ppStm ) = 0;
};

struct __declspec(uuid("00000517-0000-0010-8000-00aa006d2ea4"))
ADOCommandConstruction : IUnknown
{
    //
    // Property data
    //

    __declspec(property(get=GetOLEDBCommand,put=PutOLEDBCommand))
    IUnknownPtr OLEDBCommand;

    //
    // Wrapper methods for error-handling
    //

    IUnknownPtr GetOLEDBCommand ( );
    void PutOLEDBCommand (
        IUnknown * ppOLEDBCommand );

    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_OLEDBCommand (
        /*[out,retval]*/ IUnknown * * ppOLEDBCommand ) = 0;
      virtual HRESULT __stdcall put_OLEDBCommand (
        /*[in]*/ IUnknown * ppOLEDBCommand ) = 0;
};

struct __declspec(uuid("00000507-0000-0010-8000-00aa006d2ea4"))
Command;
    // [ default ] interface _Command

struct __declspec(uuid("00000535-0000-0010-8000-00aa006d2ea4"))
Recordset;
    // [ default ] interface _Recordset
    // [ default, source ] dispinterface RecordsetEvents

struct __declspec(uuid("00000283-0000-0010-8000-00aa006d2ea4"))
ADORecordsetConstruction : IDispatch
{
    //
    // Property data
    //

    __declspec(property(get=GetRowset,put=PutRowset))
    IUnknownPtr Rowset;
    __declspec(property(get=GetChapter,put=PutChapter))
    ADO_LONGPTR Chapter;
    __declspec(property(get=GetRowPosition,put=PutRowPosition))
    IUnknownPtr RowPosition;

    //
    // Wrapper methods for error-handling
    //

    IUnknownPtr GetRowset ( );
    void PutRowset (
        IUnknown * ppRowset );
    ADO_LONGPTR GetChapter ( );
    void PutChapter (
        ADO_LONGPTR plChapter );
    IUnknownPtr GetRowPosition ( );
    void PutRowPosition (
        IUnknown * ppRowPos );

    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_Rowset (
        /*[out,retval]*/ IUnknown * * ppRowset ) = 0;
      virtual HRESULT __stdcall put_Rowset (
        /*[in]*/ IUnknown * ppRowset ) = 0;
      virtual HRESULT __stdcall get_Chapter (
        /*[out,retval]*/ ADO_LONGPTR * plChapter ) = 0;
      virtual HRESULT __stdcall put_Chapter (
        /*[in]*/ ADO_LONGPTR plChapter ) = 0;
      virtual HRESULT __stdcall get_RowPosition (
        /*[out,retval]*/ IUnknown * * ppRowPos ) = 0;
      virtual HRESULT __stdcall put_RowPosition (
        /*[in]*/ IUnknown * ppRowPos ) = 0;
};

struct __declspec(uuid("00000505-0000-0010-8000-00aa006d2ea4"))
Field15 : _ADO
{
    //
    // Property data
    //

    __declspec(property(get=GetValue,put=PutValue))
    _variant_t Value;
    __declspec(property(get=GetName))
    _bstr_t Name;
    __declspec(property(get=GetType))
    TagENUM DataTypeEnum Type;
    __declspec(property(get=GetDefinedSize))
    ADO_LONGPTR DefinedSize;
    __declspec(property(get=GetOriginalValue))
    _variant_t OriginalValue;
    __declspec(property(get=GetUnderlyingValue))
    _variant_t UnderlyingValue;
    __declspec(property(get=GetActualSize))
    ADO_LONGPTR ActualSize;
    __declspec(property(get=GetPrecision))
    unsigned char Precision;
    __declspec(property(get=GetNumericScale))
    unsigned char NumericScale;
    __declspec(property(get=GetAttributes))
    long Attributes;

    //
    // Wrapper methods for error-handling
    //

    ADO_LONGPTR GetActualSize ( );
    long GetAttributes ( );
    ADO_LONGPTR GetDefinedSize ( );
    _bstr_t GetName ( );
    TagENUM DataTypeEnum GetType ( );
    _variant_t GetValue ( );
    void PutValue (
        const _variant_t & pvar );
    unsigned char GetPrecision ( );
    unsigned char GetNumericScale ( );
    HRESULT AppendChunk (
        const _variant_t & Data );
    _variant_t GetChunk (
        long Length );
    _variant_t GetOriginalValue ( );
    _variant_t GetUnderlyingValue ( );

    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_ActualSize (
        /*[out,retval]*/ ADO_LONGPTR * pl ) = 0;
      virtual HRESULT __stdcall get_Attributes (
        /*[out,retval]*/ long * pl ) = 0;
      virtual HRESULT __stdcall get_DefinedSize (
        /*[out,retval]*/ ADO_LONGPTR * pl ) = 0;
      virtual HRESULT __stdcall get_Name (
        /*[out,retval]*/ BSTR * pbstr ) = 0;
      virtual HRESULT __stdcall get_Type (
        /*[out,retval]*/ TagENUM DataTypeEnum * pDataType ) = 0;
      virtual HRESULT __stdcall get_Value (
        /*[out,retval]*/ VARIANT * pvar ) = 0;
      virtual HRESULT __stdcall put_Value (
        /*[in]*/ VARIANT pvar ) = 0;
      virtual HRESULT __stdcall get_Precision (
        /*[out,retval]*/ unsigned char * pbPrecision ) = 0;
      virtual HRESULT __stdcall get_NumericScale (
        /*[out,retval]*/ unsigned char * pbNumericScale ) = 0;
      virtual HRESULT __stdcall raw_AppendChunk (
        /*[in]*/ VARIANT Data ) = 0;
      virtual HRESULT __stdcall raw_GetChunk (
        /*[in]*/ long Length,
        /*[out,retval]*/ VARIANT * pvar ) = 0;
      virtual HRESULT __stdcall get_OriginalValue (
        /*[out,retval]*/ VARIANT * pvar ) = 0;
      virtual HRESULT __stdcall get_UnderlyingValue (
        /*[out,retval]*/ VARIANT * pvar ) = 0;
};

struct __declspec(uuid("0000050b-0000-0010-8000-00aa006d2ea4"))
Parameter;
    // [ default ] interface _Parameter

struct __declspec(uuid("00000508-0000-0010-8000-00aa006d2ea4"))
Command15 : _ADO
{
    //
    // Property data
    //

    __declspec(property(get=GetParameters))
    ParametersPtr Parameters;
    __declspec(property(get=GetActiveConnection,put=PutRefActiveConnection))
    _ConnectionPtr ActiveConnection;
    __declspec(property(get=GetCommandText,put=PutCommandText))
    _bstr_t CommandText;
    __declspec(property(get=GetCommandTimeout,put=PutCommandTimeout))
    long CommandTimeout;
    __declspec(property(get=GetPrepared,put=PutPrepared))
    VARIANT_BOOL Prepared;
    __declspec(property(get=GetCommandType,put=PutCommandType))
    TagENUM CommandTypeEnum CommandType;
    __declspec(property(get=GetName,put=PutName))
    _bstr_t Name;

    //
    // Wrapper methods for error-handling
    //

    _ConnectionPtr GetActiveConnection ( );
    void PutRefActiveConnection (
        struct _Connection * ppvObject );
    void PutActiveConnection (
        const _variant_t & ppvObject );
    _bstr_t GetCommandText ( );
    void PutCommandText (
        _bstr_t pbstr );
    long GetCommandTimeout ( );
    void PutCommandTimeout (
        long pl );
    VARIANT_BOOL GetPrepared ( );
    void PutPrepared (
        VARIANT_BOOL pfPrepared );
    _RecordsetPtr Execute (
        VARIANT * RecordsAffected,
        VARIANT * Parameters,
        long Options );
    _ParameterPtr CreateParameter (
        _bstr_t Name,
        TagENUM DataTypeEnum Type,
        TagENUM ParameterDirectionEnum Direction,
        ADO_LONGPTR Size,
        const _variant_t & Value = vtMissing );
    ParametersPtr GetParameters ( );
    void PutCommandType (
        TagENUM CommandTypeEnum plCmdType );
    TagENUM CommandTypeEnum GetCommandType ( );
    _bstr_t GetName ( );
    void PutName (
        _bstr_t pbstrName );

    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_ActiveConnection (
        /*[out,retval]*/ struct _Connection * * ppvObject ) = 0;
      virtual HRESULT __stdcall putref_ActiveConnection (
        /*[in]*/ struct _Connection * ppvObject ) = 0;
      virtual HRESULT __stdcall put_ActiveConnection (
        /*[in]*/ VARIANT ppvObject ) = 0;
      virtual HRESULT __stdcall get_CommandText (
        /*[out,retval]*/ BSTR * pbstr ) = 0;
      virtual HRESULT __stdcall put_CommandText (
        /*[in]*/ BSTR pbstr ) = 0;
      virtual HRESULT __stdcall get_CommandTimeout (
        /*[out,retval]*/ long * pl ) = 0;
      virtual HRESULT __stdcall put_CommandTimeout (
        /*[in]*/ long pl ) = 0;
      virtual HRESULT __stdcall get_Prepared (
        /*[out,retval]*/ VARIANT_BOOL * pfPrepared ) = 0;
      virtual HRESULT __stdcall put_Prepared (
        /*[in]*/ VARIANT_BOOL pfPrepared ) = 0;
      virtual HRESULT __stdcall raw_Execute (
        /*[out]*/ VARIANT * RecordsAffected,
        /*[in]*/ VARIANT * Parameters,
        /*[in]*/ long Options,
        /*[out,retval]*/ struct _Recordset * * ppiRs ) = 0;
      virtual HRESULT __stdcall raw_CreateParameter (
        /*[in]*/ BSTR Name,
        /*[in]*/ TagENUM DataTypeEnum Type,
        /*[in]*/ TagENUM ParameterDirectionEnum Direction,
        /*[in]*/ ADO_LONGPTR Size,
        /*[in]*/ VARIANT Value,
        /*[out,retval]*/ struct _Parameter * * ppiprm ) = 0;
      virtual HRESULT __stdcall get_Parameters (
        /*[out,retval]*/ struct Parameters * * ppvObject ) = 0;
      virtual HRESULT __stdcall put_CommandType (
        /*[in]*/ TagENUM CommandTypeEnum plCmdType ) = 0;
      virtual HRESULT __stdcall get_CommandType (
        /*[out,retval]*/ TagENUM CommandTypeEnum * plCmdType ) = 0;
      virtual HRESULT __stdcall get_Name (
        /*[out,retval]*/ BSTR * pbstrName ) = 0;
      virtual HRESULT __stdcall put_Name (
        /*[in]*/ BSTR pbstrName ) = 0;
};

struct __declspec(uuid("0000054e-0000-0010-8000-00aa006d2ea4"))
Command25 : Command15
{
    //
    // Property data
    //

    __declspec(property(get=GetState))
    long State;

    //
    // Wrapper methods for error-handling
    //

    long GetState ( );
    HRESULT Cancel ( );

    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_State (
        /*[out,retval]*/ long * plObjState ) = 0;
      virtual HRESULT __stdcall raw_Cancel ( ) = 0;
};

struct __declspec(uuid("b08400bd-f9d1-4d02-b856-71d5dba123e9"))
_Command : Command25
{
    //
    // Property data
    //

    __declspec(property(get=GetDialect,put=PutDialect))
    _bstr_t Dialect;
    __declspec(property(get=GetNamedParameters,put=PutNamedParameters))
    VARIANT_BOOL NamedParameters;

    //
    // Wrapper methods for error-handling
    //

    void PutRefCommandStream (
        IUnknown * pvStream );
    _variant_t GetCommandStream ( );
    void PutDialect (
        _bstr_t pbstrDialect );
    _bstr_t GetDialect ( );
    void PutNamedParameters (
        VARIANT_BOOL pfNamedParameters );
    VARIANT_BOOL GetNamedParameters ( );

    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall putref_CommandStream (
        /*[in]*/ IUnknown * pvStream ) = 0;
      virtual HRESULT __stdcall get_CommandStream (
        /*[out,retval]*/ VARIANT * pvStream ) = 0;
      virtual HRESULT __stdcall put_Dialect (
        /*[in]*/ BSTR pbstrDialect ) = 0;
      virtual HRESULT __stdcall get_Dialect (
        /*[out,retval]*/ BSTR * pbstrDialect ) = 0;
      virtual HRESULT __stdcall put_NamedParameters (
        /*[in]*/ VARIANT_BOOL pfNamedParameters ) = 0;
      virtual HRESULT __stdcall get_NamedParameters (
        /*[out,retval]*/ VARIANT_BOOL * pfNamedParameters ) = 0;
};

struct __declspec(uuid("00000515-0000-0010-8000-00aa006d2ea4"))
Connection15 : _ADO
{
    //
    // Property data
    //

    __declspec(property(get=GetConnectionString,put=PutConnectionString))
    _bstr_t ConnectionString;
    __declspec(property(get=GetCommandTimeout,put=PutCommandTimeout))
    long CommandTimeout;
    __declspec(property(get=GetConnectionTimeout,put=PutConnectionTimeout))
    long ConnectionTimeout;
    __declspec(property(get=GetVersion))
    _bstr_t Version;
    __declspec(property(get=GetErrors))
    ErrorsPtr Errors;
    __declspec(property(get=GetDefaultDatabase,put=PutDefaultDatabase))
    _bstr_t DefaultDatabase;
    __declspec(property(get=GetIsolationLevel,put=PutIsolationLevel))
    TagENUM IsolationLevelEnum IsolationLevel;
    __declspec(property(get=GetAttributes,put=PutAttributes))
    long Attributes;
    __declspec(property(get=GetCursorLocation,put=PutCursorLocation))
    TagENUM CursorLocationEnum CursorLocation;
    __declspec(property(get=GetMode,put=PutMode))
    TagENUM ConnectModeEnum Mode;
    __declspec(property(get=GetProvider,put=PutProvider))
    _bstr_t Provider;
    __declspec(property(get=GetState))
    long State;

    //
    // Wrapper methods for error-handling
    //

    _bstr_t GetConnectionString ( );
    void PutConnectionString (
        _bstr_t pbstr );
    long GetCommandTimeout ( );
    void PutCommandTimeout (
        long plTimeout );
    long GetConnectionTimeout ( );
    void PutConnectionTimeout (
        long plTimeout );
    _bstr_t GetVersion ( );
    HRESULT Close ( );
    _RecordsetPtr Execute (
        _bstr_t CommandText,
        VARIANT * RecordsAffected,
        long Options );
    long BeginTrans ( );
    HRESULT CommitTrans ( );
    HRESULT RollbackTrans ( );
    HRESULT Open (
        _bstr_t ConnectionString,
        _bstr_t UserID,
        _bstr_t Password,
        long Options );
    ErrorsPtr GetErrors ( );
    _bstr_t GetDefaultDatabase ( );
    void PutDefaultDatabase (
        _bstr_t pbstr );
    TagENUM IsolationLevelEnum GetIsolationLevel ( );
    void PutIsolationLevel (
        TagENUM IsolationLevelEnum Level );
    long GetAttributes ( );
    void PutAttributes (
        long plAttr );
    TagENUM CursorLocationEnum GetCursorLocation ( );
    void PutCursorLocation (
        TagENUM CursorLocationEnum plCursorLoc );
    TagENUM ConnectModeEnum GetMode ( );
    void PutMode (
        TagENUM ConnectModeEnum plMode );
    _bstr_t GetProvider ( );
    void PutProvider (
        _bstr_t pbstr );
    long GetState ( );
    _RecordsetPtr OpenSchema (
        TagENUM SchemaEnum Schema,
        const _variant_t & Restrictions = vtMissing,
        const _variant_t & SchemaID = vtMissing );

    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_ConnectionString (
        /*[out,retval]*/ BSTR * pbstr ) = 0;
      virtual HRESULT __stdcall put_ConnectionString (
        /*[in]*/ BSTR pbstr ) = 0;
      virtual HRESULT __stdcall get_CommandTimeout (
        /*[out,retval]*/ long * plTimeout ) = 0;
      virtual HRESULT __stdcall put_CommandTimeout (
        /*[in]*/ long plTimeout ) = 0;
      virtual HRESULT __stdcall get_ConnectionTimeout (
        /*[out,retval]*/ long * plTimeout ) = 0;
      virtual HRESULT __stdcall put_ConnectionTimeout (
        /*[in]*/ long plTimeout ) = 0;
      virtual HRESULT __stdcall get_Version (
        /*[out,retval]*/ BSTR * pbstr ) = 0;
      virtual HRESULT __stdcall raw_Close ( ) = 0;
      virtual HRESULT __stdcall raw_Execute (
        /*[in]*/ BSTR CommandText,
        /*[out]*/ VARIANT * RecordsAffected,
        /*[in]*/ long Options,
        /*[out,retval]*/ struct _Recordset * * ppiRset ) = 0;
      virtual HRESULT __stdcall raw_BeginTrans (
        /*[out,retval]*/ long * TransactionLevel ) = 0;
      virtual HRESULT __stdcall raw_CommitTrans ( ) = 0;
      virtual HRESULT __stdcall raw_RollbackTrans ( ) = 0;
      virtual HRESULT __stdcall raw_Open (
        /*[in]*/ BSTR ConnectionString,
        /*[in]*/ BSTR UserID,
        /*[in]*/ BSTR Password,
        /*[in]*/ long Options ) = 0;
      virtual HRESULT __stdcall get_Errors (
        /*[out,retval]*/ struct Errors * * ppvObject ) = 0;
      virtual HRESULT __stdcall get_DefaultDatabase (
        /*[out,retval]*/ BSTR * pbstr ) = 0;
      virtual HRESULT __stdcall put_DefaultDatabase (
        /*[in]*/ BSTR pbstr ) = 0;
      virtual HRESULT __stdcall get_IsolationLevel (
        /*[out,retval]*/ TagENUM IsolationLevelEnum * Level ) = 0;
      virtual HRESULT __stdcall put_IsolationLevel (
        /*[in]*/ TagENUM IsolationLevelEnum Level ) = 0;
      virtual HRESULT __stdcall get_Attributes (
        /*[out,retval]*/ long * plAttr ) = 0;
      virtual HRESULT __stdcall put_Attributes (
        /*[in]*/ long plAttr ) = 0;
      virtual HRESULT __stdcall get_CursorLocation (
        /*[out,retval]*/ TagENUM CursorLocationEnum * plCursorLoc ) = 0;
      virtual HRESULT __stdcall put_CursorLocation (
        /*[in]*/ TagENUM CursorLocationEnum plCursorLoc ) = 0;
      virtual HRESULT __stdcall get_Mode (
        /*[out,retval]*/ TagENUM ConnectModeEnum * plMode ) = 0;
      virtual HRESULT __stdcall put_Mode (
        /*[in]*/ TagENUM ConnectModeEnum plMode ) = 0;
      virtual HRESULT __stdcall get_Provider (
        /*[out,retval]*/ BSTR * pbstr ) = 0;
      virtual HRESULT __stdcall put_Provider (
        /*[in]*/ BSTR pbstr ) = 0;
      virtual HRESULT __stdcall get_State (
        /*[out,retval]*/ long * plObjState ) = 0;
      virtual HRESULT __stdcall raw_OpenSchema (
        /*[in]*/ TagENUM SchemaEnum Schema,
        /*[in]*/ VARIANT Restrictions,
        /*[in]*/ VARIANT SchemaID,
        /*[out,retval]*/ struct _Recordset * * pprset ) = 0;
};

struct __declspec(uuid("00000550-0000-0010-8000-00aa006d2ea4"))
_Connection : Connection15
{
    //
    // Wrapper methods for error-handling
    //

    HRESULT Cancel ( );

    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall raw_Cancel ( ) = 0;
};

struct __declspec(uuid("0000050e-0000-0010-8000-00aa006d2ea4"))
Recordset15 : _ADO
{
    //
    // Property data
    //

    __declspec(property(get=GetFields))
    FieldsPtr Fields;
    __declspec(property(get=GetPageSize,put=PutPageSize))
    long PageSize;
    __declspec(property(get=GetPageCount))
    ADO_LONGPTR PageCount;
    __declspec(property(get=GetCursorLocation,put=PutCursorLocation))
    TagENUM CursorLocationEnum CursorLocation;
    __declspec(property(get=GetState))
    long State;
    __declspec(property(get=GetMarshalOptions,put=PutMarshalOptions))
    TagENUM MarshalOptionsEnum MarshalOptions;
    __declspec(property(get=GetCollect,put=PutCollect))
    _variant_t Collect[];
    __declspec(property(get=GetEditMode))
    TagENUM EditModeEnum EditMode;
    __declspec(property(get=GetStatus))
    long Status;
    __declspec(property(get=GetFilter,put=PutFilter))
    _variant_t Filter;
    __declspec(property(get=GetSort,put=PutSort))
    _bstr_t Sort;
    __declspec(property(get=GetAbsolutePosition,put=PutAbsolutePosition))
    PositionEnum_Param AbsolutePosition;
    __declspec(property(get=GetBOF))
    VARIANT_BOOL BOF;
    __declspec(property(get=GetBookmark,put=PutBookmark))
    _variant_t Bookmark;
    __declspec(property(get=GetCacheSize,put=PutCacheSize))
    long CacheSize;
    __declspec(property(get=GetCursorType,put=PutCursorType))
    TagENUM CursorTypeEnum CursorType;
    __declspec(property(get=GetadoEOF))
    VARIANT_BOOL adoEOF;
    __declspec(property(get=GetAbsolutePage,put=PutAbsolutePage))
    PositionEnum_Param AbsolutePage;
    __declspec(property(get=GetLockType,put=PutLockType))
    TagENUM LockTypeEnum LockType;
    __declspec(property(get=GetMaxRecords,put=PutMaxRecords))
    ADO_LONGPTR MaxRecords;
    __declspec(property(get=GetRecordCount))
    ADO_LONGPTR RecordCount;

    //
    // Wrapper methods for error-handling
    //

    PositionEnum_Param GetAbsolutePosition ( );
    void PutAbsolutePosition (
        PositionEnum_Param pl );
    void PutRefActiveConnection (
        IDispatch * pvar );
    void PutActiveConnection (
        const _variant_t & pvar );
    _variant_t GetActiveConnection ( );
    VARIANT_BOOL GetBOF ( );
    _variant_t GetBookmark ( );
    void PutBookmark (
        const _variant_t & pvBookmark );
    long GetCacheSize ( );
    void PutCacheSize (
        long pl );
    TagENUM CursorTypeEnum GetCursorType ( );
    void PutCursorType (
        TagENUM CursorTypeEnum plCursorType );
    VARIANT_BOOL GetadoEOF ( );
    FieldsPtr GetFields ( );
    TagENUM LockTypeEnum GetLockType ( );
    void PutLockType (
        TagENUM LockTypeEnum plLockType );
    ADO_LONGPTR GetMaxRecords ( );
    void PutMaxRecords (
        ADO_LONGPTR plMaxRecords );
    ADO_LONGPTR GetRecordCount ( );
    void PutRefSource (
        IDispatch * pvSource );
    void PutSource (
        _bstr_t pvSource );
    _variant_t GetSource ( );
    HRESULT AddNew (
        const _variant_t & FieldList = vtMissing,
        const _variant_t & Values = vtMissing );
    HRESULT CancelUpdate ( );
    HRESULT Close ( );
    HRESULT Delete (
        TagENUM AffectEnum AffectRecords );
    _variant_t GetRows (
        long Rows,
        const _variant_t & Start = vtMissing,
        const _variant_t & Fields = vtMissing );
    HRESULT Move (
        ADO_LONGPTR NumRecords,
        const _variant_t & Start = vtMissing );
    HRESULT MoveNext ( );
    HRESULT MovePrevious ( );
    HRESULT MoveFirst ( );
    HRESULT MoveLast ( );
    HRESULT Open (
        const _variant_t & Source,
        const _variant_t & ActiveConnection,
        TagENUM CursorTypeEnum CursorType,
        TagENUM LockTypeEnum LockType,
        long Options );
    HRESULT Requery (
        long Options );
    HRESULT _xResync (
        TagENUM AffectEnum AffectRecords );
    HRESULT Update (
        const _variant_t & Fields = vtMissing,
        const _variant_t & Values = vtMissing );
    PositionEnum_Param GetAbsolutePage ( );
    void PutAbsolutePage (
        PositionEnum_Param pl );
    TagENUM EditModeEnum GetEditMode ( );
    _variant_t GetFilter ( );
    void PutFilter (
        const _variant_t & Criteria );
    ADO_LONGPTR GetPageCount ( );
    long GetPageSize ( );
    void PutPageSize (
        long pl );
    _bstr_t GetSort ( );
    void PutSort (
        _bstr_t Criteria );
    long GetStatus ( );
    long GetState ( );
    _RecordsetPtr _xClone ( );
    HRESULT UpdateBatch (
        TagENUM AffectEnum AffectRecords );
    HRESULT CancelBatch (
        TagENUM AffectEnum AffectRecords );
    TagENUM CursorLocationEnum GetCursorLocation ( );
    void PutCursorLocation (
        TagENUM CursorLocationEnum plCursorLoc );
    _RecordsetPtr NextRecordset (
        VARIANT * RecordsAffected );
    VARIANT_BOOL Supports (
        TagENUM CursorOptionEnum CursorOptions );
    _variant_t GetCollect (
        const _variant_t & Index );
    void PutCollect (
        const _variant_t & Index,
        const _variant_t & pvar );
    TagENUM MarshalOptionsEnum GetMarshalOptions ( );
    void PutMarshalOptions (
        TagENUM MarshalOptionsEnum peMarshal );
    HRESULT Find (
        _bstr_t Criteria,
        ADO_LONGPTR SkipRecords,
        TagENUM SearchDirectionEnum SearchDirection,
        const _variant_t & Start = vtMissing );

    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_AbsolutePosition (
        /*[out,retval]*/ PositionEnum_Param * pl ) = 0;
      virtual HRESULT __stdcall put_AbsolutePosition (
        /*[in]*/ PositionEnum_Param pl ) = 0;
      virtual HRESULT __stdcall putref_ActiveConnection (
        /*[in]*/ IDispatch * pvar ) = 0;
      virtual HRESULT __stdcall put_ActiveConnection (
        /*[in]*/ VARIANT pvar ) = 0;
      virtual HRESULT __stdcall get_ActiveConnection (
        /*[out,retval]*/ VARIANT * pvar ) = 0;
      virtual HRESULT __stdcall get_BOF (
        /*[out,retval]*/ VARIANT_BOOL * pb ) = 0;
      virtual HRESULT __stdcall get_Bookmark (
        /*[out,retval]*/ VARIANT * pvBookmark ) = 0;
      virtual HRESULT __stdcall put_Bookmark (
        /*[in]*/ VARIANT pvBookmark ) = 0;
      virtual HRESULT __stdcall get_CacheSize (
        /*[out,retval]*/ long * pl ) = 0;
      virtual HRESULT __stdcall put_CacheSize (
        /*[in]*/ long pl ) = 0;
      virtual HRESULT __stdcall get_CursorType (
        /*[out,retval]*/ TagENUM CursorTypeEnum * plCursorType ) = 0;
      virtual HRESULT __stdcall put_CursorType (
        /*[in]*/ TagENUM CursorTypeEnum plCursorType ) = 0;
      virtual HRESULT __stdcall get_adoEOF (
        /*[out,retval]*/ VARIANT_BOOL * pb ) = 0;
      virtual HRESULT __stdcall get_Fields (
        /*[out,retval]*/ struct Fields * * ppvObject ) = 0;
      virtual HRESULT __stdcall get_LockType (
        /*[out,retval]*/ TagENUM LockTypeEnum * plLockType ) = 0;
      virtual HRESULT __stdcall put_LockType (
        /*[in]*/ TagENUM LockTypeEnum plLockType ) = 0;
      virtual HRESULT __stdcall get_MaxRecords (
        /*[out,retval]*/ ADO_LONGPTR * plMaxRecords ) = 0;
      virtual HRESULT __stdcall put_MaxRecords (
        /*[in]*/ ADO_LONGPTR plMaxRecords ) = 0;
      virtual HRESULT __stdcall get_RecordCount (
        /*[out,retval]*/ ADO_LONGPTR * pl ) = 0;
      virtual HRESULT __stdcall putref_Source (
        /*[in]*/ IDispatch * pvSource ) = 0;
      virtual HRESULT __stdcall put_Source (
        /*[in]*/ BSTR pvSource ) = 0;
      virtual HRESULT __stdcall get_Source (
        /*[out,retval]*/ VARIANT * pvSource ) = 0;
      virtual HRESULT __stdcall raw_AddNew (
        /*[in]*/ VARIANT FieldList = vtMissing,
        /*[in]*/ VARIANT Values = vtMissing ) = 0;
      virtual HRESULT __stdcall raw_CancelUpdate ( ) = 0;
      virtual HRESULT __stdcall raw_Close ( ) = 0;
      virtual HRESULT __stdcall raw_Delete (
        /*[in]*/ TagENUM AffectEnum AffectRecords ) = 0;
      virtual HRESULT __stdcall raw_GetRows (
        /*[in]*/ long Rows,
        /*[in]*/ VARIANT Start,
        /*[in]*/ VARIANT Fields,
        /*[out,retval]*/ VARIANT * pvar ) = 0;
      virtual HRESULT __stdcall raw_Move (
        /*[in]*/ ADO_LONGPTR NumRecords,
        /*[in]*/ VARIANT Start = vtMissing ) = 0;
      virtual HRESULT __stdcall raw_MoveNext ( ) = 0;
      virtual HRESULT __stdcall raw_MovePrevious ( ) = 0;
      virtual HRESULT __stdcall raw_MoveFirst ( ) = 0;
      virtual HRESULT __stdcall raw_MoveLast ( ) = 0;
      virtual HRESULT __stdcall raw_Open (
        /*[in]*/ VARIANT Source,
        /*[in]*/ VARIANT ActiveConnection,
        /*[in]*/ TagENUM CursorTypeEnum CursorType,
        /*[in]*/ TagENUM LockTypeEnum LockType,
        /*[in]*/ long Options ) = 0;
      virtual HRESULT __stdcall raw_Requery (
        /*[in]*/ long Options ) = 0;
      virtual HRESULT __stdcall raw__xResync (
        /*[in]*/ TagENUM AffectEnum AffectRecords ) = 0;
      virtual HRESULT __stdcall raw_Update (
        /*[in]*/ VARIANT Fields = vtMissing,
        /*[in]*/ VARIANT Values = vtMissing ) = 0;
      virtual HRESULT __stdcall get_AbsolutePage (
        /*[out,retval]*/ PositionEnum_Param * pl ) = 0;
      virtual HRESULT __stdcall put_AbsolutePage (
        /*[in]*/ PositionEnum_Param pl ) = 0;
      virtual HRESULT __stdcall get_EditMode (
        /*[out,retval]*/ TagENUM EditModeEnum * pl ) = 0;
      virtual HRESULT __stdcall get_Filter (
        /*[out,retval]*/ VARIANT * Criteria ) = 0;
      virtual HRESULT __stdcall put_Filter (
        /*[in]*/ VARIANT Criteria ) = 0;
      virtual HRESULT __stdcall get_PageCount (
        /*[out,retval]*/ ADO_LONGPTR * pl ) = 0;
      virtual HRESULT __stdcall get_PageSize (
        /*[out,retval]*/ long * pl ) = 0;
      virtual HRESULT __stdcall put_PageSize (
        /*[in]*/ long pl ) = 0;
      virtual HRESULT __stdcall get_Sort (
        /*[out,retval]*/ BSTR * Criteria ) = 0;
      virtual HRESULT __stdcall put_Sort (
        /*[in]*/ BSTR Criteria ) = 0;
      virtual HRESULT __stdcall get_Status (
        /*[out,retval]*/ long * pl ) = 0;
      virtual HRESULT __stdcall get_State (
        /*[out,retval]*/ long * plObjState ) = 0;
      virtual HRESULT __stdcall raw__xClone (
        /*[out,retval]*/ struct _Recordset * * ppvObject ) = 0;
      virtual HRESULT __stdcall raw_UpdateBatch (
        /*[in]*/ TagENUM AffectEnum AffectRecords ) = 0;
      virtual HRESULT __stdcall raw_CancelBatch (
        /*[in]*/ TagENUM AffectEnum AffectRecords ) = 0;
      virtual HRESULT __stdcall get_CursorLocation (
        /*[out,retval]*/ TagENUM CursorLocationEnum * plCursorLoc ) = 0;
      virtual HRESULT __stdcall put_CursorLocation (
        /*[in]*/ TagENUM CursorLocationEnum plCursorLoc ) = 0;
      virtual HRESULT __stdcall raw_NextRecordset (
        /*[out]*/ VARIANT * RecordsAffected,
        /*[out,retval]*/ struct _Recordset * * ppiRs ) = 0;
      virtual HRESULT __stdcall raw_Supports (
        /*[in]*/ TagENUM CursorOptionEnum CursorOptions,
        /*[out,retval]*/ VARIANT_BOOL * pb ) = 0;
      virtual HRESULT __stdcall get_Collect (
        /*[in]*/ VARIANT Index,
        /*[out,retval]*/ VARIANT * pvar ) = 0;
      virtual HRESULT __stdcall put_Collect (
        /*[in]*/ VARIANT Index,
        /*[in]*/ VARIANT pvar ) = 0;
      virtual HRESULT __stdcall get_MarshalOptions (
        /*[out,retval]*/ TagENUM MarshalOptionsEnum * peMarshal ) = 0;
      virtual HRESULT __stdcall put_MarshalOptions (
        /*[in]*/ TagENUM MarshalOptionsEnum peMarshal ) = 0;
      virtual HRESULT __stdcall raw_Find (
        /*[in]*/ BSTR Criteria,
        /*[in]*/ ADO_LONGPTR SkipRecords,
        /*[in]*/ TagENUM SearchDirectionEnum SearchDirection,
        /*[in]*/ VARIANT Start = vtMissing ) = 0;
};

struct __declspec(uuid("0000054f-0000-0010-8000-00aa006d2ea4"))
Recordset20 : Recordset15
{
    //
    // Property data
    //

    __declspec(property(get=GetDataSource,put=PutRefDataSource))
    IUnknownPtr DataSource;
    __declspec(property(get=GetActiveCommand))
    IDispatchPtr ActiveCommand;
    __declspec(property(get=GetStayInSync,put=PutStayInSync))
    VARIANT_BOOL StayInSync;
    __declspec(property(get=GetDataMember,put=PutDataMember))
    _bstr_t DataMember;

    //
    // Wrapper methods for error-handling
    //

    HRESULT Cancel ( );
    IUnknownPtr GetDataSource ( );
    void PutRefDataSource (
        IUnknown * ppunkDataSource );
    HRESULT _xSave (
        _bstr_t FileName,
        TagENUM PersistFormatEnum PersistFormat );
    IDispatchPtr GetActiveCommand ( );
    void PutStayInSync (
        VARIANT_BOOL pbStayInSync );
    VARIANT_BOOL GetStayInSync ( );
    _bstr_t GetString (
        TagENUM StringFormatEnum StringFormat,
        long NumRows,
        _bstr_t ColumnDelimeter,
        _bstr_t RowDelimeter,
        _bstr_t NullExpr );
    _bstr_t GetDataMember ( );
    void PutDataMember (
        _bstr_t pbstrDataMember );
    TagENUM CompareEnum CompareBookmarks (
        const _variant_t & Bookmark1,
        const _variant_t & Bookmark2 );
    _RecordsetPtr Clone (
        TagENUM LockTypeEnum LockType );
    HRESULT Resync (
        TagENUM AffectEnum AffectRecords,
        TagENUM ResyncEnum ResyncValues );

    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall raw_Cancel ( ) = 0;
      virtual HRESULT __stdcall get_DataSource (
        /*[out,retval]*/ IUnknown * * ppunkDataSource ) = 0;
      virtual HRESULT __stdcall putref_DataSource (
        /*[in]*/ IUnknown * ppunkDataSource ) = 0;
      virtual HRESULT __stdcall raw__xSave (
        /*[in]*/ BSTR FileName,
        /*[in]*/ TagENUM PersistFormatEnum PersistFormat ) = 0;
      virtual HRESULT __stdcall get_ActiveCommand (
        /*[out,retval]*/ IDispatch * * ppCmd ) = 0;
      virtual HRESULT __stdcall put_StayInSync (
        /*[in]*/ VARIANT_BOOL pbStayInSync ) = 0;
      virtual HRESULT __stdcall get_StayInSync (
        /*[out,retval]*/ VARIANT_BOOL * pbStayInSync ) = 0;
      virtual HRESULT __stdcall raw_GetString (
        /*[in]*/ TagENUM StringFormatEnum StringFormat,
        /*[in]*/ long NumRows,
        /*[in]*/ BSTR ColumnDelimeter,
        /*[in]*/ BSTR RowDelimeter,
        /*[in]*/ BSTR NullExpr,
        /*[out,retval]*/ BSTR * pRetString ) = 0;
      virtual HRESULT __stdcall get_DataMember (
        /*[out,retval]*/ BSTR * pbstrDataMember ) = 0;
      virtual HRESULT __stdcall put_DataMember (
        /*[in]*/ BSTR pbstrDataMember ) = 0;
      virtual HRESULT __stdcall raw_CompareBookmarks (
        /*[in]*/ VARIANT Bookmark1,
        /*[in]*/ VARIANT Bookmark2,
        /*[out,retval]*/ TagENUM CompareEnum * pCompare ) = 0;
      virtual HRESULT __stdcall raw_Clone (
        /*[in]*/ TagENUM LockTypeEnum LockType,
        /*[out,retval]*/ struct _Recordset * * ppvObject ) = 0;
      virtual HRESULT __stdcall raw_Resync (
        /*[in]*/ TagENUM AffectEnum AffectRecords,
        /*[in]*/ TagENUM ResyncEnum ResyncValues ) = 0;
};

struct __declspec(uuid("00000555-0000-0010-8000-00aa006d2ea4"))
Recordset21 : Recordset20
{
    //
    // Property data
    //

    __declspec(property(get=GetIndex,put=PutIndex))
    _bstr_t Index;

    //
    // Wrapper methods for error-handling
    //

    HRESULT Seek (
        const _variant_t & KeyValues,
        TagENUM SeekEnum SeekOption );
    void PutIndex (
        _bstr_t pbstrIndex );
    _bstr_t GetIndex ( );

    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall raw_Seek (
        /*[in]*/ VARIANT KeyValues,
        /*[in]*/ TagENUM SeekEnum SeekOption ) = 0;
      virtual HRESULT __stdcall put_Index (
        /*[in]*/ BSTR pbstrIndex ) = 0;
      virtual HRESULT __stdcall get_Index (
        /*[out,retval]*/ BSTR * pbstrIndex ) = 0;
};

struct __declspec(uuid("00000556-0000-0010-8000-00aa006d2ea4"))
_Recordset : Recordset21
{
    //
    // Wrapper methods for error-handling
    //

    HRESULT Save (
        const _variant_t & Destination,
        TagENUM PersistFormatEnum PersistFormat );

    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall raw_Save (
        /*[in]*/ VARIANT Destination,
        /*[in]*/ TagENUM PersistFormatEnum PersistFormat ) = 0;
};

struct __declspec(uuid("00000402-0000-0010-8000-00aa006d2ea4"))
ConnectionEventsVt : IUnknown
{
    //
    // Wrapper methods for error-handling
    //

    HRESULT InfoMessage (
        struct Error * pError,
        TagENUM EventStatusEnum * adStatus,
        struct _Connection * pConnection );
    HRESULT BeginTransComplete (
        long TransactionLevel,
        struct Error * pError,
        TagENUM EventStatusEnum * adStatus,
        struct _Connection * pConnection );
    HRESULT CommitTransComplete (
        struct Error * pError,
        TagENUM EventStatusEnum * adStatus,
        struct _Connection * pConnection );
    HRESULT RollbackTransComplete (
        struct Error * pError,
        TagENUM EventStatusEnum * adStatus,
        struct _Connection * pConnection );
    HRESULT WillExecute (
        BSTR * Source,
        TagENUM CursorTypeEnum * CursorType,
        TagENUM LockTypeEnum * LockType,
        long * Options,
        TagENUM EventStatusEnum * adStatus,
        struct _Command * pCommand,
        struct _Recordset * pRecordset,
        struct _Connection * pConnection );
    HRESULT ExecuteComplete (
        long RecordsAffected,
        struct Error * pError,
        TagENUM EventStatusEnum * adStatus,
        struct _Command * pCommand,
        struct _Recordset * pRecordset,
        struct _Connection * pConnection );
    HRESULT WillConnect (
        BSTR * ConnectionString,
        BSTR * UserID,
        BSTR * Password,
        long * Options,
        TagENUM EventStatusEnum * adStatus,
        struct _Connection * pConnection );
    HRESULT ConnectComplete (
        struct Error * pError,
        TagENUM EventStatusEnum * adStatus,
        struct _Connection * pConnection );
    HRESULT Disconnect (
        TagENUM EventStatusEnum * adStatus,
        struct _Connection * pConnection );

    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall raw_InfoMessage (
        /*[in]*/ struct Error * pError,
        /*[in,out]*/ TagENUM EventStatusEnum * adStatus,
        /*[in]*/ struct _Connection * pConnection ) = 0;
      virtual HRESULT __stdcall raw_BeginTransComplete (
        /*[in]*/ long TransactionLevel,
        /*[in]*/ struct Error * pError,
        /*[in,out]*/ TagENUM EventStatusEnum * adStatus,
        /*[in]*/ struct _Connection * pConnection ) = 0;
      virtual HRESULT __stdcall raw_CommitTransComplete (
        /*[in]*/ struct Error * pError,
        /*[in,out]*/ TagENUM EventStatusEnum * adStatus,
        /*[in]*/ struct _Connection * pConnection ) = 0;
      virtual HRESULT __stdcall raw_RollbackTransComplete (
        /*[in]*/ struct Error * pError,
        /*[in,out]*/ TagENUM EventStatusEnum * adStatus,
        /*[in]*/ struct _Connection * pConnection ) = 0;
      virtual HRESULT __stdcall raw_WillExecute (
        /*[in,out]*/ BSTR * Source,
        /*[in,out]*/ TagENUM CursorTypeEnum * CursorType,
        /*[in,out]*/ TagENUM LockTypeEnum * LockType,
        /*[in,out]*/ long * Options,
        /*[in,out]*/ TagENUM EventStatusEnum * adStatus,
        /*[in]*/ struct _Command * pCommand,
        /*[in]*/ struct _Recordset * pRecordset,
        /*[in]*/ struct _Connection * pConnection ) = 0;
      virtual HRESULT __stdcall raw_ExecuteComplete (
        /*[in]*/ long RecordsAffected,
        /*[in]*/ struct Error * pError,
        /*[in,out]*/ TagENUM EventStatusEnum * adStatus,
        /*[in]*/ struct _Command * pCommand,
        /*[in]*/ struct _Recordset * pRecordset,
        /*[in]*/ struct _Connection * pConnection ) = 0;
      virtual HRESULT __stdcall raw_WillConnect (
        /*[in,out]*/ BSTR * ConnectionString,
        /*[in,out]*/ BSTR * UserID,
        /*[in,out]*/ BSTR * Password,
        /*[in,out]*/ long * Options,
        /*[in,out]*/ TagENUM EventStatusEnum * adStatus,
        /*[in]*/ struct _Connection * pConnection ) = 0;
      virtual HRESULT __stdcall raw_ConnectComplete (
        /*[in]*/ struct Error * pError,
        /*[in,out]*/ TagENUM EventStatusEnum * adStatus,
        /*[in]*/ struct _Connection * pConnection ) = 0;
      virtual HRESULT __stdcall raw_Disconnect (
        /*[in,out]*/ TagENUM EventStatusEnum * adStatus,
        /*[in]*/ struct _Connection * pConnection ) = 0;
};

struct __declspec(uuid("00000403-0000-0010-8000-00aa006d2ea4"))
RecordsetEventsVt : IUnknown
{
    //
    // Wrapper methods for error-handling
    //

    HRESULT WillChangeField (
        long cFields,
        const _variant_t & Fields,
        TagENUM EventStatusEnum * adStatus,
        struct _Recordset * pRecordset );
    HRESULT FieldChangeComplete (
        long cFields,
        const _variant_t & Fields,
        struct Error * pError,
        TagENUM EventStatusEnum * adStatus,
        struct _Recordset * pRecordset );
    HRESULT WillChangeRecord (
        TagENUM EventReasonEnum adReason,
        long cRecords,
        TagENUM EventStatusEnum * adStatus,
        struct _Recordset * pRecordset );
    HRESULT RecordChangeComplete (
        TagENUM EventReasonEnum adReason,
        long cRecords,
        struct Error * pError,
        TagENUM EventStatusEnum * adStatus,
        struct _Recordset * pRecordset );
    HRESULT WillChangeRecordset (
        TagENUM EventReasonEnum adReason,
        TagENUM EventStatusEnum * adStatus,
        struct _Recordset * pRecordset );
    HRESULT RecordsetChangeComplete (
        TagENUM EventReasonEnum adReason,
        struct Error * pError,
        TagENUM EventStatusEnum * adStatus,
        struct _Recordset * pRecordset );
    HRESULT WillMove (
        TagENUM EventReasonEnum adReason,
        TagENUM EventStatusEnum * adStatus,
        struct _Recordset * pRecordset );
    HRESULT MoveComplete (
        TagENUM EventReasonEnum adReason,
        struct Error * pError,
        TagENUM EventStatusEnum * adStatus,
        struct _Recordset * pRecordset );
    HRESULT EndOfRecordset (
        VARIANT_BOOL * fMoreData,
        TagENUM EventStatusEnum * adStatus,
        struct _Recordset * pRecordset );
    HRESULT FetchProgress (
        long Progress,
        long MaxProgress,
        TagENUM EventStatusEnum * adStatus,
        struct _Recordset * pRecordset );
    HRESULT FetchComplete (
        struct Error * pError,
        TagENUM EventStatusEnum * adStatus,
        struct _Recordset * pRecordset );

    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall raw_WillChangeField (
        /*[in]*/ long cFields,
        /*[in]*/ VARIANT Fields,
        /*[in,out]*/ TagENUM EventStatusEnum * adStatus,
        /*[in]*/ struct _Recordset * pRecordset ) = 0;
      virtual HRESULT __stdcall raw_FieldChangeComplete (
        /*[in]*/ long cFields,
        /*[in]*/ VARIANT Fields,
        /*[in]*/ struct Error * pError,
        /*[in,out]*/ TagENUM EventStatusEnum * adStatus,
        /*[in]*/ struct _Recordset * pRecordset ) = 0;
      virtual HRESULT __stdcall raw_WillChangeRecord (
        /*[in]*/ TagENUM EventReasonEnum adReason,
        /*[in]*/ long cRecords,
        /*[in,out]*/ TagENUM EventStatusEnum * adStatus,
        /*[in]*/ struct _Recordset * pRecordset ) = 0;
      virtual HRESULT __stdcall raw_RecordChangeComplete (
        /*[in]*/ TagENUM EventReasonEnum adReason,
        /*[in]*/ long cRecords,
        /*[in]*/ struct Error * pError,
        /*[in,out]*/ TagENUM EventStatusEnum * adStatus,
        /*[in]*/ struct _Recordset * pRecordset ) = 0;
      virtual HRESULT __stdcall raw_WillChangeRecordset (
        /*[in]*/ TagENUM EventReasonEnum adReason,
        /*[in,out]*/ TagENUM EventStatusEnum * adStatus,
        /*[in]*/ struct _Recordset * pRecordset ) = 0;
      virtual HRESULT __stdcall raw_RecordsetChangeComplete (
        /*[in]*/ TagENUM EventReasonEnum adReason,
        /*[in]*/ struct Error * pError,
        /*[in,out]*/ TagENUM EventStatusEnum * adStatus,
        /*[in]*/ struct _Recordset * pRecordset ) = 0;
      virtual HRESULT __stdcall raw_WillMove (
        /*[in]*/ TagENUM EventReasonEnum adReason,
        /*[in,out]*/ TagENUM EventStatusEnum * adStatus,
        /*[in]*/ struct _Recordset * pRecordset ) = 0;
      virtual HRESULT __stdcall raw_MoveComplete (
        /*[in]*/ TagENUM EventReasonEnum adReason,
        /*[in]*/ struct Error * pError,
        /*[in,out]*/ TagENUM EventStatusEnum * adStatus,
        /*[in]*/ struct _Recordset * pRecordset ) = 0;
      virtual HRESULT __stdcall raw_EndOfRecordset (
        /*[in,out]*/ VARIANT_BOOL * fMoreData,
        /*[in,out]*/ TagENUM EventStatusEnum * adStatus,
        /*[in]*/ struct _Recordset * pRecordset ) = 0;
      virtual HRESULT __stdcall raw_FetchProgress (
        /*[in]*/ long Progress,
        /*[in]*/ long MaxProgress,
        /*[in,out]*/ TagENUM EventStatusEnum * adStatus,
        /*[in]*/ struct _Recordset * pRecordset ) = 0;
      virtual HRESULT __stdcall raw_FetchComplete (
        /*[in]*/ struct Error * pError,
        /*[in,out]*/ TagENUM EventStatusEnum * adStatus,
        /*[in]*/ struct _Recordset * pRecordset ) = 0;
};

struct __declspec(uuid("00000562-0000-0010-8000-00aa006d2ea4"))
_Record : _ADO
{
    //
    // Property data
    //

    __declspec(property(get=GetFields))
    FieldsPtr Fields;
    __declspec(property(get=GetState))
    TagENUM ObjectStateEnum State;
    __declspec(property(get=GetMode,put=PutMode))
    TagENUM ConnectModeEnum Mode;
    __declspec(property(get=GetParentURL))
    _bstr_t ParentURL;
    __declspec(property(get=GetRecordType))
    TagENUM RecordTypeEnum RecordType;

    //
    // Wrapper methods for error-handling
    //

    _variant_t GetActiveConnection ( );
    void PutActiveConnection (
        _bstr_t pvar );
    void PutRefActiveConnection (
        struct _Connection * pvar );
    TagENUM ObjectStateEnum GetState ( );
    _variant_t GetSource ( );
    void PutSource (
        _bstr_t pvar );
    void PutRefSource (
        IDispatch * pvar );
    TagENUM ConnectModeEnum GetMode ( );
    void PutMode (
        TagENUM ConnectModeEnum pMode );
    _bstr_t GetParentURL ( );
    _bstr_t MoveRecord (
        _bstr_t Source,
        _bstr_t Destination,
        _bstr_t UserName,
        _bstr_t Password,
        TagENUM MoveRecordOptionsEnum Options,
        VARIANT_BOOL Async );
    _bstr_t CopyRecord (
        _bstr_t Source,
        _bstr_t Destination,
        _bstr_t UserName,
        _bstr_t Password,
        TagENUM CopyRecordOptionsEnum Options,
        VARIANT_BOOL Async );
    HRESULT DeleteRecord (
        _bstr_t Source,
        VARIANT_BOOL Async );
    HRESULT Open (
        const _variant_t & Source,
        const _variant_t & ActiveConnection,
        TagENUM ConnectModeEnum Mode,
        TagENUM RecordCreateOptionsEnum CreateOptions,
        TagENUM RecordOpenOptionsEnum Options,
        _bstr_t UserName,
        _bstr_t Password );
    HRESULT Close ( );
    FieldsPtr GetFields ( );
    TagENUM RecordTypeEnum GetRecordType ( );
    _RecordsetPtr GetChildren ( );
    HRESULT Cancel ( );

    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_ActiveConnection (
        /*[out,retval]*/ VARIANT * pvar ) = 0;
      virtual HRESULT __stdcall put_ActiveConnection (
        /*[in]*/ BSTR pvar ) = 0;
      virtual HRESULT __stdcall putref_ActiveConnection (
        /*[in]*/ struct _Connection * pvar ) = 0;
      virtual HRESULT __stdcall get_State (
        /*[out,retval]*/ TagENUM ObjectStateEnum * pState ) = 0;
      virtual HRESULT __stdcall get_Source (
        /*[out,retval]*/ VARIANT * pvar ) = 0;
      virtual HRESULT __stdcall put_Source (
        /*[in]*/ BSTR pvar ) = 0;
      virtual HRESULT __stdcall putref_Source (
        /*[in]*/ IDispatch * pvar ) = 0;
      virtual HRESULT __stdcall get_Mode (
        /*[out,retval]*/ TagENUM ConnectModeEnum * pMode ) = 0;
      virtual HRESULT __stdcall put_Mode (
        /*[in]*/ TagENUM ConnectModeEnum pMode ) = 0;
      virtual HRESULT __stdcall get_ParentURL (
        /*[out,retval]*/ BSTR * pbstrParentURL ) = 0;
      virtual HRESULT __stdcall raw_MoveRecord (
        /*[in]*/ BSTR Source,
        /*[in]*/ BSTR Destination,
        /*[in]*/ BSTR UserName,
        /*[in]*/ BSTR Password,
        /*[in]*/ TagENUM MoveRecordOptionsEnum Options,
        /*[in]*/ VARIANT_BOOL Async,
        /*[out,retval]*/ BSTR * pbstrNewURL ) = 0;
      virtual HRESULT __stdcall raw_CopyRecord (
        /*[in]*/ BSTR Source,
        /*[in]*/ BSTR Destination,
        /*[in]*/ BSTR UserName,
        /*[in]*/ BSTR Password,
        /*[in]*/ TagENUM CopyRecordOptionsEnum Options,
        /*[in]*/ VARIANT_BOOL Async,
        /*[out,retval]*/ BSTR * pbstrNewURL ) = 0;
      virtual HRESULT __stdcall raw_DeleteRecord (
        /*[in]*/ BSTR Source,
        /*[in]*/ VARIANT_BOOL Async ) = 0;
      virtual HRESULT __stdcall raw_Open (
        /*[in]*/ VARIANT Source,
        /*[in]*/ VARIANT ActiveConnection,
        /*[in]*/ TagENUM ConnectModeEnum Mode,
        /*[in]*/ TagENUM RecordCreateOptionsEnum CreateOptions,
        /*[in]*/ TagENUM RecordOpenOptionsEnum Options,
        /*[in]*/ BSTR UserName,
        /*[in]*/ BSTR Password ) = 0;
      virtual HRESULT __stdcall raw_Close ( ) = 0;
      virtual HRESULT __stdcall get_Fields (
        /*[out,retval]*/ struct Fields * * ppFlds ) = 0;
      virtual HRESULT __stdcall get_RecordType (
        /*[out,retval]*/ TagENUM RecordTypeEnum * ptype ) = 0;
      virtual HRESULT __stdcall raw_GetChildren (
        /*[out,retval]*/ struct _Recordset * * pprset ) = 0;
      virtual HRESULT __stdcall raw_Cancel ( ) = 0;
};

//
// Wrapper method implementations
//

} // namespace ADO

#pragma pack(pop)
