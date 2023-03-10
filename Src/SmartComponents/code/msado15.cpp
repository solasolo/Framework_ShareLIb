// Created by Microsoft (R) C/C++ Compiler Version 15.00.21022.08 (d5824154).
//
// D:\DOCUME~1\ADMINI~1\LOCALS~1\Temp\msado15.tli
//
// Wrapper implementations for Win32 type library 2A75196C-D9EB-4129-B803-931327F72D5C
// compiler-generated file created 05/07/09 at 11:19:06 - DO NOT EDIT!

#include "msado15.h"

namespace ADO {

	//
	// interface _Collection wrapper method implementations
	//

	long _Collection::GetCount ( ) {
		long _result = 0;
		HRESULT _hr = get_Count(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(_Collection));
		return _result;
	}

	IUnknownPtr _Collection::_NewEnum ( ) {
		IUnknown * _result = 0;
		HRESULT _hr = raw__NewEnum(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(_Collection));
		return IUnknownPtr(_result, false);
	}

	HRESULT _Collection::Refresh ( ) {
		HRESULT _hr = raw_Refresh();
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(_Collection));
		return _hr;
	}

	//
	// interface _DynaCollection wrapper method implementations
	//

	HRESULT _DynaCollection::Append ( IDispatch * Object ) {
		HRESULT _hr = raw_Append(Object);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(_DynaCollection));
		return _hr;
	}

	HRESULT _DynaCollection::Delete ( const _variant_t & Index ) {
		HRESULT _hr = raw_Delete(Index);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(_DynaCollection));
		return _hr;
	}

	//
	// interface Property wrapper method implementations
	//

	_variant_t Property::GetValue ( ) {
		VARIANT _result;
		VariantInit(&_result);
		HRESULT _hr = get_Value(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(Property));
		return _variant_t(_result, false);
	}

	void Property::PutValue ( const _variant_t & pval ) {
		HRESULT _hr = put_Value(pval);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(Property));
	}

	_bstr_t Property::GetName ( ) {
		BSTR _result = 0;
		HRESULT _hr = get_Name(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(Property));
		return _bstr_t(_result, false);
	}

	enum DataTypeEnum Property::GetType ( ) {
		enum DataTypeEnum _result;
		HRESULT _hr = get_Type(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(this));
		return _result;
	}

	long Property::GetAttributes ( ) {
		long _result = 0;
		HRESULT _hr = get_Attributes(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(Property));
		return _result;
	}

	void Property::PutAttributes ( long plAttributes ) {
		HRESULT _hr = put_Attributes(plAttributes);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(Property));
	}

	//
	// interface Properties wrapper method implementations
	//

	PropertyPtr Properties::GetItem ( const _variant_t & Index ) {
		struct Property * _result = 0;
		HRESULT _hr = get_Item(Index, &_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(Properties));
		return PropertyPtr(_result, false);
	}

	//
	// interface _ADO wrapper method implementations
	//

	PropertiesPtr _ADO::GetProperties ( ) {
		struct Properties * _result = 0;
		HRESULT _hr = get_Properties(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(_ADO));
		return PropertiesPtr(_result, false);
	}

	//
	// interface Error wrapper method implementations
	//

	long Error::GetNumber ( ) {
		long _result = 0;
		HRESULT _hr = get_Number(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(Error));
		return _result;
	}

	_bstr_t Error::GetSource ( ) {
		BSTR _result = 0;
		HRESULT _hr = get_Source(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(Error));
		return _bstr_t(_result, false);
	}

	_bstr_t Error::GetDescription ( ) {
		BSTR _result = 0;
		HRESULT _hr = get_Description(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(Error));
		return _bstr_t(_result, false);
	}

	_bstr_t Error::GetHelpFile ( ) {
		BSTR _result = 0;
		HRESULT _hr = get_HelpFile(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(Error));
		return _bstr_t(_result, false);
	}

	long Error::GetHelpContext ( ) {
		long _result = 0;
		HRESULT _hr = get_HelpContext(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(Error));
		return _result;
	}

	_bstr_t Error::GetSQLState ( ) {
		BSTR _result = 0;
		HRESULT _hr = get_SQLState(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(Error));
		return _bstr_t(_result, false);
	}

	long Error::GetNativeError ( ) {
		long _result = 0;
		HRESULT _hr = get_NativeError(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(Error));
		return _result;
	}

	//
	// interface Errors wrapper method implementations
	//

	ErrorPtr Errors::GetItem ( const _variant_t & Index ) {
		struct Error * _result = 0;
		HRESULT _hr = get_Item(Index, &_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(Errors));
		return ErrorPtr(_result, false);
	}

	HRESULT Errors::Clear ( ) {
		HRESULT _hr = raw_Clear();
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(Errors));
		return _hr;
	}

	//
	// interface Field20 wrapper method implementations
	//

	ADO_LONGPTR Field20::GetActualSize ( ) {
		ADO_LONGPTR _result;
		HRESULT _hr = get_ActualSize(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(Field20));
		return _result;
	}

	long Field20::GetAttributes ( ) {
		long _result = 0;
		HRESULT _hr = get_Attributes(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(Field20));
		return _result;
	}

	ADO_LONGPTR Field20::GetDefinedSize ( ) {
		ADO_LONGPTR _result;
		HRESULT _hr = get_DefinedSize(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(Field20));
		return _result;
	}

	_bstr_t Field20::GetName ( ) {
		BSTR _result = 0;
		HRESULT _hr = get_Name(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(Field20));
		return _bstr_t(_result, false);
	}

	enum DataTypeEnum Field20::GetType ( ) {
		enum DataTypeEnum _result;
		HRESULT _hr = get_Type(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(this));
		return _result;
	}

	_variant_t Field20::GetValue ( ) {
		VARIANT _result;
		VariantInit(&_result);
		HRESULT _hr = get_Value(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(Field20));
		return _variant_t(_result, false);
	}

	void Field20::PutValue ( const _variant_t & pvar ) {
		HRESULT _hr = put_Value(pvar);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(Field20));
	}

	unsigned char Field20::GetPrecision ( ) {
		unsigned char _result = 0;
		HRESULT _hr = get_Precision(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(this));
		return _result;
	}

	unsigned char Field20::GetNumericScale ( ) {
		unsigned char _result = 0;
		HRESULT _hr = get_NumericScale(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(this));
		return _result;
	}

	HRESULT Field20::AppendChunk ( const _variant_t & Data ) {
		HRESULT _hr = raw_AppendChunk(Data);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(Field20));
		return _hr;
	}

	_variant_t Field20::GetChunk ( long Length ) {
		VARIANT _result;
		VariantInit(&_result);
		HRESULT _hr = raw_GetChunk(Length, &_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(Field20));
		return _variant_t(_result, false);
	}

	_variant_t Field20::GetOriginalValue ( ) {
		VARIANT _result;
		VariantInit(&_result);
		HRESULT _hr = get_OriginalValue(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(Field20));
		return _variant_t(_result, false);
	}

	_variant_t Field20::GetUnderlyingValue ( ) {
		VARIANT _result;
		VariantInit(&_result);
		HRESULT _hr = get_UnderlyingValue(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(Field20));
		return _variant_t(_result, false);
	}

	IUnknownPtr Field20::GetDataFormat ( ) {
		IUnknown * _result = 0;
		HRESULT _hr = get_DataFormat(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(Field20));
		return IUnknownPtr(_result, false);
	}

	void Field20::PutRefDataFormat ( IUnknown * ppiDF ) {
		HRESULT _hr = putref_DataFormat(ppiDF);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(Field20));
	}

	void Field20::PutPrecision ( unsigned char pbPrecision ) {
		HRESULT _hr = put_Precision(pbPrecision);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(Field20));
	}

	void Field20::PutNumericScale ( unsigned char pbNumericScale ) {
		HRESULT _hr = put_NumericScale(pbNumericScale);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(Field20));
	}

	void Field20::PutType ( enum DataTypeEnum pDataType ) {
		HRESULT _hr = put_Type(pDataType);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(Field20));
	}

	void Field20::PutDefinedSize ( ADO_LONGPTR pl ) {
		HRESULT _hr = put_DefinedSize(pl);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(Field20));
	}

	void Field20::PutAttributes ( long pl ) {
		HRESULT _hr = put_Attributes(pl);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(Field20));
	}

	//
	// interface Field wrapper method implementations
	//

	long Field::GetStatus ( ) {
		long _result = 0;
		HRESULT _hr = get_Status(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(Field));
		return _result;
	}

	//
	// interface Fields15 wrapper method implementations
	//

	FieldPtr Fields15::GetItem ( const _variant_t & Index ) {
		struct Field * _result = 0;
		HRESULT _hr = get_Item(Index, &_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(Fields15));
		return FieldPtr(_result, false);
	}

	//
	// interface Fields20 wrapper method implementations
	//

	HRESULT Fields20::_Append ( _bstr_t Name, enum DataTypeEnum Type, ADO_LONGPTR DefinedSize, enum FieldAttributeEnum Attrib ) {
		HRESULT _hr = raw__Append(Name, Type, DefinedSize, Attrib);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(Fields20));
		return _hr;
	}

	HRESULT Fields20::Delete ( const _variant_t & Index ) {
		HRESULT _hr = raw_Delete(Index);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(Fields20));
		return _hr;
	}

	//
	// interface Fields wrapper method implementations
	//

	HRESULT Fields::Append ( _bstr_t Name, enum DataTypeEnum Type, ADO_LONGPTR DefinedSize, enum FieldAttributeEnum Attrib, const _variant_t & FieldValue ) {
		HRESULT _hr = raw_Append(Name, Type, DefinedSize, Attrib, FieldValue);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(Fields));
		return _hr;
	}

	HRESULT Fields::Update ( ) {
		HRESULT _hr = raw_Update();
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(Fields));
		return _hr;
	}

	HRESULT Fields::Resync ( enum ResyncEnum ResyncValues ) {
		HRESULT _hr = raw_Resync(ResyncValues);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(Fields));
		return _hr;
	}

	HRESULT Fields::CancelUpdate ( ) {
		HRESULT _hr = raw_CancelUpdate();
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(Fields));
		return _hr;
	}

	//
	// interface _Parameter wrapper method implementations
	//

	_bstr_t _Parameter::GetName ( ) {
		BSTR _result = 0;
		HRESULT _hr = get_Name(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(_Parameter));
		return _bstr_t(_result, false);
	}

	void _Parameter::PutName ( _bstr_t pbstr ) {
		HRESULT _hr = put_Name(pbstr);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(_Parameter));
	}

	_variant_t _Parameter::GetValue ( ) {
		VARIANT _result;
		VariantInit(&_result);
		HRESULT _hr = get_Value(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(_Parameter));
		return _variant_t(_result, false);
	}

	void _Parameter::PutValue ( const _variant_t & pvar ) {
		HRESULT _hr = put_Value(pvar);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(_Parameter));
	}

	enum DataTypeEnum _Parameter::GetType ( ) {
		enum DataTypeEnum _result;
		HRESULT _hr = get_Type(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(this));
		return _result;
	}

	void _Parameter::PutType ( enum DataTypeEnum psDataType ) {
		HRESULT _hr = put_Type(psDataType);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(_Parameter));
	}

	void _Parameter::PutDirection ( enum ParameterDirectionEnum plParmDirection ) {
		HRESULT _hr = put_Direction(plParmDirection);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(_Parameter));
	}

	enum ParameterDirectionEnum _Parameter::GetDirection ( ) {
		enum ParameterDirectionEnum _result;
		HRESULT _hr = get_Direction(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(this));
		return _result;
	}

	void _Parameter::PutPrecision ( unsigned char pbPrecision ) {
		HRESULT _hr = put_Precision(pbPrecision);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(_Parameter));
	}

	unsigned char _Parameter::GetPrecision ( ) {
		unsigned char _result = 0;
		HRESULT _hr = get_Precision(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(this));
		return _result;
	}

	void _Parameter::PutNumericScale ( unsigned char pbScale ) {
		HRESULT _hr = put_NumericScale(pbScale);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(_Parameter));
	}

	unsigned char _Parameter::GetNumericScale ( ) {
		unsigned char _result = 0;
		HRESULT _hr = get_NumericScale(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(this));
		return _result;
	}

	void _Parameter::PutSize ( ADO_LONGPTR pl ) {
		HRESULT _hr = put_Size(pl);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(_Parameter));
	}

	ADO_LONGPTR _Parameter::GetSize ( ) {
		ADO_LONGPTR _result;
		HRESULT _hr = get_Size(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(_Parameter));
		return _result;
	}

	HRESULT _Parameter::AppendChunk ( const _variant_t & Val ) {
		HRESULT _hr = raw_AppendChunk(Val);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(_Parameter));
		return _hr;
	}

	long _Parameter::GetAttributes ( ) {
		long _result = 0;
		HRESULT _hr = get_Attributes(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(_Parameter));
		return _result;
	}

	void _Parameter::PutAttributes ( long plParmAttribs ) {
		HRESULT _hr = put_Attributes(plParmAttribs);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(_Parameter));
	}

	//
	// interface Parameters wrapper method implementations
	//

	_ParameterPtr Parameters::GetItem ( const _variant_t & Index ) {
		struct _Parameter * _result = 0;
		HRESULT _hr = get_Item(Index, &_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(Parameters));
		return _ParameterPtr(_result, false);
	}

	//
	// dispinterface ConnectionEvents wrapper method implementations
	//

	HRESULT ConnectionEvents::InfoMessage ( struct Error * pError, enum EventStatusEnum * adStatus, struct _Connection * pConnection ) {
		HRESULT _result = 0;
		_com_dispatch_method(this, 0x0, DISPATCH_METHOD, VT_ERROR, (void*)&_result, 
			L"\x0009\x4003\x0009", pError, adStatus, pConnection);
		return _result;
	}

	HRESULT ConnectionEvents::BeginTransComplete ( long TransactionLevel, struct Error * pError, enum EventStatusEnum * adStatus, struct _Connection * pConnection ) {
		HRESULT _result = 0;
		_com_dispatch_method(this, 0x1, DISPATCH_METHOD, VT_ERROR, (void*)&_result, 
			L"\x0003\x0009\x4003\x0009", TransactionLevel, pError, adStatus, pConnection);
		return _result;
	}

	HRESULT ConnectionEvents::CommitTransComplete ( struct Error * pError, enum EventStatusEnum * adStatus, struct _Connection * pConnection ) {
		HRESULT _result = 0;
		_com_dispatch_method(this, 0x3, DISPATCH_METHOD, VT_ERROR, (void*)&_result, 
			L"\x0009\x4003\x0009", pError, adStatus, pConnection);
		return _result;
	}

	HRESULT ConnectionEvents::RollbackTransComplete ( struct Error * pError, enum EventStatusEnum * adStatus, struct _Connection * pConnection ) {
		HRESULT _result = 0;
		_com_dispatch_method(this, 0x2, DISPATCH_METHOD, VT_ERROR, (void*)&_result, 
			L"\x0009\x4003\x0009", pError, adStatus, pConnection);
		return _result;
	}

	HRESULT ConnectionEvents::WillExecute ( BSTR * Source, enum CursorTypeEnum * CursorType, enum LockTypeEnum * LockType, long * Options, enum EventStatusEnum * adStatus, struct _Command * pCommand, struct _Recordset * pRecordset, struct _Connection * pConnection ) {
		HRESULT _result = 0;
		_com_dispatch_method(this, 0x4, DISPATCH_METHOD, VT_ERROR, (void*)&_result, 
			L"\x4008\x4003\x4003\x4003\x4003\x0009\x0009\x0009", Source, CursorType, LockType, Options, adStatus, pCommand, pRecordset, pConnection);
		return _result;
	}

	HRESULT ConnectionEvents::ExecuteComplete ( long RecordsAffected, struct Error * pError, enum EventStatusEnum * adStatus, struct _Command * pCommand, struct _Recordset * pRecordset, struct _Connection * pConnection ) {
		HRESULT _result = 0;
		_com_dispatch_method(this, 0x5, DISPATCH_METHOD, VT_ERROR, (void*)&_result, 
			L"\x0003\x0009\x4003\x0009\x0009\x0009", RecordsAffected, pError, adStatus, pCommand, pRecordset, pConnection);
		return _result;
	}

	HRESULT ConnectionEvents::WillConnect ( BSTR * ConnectionString, BSTR * UserID, BSTR * Password, long * Options, enum EventStatusEnum * adStatus, struct _Connection * pConnection ) {
		HRESULT _result = 0;
		_com_dispatch_method(this, 0x6, DISPATCH_METHOD, VT_ERROR, (void*)&_result, 
			L"\x4008\x4008\x4008\x4003\x4003\x0009", ConnectionString, UserID, Password, Options, adStatus, pConnection);
		return _result;
	}

	HRESULT ConnectionEvents::ConnectComplete ( struct Error * pError, enum EventStatusEnum * adStatus, struct _Connection * pConnection ) {
		HRESULT _result = 0;
		_com_dispatch_method(this, 0x7, DISPATCH_METHOD, VT_ERROR, (void*)&_result, 
			L"\x0009\x4003\x0009", pError, adStatus, pConnection);
		return _result;
	}

	HRESULT ConnectionEvents::Disconnect ( enum EventStatusEnum * adStatus, struct _Connection * pConnection ) {
		HRESULT _result = 0;
		_com_dispatch_method(this, 0x8, DISPATCH_METHOD, VT_ERROR, (void*)&_result, 
			L"\x4003\x0009", adStatus, pConnection);
		return _result;
	}

	//
	// dispinterface RecordsetEvents wrapper method implementations
	//

	HRESULT RecordsetEvents::WillChangeField ( long cFields, const _variant_t & Fields, enum EventStatusEnum * adStatus, struct _Recordset * pRecordset ) {
		HRESULT _result = 0;
		_com_dispatch_method(this, 0x9, DISPATCH_METHOD, VT_ERROR, (void*)&_result, 
			L"\x0003\x000c\x4003\x0009", cFields, &Fields, adStatus, pRecordset);
		return _result;
	}

	HRESULT RecordsetEvents::FieldChangeComplete ( long cFields, const _variant_t & Fields, struct Error * pError, enum EventStatusEnum * adStatus, struct _Recordset * pRecordset ) {
		HRESULT _result = 0;
		_com_dispatch_method(this, 0xa, DISPATCH_METHOD, VT_ERROR, (void*)&_result, 
			L"\x0003\x000c\x0009\x4003\x0009", cFields, &Fields, pError, adStatus, pRecordset);
		return _result;
	}

	HRESULT RecordsetEvents::WillChangeRecord ( enum EventReasonEnum adReason, long cRecords, enum EventStatusEnum * adStatus, struct _Recordset * pRecordset ) {
		HRESULT _result = 0;
		_com_dispatch_method(this, 0xb, DISPATCH_METHOD, VT_ERROR, (void*)&_result, 
			L"\x0003\x0003\x4003\x0009", adReason, cRecords, adStatus, pRecordset);
		return _result;
	}

	HRESULT RecordsetEvents::RecordChangeComplete ( enum EventReasonEnum adReason, long cRecords, struct Error * pError, enum EventStatusEnum * adStatus, struct _Recordset * pRecordset ) {
		HRESULT _result = 0;
		_com_dispatch_method(this, 0xc, DISPATCH_METHOD, VT_ERROR, (void*)&_result, 
			L"\x0003\x0003\x0009\x4003\x0009", adReason, cRecords, pError, adStatus, pRecordset);
		return _result;
	}

	HRESULT RecordsetEvents::WillChangeRecordset ( enum EventReasonEnum adReason, enum EventStatusEnum * adStatus, struct _Recordset * pRecordset ) {
		HRESULT _result = 0;
		_com_dispatch_method(this, 0xd, DISPATCH_METHOD, VT_ERROR, (void*)&_result, 
			L"\x0003\x4003\x0009", adReason, adStatus, pRecordset);
		return _result;
	}

	HRESULT RecordsetEvents::RecordsetChangeComplete ( enum EventReasonEnum adReason, struct Error * pError, enum EventStatusEnum * adStatus, struct _Recordset * pRecordset ) {
		HRESULT _result = 0;
		_com_dispatch_method(this, 0xe, DISPATCH_METHOD, VT_ERROR, (void*)&_result, 
			L"\x0003\x0009\x4003\x0009", adReason, pError, adStatus, pRecordset);
		return _result;
	}

	HRESULT RecordsetEvents::WillMove ( enum EventReasonEnum adReason, enum EventStatusEnum * adStatus, struct _Recordset * pRecordset ) {
		HRESULT _result = 0;
		_com_dispatch_method(this, 0xf, DISPATCH_METHOD, VT_ERROR, (void*)&_result, 
			L"\x0003\x4003\x0009", adReason, adStatus, pRecordset);
		return _result;
	}

	HRESULT RecordsetEvents::MoveComplete ( enum EventReasonEnum adReason, struct Error * pError, enum EventStatusEnum * adStatus, struct _Recordset * pRecordset ) {
		HRESULT _result = 0;
		_com_dispatch_method(this, 0x10, DISPATCH_METHOD, VT_ERROR, (void*)&_result, 
			L"\x0003\x0009\x4003\x0009", adReason, pError, adStatus, pRecordset);
		return _result;
	}

	HRESULT RecordsetEvents::EndOfRecordset ( VARIANT_BOOL * fMoreData, enum EventStatusEnum * adStatus, struct _Recordset * pRecordset ) {
		HRESULT _result = 0;
		_com_dispatch_method(this, 0x11, DISPATCH_METHOD, VT_ERROR, (void*)&_result, 
			L"\x400b\x4003\x0009", fMoreData, adStatus, pRecordset);
		return _result;
	}

	HRESULT RecordsetEvents::FetchProgress ( long Progress, long MaxProgress, enum EventStatusEnum * adStatus, struct _Recordset * pRecordset ) {
		HRESULT _result = 0;
		_com_dispatch_method(this, 0x12, DISPATCH_METHOD, VT_ERROR, (void*)&_result, 
			L"\x0003\x0003\x4003\x0009", Progress, MaxProgress, adStatus, pRecordset);
		return _result;
	}

	HRESULT RecordsetEvents::FetchComplete ( struct Error * pError, enum EventStatusEnum * adStatus, struct _Recordset * pRecordset ) {
		HRESULT _result = 0;
		_com_dispatch_method(this, 0x13, DISPATCH_METHOD, VT_ERROR, (void*)&_result, 
			L"\x0009\x4003\x0009", pError, adStatus, pRecordset);
		return _result;
	}

	//
	// interface ADOConnectionConstruction15 wrapper method implementations
	//

	IUnknownPtr ADOConnectionConstruction15::GetDSO ( ) {
		IUnknown * _result = 0;
		HRESULT _hr = get_DSO(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(ADOConnectionConstruction15));
		return IUnknownPtr(_result, false);
	}

	IUnknownPtr ADOConnectionConstruction15::GetSession ( ) {
		IUnknown * _result = 0;
		HRESULT _hr = get_Session(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(ADOConnectionConstruction15));
		return IUnknownPtr(_result, false);
	}

	HRESULT ADOConnectionConstruction15::WrapDSOandSession ( IUnknown * pDSO, IUnknown * pSession ) {
		HRESULT _hr = raw_WrapDSOandSession(pDSO, pSession);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(ADOConnectionConstruction15));
		return _hr;
	}

	//
	// interface _Stream wrapper method implementations
	//

	ADO_LONGPTR _Stream::GetSize ( ) {
		ADO_LONGPTR _result;
		HRESULT _hr = get_Size(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(_Stream));
		return _result;
	}

	VARIANT_BOOL _Stream::GetEOS ( ) {
		VARIANT_BOOL _result = 0;
		HRESULT _hr = get_EOS(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(_Stream));
		return _result;
	}

	ADO_LONGPTR _Stream::GetPosition ( ) {
		ADO_LONGPTR _result;
		HRESULT _hr = get_Position(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(_Stream));
		return _result;
	}

	void _Stream::PutPosition ( ADO_LONGPTR pPos ) {
		HRESULT _hr = put_Position(pPos);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(_Stream));
	}

	enum StreamTypeEnum _Stream::GetType ( ) {
		enum StreamTypeEnum _result;
		HRESULT _hr = get_Type(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(this));
		return _result;
	}

	void _Stream::PutType ( enum StreamTypeEnum ptype ) {
		HRESULT _hr = put_Type(ptype);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(_Stream));
	}

	enum LineSeparatorEnum _Stream::GetLineSeparator ( ) {
		enum LineSeparatorEnum _result;
		HRESULT _hr = get_LineSeparator(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(this));
		return _result;
	}

	void _Stream::PutLineSeparator ( enum LineSeparatorEnum pLS ) {
		HRESULT _hr = put_LineSeparator(pLS);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(_Stream));
	}

	enum ObjectStateEnum _Stream::GetState ( ) {
		enum ObjectStateEnum _result;
		HRESULT _hr = get_State(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(this));
		return _result;
	}

	enum ConnectModeEnum _Stream::GetMode ( ) {
		enum ConnectModeEnum _result;
		HRESULT _hr = get_Mode(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(this));
		return _result;
	}

	void _Stream::PutMode ( enum ConnectModeEnum pMode ) {
		HRESULT _hr = put_Mode(pMode);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(_Stream));
	}

	_bstr_t _Stream::GetCharset ( ) {
		BSTR _result = 0;
		HRESULT _hr = get_Charset(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(_Stream));
		return _bstr_t(_result, false);
	}

	void _Stream::PutCharset ( _bstr_t pbstrCharset ) {
		HRESULT _hr = put_Charset(pbstrCharset);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(_Stream));
	}

	_variant_t _Stream::Read ( long NumBytes ) {
		VARIANT _result;
		VariantInit(&_result);
		HRESULT _hr = raw_Read(NumBytes, &_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(_Stream));
		return _variant_t(_result, false);
	}

	HRESULT _Stream::Open ( const _variant_t & Source, enum ConnectModeEnum Mode, enum StreamOpenOptionsEnum Options, _bstr_t UserName, _bstr_t Password ) {
		HRESULT _hr = raw_Open(Source, Mode, Options, UserName, Password);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(_Stream));
		return _hr;
	}

	HRESULT _Stream::Close ( ) {
		HRESULT _hr = raw_Close();
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(_Stream));
		return _hr;
	}

	HRESULT _Stream::SkipLine ( ) {
		HRESULT _hr = raw_SkipLine();
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(_Stream));
		return _hr;
	}

	HRESULT _Stream::Write ( const _variant_t & Buffer ) {
		HRESULT _hr = raw_Write(Buffer);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(_Stream));
		return _hr;
	}

	HRESULT _Stream::SetEOS ( ) {
		HRESULT _hr = raw_SetEOS();
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(_Stream));
		return _hr;
	}

	HRESULT _Stream::CopyTo ( struct _Stream * DestStream, ADO_LONGPTR CharNumber ) {
		HRESULT _hr = raw_CopyTo(DestStream, CharNumber);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(_Stream));
		return _hr;
	}

	HRESULT _Stream::Flush ( ) {
		HRESULT _hr = raw_Flush();
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(_Stream));
		return _hr;
	}

	HRESULT _Stream::SaveToFile ( _bstr_t FileName, enum SaveOptionsEnum Options ) {
		HRESULT _hr = raw_SaveToFile(FileName, Options);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(_Stream));
		return _hr;
	}

	HRESULT _Stream::LoadFromFile ( _bstr_t FileName ) {
		HRESULT _hr = raw_LoadFromFile(FileName);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(_Stream));
		return _hr;
	}

	_bstr_t _Stream::ReadText ( long NumChars ) {
		BSTR _result = 0;
		HRESULT _hr = raw_ReadText(NumChars, &_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(_Stream));
		return _bstr_t(_result, false);
	}

	HRESULT _Stream::WriteText ( _bstr_t Data, enum StreamWriteEnum Options ) {
		HRESULT _hr = raw_WriteText(Data, Options);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(_Stream));
		return _hr;
	}

	HRESULT _Stream::Cancel ( ) {
		HRESULT _hr = raw_Cancel();
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(_Stream));
		return _hr;
	}

	//
	// interface ADORecordConstruction wrapper method implementations
	//

	IUnknownPtr ADORecordConstruction::GetRow ( ) {
		IUnknown * _result = 0;
		HRESULT _hr = get_Row(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(ADORecordConstruction));
		return IUnknownPtr(_result, false);
	}

	void ADORecordConstruction::PutRow ( IUnknown * ppRow ) {
		HRESULT _hr = put_Row(ppRow);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(ADORecordConstruction));
	}

	void ADORecordConstruction::PutParentRow ( IUnknown * _arg1 ) {
		HRESULT _hr = put_ParentRow(_arg1);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(ADORecordConstruction));
	}

	//
	// interface ADOStreamConstruction wrapper method implementations
	//

	IUnknownPtr ADOStreamConstruction::GetStream ( ) {
		IUnknown * _result = 0;
		HRESULT _hr = get_Stream(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(ADOStreamConstruction));
		return IUnknownPtr(_result, false);
	}

	void ADOStreamConstruction::PutStream ( IUnknown * ppStm ) {
		HRESULT _hr = put_Stream(ppStm);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(ADOStreamConstruction));
	}

	//
	// interface ADOCommandConstruction wrapper method implementations
	//

	IUnknownPtr ADOCommandConstruction::GetOLEDBCommand ( ) {
		IUnknown * _result = 0;
		HRESULT _hr = get_OLEDBCommand(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(ADOCommandConstruction));
		return IUnknownPtr(_result, false);
	}

	void ADOCommandConstruction::PutOLEDBCommand ( IUnknown * ppOLEDBCommand ) {
		HRESULT _hr = put_OLEDBCommand(ppOLEDBCommand);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(ADOCommandConstruction));
	}

	//
	// interface ADORecordsetConstruction wrapper method implementations
	//

	IUnknownPtr ADORecordsetConstruction::GetRowset ( ) {
		IUnknown * _result = 0;
		HRESULT _hr = get_Rowset(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(ADORecordsetConstruction));
		return IUnknownPtr(_result, false);
	}

	void ADORecordsetConstruction::PutRowset ( IUnknown * ppRowset ) {
		HRESULT _hr = put_Rowset(ppRowset);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(ADORecordsetConstruction));
	}

	ADO_LONGPTR ADORecordsetConstruction::GetChapter ( ) {
		ADO_LONGPTR _result;
		HRESULT _hr = get_Chapter(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(ADORecordsetConstruction));
		return _result;
	}

	void ADORecordsetConstruction::PutChapter ( ADO_LONGPTR plChapter ) {
		HRESULT _hr = put_Chapter(plChapter);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(ADORecordsetConstruction));
	}

	IUnknownPtr ADORecordsetConstruction::GetRowPosition ( ) {
		IUnknown * _result = 0;
		HRESULT _hr = get_RowPosition(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(ADORecordsetConstruction));
		return IUnknownPtr(_result, false);
	}

	void ADORecordsetConstruction::PutRowPosition ( IUnknown * ppRowPos ) {
		HRESULT _hr = put_RowPosition(ppRowPos);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(ADORecordsetConstruction));
	}

	//
	// interface Field15 wrapper method implementations
	//

	ADO_LONGPTR Field15::GetActualSize ( ) {
		ADO_LONGPTR _result;
		HRESULT _hr = get_ActualSize(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(Field15));
		return _result;
	}

	long Field15::GetAttributes ( ) {
		long _result = 0;
		HRESULT _hr = get_Attributes(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(Field15));
		return _result;
	}

	ADO_LONGPTR Field15::GetDefinedSize ( ) {
		ADO_LONGPTR _result;
		HRESULT _hr = get_DefinedSize(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(Field15));
		return _result;
	}

	_bstr_t Field15::GetName ( ) {
		BSTR _result = 0;
		HRESULT _hr = get_Name(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(Field15));
		return _bstr_t(_result, false);
	}

	enum DataTypeEnum Field15::GetType ( ) {
		enum DataTypeEnum _result;
		HRESULT _hr = get_Type(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(this));
		return _result;
	}

	_variant_t Field15::GetValue ( ) {
		VARIANT _result;
		VariantInit(&_result);
		HRESULT _hr = get_Value(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(Field15));
		return _variant_t(_result, false);
	}

	void Field15::PutValue ( const _variant_t & pvar ) {
		HRESULT _hr = put_Value(pvar);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(Field15));
	}

	unsigned char Field15::GetPrecision ( ) {
		unsigned char _result = 0;
		HRESULT _hr = get_Precision(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(this));
		return _result;
	}

	unsigned char Field15::GetNumericScale ( ) {
		unsigned char _result = 0;
		HRESULT _hr = get_NumericScale(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(this));
		return _result;
	}

	HRESULT Field15::AppendChunk ( const _variant_t & Data ) {
		HRESULT _hr = raw_AppendChunk(Data);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(Field15));
		return _hr;
	}

	_variant_t Field15::GetChunk ( long Length ) {
		VARIANT _result;
		VariantInit(&_result);
		HRESULT _hr = raw_GetChunk(Length, &_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(Field15));
		return _variant_t(_result, false);
	}

	_variant_t Field15::GetOriginalValue ( ) {
		VARIANT _result;
		VariantInit(&_result);
		HRESULT _hr = get_OriginalValue(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(Field15));
		return _variant_t(_result, false);
	}

	_variant_t Field15::GetUnderlyingValue ( ) {
		VARIANT _result;
		VariantInit(&_result);
		HRESULT _hr = get_UnderlyingValue(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(Field15));
		return _variant_t(_result, false);
	}

	//
	// interface Command15 wrapper method implementations
	//

	_ConnectionPtr Command15::GetActiveConnection ( ) {
		struct _Connection * _result = 0;
		HRESULT _hr = get_ActiveConnection(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(Command15));
		return _ConnectionPtr(_result, false);
	}

	void Command15::PutRefActiveConnection ( struct _Connection * ppvObject ) {
		HRESULT _hr = putref_ActiveConnection(ppvObject);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(Command15));
	}

	void Command15::PutActiveConnection ( const _variant_t & ppvObject ) {
		HRESULT _hr = put_ActiveConnection(ppvObject);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(Command15));
	}

	_bstr_t Command15::GetCommandText ( ) {
		BSTR _result = 0;
		HRESULT _hr = get_CommandText(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(Command15));
		return _bstr_t(_result, false);
	}

	void Command15::PutCommandText ( _bstr_t pbstr ) {
		HRESULT _hr = put_CommandText(pbstr);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(Command15));
	}

	long Command15::GetCommandTimeout ( ) {
		long _result = 0;
		HRESULT _hr = get_CommandTimeout(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(Command15));
		return _result;
	}

	void Command15::PutCommandTimeout ( long pl ) {
		HRESULT _hr = put_CommandTimeout(pl);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(Command15));
	}

	VARIANT_BOOL Command15::GetPrepared ( ) {
		VARIANT_BOOL _result = 0;
		HRESULT _hr = get_Prepared(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(Command15));
		return _result;
	}

	void Command15::PutPrepared ( VARIANT_BOOL pfPrepared ) {
		HRESULT _hr = put_Prepared(pfPrepared);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(Command15));
	}

	_RecordsetPtr Command15::Execute ( VARIANT * RecordsAffected, VARIANT * Parameters, long Options ) {
		struct _Recordset * _result = 0;
		HRESULT _hr = raw_Execute(RecordsAffected, Parameters, Options, &_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(Command15));
		return _RecordsetPtr(_result, false);
	}

	_ParameterPtr Command15::CreateParameter ( _bstr_t Name, enum DataTypeEnum Type, enum ParameterDirectionEnum Direction, ADO_LONGPTR Size, const _variant_t & Value ) {
		struct _Parameter * _result = 0;
		HRESULT _hr = raw_CreateParameter(Name, Type, Direction, Size, Value, &_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(Command15));
		return _ParameterPtr(_result, false);
	}

	ParametersPtr Command15::GetParameters ( ) {
		struct Parameters * _result = 0;
		HRESULT _hr = get_Parameters(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(Command15));
		return ParametersPtr(_result, false);
	}

	void Command15::PutCommandType ( enum CommandTypeEnum plCmdType ) {
		HRESULT _hr = put_CommandType(plCmdType);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(Command15));
	}

	enum CommandTypeEnum Command15::GetCommandType ( ) {
		enum CommandTypeEnum _result;
		HRESULT _hr = get_CommandType(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(this));
		return _result;
	}

	_bstr_t Command15::GetName ( ) {
		BSTR _result = 0;
		HRESULT _hr = get_Name(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(Command15));
		return _bstr_t(_result, false);
	}

	void Command15::PutName ( _bstr_t pbstrName ) {
		HRESULT _hr = put_Name(pbstrName);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(Command15));
	}

	//
	// interface Command25 wrapper method implementations
	//

	long Command25::GetState ( ) {
		long _result = 0;
		HRESULT _hr = get_State(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(Command25));
		return _result;
	}

	HRESULT Command25::Cancel ( ) {
		HRESULT _hr = raw_Cancel();
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(Command25));
		return _hr;
	}

	//
	// interface _Command wrapper method implementations
	//

	void _Command::PutRefCommandStream ( IUnknown * pvStream ) {
		HRESULT _hr = putref_CommandStream(pvStream);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(_Command));
	}

	_variant_t _Command::GetCommandStream ( ) {
		VARIANT _result;
		VariantInit(&_result);
		HRESULT _hr = get_CommandStream(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(_Command));
		return _variant_t(_result, false);
	}

	void _Command::PutDialect ( _bstr_t pbstrDialect ) {
		HRESULT _hr = put_Dialect(pbstrDialect);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(_Command));
	}

	_bstr_t _Command::GetDialect ( ) {
		BSTR _result = 0;
		HRESULT _hr = get_Dialect(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(_Command));
		return _bstr_t(_result, false);
	}

	void _Command::PutNamedParameters ( VARIANT_BOOL pfNamedParameters ) {
		HRESULT _hr = put_NamedParameters(pfNamedParameters);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(_Command));
	}

	VARIANT_BOOL _Command::GetNamedParameters ( ) {
		VARIANT_BOOL _result = 0;
		HRESULT _hr = get_NamedParameters(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(_Command));
		return _result;
	}

	//
	// interface Connection15 wrapper method implementations
	//

	_bstr_t Connection15::GetConnectionString ( ) {
		BSTR _result = 0;
		HRESULT _hr = get_ConnectionString(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(Connection15));
		return _bstr_t(_result, false);
	}

	void Connection15::PutConnectionString ( _bstr_t pbstr ) {
		HRESULT _hr = put_ConnectionString(pbstr);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(Connection15));
	}

	long Connection15::GetCommandTimeout ( ) {
		long _result = 0;
		HRESULT _hr = get_CommandTimeout(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(Connection15));
		return _result;
	}

	void Connection15::PutCommandTimeout ( long plTimeout ) {
		HRESULT _hr = put_CommandTimeout(plTimeout);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(Connection15));
	}

	long Connection15::GetConnectionTimeout ( ) {
		long _result = 0;
		HRESULT _hr = get_ConnectionTimeout(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(Connection15));
		return _result;
	}

	void Connection15::PutConnectionTimeout ( long plTimeout ) {
		HRESULT _hr = put_ConnectionTimeout(plTimeout);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(Connection15));
	}

	_bstr_t Connection15::GetVersion ( ) {
		BSTR _result = 0;
		HRESULT _hr = get_Version(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(Connection15));
		return _bstr_t(_result, false);
	}

	HRESULT Connection15::Close ( ) {
		HRESULT _hr = raw_Close();
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(Connection15));
		return _hr;
	}

	_RecordsetPtr Connection15::Execute ( _bstr_t CommandText, VARIANT * RecordsAffected, long Options ) {
		struct _Recordset * _result = 0;
		HRESULT _hr = raw_Execute(CommandText, RecordsAffected, Options, &_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(Connection15));
		return _RecordsetPtr(_result, false);
	}

	long Connection15::BeginTrans ( ) {
		long _result = 0;
		HRESULT _hr = raw_BeginTrans(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(Connection15));
		return _result;
	}

	HRESULT Connection15::CommitTrans ( ) {
		HRESULT _hr = raw_CommitTrans();
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(Connection15));
		return _hr;
	}

	HRESULT Connection15::RollbackTrans ( ) {
		HRESULT _hr = raw_RollbackTrans();
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(Connection15));
		return _hr;
	}

	HRESULT Connection15::Open ( _bstr_t ConnectionString, _bstr_t UserID, _bstr_t Password, long Options ) {
		HRESULT _hr = raw_Open(ConnectionString, UserID, Password, Options);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(Connection15));
		return _hr;
	}

	ErrorsPtr Connection15::GetErrors ( ) {
		struct Errors * _result = 0;
		HRESULT _hr = get_Errors(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(Connection15));
		return ErrorsPtr(_result, false);
	}

	_bstr_t Connection15::GetDefaultDatabase ( ) {
		BSTR _result = 0;
		HRESULT _hr = get_DefaultDatabase(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(Connection15));
		return _bstr_t(_result, false);
	}

	void Connection15::PutDefaultDatabase ( _bstr_t pbstr ) {
		HRESULT _hr = put_DefaultDatabase(pbstr);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(Connection15));
	}

	enum IsolationLevelEnum Connection15::GetIsolationLevel ( ) {
		enum IsolationLevelEnum _result;
		HRESULT _hr = get_IsolationLevel(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(this));
		return _result;
	}

	void Connection15::PutIsolationLevel ( enum IsolationLevelEnum Level ) {
		HRESULT _hr = put_IsolationLevel(Level);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(Connection15));
	}

	long Connection15::GetAttributes ( ) {
		long _result = 0;
		HRESULT _hr = get_Attributes(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(Connection15));
		return _result;
	}

	void Connection15::PutAttributes ( long plAttr ) {
		HRESULT _hr = put_Attributes(plAttr);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(Connection15));
	}

	enum CursorLocationEnum Connection15::GetCursorLocation ( ) {
		enum CursorLocationEnum _result;
		HRESULT _hr = get_CursorLocation(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(this));
		return _result;
	}

	void Connection15::PutCursorLocation ( enum CursorLocationEnum plCursorLoc ) {
		HRESULT _hr = put_CursorLocation(plCursorLoc);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(Connection15));
	}

	enum ConnectModeEnum Connection15::GetMode ( ) {
		enum ConnectModeEnum _result;
		HRESULT _hr = get_Mode(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(this));
		return _result;
	}

	void Connection15::PutMode ( enum ConnectModeEnum plMode ) {
		HRESULT _hr = put_Mode(plMode);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(Connection15));
	}

	_bstr_t Connection15::GetProvider ( ) {
		BSTR _result = 0;
		HRESULT _hr = get_Provider(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(Connection15));
		return _bstr_t(_result, false);
	}

	void Connection15::PutProvider ( _bstr_t pbstr ) {
		HRESULT _hr = put_Provider(pbstr);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(Connection15));
	}

	long Connection15::GetState ( ) {
		long _result = 0;
		HRESULT _hr = get_State(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(Connection15));
		return _result;
	}

	_RecordsetPtr Connection15::OpenSchema ( enum SchemaEnum Schema, const _variant_t & Restrictions, const _variant_t & SchemaID ) {
		struct _Recordset * _result = 0;
		HRESULT _hr = raw_OpenSchema(Schema, Restrictions, SchemaID, &_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(Connection15));
		return _RecordsetPtr(_result, false);
	}

	//
	// interface _Connection wrapper method implementations
	//

	HRESULT _Connection::Cancel ( ) {
		HRESULT _hr = raw_Cancel();
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(_Connection));
		return _hr;
	}

	//
	// interface Recordset15 wrapper method implementations
	//

	PositionEnum_Param Recordset15::GetAbsolutePosition ( ) {
		PositionEnum_Param _result;
		HRESULT _hr = get_AbsolutePosition(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(Recordset15));
		return _result;
	}

	void Recordset15::PutAbsolutePosition ( PositionEnum_Param pl ) {
		HRESULT _hr = put_AbsolutePosition(pl);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(Recordset15));
	}

	void Recordset15::PutRefActiveConnection ( IDispatch * pvar ) {
		HRESULT _hr = putref_ActiveConnection(pvar);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(Recordset15));
	}

	void Recordset15::PutActiveConnection ( const _variant_t & pvar ) {
		HRESULT _hr = put_ActiveConnection(pvar);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(Recordset15));
	}

	_variant_t Recordset15::GetActiveConnection ( ) {
		VARIANT _result;
		VariantInit(&_result);
		HRESULT _hr = get_ActiveConnection(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(Recordset15));
		return _variant_t(_result, false);
	}

	VARIANT_BOOL Recordset15::GetBOF ( ) {
		VARIANT_BOOL _result = 0;
		HRESULT _hr = get_BOF(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(Recordset15));
		return _result;
	}

	_variant_t Recordset15::GetBookmark ( ) {
		VARIANT _result;
		VariantInit(&_result);
		HRESULT _hr = get_Bookmark(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(Recordset15));
		return _variant_t(_result, false);
	}

	void Recordset15::PutBookmark ( const _variant_t & pvBookmark ) {
		HRESULT _hr = put_Bookmark(pvBookmark);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(Recordset15));
	}

	long Recordset15::GetCacheSize ( ) {
		long _result = 0;
		HRESULT _hr = get_CacheSize(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(Recordset15));
		return _result;
	}

	void Recordset15::PutCacheSize ( long pl ) {
		HRESULT _hr = put_CacheSize(pl);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(Recordset15));
	}

	enum CursorTypeEnum Recordset15::GetCursorType ( ) {
		enum CursorTypeEnum _result;
		HRESULT _hr = get_CursorType(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(this));
		return _result;
	}

	void Recordset15::PutCursorType ( enum CursorTypeEnum plCursorType ) {
		HRESULT _hr = put_CursorType(plCursorType);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(Recordset15));
	}

	VARIANT_BOOL Recordset15::GetadoEOF ( ) {
		VARIANT_BOOL _result = 0;
		HRESULT _hr = get_adoEOF(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(Recordset15));
		return _result;
	}

	FieldsPtr Recordset15::GetFields ( ) {
		struct Fields * _result = 0;
		HRESULT _hr = get_Fields(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(Recordset15));
		return FieldsPtr(_result, false);
	}

	enum LockTypeEnum Recordset15::GetLockType ( ) {
		enum LockTypeEnum _result;
		HRESULT _hr = get_LockType(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(this));
		return _result;
	}

	void Recordset15::PutLockType ( enum LockTypeEnum plLockType ) {
		HRESULT _hr = put_LockType(plLockType);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(Recordset15));
	}

	ADO_LONGPTR Recordset15::GetMaxRecords ( ) {
		ADO_LONGPTR _result;
		HRESULT _hr = get_MaxRecords(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(Recordset15));
		return _result;
	}

	void Recordset15::PutMaxRecords ( ADO_LONGPTR plMaxRecords ) {
		HRESULT _hr = put_MaxRecords(plMaxRecords);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(Recordset15));
	}

	ADO_LONGPTR Recordset15::GetRecordCount ( ) {
		ADO_LONGPTR _result;
		HRESULT _hr = get_RecordCount(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(Recordset15));
		return _result;
	}

	void Recordset15::PutRefSource ( IDispatch * pvSource ) {
		HRESULT _hr = putref_Source(pvSource);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(Recordset15));
	}

	void Recordset15::PutSource ( _bstr_t pvSource ) {
		HRESULT _hr = put_Source(pvSource);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(Recordset15));
	}

	_variant_t Recordset15::GetSource ( ) {
		VARIANT _result;
		VariantInit(&_result);
		HRESULT _hr = get_Source(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(Recordset15));
		return _variant_t(_result, false);
	}

	HRESULT Recordset15::AddNew ( const _variant_t & FieldList, const _variant_t & Values ) {
		HRESULT _hr = raw_AddNew(FieldList, Values);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(Recordset15));
		return _hr;
	}

	HRESULT Recordset15::CancelUpdate ( ) {
		HRESULT _hr = raw_CancelUpdate();
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(Recordset15));
		return _hr;
	}

	HRESULT Recordset15::Close ( ) {
		HRESULT _hr = raw_Close();
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(Recordset15));
		return _hr;
	}

	HRESULT Recordset15::Delete ( enum AffectEnum AffectRecords ) {
		HRESULT _hr = raw_Delete(AffectRecords);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(Recordset15));
		return _hr;
	}

	_variant_t Recordset15::GetRows ( long Rows, const _variant_t & Start, const _variant_t & Fields ) {
		VARIANT _result;
		VariantInit(&_result);
		HRESULT _hr = raw_GetRows(Rows, Start, Fields, &_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(Recordset15));
		return _variant_t(_result, false);
	}

	HRESULT Recordset15::Move ( ADO_LONGPTR NumRecords, const _variant_t & Start ) {
		HRESULT _hr = raw_Move(NumRecords, Start);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(Recordset15));
		return _hr;
	}

	HRESULT Recordset15::MoveNext ( ) {
		HRESULT _hr = raw_MoveNext();
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(Recordset15));
		return _hr;
	}

	HRESULT Recordset15::MovePrevious ( ) {
		HRESULT _hr = raw_MovePrevious();
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(Recordset15));
		return _hr;
	}

	HRESULT Recordset15::MoveFirst ( ) {
		HRESULT _hr = raw_MoveFirst();
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(Recordset15));
		return _hr;
	}

	HRESULT Recordset15::MoveLast ( ) {
		HRESULT _hr = raw_MoveLast();
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(Recordset15));
		return _hr;
	}

	HRESULT Recordset15::Open ( const _variant_t & Source, const _variant_t & ActiveConnection, enum CursorTypeEnum CursorType, enum LockTypeEnum LockType, long Options ) {
		HRESULT _hr = raw_Open(Source, ActiveConnection, CursorType, LockType, Options);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(Recordset15));
		return _hr;
	}

	HRESULT Recordset15::Requery ( long Options ) {
		HRESULT _hr = raw_Requery(Options);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(Recordset15));
		return _hr;
	}

	HRESULT Recordset15::_xResync ( enum AffectEnum AffectRecords ) {
		HRESULT _hr = raw__xResync(AffectRecords);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(Recordset15));
		return _hr;
	}

	HRESULT Recordset15::Update ( const _variant_t & Fields, const _variant_t & Values ) {
		HRESULT _hr = raw_Update(Fields, Values);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(Recordset15));
		return _hr;
	}

	PositionEnum_Param Recordset15::GetAbsolutePage ( ) {
		PositionEnum_Param _result;
		HRESULT _hr = get_AbsolutePage(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(Recordset15));
		return _result;
	}

	void Recordset15::PutAbsolutePage ( PositionEnum_Param pl ) {
		HRESULT _hr = put_AbsolutePage(pl);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(Recordset15));
	}

	enum EditModeEnum Recordset15::GetEditMode ( ) {
		enum EditModeEnum _result;
		HRESULT _hr = get_EditMode(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(this));
		return _result;
	}

	_variant_t Recordset15::GetFilter ( ) {
		VARIANT _result;
		VariantInit(&_result);
		HRESULT _hr = get_Filter(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(Recordset15));
		return _variant_t(_result, false);
	}

	void Recordset15::PutFilter ( const _variant_t & Criteria ) {
		HRESULT _hr = put_Filter(Criteria);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(Recordset15));
	}

	ADO_LONGPTR Recordset15::GetPageCount ( ) {
		ADO_LONGPTR _result;
		HRESULT _hr = get_PageCount(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(Recordset15));
		return _result;
	}

	long Recordset15::GetPageSize ( ) {
		long _result = 0;
		HRESULT _hr = get_PageSize(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(Recordset15));
		return _result;
	}

	void Recordset15::PutPageSize ( long pl ) {
		HRESULT _hr = put_PageSize(pl);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(Recordset15));
	}

	_bstr_t Recordset15::GetSort ( ) {
		BSTR _result = 0;
		HRESULT _hr = get_Sort(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(Recordset15));
		return _bstr_t(_result, false);
	}

	void Recordset15::PutSort ( _bstr_t Criteria ) {
		HRESULT _hr = put_Sort(Criteria);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(Recordset15));
	}

	long Recordset15::GetStatus ( ) {
		long _result = 0;
		HRESULT _hr = get_Status(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(Recordset15));
		return _result;
	}

	long Recordset15::GetState ( ) {
		long _result = 0;
		HRESULT _hr = get_State(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(Recordset15));
		return _result;
	}

	_RecordsetPtr Recordset15::_xClone ( ) {
		struct _Recordset * _result = 0;
		HRESULT _hr = raw__xClone(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(Recordset15));
		return _RecordsetPtr(_result, false);
	}

	HRESULT Recordset15::UpdateBatch ( enum AffectEnum AffectRecords ) {
		HRESULT _hr = raw_UpdateBatch(AffectRecords);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(Recordset15));
		return _hr;
	}

	HRESULT Recordset15::CancelBatch ( enum AffectEnum AffectRecords ) {
		HRESULT _hr = raw_CancelBatch(AffectRecords);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(Recordset15));
		return _hr;
	}

	enum CursorLocationEnum Recordset15::GetCursorLocation ( ) {
		enum CursorLocationEnum _result;
		HRESULT _hr = get_CursorLocation(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(this));
		return _result;
	}

	void Recordset15::PutCursorLocation ( enum CursorLocationEnum plCursorLoc ) {
		HRESULT _hr = put_CursorLocation(plCursorLoc);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(Recordset15));
	}

	_RecordsetPtr Recordset15::NextRecordset ( VARIANT * RecordsAffected ) {
		struct _Recordset * _result = 0;
		HRESULT _hr = raw_NextRecordset(RecordsAffected, &_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(Recordset15));
		return _RecordsetPtr(_result, false);
	}

	VARIANT_BOOL Recordset15::Supports ( enum CursorOptionEnum CursorOptions ) {
		VARIANT_BOOL _result = 0;
		HRESULT _hr = raw_Supports(CursorOptions, &_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(Recordset15));
		return _result;
	}

	_variant_t Recordset15::GetCollect ( const _variant_t & Index ) {
		VARIANT _result;
		VariantInit(&_result);
		HRESULT _hr = get_Collect(Index, &_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(Recordset15));
		return _variant_t(_result, false);
	}

	void Recordset15::PutCollect ( const _variant_t & Index, const _variant_t & pvar ) {
		HRESULT _hr = put_Collect(Index, pvar);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(Recordset15));
	}

	enum MarshalOptionsEnum Recordset15::GetMarshalOptions ( ) {
		enum MarshalOptionsEnum _result;
		HRESULT _hr = get_MarshalOptions(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(this));
		return _result;
	}

	void Recordset15::PutMarshalOptions ( enum MarshalOptionsEnum peMarshal ) {
		HRESULT _hr = put_MarshalOptions(peMarshal);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(Recordset15));
	}

	HRESULT Recordset15::Find ( _bstr_t Criteria, ADO_LONGPTR SkipRecords, enum SearchDirectionEnum SearchDirection, const _variant_t & Start ) {
		HRESULT _hr = raw_Find(Criteria, SkipRecords, SearchDirection, Start);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(Recordset15));
		return _hr;
	}

	//
	// interface Recordset20 wrapper method implementations
	//

	HRESULT Recordset20::Cancel ( ) {
		HRESULT _hr = raw_Cancel();
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(Recordset20));
		return _hr;
	}

	IUnknownPtr Recordset20::GetDataSource ( ) {
		IUnknown * _result = 0;
		HRESULT _hr = get_DataSource(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(Recordset20));
		return IUnknownPtr(_result, false);
	}

	void Recordset20::PutRefDataSource ( IUnknown * ppunkDataSource ) {
		HRESULT _hr = putref_DataSource(ppunkDataSource);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(Recordset20));
	}

	HRESULT Recordset20::_xSave ( _bstr_t FileName, enum PersistFormatEnum PersistFormat ) {
		HRESULT _hr = raw__xSave(FileName, PersistFormat);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(Recordset20));
		return _hr;
	}

	IDispatchPtr Recordset20::GetActiveCommand ( ) {
		IDispatch * _result = 0;
		HRESULT _hr = get_ActiveCommand(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(Recordset20));
		return IDispatchPtr(_result, false);
	}

	void Recordset20::PutStayInSync ( VARIANT_BOOL pbStayInSync ) {
		HRESULT _hr = put_StayInSync(pbStayInSync);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(Recordset20));
	}

	VARIANT_BOOL Recordset20::GetStayInSync ( ) {
		VARIANT_BOOL _result = 0;
		HRESULT _hr = get_StayInSync(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(Recordset20));
		return _result;
	}

	_bstr_t Recordset20::GetString ( enum StringFormatEnum StringFormat, long NumRows, _bstr_t ColumnDelimeter, _bstr_t RowDelimeter, _bstr_t NullExpr ) {
		BSTR _result = 0;
		HRESULT _hr = raw_GetString(StringFormat, NumRows, ColumnDelimeter, RowDelimeter, NullExpr, &_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(Recordset20));
		return _bstr_t(_result, false);
	}

	_bstr_t Recordset20::GetDataMember ( ) {
		BSTR _result = 0;
		HRESULT _hr = get_DataMember(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(Recordset20));
		return _bstr_t(_result, false);
	}

	void Recordset20::PutDataMember ( _bstr_t pbstrDataMember ) {
		HRESULT _hr = put_DataMember(pbstrDataMember);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(Recordset20));
	}

	enum CompareEnum Recordset20::CompareBookmarks ( const _variant_t & Bookmark1, const _variant_t & Bookmark2 ) {
		enum CompareEnum _result;
		HRESULT _hr = raw_CompareBookmarks(Bookmark1, Bookmark2, &_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(this));
		return _result;
	}

	_RecordsetPtr Recordset20::Clone ( enum LockTypeEnum LockType ) {
		struct _Recordset * _result = 0;
		HRESULT _hr = raw_Clone(LockType, &_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(Recordset20));
		return _RecordsetPtr(_result, false);
	}

	HRESULT Recordset20::Resync ( enum AffectEnum AffectRecords, enum ResyncEnum ResyncValues ) {
		HRESULT _hr = raw_Resync(AffectRecords, ResyncValues);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(Recordset20));
		return _hr;
	}

	//
	// interface Recordset21 wrapper method implementations
	//

	HRESULT Recordset21::Seek ( const _variant_t & KeyValues, enum SeekEnum SeekOption ) {
		HRESULT _hr = raw_Seek(KeyValues, SeekOption);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(Recordset21));
		return _hr;
	}

	void Recordset21::PutIndex ( _bstr_t pbstrIndex ) {
		HRESULT _hr = put_Index(pbstrIndex);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(Recordset21));
	}

	_bstr_t Recordset21::GetIndex ( ) {
		BSTR _result = 0;
		HRESULT _hr = get_Index(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(Recordset21));
		return _bstr_t(_result, false);
	}

	//
	// interface _Recordset wrapper method implementations
	//

	HRESULT _Recordset::Save ( const _variant_t & Destination, enum PersistFormatEnum PersistFormat ) {
		HRESULT _hr = raw_Save(Destination, PersistFormat);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(_Recordset));
		return _hr;
	}

	//
	// interface ConnectionEventsVt wrapper method implementations
	//

	HRESULT ConnectionEventsVt::InfoMessage ( struct Error * pError, enum EventStatusEnum * adStatus, struct _Connection * pConnection ) {
		HRESULT _hr = raw_InfoMessage(pError, adStatus, pConnection);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(ConnectionEventsVt));
		return _hr;
	}

	HRESULT ConnectionEventsVt::BeginTransComplete ( long TransactionLevel, struct Error * pError, enum EventStatusEnum * adStatus, struct _Connection * pConnection ) {
		HRESULT _hr = raw_BeginTransComplete(TransactionLevel, pError, adStatus, pConnection);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(ConnectionEventsVt));
		return _hr;
	}

	HRESULT ConnectionEventsVt::CommitTransComplete ( struct Error * pError, enum EventStatusEnum * adStatus, struct _Connection * pConnection ) {
		HRESULT _hr = raw_CommitTransComplete(pError, adStatus, pConnection);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(ConnectionEventsVt));
		return _hr;
	}

	HRESULT ConnectionEventsVt::RollbackTransComplete ( struct Error * pError, enum EventStatusEnum * adStatus, struct _Connection * pConnection ) {
		HRESULT _hr = raw_RollbackTransComplete(pError, adStatus, pConnection);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(ConnectionEventsVt));
		return _hr;
	}

	HRESULT ConnectionEventsVt::WillExecute ( BSTR * Source, enum CursorTypeEnum * CursorType, enum LockTypeEnum * LockType, long * Options, enum EventStatusEnum * adStatus, struct _Command * pCommand, struct _Recordset * pRecordset, struct _Connection * pConnection ) {
		HRESULT _hr = raw_WillExecute(Source, CursorType, LockType, Options, adStatus, pCommand, pRecordset, pConnection);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(ConnectionEventsVt));
		return _hr;
	}

	HRESULT ConnectionEventsVt::ExecuteComplete ( long RecordsAffected, struct Error * pError, enum EventStatusEnum * adStatus, struct _Command * pCommand, struct _Recordset * pRecordset, struct _Connection * pConnection ) {
		HRESULT _hr = raw_ExecuteComplete(RecordsAffected, pError, adStatus, pCommand, pRecordset, pConnection);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(ConnectionEventsVt));
		return _hr;
	}

	HRESULT ConnectionEventsVt::WillConnect ( BSTR * ConnectionString, BSTR * UserID, BSTR * Password, long * Options, enum EventStatusEnum * adStatus, struct _Connection * pConnection ) {
		HRESULT _hr = raw_WillConnect(ConnectionString, UserID, Password, Options, adStatus, pConnection);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(ConnectionEventsVt));
		return _hr;
	}

	HRESULT ConnectionEventsVt::ConnectComplete ( struct Error * pError, enum EventStatusEnum * adStatus, struct _Connection * pConnection ) {
		HRESULT _hr = raw_ConnectComplete(pError, adStatus, pConnection);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(ConnectionEventsVt));
		return _hr;
	}

	HRESULT ConnectionEventsVt::Disconnect ( enum EventStatusEnum * adStatus, struct _Connection * pConnection ) {
		HRESULT _hr = raw_Disconnect(adStatus, pConnection);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(ConnectionEventsVt));
		return _hr;
	}

	//
	// interface RecordsetEventsVt wrapper method implementations
	//

	HRESULT RecordsetEventsVt::WillChangeField ( long cFields, const _variant_t & Fields, enum EventStatusEnum * adStatus, struct _Recordset * pRecordset ) {
		HRESULT _hr = raw_WillChangeField(cFields, Fields, adStatus, pRecordset);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(RecordsetEventsVt));
		return _hr;
	}

	HRESULT RecordsetEventsVt::FieldChangeComplete ( long cFields, const _variant_t & Fields, struct Error * pError, enum EventStatusEnum * adStatus, struct _Recordset * pRecordset ) {
		HRESULT _hr = raw_FieldChangeComplete(cFields, Fields, pError, adStatus, pRecordset);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(RecordsetEventsVt));
		return _hr;
	}

	HRESULT RecordsetEventsVt::WillChangeRecord ( enum EventReasonEnum adReason, long cRecords, enum EventStatusEnum * adStatus, struct _Recordset * pRecordset ) {
		HRESULT _hr = raw_WillChangeRecord(adReason, cRecords, adStatus, pRecordset);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(RecordsetEventsVt));
		return _hr;
	}

	HRESULT RecordsetEventsVt::RecordChangeComplete ( enum EventReasonEnum adReason, long cRecords, struct Error * pError, enum EventStatusEnum * adStatus, struct _Recordset * pRecordset ) {
		HRESULT _hr = raw_RecordChangeComplete(adReason, cRecords, pError, adStatus, pRecordset);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(RecordsetEventsVt));
		return _hr;
	}

	HRESULT RecordsetEventsVt::WillChangeRecordset ( enum EventReasonEnum adReason, enum EventStatusEnum * adStatus, struct _Recordset * pRecordset ) {
		HRESULT _hr = raw_WillChangeRecordset(adReason, adStatus, pRecordset);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(RecordsetEventsVt));
		return _hr;
	}

	HRESULT RecordsetEventsVt::RecordsetChangeComplete ( enum EventReasonEnum adReason, struct Error * pError, enum EventStatusEnum * adStatus, struct _Recordset * pRecordset ) {
		HRESULT _hr = raw_RecordsetChangeComplete(adReason, pError, adStatus, pRecordset);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(RecordsetEventsVt));
		return _hr;
	}

	HRESULT RecordsetEventsVt::WillMove ( enum EventReasonEnum adReason, enum EventStatusEnum * adStatus, struct _Recordset * pRecordset ) {
		HRESULT _hr = raw_WillMove(adReason, adStatus, pRecordset);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(RecordsetEventsVt));
		return _hr;
	}

	HRESULT RecordsetEventsVt::MoveComplete ( enum EventReasonEnum adReason, struct Error * pError, enum EventStatusEnum * adStatus, struct _Recordset * pRecordset ) {
		HRESULT _hr = raw_MoveComplete(adReason, pError, adStatus, pRecordset);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(RecordsetEventsVt));
		return _hr;
	}

	HRESULT RecordsetEventsVt::EndOfRecordset ( VARIANT_BOOL * fMoreData, enum EventStatusEnum * adStatus, struct _Recordset * pRecordset ) {
		HRESULT _hr = raw_EndOfRecordset(fMoreData, adStatus, pRecordset);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(RecordsetEventsVt));
		return _hr;
	}

	HRESULT RecordsetEventsVt::FetchProgress ( long Progress, long MaxProgress, enum EventStatusEnum * adStatus, struct _Recordset * pRecordset ) {
		HRESULT _hr = raw_FetchProgress(Progress, MaxProgress, adStatus, pRecordset);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(RecordsetEventsVt));
		return _hr;
	}

	HRESULT RecordsetEventsVt::FetchComplete ( struct Error * pError, enum EventStatusEnum * adStatus, struct _Recordset * pRecordset ) {
		HRESULT _hr = raw_FetchComplete(pError, adStatus, pRecordset);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(RecordsetEventsVt));
		return _hr;
	}

	//
	// interface _Record wrapper method implementations
	//

	_variant_t _Record::GetActiveConnection ( ) {
		VARIANT _result;
		VariantInit(&_result);
		HRESULT _hr = get_ActiveConnection(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(_Record));
		return _variant_t(_result, false);
	}

	void _Record::PutActiveConnection ( _bstr_t pvar ) {
		HRESULT _hr = put_ActiveConnection(pvar);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(_Record));
	}

	void _Record::PutRefActiveConnection ( struct _Connection * pvar ) {
		HRESULT _hr = putref_ActiveConnection(pvar);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(_Record));
	}

	enum ObjectStateEnum _Record::GetState ( ) {
		enum ObjectStateEnum _result;
		HRESULT _hr = get_State(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(this));
		return _result;
	}

	_variant_t _Record::GetSource ( ) {
		VARIANT _result;
		VariantInit(&_result);
		HRESULT _hr = get_Source(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(_Record));
		return _variant_t(_result, false);
	}

	void _Record::PutSource ( _bstr_t pvar ) {
		HRESULT _hr = put_Source(pvar);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(_Record));
	}

	void _Record::PutRefSource ( IDispatch * pvar ) {
		HRESULT _hr = putref_Source(pvar);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(_Record));
	}

	enum ConnectModeEnum _Record::GetMode ( ) {
		enum ConnectModeEnum _result;
		HRESULT _hr = get_Mode(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(this));
		return _result;
	}

	void _Record::PutMode ( enum ConnectModeEnum pMode ) {
		HRESULT _hr = put_Mode(pMode);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(_Record));
	}

	_bstr_t _Record::GetParentURL ( ) {
		BSTR _result = 0;
		HRESULT _hr = get_ParentURL(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(_Record));
		return _bstr_t(_result, false);
	}

	_bstr_t _Record::MoveRecord ( _bstr_t Source, _bstr_t Destination, _bstr_t UserName, _bstr_t Password, enum MoveRecordOptionsEnum Options, VARIANT_BOOL Async ) {
		BSTR _result = 0;
		HRESULT _hr = raw_MoveRecord(Source, Destination, UserName, Password, Options, Async, &_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(_Record));
		return _bstr_t(_result, false);
	}

	_bstr_t _Record::CopyRecord ( _bstr_t Source, _bstr_t Destination, _bstr_t UserName, _bstr_t Password, enum CopyRecordOptionsEnum Options, VARIANT_BOOL Async ) {
		BSTR _result = 0;
		HRESULT _hr = raw_CopyRecord(Source, Destination, UserName, Password, Options, Async, &_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(_Record));
		return _bstr_t(_result, false);
	}

	HRESULT _Record::DeleteRecord ( _bstr_t Source, VARIANT_BOOL Async ) {
		HRESULT _hr = raw_DeleteRecord(Source, Async);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(_Record));
		return _hr;
	}

	HRESULT _Record::Open ( const _variant_t & Source, const _variant_t & ActiveConnection, enum ConnectModeEnum Mode, enum RecordCreateOptionsEnum CreateOptions, enum RecordOpenOptionsEnum Options, _bstr_t UserName, _bstr_t Password ) {
		HRESULT _hr = raw_Open(Source, ActiveConnection, Mode, CreateOptions, Options, UserName, Password);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(_Record));
		return _hr;
	}

	HRESULT _Record::Close ( ) {
		HRESULT _hr = raw_Close();
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(_Record));
		return _hr;
	}

	FieldsPtr _Record::GetFields ( ) {
		struct Fields * _result = 0;
		HRESULT _hr = get_Fields(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(_Record));
		return FieldsPtr(_result, false);
	}

	enum RecordTypeEnum _Record::GetRecordType ( ) {
		enum RecordTypeEnum _result;
		HRESULT _hr = get_RecordType(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(this));
		return _result;
	}

	_RecordsetPtr _Record::GetChildren ( ) {
		struct _Recordset * _result = 0;
		HRESULT _hr = raw_GetChildren(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(_Record));
		return _RecordsetPtr(_result, false);
	}

	HRESULT _Record::Cancel ( ) {
		HRESULT _hr = raw_Cancel();
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(_Record));
		return _hr;
	}

}
