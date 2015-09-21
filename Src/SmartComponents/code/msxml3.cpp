// Created by Microsoft (R) C/C++ Compiler Version 15.00.21022.08 (a412cb33).
//
// D:\DOCUME~1\ADMINI~1\LOCALS~1\Temp\msxml3.tli
//
// Wrapper implementations for Win32 type library F5078F18-C551-11D3-89B9-0000F81FE221
// compiler-generated file created 05/07/09 at 11:19:07 - DO NOT EDIT!

#include "msxml3.h"

namespace MSXML2 {

	//
	// interface IXMLDOMImplementation wrapper method implementations
	//

	VARIANT_BOOL IXMLDOMImplementation::hasFeature ( _bstr_t feature, _bstr_t version ) {
		VARIANT_BOOL _result = 0;
		HRESULT _hr = raw_hasFeature(feature, version, &_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IXMLDOMImplementation));
		return _result;
	}

	//
	// interface IXMLDOMParseError wrapper method implementations
	//

	long IXMLDOMParseError::GeterrorCode ( ) {
		long _result = 0;
		HRESULT _hr = get_errorCode(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IXMLDOMParseError));
		return _result;
	}

	_bstr_t IXMLDOMParseError::Geturl ( ) {
		BSTR _result = 0;
		HRESULT _hr = get_url(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IXMLDOMParseError));
		return _bstr_t(_result, false);
	}

	_bstr_t IXMLDOMParseError::Getreason ( ) {
		BSTR _result = 0;
		HRESULT _hr = get_reason(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IXMLDOMParseError));
		return _bstr_t(_result, false);
	}

	_bstr_t IXMLDOMParseError::GetsrcText ( ) {
		BSTR _result = 0;
		HRESULT _hr = get_srcText(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IXMLDOMParseError));
		return _bstr_t(_result, false);
	}

	long IXMLDOMParseError::Getline ( ) {
		long _result = 0;
		HRESULT _hr = get_line(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IXMLDOMParseError));
		return _result;
	}

	long IXMLDOMParseError::Getlinepos ( ) {
		long _result = 0;
		HRESULT _hr = get_linepos(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IXMLDOMParseError));
		return _result;
	}

	long IXMLDOMParseError::Getfilepos ( ) {
		long _result = 0;
		HRESULT _hr = get_filepos(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IXMLDOMParseError));
		return _result;
	}

	//
	// interface ISAXEntityResolver wrapper method implementations
	//

	_variant_t ISAXEntityResolver::resolveEntity ( unsigned short * pwchPublicId, unsigned short * pwchSystemId ) {
		VARIANT _result;
		VariantInit(&_result);
		HRESULT _hr = raw_resolveEntity(pwchPublicId, pwchSystemId, &_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(ISAXEntityResolver));
		return _variant_t(_result, false);
	}

	//
	// interface ISAXLocator wrapper method implementations
	//

	int ISAXLocator::getColumnNumber ( ) {
		int _result = 0;
		HRESULT _hr = raw_getColumnNumber(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(ISAXEntityResolver));
		return _result;
	}

	int ISAXLocator::getLineNumber ( ) {
		int _result = 0;
		HRESULT _hr = raw_getLineNumber(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(ISAXEntityResolver));
		return _result;
	}

	unsigned short * ISAXLocator::getPublicId ( ) {
		unsigned short * _result = 0;
		HRESULT _hr = raw_getPublicId(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(ISAXEntityResolver));
		return _result;
	}

	unsigned short * ISAXLocator::getSystemId ( ) {
		unsigned short * _result = 0;
		HRESULT _hr = raw_getSystemId(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(ISAXEntityResolver));
		return _result;
	}

	//
	// interface ISAXAttributes wrapper method implementations
	//

	int ISAXAttributes::getLength ( ) {
		int _result = 0;
		HRESULT _hr = raw_getLength(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(ISAXAttributes));
		return _result;
	}

	HRESULT ISAXAttributes::getURI ( int nIndex, unsigned short * * ppwchUri, int * pcchUri ) {
		HRESULT _hr = raw_getURI(nIndex, ppwchUri, pcchUri);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(ISAXAttributes));
		return _hr;
	}

	HRESULT ISAXAttributes::getLocalName ( int nIndex, unsigned short * * ppwchLocalName, int * pcchLocalName ) {
		HRESULT _hr = raw_getLocalName(nIndex, ppwchLocalName, pcchLocalName);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(ISAXAttributes));
		return _hr;
	}

	HRESULT ISAXAttributes::getQName ( int nIndex, unsigned short * * ppwchQName, int * pcchQName ) {
		HRESULT _hr = raw_getQName(nIndex, ppwchQName, pcchQName);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(ISAXAttributes));
		return _hr;
	}

	HRESULT ISAXAttributes::getName ( int nIndex, unsigned short * * ppwchUri, int * pcchUri, unsigned short * * ppwchLocalName, int * pcchLocalName, unsigned short * * ppwchQName, int * pcchQName ) {
		HRESULT _hr = raw_getName(nIndex, ppwchUri, pcchUri, ppwchLocalName, pcchLocalName, ppwchQName, pcchQName);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(ISAXAttributes));
		return _hr;
	}

	int ISAXAttributes::getIndexFromName ( unsigned short * pwchUri, int cchUri, unsigned short * pwchLocalName, int cchLocalName ) {
		int _result = 0;
		HRESULT _hr = raw_getIndexFromName(pwchUri, cchUri, pwchLocalName, cchLocalName, &_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(ISAXAttributes));
		return _result;
	}

	int ISAXAttributes::getIndexFromQName ( unsigned short * pwchQName, int cchQName ) {
		int _result = 0;
		HRESULT _hr = raw_getIndexFromQName(pwchQName, cchQName, &_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(ISAXAttributes));
		return _result;
	}

	HRESULT ISAXAttributes::getType ( int nIndex, unsigned short * * ppwchType, int * pcchType ) {
		HRESULT _hr = raw_getType(nIndex, ppwchType, pcchType);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(ISAXAttributes));
		return _hr;
	}

	HRESULT ISAXAttributes::getTypeFromName ( unsigned short * pwchUri, int cchUri, unsigned short * pwchLocalName, int cchLocalName, unsigned short * * ppwchType, int * pcchType ) {
		HRESULT _hr = raw_getTypeFromName(pwchUri, cchUri, pwchLocalName, cchLocalName, ppwchType, pcchType);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(ISAXAttributes));
		return _hr;
	}

	HRESULT ISAXAttributes::getTypeFromQName ( unsigned short * pwchQName, int cchQName, unsigned short * * ppwchType, int * pcchType ) {
		HRESULT _hr = raw_getTypeFromQName(pwchQName, cchQName, ppwchType, pcchType);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(ISAXAttributes));
		return _hr;
	}

	HRESULT ISAXAttributes::getValue ( int nIndex, unsigned short * * ppwchValue, int * pcchValue ) {
		HRESULT _hr = raw_getValue(nIndex, ppwchValue, pcchValue);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(ISAXAttributes));
		return _hr;
	}

	HRESULT ISAXAttributes::getValueFromName ( unsigned short * pwchUri, int cchUri, unsigned short * pwchLocalName, int cchLocalName, unsigned short * * ppwchValue, int * pcchValue ) {
		HRESULT _hr = raw_getValueFromName(pwchUri, cchUri, pwchLocalName, cchLocalName, ppwchValue, pcchValue);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(ISAXAttributes));
		return _hr;
	}

	HRESULT ISAXAttributes::getValueFromQName ( unsigned short * pwchQName, int cchQName, unsigned short * * ppwchValue, int * pcchValue ) {
		HRESULT _hr = raw_getValueFromQName(pwchQName, cchQName, ppwchValue, pcchValue);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(ISAXAttributes));
		return _hr;
	}

	//
	// interface ISAXContentHandler wrapper method implementations
	//

	HRESULT ISAXContentHandler::putDocumentLocator ( struct ISAXLocator * pLocator ) {
		HRESULT _hr = raw_putDocumentLocator(pLocator);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(ISAXContentHandler));
		return _hr;
	}

	HRESULT ISAXContentHandler::startDocument ( ) {
		HRESULT _hr = raw_startDocument();
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(ISAXContentHandler));
		return _hr;
	}

	HRESULT ISAXContentHandler::endDocument ( ) {
		HRESULT _hr = raw_endDocument();
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(ISAXContentHandler));
		return _hr;
	}

	HRESULT ISAXContentHandler::startPrefixMapping ( unsigned short * pwchPrefix, int cchPrefix, unsigned short * pwchUri, int cchUri ) {
		HRESULT _hr = raw_startPrefixMapping(pwchPrefix, cchPrefix, pwchUri, cchUri);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(ISAXContentHandler));
		return _hr;
	}

	HRESULT ISAXContentHandler::endPrefixMapping ( unsigned short * pwchPrefix, int cchPrefix ) {
		HRESULT _hr = raw_endPrefixMapping(pwchPrefix, cchPrefix);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(ISAXContentHandler));
		return _hr;
	}

	HRESULT ISAXContentHandler::startElement ( unsigned short * pwchNamespaceUri, int cchNamespaceUri, unsigned short * pwchLocalName, int cchLocalName, unsigned short * pwchQName, int cchQName, struct ISAXAttributes * pAttributes ) {
		HRESULT _hr = raw_startElement(pwchNamespaceUri, cchNamespaceUri, pwchLocalName, cchLocalName, pwchQName, cchQName, pAttributes);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(ISAXContentHandler));
		return _hr;
	}

	HRESULT ISAXContentHandler::endElement ( unsigned short * pwchNamespaceUri, int cchNamespaceUri, unsigned short * pwchLocalName, int cchLocalName, unsigned short * pwchQName, int cchQName ) {
		HRESULT _hr = raw_endElement(pwchNamespaceUri, cchNamespaceUri, pwchLocalName, cchLocalName, pwchQName, cchQName);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(ISAXContentHandler));
		return _hr;
	}

	HRESULT ISAXContentHandler::characters ( unsigned short * pwchChars, int cchChars ) {
		HRESULT _hr = raw_characters(pwchChars, cchChars);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(ISAXContentHandler));
		return _hr;
	}

	HRESULT ISAXContentHandler::ignorableWhitespace ( unsigned short * pwchChars, int cchChars ) {
		HRESULT _hr = raw_ignorableWhitespace(pwchChars, cchChars);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(ISAXContentHandler));
		return _hr;
	}

	HRESULT ISAXContentHandler::processingInstruction ( unsigned short * pwchTarget, int cchTarget, unsigned short * pwchData, int cchData ) {
		HRESULT _hr = raw_processingInstruction(pwchTarget, cchTarget, pwchData, cchData);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(ISAXContentHandler));
		return _hr;
	}

	HRESULT ISAXContentHandler::skippedEntity ( unsigned short * pwchName, int cchName ) {
		HRESULT _hr = raw_skippedEntity(pwchName, cchName);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(ISAXContentHandler));
		return _hr;
	}

	//
	// interface ISAXDTDHandler wrapper method implementations
	//

	HRESULT ISAXDTDHandler::notationDecl ( unsigned short * pwchName, int cchName, unsigned short * pwchPublicId, int cchPublicId, unsigned short * pwchSystemId, int cchSystemId ) {
		HRESULT _hr = raw_notationDecl(pwchName, cchName, pwchPublicId, cchPublicId, pwchSystemId, cchSystemId);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(ISAXDTDHandler));
		return _hr;
	}

	HRESULT ISAXDTDHandler::unparsedEntityDecl ( unsigned short * pwchName, int cchName, unsigned short * pwchPublicId, int cchPublicId, unsigned short * pwchSystemId, int cchSystemId, unsigned short * pwchNotationName, int cchNotationName ) {
		HRESULT _hr = raw_unparsedEntityDecl(pwchName, cchName, pwchPublicId, cchPublicId, pwchSystemId, cchSystemId, pwchNotationName, cchNotationName);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(ISAXDTDHandler));
		return _hr;
	}

	//
	// interface ISAXErrorHandler wrapper method implementations
	//

	HRESULT ISAXErrorHandler::error ( struct ISAXLocator * pLocator, unsigned short * pwchErrorMessage, HRESULT hrErrorCode ) {
		HRESULT _hr = raw_error(pLocator, pwchErrorMessage, hrErrorCode);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(ISAXErrorHandler));
		return _hr;
	}

	HRESULT ISAXErrorHandler::fatalError ( struct ISAXLocator * pLocator, unsigned short * pwchErrorMessage, HRESULT hrErrorCode ) {
		HRESULT _hr = raw_fatalError(pLocator, pwchErrorMessage, hrErrorCode);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(ISAXErrorHandler));
		return _hr;
	}

	HRESULT ISAXErrorHandler::ignorableWarning ( struct ISAXLocator * pLocator, unsigned short * pwchErrorMessage, HRESULT hrErrorCode ) {
		HRESULT _hr = raw_ignorableWarning(pLocator, pwchErrorMessage, hrErrorCode);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(ISAXErrorHandler));
		return _hr;
	}

	//
	// interface ISAXXMLReader wrapper method implementations
	//

	VARIANT_BOOL ISAXXMLReader::getFeature ( unsigned short * pwchName ) {
		VARIANT_BOOL _result = 0;
		HRESULT _hr = raw_getFeature(pwchName, &_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(ISAXXMLReader));
		return _result;
	}

	HRESULT ISAXXMLReader::putFeature ( unsigned short * pwchName, VARIANT_BOOL vfValue ) {
		HRESULT _hr = raw_putFeature(pwchName, vfValue);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(ISAXXMLReader));
		return _hr;
	}

	_variant_t ISAXXMLReader::getProperty ( unsigned short * pwchName ) {
		VARIANT _result;
		VariantInit(&_result);
		HRESULT _hr = raw_getProperty(pwchName, &_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(ISAXXMLReader));
		return _variant_t(_result, false);
	}

	HRESULT ISAXXMLReader::putProperty ( unsigned short * pwchName, const _variant_t & varValue ) {
		HRESULT _hr = raw_putProperty(pwchName, varValue);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(ISAXXMLReader));
		return _hr;
	}

	ISAXEntityResolverPtr ISAXXMLReader::getEntityResolver ( ) {
		struct ISAXEntityResolver * _result = 0;
		HRESULT _hr = raw_getEntityResolver(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(ISAXXMLReader));
		return ISAXEntityResolverPtr(_result, false);
	}

	HRESULT ISAXXMLReader::putEntityResolver ( struct ISAXEntityResolver * pResolver ) {
		HRESULT _hr = raw_putEntityResolver(pResolver);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(ISAXXMLReader));
		return _hr;
	}

	ISAXContentHandlerPtr ISAXXMLReader::getContentHandler ( ) {
		struct ISAXContentHandler * _result = 0;
		HRESULT _hr = raw_getContentHandler(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(ISAXXMLReader));
		return ISAXContentHandlerPtr(_result, false);
	}

	HRESULT ISAXXMLReader::putContentHandler ( struct ISAXContentHandler * pHandler ) {
		HRESULT _hr = raw_putContentHandler(pHandler);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(ISAXXMLReader));
		return _hr;
	}

	ISAXDTDHandlerPtr ISAXXMLReader::getDTDHandler ( ) {
		struct ISAXDTDHandler * _result = 0;
		HRESULT _hr = raw_getDTDHandler(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(ISAXXMLReader));
		return ISAXDTDHandlerPtr(_result, false);
	}

	HRESULT ISAXXMLReader::putDTDHandler ( struct ISAXDTDHandler * pHandler ) {
		HRESULT _hr = raw_putDTDHandler(pHandler);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(ISAXXMLReader));
		return _hr;
	}

	ISAXErrorHandlerPtr ISAXXMLReader::getErrorHandler ( ) {
		struct ISAXErrorHandler * _result = 0;
		HRESULT _hr = raw_getErrorHandler(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(ISAXXMLReader));
		return ISAXErrorHandlerPtr(_result, false);
	}

	HRESULT ISAXXMLReader::putErrorHandler ( struct ISAXErrorHandler * pHandler ) {
		HRESULT _hr = raw_putErrorHandler(pHandler);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(ISAXXMLReader));
		return _hr;
	}

	unsigned short * ISAXXMLReader::getBaseURL ( ) {
		unsigned short * _result = 0;
		HRESULT _hr = raw_getBaseURL(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(ISAXXMLReader));
		return _result;
	}

	HRESULT ISAXXMLReader::putBaseURL ( unsigned short * pwchBaseUrl ) {
		HRESULT _hr = raw_putBaseURL(pwchBaseUrl);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(ISAXXMLReader));
		return _hr;
	}

	unsigned short * ISAXXMLReader::getSecureBaseURL ( ) {
		unsigned short * _result = 0;
		HRESULT _hr = raw_getSecureBaseURL(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(ISAXXMLReader));
		return _result;
	}

	HRESULT ISAXXMLReader::putSecureBaseURL ( unsigned short * pwchSecureBaseUrl ) {
		HRESULT _hr = raw_putSecureBaseURL(pwchSecureBaseUrl);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(ISAXXMLReader));
		return _hr;
	}

	HRESULT ISAXXMLReader::parse ( const _variant_t & varInput ) {
		HRESULT _hr = raw_parse(varInput);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(ISAXXMLReader));
		return _hr;
	}

	HRESULT ISAXXMLReader::parseURL ( unsigned short * pwchUrl ) {
		HRESULT _hr = raw_parseURL(pwchUrl);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(ISAXXMLReader));
		return _hr;
	}

	//
	// interface ISAXXMLFilter wrapper method implementations
	//

	ISAXXMLReaderPtr ISAXXMLFilter::getParent ( ) {
		struct ISAXXMLReader * _result = 0;
		HRESULT _hr = raw_getParent(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(ISAXXMLFilter));
		return ISAXXMLReaderPtr(_result, false);
	}

	HRESULT ISAXXMLFilter::putParent ( struct ISAXXMLReader * pReader ) {
		HRESULT _hr = raw_putParent(pReader);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(ISAXXMLFilter));
		return _hr;
	}

	//
	// interface ISAXLexicalHandler wrapper method implementations
	//

	HRESULT ISAXLexicalHandler::startDTD ( unsigned short * pwchName, int cchName, unsigned short * pwchPublicId, int cchPublicId, unsigned short * pwchSystemId, int cchSystemId ) {
		HRESULT _hr = raw_startDTD(pwchName, cchName, pwchPublicId, cchPublicId, pwchSystemId, cchSystemId);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(ISAXLexicalHandler));
		return _hr;
	}

	HRESULT ISAXLexicalHandler::endDTD ( ) {
		HRESULT _hr = raw_endDTD();
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(ISAXLexicalHandler));
		return _hr;
	}

	HRESULT ISAXLexicalHandler::startEntity ( unsigned short * pwchName, int cchName ) {
		HRESULT _hr = raw_startEntity(pwchName, cchName);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(ISAXLexicalHandler));
		return _hr;
	}

	HRESULT ISAXLexicalHandler::endEntity ( unsigned short * pwchName, int cchName ) {
		HRESULT _hr = raw_endEntity(pwchName, cchName);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(ISAXLexicalHandler));
		return _hr;
	}

	HRESULT ISAXLexicalHandler::startCDATA ( ) {
		HRESULT _hr = raw_startCDATA();
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(ISAXLexicalHandler));
		return _hr;
	}

	HRESULT ISAXLexicalHandler::endCDATA ( ) {
		HRESULT _hr = raw_endCDATA();
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(ISAXLexicalHandler));
		return _hr;
	}

	HRESULT ISAXLexicalHandler::comment ( unsigned short * pwchChars, int cchChars ) {
		HRESULT _hr = raw_comment(pwchChars, cchChars);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(ISAXLexicalHandler));
		return _hr;
	}

	//
	// interface ISAXDeclHandler wrapper method implementations
	//

	HRESULT ISAXDeclHandler::elementDecl ( unsigned short * pwchName, int cchName, unsigned short * pwchModel, int cchModel ) {
		HRESULT _hr = raw_elementDecl(pwchName, cchName, pwchModel, cchModel);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(ISAXDeclHandler));
		return _hr;
	}

	HRESULT ISAXDeclHandler::attributeDecl ( unsigned short * pwchElementName, int cchElementName, unsigned short * pwchAttributeName, int cchAttributeName, unsigned short * pwchType, int cchType, unsigned short * pwchValueDefault, int cchValueDefault, unsigned short * pwchValue, int cchValue ) {
		HRESULT _hr = raw_attributeDecl(pwchElementName, cchElementName, pwchAttributeName, cchAttributeName, pwchType, cchType, pwchValueDefault, cchValueDefault, pwchValue, cchValue);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(ISAXDeclHandler));
		return _hr;
	}

	HRESULT ISAXDeclHandler::internalEntityDecl ( unsigned short * pwchName, int cchName, unsigned short * pwchValue, int cchValue ) {
		HRESULT _hr = raw_internalEntityDecl(pwchName, cchName, pwchValue, cchValue);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(ISAXDeclHandler));
		return _hr;
	}

	HRESULT ISAXDeclHandler::externalEntityDecl ( unsigned short * pwchName, int cchName, unsigned short * pwchPublicId, int cchPublicId, unsigned short * pwchSystemId, int cchSystemId ) {
		HRESULT _hr = raw_externalEntityDecl(pwchName, cchName, pwchPublicId, cchPublicId, pwchSystemId, cchSystemId);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(ISAXDeclHandler));
		return _hr;
	}

	//
	// interface IVBSAXEntityResolver wrapper method implementations
	//

	_variant_t IVBSAXEntityResolver::resolveEntity ( BSTR * strPublicId, BSTR * strSystemId ) {
		VARIANT _result;
		VariantInit(&_result);
		HRESULT _hr = raw_resolveEntity(strPublicId, strSystemId, &_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IVBSAXEntityResolver));
		return _variant_t(_result, false);
	}

	//
	// interface IVBSAXLocator wrapper method implementations
	//

	int IVBSAXLocator::GetcolumnNumber ( ) {
		int _result = 0;
		HRESULT _hr = get_columnNumber(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IVBSAXLocator));
		return _result;
	}

	int IVBSAXLocator::GetlineNumber ( ) {
		int _result = 0;
		HRESULT _hr = get_lineNumber(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IVBSAXLocator));
		return _result;
	}

	_bstr_t IVBSAXLocator::GetpublicId ( ) {
		BSTR _result = 0;
		HRESULT _hr = get_publicId(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IVBSAXLocator));
		return _bstr_t(_result, false);
	}

	_bstr_t IVBSAXLocator::GetsystemId ( ) {
		BSTR _result = 0;
		HRESULT _hr = get_systemId(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IVBSAXLocator));
		return _bstr_t(_result, false);
	}

	//
	// interface IVBSAXAttributes wrapper method implementations
	//

	int IVBSAXAttributes::Getlength ( ) {
		int _result = 0;
		HRESULT _hr = get_length(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IVBSAXAttributes));
		return _result;
	}

	_bstr_t IVBSAXAttributes::getURI ( int nIndex ) {
		BSTR _result = 0;
		HRESULT _hr = raw_getURI(nIndex, &_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IVBSAXAttributes));
		return _bstr_t(_result, false);
	}

	_bstr_t IVBSAXAttributes::getLocalName ( int nIndex ) {
		BSTR _result = 0;
		HRESULT _hr = raw_getLocalName(nIndex, &_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IVBSAXAttributes));
		return _bstr_t(_result, false);
	}

	_bstr_t IVBSAXAttributes::getQName ( int nIndex ) {
		BSTR _result = 0;
		HRESULT _hr = raw_getQName(nIndex, &_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IVBSAXAttributes));
		return _bstr_t(_result, false);
	}

	int IVBSAXAttributes::getIndexFromName ( _bstr_t strURI, _bstr_t strLocalName ) {
		int _result = 0;
		HRESULT _hr = raw_getIndexFromName(strURI, strLocalName, &_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IVBSAXAttributes));
		return _result;
	}

	int IVBSAXAttributes::getIndexFromQName ( _bstr_t strQName ) {
		int _result = 0;
		HRESULT _hr = raw_getIndexFromQName(strQName, &_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IVBSAXAttributes));
		return _result;
	}

	_bstr_t IVBSAXAttributes::getType ( int nIndex ) {
		BSTR _result = 0;
		HRESULT _hr = raw_getType(nIndex, &_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IVBSAXAttributes));
		return _bstr_t(_result, false);
	}

	_bstr_t IVBSAXAttributes::getTypeFromName ( _bstr_t strURI, _bstr_t strLocalName ) {
		BSTR _result = 0;
		HRESULT _hr = raw_getTypeFromName(strURI, strLocalName, &_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IVBSAXAttributes));
		return _bstr_t(_result, false);
	}

	_bstr_t IVBSAXAttributes::getTypeFromQName ( _bstr_t strQName ) {
		BSTR _result = 0;
		HRESULT _hr = raw_getTypeFromQName(strQName, &_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IVBSAXAttributes));
		return _bstr_t(_result, false);
	}

	_bstr_t IVBSAXAttributes::getValue ( int nIndex ) {
		BSTR _result = 0;
		HRESULT _hr = raw_getValue(nIndex, &_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IVBSAXAttributes));
		return _bstr_t(_result, false);
	}

	_bstr_t IVBSAXAttributes::getValueFromName ( _bstr_t strURI, _bstr_t strLocalName ) {
		BSTR _result = 0;
		HRESULT _hr = raw_getValueFromName(strURI, strLocalName, &_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IVBSAXAttributes));
		return _bstr_t(_result, false);
	}

	_bstr_t IVBSAXAttributes::getValueFromQName ( _bstr_t strQName ) {
		BSTR _result = 0;
		HRESULT _hr = raw_getValueFromQName(strQName, &_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IVBSAXAttributes));
		return _bstr_t(_result, false);
	}

	//
	// interface IVBSAXContentHandler wrapper method implementations
	//

	void IVBSAXContentHandler::PutRefdocumentLocator ( struct IVBSAXLocator * _arg1 ) {
		HRESULT _hr = putref_documentLocator(_arg1);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IVBSAXContentHandler));
	}

	HRESULT IVBSAXContentHandler::startDocument ( ) {
		HRESULT _hr = raw_startDocument();
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IVBSAXContentHandler));
		return _hr;
	}

	HRESULT IVBSAXContentHandler::endDocument ( ) {
		HRESULT _hr = raw_endDocument();
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IVBSAXContentHandler));
		return _hr;
	}

	HRESULT IVBSAXContentHandler::startPrefixMapping ( BSTR * strPrefix, BSTR * strURI ) {
		HRESULT _hr = raw_startPrefixMapping(strPrefix, strURI);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IVBSAXContentHandler));
		return _hr;
	}

	HRESULT IVBSAXContentHandler::endPrefixMapping ( BSTR * strPrefix ) {
		HRESULT _hr = raw_endPrefixMapping(strPrefix);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IVBSAXContentHandler));
		return _hr;
	}

	HRESULT IVBSAXContentHandler::startElement ( BSTR * strNamespaceURI, BSTR * strLocalName, BSTR * strQName, struct IVBSAXAttributes * oAttributes ) {
		HRESULT _hr = raw_startElement(strNamespaceURI, strLocalName, strQName, oAttributes);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IVBSAXContentHandler));
		return _hr;
	}

	HRESULT IVBSAXContentHandler::endElement ( BSTR * strNamespaceURI, BSTR * strLocalName, BSTR * strQName ) {
		HRESULT _hr = raw_endElement(strNamespaceURI, strLocalName, strQName);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IVBSAXContentHandler));
		return _hr;
	}

	HRESULT IVBSAXContentHandler::characters ( BSTR * strChars ) {
		HRESULT _hr = raw_characters(strChars);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IVBSAXContentHandler));
		return _hr;
	}

	HRESULT IVBSAXContentHandler::ignorableWhitespace ( BSTR * strChars ) {
		HRESULT _hr = raw_ignorableWhitespace(strChars);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IVBSAXContentHandler));
		return _hr;
	}

	HRESULT IVBSAXContentHandler::processingInstruction ( BSTR * strTarget, BSTR * strData ) {
		HRESULT _hr = raw_processingInstruction(strTarget, strData);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IVBSAXContentHandler));
		return _hr;
	}

	HRESULT IVBSAXContentHandler::skippedEntity ( BSTR * strName ) {
		HRESULT _hr = raw_skippedEntity(strName);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IVBSAXContentHandler));
		return _hr;
	}

	//
	// interface IVBSAXDTDHandler wrapper method implementations
	//

	HRESULT IVBSAXDTDHandler::notationDecl ( BSTR * strName, BSTR * strPublicId, BSTR * strSystemId ) {
		HRESULT _hr = raw_notationDecl(strName, strPublicId, strSystemId);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IVBSAXDTDHandler));
		return _hr;
	}

	HRESULT IVBSAXDTDHandler::unparsedEntityDecl ( BSTR * strName, BSTR * strPublicId, BSTR * strSystemId, BSTR * strNotationName ) {
		HRESULT _hr = raw_unparsedEntityDecl(strName, strPublicId, strSystemId, strNotationName);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IVBSAXDTDHandler));
		return _hr;
	}

	//
	// interface IVBSAXErrorHandler wrapper method implementations
	//

	HRESULT IVBSAXErrorHandler::error ( struct IVBSAXLocator * oLocator, BSTR * strErrorMessage, long nErrorCode ) {
		HRESULT _hr = raw_error(oLocator, strErrorMessage, nErrorCode);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IVBSAXErrorHandler));
		return _hr;
	}

	HRESULT IVBSAXErrorHandler::fatalError ( struct IVBSAXLocator * oLocator, BSTR * strErrorMessage, long nErrorCode ) {
		HRESULT _hr = raw_fatalError(oLocator, strErrorMessage, nErrorCode);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IVBSAXErrorHandler));
		return _hr;
	}

	HRESULT IVBSAXErrorHandler::ignorableWarning ( struct IVBSAXLocator * oLocator, BSTR * strErrorMessage, long nErrorCode ) {
		HRESULT _hr = raw_ignorableWarning(oLocator, strErrorMessage, nErrorCode);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IVBSAXErrorHandler));
		return _hr;
	}

	//
	// interface IVBSAXXMLReader wrapper method implementations
	//

	VARIANT_BOOL IVBSAXXMLReader::getFeature ( _bstr_t strName ) {
		VARIANT_BOOL _result = 0;
		HRESULT _hr = raw_getFeature(strName, &_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IVBSAXXMLReader));
		return _result;
	}

	HRESULT IVBSAXXMLReader::putFeature ( _bstr_t strName, VARIANT_BOOL fValue ) {
		HRESULT _hr = raw_putFeature(strName, fValue);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IVBSAXXMLReader));
		return _hr;
	}

	_variant_t IVBSAXXMLReader::getProperty ( _bstr_t strName ) {
		VARIANT _result;
		VariantInit(&_result);
		HRESULT _hr = raw_getProperty(strName, &_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IVBSAXXMLReader));
		return _variant_t(_result, false);
	}

	HRESULT IVBSAXXMLReader::putProperty ( _bstr_t strName, const _variant_t & varValue ) {
		HRESULT _hr = raw_putProperty(strName, varValue);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IVBSAXXMLReader));
		return _hr;
	}

	IVBSAXEntityResolverPtr IVBSAXXMLReader::GetentityResolver ( ) {
		struct IVBSAXEntityResolver * _result = 0;
		HRESULT _hr = get_entityResolver(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IVBSAXXMLReader));
		return IVBSAXEntityResolverPtr(_result, false);
	}

	void IVBSAXXMLReader::PutRefentityResolver ( struct IVBSAXEntityResolver * oResolver ) {
		HRESULT _hr = putref_entityResolver(oResolver);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IVBSAXXMLReader));
	}

	IVBSAXContentHandlerPtr IVBSAXXMLReader::GetcontentHandler ( ) {
		struct IVBSAXContentHandler * _result = 0;
		HRESULT _hr = get_contentHandler(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IVBSAXXMLReader));
		return IVBSAXContentHandlerPtr(_result, false);
	}

	void IVBSAXXMLReader::PutRefcontentHandler ( struct IVBSAXContentHandler * oHandler ) {
		HRESULT _hr = putref_contentHandler(oHandler);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IVBSAXXMLReader));
	}

	IVBSAXDTDHandlerPtr IVBSAXXMLReader::GetdtdHandler ( ) {
		struct IVBSAXDTDHandler * _result = 0;
		HRESULT _hr = get_dtdHandler(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IVBSAXXMLReader));
		return IVBSAXDTDHandlerPtr(_result, false);
	}

	void IVBSAXXMLReader::PutRefdtdHandler ( struct IVBSAXDTDHandler * oHandler ) {
		HRESULT _hr = putref_dtdHandler(oHandler);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IVBSAXXMLReader));
	}

	IVBSAXErrorHandlerPtr IVBSAXXMLReader::GeterrorHandler ( ) {
		struct IVBSAXErrorHandler * _result = 0;
		HRESULT _hr = get_errorHandler(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IVBSAXXMLReader));
		return IVBSAXErrorHandlerPtr(_result, false);
	}

	void IVBSAXXMLReader::PutReferrorHandler ( struct IVBSAXErrorHandler * oHandler ) {
		HRESULT _hr = putref_errorHandler(oHandler);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IVBSAXXMLReader));
	}

	_bstr_t IVBSAXXMLReader::GetbaseURL ( ) {
		BSTR _result = 0;
		HRESULT _hr = get_baseURL(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IVBSAXXMLReader));
		return _bstr_t(_result, false);
	}

	void IVBSAXXMLReader::PutbaseURL ( _bstr_t strBaseURL ) {
		HRESULT _hr = put_baseURL(strBaseURL);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IVBSAXXMLReader));
	}

	_bstr_t IVBSAXXMLReader::GetsecureBaseURL ( ) {
		BSTR _result = 0;
		HRESULT _hr = get_secureBaseURL(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IVBSAXXMLReader));
		return _bstr_t(_result, false);
	}

	void IVBSAXXMLReader::PutsecureBaseURL ( _bstr_t strSecureBaseURL ) {
		HRESULT _hr = put_secureBaseURL(strSecureBaseURL);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IVBSAXXMLReader));
	}

	HRESULT IVBSAXXMLReader::parse ( const _variant_t & varInput ) {
		HRESULT _hr = raw_parse(varInput);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IVBSAXXMLReader));
		return _hr;
	}

	HRESULT IVBSAXXMLReader::parseURL ( _bstr_t strURL ) {
		HRESULT _hr = raw_parseURL(strURL);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IVBSAXXMLReader));
		return _hr;
	}

	//
	// interface IVBSAXXMLFilter wrapper method implementations
	//

	IVBSAXXMLReaderPtr IVBSAXXMLFilter::Getparent ( ) {
		struct IVBSAXXMLReader * _result = 0;
		HRESULT _hr = get_parent(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IVBSAXXMLFilter));
		return IVBSAXXMLReaderPtr(_result, false);
	}

	void IVBSAXXMLFilter::PutRefparent ( struct IVBSAXXMLReader * oReader ) {
		HRESULT _hr = putref_parent(oReader);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IVBSAXXMLFilter));
	}

	//
	// interface IVBSAXLexicalHandler wrapper method implementations
	//

	HRESULT IVBSAXLexicalHandler::startDTD ( BSTR * strName, BSTR * strPublicId, BSTR * strSystemId ) {
		HRESULT _hr = raw_startDTD(strName, strPublicId, strSystemId);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IVBSAXLexicalHandler));
		return _hr;
	}

	HRESULT IVBSAXLexicalHandler::endDTD ( ) {
		HRESULT _hr = raw_endDTD();
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IVBSAXLexicalHandler));
		return _hr;
	}

	HRESULT IVBSAXLexicalHandler::startEntity ( BSTR * strName ) {
		HRESULT _hr = raw_startEntity(strName);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IVBSAXLexicalHandler));
		return _hr;
	}

	HRESULT IVBSAXLexicalHandler::endEntity ( BSTR * strName ) {
		HRESULT _hr = raw_endEntity(strName);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IVBSAXLexicalHandler));
		return _hr;
	}

	HRESULT IVBSAXLexicalHandler::startCDATA ( ) {
		HRESULT _hr = raw_startCDATA();
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IVBSAXLexicalHandler));
		return _hr;
	}

	HRESULT IVBSAXLexicalHandler::endCDATA ( ) {
		HRESULT _hr = raw_endCDATA();
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IVBSAXLexicalHandler));
		return _hr;
	}

	HRESULT IVBSAXLexicalHandler::comment ( BSTR * strChars ) {
		HRESULT _hr = raw_comment(strChars);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IVBSAXLexicalHandler));
		return _hr;
	}

	//
	// interface IVBSAXDeclHandler wrapper method implementations
	//

	HRESULT IVBSAXDeclHandler::elementDecl ( BSTR * strName, BSTR * strModel ) {
		HRESULT _hr = raw_elementDecl(strName, strModel);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IVBSAXDeclHandler));
		return _hr;
	}

	HRESULT IVBSAXDeclHandler::attributeDecl ( BSTR * strElementName, BSTR * strAttributeName, BSTR * strType, BSTR * strValueDefault, BSTR * strValue ) {
		HRESULT _hr = raw_attributeDecl(strElementName, strAttributeName, strType, strValueDefault, strValue);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IVBSAXDeclHandler));
		return _hr;
	}

	HRESULT IVBSAXDeclHandler::internalEntityDecl ( BSTR * strName, BSTR * strValue ) {
		HRESULT _hr = raw_internalEntityDecl(strName, strValue);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IVBSAXDeclHandler));
		return _hr;
	}

	HRESULT IVBSAXDeclHandler::externalEntityDecl ( BSTR * strName, BSTR * strPublicId, BSTR * strSystemId ) {
		HRESULT _hr = raw_externalEntityDecl(strName, strPublicId, strSystemId);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IVBSAXDeclHandler));
		return _hr;
	}

	//
	// interface IMXWriter wrapper method implementations
	//

	void IMXWriter::Putoutput ( const _variant_t & varDestination ) {
		HRESULT _hr = put_output(varDestination);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IMXWriter));
	}

	_variant_t IMXWriter::Getoutput ( ) {
		VARIANT _result;
		VariantInit(&_result);
		HRESULT _hr = get_output(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IMXWriter));
		return _variant_t(_result, false);
	}

	void IMXWriter::Putencoding ( _bstr_t strEncoding ) {
		HRESULT _hr = put_encoding(strEncoding);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IMXWriter));
	}

	_bstr_t IMXWriter::Getencoding ( ) {
		BSTR _result = 0;
		HRESULT _hr = get_encoding(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IMXWriter));
		return _bstr_t(_result, false);
	}

	void IMXWriter::PutbyteOrderMark ( VARIANT_BOOL fWriteByteOrderMark ) {
		HRESULT _hr = put_byteOrderMark(fWriteByteOrderMark);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IMXWriter));
	}

	VARIANT_BOOL IMXWriter::GetbyteOrderMark ( ) {
		VARIANT_BOOL _result = 0;
		HRESULT _hr = get_byteOrderMark(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IMXWriter));
		return _result;
	}

	void IMXWriter::Putindent ( VARIANT_BOOL fIndentMode ) {
		HRESULT _hr = put_indent(fIndentMode);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IMXWriter));
	}

	VARIANT_BOOL IMXWriter::Getindent ( ) {
		VARIANT_BOOL _result = 0;
		HRESULT _hr = get_indent(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IMXWriter));
		return _result;
	}

	void IMXWriter::Putstandalone ( VARIANT_BOOL fValue ) {
		HRESULT _hr = put_standalone(fValue);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IMXWriter));
	}

	VARIANT_BOOL IMXWriter::Getstandalone ( ) {
		VARIANT_BOOL _result = 0;
		HRESULT _hr = get_standalone(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IMXWriter));
		return _result;
	}

	void IMXWriter::PutomitXMLDeclaration ( VARIANT_BOOL fValue ) {
		HRESULT _hr = put_omitXMLDeclaration(fValue);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IMXWriter));
	}

	VARIANT_BOOL IMXWriter::GetomitXMLDeclaration ( ) {
		VARIANT_BOOL _result = 0;
		HRESULT _hr = get_omitXMLDeclaration(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IMXWriter));
		return _result;
	}

	void IMXWriter::Putversion ( _bstr_t strVersion ) {
		HRESULT _hr = put_version(strVersion);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IMXWriter));
	}

	_bstr_t IMXWriter::Getversion ( ) {
		BSTR _result = 0;
		HRESULT _hr = get_version(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IMXWriter));
		return _bstr_t(_result, false);
	}

	void IMXWriter::PutdisableOutputEscaping ( VARIANT_BOOL fValue ) {
		HRESULT _hr = put_disableOutputEscaping(fValue);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IMXWriter));
	}

	VARIANT_BOOL IMXWriter::GetdisableOutputEscaping ( ) {
		VARIANT_BOOL _result = 0;
		HRESULT _hr = get_disableOutputEscaping(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IMXWriter));
		return _result;
	}

	HRESULT IMXWriter::flush ( ) {
		HRESULT _hr = raw_flush();
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IMXWriter));
		return _hr;
	}

	//
	// interface IMXAttributes wrapper method implementations
	//

	HRESULT IMXAttributes::addAttribute ( _bstr_t strURI, _bstr_t strLocalName, _bstr_t strQName, _bstr_t strType, _bstr_t strValue ) {
		HRESULT _hr = raw_addAttribute(strURI, strLocalName, strQName, strType, strValue);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IMXAttributes));
		return _hr;
	}

	HRESULT IMXAttributes::addAttributeFromIndex ( const _variant_t & varAtts, int nIndex ) {
		HRESULT _hr = raw_addAttributeFromIndex(varAtts, nIndex);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IMXAttributes));
		return _hr;
	}

	HRESULT IMXAttributes::clear ( ) {
		HRESULT _hr = raw_clear();
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IMXAttributes));
		return _hr;
	}

	HRESULT IMXAttributes::removeAttribute ( int nIndex ) {
		HRESULT _hr = raw_removeAttribute(nIndex);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IMXAttributes));
		return _hr;
	}

	HRESULT IMXAttributes::setAttribute ( int nIndex, _bstr_t strURI, _bstr_t strLocalName, _bstr_t strQName, _bstr_t strType, _bstr_t strValue ) {
		HRESULT _hr = raw_setAttribute(nIndex, strURI, strLocalName, strQName, strType, strValue);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IMXAttributes));
		return _hr;
	}

	HRESULT IMXAttributes::setAttributes ( const _variant_t & varAtts ) {
		HRESULT _hr = raw_setAttributes(varAtts);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IMXAttributes));
		return _hr;
	}

	HRESULT IMXAttributes::setLocalName ( int nIndex, _bstr_t strLocalName ) {
		HRESULT _hr = raw_setLocalName(nIndex, strLocalName);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IMXAttributes));
		return _hr;
	}

	HRESULT IMXAttributes::setQName ( int nIndex, _bstr_t strQName ) {
		HRESULT _hr = raw_setQName(nIndex, strQName);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IMXAttributes));
		return _hr;
	}

	HRESULT IMXAttributes::setType ( int nIndex, _bstr_t strType ) {
		HRESULT _hr = raw_setType(nIndex, strType);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IMXAttributes));
		return _hr;
	}

	HRESULT IMXAttributes::setURI ( int nIndex, _bstr_t strURI ) {
		HRESULT _hr = raw_setURI(nIndex, strURI);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IMXAttributes));
		return _hr;
	}

	HRESULT IMXAttributes::setValue ( int nIndex, _bstr_t strValue ) {
		HRESULT _hr = raw_setValue(nIndex, strValue);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IMXAttributes));
		return _hr;
	}

	//
	// interface IMXReaderControl wrapper method implementations
	//

	HRESULT IMXReaderControl::abort ( ) {
		HRESULT _hr = raw_abort();
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IMXReaderControl));
		return _hr;
	}

	HRESULT IMXReaderControl::resume ( ) {
		HRESULT _hr = raw_resume();
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IMXReaderControl));
		return _hr;
	}

	HRESULT IMXReaderControl::suspend ( ) {
		HRESULT _hr = raw_suspend();
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IMXReaderControl));
		return _hr;
	}

	//
	// interface ISchemaStringCollection wrapper method implementations
	//

	_bstr_t ISchemaStringCollection::Getitem ( long index ) {
		BSTR _result = 0;
		HRESULT _hr = get_item(index, &_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(ISchemaStringCollection));
		return _bstr_t(_result, false);
	}

	long ISchemaStringCollection::Getlength ( ) {
		long _result = 0;
		HRESULT _hr = get_length(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(ISchemaStringCollection));
		return _result;
	}

	IUnknownPtr ISchemaStringCollection::Get_newEnum ( ) {
		IUnknown * _result = 0;
		HRESULT _hr = get__newEnum(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(ISchemaStringCollection));
		return IUnknownPtr(_result, false);
	}

	//
	// interface IMXXMLFilter wrapper method implementations
	//

	VARIANT_BOOL IMXXMLFilter::getFeature ( _bstr_t strName ) {
		VARIANT_BOOL _result = 0;
		HRESULT _hr = raw_getFeature(strName, &_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IMXXMLFilter));
		return _result;
	}

	HRESULT IMXXMLFilter::putFeature ( _bstr_t strName, VARIANT_BOOL fValue ) {
		HRESULT _hr = raw_putFeature(strName, fValue);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IMXXMLFilter));
		return _hr;
	}

	_variant_t IMXXMLFilter::getProperty ( _bstr_t strName ) {
		VARIANT _result;
		VariantInit(&_result);
		HRESULT _hr = raw_getProperty(strName, &_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IMXXMLFilter));
		return _variant_t(_result, false);
	}

	HRESULT IMXXMLFilter::putProperty ( _bstr_t strName, const _variant_t & varValue ) {
		HRESULT _hr = raw_putProperty(strName, varValue);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IMXXMLFilter));
		return _hr;
	}

	IUnknownPtr IMXXMLFilter::GetentityResolver ( ) {
		IUnknown * _result = 0;
		HRESULT _hr = get_entityResolver(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IMXXMLFilter));
		return IUnknownPtr(_result, false);
	}

	void IMXXMLFilter::PutRefentityResolver ( IUnknown * oResolver ) {
		HRESULT _hr = putref_entityResolver(oResolver);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IMXXMLFilter));
	}

	IUnknownPtr IMXXMLFilter::GetcontentHandler ( ) {
		IUnknown * _result = 0;
		HRESULT _hr = get_contentHandler(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IMXXMLFilter));
		return IUnknownPtr(_result, false);
	}

	void IMXXMLFilter::PutRefcontentHandler ( IUnknown * oHandler ) {
		HRESULT _hr = putref_contentHandler(oHandler);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IMXXMLFilter));
	}

	IUnknownPtr IMXXMLFilter::GetdtdHandler ( ) {
		IUnknown * _result = 0;
		HRESULT _hr = get_dtdHandler(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IMXXMLFilter));
		return IUnknownPtr(_result, false);
	}

	void IMXXMLFilter::PutRefdtdHandler ( IUnknown * oHandler ) {
		HRESULT _hr = putref_dtdHandler(oHandler);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IMXXMLFilter));
	}

	IUnknownPtr IMXXMLFilter::GeterrorHandler ( ) {
		IUnknown * _result = 0;
		HRESULT _hr = get_errorHandler(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IMXXMLFilter));
		return IUnknownPtr(_result, false);
	}

	void IMXXMLFilter::PutReferrorHandler ( IUnknown * oHandler ) {
		HRESULT _hr = putref_errorHandler(oHandler);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IMXXMLFilter));
	}

	//
	// interface IXMLElementCollection wrapper method implementations
	//

	void IXMLElementCollection::Putlength ( long p ) {
		HRESULT _hr = put_length(p);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IXMLElementCollection));
	}

	long IXMLElementCollection::Getlength ( ) {
		long _result = 0;
		HRESULT _hr = get_length(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IXMLElementCollection));
		return _result;
	}

	IUnknownPtr IXMLElementCollection::Get_newEnum ( ) {
		IUnknown * _result = 0;
		HRESULT _hr = get__newEnum(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IXMLElementCollection));
		return IUnknownPtr(_result, false);
	}

	IDispatchPtr IXMLElementCollection::item ( const _variant_t & var1, const _variant_t & var2 ) {
		IDispatch * _result = 0;
		HRESULT _hr = raw_item(var1, var2, &_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IXMLElementCollection));
		return IDispatchPtr(_result, false);
	}

	//
	// interface IXMLElement wrapper method implementations
	//

	_bstr_t IXMLElement::GettagName ( ) {
		BSTR _result = 0;
		HRESULT _hr = get_tagName(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IXMLElement));
		return _bstr_t(_result, false);
	}

	void IXMLElement::PuttagName ( _bstr_t p ) {
		HRESULT _hr = put_tagName(p);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IXMLElement));
	}

	IXMLElementPtr IXMLElement::Getparent ( ) {
		struct IXMLElement * _result = 0;
		HRESULT _hr = get_parent(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IXMLElement));
		return IXMLElementPtr(_result, false);
	}

	HRESULT IXMLElement::setAttribute ( _bstr_t strPropertyName, const _variant_t & PropertyValue ) {
		HRESULT _hr = raw_setAttribute(strPropertyName, PropertyValue);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IXMLElement));
		return _hr;
	}

	_variant_t IXMLElement::getAttribute ( _bstr_t strPropertyName ) {
		VARIANT _result;
		VariantInit(&_result);
		HRESULT _hr = raw_getAttribute(strPropertyName, &_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IXMLElement));
		return _variant_t(_result, false);
	}

	HRESULT IXMLElement::removeAttribute ( _bstr_t strPropertyName ) {
		HRESULT _hr = raw_removeAttribute(strPropertyName);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IXMLElement));
		return _hr;
	}

	IXMLElementCollectionPtr IXMLElement::Getchildren ( ) {
		struct IXMLElementCollection * _result = 0;
		HRESULT _hr = get_children(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IXMLElement));
		return IXMLElementCollectionPtr(_result, false);
	}

	long IXMLElement::Gettype ( ) {
		long _result = 0;
		HRESULT _hr = get_type(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IXMLElement));
		return _result;
	}

	_bstr_t IXMLElement::Gettext ( ) {
		BSTR _result = 0;
		HRESULT _hr = get_text(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IXMLElement));
		return _bstr_t(_result, false);
	}

	void IXMLElement::Puttext ( _bstr_t p ) {
		HRESULT _hr = put_text(p);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IXMLElement));
	}

	HRESULT IXMLElement::addChild ( struct IXMLElement * pChildElem, long lIndex, long lReserved ) {
		HRESULT _hr = raw_addChild(pChildElem, lIndex, lReserved);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IXMLElement));
		return _hr;
	}

	HRESULT IXMLElement::removeChild ( struct IXMLElement * pChildElem ) {
		HRESULT _hr = raw_removeChild(pChildElem);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IXMLElement));
		return _hr;
	}

	//
	// interface IXMLDocument wrapper method implementations
	//

	IXMLElementPtr IXMLDocument::Getroot ( ) {
		struct IXMLElement * _result = 0;
		HRESULT _hr = get_root(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IXMLDocument));
		return IXMLElementPtr(_result, false);
	}

	_bstr_t IXMLDocument::GetfileSize ( ) {
		BSTR _result = 0;
		HRESULT _hr = get_fileSize(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IXMLDocument));
		return _bstr_t(_result, false);
	}

	_bstr_t IXMLDocument::GetfileModifiedDate ( ) {
		BSTR _result = 0;
		HRESULT _hr = get_fileModifiedDate(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IXMLDocument));
		return _bstr_t(_result, false);
	}

	_bstr_t IXMLDocument::GetfileUpdatedDate ( ) {
		BSTR _result = 0;
		HRESULT _hr = get_fileUpdatedDate(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IXMLDocument));
		return _bstr_t(_result, false);
	}

	_bstr_t IXMLDocument::Geturl ( ) {
		BSTR _result = 0;
		HRESULT _hr = get_url(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IXMLDocument));
		return _bstr_t(_result, false);
	}

	void IXMLDocument::Puturl ( _bstr_t p ) {
		HRESULT _hr = put_url(p);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IXMLDocument));
	}

	_bstr_t IXMLDocument::GetmimeType ( ) {
		BSTR _result = 0;
		HRESULT _hr = get_mimeType(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IXMLDocument));
		return _bstr_t(_result, false);
	}

	long IXMLDocument::GetreadyState ( ) {
		long _result = 0;
		HRESULT _hr = get_readyState(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IXMLDocument));
		return _result;
	}

	_bstr_t IXMLDocument::Getcharset ( ) {
		BSTR _result = 0;
		HRESULT _hr = get_charset(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IXMLDocument));
		return _bstr_t(_result, false);
	}

	void IXMLDocument::Putcharset ( _bstr_t p ) {
		HRESULT _hr = put_charset(p);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IXMLDocument));
	}

	_bstr_t IXMLDocument::Getversion ( ) {
		BSTR _result = 0;
		HRESULT _hr = get_version(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IXMLDocument));
		return _bstr_t(_result, false);
	}

	_bstr_t IXMLDocument::Getdoctype ( ) {
		BSTR _result = 0;
		HRESULT _hr = get_doctype(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IXMLDocument));
		return _bstr_t(_result, false);
	}

	_bstr_t IXMLDocument::GetdtdURL ( ) {
		BSTR _result = 0;
		HRESULT _hr = get_dtdURL(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IXMLDocument));
		return _bstr_t(_result, false);
	}

	IXMLElementPtr IXMLDocument::createElement ( const _variant_t & vType, const _variant_t & var1 ) {
		struct IXMLElement * _result = 0;
		HRESULT _hr = raw_createElement(vType, var1, &_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IXMLDocument));
		return IXMLElementPtr(_result, false);
	}

	//
	// interface IXMLElement2 wrapper method implementations
	//

	_bstr_t IXMLElement2::GettagName ( ) {
		BSTR _result = 0;
		HRESULT _hr = get_tagName(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IXMLElement2));
		return _bstr_t(_result, false);
	}

	void IXMLElement2::PuttagName ( _bstr_t p ) {
		HRESULT _hr = put_tagName(p);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IXMLElement2));
	}

	IXMLElement2Ptr IXMLElement2::Getparent ( ) {
		struct IXMLElement2 * _result = 0;
		HRESULT _hr = get_parent(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IXMLElement2));
		return IXMLElement2Ptr(_result, false);
	}

	HRESULT IXMLElement2::setAttribute ( _bstr_t strPropertyName, const _variant_t & PropertyValue ) {
		HRESULT _hr = raw_setAttribute(strPropertyName, PropertyValue);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IXMLElement2));
		return _hr;
	}

	_variant_t IXMLElement2::getAttribute ( _bstr_t strPropertyName ) {
		VARIANT _result;
		VariantInit(&_result);
		HRESULT _hr = raw_getAttribute(strPropertyName, &_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IXMLElement2));
		return _variant_t(_result, false);
	}

	HRESULT IXMLElement2::removeAttribute ( _bstr_t strPropertyName ) {
		HRESULT _hr = raw_removeAttribute(strPropertyName);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IXMLElement2));
		return _hr;
	}

	IXMLElementCollectionPtr IXMLElement2::Getchildren ( ) {
		struct IXMLElementCollection * _result = 0;
		HRESULT _hr = get_children(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IXMLElement2));
		return IXMLElementCollectionPtr(_result, false);
	}

	long IXMLElement2::Gettype ( ) {
		long _result = 0;
		HRESULT _hr = get_type(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IXMLElement2));
		return _result;
	}

	_bstr_t IXMLElement2::Gettext ( ) {
		BSTR _result = 0;
		HRESULT _hr = get_text(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IXMLElement2));
		return _bstr_t(_result, false);
	}

	void IXMLElement2::Puttext ( _bstr_t p ) {
		HRESULT _hr = put_text(p);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IXMLElement2));
	}

	HRESULT IXMLElement2::addChild ( struct IXMLElement2 * pChildElem, long lIndex, long lReserved ) {
		HRESULT _hr = raw_addChild(pChildElem, lIndex, lReserved);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IXMLElement2));
		return _hr;
	}

	HRESULT IXMLElement2::removeChild ( struct IXMLElement2 * pChildElem ) {
		HRESULT _hr = raw_removeChild(pChildElem);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IXMLElement2));
		return _hr;
	}

	IXMLElementCollectionPtr IXMLElement2::Getattributes ( ) {
		struct IXMLElementCollection * _result = 0;
		HRESULT _hr = get_attributes(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IXMLElement2));
		return IXMLElementCollectionPtr(_result, false);
	}

	//
	// interface IXMLDocument2 wrapper method implementations
	//

	IXMLElement2Ptr IXMLDocument2::Getroot ( ) {
		struct IXMLElement2 * _result = 0;
		HRESULT _hr = get_root(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IXMLDocument2));
		return IXMLElement2Ptr(_result, false);
	}

	_bstr_t IXMLDocument2::GetfileSize ( ) {
		BSTR _result = 0;
		HRESULT _hr = get_fileSize(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IXMLDocument2));
		return _bstr_t(_result, false);
	}

	_bstr_t IXMLDocument2::GetfileModifiedDate ( ) {
		BSTR _result = 0;
		HRESULT _hr = get_fileModifiedDate(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IXMLDocument2));
		return _bstr_t(_result, false);
	}

	_bstr_t IXMLDocument2::GetfileUpdatedDate ( ) {
		BSTR _result = 0;
		HRESULT _hr = get_fileUpdatedDate(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IXMLDocument2));
		return _bstr_t(_result, false);
	}

	_bstr_t IXMLDocument2::Geturl ( ) {
		BSTR _result = 0;
		HRESULT _hr = get_url(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IXMLDocument2));
		return _bstr_t(_result, false);
	}

	void IXMLDocument2::Puturl ( _bstr_t p ) {
		HRESULT _hr = put_url(p);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IXMLDocument2));
	}

	_bstr_t IXMLDocument2::GetmimeType ( ) {
		BSTR _result = 0;
		HRESULT _hr = get_mimeType(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IXMLDocument2));
		return _bstr_t(_result, false);
	}

	long IXMLDocument2::GetreadyState ( ) {
		long _result = 0;
		HRESULT _hr = get_readyState(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IXMLDocument2));
		return _result;
	}

	_bstr_t IXMLDocument2::Getcharset ( ) {
		BSTR _result = 0;
		HRESULT _hr = get_charset(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IXMLDocument2));
		return _bstr_t(_result, false);
	}

	void IXMLDocument2::Putcharset ( _bstr_t p ) {
		HRESULT _hr = put_charset(p);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IXMLDocument2));
	}

	_bstr_t IXMLDocument2::Getversion ( ) {
		BSTR _result = 0;
		HRESULT _hr = get_version(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IXMLDocument2));
		return _bstr_t(_result, false);
	}

	_bstr_t IXMLDocument2::Getdoctype ( ) {
		BSTR _result = 0;
		HRESULT _hr = get_doctype(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IXMLDocument2));
		return _bstr_t(_result, false);
	}

	_bstr_t IXMLDocument2::GetdtdURL ( ) {
		BSTR _result = 0;
		HRESULT _hr = get_dtdURL(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IXMLDocument2));
		return _bstr_t(_result, false);
	}

	IXMLElement2Ptr IXMLDocument2::createElement ( const _variant_t & vType, const _variant_t & var1 ) {
		struct IXMLElement2 * _result = 0;
		HRESULT _hr = raw_createElement(vType, var1, &_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IXMLDocument2));
		return IXMLElement2Ptr(_result, false);
	}

	VARIANT_BOOL IXMLDocument2::Getasync ( ) {
		VARIANT_BOOL _result = 0;
		HRESULT _hr = get_async(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IXMLDocument2));
		return _result;
	}

	void IXMLDocument2::Putasync ( VARIANT_BOOL pf ) {
		HRESULT _hr = put_async(pf);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IXMLDocument2));
	}

	//
	// interface IXMLAttribute wrapper method implementations
	//

	_bstr_t IXMLAttribute::Getname ( ) {
		BSTR _result = 0;
		HRESULT _hr = get_name(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IXMLAttribute));
		return _bstr_t(_result, false);
	}

	_bstr_t IXMLAttribute::Getvalue ( ) {
		BSTR _result = 0;
		HRESULT _hr = get_value(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IXMLAttribute));
		return _bstr_t(_result, false);
	}

	//
	// interface IXMLError wrapper method implementations
	//

	HRESULT IXMLError::GetErrorInfo ( struct _xml_error * pErrorReturn ) {
		HRESULT _hr = raw_GetErrorInfo(pErrorReturn);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IXMLError));
		return _hr;
	}

	//
	// dispinterface XMLDOMDocumentEvents wrapper method implementations
	//

	HRESULT XMLDOMDocumentEvents::ondataavailable ( ) {
		HRESULT _result = 0;
		_com_dispatch_method(this, 0xc6, DISPATCH_METHOD, VT_ERROR, (void*)&_result, NULL);
		return _result;
	}

	HRESULT XMLDOMDocumentEvents::onreadystatechange ( ) {
		HRESULT _result = 0;
		_com_dispatch_method(this, DISPID_READYSTATECHANGE, DISPATCH_METHOD, VT_ERROR, (void*)&_result, NULL);
		return _result;
	}

	//
	// interface IXMLHTTPRequest wrapper method implementations
	//

	HRESULT IXMLHTTPRequest::open ( _bstr_t bstrMethod, _bstr_t bstrUrl, const _variant_t & varAsync, const _variant_t & bstrUser, const _variant_t & bstrPassword ) {
		HRESULT _hr = raw_open(bstrMethod, bstrUrl, varAsync, bstrUser, bstrPassword);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IXMLHTTPRequest));
		return _hr;
	}

	HRESULT IXMLHTTPRequest::setRequestHeader ( _bstr_t bstrHeader, _bstr_t bstrValue ) {
		HRESULT _hr = raw_setRequestHeader(bstrHeader, bstrValue);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IXMLHTTPRequest));
		return _hr;
	}

	_bstr_t IXMLHTTPRequest::getResponseHeader ( _bstr_t bstrHeader ) {
		BSTR _result = 0;
		HRESULT _hr = raw_getResponseHeader(bstrHeader, &_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IXMLHTTPRequest));
		return _bstr_t(_result, false);
	}

	_bstr_t IXMLHTTPRequest::getAllResponseHeaders ( ) {
		BSTR _result = 0;
		HRESULT _hr = raw_getAllResponseHeaders(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IXMLHTTPRequest));
		return _bstr_t(_result, false);
	}

	HRESULT IXMLHTTPRequest::send ( const _variant_t & varBody ) {
		HRESULT _hr = raw_send(varBody);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IXMLHTTPRequest));
		return _hr;
	}

	HRESULT IXMLHTTPRequest::abort ( ) {
		HRESULT _hr = raw_abort();
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IXMLHTTPRequest));
		return _hr;
	}

	long IXMLHTTPRequest::Getstatus ( ) {
		long _result = 0;
		HRESULT _hr = get_status(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IXMLHTTPRequest));
		return _result;
	}

	_bstr_t IXMLHTTPRequest::GetstatusText ( ) {
		BSTR _result = 0;
		HRESULT _hr = get_statusText(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IXMLHTTPRequest));
		return _bstr_t(_result, false);
	}

	IDispatchPtr IXMLHTTPRequest::GetresponseXML ( ) {
		IDispatch * _result = 0;
		HRESULT _hr = get_responseXML(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IXMLHTTPRequest));
		return IDispatchPtr(_result, false);
	}

	_bstr_t IXMLHTTPRequest::GetresponseText ( ) {
		BSTR _result = 0;
		HRESULT _hr = get_responseText(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IXMLHTTPRequest));
		return _bstr_t(_result, false);
	}

	_variant_t IXMLHTTPRequest::GetresponseBody ( ) {
		VARIANT _result;
		VariantInit(&_result);
		HRESULT _hr = get_responseBody(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IXMLHTTPRequest));
		return _variant_t(_result, false);
	}

	_variant_t IXMLHTTPRequest::GetresponseStream ( ) {
		VARIANT _result;
		VariantInit(&_result);
		HRESULT _hr = get_responseStream(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IXMLHTTPRequest));
		return _variant_t(_result, false);
	}

	long IXMLHTTPRequest::GetreadyState ( ) {
		long _result = 0;
		HRESULT _hr = get_readyState(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IXMLHTTPRequest));
		return _result;
	}

	void IXMLHTTPRequest::Putonreadystatechange ( IDispatch * _arg1 ) {
		HRESULT _hr = put_onreadystatechange(_arg1);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IXMLHTTPRequest));
	}

	//
	// interface IServerXMLHTTPRequest wrapper method implementations
	//

	HRESULT IServerXMLHTTPRequest::setTimeouts ( long resolveTimeout, long connectTimeout, long sendTimeout, long receiveTimeout ) {
		HRESULT _hr = raw_setTimeouts(resolveTimeout, connectTimeout, sendTimeout, receiveTimeout);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IServerXMLHTTPRequest));
		return _hr;
	}

	VARIANT_BOOL IServerXMLHTTPRequest::waitForResponse ( const _variant_t & timeoutInSeconds ) {
		VARIANT_BOOL _result = 0;
		HRESULT _hr = raw_waitForResponse(timeoutInSeconds, &_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IServerXMLHTTPRequest));
		return _result;
	}

	_variant_t IServerXMLHTTPRequest::getOption ( SERVERXMLHTTP_OPTION option ) {
		VARIANT _result;
		VariantInit(&_result);
		HRESULT _hr = raw_getOption(option, &_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IServerXMLHTTPRequest));
		return _variant_t(_result, false);
	}

	HRESULT IServerXMLHTTPRequest::setOption ( SERVERXMLHTTP_OPTION option, const _variant_t & value ) {
		HRESULT _hr = raw_setOption(option, value);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IServerXMLHTTPRequest));
		return _hr;
	}

	//
	// interface IServerXMLHTTPRequest2 wrapper method implementations
	//

	HRESULT IServerXMLHTTPRequest2::setProxy ( SXH_PROXY_SETTING proxySetting, const _variant_t & varProxyServer, const _variant_t & varBypassList ) {
		HRESULT _hr = raw_setProxy(proxySetting, varProxyServer, varBypassList);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IServerXMLHTTPRequest2));
		return _hr;
	}

	HRESULT IServerXMLHTTPRequest2::setProxyCredentials ( _bstr_t bstrUserName, _bstr_t bstrPassword ) {
		HRESULT _hr = raw_setProxyCredentials(bstrUserName, bstrPassword);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IServerXMLHTTPRequest2));
		return _hr;
	}

	//
	// interface IMXNamespacePrefixes wrapper method implementations
	//

	_bstr_t IMXNamespacePrefixes::Getitem ( long index ) {
		BSTR _result = 0;
		HRESULT _hr = get_item(index, &_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IMXNamespacePrefixes));
		return _bstr_t(_result, false);
	}

	long IMXNamespacePrefixes::Getlength ( ) {
		long _result = 0;
		HRESULT _hr = get_length(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IMXNamespacePrefixes));
		return _result;
	}

	IUnknownPtr IMXNamespacePrefixes::Get_newEnum ( ) {
		IUnknown * _result = 0;
		HRESULT _hr = get__newEnum(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IMXNamespacePrefixes));
		return IUnknownPtr(_result, false);
	}

	//
	// interface IXMLDOMNode wrapper method implementations
	//

	_bstr_t IXMLDOMNode::GetnodeName ( ) {
		BSTR _result = 0;
		HRESULT _hr = get_nodeName(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IXMLDOMNode));
		return _bstr_t(_result, false);
	}

	_variant_t IXMLDOMNode::GetnodeValue ( ) {
		VARIANT _result;
		VariantInit(&_result);
		HRESULT _hr = get_nodeValue(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IXMLDOMNode));
		return _variant_t(_result, false);
	}

	void IXMLDOMNode::PutnodeValue ( const _variant_t & value ) {
		HRESULT _hr = put_nodeValue(value);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IXMLDOMNode));
	}

	DOMNodeType IXMLDOMNode::GetnodeType ( ) {
		DOMNodeType _result;
		HRESULT _hr = get_nodeType(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IXMLDOMNode));
		return _result;
	}

	IXMLDOMNodePtr IXMLDOMNode::GetparentNode ( ) {
		struct IXMLDOMNode * _result = 0;
		HRESULT _hr = get_parentNode(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IXMLDOMNode));
		return IXMLDOMNodePtr(_result, false);
	}

	IXMLDOMNodeListPtr IXMLDOMNode::GetchildNodes ( ) {
		struct IXMLDOMNodeList * _result = 0;
		HRESULT _hr = get_childNodes(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IXMLDOMNode));
		return IXMLDOMNodeListPtr(_result, false);
	}

	IXMLDOMNodePtr IXMLDOMNode::GetfirstChild ( ) {
		struct IXMLDOMNode * _result = 0;
		HRESULT _hr = get_firstChild(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IXMLDOMNode));
		return IXMLDOMNodePtr(_result, false);
	}

	IXMLDOMNodePtr IXMLDOMNode::GetlastChild ( ) {
		struct IXMLDOMNode * _result = 0;
		HRESULT _hr = get_lastChild(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IXMLDOMNode));
		return IXMLDOMNodePtr(_result, false);
	}

	IXMLDOMNodePtr IXMLDOMNode::GetpreviousSibling ( ) {
		struct IXMLDOMNode * _result = 0;
		HRESULT _hr = get_previousSibling(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IXMLDOMNode));
		return IXMLDOMNodePtr(_result, false);
	}

	IXMLDOMNodePtr IXMLDOMNode::GetnextSibling ( ) {
		struct IXMLDOMNode * _result = 0;
		HRESULT _hr = get_nextSibling(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IXMLDOMNode));
		return IXMLDOMNodePtr(_result, false);
	}

	IXMLDOMNamedNodeMapPtr IXMLDOMNode::Getattributes ( ) {
		struct IXMLDOMNamedNodeMap * _result = 0;
		HRESULT _hr = get_attributes(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IXMLDOMNode));
		return IXMLDOMNamedNodeMapPtr(_result, false);
	}

	IXMLDOMNodePtr IXMLDOMNode::insertBefore ( struct IXMLDOMNode * newChild, const _variant_t & refChild ) {
		struct IXMLDOMNode * _result = 0;
		HRESULT _hr = raw_insertBefore(newChild, refChild, &_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IXMLDOMNode));
		return IXMLDOMNodePtr(_result, false);
	}

	IXMLDOMNodePtr IXMLDOMNode::replaceChild ( struct IXMLDOMNode * newChild, struct IXMLDOMNode * oldChild ) {
		struct IXMLDOMNode * _result = 0;
		HRESULT _hr = raw_replaceChild(newChild, oldChild, &_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IXMLDOMNode));
		return IXMLDOMNodePtr(_result, false);
	}

	IXMLDOMNodePtr IXMLDOMNode::removeChild ( struct IXMLDOMNode * childNode ) {
		struct IXMLDOMNode * _result = 0;
		HRESULT _hr = raw_removeChild(childNode, &_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IXMLDOMNode));
		return IXMLDOMNodePtr(_result, false);
	}

	IXMLDOMNodePtr IXMLDOMNode::appendChild ( struct IXMLDOMNode * newChild ) {
		struct IXMLDOMNode * _result = 0;
		HRESULT _hr = raw_appendChild(newChild, &_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IXMLDOMNode));
		return IXMLDOMNodePtr(_result, false);
	}

	VARIANT_BOOL IXMLDOMNode::hasChildNodes ( ) {
		VARIANT_BOOL _result = 0;
		HRESULT _hr = raw_hasChildNodes(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IXMLDOMNode));
		return _result;
	}

	IXMLDOMDocumentPtr IXMLDOMNode::GetownerDocument ( ) {
		struct IXMLDOMDocument * _result = 0;
		HRESULT _hr = get_ownerDocument(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IXMLDOMNode));
		return IXMLDOMDocumentPtr(_result, false);
	}

	IXMLDOMNodePtr IXMLDOMNode::cloneNode ( VARIANT_BOOL deep ) {
		struct IXMLDOMNode * _result = 0;
		HRESULT _hr = raw_cloneNode(deep, &_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IXMLDOMNode));
		return IXMLDOMNodePtr(_result, false);
	}

	_bstr_t IXMLDOMNode::GetnodeTypeString ( ) {
		BSTR _result = 0;
		HRESULT _hr = get_nodeTypeString(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IXMLDOMNode));
		return _bstr_t(_result, false);
	}

	_bstr_t IXMLDOMNode::Gettext ( ) {
		BSTR _result = 0;
		HRESULT _hr = get_text(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IXMLDOMNode));
		return _bstr_t(_result, false);
	}

	void IXMLDOMNode::Puttext ( _bstr_t text ) {
		HRESULT _hr = put_text(text);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IXMLDOMNode));
	}

	VARIANT_BOOL IXMLDOMNode::Getspecified ( ) {
		VARIANT_BOOL _result = 0;
		HRESULT _hr = get_specified(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IXMLDOMNode));
		return _result;
	}

	IXMLDOMNodePtr IXMLDOMNode::Getdefinition ( ) {
		struct IXMLDOMNode * _result = 0;
		HRESULT _hr = get_definition(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IXMLDOMNode));
		return IXMLDOMNodePtr(_result, false);
	}

	_variant_t IXMLDOMNode::GetnodeTypedValue ( ) {
		VARIANT _result;
		VariantInit(&_result);
		HRESULT _hr = get_nodeTypedValue(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IXMLDOMNode));
		return _variant_t(_result, false);
	}

	void IXMLDOMNode::PutnodeTypedValue ( const _variant_t & typedValue ) {
		HRESULT _hr = put_nodeTypedValue(typedValue);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IXMLDOMNode));
	}

	_variant_t IXMLDOMNode::GetdataType ( ) {
		VARIANT _result;
		VariantInit(&_result);
		HRESULT _hr = get_dataType(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IXMLDOMNode));
		return _variant_t(_result, false);
	}

	void IXMLDOMNode::PutdataType ( _bstr_t dataTypeName ) {
		HRESULT _hr = put_dataType(dataTypeName);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IXMLDOMNode));
	}

	_bstr_t IXMLDOMNode::Getxml ( ) {
		BSTR _result = 0;
		HRESULT _hr = get_xml(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IXMLDOMNode));
		return _bstr_t(_result, false);
	}

	_bstr_t IXMLDOMNode::transformNode ( struct IXMLDOMNode * stylesheet ) {
		BSTR _result = 0;
		HRESULT _hr = raw_transformNode(stylesheet, &_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IXMLDOMNode));
		return _bstr_t(_result, false);
	}

	IXMLDOMNodeListPtr IXMLDOMNode::selectNodes ( _bstr_t queryString ) {
		struct IXMLDOMNodeList * _result = 0;
		HRESULT _hr = raw_selectNodes(queryString, &_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IXMLDOMNode));
		return IXMLDOMNodeListPtr(_result, false);
	}

	IXMLDOMNodePtr IXMLDOMNode::selectSingleNode ( _bstr_t queryString ) {
		struct IXMLDOMNode * _result = 0;
		HRESULT _hr = raw_selectSingleNode(queryString, &_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IXMLDOMNode));
		return IXMLDOMNodePtr(_result, false);
	}

	VARIANT_BOOL IXMLDOMNode::Getparsed ( ) {
		VARIANT_BOOL _result = 0;
		HRESULT _hr = get_parsed(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IXMLDOMNode));
		return _result;
	}

	_bstr_t IXMLDOMNode::GetnamespaceURI ( ) {
		BSTR _result = 0;
		HRESULT _hr = get_namespaceURI(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IXMLDOMNode));
		return _bstr_t(_result, false);
	}

	_bstr_t IXMLDOMNode::Getprefix ( ) {
		BSTR _result = 0;
		HRESULT _hr = get_prefix(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IXMLDOMNode));
		return _bstr_t(_result, false);
	}

	_bstr_t IXMLDOMNode::GetbaseName ( ) {
		BSTR _result = 0;
		HRESULT _hr = get_baseName(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IXMLDOMNode));
		return _bstr_t(_result, false);
	}

	HRESULT IXMLDOMNode::transformNodeToObject ( struct IXMLDOMNode * stylesheet, const _variant_t & outputObject ) {
		HRESULT _hr = raw_transformNodeToObject(stylesheet, outputObject);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IXMLDOMNode));
		return _hr;
	}

	//
	// interface IXMLDOMNodeList wrapper method implementations
	//

	IXMLDOMNodePtr IXMLDOMNodeList::Getitem ( long index ) {
		struct IXMLDOMNode * _result = 0;
		HRESULT _hr = get_item(index, &_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IXMLDOMNodeList));
		return IXMLDOMNodePtr(_result, false);
	}

	long IXMLDOMNodeList::Getlength ( ) {
		long _result = 0;
		HRESULT _hr = get_length(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IXMLDOMNodeList));
		return _result;
	}

	IXMLDOMNodePtr IXMLDOMNodeList::nextNode ( ) {
		struct IXMLDOMNode * _result = 0;
		HRESULT _hr = raw_nextNode(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IXMLDOMNodeList));
		return IXMLDOMNodePtr(_result, false);
	}

	HRESULT IXMLDOMNodeList::reset ( ) {
		HRESULT _hr = raw_reset();
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IXMLDOMNodeList));
		return _hr;
	}

	IUnknownPtr IXMLDOMNodeList::Get_newEnum ( ) {
		IUnknown * _result = 0;
		HRESULT _hr = get__newEnum(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IXMLDOMNodeList));
		return IUnknownPtr(_result, false);
	}

	//
	// interface IXMLDOMNamedNodeMap wrapper method implementations
	//

	IXMLDOMNodePtr IXMLDOMNamedNodeMap::getNamedItem ( _bstr_t name ) {
		struct IXMLDOMNode * _result = 0;
		HRESULT _hr = raw_getNamedItem(name, &_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IXMLDOMNamedNodeMap));
		return IXMLDOMNodePtr(_result, false);
	}

	IXMLDOMNodePtr IXMLDOMNamedNodeMap::setNamedItem ( struct IXMLDOMNode * newItem ) {
		struct IXMLDOMNode * _result = 0;
		HRESULT _hr = raw_setNamedItem(newItem, &_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IXMLDOMNamedNodeMap));
		return IXMLDOMNodePtr(_result, false);
	}

	IXMLDOMNodePtr IXMLDOMNamedNodeMap::removeNamedItem ( _bstr_t name ) {
		struct IXMLDOMNode * _result = 0;
		HRESULT _hr = raw_removeNamedItem(name, &_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IXMLDOMNamedNodeMap));
		return IXMLDOMNodePtr(_result, false);
	}

	IXMLDOMNodePtr IXMLDOMNamedNodeMap::Getitem ( long index ) {
		struct IXMLDOMNode * _result = 0;
		HRESULT _hr = get_item(index, &_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IXMLDOMNamedNodeMap));
		return IXMLDOMNodePtr(_result, false);
	}

	long IXMLDOMNamedNodeMap::Getlength ( ) {
		long _result = 0;
		HRESULT _hr = get_length(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IXMLDOMNamedNodeMap));
		return _result;
	}

	IXMLDOMNodePtr IXMLDOMNamedNodeMap::getQualifiedItem ( _bstr_t baseName, _bstr_t namespaceURI ) {
		struct IXMLDOMNode * _result = 0;
		HRESULT _hr = raw_getQualifiedItem(baseName, namespaceURI, &_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IXMLDOMNamedNodeMap));
		return IXMLDOMNodePtr(_result, false);
	}

	IXMLDOMNodePtr IXMLDOMNamedNodeMap::removeQualifiedItem ( _bstr_t baseName, _bstr_t namespaceURI ) {
		struct IXMLDOMNode * _result = 0;
		HRESULT _hr = raw_removeQualifiedItem(baseName, namespaceURI, &_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IXMLDOMNamedNodeMap));
		return IXMLDOMNodePtr(_result, false);
	}

	IXMLDOMNodePtr IXMLDOMNamedNodeMap::nextNode ( ) {
		struct IXMLDOMNode * _result = 0;
		HRESULT _hr = raw_nextNode(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IXMLDOMNamedNodeMap));
		return IXMLDOMNodePtr(_result, false);
	}

	HRESULT IXMLDOMNamedNodeMap::reset ( ) {
		HRESULT _hr = raw_reset();
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IXMLDOMNamedNodeMap));
		return _hr;
	}

	IUnknownPtr IXMLDOMNamedNodeMap::Get_newEnum ( ) {
		IUnknown * _result = 0;
		HRESULT _hr = get__newEnum(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IXMLDOMNamedNodeMap));
		return IUnknownPtr(_result, false);
	}

	//
	// interface IXMLDOMDocumentType wrapper method implementations
	//

	_bstr_t IXMLDOMDocumentType::Getname ( ) {
		BSTR _result = 0;
		HRESULT _hr = get_name(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IXMLDOMDocumentType));
		return _bstr_t(_result, false);
	}

	IXMLDOMNamedNodeMapPtr IXMLDOMDocumentType::Getentities ( ) {
		struct IXMLDOMNamedNodeMap * _result = 0;
		HRESULT _hr = get_entities(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IXMLDOMDocumentType));
		return IXMLDOMNamedNodeMapPtr(_result, false);
	}

	IXMLDOMNamedNodeMapPtr IXMLDOMDocumentType::Getnotations ( ) {
		struct IXMLDOMNamedNodeMap * _result = 0;
		HRESULT _hr = get_notations(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IXMLDOMDocumentType));
		return IXMLDOMNamedNodeMapPtr(_result, false);
	}

	//
	// interface IXMLDOMAttribute wrapper method implementations
	//

	_bstr_t IXMLDOMAttribute::Getname ( ) {
		BSTR _result = 0;
		HRESULT _hr = get_name(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IXMLDOMAttribute));
		return _bstr_t(_result, false);
	}

	_variant_t IXMLDOMAttribute::Getvalue ( ) {
		VARIANT _result;
		VariantInit(&_result);
		HRESULT _hr = get_value(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IXMLDOMAttribute));
		return _variant_t(_result, false);
	}

	void IXMLDOMAttribute::Putvalue ( const _variant_t & attributeValue ) {
		HRESULT _hr = put_value(attributeValue);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IXMLDOMAttribute));
	}

	//
	// interface IXMLDOMElement wrapper method implementations
	//

	_bstr_t IXMLDOMElement::GettagName ( ) {
		BSTR _result = 0;
		HRESULT _hr = get_tagName(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IXMLDOMElement));
		return _bstr_t(_result, false);
	}

	_variant_t IXMLDOMElement::getAttribute ( _bstr_t name ) {
		VARIANT _result;
		VariantInit(&_result);
		HRESULT _hr = raw_getAttribute(name, &_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IXMLDOMElement));
		return _variant_t(_result, false);
	}

	HRESULT IXMLDOMElement::setAttribute ( _bstr_t name, const _variant_t & value ) {
		HRESULT _hr = raw_setAttribute(name, value);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IXMLDOMElement));
		return _hr;
	}

	HRESULT IXMLDOMElement::removeAttribute ( _bstr_t name ) {
		HRESULT _hr = raw_removeAttribute(name);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IXMLDOMElement));
		return _hr;
	}

	IXMLDOMAttributePtr IXMLDOMElement::getAttributeNode ( _bstr_t name ) {
		struct IXMLDOMAttribute * _result = 0;
		HRESULT _hr = raw_getAttributeNode(name, &_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IXMLDOMElement));
		return IXMLDOMAttributePtr(_result, false);
	}

	IXMLDOMAttributePtr IXMLDOMElement::setAttributeNode ( struct IXMLDOMAttribute * DOMAttribute ) {
		struct IXMLDOMAttribute * _result = 0;
		HRESULT _hr = raw_setAttributeNode(DOMAttribute, &_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IXMLDOMElement));
		return IXMLDOMAttributePtr(_result, false);
	}

	IXMLDOMAttributePtr IXMLDOMElement::removeAttributeNode ( struct IXMLDOMAttribute * DOMAttribute ) {
		struct IXMLDOMAttribute * _result = 0;
		HRESULT _hr = raw_removeAttributeNode(DOMAttribute, &_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IXMLDOMElement));
		return IXMLDOMAttributePtr(_result, false);
	}

	IXMLDOMNodeListPtr IXMLDOMElement::getElementsByTagName ( _bstr_t tagName ) {
		struct IXMLDOMNodeList * _result = 0;
		HRESULT _hr = raw_getElementsByTagName(tagName, &_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IXMLDOMElement));
		return IXMLDOMNodeListPtr(_result, false);
	}

	HRESULT IXMLDOMElement::normalize ( ) {
		HRESULT _hr = raw_normalize();
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IXMLDOMElement));
		return _hr;
	}

	//
	// interface IXMLDOMCharacterData wrapper method implementations
	//

	_bstr_t IXMLDOMCharacterData::Getdata ( ) {
		BSTR _result = 0;
		HRESULT _hr = get_data(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IXMLDOMCharacterData));
		return _bstr_t(_result, false);
	}

	void IXMLDOMCharacterData::Putdata ( _bstr_t data ) {
		HRESULT _hr = put_data(data);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IXMLDOMCharacterData));
	}

	long IXMLDOMCharacterData::Getlength ( ) {
		long _result = 0;
		HRESULT _hr = get_length(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IXMLDOMCharacterData));
		return _result;
	}

	_bstr_t IXMLDOMCharacterData::substringData ( long offset, long count ) {
		BSTR _result = 0;
		HRESULT _hr = raw_substringData(offset, count, &_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IXMLDOMCharacterData));
		return _bstr_t(_result, false);
	}

	HRESULT IXMLDOMCharacterData::appendData ( _bstr_t data ) {
		HRESULT _hr = raw_appendData(data);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IXMLDOMCharacterData));
		return _hr;
	}

	HRESULT IXMLDOMCharacterData::insertData ( long offset, _bstr_t data ) {
		HRESULT _hr = raw_insertData(offset, data);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IXMLDOMCharacterData));
		return _hr;
	}

	HRESULT IXMLDOMCharacterData::deleteData ( long offset, long count ) {
		HRESULT _hr = raw_deleteData(offset, count);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IXMLDOMCharacterData));
		return _hr;
	}

	HRESULT IXMLDOMCharacterData::replaceData ( long offset, long count, _bstr_t data ) {
		HRESULT _hr = raw_replaceData(offset, count, data);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IXMLDOMCharacterData));
		return _hr;
	}

	//
	// interface IXMLDOMText wrapper method implementations
	//

	IXMLDOMTextPtr IXMLDOMText::splitText ( long offset ) {
		struct IXMLDOMText * _result = 0;
		HRESULT _hr = raw_splitText(offset, &_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IXMLDOMText));
		return IXMLDOMTextPtr(_result, false);
	}

	//
	// interface IXMLDOMProcessingInstruction wrapper method implementations
	//

	_bstr_t IXMLDOMProcessingInstruction::Gettarget ( ) {
		BSTR _result = 0;
		HRESULT _hr = get_target(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IXMLDOMProcessingInstruction));
		return _bstr_t(_result, false);
	}

	_bstr_t IXMLDOMProcessingInstruction::Getdata ( ) {
		BSTR _result = 0;
		HRESULT _hr = get_data(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IXMLDOMProcessingInstruction));
		return _bstr_t(_result, false);
	}

	void IXMLDOMProcessingInstruction::Putdata ( _bstr_t value ) {
		HRESULT _hr = put_data(value);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IXMLDOMProcessingInstruction));
	}

	//
	// interface IXMLDOMDocument wrapper method implementations
	//

	IXMLDOMDocumentTypePtr IXMLDOMDocument::Getdoctype ( ) {
		struct IXMLDOMDocumentType * _result = 0;
		HRESULT _hr = get_doctype(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IXMLDOMDocument));
		return IXMLDOMDocumentTypePtr(_result, false);
	}

	IXMLDOMImplementationPtr IXMLDOMDocument::Getimplementation ( ) {
		struct IXMLDOMImplementation * _result = 0;
		HRESULT _hr = get_implementation(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IXMLDOMDocument));
		return IXMLDOMImplementationPtr(_result, false);
	}

	IXMLDOMElementPtr IXMLDOMDocument::GetdocumentElement ( ) {
		struct IXMLDOMElement * _result = 0;
		HRESULT _hr = get_documentElement(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IXMLDOMDocument));
		return IXMLDOMElementPtr(_result, false);
	}

	void IXMLDOMDocument::PutRefdocumentElement ( struct IXMLDOMElement * DOMElement ) {
		HRESULT _hr = putref_documentElement(DOMElement);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IXMLDOMDocument));
	}

	IXMLDOMElementPtr IXMLDOMDocument::createElement ( _bstr_t tagName ) {
		struct IXMLDOMElement * _result = 0;
		HRESULT _hr = raw_createElement(tagName, &_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IXMLDOMDocument));
		return IXMLDOMElementPtr(_result, false);
	}

	IXMLDOMDocumentFragmentPtr IXMLDOMDocument::createDocumentFragment ( ) {
		struct IXMLDOMDocumentFragment * _result = 0;
		HRESULT _hr = raw_createDocumentFragment(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IXMLDOMDocument));
		return IXMLDOMDocumentFragmentPtr(_result, false);
	}

	IXMLDOMTextPtr IXMLDOMDocument::createTextNode ( _bstr_t data ) {
		struct IXMLDOMText * _result = 0;
		HRESULT _hr = raw_createTextNode(data, &_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IXMLDOMDocument));
		return IXMLDOMTextPtr(_result, false);
	}

	IXMLDOMCommentPtr IXMLDOMDocument::createComment ( _bstr_t data ) {
		struct IXMLDOMComment * _result = 0;
		HRESULT _hr = raw_createComment(data, &_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IXMLDOMDocument));
		return IXMLDOMCommentPtr(_result, false);
	}

	IXMLDOMCDATASectionPtr IXMLDOMDocument::createCDATASection ( _bstr_t data ) {
		struct IXMLDOMCDATASection * _result = 0;
		HRESULT _hr = raw_createCDATASection(data, &_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IXMLDOMDocument));
		return IXMLDOMCDATASectionPtr(_result, false);
	}

	IXMLDOMProcessingInstructionPtr IXMLDOMDocument::createProcessingInstruction ( _bstr_t target, _bstr_t data ) {
		struct IXMLDOMProcessingInstruction * _result = 0;
		HRESULT _hr = raw_createProcessingInstruction(target, data, &_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IXMLDOMDocument));
		return IXMLDOMProcessingInstructionPtr(_result, false);
	}

	IXMLDOMAttributePtr IXMLDOMDocument::createAttribute ( _bstr_t name ) {
		struct IXMLDOMAttribute * _result = 0;
		HRESULT _hr = raw_createAttribute(name, &_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IXMLDOMDocument));
		return IXMLDOMAttributePtr(_result, false);
	}

	IXMLDOMEntityReferencePtr IXMLDOMDocument::createEntityReference ( _bstr_t name ) {
		struct IXMLDOMEntityReference * _result = 0;
		HRESULT _hr = raw_createEntityReference(name, &_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IXMLDOMDocument));
		return IXMLDOMEntityReferencePtr(_result, false);
	}

	IXMLDOMNodeListPtr IXMLDOMDocument::getElementsByTagName ( _bstr_t tagName ) {
		struct IXMLDOMNodeList * _result = 0;
		HRESULT _hr = raw_getElementsByTagName(tagName, &_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IXMLDOMDocument));
		return IXMLDOMNodeListPtr(_result, false);
	}

	IXMLDOMNodePtr IXMLDOMDocument::createNode ( const _variant_t & type, _bstr_t name, _bstr_t namespaceURI ) {
		struct IXMLDOMNode * _result = 0;
		HRESULT _hr = raw_createNode(type, name, namespaceURI, &_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IXMLDOMDocument));
		return IXMLDOMNodePtr(_result, false);
	}

	IXMLDOMNodePtr IXMLDOMDocument::nodeFromID ( _bstr_t idString ) {
		struct IXMLDOMNode * _result = 0;
		HRESULT _hr = raw_nodeFromID(idString, &_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IXMLDOMDocument));
		return IXMLDOMNodePtr(_result, false);
	}

	VARIANT_BOOL IXMLDOMDocument::load ( const _variant_t & xmlSource ) {
		VARIANT_BOOL _result = 0;
		HRESULT _hr = raw_load(xmlSource, &_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IXMLDOMDocument));
		return _result;
	}

	long IXMLDOMDocument::GetreadyState ( ) {
		long _result = 0;
		HRESULT _hr = get_readyState(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IXMLDOMDocument));
		return _result;
	}

	IXMLDOMParseErrorPtr IXMLDOMDocument::GetparseError ( ) {
		struct IXMLDOMParseError * _result = 0;
		HRESULT _hr = get_parseError(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IXMLDOMDocument));
		return IXMLDOMParseErrorPtr(_result, false);
	}

	_bstr_t IXMLDOMDocument::Geturl ( ) {
		BSTR _result = 0;
		HRESULT _hr = get_url(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IXMLDOMDocument));
		return _bstr_t(_result, false);
	}

	VARIANT_BOOL IXMLDOMDocument::Getasync ( ) {
		VARIANT_BOOL _result = 0;
		HRESULT _hr = get_async(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IXMLDOMDocument));
		return _result;
	}

	void IXMLDOMDocument::Putasync ( VARIANT_BOOL isAsync ) {
		HRESULT _hr = put_async(isAsync);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IXMLDOMDocument));
	}

	HRESULT IXMLDOMDocument::abort ( ) {
		HRESULT _hr = raw_abort();
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IXMLDOMDocument));
		return _hr;
	}

	VARIANT_BOOL IXMLDOMDocument::loadXML ( _bstr_t bstrXML ) {
		VARIANT_BOOL _result = 0;
		HRESULT _hr = raw_loadXML(bstrXML, &_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IXMLDOMDocument));
		return _result;
	}

	HRESULT IXMLDOMDocument::save ( const _variant_t & destination ) {
		HRESULT _hr = raw_save(destination);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IXMLDOMDocument));
		return _hr;
	}

	VARIANT_BOOL IXMLDOMDocument::GetvalidateOnParse ( ) {
		VARIANT_BOOL _result = 0;
		HRESULT _hr = get_validateOnParse(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IXMLDOMDocument));
		return _result;
	}

	void IXMLDOMDocument::PutvalidateOnParse ( VARIANT_BOOL isValidating ) {
		HRESULT _hr = put_validateOnParse(isValidating);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IXMLDOMDocument));
	}

	VARIANT_BOOL IXMLDOMDocument::GetresolveExternals ( ) {
		VARIANT_BOOL _result = 0;
		HRESULT _hr = get_resolveExternals(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IXMLDOMDocument));
		return _result;
	}

	void IXMLDOMDocument::PutresolveExternals ( VARIANT_BOOL isResolving ) {
		HRESULT _hr = put_resolveExternals(isResolving);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IXMLDOMDocument));
	}

	VARIANT_BOOL IXMLDOMDocument::GetpreserveWhiteSpace ( ) {
		VARIANT_BOOL _result = 0;
		HRESULT _hr = get_preserveWhiteSpace(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IXMLDOMDocument));
		return _result;
	}

	void IXMLDOMDocument::PutpreserveWhiteSpace ( VARIANT_BOOL isPreserving ) {
		HRESULT _hr = put_preserveWhiteSpace(isPreserving);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IXMLDOMDocument));
	}

	void IXMLDOMDocument::Putonreadystatechange ( const _variant_t & _arg1 ) {
		HRESULT _hr = put_onreadystatechange(_arg1);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IXMLDOMDocument));
	}

	void IXMLDOMDocument::Putondataavailable ( const _variant_t & _arg1 ) {
		HRESULT _hr = put_ondataavailable(_arg1);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IXMLDOMDocument));
	}

	void IXMLDOMDocument::Putontransformnode ( const _variant_t & _arg1 ) {
		HRESULT _hr = put_ontransformnode(_arg1);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IXMLDOMDocument));
	}

	//
	// interface IXMLDOMSchemaCollection wrapper method implementations
	//

	HRESULT IXMLDOMSchemaCollection::add ( _bstr_t namespaceURI, const _variant_t & var ) {
		HRESULT _hr = raw_add(namespaceURI, var);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IXMLDOMSchemaCollection));
		return _hr;
	}

	IXMLDOMNodePtr IXMLDOMSchemaCollection::get ( _bstr_t namespaceURI ) {
		struct IXMLDOMNode * _result = 0;
		HRESULT _hr = raw_get(namespaceURI, &_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IXMLDOMSchemaCollection));
		return IXMLDOMNodePtr(_result, false);
	}

	HRESULT IXMLDOMSchemaCollection::remove ( _bstr_t namespaceURI ) {
		HRESULT _hr = raw_remove(namespaceURI);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IXMLDOMSchemaCollection));
		return _hr;
	}

	long IXMLDOMSchemaCollection::Getlength ( ) {
		long _result = 0;
		HRESULT _hr = get_length(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IXMLDOMSchemaCollection));
		return _result;
	}

	_bstr_t IXMLDOMSchemaCollection::GetnamespaceURI ( long index ) {
		BSTR _result = 0;
		HRESULT _hr = get_namespaceURI(index, &_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IXMLDOMSchemaCollection));
		return _bstr_t(_result, false);
	}

	HRESULT IXMLDOMSchemaCollection::addCollection ( struct IXMLDOMSchemaCollection * otherCollection ) {
		HRESULT _hr = raw_addCollection(otherCollection);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IXMLDOMSchemaCollection));
		return _hr;
	}

	IUnknownPtr IXMLDOMSchemaCollection::Get_newEnum ( ) {
		IUnknown * _result = 0;
		HRESULT _hr = get__newEnum(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IXMLDOMSchemaCollection));
		return IUnknownPtr(_result, false);
	}

	//
	// interface IXMLDOMDocument2 wrapper method implementations
	//

	IXMLDOMSchemaCollectionPtr IXMLDOMDocument2::Getnamespaces ( ) {
		struct IXMLDOMSchemaCollection * _result = 0;
		HRESULT _hr = get_namespaces(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IXMLDOMDocument2));
		return IXMLDOMSchemaCollectionPtr(_result, false);
	}

	_variant_t IXMLDOMDocument2::Getschemas ( ) {
		VARIANT _result;
		VariantInit(&_result);
		HRESULT _hr = get_schemas(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IXMLDOMDocument2));
		return _variant_t(_result, false);
	}

	void IXMLDOMDocument2::PutRefschemas ( const _variant_t & otherCollection ) {
		HRESULT _hr = putref_schemas(otherCollection);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IXMLDOMDocument2));
	}

	IXMLDOMParseErrorPtr IXMLDOMDocument2::validate ( ) {
		struct IXMLDOMParseError * _result = 0;
		HRESULT _hr = raw_validate(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IXMLDOMDocument2));
		return IXMLDOMParseErrorPtr(_result, false);
	}

	HRESULT IXMLDOMDocument2::setProperty ( _bstr_t name, const _variant_t & value ) {
		HRESULT _hr = raw_setProperty(name, value);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IXMLDOMDocument2));
		return _hr;
	}

	_variant_t IXMLDOMDocument2::getProperty ( _bstr_t name ) {
		VARIANT _result;
		VariantInit(&_result);
		HRESULT _hr = raw_getProperty(name, &_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IXMLDOMDocument2));
		return _variant_t(_result, false);
	}

	//
	// interface IXMLDOMDocument3 wrapper method implementations
	//

	IXMLDOMParseErrorPtr IXMLDOMDocument3::validateNode ( struct IXMLDOMNode * node ) {
		struct IXMLDOMParseError * _result = 0;
		HRESULT _hr = raw_validateNode(node, &_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IXMLDOMDocument3));
		return IXMLDOMParseErrorPtr(_result, false);
	}

	IXMLDOMNodePtr IXMLDOMDocument3::importNode ( struct IXMLDOMNode * node, VARIANT_BOOL deep ) {
		struct IXMLDOMNode * _result = 0;
		HRESULT _hr = raw_importNode(node, deep, &_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IXMLDOMDocument3));
		return IXMLDOMNodePtr(_result, false);
	}

	//
	// interface IXMLDOMNotation wrapper method implementations
	//

	_variant_t IXMLDOMNotation::GetpublicId ( ) {
		VARIANT _result;
		VariantInit(&_result);
		HRESULT _hr = get_publicId(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IXMLDOMNotation));
		return _variant_t(_result, false);
	}

	_variant_t IXMLDOMNotation::GetsystemId ( ) {
		VARIANT _result;
		VariantInit(&_result);
		HRESULT _hr = get_systemId(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IXMLDOMNotation));
		return _variant_t(_result, false);
	}

	//
	// interface IXMLDOMEntity wrapper method implementations
	//

	_variant_t IXMLDOMEntity::GetpublicId ( ) {
		VARIANT _result;
		VariantInit(&_result);
		HRESULT _hr = get_publicId(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IXMLDOMEntity));
		return _variant_t(_result, false);
	}

	_variant_t IXMLDOMEntity::GetsystemId ( ) {
		VARIANT _result;
		VariantInit(&_result);
		HRESULT _hr = get_systemId(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IXMLDOMEntity));
		return _variant_t(_result, false);
	}

	_bstr_t IXMLDOMEntity::GetnotationName ( ) {
		BSTR _result = 0;
		HRESULT _hr = get_notationName(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IXMLDOMEntity));
		return _bstr_t(_result, false);
	}

	//
	// interface IXTLRuntime wrapper method implementations
	//

	long IXTLRuntime::uniqueID ( struct IXMLDOMNode * pNode ) {
		long _result = 0;
		HRESULT _hr = raw_uniqueID(pNode, &_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IXTLRuntime));
		return _result;
	}

	long IXTLRuntime::depth ( struct IXMLDOMNode * pNode ) {
		long _result = 0;
		HRESULT _hr = raw_depth(pNode, &_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IXTLRuntime));
		return _result;
	}

	long IXTLRuntime::childNumber ( struct IXMLDOMNode * pNode ) {
		long _result = 0;
		HRESULT _hr = raw_childNumber(pNode, &_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IXTLRuntime));
		return _result;
	}

	long IXTLRuntime::ancestorChildNumber ( _bstr_t bstrNodeName, struct IXMLDOMNode * pNode ) {
		long _result = 0;
		HRESULT _hr = raw_ancestorChildNumber(bstrNodeName, pNode, &_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IXTLRuntime));
		return _result;
	}

	long IXTLRuntime::absoluteChildNumber ( struct IXMLDOMNode * pNode ) {
		long _result = 0;
		HRESULT _hr = raw_absoluteChildNumber(pNode, &_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IXTLRuntime));
		return _result;
	}

	_bstr_t IXTLRuntime::formatIndex ( long lIndex, _bstr_t bstrFormat ) {
		BSTR _result = 0;
		HRESULT _hr = raw_formatIndex(lIndex, bstrFormat, &_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IXTLRuntime));
		return _bstr_t(_result, false);
	}

	_bstr_t IXTLRuntime::formatNumber ( double dblNumber, _bstr_t bstrFormat ) {
		BSTR _result = 0;
		HRESULT _hr = raw_formatNumber(dblNumber, bstrFormat, &_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IXTLRuntime));
		return _bstr_t(_result, false);
	}

	_bstr_t IXTLRuntime::formatDate ( const _variant_t & varDate, _bstr_t bstrFormat, const _variant_t & varDestLocale ) {
		BSTR _result = 0;
		HRESULT _hr = raw_formatDate(varDate, bstrFormat, varDestLocale, &_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IXTLRuntime));
		return _bstr_t(_result, false);
	}

	_bstr_t IXTLRuntime::formatTime ( const _variant_t & varTime, _bstr_t bstrFormat, const _variant_t & varDestLocale ) {
		BSTR _result = 0;
		HRESULT _hr = raw_formatTime(varTime, bstrFormat, varDestLocale, &_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IXTLRuntime));
		return _bstr_t(_result, false);
	}

	//
	// interface IXMLDOMSelection wrapper method implementations
	//

	_bstr_t IXMLDOMSelection::Getexpr ( ) {
		BSTR _result = 0;
		HRESULT _hr = get_expr(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IXMLDOMSelection));
		return _bstr_t(_result, false);
	}

	void IXMLDOMSelection::Putexpr ( _bstr_t expression ) {
		HRESULT _hr = put_expr(expression);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IXMLDOMSelection));
	}

	IXMLDOMNodePtr IXMLDOMSelection::Getcontext ( ) {
		struct IXMLDOMNode * _result = 0;
		HRESULT _hr = get_context(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IXMLDOMSelection));
		return IXMLDOMNodePtr(_result, false);
	}

	void IXMLDOMSelection::PutRefcontext ( struct IXMLDOMNode * ppNode ) {
		HRESULT _hr = putref_context(ppNode);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IXMLDOMSelection));
	}

	IXMLDOMNodePtr IXMLDOMSelection::peekNode ( ) {
		struct IXMLDOMNode * _result = 0;
		HRESULT _hr = raw_peekNode(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IXMLDOMSelection));
		return IXMLDOMNodePtr(_result, false);
	}

	IXMLDOMNodePtr IXMLDOMSelection::matches ( struct IXMLDOMNode * pNode ) {
		struct IXMLDOMNode * _result = 0;
		HRESULT _hr = raw_matches(pNode, &_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IXMLDOMSelection));
		return IXMLDOMNodePtr(_result, false);
	}

	IXMLDOMNodePtr IXMLDOMSelection::removeNext ( ) {
		struct IXMLDOMNode * _result = 0;
		HRESULT _hr = raw_removeNext(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IXMLDOMSelection));
		return IXMLDOMNodePtr(_result, false);
	}

	HRESULT IXMLDOMSelection::removeAll ( ) {
		HRESULT _hr = raw_removeAll();
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IXMLDOMSelection));
		return _hr;
	}

	IXMLDOMSelectionPtr IXMLDOMSelection::clone ( ) {
		struct IXMLDOMSelection * _result = 0;
		HRESULT _hr = raw_clone(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IXMLDOMSelection));
		return IXMLDOMSelectionPtr(_result, false);
	}

	_variant_t IXMLDOMSelection::getProperty ( _bstr_t name ) {
		VARIANT _result;
		VariantInit(&_result);
		HRESULT _hr = raw_getProperty(name, &_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IXMLDOMSelection));
		return _variant_t(_result, false);
	}

	HRESULT IXMLDOMSelection::setProperty ( _bstr_t name, const _variant_t & value ) {
		HRESULT _hr = raw_setProperty(name, value);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IXMLDOMSelection));
		return _hr;
	}

	//
	// interface IDSOControl wrapper method implementations
	//

	IXMLDOMDocumentPtr IDSOControl::GetXMLDocument ( ) {
		struct IXMLDOMDocument * _result = 0;
		HRESULT _hr = get_XMLDocument(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IDSOControl));
		return IXMLDOMDocumentPtr(_result, false);
	}

	void IDSOControl::PutXMLDocument ( struct IXMLDOMDocument * ppDoc ) {
		HRESULT _hr = put_XMLDocument(ppDoc);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IDSOControl));
	}

	long IDSOControl::GetJavaDSOCompatible ( ) {
		long _result = 0;
		HRESULT _hr = get_JavaDSOCompatible(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IDSOControl));
		return _result;
	}

	void IDSOControl::PutJavaDSOCompatible ( long fJavaDSOCompatible ) {
		HRESULT _hr = put_JavaDSOCompatible(fJavaDSOCompatible);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IDSOControl));
	}

	long IDSOControl::GetreadyState ( ) {
		long _result = 0;
		HRESULT _hr = get_readyState(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IDSOControl));
		return _result;
	}

	//
	// interface IVBMXNamespaceManager wrapper method implementations
	//

	void IVBMXNamespaceManager::PutallowOverride ( VARIANT_BOOL fOverride ) {
		HRESULT _hr = put_allowOverride(fOverride);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IVBMXNamespaceManager));
	}

	VARIANT_BOOL IVBMXNamespaceManager::GetallowOverride ( ) {
		VARIANT_BOOL _result = 0;
		HRESULT _hr = get_allowOverride(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IVBMXNamespaceManager));
		return _result;
	}

	HRESULT IVBMXNamespaceManager::reset ( ) {
		HRESULT _hr = raw_reset();
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IVBMXNamespaceManager));
		return _hr;
	}

	HRESULT IVBMXNamespaceManager::pushContext ( ) {
		HRESULT _hr = raw_pushContext();
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IVBMXNamespaceManager));
		return _hr;
	}

	HRESULT IVBMXNamespaceManager::pushNodeContext ( struct IXMLDOMNode * contextNode, VARIANT_BOOL fDeep ) {
		HRESULT _hr = raw_pushNodeContext(contextNode, fDeep);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IVBMXNamespaceManager));
		return _hr;
	}

	HRESULT IVBMXNamespaceManager::popContext ( ) {
		HRESULT _hr = raw_popContext();
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IVBMXNamespaceManager));
		return _hr;
	}

	HRESULT IVBMXNamespaceManager::declarePrefix ( _bstr_t prefix, _bstr_t namespaceURI ) {
		HRESULT _hr = raw_declarePrefix(prefix, namespaceURI);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IVBMXNamespaceManager));
		return _hr;
	}

	IMXNamespacePrefixesPtr IVBMXNamespaceManager::getDeclaredPrefixes ( ) {
		struct IMXNamespacePrefixes * _result = 0;
		HRESULT _hr = raw_getDeclaredPrefixes(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IVBMXNamespaceManager));
		return IMXNamespacePrefixesPtr(_result, false);
	}

	IMXNamespacePrefixesPtr IVBMXNamespaceManager::getPrefixes ( _bstr_t namespaceURI ) {
		struct IMXNamespacePrefixes * _result = 0;
		HRESULT _hr = raw_getPrefixes(namespaceURI, &_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IVBMXNamespaceManager));
		return IMXNamespacePrefixesPtr(_result, false);
	}

	_variant_t IVBMXNamespaceManager::getURI ( _bstr_t prefix ) {
		VARIANT _result;
		VariantInit(&_result);
		HRESULT _hr = raw_getURI(prefix, &_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IVBMXNamespaceManager));
		return _variant_t(_result, false);
	}

	_variant_t IVBMXNamespaceManager::getURIFromNode ( _bstr_t strPrefix, struct IXMLDOMNode * contextNode ) {
		VARIANT _result;
		VariantInit(&_result);
		HRESULT _hr = raw_getURIFromNode(strPrefix, contextNode, &_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IVBMXNamespaceManager));
		return _variant_t(_result, false);
	}

	//
	// interface IMXNamespaceManager wrapper method implementations
	//

	HRESULT IMXNamespaceManager::putAllowOverride ( VARIANT_BOOL fOverride ) {
		HRESULT _hr = raw_putAllowOverride(fOverride);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IMXNamespaceManager));
		return _hr;
	}

	VARIANT_BOOL IMXNamespaceManager::getAllowOverride ( ) {
		VARIANT_BOOL _result = 0;
		HRESULT _hr = raw_getAllowOverride(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IMXNamespaceManager));
		return _result;
	}

	HRESULT IMXNamespaceManager::reset ( ) {
		HRESULT _hr = raw_reset();
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IMXNamespaceManager));
		return _hr;
	}

	HRESULT IMXNamespaceManager::pushContext ( ) {
		HRESULT _hr = raw_pushContext();
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IMXNamespaceManager));
		return _hr;
	}

	HRESULT IMXNamespaceManager::pushNodeContext ( struct IXMLDOMNode * contextNode, VARIANT_BOOL fDeep ) {
		HRESULT _hr = raw_pushNodeContext(contextNode, fDeep);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IMXNamespaceManager));
		return _hr;
	}

	HRESULT IMXNamespaceManager::popContext ( ) {
		HRESULT _hr = raw_popContext();
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IMXNamespaceManager));
		return _hr;
	}

	HRESULT IMXNamespaceManager::declarePrefix ( unsigned short * prefix, unsigned short * namespaceURI ) {
		HRESULT _hr = raw_declarePrefix(prefix, namespaceURI);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IMXNamespaceManager));
		return _hr;
	}

	HRESULT IMXNamespaceManager::getDeclaredPrefix ( long nIndex, unsigned short * pwchPrefix, int * pcchPrefix ) {
		HRESULT _hr = raw_getDeclaredPrefix(nIndex, pwchPrefix, pcchPrefix);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IMXNamespaceManager));
		return _hr;
	}

	HRESULT IMXNamespaceManager::getPrefix ( unsigned short * pwszNamespaceURI, long nIndex, unsigned short * pwchPrefix, int * pcchPrefix ) {
		HRESULT _hr = raw_getPrefix(pwszNamespaceURI, nIndex, pwchPrefix, pcchPrefix);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IMXNamespaceManager));
		return _hr;
	}

	HRESULT IMXNamespaceManager::getURI ( unsigned short * pwchPrefix, struct IXMLDOMNode * pContextNode, unsigned short * pwchUri, int * pcchUri ) {
		HRESULT _hr = raw_getURI(pwchPrefix, pContextNode, pwchUri, pcchUri);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IMXNamespaceManager));
		return _hr;
	}

	//
	// interface IXMLDOMParseError2 wrapper method implementations
	//

	_bstr_t IXMLDOMParseError2::GeterrorXPath ( ) {
		BSTR _result = 0;
		HRESULT _hr = get_errorXPath(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IXMLDOMParseError2));
		return _bstr_t(_result, false);
	}

	IXMLDOMParseErrorCollectionPtr IXMLDOMParseError2::GetallErrors ( ) {
		struct IXMLDOMParseErrorCollection * _result = 0;
		HRESULT _hr = get_allErrors(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IXMLDOMParseError2));
		return IXMLDOMParseErrorCollectionPtr(_result, false);
	}

	_bstr_t IXMLDOMParseError2::errorParameters ( long index ) {
		BSTR _result = 0;
		HRESULT _hr = raw_errorParameters(index, &_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IXMLDOMParseError2));
		return _bstr_t(_result, false);
	}

	long IXMLDOMParseError2::GeterrorParametersCount ( ) {
		long _result = 0;
		HRESULT _hr = get_errorParametersCount(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IXMLDOMParseError2));
		return _result;
	}

	//
	// interface IXMLDOMParseErrorCollection wrapper method implementations
	//

	IXMLDOMParseError2Ptr IXMLDOMParseErrorCollection::Getitem ( long index ) {
		struct IXMLDOMParseError2 * _result = 0;
		HRESULT _hr = get_item(index, &_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IXMLDOMParseErrorCollection));
		return IXMLDOMParseError2Ptr(_result, false);
	}

	long IXMLDOMParseErrorCollection::Getlength ( ) {
		long _result = 0;
		HRESULT _hr = get_length(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IXMLDOMParseErrorCollection));
		return _result;
	}

	IXMLDOMParseError2Ptr IXMLDOMParseErrorCollection::Getnext ( ) {
		struct IXMLDOMParseError2 * _result = 0;
		HRESULT _hr = get_next(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IXMLDOMParseErrorCollection));
		return IXMLDOMParseError2Ptr(_result, false);
	}

	HRESULT IXMLDOMParseErrorCollection::reset ( ) {
		HRESULT _hr = raw_reset();
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IXMLDOMParseErrorCollection));
		return _hr;
	}

	IUnknownPtr IXMLDOMParseErrorCollection::Get_newEnum ( ) {
		IUnknown * _result = 0;
		HRESULT _hr = get__newEnum(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IXMLDOMParseErrorCollection));
		return IUnknownPtr(_result, false);
	}

	//
	// interface IXSLTemplate wrapper method implementations
	//

	void IXSLTemplate::PutRefstylesheet ( struct IXMLDOMNode * stylesheet ) {
		HRESULT _hr = putref_stylesheet(stylesheet);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IXSLTemplate));
	}

	IXMLDOMNodePtr IXSLTemplate::Getstylesheet ( ) {
		struct IXMLDOMNode * _result = 0;
		HRESULT _hr = get_stylesheet(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IXSLTemplate));
		return IXMLDOMNodePtr(_result, false);
	}

	IXSLProcessorPtr IXSLTemplate::createProcessor ( ) {
		struct IXSLProcessor * _result = 0;
		HRESULT _hr = raw_createProcessor(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IXSLTemplate));
		return IXSLProcessorPtr(_result, false);
	}

	//
	// interface IXSLProcessor wrapper method implementations
	//

	void IXSLProcessor::Putinput ( const _variant_t & pVar ) {
		HRESULT _hr = put_input(pVar);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IXSLProcessor));
	}

	_variant_t IXSLProcessor::Getinput ( ) {
		VARIANT _result;
		VariantInit(&_result);
		HRESULT _hr = get_input(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IXSLProcessor));
		return _variant_t(_result, false);
	}

	IXSLTemplatePtr IXSLProcessor::GetownerTemplate ( ) {
		struct IXSLTemplate * _result = 0;
		HRESULT _hr = get_ownerTemplate(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IXSLProcessor));
		return IXSLTemplatePtr(_result, false);
	}

	HRESULT IXSLProcessor::setStartMode ( _bstr_t mode, _bstr_t namespaceURI ) {
		HRESULT _hr = raw_setStartMode(mode, namespaceURI);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IXSLProcessor));
		return _hr;
	}

	_bstr_t IXSLProcessor::GetstartMode ( ) {
		BSTR _result = 0;
		HRESULT _hr = get_startMode(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IXSLProcessor));
		return _bstr_t(_result, false);
	}

	_bstr_t IXSLProcessor::GetstartModeURI ( ) {
		BSTR _result = 0;
		HRESULT _hr = get_startModeURI(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IXSLProcessor));
		return _bstr_t(_result, false);
	}

	void IXSLProcessor::Putoutput ( const _variant_t & pOutput ) {
		HRESULT _hr = put_output(pOutput);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IXSLProcessor));
	}

	_variant_t IXSLProcessor::Getoutput ( ) {
		VARIANT _result;
		VariantInit(&_result);
		HRESULT _hr = get_output(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IXSLProcessor));
		return _variant_t(_result, false);
	}

	VARIANT_BOOL IXSLProcessor::transform ( ) {
		VARIANT_BOOL _result = 0;
		HRESULT _hr = raw_transform(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IXSLProcessor));
		return _result;
	}

	HRESULT IXSLProcessor::reset ( ) {
		HRESULT _hr = raw_reset();
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IXSLProcessor));
		return _hr;
	}

	long IXSLProcessor::GetreadyState ( ) {
		long _result = 0;
		HRESULT _hr = get_readyState(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IXSLProcessor));
		return _result;
	}

	HRESULT IXSLProcessor::addParameter ( _bstr_t baseName, const _variant_t & parameter, _bstr_t namespaceURI ) {
		HRESULT _hr = raw_addParameter(baseName, parameter, namespaceURI);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IXSLProcessor));
		return _hr;
	}

	HRESULT IXSLProcessor::addObject ( IDispatch * obj, _bstr_t namespaceURI ) {
		HRESULT _hr = raw_addObject(obj, namespaceURI);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IXSLProcessor));
		return _hr;
	}

	IXMLDOMNodePtr IXSLProcessor::Getstylesheet ( ) {
		struct IXMLDOMNode * _result = 0;
		HRESULT _hr = get_stylesheet(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IXSLProcessor));
		return IXMLDOMNodePtr(_result, false);
	}

	//
	// interface IMXSchemaDeclHandler wrapper method implementations
	//

	HRESULT IMXSchemaDeclHandler::schemaElementDecl ( struct ISchemaElement * oSchemaElement ) {
		HRESULT _hr = raw_schemaElementDecl(oSchemaElement);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IMXSchemaDeclHandler));
		return _hr;
	}

	//
	// interface ISchemaItem wrapper method implementations
	//

	_bstr_t ISchemaItem::Getname ( ) {
		BSTR _result = 0;
		HRESULT _hr = get_name(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(ISchemaItem));
		return _bstr_t(_result, false);
	}

	_bstr_t ISchemaItem::GetnamespaceURI ( ) {
		BSTR _result = 0;
		HRESULT _hr = get_namespaceURI(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(ISchemaItem));
		return _bstr_t(_result, false);
	}

	ISchemaPtr ISchemaItem::Getschema ( ) {
		struct ISchema * _result = 0;
		HRESULT _hr = get_schema(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(ISchemaItem));
		return ISchemaPtr(_result, false);
	}

	_bstr_t ISchemaItem::Getid ( ) {
		BSTR _result = 0;
		HRESULT _hr = get_id(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(ISchemaItem));
		return _bstr_t(_result, false);
	}

	SOMITEMTYPE ISchemaItem::GetitemType ( ) {
		SOMITEMTYPE _result;
		HRESULT _hr = get_itemType(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(ISchemaItem));
		return _result;
	}

	IVBSAXAttributesPtr ISchemaItem::GetunhandledAttributes ( ) {
		struct IVBSAXAttributes * _result = 0;
		HRESULT _hr = get_unhandledAttributes(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(ISchemaItem));
		return IVBSAXAttributesPtr(_result, false);
	}

	VARIANT_BOOL ISchemaItem::writeAnnotation ( IUnknown * annotationSink ) {
		VARIANT_BOOL _result = 0;
		HRESULT _hr = raw_writeAnnotation(annotationSink, &_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(ISchemaItem));
		return _result;
	}

	//
	// interface ISchemaParticle wrapper method implementations
	//

	_variant_t ISchemaParticle::GetminOccurs ( ) {
		VARIANT _result;
		VariantInit(&_result);
		HRESULT _hr = get_minOccurs(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(ISchemaParticle));
		return _variant_t(_result, false);
	}

	_variant_t ISchemaParticle::GetmaxOccurs ( ) {
		VARIANT _result;
		VariantInit(&_result);
		HRESULT _hr = get_maxOccurs(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(ISchemaParticle));
		return _variant_t(_result, false);
	}

	//
	// interface ISchemaItemCollection wrapper method implementations
	//

	ISchemaItemPtr ISchemaItemCollection::Getitem ( long index ) {
		struct ISchemaItem * _result = 0;
		HRESULT _hr = get_item(index, &_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(ISchemaItemCollection));
		return ISchemaItemPtr(_result, false);
	}

	ISchemaItemPtr ISchemaItemCollection::itemByName ( _bstr_t name ) {
		struct ISchemaItem * _result = 0;
		HRESULT _hr = raw_itemByName(name, &_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(ISchemaItemCollection));
		return ISchemaItemPtr(_result, false);
	}

	ISchemaItemPtr ISchemaItemCollection::itemByQName ( _bstr_t name, _bstr_t namespaceURI ) {
		struct ISchemaItem * _result = 0;
		HRESULT _hr = raw_itemByQName(name, namespaceURI, &_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(ISchemaItemCollection));
		return ISchemaItemPtr(_result, false);
	}

	long ISchemaItemCollection::Getlength ( ) {
		long _result = 0;
		HRESULT _hr = get_length(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(ISchemaItemCollection));
		return _result;
	}

	IUnknownPtr ISchemaItemCollection::Get_newEnum ( ) {
		IUnknown * _result = 0;
		HRESULT _hr = get__newEnum(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(ISchemaItemCollection));
		return IUnknownPtr(_result, false);
	}

	//
	// interface ISchema wrapper method implementations
	//

	_bstr_t ISchema::GettargetNamespace ( ) {
		BSTR _result = 0;
		HRESULT _hr = get_targetNamespace(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(ISchema));
		return _bstr_t(_result, false);
	}

	_bstr_t ISchema::Getversion ( ) {
		BSTR _result = 0;
		HRESULT _hr = get_version(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(ISchema));
		return _bstr_t(_result, false);
	}

	ISchemaItemCollectionPtr ISchema::Gettypes ( ) {
		struct ISchemaItemCollection * _result = 0;
		HRESULT _hr = get_types(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(ISchema));
		return ISchemaItemCollectionPtr(_result, false);
	}

	ISchemaItemCollectionPtr ISchema::Getelements ( ) {
		struct ISchemaItemCollection * _result = 0;
		HRESULT _hr = get_elements(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(ISchema));
		return ISchemaItemCollectionPtr(_result, false);
	}

	ISchemaItemCollectionPtr ISchema::Getattributes ( ) {
		struct ISchemaItemCollection * _result = 0;
		HRESULT _hr = get_attributes(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(ISchema));
		return ISchemaItemCollectionPtr(_result, false);
	}

	ISchemaItemCollectionPtr ISchema::GetattributeGroups ( ) {
		struct ISchemaItemCollection * _result = 0;
		HRESULT _hr = get_attributeGroups(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(ISchema));
		return ISchemaItemCollectionPtr(_result, false);
	}

	ISchemaItemCollectionPtr ISchema::GetmodelGroups ( ) {
		struct ISchemaItemCollection * _result = 0;
		HRESULT _hr = get_modelGroups(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(ISchema));
		return ISchemaItemCollectionPtr(_result, false);
	}

	ISchemaItemCollectionPtr ISchema::Getnotations ( ) {
		struct ISchemaItemCollection * _result = 0;
		HRESULT _hr = get_notations(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(ISchema));
		return ISchemaItemCollectionPtr(_result, false);
	}

	ISchemaStringCollectionPtr ISchema::GetschemaLocations ( ) {
		struct ISchemaStringCollection * _result = 0;
		HRESULT _hr = get_schemaLocations(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(ISchema));
		return ISchemaStringCollectionPtr(_result, false);
	}

	//
	// interface ISchemaType wrapper method implementations
	//

	ISchemaItemCollectionPtr ISchemaType::GetbaseTypes ( ) {
		struct ISchemaItemCollection * _result = 0;
		HRESULT _hr = get_baseTypes(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(ISchemaType));
		return ISchemaItemCollectionPtr(_result, false);
	}

	SCHEMADERIVATIONMETHOD ISchemaType::Getfinal ( ) {
		SCHEMADERIVATIONMETHOD _result;
		HRESULT _hr = get_final(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(ISchemaType));
		return _result;
	}

	SCHEMATYPEVARIETY ISchemaType::Getvariety ( ) {
		SCHEMATYPEVARIETY _result;
		HRESULT _hr = get_variety(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(ISchemaType));
		return _result;
	}

	SCHEMADERIVATIONMETHOD ISchemaType::GetderivedBy ( ) {
		SCHEMADERIVATIONMETHOD _result;
		HRESULT _hr = get_derivedBy(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(ISchemaType));
		return _result;
	}

	VARIANT_BOOL ISchemaType::isValid ( _bstr_t data ) {
		VARIANT_BOOL _result = 0;
		HRESULT _hr = raw_isValid(data, &_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(ISchemaType));
		return _result;
	}

	_bstr_t ISchemaType::GetminExclusive ( ) {
		BSTR _result = 0;
		HRESULT _hr = get_minExclusive(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(ISchemaType));
		return _bstr_t(_result, false);
	}

	_bstr_t ISchemaType::GetminInclusive ( ) {
		BSTR _result = 0;
		HRESULT _hr = get_minInclusive(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(ISchemaType));
		return _bstr_t(_result, false);
	}

	_bstr_t ISchemaType::GetmaxExclusive ( ) {
		BSTR _result = 0;
		HRESULT _hr = get_maxExclusive(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(ISchemaType));
		return _bstr_t(_result, false);
	}

	_bstr_t ISchemaType::GetmaxInclusive ( ) {
		BSTR _result = 0;
		HRESULT _hr = get_maxInclusive(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(ISchemaType));
		return _bstr_t(_result, false);
	}

	_variant_t ISchemaType::GettotalDigits ( ) {
		VARIANT _result;
		VariantInit(&_result);
		HRESULT _hr = get_totalDigits(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(ISchemaType));
		return _variant_t(_result, false);
	}

	_variant_t ISchemaType::GetfractionDigits ( ) {
		VARIANT _result;
		VariantInit(&_result);
		HRESULT _hr = get_fractionDigits(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(ISchemaType));
		return _variant_t(_result, false);
	}

	_variant_t ISchemaType::Getlength ( ) {
		VARIANT _result;
		VariantInit(&_result);
		HRESULT _hr = get_length(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(ISchemaType));
		return _variant_t(_result, false);
	}

	_variant_t ISchemaType::GetminLength ( ) {
		VARIANT _result;
		VariantInit(&_result);
		HRESULT _hr = get_minLength(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(ISchemaType));
		return _variant_t(_result, false);
	}

	_variant_t ISchemaType::GetmaxLength ( ) {
		VARIANT _result;
		VariantInit(&_result);
		HRESULT _hr = get_maxLength(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(ISchemaType));
		return _variant_t(_result, false);
	}

	ISchemaStringCollectionPtr ISchemaType::Getenumeration ( ) {
		struct ISchemaStringCollection * _result = 0;
		HRESULT _hr = get_enumeration(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(ISchemaType));
		return ISchemaStringCollectionPtr(_result, false);
	}

	SCHEMAWHITESPACE ISchemaType::Getwhitespace ( ) {
		SCHEMAWHITESPACE _result;
		HRESULT _hr = get_whitespace(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(ISchemaType));
		return _result;
	}

	ISchemaStringCollectionPtr ISchemaType::Getpatterns ( ) {
		struct ISchemaStringCollection * _result = 0;
		HRESULT _hr = get_patterns(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(ISchemaType));
		return ISchemaStringCollectionPtr(_result, false);
	}

	//
	// interface ISchemaAny wrapper method implementations
	//

	ISchemaStringCollectionPtr ISchemaAny::Getnamespaces ( ) {
		struct ISchemaStringCollection * _result = 0;
		HRESULT _hr = get_namespaces(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(ISchemaAny));
		return ISchemaStringCollectionPtr(_result, false);
	}

	SCHEMAPROCESSCONTENTS ISchemaAny::GetprocessContents ( ) {
		SCHEMAPROCESSCONTENTS _result;
		HRESULT _hr = get_processContents(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(ISchemaAny));
		return _result;
	}

	//
	// interface ISchemaModelGroup wrapper method implementations
	//

	ISchemaItemCollectionPtr ISchemaModelGroup::Getparticles ( ) {
		struct ISchemaItemCollection * _result = 0;
		HRESULT _hr = get_particles(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(ISchemaModelGroup));
		return ISchemaItemCollectionPtr(_result, false);
	}

	//
	// interface ISchemaComplexType wrapper method implementations
	//

	VARIANT_BOOL ISchemaComplexType::GetisAbstract ( ) {
		VARIANT_BOOL _result = 0;
		HRESULT _hr = get_isAbstract(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(ISchemaComplexType));
		return _result;
	}

	ISchemaAnyPtr ISchemaComplexType::GetanyAttribute ( ) {
		struct ISchemaAny * _result = 0;
		HRESULT _hr = get_anyAttribute(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(ISchemaComplexType));
		return ISchemaAnyPtr(_result, false);
	}

	ISchemaItemCollectionPtr ISchemaComplexType::Getattributes ( ) {
		struct ISchemaItemCollection * _result = 0;
		HRESULT _hr = get_attributes(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(ISchemaComplexType));
		return ISchemaItemCollectionPtr(_result, false);
	}

	SCHEMACONTENTTYPE ISchemaComplexType::GetcontentType ( ) {
		SCHEMACONTENTTYPE _result;
		HRESULT _hr = get_contentType(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(ISchemaComplexType));
		return _result;
	}

	ISchemaModelGroupPtr ISchemaComplexType::GetcontentModel ( ) {
		struct ISchemaModelGroup * _result = 0;
		HRESULT _hr = get_contentModel(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(ISchemaComplexType));
		return ISchemaModelGroupPtr(_result, false);
	}

	SCHEMADERIVATIONMETHOD ISchemaComplexType::GetprohibitedSubstitutions ( ) {
		SCHEMADERIVATIONMETHOD _result;
		HRESULT _hr = get_prohibitedSubstitutions(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(ISchemaComplexType));
		return _result;
	}

	//
	// interface ISchemaElement wrapper method implementations
	//

	ISchemaTypePtr ISchemaElement::Gettype ( ) {
		struct ISchemaType * _result = 0;
		HRESULT _hr = get_type(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(ISchemaElement));
		return ISchemaTypePtr(_result, false);
	}

	ISchemaComplexTypePtr ISchemaElement::Getscope ( ) {
		struct ISchemaComplexType * _result = 0;
		HRESULT _hr = get_scope(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(ISchemaElement));
		return ISchemaComplexTypePtr(_result, false);
	}

	_bstr_t ISchemaElement::GetdefaultValue ( ) {
		BSTR _result = 0;
		HRESULT _hr = get_defaultValue(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(ISchemaElement));
		return _bstr_t(_result, false);
	}

	_bstr_t ISchemaElement::GetfixedValue ( ) {
		BSTR _result = 0;
		HRESULT _hr = get_fixedValue(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(ISchemaElement));
		return _bstr_t(_result, false);
	}

	VARIANT_BOOL ISchemaElement::GetisNillable ( ) {
		VARIANT_BOOL _result = 0;
		HRESULT _hr = get_isNillable(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(ISchemaElement));
		return _result;
	}

	ISchemaItemCollectionPtr ISchemaElement::GetidentityConstraints ( ) {
		struct ISchemaItemCollection * _result = 0;
		HRESULT _hr = get_identityConstraints(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(ISchemaElement));
		return ISchemaItemCollectionPtr(_result, false);
	}

	ISchemaElementPtr ISchemaElement::GetsubstitutionGroup ( ) {
		struct ISchemaElement * _result = 0;
		HRESULT _hr = get_substitutionGroup(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(ISchemaElement));
		return ISchemaElementPtr(_result, false);
	}

	SCHEMADERIVATIONMETHOD ISchemaElement::GetsubstitutionGroupExclusions ( ) {
		SCHEMADERIVATIONMETHOD _result;
		HRESULT _hr = get_substitutionGroupExclusions(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(ISchemaElement));
		return _result;
	}

	SCHEMADERIVATIONMETHOD ISchemaElement::GetdisallowedSubstitutions ( ) {
		SCHEMADERIVATIONMETHOD _result;
		HRESULT _hr = get_disallowedSubstitutions(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(ISchemaElement));
		return _result;
	}

	VARIANT_BOOL ISchemaElement::GetisAbstract ( ) {
		VARIANT_BOOL _result = 0;
		HRESULT _hr = get_isAbstract(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(ISchemaElement));
		return _result;
	}

	VARIANT_BOOL ISchemaElement::GetisReference ( ) {
		VARIANT_BOOL _result = 0;
		HRESULT _hr = get_isReference(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(ISchemaElement));
		return _result;
	}

	//
	// interface IXMLDOMSchemaCollection2 wrapper method implementations
	//

	HRESULT IXMLDOMSchemaCollection2::validate ( ) {
		HRESULT _hr = raw_validate();
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IXMLDOMSchemaCollection2));
		return _hr;
	}

	void IXMLDOMSchemaCollection2::PutvalidateOnLoad ( VARIANT_BOOL validateOnLoad ) {
		HRESULT _hr = put_validateOnLoad(validateOnLoad);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IXMLDOMSchemaCollection2));
	}

	VARIANT_BOOL IXMLDOMSchemaCollection2::GetvalidateOnLoad ( ) {
		VARIANT_BOOL _result = 0;
		HRESULT _hr = get_validateOnLoad(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IXMLDOMSchemaCollection2));
		return _result;
	}

	ISchemaPtr IXMLDOMSchemaCollection2::getSchema ( _bstr_t namespaceURI ) {
		struct ISchema * _result = 0;
		HRESULT _hr = raw_getSchema(namespaceURI, &_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IXMLDOMSchemaCollection2));
		return ISchemaPtr(_result, false);
	}

	ISchemaItemPtr IXMLDOMSchemaCollection2::getDeclaration ( struct IXMLDOMNode * node ) {
		struct ISchemaItem * _result = 0;
		HRESULT _hr = raw_getDeclaration(node, &_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(IXMLDOMSchemaCollection2));
		return ISchemaItemPtr(_result, false);
	}

	//
	// interface ISchemaAttribute wrapper method implementations
	//

	ISchemaTypePtr ISchemaAttribute::Gettype ( ) {
		struct ISchemaType * _result = 0;
		HRESULT _hr = get_type(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(ISchemaAttribute));
		return ISchemaTypePtr(_result, false);
	}

	ISchemaComplexTypePtr ISchemaAttribute::Getscope ( ) {
		struct ISchemaComplexType * _result = 0;
		HRESULT _hr = get_scope(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(ISchemaAttribute));
		return ISchemaComplexTypePtr(_result, false);
	}

	_bstr_t ISchemaAttribute::GetdefaultValue ( ) {
		BSTR _result = 0;
		HRESULT _hr = get_defaultValue(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(ISchemaAttribute));
		return _bstr_t(_result, false);
	}

	_bstr_t ISchemaAttribute::GetfixedValue ( ) {
		BSTR _result = 0;
		HRESULT _hr = get_fixedValue(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(ISchemaAttribute));
		return _bstr_t(_result, false);
	}

	SCHEMAUSE ISchemaAttribute::Getuse ( ) {
		SCHEMAUSE _result;
		HRESULT _hr = get_use(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(ISchemaAttribute));
		return _result;
	}

	VARIANT_BOOL ISchemaAttribute::GetisReference ( ) {
		VARIANT_BOOL _result = 0;
		HRESULT _hr = get_isReference(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(ISchemaAttribute));
		return _result;
	}

	//
	// interface ISchemaAttributeGroup wrapper method implementations
	//

	ISchemaAnyPtr ISchemaAttributeGroup::GetanyAttribute ( ) {
		struct ISchemaAny * _result = 0;
		HRESULT _hr = get_anyAttribute(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(ISchemaAttributeGroup));
		return ISchemaAnyPtr(_result, false);
	}

	ISchemaItemCollectionPtr ISchemaAttributeGroup::Getattributes ( ) {
		struct ISchemaItemCollection * _result = 0;
		HRESULT _hr = get_attributes(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(ISchemaAttributeGroup));
		return ISchemaItemCollectionPtr(_result, false);
	}

	//
	// interface ISchemaIdentityConstraint wrapper method implementations
	//

	_bstr_t ISchemaIdentityConstraint::Getselector ( ) {
		BSTR _result = 0;
		HRESULT _hr = get_selector(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(ISchemaIdentityConstraint));
		return _bstr_t(_result, false);
	}

	ISchemaStringCollectionPtr ISchemaIdentityConstraint::Getfields ( ) {
		struct ISchemaStringCollection * _result = 0;
		HRESULT _hr = get_fields(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(ISchemaIdentityConstraint));
		return ISchemaStringCollectionPtr(_result, false);
	}

	ISchemaIdentityConstraintPtr ISchemaIdentityConstraint::GetreferencedKey ( ) {
		struct ISchemaIdentityConstraint * _result = 0;
		HRESULT _hr = get_referencedKey(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(ISchemaIdentityConstraint));
		return ISchemaIdentityConstraintPtr(_result, false);
	}

	//
	// interface ISchemaNotation wrapper method implementations
	//

	_bstr_t ISchemaNotation::GetsystemIdentifier ( ) {
		BSTR _result = 0;
		HRESULT _hr = get_systemIdentifier(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(ISchemaNotation));
		return _bstr_t(_result, false);
	}

	_bstr_t ISchemaNotation::GetpublicIdentifier ( ) {
		BSTR _result = 0;
		HRESULT _hr = get_publicIdentifier(&_result);
		if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(ISchemaNotation));
		return _bstr_t(_result, false);
	}

}
