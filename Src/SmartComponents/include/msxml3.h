﻿// Created by Microsoft (R) C/C++ Compiler Version 15.00.21022.08 (a412cb33).
//
// D:\DOCUME~1\ADMINI~1\LOCALS~1\Temp\msxml3.tlh
//
// C++ source equivalent of Win32 type library F5078F18-C551-11D3-89B9-0000F81FE221
// compiler-generated file created 05/07/09 at 11:19:07 - DO NOT EDIT!

#pragma once
#pragma pack(push, 8)

#include <comdef.h>

#include "Compatibility.h"

namespace MSXML2 {

//
// Forward references and typedefs
//

struct __declspec(uuid("f5078f18-c551-11d3-89b9-0000f81fe221"))
/* LIBID */ __MSXML2;
struct __declspec(uuid("2933bf8f-7b36-11d2-b20e-00c04f983e60"))
/* dual interface */ IXMLDOMImplementation;
struct __declspec(uuid("2933bf80-7b36-11d2-b20e-00c04f983e60"))
/* dual interface */ IXMLDOMNode;
TagENUM tagDOMNodeType;
struct __declspec(uuid("2933bf82-7b36-11d2-b20e-00c04f983e60"))
/* dual interface */ IXMLDOMNodeList;
struct __declspec(uuid("2933bf83-7b36-11d2-b20e-00c04f983e60"))
/* dual interface */ IXMLDOMNamedNodeMap;
struct __declspec(uuid("2933bf81-7b36-11d2-b20e-00c04f983e60"))
/* dual interface */ IXMLDOMDocument;
struct __declspec(uuid("2933bf8b-7b36-11d2-b20e-00c04f983e60"))
/* dual interface */ IXMLDOMDocumentType;
struct __declspec(uuid("2933bf86-7b36-11d2-b20e-00c04f983e60"))
/* dual interface */ IXMLDOMElement;
struct __declspec(uuid("2933bf85-7b36-11d2-b20e-00c04f983e60"))
/* dual interface */ IXMLDOMAttribute;
struct __declspec(uuid("3efaa413-272f-11d2-836f-0000f87a7782"))
/* dual interface */ IXMLDOMDocumentFragment;
struct __declspec(uuid("2933bf87-7b36-11d2-b20e-00c04f983e60"))
/* dual interface */ IXMLDOMText;
struct __declspec(uuid("2933bf84-7b36-11d2-b20e-00c04f983e60"))
/* dual interface */ IXMLDOMCharacterData;
struct __declspec(uuid("2933bf88-7b36-11d2-b20e-00c04f983e60"))
/* dual interface */ IXMLDOMComment;
struct __declspec(uuid("2933bf8a-7b36-11d2-b20e-00c04f983e60"))
/* dual interface */ IXMLDOMCDATASection;
struct __declspec(uuid("2933bf89-7b36-11d2-b20e-00c04f983e60"))
/* dual interface */ IXMLDOMProcessingInstruction;
struct __declspec(uuid("2933bf8e-7b36-11d2-b20e-00c04f983e60"))
/* dual interface */ IXMLDOMEntityReference;
struct __declspec(uuid("3efaa426-272f-11d2-836f-0000f87a7782"))
/* dual interface */ IXMLDOMParseError;
struct __declspec(uuid("2933bf95-7b36-11d2-b20e-00c04f983e60"))
/* dual interface */ IXMLDOMDocument2;
struct __declspec(uuid("373984c8-b845-449b-91e7-45ac83036ade"))
/* dual interface */ IXMLDOMSchemaCollection;
struct __declspec(uuid("2933bf96-7b36-11d2-b20e-00c04f983e60"))
/* dual interface */ IXMLDOMDocument3;
struct __declspec(uuid("2933bf8c-7b36-11d2-b20e-00c04f983e60"))
/* dual interface */ IXMLDOMNotation;
struct __declspec(uuid("2933bf8d-7b36-11d2-b20e-00c04f983e60"))
/* dual interface */ IXMLDOMEntity;
struct __declspec(uuid("3efaa428-272f-11d2-836f-0000f87a7782"))
/* dual interface */ IXMLDOMParseError2;
struct __declspec(uuid("3efaa429-272f-11d2-836f-0000f87a7782"))
/* dual interface */ IXMLDOMParseErrorCollection;
struct __declspec(uuid("3efaa425-272f-11d2-836f-0000f87a7782"))
/* dual interface */ IXTLRuntime;
struct __declspec(uuid("2933bf93-7b36-11d2-b20e-00c04f983e60"))
/* dual interface */ IXSLTemplate;
struct __declspec(uuid("2933bf92-7b36-11d2-b20e-00c04f983e60"))
/* dual interface */ IXSLProcessor;
struct __declspec(uuid("a4f96ed0-f829-476e-81c0-cdc7bd2a0802"))
/* interface */ ISAXXMLReader;
struct __declspec(uuid("99bca7bd-e8c4-4d5f-a0cf-6d907901ff07"))
/* interface */ ISAXEntityResolver;
struct __declspec(uuid("1545cdfa-9e4e-4497-a8a4-2bf7d0112c44"))
/* interface */ ISAXContentHandler;
struct __declspec(uuid("9b7e472a-0de4-4640-bff3-84d38a051c31"))
/* interface */ ISAXLocator;
struct __declspec(uuid("f078abe1-45d2-4832-91ea-4466ce2f25c9"))
/* interface */ ISAXAttributes;
struct __declspec(uuid("e15c1baf-afb3-4d60-8c36-19a8c45defed"))
/* interface */ ISAXDTDHandler;
struct __declspec(uuid("a60511c4-ccf5-479e-98a3-dc8dc545b7d0"))
/* interface */ ISAXErrorHandler;
struct __declspec(uuid("70409222-ca09-4475-acb8-40312fe8d145"))
/* interface */ ISAXXMLFilter;
struct __declspec(uuid("7f85d5f5-47a8-4497-bda5-84ba04819ea6"))
/* interface */ ISAXLexicalHandler;
struct __declspec(uuid("862629ac-771a-47b2-8337-4e6843c1be90"))
/* interface */ ISAXDeclHandler;
struct __declspec(uuid("8c033caa-6cd6-4f73-b728-4531af74945f"))
/* dual interface */ IVBSAXXMLReader;
struct __declspec(uuid("0c05d096-f45b-4aca-ad1a-aa0bc25518dc"))
/* dual interface */ IVBSAXEntityResolver;
struct __declspec(uuid("2ed7290a-4dd5-4b46-bb26-4e4155e77faa"))
/* dual interface */ IVBSAXContentHandler;
struct __declspec(uuid("796e7ac5-5aa2-4eff-acad-3faaf01a3288"))
/* dual interface */ IVBSAXLocator;
struct __declspec(uuid("10dc0586-132b-4cac-8bb3-db00ac8b7ee0"))
/* dual interface */ IVBSAXAttributes;
struct __declspec(uuid("24fb3297-302d-4620-ba39-3a732d850558"))
/* dual interface */ IVBSAXDTDHandler;
struct __declspec(uuid("d963d3fe-173c-4862-9095-b92f66995f52"))
/* dual interface */ IVBSAXErrorHandler;
struct __declspec(uuid("1299eb1b-5b88-433e-82de-82ca75ad4e04"))
/* dual interface */ IVBSAXXMLFilter;
struct __declspec(uuid("032aac35-8c0e-4d9d-979f-e3b702935576"))
/* dual interface */ IVBSAXLexicalHandler;
struct __declspec(uuid("e8917260-7579-4be1-b5dd-7afbfa6f077b"))
/* dual interface */ IVBSAXDeclHandler;
struct __declspec(uuid("4d7ff4ba-1565-4ea8-94e1-6e724a46f98d"))
/* dual interface */ IMXWriter;
struct __declspec(uuid("f10d27cc-3ec0-415c-8ed8-77ab1c5e7262"))
/* dual interface */ IMXAttributes;
struct __declspec(uuid("808f4e35-8d5a-4fbe-8466-33a41279ed30"))
/* dual interface */ IMXReaderControl;
struct __declspec(uuid("fa4bb38c-faf9-4cca-9302-d1dd0fe520db"))
/* dual interface */ IMXSchemaDeclHandler;
struct __declspec(uuid("50ea08b7-dd1b-4664-9a50-c2f40f4bd79a"))
/* dual interface */ ISchemaElement;
struct __declspec(uuid("50ea08b5-dd1b-4664-9a50-c2f40f4bd79a"))
/* dual interface */ ISchemaParticle;
struct __declspec(uuid("50ea08b3-dd1b-4664-9a50-c2f40f4bd79a"))
/* dual interface */ ISchemaItem;
struct __declspec(uuid("50ea08b4-dd1b-4664-9a50-c2f40f4bd79a"))
/* dual interface */ ISchema;
struct __declspec(uuid("50ea08b2-dd1b-4664-9a50-c2f40f4bd79a"))
/* dual interface */ ISchemaItemCollection;
struct __declspec(uuid("50ea08b1-dd1b-4664-9a50-c2f40f4bd79a"))
/* dual interface */ ISchemaStringCollection;
TagENUM _SOMITEMTYPE;
struct __declspec(uuid("50ea08b8-dd1b-4664-9a50-c2f40f4bd79a"))
/* dual interface */ ISchemaType;
TagENUM _SCHEMADERIVATIONMETHOD;
TagENUM _SCHEMATYPEVARIETY;
TagENUM _SCHEMAWHITESPACE;
struct __declspec(uuid("50ea08b9-dd1b-4664-9a50-c2f40f4bd79a"))
/* dual interface */ ISchemaComplexType;
struct __declspec(uuid("50ea08bc-dd1b-4664-9a50-c2f40f4bd79a"))
/* dual interface */ ISchemaAny;
TagENUM _SCHEMAPROCESSCONTENTS;
TagENUM _SCHEMACONTENTTYPE;
struct __declspec(uuid("50ea08bb-dd1b-4664-9a50-c2f40f4bd79a"))
/* dual interface */ ISchemaModelGroup;
struct __declspec(uuid("c90352f7-643c-4fbc-bb23-e996eb2d51fd"))
/* dual interface */ IMXXMLFilter;
struct __declspec(uuid("50ea08b0-dd1b-4664-9a50-c2f40f4bd79a"))
/* dual interface */ IXMLDOMSchemaCollection2;
struct __declspec(uuid("50ea08b6-dd1b-4664-9a50-c2f40f4bd79a"))
/* dual interface */ ISchemaAttribute;
TagENUM _SCHEMAUSE;
struct __declspec(uuid("50ea08ba-dd1b-4664-9a50-c2f40f4bd79a"))
/* dual interface */ ISchemaAttributeGroup;
struct __declspec(uuid("50ea08bd-dd1b-4664-9a50-c2f40f4bd79a"))
/* dual interface */ ISchemaIdentityConstraint;
struct __declspec(uuid("50ea08be-dd1b-4664-9a50-c2f40f4bd79a"))
/* dual interface */ ISchemaNotation;
struct __declspec(uuid("65725580-9b5d-11d0-9bfe-00c04fc99c8e"))
/* dual interface */ IXMLElementCollection;
struct __declspec(uuid("f52e2b61-18a1-11d1-b105-00805f49916b"))
/* dual interface */ IXMLDocument;
struct __declspec(uuid("3f7f31ac-e15f-11d0-9c25-00c04fc99c8e"))
/* dual interface */ IXMLElement;
struct __declspec(uuid("2b8de2fe-8d2d-11d1-b2fc-00c04fd915a9"))
/* interface */ IXMLDocument2;
struct __declspec(uuid("2b8de2ff-8d2d-11d1-b2fc-00c04fd915a9"))
/* dual interface */ IXMLElement2;
struct __declspec(uuid("d4d4a0fc-3b73-11d1-b2b4-00c04fb92596"))
/* dual interface */ IXMLAttribute;
struct __declspec(uuid("948c5ad3-c58d-11d0-9c0b-00c04fc99c8e"))
/* interface */ IXMLError;
struct _xml_error;
TagENUM tagXMLEMEM_TYPE;
struct __declspec(uuid("aa634fc7-5888-44a7-a257-3a47150d3a0e"))
/* dual interface */ IXMLDOMSelection;
struct __declspec(uuid("3efaa427-272f-11d2-836f-0000f87a7782"))
/* dispinterface */ XMLDOMDocumentEvents;
struct __declspec(uuid("310afa62-0575-11d2-9ca9-0060b0ec3d39"))
/* dual interface */ IDSOControl;
struct __declspec(uuid("ed8c108d-4349-11d2-91a4-00c04f7969e8"))
/* dual interface */ IXMLHTTPRequest;
TagENUM _SERVERXMLHTTP_OPTION;
TagENUM _SXH_SERVER_CERT_OPTION;
TagENUM _SXH_PROXY_SETTING;
struct __declspec(uuid("2e9196bf-13ba-4dd4-91ca-6c571f281495"))
/* dual interface */ IServerXMLHTTPRequest;
struct __declspec(uuid("2e01311b-c322-4b0a-bd77-b90cfdc8dce7"))
/* dual interface */ IServerXMLHTTPRequest2;
struct __declspec(uuid("c90352f4-643c-4fbc-bb23-e996eb2d51fd"))
/* dual interface */ IMXNamespacePrefixes;
struct __declspec(uuid("c90352f5-643c-4fbc-bb23-e996eb2d51fd"))
/* dual interface */ IVBMXNamespaceManager;
struct __declspec(uuid("c90352f6-643c-4fbc-bb23-e996eb2d51fd"))
/* interface */ IMXNamespaceManager;
struct /* coclass */ DOMDocument;
struct /* coclass */ DOMDocument26;
struct /* coclass */ DOMDocument30;
struct /* coclass */ DOMDocument40;
struct /* coclass */ DOMDocument60;
struct /* coclass */ FreeThreadedDOMDocument;
struct /* coclass */ FreeThreadedDOMDocument26;
struct /* coclass */ FreeThreadedDOMDocument30;
struct /* coclass */ FreeThreadedDOMDocument40;
struct /* coclass */ FreeThreadedDOMDocument60;
struct /* coclass */ XMLSchemaCache;
struct /* coclass */ XMLSchemaCache26;
struct /* coclass */ XMLSchemaCache30;
struct /* coclass */ XMLSchemaCache40;
struct /* coclass */ XMLSchemaCache60;
struct /* coclass */ XSLTemplate;
struct /* coclass */ XSLTemplate26;
struct /* coclass */ XSLTemplate30;
struct /* coclass */ XSLTemplate40;
struct /* coclass */ XSLTemplate60;
struct /* coclass */ DSOControl;
struct /* coclass */ DSOControl26;
struct /* coclass */ DSOControl30;
struct /* coclass */ DSOControl40;
struct /* coclass */ XMLHTTP;
struct /* coclass */ XMLHTTP26;
struct /* coclass */ XMLHTTP30;
struct /* coclass */ XMLHTTP40;
struct /* coclass */ XMLHTTP60;
struct /* coclass */ ServerXMLHTTP;
struct /* coclass */ ServerXMLHTTP30;
struct /* coclass */ ServerXMLHTTP40;
struct /* coclass */ ServerXMLHTTP60;
struct /* coclass */ SAXXMLReader;
struct /* coclass */ SAXXMLReader30;
struct /* coclass */ SAXXMLReader40;
struct /* coclass */ SAXXMLReader60;
struct /* coclass */ MXXMLWriter;
struct /* coclass */ MXXMLWriter30;
struct /* coclass */ MXXMLWriter40;
struct /* coclass */ MXXMLWriter60;
struct /* coclass */ MXHTMLWriter;
struct /* coclass */ MXHTMLWriter30;
struct /* coclass */ MXHTMLWriter40;
struct /* coclass */ MXHTMLWriter60;
struct /* coclass */ SAXAttributes;
struct /* coclass */ SAXAttributes30;
struct /* coclass */ SAXAttributes40;
struct /* coclass */ SAXAttributes60;
struct /* coclass */ MXNamespaceManager;
struct /* coclass */ MXNamespaceManager40;
struct /* coclass */ MXNamespaceManager60;
struct /* coclass */ XMLDocument;
typedef enum tagDOMNodeType DOMNodeType;
typedef enum _SOMITEMTYPE SOMITEMTYPE;
typedef enum _SCHEMADERIVATIONMETHOD SCHEMADERIVATIONMETHOD;
typedef enum _SCHEMATYPEVARIETY SCHEMATYPEVARIETY;
typedef enum _SCHEMAWHITESPACE SCHEMAWHITESPACE;
typedef enum _SCHEMAPROCESSCONTENTS SCHEMAPROCESSCONTENTS;
typedef enum _SCHEMACONTENTTYPE SCHEMACONTENTTYPE;
typedef enum _SCHEMAUSE SCHEMAUSE;
typedef enum tagXMLEMEM_TYPE XMLELEM_TYPE;
typedef enum _SERVERXMLHTTP_OPTION SERVERXMLHTTP_OPTION;
typedef enum _SXH_SERVER_CERT_OPTION SXH_SERVER_CERT_OPTION;
typedef enum _SXH_PROXY_SETTING SXH_PROXY_SETTING;

//
// Smart pointer typedef declarations
//

_COM_SMARTPTR_TYPEDEF(IXMLDOMImplementation, __uuidof(IXMLDOMImplementation));
_COM_SMARTPTR_TYPEDEF(IXMLDOMParseError, __uuidof(IXMLDOMParseError));
_COM_SMARTPTR_TYPEDEF(ISAXEntityResolver, __uuidof(ISAXEntityResolver));
_COM_SMARTPTR_TYPEDEF(ISAXLocator, __uuidof(ISAXLocator));
_COM_SMARTPTR_TYPEDEF(ISAXAttributes, __uuidof(ISAXAttributes));
_COM_SMARTPTR_TYPEDEF(ISAXContentHandler, __uuidof(ISAXContentHandler));
_COM_SMARTPTR_TYPEDEF(ISAXDTDHandler, __uuidof(ISAXDTDHandler));
_COM_SMARTPTR_TYPEDEF(ISAXErrorHandler, __uuidof(ISAXErrorHandler));
_COM_SMARTPTR_TYPEDEF(ISAXXMLReader, __uuidof(ISAXXMLReader));
_COM_SMARTPTR_TYPEDEF(ISAXXMLFilter, __uuidof(ISAXXMLFilter));
_COM_SMARTPTR_TYPEDEF(ISAXLexicalHandler, __uuidof(ISAXLexicalHandler));
_COM_SMARTPTR_TYPEDEF(ISAXDeclHandler, __uuidof(ISAXDeclHandler));
_COM_SMARTPTR_TYPEDEF(IVBSAXEntityResolver, __uuidof(IVBSAXEntityResolver));
_COM_SMARTPTR_TYPEDEF(IVBSAXLocator, __uuidof(IVBSAXLocator));
_COM_SMARTPTR_TYPEDEF(IVBSAXAttributes, __uuidof(IVBSAXAttributes));
_COM_SMARTPTR_TYPEDEF(IVBSAXContentHandler, __uuidof(IVBSAXContentHandler));
_COM_SMARTPTR_TYPEDEF(IVBSAXDTDHandler, __uuidof(IVBSAXDTDHandler));
_COM_SMARTPTR_TYPEDEF(IVBSAXErrorHandler, __uuidof(IVBSAXErrorHandler));
_COM_SMARTPTR_TYPEDEF(IVBSAXXMLReader, __uuidof(IVBSAXXMLReader));
_COM_SMARTPTR_TYPEDEF(IVBSAXXMLFilter, __uuidof(IVBSAXXMLFilter));
_COM_SMARTPTR_TYPEDEF(IVBSAXLexicalHandler, __uuidof(IVBSAXLexicalHandler));
_COM_SMARTPTR_TYPEDEF(IVBSAXDeclHandler, __uuidof(IVBSAXDeclHandler));
_COM_SMARTPTR_TYPEDEF(IMXWriter, __uuidof(IMXWriter));
_COM_SMARTPTR_TYPEDEF(IMXAttributes, __uuidof(IMXAttributes));
_COM_SMARTPTR_TYPEDEF(IMXReaderControl, __uuidof(IMXReaderControl));
_COM_SMARTPTR_TYPEDEF(ISchemaStringCollection, __uuidof(ISchemaStringCollection));
_COM_SMARTPTR_TYPEDEF(IMXXMLFilter, __uuidof(IMXXMLFilter));
_COM_SMARTPTR_TYPEDEF(IXMLElementCollection, __uuidof(IXMLElementCollection));
_COM_SMARTPTR_TYPEDEF(IXMLElement, __uuidof(IXMLElement));
_COM_SMARTPTR_TYPEDEF(IXMLDocument, __uuidof(IXMLDocument));
_COM_SMARTPTR_TYPEDEF(IXMLElement2, __uuidof(IXMLElement2));
_COM_SMARTPTR_TYPEDEF(IXMLDocument2, __uuidof(IXMLDocument2));
_COM_SMARTPTR_TYPEDEF(IXMLAttribute, __uuidof(IXMLAttribute));
_COM_SMARTPTR_TYPEDEF(IXMLError, __uuidof(IXMLError));
_COM_SMARTPTR_TYPEDEF(XMLDOMDocumentEvents, __uuidof(XMLDOMDocumentEvents));
_COM_SMARTPTR_TYPEDEF(IXMLHTTPRequest, __uuidof(IXMLHTTPRequest));
_COM_SMARTPTR_TYPEDEF(IServerXMLHTTPRequest, __uuidof(IServerXMLHTTPRequest));
_COM_SMARTPTR_TYPEDEF(IServerXMLHTTPRequest2, __uuidof(IServerXMLHTTPRequest2));
_COM_SMARTPTR_TYPEDEF(IMXNamespacePrefixes, __uuidof(IMXNamespacePrefixes));
_COM_SMARTPTR_TYPEDEF(IXMLDOMNode, __uuidof(IXMLDOMNode));
_COM_SMARTPTR_TYPEDEF(IXMLDOMNodeList, __uuidof(IXMLDOMNodeList));
_COM_SMARTPTR_TYPEDEF(IXMLDOMNamedNodeMap, __uuidof(IXMLDOMNamedNodeMap));
_COM_SMARTPTR_TYPEDEF(IXMLDOMDocumentType, __uuidof(IXMLDOMDocumentType));
_COM_SMARTPTR_TYPEDEF(IXMLDOMAttribute, __uuidof(IXMLDOMAttribute));
_COM_SMARTPTR_TYPEDEF(IXMLDOMElement, __uuidof(IXMLDOMElement));
_COM_SMARTPTR_TYPEDEF(IXMLDOMDocumentFragment, __uuidof(IXMLDOMDocumentFragment));
_COM_SMARTPTR_TYPEDEF(IXMLDOMCharacterData, __uuidof(IXMLDOMCharacterData));
_COM_SMARTPTR_TYPEDEF(IXMLDOMText, __uuidof(IXMLDOMText));
_COM_SMARTPTR_TYPEDEF(IXMLDOMComment, __uuidof(IXMLDOMComment));
_COM_SMARTPTR_TYPEDEF(IXMLDOMCDATASection, __uuidof(IXMLDOMCDATASection));
_COM_SMARTPTR_TYPEDEF(IXMLDOMProcessingInstruction, __uuidof(IXMLDOMProcessingInstruction));
_COM_SMARTPTR_TYPEDEF(IXMLDOMEntityReference, __uuidof(IXMLDOMEntityReference));
_COM_SMARTPTR_TYPEDEF(IXMLDOMDocument, __uuidof(IXMLDOMDocument));
_COM_SMARTPTR_TYPEDEF(IXMLDOMSchemaCollection, __uuidof(IXMLDOMSchemaCollection));
_COM_SMARTPTR_TYPEDEF(IXMLDOMDocument2, __uuidof(IXMLDOMDocument2));
_COM_SMARTPTR_TYPEDEF(IXMLDOMDocument3, __uuidof(IXMLDOMDocument3));
_COM_SMARTPTR_TYPEDEF(IXMLDOMNotation, __uuidof(IXMLDOMNotation));
_COM_SMARTPTR_TYPEDEF(IXMLDOMEntity, __uuidof(IXMLDOMEntity));
_COM_SMARTPTR_TYPEDEF(IXTLRuntime, __uuidof(IXTLRuntime));
_COM_SMARTPTR_TYPEDEF(IXMLDOMSelection, __uuidof(IXMLDOMSelection));
_COM_SMARTPTR_TYPEDEF(IDSOControl, __uuidof(IDSOControl));
_COM_SMARTPTR_TYPEDEF(IVBMXNamespaceManager, __uuidof(IVBMXNamespaceManager));
_COM_SMARTPTR_TYPEDEF(IMXNamespaceManager, __uuidof(IMXNamespaceManager));
_COM_SMARTPTR_TYPEDEF(IXMLDOMParseError2, __uuidof(IXMLDOMParseError2));
_COM_SMARTPTR_TYPEDEF(IXMLDOMParseErrorCollection, __uuidof(IXMLDOMParseErrorCollection));
_COM_SMARTPTR_TYPEDEF(IXSLTemplate, __uuidof(IXSLTemplate));
_COM_SMARTPTR_TYPEDEF(IXSLProcessor, __uuidof(IXSLProcessor));
_COM_SMARTPTR_TYPEDEF(IMXSchemaDeclHandler, __uuidof(IMXSchemaDeclHandler));
_COM_SMARTPTR_TYPEDEF(ISchemaItem, __uuidof(ISchemaItem));
_COM_SMARTPTR_TYPEDEF(ISchemaParticle, __uuidof(ISchemaParticle));
_COM_SMARTPTR_TYPEDEF(ISchemaItemCollection, __uuidof(ISchemaItemCollection));
_COM_SMARTPTR_TYPEDEF(ISchema, __uuidof(ISchema));
_COM_SMARTPTR_TYPEDEF(ISchemaType, __uuidof(ISchemaType));
_COM_SMARTPTR_TYPEDEF(ISchemaAny, __uuidof(ISchemaAny));
_COM_SMARTPTR_TYPEDEF(ISchemaModelGroup, __uuidof(ISchemaModelGroup));
_COM_SMARTPTR_TYPEDEF(ISchemaComplexType, __uuidof(ISchemaComplexType));
_COM_SMARTPTR_TYPEDEF(ISchemaElement, __uuidof(ISchemaElement));
_COM_SMARTPTR_TYPEDEF(IXMLDOMSchemaCollection2, __uuidof(IXMLDOMSchemaCollection2));
_COM_SMARTPTR_TYPEDEF(ISchemaAttribute, __uuidof(ISchemaAttribute));
_COM_SMARTPTR_TYPEDEF(ISchemaAttributeGroup, __uuidof(ISchemaAttributeGroup));
_COM_SMARTPTR_TYPEDEF(ISchemaIdentityConstraint, __uuidof(ISchemaIdentityConstraint));
_COM_SMARTPTR_TYPEDEF(ISchemaNotation, __uuidof(ISchemaNotation));

//
// Type library items
//

struct __declspec(uuid("2933bf8f-7b36-11d2-b20e-00c04f983e60"))
IXMLDOMImplementation : IDispatch
{
    //
    // Wrapper methods for error-handling
    //

    VARIANT_BOOL hasFeature (
        _bstr_t feature,
        _bstr_t version );

    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall raw_hasFeature (
        /*[in]*/ BSTR feature,
        /*[in]*/ BSTR version,
        /*[out,retval]*/ VARIANT_BOOL * hasFeature ) = 0;
};

TagENUM tagDOMNodeType
{
    NODE_INVALID = 0,
    NODE_ELEMENT = 1,
    NODE_ATTRIBUTE = 2,
    NODE_TEXT = 3,
    NODE_CDATA_SECTION = 4,
    NODE_ENTITY_REFERENCE = 5,
    NODE_ENTITY = 6,
    NODE_PROCESSING_INSTRUCTION = 7,
    NODE_COMMENT = 8,
    NODE_DOCUMENT = 9,
    NODE_DOCUMENT_TYPE = 10,
    NODE_DOCUMENT_FRAGMENT = 11,
    NODE_NOTATION = 12
};

struct __declspec(uuid("3efaa426-272f-11d2-836f-0000f87a7782"))
IXMLDOMParseError : IDispatch
{
    //
    // Property data
    //

    __declspec(property(get=GeterrorCode))
    long errorCode;
    __declspec(property(get=Geturl))
    _bstr_t url;
    __declspec(property(get=Getreason))
    _bstr_t reason;
    __declspec(property(get=GetsrcText))
    _bstr_t srcText;
    __declspec(property(get=Getline))
    long line;
    __declspec(property(get=Getlinepos))
    long linepos;
    __declspec(property(get=Getfilepos))
    long filepos;

    //
    // Wrapper methods for error-handling
    //

    long GeterrorCode ( );
    _bstr_t Geturl ( );
    _bstr_t Getreason ( );
    _bstr_t GetsrcText ( );
    long Getline ( );
    long Getlinepos ( );
    long Getfilepos ( );

    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_errorCode (
        /*[out,retval]*/ long * errorCode ) = 0;
      virtual HRESULT __stdcall get_url (
        /*[out,retval]*/ BSTR * urlString ) = 0;
      virtual HRESULT __stdcall get_reason (
        /*[out,retval]*/ BSTR * reasonString ) = 0;
      virtual HRESULT __stdcall get_srcText (
        /*[out,retval]*/ BSTR * sourceString ) = 0;
      virtual HRESULT __stdcall get_line (
        /*[out,retval]*/ long * lineNumber ) = 0;
      virtual HRESULT __stdcall get_linepos (
        /*[out,retval]*/ long * linePosition ) = 0;
      virtual HRESULT __stdcall get_filepos (
        /*[out,retval]*/ long * filePosition ) = 0;
};

struct __declspec(uuid("99bca7bd-e8c4-4d5f-a0cf-6d907901ff07"))
ISAXEntityResolver : IUnknown
{
    //
    // Wrapper methods for error-handling
    //

    _variant_t resolveEntity (
        unsigned short * pwchPublicId,
        unsigned short * pwchSystemId );

    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall raw_resolveEntity (
        /*[in]*/ unsigned short * pwchPublicId,
        /*[in]*/ unsigned short * pwchSystemId,
        /*[out,retval]*/ VARIANT * pvarInput ) = 0;
};

struct __declspec(uuid("9b7e472a-0de4-4640-bff3-84d38a051c31"))
ISAXLocator : IUnknown
{
    //
    // Wrapper methods for error-handling
    //

    int getColumnNumber ( );
    int getLineNumber ( );
    unsigned short * getPublicId ( );
    unsigned short * getSystemId ( );

    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall raw_getColumnNumber (
        /*[out,retval]*/ int * pnColumn ) = 0;
      virtual HRESULT __stdcall raw_getLineNumber (
        /*[out,retval]*/ int * pnLine ) = 0;
      virtual HRESULT __stdcall raw_getPublicId (
        /*[out,retval]*/ unsigned short * * ppwchPublicId ) = 0;
      virtual HRESULT __stdcall raw_getSystemId (
        /*[out,retval]*/ unsigned short * * ppwchSystemId ) = 0;
};

struct __declspec(uuid("f078abe1-45d2-4832-91ea-4466ce2f25c9"))
ISAXAttributes : IUnknown
{
    //
    // Wrapper methods for error-handling
    //

    int getLength ( );
    HRESULT getURI (
        int nIndex,
        unsigned short * * ppwchUri,
        int * pcchUri );
    HRESULT getLocalName (
        int nIndex,
        unsigned short * * ppwchLocalName,
        int * pcchLocalName );
    HRESULT getQName (
        int nIndex,
        unsigned short * * ppwchQName,
        int * pcchQName );
    HRESULT getName (
        int nIndex,
        unsigned short * * ppwchUri,
        int * pcchUri,
        unsigned short * * ppwchLocalName,
        int * pcchLocalName,
        unsigned short * * ppwchQName,
        int * pcchQName );
    int getIndexFromName (
        unsigned short * pwchUri,
        int cchUri,
        unsigned short * pwchLocalName,
        int cchLocalName );
    int getIndexFromQName (
        unsigned short * pwchQName,
        int cchQName );
    HRESULT getType (
        int nIndex,
        unsigned short * * ppwchType,
        int * pcchType );
    HRESULT getTypeFromName (
        unsigned short * pwchUri,
        int cchUri,
        unsigned short * pwchLocalName,
        int cchLocalName,
        unsigned short * * ppwchType,
        int * pcchType );
    HRESULT getTypeFromQName (
        unsigned short * pwchQName,
        int cchQName,
        unsigned short * * ppwchType,
        int * pcchType );
    HRESULT getValue (
        int nIndex,
        unsigned short * * ppwchValue,
        int * pcchValue );
    HRESULT getValueFromName (
        unsigned short * pwchUri,
        int cchUri,
        unsigned short * pwchLocalName,
        int cchLocalName,
        unsigned short * * ppwchValue,
        int * pcchValue );
    HRESULT getValueFromQName (
        unsigned short * pwchQName,
        int cchQName,
        unsigned short * * ppwchValue,
        int * pcchValue );

    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall raw_getLength (
        /*[out,retval]*/ int * pnLength ) = 0;
      virtual HRESULT __stdcall raw_getURI (
        /*[in]*/ int nIndex,
        /*[out]*/ unsigned short * * ppwchUri,
        /*[out]*/ int * pcchUri ) = 0;
      virtual HRESULT __stdcall raw_getLocalName (
        /*[in]*/ int nIndex,
        /*[out]*/ unsigned short * * ppwchLocalName,
        /*[out]*/ int * pcchLocalName ) = 0;
      virtual HRESULT __stdcall raw_getQName (
        /*[in]*/ int nIndex,
        /*[out]*/ unsigned short * * ppwchQName,
        /*[out]*/ int * pcchQName ) = 0;
      virtual HRESULT __stdcall raw_getName (
        /*[in]*/ int nIndex,
        /*[out]*/ unsigned short * * ppwchUri,
        /*[out]*/ int * pcchUri,
        /*[out]*/ unsigned short * * ppwchLocalName,
        /*[out]*/ int * pcchLocalName,
        /*[out]*/ unsigned short * * ppwchQName,
        /*[out]*/ int * pcchQName ) = 0;
      virtual HRESULT __stdcall raw_getIndexFromName (
        /*[in]*/ unsigned short * pwchUri,
        /*[in]*/ int cchUri,
        /*[in]*/ unsigned short * pwchLocalName,
        /*[in]*/ int cchLocalName,
        /*[out,retval]*/ int * pnIndex ) = 0;
      virtual HRESULT __stdcall raw_getIndexFromQName (
        /*[in]*/ unsigned short * pwchQName,
        /*[in]*/ int cchQName,
        /*[out,retval]*/ int * pnIndex ) = 0;
      virtual HRESULT __stdcall raw_getType (
        /*[in]*/ int nIndex,
        /*[out]*/ unsigned short * * ppwchType,
        /*[out]*/ int * pcchType ) = 0;
      virtual HRESULT __stdcall raw_getTypeFromName (
        /*[in]*/ unsigned short * pwchUri,
        /*[in]*/ int cchUri,
        /*[in]*/ unsigned short * pwchLocalName,
        /*[in]*/ int cchLocalName,
        /*[out]*/ unsigned short * * ppwchType,
        /*[out]*/ int * pcchType ) = 0;
      virtual HRESULT __stdcall raw_getTypeFromQName (
        /*[in]*/ unsigned short * pwchQName,
        /*[in]*/ int cchQName,
        /*[out]*/ unsigned short * * ppwchType,
        /*[out]*/ int * pcchType ) = 0;
      virtual HRESULT __stdcall raw_getValue (
        /*[in]*/ int nIndex,
        /*[out]*/ unsigned short * * ppwchValue,
        /*[out]*/ int * pcchValue ) = 0;
      virtual HRESULT __stdcall raw_getValueFromName (
        /*[in]*/ unsigned short * pwchUri,
        /*[in]*/ int cchUri,
        /*[in]*/ unsigned short * pwchLocalName,
        /*[in]*/ int cchLocalName,
        /*[out]*/ unsigned short * * ppwchValue,
        /*[out]*/ int * pcchValue ) = 0;
      virtual HRESULT __stdcall raw_getValueFromQName (
        /*[in]*/ unsigned short * pwchQName,
        /*[in]*/ int cchQName,
        /*[out]*/ unsigned short * * ppwchValue,
        /*[out]*/ int * pcchValue ) = 0;
};

struct __declspec(uuid("1545cdfa-9e4e-4497-a8a4-2bf7d0112c44"))
ISAXContentHandler : IUnknown
{
    //
    // Wrapper methods for error-handling
    //

    HRESULT putDocumentLocator (
        struct ISAXLocator * pLocator );
    HRESULT startDocument ( );
    HRESULT endDocument ( );
    HRESULT startPrefixMapping (
        unsigned short * pwchPrefix,
        int cchPrefix,
        unsigned short * pwchUri,
        int cchUri );
    HRESULT endPrefixMapping (
        unsigned short * pwchPrefix,
        int cchPrefix );
    HRESULT startElement (
        unsigned short * pwchNamespaceUri,
        int cchNamespaceUri,
        unsigned short * pwchLocalName,
        int cchLocalName,
        unsigned short * pwchQName,
        int cchQName,
        struct ISAXAttributes * pAttributes );
    HRESULT endElement (
        unsigned short * pwchNamespaceUri,
        int cchNamespaceUri,
        unsigned short * pwchLocalName,
        int cchLocalName,
        unsigned short * pwchQName,
        int cchQName );
    HRESULT characters (
        unsigned short * pwchChars,
        int cchChars );
    HRESULT ignorableWhitespace (
        unsigned short * pwchChars,
        int cchChars );
    HRESULT processingInstruction (
        unsigned short * pwchTarget,
        int cchTarget,
        unsigned short * pwchData,
        int cchData );
    HRESULT skippedEntity (
        unsigned short * pwchName,
        int cchName );

    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall raw_putDocumentLocator (
        /*[in]*/ struct ISAXLocator * pLocator ) = 0;
      virtual HRESULT __stdcall raw_startDocument ( ) = 0;
      virtual HRESULT __stdcall raw_endDocument ( ) = 0;
      virtual HRESULT __stdcall raw_startPrefixMapping (
        /*[in]*/ unsigned short * pwchPrefix,
        /*[in]*/ int cchPrefix,
        /*[in]*/ unsigned short * pwchUri,
        /*[in]*/ int cchUri ) = 0;
      virtual HRESULT __stdcall raw_endPrefixMapping (
        /*[in]*/ unsigned short * pwchPrefix,
        /*[in]*/ int cchPrefix ) = 0;
      virtual HRESULT __stdcall raw_startElement (
        /*[in]*/ unsigned short * pwchNamespaceUri,
        /*[in]*/ int cchNamespaceUri,
        /*[in]*/ unsigned short * pwchLocalName,
        /*[in]*/ int cchLocalName,
        /*[in]*/ unsigned short * pwchQName,
        /*[in]*/ int cchQName,
        /*[in]*/ struct ISAXAttributes * pAttributes ) = 0;
      virtual HRESULT __stdcall raw_endElement (
        /*[in]*/ unsigned short * pwchNamespaceUri,
        /*[in]*/ int cchNamespaceUri,
        /*[in]*/ unsigned short * pwchLocalName,
        /*[in]*/ int cchLocalName,
        /*[in]*/ unsigned short * pwchQName,
        /*[in]*/ int cchQName ) = 0;
      virtual HRESULT __stdcall raw_characters (
        /*[in]*/ unsigned short * pwchChars,
        /*[in]*/ int cchChars ) = 0;
      virtual HRESULT __stdcall raw_ignorableWhitespace (
        /*[in]*/ unsigned short * pwchChars,
        /*[in]*/ int cchChars ) = 0;
      virtual HRESULT __stdcall raw_processingInstruction (
        /*[in]*/ unsigned short * pwchTarget,
        /*[in]*/ int cchTarget,
        /*[in]*/ unsigned short * pwchData,
        /*[in]*/ int cchData ) = 0;
      virtual HRESULT __stdcall raw_skippedEntity (
        /*[in]*/ unsigned short * pwchName,
        /*[in]*/ int cchName ) = 0;
};

struct __declspec(uuid("e15c1baf-afb3-4d60-8c36-19a8c45defed"))
ISAXDTDHandler : IUnknown
{
    //
    // Wrapper methods for error-handling
    //

    HRESULT notationDecl (
        unsigned short * pwchName,
        int cchName,
        unsigned short * pwchPublicId,
        int cchPublicId,
        unsigned short * pwchSystemId,
        int cchSystemId );
    HRESULT unparsedEntityDecl (
        unsigned short * pwchName,
        int cchName,
        unsigned short * pwchPublicId,
        int cchPublicId,
        unsigned short * pwchSystemId,
        int cchSystemId,
        unsigned short * pwchNotationName,
        int cchNotationName );

    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall raw_notationDecl (
        /*[in]*/ unsigned short * pwchName,
        /*[in]*/ int cchName,
        /*[in]*/ unsigned short * pwchPublicId,
        /*[in]*/ int cchPublicId,
        /*[in]*/ unsigned short * pwchSystemId,
        /*[in]*/ int cchSystemId ) = 0;
      virtual HRESULT __stdcall raw_unparsedEntityDecl (
        /*[in]*/ unsigned short * pwchName,
        /*[in]*/ int cchName,
        /*[in]*/ unsigned short * pwchPublicId,
        /*[in]*/ int cchPublicId,
        /*[in]*/ unsigned short * pwchSystemId,
        /*[in]*/ int cchSystemId,
        /*[in]*/ unsigned short * pwchNotationName,
        /*[in]*/ int cchNotationName ) = 0;
};

struct __declspec(uuid("a60511c4-ccf5-479e-98a3-dc8dc545b7d0"))
ISAXErrorHandler : IUnknown
{
    //
    // Wrapper methods for error-handling
    //

    HRESULT error (
        struct ISAXLocator * pLocator,
        unsigned short * pwchErrorMessage,
        HRESULT hrErrorCode );
    HRESULT fatalError (
        struct ISAXLocator * pLocator,
        unsigned short * pwchErrorMessage,
        HRESULT hrErrorCode );
    HRESULT ignorableWarning (
        struct ISAXLocator * pLocator,
        unsigned short * pwchErrorMessage,
        HRESULT hrErrorCode );

    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall raw_error (
        /*[in]*/ struct ISAXLocator * pLocator,
        /*[in]*/ unsigned short * pwchErrorMessage,
        /*[in]*/ HRESULT hrErrorCode ) = 0;
      virtual HRESULT __stdcall raw_fatalError (
        /*[in]*/ struct ISAXLocator * pLocator,
        /*[in]*/ unsigned short * pwchErrorMessage,
        /*[in]*/ HRESULT hrErrorCode ) = 0;
      virtual HRESULT __stdcall raw_ignorableWarning (
        /*[in]*/ struct ISAXLocator * pLocator,
        /*[in]*/ unsigned short * pwchErrorMessage,
        /*[in]*/ HRESULT hrErrorCode ) = 0;
};

struct __declspec(uuid("a4f96ed0-f829-476e-81c0-cdc7bd2a0802"))
ISAXXMLReader : IUnknown
{
    //
    // Wrapper methods for error-handling
    //

    VARIANT_BOOL getFeature (
        unsigned short * pwchName );
    HRESULT putFeature (
        unsigned short * pwchName,
        VARIANT_BOOL vfValue );
    _variant_t getProperty (
        unsigned short * pwchName );
    HRESULT putProperty (
        unsigned short * pwchName,
        const _variant_t & varValue );
    ISAXEntityResolverPtr getEntityResolver ( );
    HRESULT putEntityResolver (
        struct ISAXEntityResolver * pResolver );
    ISAXContentHandlerPtr getContentHandler ( );
    HRESULT putContentHandler (
        struct ISAXContentHandler * pHandler );
    ISAXDTDHandlerPtr getDTDHandler ( );
    HRESULT putDTDHandler (
        struct ISAXDTDHandler * pHandler );
    ISAXErrorHandlerPtr getErrorHandler ( );
    HRESULT putErrorHandler (
        struct ISAXErrorHandler * pHandler );
    unsigned short * getBaseURL ( );
    HRESULT putBaseURL (
        unsigned short * pwchBaseUrl );
    unsigned short * getSecureBaseURL ( );
    HRESULT putSecureBaseURL (
        unsigned short * pwchSecureBaseUrl );
    HRESULT parse (
        const _variant_t & varInput = vtMissing );
    HRESULT parseURL (
        unsigned short * pwchUrl );

    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall raw_getFeature (
        /*[in]*/ unsigned short * pwchName,
        /*[out,retval]*/ VARIANT_BOOL * pvfValue ) = 0;
      virtual HRESULT __stdcall raw_putFeature (
        /*[in]*/ unsigned short * pwchName,
        /*[in]*/ VARIANT_BOOL vfValue ) = 0;
      virtual HRESULT __stdcall raw_getProperty (
        /*[in]*/ unsigned short * pwchName,
        /*[out,retval]*/ VARIANT * pvarValue ) = 0;
      virtual HRESULT __stdcall raw_putProperty (
        /*[in]*/ unsigned short * pwchName,
        /*[in]*/ VARIANT varValue ) = 0;
      virtual HRESULT __stdcall raw_getEntityResolver (
        /*[out,retval]*/ struct ISAXEntityResolver * * ppResolver ) = 0;
      virtual HRESULT __stdcall raw_putEntityResolver (
        /*[in]*/ struct ISAXEntityResolver * pResolver ) = 0;
      virtual HRESULT __stdcall raw_getContentHandler (
        /*[out,retval]*/ struct ISAXContentHandler * * ppHandler ) = 0;
      virtual HRESULT __stdcall raw_putContentHandler (
        /*[in]*/ struct ISAXContentHandler * pHandler ) = 0;
      virtual HRESULT __stdcall raw_getDTDHandler (
        /*[out,retval]*/ struct ISAXDTDHandler * * ppHandler ) = 0;
      virtual HRESULT __stdcall raw_putDTDHandler (
        /*[in]*/ struct ISAXDTDHandler * pHandler ) = 0;
      virtual HRESULT __stdcall raw_getErrorHandler (
        /*[out,retval]*/ struct ISAXErrorHandler * * ppHandler ) = 0;
      virtual HRESULT __stdcall raw_putErrorHandler (
        /*[in]*/ struct ISAXErrorHandler * pHandler ) = 0;
      virtual HRESULT __stdcall raw_getBaseURL (
        /*[out,retval]*/ unsigned short * * ppwchBaseUrl ) = 0;
      virtual HRESULT __stdcall raw_putBaseURL (
        /*[in]*/ unsigned short * pwchBaseUrl ) = 0;
      virtual HRESULT __stdcall raw_getSecureBaseURL (
        /*[out,retval]*/ unsigned short * * ppwchSecureBaseUrl ) = 0;
      virtual HRESULT __stdcall raw_putSecureBaseURL (
        /*[in]*/ unsigned short * pwchSecureBaseUrl ) = 0;
      virtual HRESULT __stdcall raw_parse (
        /*[in]*/ VARIANT varInput = vtMissing ) = 0;
      virtual HRESULT __stdcall raw_parseURL (
        /*[in]*/ unsigned short * pwchUrl ) = 0;
};

struct __declspec(uuid("70409222-ca09-4475-acb8-40312fe8d145"))
ISAXXMLFilter : ISAXXMLReader
{
    //
    // Wrapper methods for error-handling
    //

    ISAXXMLReaderPtr getParent ( );
    HRESULT putParent (
        struct ISAXXMLReader * pReader );

    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall raw_getParent (
        /*[out,retval]*/ struct ISAXXMLReader * * ppReader ) = 0;
      virtual HRESULT __stdcall raw_putParent (
        /*[in]*/ struct ISAXXMLReader * pReader ) = 0;
};

struct __declspec(uuid("7f85d5f5-47a8-4497-bda5-84ba04819ea6"))
ISAXLexicalHandler : IUnknown
{
    //
    // Wrapper methods for error-handling
    //

    HRESULT startDTD (
        unsigned short * pwchName,
        int cchName,
        unsigned short * pwchPublicId,
        int cchPublicId,
        unsigned short * pwchSystemId,
        int cchSystemId );
    HRESULT endDTD ( );
    HRESULT startEntity (
        unsigned short * pwchName,
        int cchName );
    HRESULT endEntity (
        unsigned short * pwchName,
        int cchName );
    HRESULT startCDATA ( );
    HRESULT endCDATA ( );
    HRESULT comment (
        unsigned short * pwchChars,
        int cchChars );

    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall raw_startDTD (
        /*[in]*/ unsigned short * pwchName,
        /*[in]*/ int cchName,
        /*[in]*/ unsigned short * pwchPublicId,
        /*[in]*/ int cchPublicId,
        /*[in]*/ unsigned short * pwchSystemId,
        /*[in]*/ int cchSystemId ) = 0;
      virtual HRESULT __stdcall raw_endDTD ( ) = 0;
      virtual HRESULT __stdcall raw_startEntity (
        /*[in]*/ unsigned short * pwchName,
        /*[in]*/ int cchName ) = 0;
      virtual HRESULT __stdcall raw_endEntity (
        /*[in]*/ unsigned short * pwchName,
        /*[in]*/ int cchName ) = 0;
      virtual HRESULT __stdcall raw_startCDATA ( ) = 0;
      virtual HRESULT __stdcall raw_endCDATA ( ) = 0;
      virtual HRESULT __stdcall raw_comment (
        /*[in]*/ unsigned short * pwchChars,
        /*[in]*/ int cchChars ) = 0;
};

struct __declspec(uuid("862629ac-771a-47b2-8337-4e6843c1be90"))
ISAXDeclHandler : IUnknown
{
    //
    // Wrapper methods for error-handling
    //

    HRESULT elementDecl (
        unsigned short * pwchName,
        int cchName,
        unsigned short * pwchModel,
        int cchModel );
    HRESULT attributeDecl (
        unsigned short * pwchElementName,
        int cchElementName,
        unsigned short * pwchAttributeName,
        int cchAttributeName,
        unsigned short * pwchType,
        int cchType,
        unsigned short * pwchValueDefault,
        int cchValueDefault,
        unsigned short * pwchValue,
        int cchValue );
    HRESULT internalEntityDecl (
        unsigned short * pwchName,
        int cchName,
        unsigned short * pwchValue,
        int cchValue );
    HRESULT externalEntityDecl (
        unsigned short * pwchName,
        int cchName,
        unsigned short * pwchPublicId,
        int cchPublicId,
        unsigned short * pwchSystemId,
        int cchSystemId );

    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall raw_elementDecl (
        /*[in]*/ unsigned short * pwchName,
        /*[in]*/ int cchName,
        /*[in]*/ unsigned short * pwchModel,
        /*[in]*/ int cchModel ) = 0;
      virtual HRESULT __stdcall raw_attributeDecl (
        /*[in]*/ unsigned short * pwchElementName,
        /*[in]*/ int cchElementName,
        /*[in]*/ unsigned short * pwchAttributeName,
        /*[in]*/ int cchAttributeName,
        /*[in]*/ unsigned short * pwchType,
        /*[in]*/ int cchType,
        /*[in]*/ unsigned short * pwchValueDefault,
        /*[in]*/ int cchValueDefault,
        /*[in]*/ unsigned short * pwchValue,
        /*[in]*/ int cchValue ) = 0;
      virtual HRESULT __stdcall raw_internalEntityDecl (
        /*[in]*/ unsigned short * pwchName,
        /*[in]*/ int cchName,
        /*[in]*/ unsigned short * pwchValue,
        /*[in]*/ int cchValue ) = 0;
      virtual HRESULT __stdcall raw_externalEntityDecl (
        /*[in]*/ unsigned short * pwchName,
        /*[in]*/ int cchName,
        /*[in]*/ unsigned short * pwchPublicId,
        /*[in]*/ int cchPublicId,
        /*[in]*/ unsigned short * pwchSystemId,
        /*[in]*/ int cchSystemId ) = 0;
};

struct __declspec(uuid("0c05d096-f45b-4aca-ad1a-aa0bc25518dc"))
IVBSAXEntityResolver : IDispatch
{
    //
    // Wrapper methods for error-handling
    //

    _variant_t resolveEntity (
        BSTR * strPublicId,
        BSTR * strSystemId );

    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall raw_resolveEntity (
        /*[in,out]*/ BSTR * strPublicId,
        /*[in,out]*/ BSTR * strSystemId,
        /*[out,retval]*/ VARIANT * varInput ) = 0;
};

struct __declspec(uuid("796e7ac5-5aa2-4eff-acad-3faaf01a3288"))
IVBSAXLocator : IDispatch
{
    //
    // Property data
    //

    __declspec(property(get=GetcolumnNumber))
    int columnNumber;
    __declspec(property(get=GetlineNumber))
    int lineNumber;
    __declspec(property(get=GetpublicId))
    _bstr_t publicId;
    __declspec(property(get=GetsystemId))
    _bstr_t systemId;

    //
    // Wrapper methods for error-handling
    //

    int GetcolumnNumber ( );
    int GetlineNumber ( );
    _bstr_t GetpublicId ( );
    _bstr_t GetsystemId ( );

    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_columnNumber (
        /*[out,retval]*/ int * nColumn ) = 0;
      virtual HRESULT __stdcall get_lineNumber (
        /*[out,retval]*/ int * nLine ) = 0;
      virtual HRESULT __stdcall get_publicId (
        /*[out,retval]*/ BSTR * strPublicId ) = 0;
      virtual HRESULT __stdcall get_systemId (
        /*[out,retval]*/ BSTR * strSystemId ) = 0;
};

struct __declspec(uuid("10dc0586-132b-4cac-8bb3-db00ac8b7ee0"))
IVBSAXAttributes : IDispatch
{
    //
    // Property data
    //

    __declspec(property(get=Getlength))
    int length;

    //
    // Wrapper methods for error-handling
    //

    int Getlength ( );
    _bstr_t getURI (
        int nIndex );
    _bstr_t getLocalName (
        int nIndex );
    _bstr_t getQName (
        int nIndex );
    int getIndexFromName (
        _bstr_t strURI,
        _bstr_t strLocalName );
    int getIndexFromQName (
        _bstr_t strQName );
    _bstr_t getType (
        int nIndex );
    _bstr_t getTypeFromName (
        _bstr_t strURI,
        _bstr_t strLocalName );
    _bstr_t getTypeFromQName (
        _bstr_t strQName );
    _bstr_t getValue (
        int nIndex );
    _bstr_t getValueFromName (
        _bstr_t strURI,
        _bstr_t strLocalName );
    _bstr_t getValueFromQName (
        _bstr_t strQName );

    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_length (
        /*[out,retval]*/ int * nLength ) = 0;
      virtual HRESULT __stdcall raw_getURI (
        /*[in]*/ int nIndex,
        /*[out,retval]*/ BSTR * strURI ) = 0;
      virtual HRESULT __stdcall raw_getLocalName (
        /*[in]*/ int nIndex,
        /*[out,retval]*/ BSTR * strLocalName ) = 0;
      virtual HRESULT __stdcall raw_getQName (
        /*[in]*/ int nIndex,
        /*[out,retval]*/ BSTR * strQName ) = 0;
      virtual HRESULT __stdcall raw_getIndexFromName (
        /*[in]*/ BSTR strURI,
        /*[in]*/ BSTR strLocalName,
        /*[out,retval]*/ int * nIndex ) = 0;
      virtual HRESULT __stdcall raw_getIndexFromQName (
        /*[in]*/ BSTR strQName,
        /*[out,retval]*/ int * nIndex ) = 0;
      virtual HRESULT __stdcall raw_getType (
        /*[in]*/ int nIndex,
        /*[out,retval]*/ BSTR * strType ) = 0;
      virtual HRESULT __stdcall raw_getTypeFromName (
        /*[in]*/ BSTR strURI,
        /*[in]*/ BSTR strLocalName,
        /*[out,retval]*/ BSTR * strType ) = 0;
      virtual HRESULT __stdcall raw_getTypeFromQName (
        /*[in]*/ BSTR strQName,
        /*[out,retval]*/ BSTR * strType ) = 0;
      virtual HRESULT __stdcall raw_getValue (
        /*[in]*/ int nIndex,
        /*[out,retval]*/ BSTR * strValue ) = 0;
      virtual HRESULT __stdcall raw_getValueFromName (
        /*[in]*/ BSTR strURI,
        /*[in]*/ BSTR strLocalName,
        /*[out,retval]*/ BSTR * strValue ) = 0;
      virtual HRESULT __stdcall raw_getValueFromQName (
        /*[in]*/ BSTR strQName,
        /*[out,retval]*/ BSTR * strValue ) = 0;
};

struct __declspec(uuid("2ed7290a-4dd5-4b46-bb26-4e4155e77faa"))
IVBSAXContentHandler : IDispatch
{
    //
    // Property data
    //

    __declspec(property(put=PutRefdocumentLocator))
    IVBSAXLocatorPtr documentLocator;

    //
    // Wrapper methods for error-handling
    //

    void PutRefdocumentLocator (
        struct IVBSAXLocator * _arg1 );
    HRESULT startDocument ( );
    HRESULT endDocument ( );
    HRESULT startPrefixMapping (
        BSTR * strPrefix,
        BSTR * strURI );
    HRESULT endPrefixMapping (
        BSTR * strPrefix );
    HRESULT startElement (
        BSTR * strNamespaceURI,
        BSTR * strLocalName,
        BSTR * strQName,
        struct IVBSAXAttributes * oAttributes );
    HRESULT endElement (
        BSTR * strNamespaceURI,
        BSTR * strLocalName,
        BSTR * strQName );
    HRESULT characters (
        BSTR * strChars );
    HRESULT ignorableWhitespace (
        BSTR * strChars );
    HRESULT processingInstruction (
        BSTR * strTarget,
        BSTR * strData );
    HRESULT skippedEntity (
        BSTR * strName );

    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall putref_documentLocator (
        /*[in]*/ struct IVBSAXLocator * _arg1 ) = 0;
      virtual HRESULT __stdcall raw_startDocument ( ) = 0;
      virtual HRESULT __stdcall raw_endDocument ( ) = 0;
      virtual HRESULT __stdcall raw_startPrefixMapping (
        /*[in,out]*/ BSTR * strPrefix,
        /*[in,out]*/ BSTR * strURI ) = 0;
      virtual HRESULT __stdcall raw_endPrefixMapping (
        /*[in,out]*/ BSTR * strPrefix ) = 0;
      virtual HRESULT __stdcall raw_startElement (
        /*[in,out]*/ BSTR * strNamespaceURI,
        /*[in,out]*/ BSTR * strLocalName,
        /*[in,out]*/ BSTR * strQName,
        /*[in]*/ struct IVBSAXAttributes * oAttributes ) = 0;
      virtual HRESULT __stdcall raw_endElement (
        /*[in,out]*/ BSTR * strNamespaceURI,
        /*[in,out]*/ BSTR * strLocalName,
        /*[in,out]*/ BSTR * strQName ) = 0;
      virtual HRESULT __stdcall raw_characters (
        /*[in,out]*/ BSTR * strChars ) = 0;
      virtual HRESULT __stdcall raw_ignorableWhitespace (
        /*[in,out]*/ BSTR * strChars ) = 0;
      virtual HRESULT __stdcall raw_processingInstruction (
        /*[in,out]*/ BSTR * strTarget,
        /*[in,out]*/ BSTR * strData ) = 0;
      virtual HRESULT __stdcall raw_skippedEntity (
        /*[in,out]*/ BSTR * strName ) = 0;
};

struct __declspec(uuid("24fb3297-302d-4620-ba39-3a732d850558"))
IVBSAXDTDHandler : IDispatch
{
    //
    // Wrapper methods for error-handling
    //

    HRESULT notationDecl (
        BSTR * strName,
        BSTR * strPublicId,
        BSTR * strSystemId );
    HRESULT unparsedEntityDecl (
        BSTR * strName,
        BSTR * strPublicId,
        BSTR * strSystemId,
        BSTR * strNotationName );

    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall raw_notationDecl (
        /*[in,out]*/ BSTR * strName,
        /*[in,out]*/ BSTR * strPublicId,
        /*[in,out]*/ BSTR * strSystemId ) = 0;
      virtual HRESULT __stdcall raw_unparsedEntityDecl (
        /*[in,out]*/ BSTR * strName,
        /*[in,out]*/ BSTR * strPublicId,
        /*[in,out]*/ BSTR * strSystemId,
        /*[in,out]*/ BSTR * strNotationName ) = 0;
};

struct __declspec(uuid("d963d3fe-173c-4862-9095-b92f66995f52"))
IVBSAXErrorHandler : IDispatch
{
    //
    // Wrapper methods for error-handling
    //

    HRESULT error (
        struct IVBSAXLocator * oLocator,
        BSTR * strErrorMessage,
        long nErrorCode );
    HRESULT fatalError (
        struct IVBSAXLocator * oLocator,
        BSTR * strErrorMessage,
        long nErrorCode );
    HRESULT ignorableWarning (
        struct IVBSAXLocator * oLocator,
        BSTR * strErrorMessage,
        long nErrorCode );

    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall raw_error (
        /*[in]*/ struct IVBSAXLocator * oLocator,
        /*[in,out]*/ BSTR * strErrorMessage,
        /*[in]*/ long nErrorCode ) = 0;
      virtual HRESULT __stdcall raw_fatalError (
        /*[in]*/ struct IVBSAXLocator * oLocator,
        /*[in,out]*/ BSTR * strErrorMessage,
        /*[in]*/ long nErrorCode ) = 0;
      virtual HRESULT __stdcall raw_ignorableWarning (
        /*[in]*/ struct IVBSAXLocator * oLocator,
        /*[in,out]*/ BSTR * strErrorMessage,
        /*[in]*/ long nErrorCode ) = 0;
};

struct __declspec(uuid("8c033caa-6cd6-4f73-b728-4531af74945f"))
IVBSAXXMLReader : IDispatch
{
    //
    // Property data
    //

    __declspec(property(get=GetentityResolver,put=PutRefentityResolver))
    IVBSAXEntityResolverPtr entityResolver;
    __declspec(property(get=GetcontentHandler,put=PutRefcontentHandler))
    IVBSAXContentHandlerPtr contentHandler;
    __declspec(property(get=GetdtdHandler,put=PutRefdtdHandler))
    IVBSAXDTDHandlerPtr dtdHandler;
    __declspec(property(get=GeterrorHandler,put=PutReferrorHandler))
    IVBSAXErrorHandlerPtr errorHandler;
    __declspec(property(get=GetbaseURL,put=PutbaseURL))
    _bstr_t baseURL;
    __declspec(property(get=GetsecureBaseURL,put=PutsecureBaseURL))
    _bstr_t secureBaseURL;

    //
    // Wrapper methods for error-handling
    //

    VARIANT_BOOL getFeature (
        _bstr_t strName );
    HRESULT putFeature (
        _bstr_t strName,
        VARIANT_BOOL fValue );
    _variant_t getProperty (
        _bstr_t strName );
    HRESULT putProperty (
        _bstr_t strName,
        const _variant_t & varValue );
    IVBSAXEntityResolverPtr GetentityResolver ( );
    void PutRefentityResolver (
        struct IVBSAXEntityResolver * oResolver );
    IVBSAXContentHandlerPtr GetcontentHandler ( );
    void PutRefcontentHandler (
        struct IVBSAXContentHandler * oHandler );
    IVBSAXDTDHandlerPtr GetdtdHandler ( );
    void PutRefdtdHandler (
        struct IVBSAXDTDHandler * oHandler );
    IVBSAXErrorHandlerPtr GeterrorHandler ( );
    void PutReferrorHandler (
        struct IVBSAXErrorHandler * oHandler );
    _bstr_t GetbaseURL ( );
    void PutbaseURL (
        _bstr_t strBaseURL );
    _bstr_t GetsecureBaseURL ( );
    void PutsecureBaseURL (
        _bstr_t strSecureBaseURL );
    HRESULT parse (
        const _variant_t & varInput = vtMissing );
    HRESULT parseURL (
        _bstr_t strURL );

    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall raw_getFeature (
        /*[in]*/ BSTR strName,
        /*[out,retval]*/ VARIANT_BOOL * fValue ) = 0;
      virtual HRESULT __stdcall raw_putFeature (
        /*[in]*/ BSTR strName,
        /*[in]*/ VARIANT_BOOL fValue ) = 0;
      virtual HRESULT __stdcall raw_getProperty (
        /*[in]*/ BSTR strName,
        /*[out,retval]*/ VARIANT * varValue ) = 0;
      virtual HRESULT __stdcall raw_putProperty (
        /*[in]*/ BSTR strName,
        /*[in]*/ VARIANT varValue ) = 0;
      virtual HRESULT __stdcall get_entityResolver (
        /*[out,retval]*/ struct IVBSAXEntityResolver * * oResolver ) = 0;
      virtual HRESULT __stdcall putref_entityResolver (
        /*[in]*/ struct IVBSAXEntityResolver * oResolver ) = 0;
      virtual HRESULT __stdcall get_contentHandler (
        /*[out,retval]*/ struct IVBSAXContentHandler * * oHandler ) = 0;
      virtual HRESULT __stdcall putref_contentHandler (
        /*[in]*/ struct IVBSAXContentHandler * oHandler ) = 0;
      virtual HRESULT __stdcall get_dtdHandler (
        /*[out,retval]*/ struct IVBSAXDTDHandler * * oHandler ) = 0;
      virtual HRESULT __stdcall putref_dtdHandler (
        /*[in]*/ struct IVBSAXDTDHandler * oHandler ) = 0;
      virtual HRESULT __stdcall get_errorHandler (
        /*[out,retval]*/ struct IVBSAXErrorHandler * * oHandler ) = 0;
      virtual HRESULT __stdcall putref_errorHandler (
        /*[in]*/ struct IVBSAXErrorHandler * oHandler ) = 0;
      virtual HRESULT __stdcall get_baseURL (
        /*[out,retval]*/ BSTR * strBaseURL ) = 0;
      virtual HRESULT __stdcall put_baseURL (
        /*[in]*/ BSTR strBaseURL ) = 0;
      virtual HRESULT __stdcall get_secureBaseURL (
        /*[out,retval]*/ BSTR * strSecureBaseURL ) = 0;
      virtual HRESULT __stdcall put_secureBaseURL (
        /*[in]*/ BSTR strSecureBaseURL ) = 0;
      virtual HRESULT __stdcall raw_parse (
        /*[in]*/ VARIANT varInput = vtMissing ) = 0;
      virtual HRESULT __stdcall raw_parseURL (
        /*[in]*/ BSTR strURL ) = 0;
};

struct __declspec(uuid("1299eb1b-5b88-433e-82de-82ca75ad4e04"))
IVBSAXXMLFilter : IDispatch
{
    //
    // Property data
    //

    __declspec(property(get=Getparent,put=PutRefparent))
    IVBSAXXMLReaderPtr parent;

    //
    // Wrapper methods for error-handling
    //

    IVBSAXXMLReaderPtr Getparent ( );
    void PutRefparent (
        struct IVBSAXXMLReader * oReader );

    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_parent (
        /*[out,retval]*/ struct IVBSAXXMLReader * * oReader ) = 0;
      virtual HRESULT __stdcall putref_parent (
        /*[in]*/ struct IVBSAXXMLReader * oReader ) = 0;
};

struct __declspec(uuid("032aac35-8c0e-4d9d-979f-e3b702935576"))
IVBSAXLexicalHandler : IDispatch
{
    //
    // Wrapper methods for error-handling
    //

    HRESULT startDTD (
        BSTR * strName,
        BSTR * strPublicId,
        BSTR * strSystemId );
    HRESULT endDTD ( );
    HRESULT startEntity (
        BSTR * strName );
    HRESULT endEntity (
        BSTR * strName );
    HRESULT startCDATA ( );
    HRESULT endCDATA ( );
    HRESULT comment (
        BSTR * strChars );

    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall raw_startDTD (
        /*[in,out]*/ BSTR * strName,
        /*[in,out]*/ BSTR * strPublicId,
        /*[in,out]*/ BSTR * strSystemId ) = 0;
      virtual HRESULT __stdcall raw_endDTD ( ) = 0;
      virtual HRESULT __stdcall raw_startEntity (
        /*[in,out]*/ BSTR * strName ) = 0;
      virtual HRESULT __stdcall raw_endEntity (
        /*[in,out]*/ BSTR * strName ) = 0;
      virtual HRESULT __stdcall raw_startCDATA ( ) = 0;
      virtual HRESULT __stdcall raw_endCDATA ( ) = 0;
      virtual HRESULT __stdcall raw_comment (
        /*[in,out]*/ BSTR * strChars ) = 0;
};

struct __declspec(uuid("e8917260-7579-4be1-b5dd-7afbfa6f077b"))
IVBSAXDeclHandler : IDispatch
{
    //
    // Wrapper methods for error-handling
    //

    HRESULT elementDecl (
        BSTR * strName,
        BSTR * strModel );
    HRESULT attributeDecl (
        BSTR * strElementName,
        BSTR * strAttributeName,
        BSTR * strType,
        BSTR * strValueDefault,
        BSTR * strValue );
    HRESULT internalEntityDecl (
        BSTR * strName,
        BSTR * strValue );
    HRESULT externalEntityDecl (
        BSTR * strName,
        BSTR * strPublicId,
        BSTR * strSystemId );

    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall raw_elementDecl (
        /*[in,out]*/ BSTR * strName,
        /*[in,out]*/ BSTR * strModel ) = 0;
      virtual HRESULT __stdcall raw_attributeDecl (
        /*[in,out]*/ BSTR * strElementName,
        /*[in,out]*/ BSTR * strAttributeName,
        /*[in,out]*/ BSTR * strType,
        /*[in,out]*/ BSTR * strValueDefault,
        /*[in,out]*/ BSTR * strValue ) = 0;
      virtual HRESULT __stdcall raw_internalEntityDecl (
        /*[in,out]*/ BSTR * strName,
        /*[in,out]*/ BSTR * strValue ) = 0;
      virtual HRESULT __stdcall raw_externalEntityDecl (
        /*[in,out]*/ BSTR * strName,
        /*[in,out]*/ BSTR * strPublicId,
        /*[in,out]*/ BSTR * strSystemId ) = 0;
};

struct __declspec(uuid("4d7ff4ba-1565-4ea8-94e1-6e724a46f98d"))
IMXWriter : IDispatch
{
    //
    // Property data
    //

    __declspec(property(get=Getoutput,put=Putoutput))
    _variant_t output;
    __declspec(property(get=Getencoding,put=Putencoding))
    _bstr_t encoding;
    __declspec(property(get=GetbyteOrderMark,put=PutbyteOrderMark))
    VARIANT_BOOL byteOrderMark;
    __declspec(property(get=Getindent,put=Putindent))
    VARIANT_BOOL indent;
    __declspec(property(get=Getstandalone,put=Putstandalone))
    VARIANT_BOOL standalone;
    __declspec(property(get=GetomitXMLDeclaration,put=PutomitXMLDeclaration))
    VARIANT_BOOL omitXMLDeclaration;
    __declspec(property(get=Getversion,put=Putversion))
    _bstr_t version;
    __declspec(property(get=GetdisableOutputEscaping,put=PutdisableOutputEscaping))
    VARIANT_BOOL disableOutputEscaping;

    //
    // Wrapper methods for error-handling
    //

    void Putoutput (
        const _variant_t & varDestination );
    _variant_t Getoutput ( );
    void Putencoding (
        _bstr_t strEncoding );
    _bstr_t Getencoding ( );
    void PutbyteOrderMark (
        VARIANT_BOOL fWriteByteOrderMark );
    VARIANT_BOOL GetbyteOrderMark ( );
    void Putindent (
        VARIANT_BOOL fIndentMode );
    VARIANT_BOOL Getindent ( );
    void Putstandalone (
        VARIANT_BOOL fValue );
    VARIANT_BOOL Getstandalone ( );
    void PutomitXMLDeclaration (
        VARIANT_BOOL fValue );
    VARIANT_BOOL GetomitXMLDeclaration ( );
    void Putversion (
        _bstr_t strVersion );
    _bstr_t Getversion ( );
    void PutdisableOutputEscaping (
        VARIANT_BOOL fValue );
    VARIANT_BOOL GetdisableOutputEscaping ( );
    HRESULT flush ( );

    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall put_output (
        /*[in]*/ VARIANT varDestination ) = 0;
      virtual HRESULT __stdcall get_output (
        /*[out,retval]*/ VARIANT * varDestination ) = 0;
      virtual HRESULT __stdcall put_encoding (
        /*[in]*/ BSTR strEncoding ) = 0;
      virtual HRESULT __stdcall get_encoding (
        /*[out,retval]*/ BSTR * strEncoding ) = 0;
      virtual HRESULT __stdcall put_byteOrderMark (
        /*[in]*/ VARIANT_BOOL fWriteByteOrderMark ) = 0;
      virtual HRESULT __stdcall get_byteOrderMark (
        /*[out,retval]*/ VARIANT_BOOL * fWriteByteOrderMark ) = 0;
      virtual HRESULT __stdcall put_indent (
        /*[in]*/ VARIANT_BOOL fIndentMode ) = 0;
      virtual HRESULT __stdcall get_indent (
        /*[out,retval]*/ VARIANT_BOOL * fIndentMode ) = 0;
      virtual HRESULT __stdcall put_standalone (
        /*[in]*/ VARIANT_BOOL fValue ) = 0;
      virtual HRESULT __stdcall get_standalone (
        /*[out,retval]*/ VARIANT_BOOL * fValue ) = 0;
      virtual HRESULT __stdcall put_omitXMLDeclaration (
        /*[in]*/ VARIANT_BOOL fValue ) = 0;
      virtual HRESULT __stdcall get_omitXMLDeclaration (
        /*[out,retval]*/ VARIANT_BOOL * fValue ) = 0;
      virtual HRESULT __stdcall put_version (
        /*[in]*/ BSTR strVersion ) = 0;
      virtual HRESULT __stdcall get_version (
        /*[out,retval]*/ BSTR * strVersion ) = 0;
      virtual HRESULT __stdcall put_disableOutputEscaping (
        /*[in]*/ VARIANT_BOOL fValue ) = 0;
      virtual HRESULT __stdcall get_disableOutputEscaping (
        /*[out,retval]*/ VARIANT_BOOL * fValue ) = 0;
      virtual HRESULT __stdcall raw_flush ( ) = 0;
};

struct __declspec(uuid("f10d27cc-3ec0-415c-8ed8-77ab1c5e7262"))
IMXAttributes : IDispatch
{
    //
    // Wrapper methods for error-handling
    //

    HRESULT addAttribute (
        _bstr_t strURI,
        _bstr_t strLocalName,
        _bstr_t strQName,
        _bstr_t strType,
        _bstr_t strValue );
    HRESULT addAttributeFromIndex (
        const _variant_t & varAtts,
        int nIndex );
    HRESULT clear ( );
    HRESULT removeAttribute (
        int nIndex );
    HRESULT setAttribute (
        int nIndex,
        _bstr_t strURI,
        _bstr_t strLocalName,
        _bstr_t strQName,
        _bstr_t strType,
        _bstr_t strValue );
    HRESULT setAttributes (
        const _variant_t & varAtts );
    HRESULT setLocalName (
        int nIndex,
        _bstr_t strLocalName );
    HRESULT setQName (
        int nIndex,
        _bstr_t strQName );
    HRESULT setType (
        int nIndex,
        _bstr_t strType );
    HRESULT setURI (
        int nIndex,
        _bstr_t strURI );
    HRESULT setValue (
        int nIndex,
        _bstr_t strValue );

    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall raw_addAttribute (
        /*[in]*/ BSTR strURI,
        /*[in]*/ BSTR strLocalName,
        /*[in]*/ BSTR strQName,
        /*[in]*/ BSTR strType,
        /*[in]*/ BSTR strValue ) = 0;
      virtual HRESULT __stdcall raw_addAttributeFromIndex (
        /*[in]*/ VARIANT varAtts,
        /*[in]*/ int nIndex ) = 0;
      virtual HRESULT __stdcall raw_clear ( ) = 0;
      virtual HRESULT __stdcall raw_removeAttribute (
        /*[in]*/ int nIndex ) = 0;
      virtual HRESULT __stdcall raw_setAttribute (
        /*[in]*/ int nIndex,
        /*[in]*/ BSTR strURI,
        /*[in]*/ BSTR strLocalName,
        /*[in]*/ BSTR strQName,
        /*[in]*/ BSTR strType,
        /*[in]*/ BSTR strValue ) = 0;
      virtual HRESULT __stdcall raw_setAttributes (
        /*[in]*/ VARIANT varAtts ) = 0;
      virtual HRESULT __stdcall raw_setLocalName (
        /*[in]*/ int nIndex,
        /*[in]*/ BSTR strLocalName ) = 0;
      virtual HRESULT __stdcall raw_setQName (
        /*[in]*/ int nIndex,
        /*[in]*/ BSTR strQName ) = 0;
      virtual HRESULT __stdcall raw_setType (
        /*[in]*/ int nIndex,
        /*[in]*/ BSTR strType ) = 0;
      virtual HRESULT __stdcall raw_setURI (
        /*[in]*/ int nIndex,
        /*[in]*/ BSTR strURI ) = 0;
      virtual HRESULT __stdcall raw_setValue (
        /*[in]*/ int nIndex,
        /*[in]*/ BSTR strValue ) = 0;
};

struct __declspec(uuid("808f4e35-8d5a-4fbe-8466-33a41279ed30"))
IMXReaderControl : IDispatch
{
    //
    // Wrapper methods for error-handling
    //

    HRESULT abort ( );
    HRESULT resume ( );
    HRESULT suspend ( );

    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall raw_abort ( ) = 0;
      virtual HRESULT __stdcall raw_resume ( ) = 0;
      virtual HRESULT __stdcall raw_suspend ( ) = 0;
};

struct __declspec(uuid("50ea08b1-dd1b-4664-9a50-c2f40f4bd79a"))
ISchemaStringCollection : IDispatch
{
    //
    // Property data
    //

    __declspec(property(get=Getitem))
    _bstr_t item[];
    __declspec(property(get=Getlength))
    long length;
    __declspec(property(get=Get_newEnum))
    IUnknownPtr _newEnum;

    //
    // Wrapper methods for error-handling
    //

    _bstr_t Getitem (
        long index );
    long Getlength ( );
    IUnknownPtr Get_newEnum ( );

    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_item (
        /*[in]*/ long index,
        /*[out,retval]*/ BSTR * bstr ) = 0;
      virtual HRESULT __stdcall get_length (
        /*[out,retval]*/ long * length ) = 0;
      virtual HRESULT __stdcall get__newEnum (
        /*[out,retval]*/ IUnknown * * ppUnk ) = 0;
};

TagENUM _SOMITEMTYPE
{
    SOMITEM_SCHEMA = 4096,
    SOMITEM_ATTRIBUTE = 4097,
    SOMITEM_ATTRIBUTEGROUP = 4098,
    SOMITEM_NOTATION = 4099,
    SOMITEM_ANNOTATION = 4100,
    SOMITEM_IDENTITYCONSTRAINT = 4352,
    SOMITEM_KEY = 4353,
    SOMITEM_KEYREF = 4354,
    SOMITEM_UNIQUE = 4355,
    SOMITEM_ANYTYPE = 8192,
    SOMITEM_DATATYPE = 8448,
    SOMITEM_DATATYPE_ANYTYPE = 8449,
    SOMITEM_DATATYPE_ANYURI = 8450,
    SOMITEM_DATATYPE_BASE64BINARY = 8451,
    SOMITEM_DATATYPE_BOOLEAN = 8452,
    SOMITEM_DATATYPE_BYTE = 8453,
    SOMITEM_DATATYPE_DATE = 8454,
    SOMITEM_DATATYPE_DATETIME = 8455,
    SOMITEM_DATATYPE_DAY = 8456,
    SOMITEM_DATATYPE_DECIMAL = 8457,
    SOMITEM_DATATYPE_DOUBLE = 8458,
    SOMITEM_DATATYPE_DURATION = 8459,
    SOMITEM_DATATYPE_ENTITIES = 8460,
    SOMITEM_DATATYPE_ENTITY = 8461,
    SOMITEM_DATATYPE_FLOAT = 8462,
    SOMITEM_DATATYPE_HEXBINARY = 8463,
    SOMITEM_DATATYPE_ID = 8464,
    SOMITEM_DATATYPE_IDREF = 8465,
    SOMITEM_DATATYPE_IDREFS = 8466,
    SOMITEM_DATATYPE_INT = 8467,
    SOMITEM_DATATYPE_INTEGER = 8468,
    SOMITEM_DATATYPE_LANGUAGE = 8469,
    SOMITEM_DATATYPE_LONG = 8470,
    SOMITEM_DATATYPE_MONTH = 8471,
    SOMITEM_DATATYPE_MONTHDAY = 8472,
    SOMITEM_DATATYPE_NAME = 8473,
    SOMITEM_DATATYPE_NCNAME = 8474,
    SOMITEM_DATATYPE_NEGATIVEINTEGER = 8475,
    SOMITEM_DATATYPE_NMTOKEN = 8476,
    SOMITEM_DATATYPE_NMTOKENS = 8477,
    SOMITEM_DATATYPE_NONNEGATIVEINTEGER = 8478,
    SOMITEM_DATATYPE_NONPOSITIVEINTEGER = 8479,
    SOMITEM_DATATYPE_NORMALIZEDSTRING = 8480,
    SOMITEM_DATATYPE_NOTATION = 8481,
    SOMITEM_DATATYPE_POSITIVEINTEGER = 8482,
    SOMITEM_DATATYPE_QNAME = 8483,
    SOMITEM_DATATYPE_SHORT = 8484,
    SOMITEM_DATATYPE_STRING = 8485,
    SOMITEM_DATATYPE_TIME = 8486,
    SOMITEM_DATATYPE_TOKEN = 8487,
    SOMITEM_DATATYPE_UNSIGNEDBYTE = 8488,
    SOMITEM_DATATYPE_UNSIGNEDINT = 8489,
    SOMITEM_DATATYPE_UNSIGNEDLONG = 8490,
    SOMITEM_DATATYPE_UNSIGNEDSHORT = 8491,
    SOMITEM_DATATYPE_YEAR = 8492,
    SOMITEM_DATATYPE_YEARMONTH = 8493,
    SOMITEM_DATATYPE_ANYSIMPLETYPE = 8703,
    SOMITEM_SIMPLETYPE = 8704,
    SOMITEM_COMPLEXTYPE = 9216,
    SOMITEM_PARTICLE = 16384,
    SOMITEM_ANY = 16385,
    SOMITEM_ANYATTRIBUTE = 16386,
    SOMITEM_ELEMENT = 16387,
    SOMITEM_GROUP = 16640,
    SOMITEM_ALL = 16641,
    SOMITEM_CHOICE = 16642,
    SOMITEM_SEQUENCE = 16643,
    SOMITEM_EMPTYPARTICLE = 16644,
    SOMITEM_NULL = 2048,
    SOMITEM_NULL_TYPE = 10240,
    SOMITEM_NULL_ANY = 18433,
    SOMITEM_NULL_ANYATTRIBUTE = 18434,
    SOMITEM_NULL_ELEMENT = 18435
};

TagENUM _SCHEMADERIVATIONMETHOD
{
    SCHEMADERIVATIONMETHOD_EMPTY = 0,
    SCHEMADERIVATIONMETHOD_SUBSTITUTION = 1,
    SCHEMADERIVATIONMETHOD_EXTENSION = 2,
    SCHEMADERIVATIONMETHOD_RESTRICTION = 4,
    SCHEMADERIVATIONMETHOD_LIST = 8,
    SCHEMADERIVATIONMETHOD_UNION = 16,
    SCHEMADERIVATIONMETHOD_ALL = 255,
    SCHEMADERIVATIONMETHOD_NONE = 256
};

TagENUM _SCHEMATYPEVARIETY
{
    SCHEMATYPEVARIETY_NONE = -1,
    SCHEMATYPEVARIETY_ATOMIC = 0,
    SCHEMATYPEVARIETY_LIST = 1,
    SCHEMATYPEVARIETY_UNION = 2
};

TagENUM _SCHEMAWHITESPACE
{
    SCHEMAWHITESPACE_NONE = -1,
    SCHEMAWHITESPACE_PRESERVE = 0,
    SCHEMAWHITESPACE_REPLACE = 1,
    SCHEMAWHITESPACE_COLLAPSE = 2
};

TagENUM _SCHEMAPROCESSCONTENTS
{
    SCHEMAPROCESSCONTENTS_NONE = 0,
    SCHEMAPROCESSCONTENTS_SKIP = 1,
    SCHEMAPROCESSCONTENTS_LAX = 2,
    SCHEMAPROCESSCONTENTS_STRICT = 3
};

TagENUM _SCHEMACONTENTTYPE
{
    SCHEMACONTENTTYPE_EMPTY = 0,
    SCHEMACONTENTTYPE_TEXTONLY = 1,
    SCHEMACONTENTTYPE_ELEMENTONLY = 2,
    SCHEMACONTENTTYPE_MIXED = 3
};

struct __declspec(uuid("c90352f7-643c-4fbc-bb23-e996eb2d51fd"))
IMXXMLFilter : IDispatch
{
    //
    // Property data
    //

    __declspec(property(get=GetcontentHandler,put=PutRefcontentHandler))
    IUnknownPtr contentHandler;
    __declspec(property(get=GetdtdHandler,put=PutRefdtdHandler))
    IUnknownPtr dtdHandler;
    __declspec(property(get=GetentityResolver,put=PutRefentityResolver))
    IUnknownPtr entityResolver;
    __declspec(property(get=GeterrorHandler,put=PutReferrorHandler))
    IUnknownPtr errorHandler;

    //
    // Wrapper methods for error-handling
    //

    VARIANT_BOOL getFeature (
        _bstr_t strName );
    HRESULT putFeature (
        _bstr_t strName,
        VARIANT_BOOL fValue );
    _variant_t getProperty (
        _bstr_t strName );
    HRESULT putProperty (
        _bstr_t strName,
        const _variant_t & varValue );
    IUnknownPtr GetentityResolver ( );
    void PutRefentityResolver (
        IUnknown * oResolver );
    IUnknownPtr GetcontentHandler ( );
    void PutRefcontentHandler (
        IUnknown * oHandler );
    IUnknownPtr GetdtdHandler ( );
    void PutRefdtdHandler (
        IUnknown * oHandler );
    IUnknownPtr GeterrorHandler ( );
    void PutReferrorHandler (
        IUnknown * oHandler );

    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall raw_getFeature (
        /*[in]*/ BSTR strName,
        /*[out,retval]*/ VARIANT_BOOL * fValue ) = 0;
      virtual HRESULT __stdcall raw_putFeature (
        /*[in]*/ BSTR strName,
        /*[in]*/ VARIANT_BOOL fValue ) = 0;
      virtual HRESULT __stdcall raw_getProperty (
        /*[in]*/ BSTR strName,
        /*[out,retval]*/ VARIANT * varValue ) = 0;
      virtual HRESULT __stdcall raw_putProperty (
        /*[in]*/ BSTR strName,
        /*[in]*/ VARIANT varValue ) = 0;
      virtual HRESULT __stdcall get_entityResolver (
        /*[out,retval]*/ IUnknown * * oResolver ) = 0;
      virtual HRESULT __stdcall putref_entityResolver (
        /*[in]*/ IUnknown * oResolver ) = 0;
      virtual HRESULT __stdcall get_contentHandler (
        /*[out,retval]*/ IUnknown * * oHandler ) = 0;
      virtual HRESULT __stdcall putref_contentHandler (
        /*[in]*/ IUnknown * oHandler ) = 0;
      virtual HRESULT __stdcall get_dtdHandler (
        /*[out,retval]*/ IUnknown * * oHandler ) = 0;
      virtual HRESULT __stdcall putref_dtdHandler (
        /*[in]*/ IUnknown * oHandler ) = 0;
      virtual HRESULT __stdcall get_errorHandler (
        /*[out,retval]*/ IUnknown * * oHandler ) = 0;
      virtual HRESULT __stdcall putref_errorHandler (
        /*[in]*/ IUnknown * oHandler ) = 0;
};

TagENUM _SCHEMAUSE
{
    SCHEMAUSE_OPTIONAL = 0,
    SCHEMAUSE_PROHIBITED = 1,
    SCHEMAUSE_REQUIRED = 2
};

struct __declspec(uuid("65725580-9b5d-11d0-9bfe-00c04fc99c8e"))
IXMLElementCollection : IDispatch
{
    //
    // Property data
    //

    __declspec(property(get=Getlength,put=Putlength))
    long length;
    __declspec(property(get=Get_newEnum))
    IUnknownPtr _newEnum;

    //
    // Wrapper methods for error-handling
    //

    void Putlength (
        long p );
    long Getlength ( );
    IUnknownPtr Get_newEnum ( );
    IDispatchPtr item (
        const _variant_t & var1 = vtMissing,
        const _variant_t & var2 = vtMissing );

    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall put_length (
        /*[in]*/ long p ) = 0;
      virtual HRESULT __stdcall get_length (
        /*[out,retval]*/ long * p ) = 0;
      virtual HRESULT __stdcall get__newEnum (
        /*[out,retval]*/ IUnknown * * ppUnk ) = 0;
      virtual HRESULT __stdcall raw_item (
        /*[in]*/ VARIANT var1,
        /*[in]*/ VARIANT var2,
        /*[out,retval]*/ IDispatch * * ppDisp ) = 0;
};

struct __declspec(uuid("3f7f31ac-e15f-11d0-9c25-00c04fc99c8e"))
IXMLElement : IDispatch
{
    //
    // Property data
    //

    __declspec(property(get=GettagName,put=PuttagName))
    _bstr_t tagName;
    __declspec(property(get=Getparent))
    IXMLElementPtr parent;
    __declspec(property(get=Getchildren))
    IXMLElementCollectionPtr children;
    __declspec(property(get=Gettype))
    long type;
    __declspec(property(get=Gettext,put=Puttext))
    _bstr_t text;

    //
    // Wrapper methods for error-handling
    //

    _bstr_t GettagName ( );
    void PuttagName (
        _bstr_t p );
    IXMLElementPtr Getparent ( );
    HRESULT setAttribute (
        _bstr_t strPropertyName,
        const _variant_t & PropertyValue );
    _variant_t getAttribute (
        _bstr_t strPropertyName );
    HRESULT removeAttribute (
        _bstr_t strPropertyName );
    IXMLElementCollectionPtr Getchildren ( );
    long Gettype ( );
    _bstr_t Gettext ( );
    void Puttext (
        _bstr_t p );
    HRESULT addChild (
        struct IXMLElement * pChildElem,
        long lIndex,
        long lReserved );
    HRESULT removeChild (
        struct IXMLElement * pChildElem );

    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_tagName (
        /*[out,retval]*/ BSTR * p ) = 0;
      virtual HRESULT __stdcall put_tagName (
        /*[in]*/ BSTR p ) = 0;
      virtual HRESULT __stdcall get_parent (
        /*[out,retval]*/ struct IXMLElement * * ppParent ) = 0;
      virtual HRESULT __stdcall raw_setAttribute (
        /*[in]*/ BSTR strPropertyName,
        /*[in]*/ VARIANT PropertyValue ) = 0;
      virtual HRESULT __stdcall raw_getAttribute (
        /*[in]*/ BSTR strPropertyName,
        /*[out,retval]*/ VARIANT * PropertyValue ) = 0;
      virtual HRESULT __stdcall raw_removeAttribute (
        /*[in]*/ BSTR strPropertyName ) = 0;
      virtual HRESULT __stdcall get_children (
        /*[out,retval]*/ struct IXMLElementCollection * * pp ) = 0;
      virtual HRESULT __stdcall get_type (
        /*[out,retval]*/ long * plType ) = 0;
      virtual HRESULT __stdcall get_text (
        /*[out,retval]*/ BSTR * p ) = 0;
      virtual HRESULT __stdcall put_text (
        /*[in]*/ BSTR p ) = 0;
      virtual HRESULT __stdcall raw_addChild (
        /*[in]*/ struct IXMLElement * pChildElem,
        long lIndex,
        long lReserved ) = 0;
      virtual HRESULT __stdcall raw_removeChild (
        /*[in]*/ struct IXMLElement * pChildElem ) = 0;
};

struct __declspec(uuid("f52e2b61-18a1-11d1-b105-00805f49916b"))
IXMLDocument : IDispatch
{
    //
    // Property data
    //

    __declspec(property(get=Getroot))
    IXMLElementPtr root;
    __declspec(property(get=GetfileSize))
    _bstr_t fileSize;
    __declspec(property(get=GetfileModifiedDate))
    _bstr_t fileModifiedDate;
    __declspec(property(get=GetfileUpdatedDate))
    _bstr_t fileUpdatedDate;
    __declspec(property(get=Geturl,put=Puturl))
    _bstr_t url;
    __declspec(property(get=GetmimeType))
    _bstr_t mimeType;
    __declspec(property(get=GetreadyState))
    long readyState;
    __declspec(property(get=Getcharset,put=Putcharset))
    _bstr_t charset;
    __declspec(property(get=Getversion))
    _bstr_t version;
    __declspec(property(get=Getdoctype))
    _bstr_t doctype;
    __declspec(property(get=GetdtdURL))
    _bstr_t dtdURL;

    //
    // Wrapper methods for error-handling
    //

    IXMLElementPtr Getroot ( );
    _bstr_t GetfileSize ( );
    _bstr_t GetfileModifiedDate ( );
    _bstr_t GetfileUpdatedDate ( );
    _bstr_t Geturl ( );
    void Puturl (
        _bstr_t p );
    _bstr_t GetmimeType ( );
    long GetreadyState ( );
    _bstr_t Getcharset ( );
    void Putcharset (
        _bstr_t p );
    _bstr_t Getversion ( );
    _bstr_t Getdoctype ( );
    _bstr_t GetdtdURL ( );
    IXMLElementPtr createElement (
        const _variant_t & vType,
        const _variant_t & var1 = vtMissing );

    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_root (
        /*[out,retval]*/ struct IXMLElement * * p ) = 0;
      virtual HRESULT __stdcall get_fileSize (
        /*[out,retval]*/ BSTR * p ) = 0;
      virtual HRESULT __stdcall get_fileModifiedDate (
        /*[out,retval]*/ BSTR * p ) = 0;
      virtual HRESULT __stdcall get_fileUpdatedDate (
        /*[out,retval]*/ BSTR * p ) = 0;
      virtual HRESULT __stdcall get_url (
        /*[out,retval]*/ BSTR * p ) = 0;
      virtual HRESULT __stdcall put_url (
        /*[in]*/ BSTR p ) = 0;
      virtual HRESULT __stdcall get_mimeType (
        /*[out,retval]*/ BSTR * p ) = 0;
      virtual HRESULT __stdcall get_readyState (
        /*[out,retval]*/ long * pl ) = 0;
      virtual HRESULT __stdcall get_charset (
        /*[out,retval]*/ BSTR * p ) = 0;
      virtual HRESULT __stdcall put_charset (
        /*[in]*/ BSTR p ) = 0;
      virtual HRESULT __stdcall get_version (
        /*[out,retval]*/ BSTR * p ) = 0;
      virtual HRESULT __stdcall get_doctype (
        /*[out,retval]*/ BSTR * p ) = 0;
      virtual HRESULT __stdcall get_dtdURL (
        /*[out,retval]*/ BSTR * p ) = 0;
      virtual HRESULT __stdcall raw_createElement (
        /*[in]*/ VARIANT vType,
        /*[in]*/ VARIANT var1,
        /*[out,retval]*/ struct IXMLElement * * ppElem ) = 0;
};

struct __declspec(uuid("2b8de2ff-8d2d-11d1-b2fc-00c04fd915a9"))
IXMLElement2 : IDispatch
{
    //
    // Property data
    //

    __declspec(property(get=GettagName,put=PuttagName))
    _bstr_t tagName;
    __declspec(property(get=Getparent))
    IXMLElement2Ptr parent;
    __declspec(property(get=Getchildren))
    IXMLElementCollectionPtr children;
    __declspec(property(get=Gettype))
    long type;
    __declspec(property(get=Gettext,put=Puttext))
    _bstr_t text;
    __declspec(property(get=Getattributes))
    IXMLElementCollectionPtr attributes;

    //
    // Wrapper methods for error-handling
    //

    _bstr_t GettagName ( );
    void PuttagName (
        _bstr_t p );
    IXMLElement2Ptr Getparent ( );
    HRESULT setAttribute (
        _bstr_t strPropertyName,
        const _variant_t & PropertyValue );
    _variant_t getAttribute (
        _bstr_t strPropertyName );
    HRESULT removeAttribute (
        _bstr_t strPropertyName );
    IXMLElementCollectionPtr Getchildren ( );
    long Gettype ( );
    _bstr_t Gettext ( );
    void Puttext (
        _bstr_t p );
    HRESULT addChild (
        struct IXMLElement2 * pChildElem,
        long lIndex,
        long lReserved );
    HRESULT removeChild (
        struct IXMLElement2 * pChildElem );
    IXMLElementCollectionPtr Getattributes ( );

    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_tagName (
        /*[out,retval]*/ BSTR * p ) = 0;
      virtual HRESULT __stdcall put_tagName (
        /*[in]*/ BSTR p ) = 0;
      virtual HRESULT __stdcall get_parent (
        /*[out,retval]*/ struct IXMLElement2 * * ppParent ) = 0;
      virtual HRESULT __stdcall raw_setAttribute (
        /*[in]*/ BSTR strPropertyName,
        /*[in]*/ VARIANT PropertyValue ) = 0;
      virtual HRESULT __stdcall raw_getAttribute (
        /*[in]*/ BSTR strPropertyName,
        /*[out,retval]*/ VARIANT * PropertyValue ) = 0;
      virtual HRESULT __stdcall raw_removeAttribute (
        /*[in]*/ BSTR strPropertyName ) = 0;
      virtual HRESULT __stdcall get_children (
        /*[out,retval]*/ struct IXMLElementCollection * * pp ) = 0;
      virtual HRESULT __stdcall get_type (
        /*[out,retval]*/ long * plType ) = 0;
      virtual HRESULT __stdcall get_text (
        /*[out,retval]*/ BSTR * p ) = 0;
      virtual HRESULT __stdcall put_text (
        /*[in]*/ BSTR p ) = 0;
      virtual HRESULT __stdcall raw_addChild (
        /*[in]*/ struct IXMLElement2 * pChildElem,
        long lIndex,
        long lReserved ) = 0;
      virtual HRESULT __stdcall raw_removeChild (
        /*[in]*/ struct IXMLElement2 * pChildElem ) = 0;
      virtual HRESULT __stdcall get_attributes (
        /*[out,retval]*/ struct IXMLElementCollection * * pp ) = 0;
};

struct __declspec(uuid("2b8de2fe-8d2d-11d1-b2fc-00c04fd915a9"))
IXMLDocument2 : IDispatch
{
    //
    // Property data
    //

    __declspec(property(get=Getroot))
    IXMLElement2Ptr root;
    __declspec(property(get=GetfileSize))
    _bstr_t fileSize;
    __declspec(property(get=GetfileModifiedDate))
    _bstr_t fileModifiedDate;
    __declspec(property(get=GetfileUpdatedDate))
    _bstr_t fileUpdatedDate;
    __declspec(property(get=Geturl,put=Puturl))
    _bstr_t url;
    __declspec(property(get=GetmimeType))
    _bstr_t mimeType;
    __declspec(property(get=GetreadyState))
    long readyState;
    __declspec(property(get=Getcharset,put=Putcharset))
    _bstr_t charset;
    __declspec(property(get=Getversion))
    _bstr_t version;
    __declspec(property(get=Getdoctype))
    _bstr_t doctype;
    __declspec(property(get=GetdtdURL))
    _bstr_t dtdURL;
    __declspec(property(get=Getasync,put=Putasync))
    VARIANT_BOOL async;

    //
    // Wrapper methods for error-handling
    //

    IXMLElement2Ptr Getroot ( );
    _bstr_t GetfileSize ( );
    _bstr_t GetfileModifiedDate ( );
    _bstr_t GetfileUpdatedDate ( );
    _bstr_t Geturl ( );
    void Puturl (
        _bstr_t p );
    _bstr_t GetmimeType ( );
    long GetreadyState ( );
    _bstr_t Getcharset ( );
    void Putcharset (
        _bstr_t p );
    _bstr_t Getversion ( );
    _bstr_t Getdoctype ( );
    _bstr_t GetdtdURL ( );
    IXMLElement2Ptr createElement (
        const _variant_t & vType,
        const _variant_t & var1 = vtMissing );
    VARIANT_BOOL Getasync ( );
    void Putasync (
        VARIANT_BOOL pf );

    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_root (
        /*[out,retval]*/ struct IXMLElement2 * * p ) = 0;
      virtual HRESULT __stdcall get_fileSize (
        /*[out,retval]*/ BSTR * p ) = 0;
      virtual HRESULT __stdcall get_fileModifiedDate (
        /*[out,retval]*/ BSTR * p ) = 0;
      virtual HRESULT __stdcall get_fileUpdatedDate (
        /*[out,retval]*/ BSTR * p ) = 0;
      virtual HRESULT __stdcall get_url (
        /*[out,retval]*/ BSTR * p ) = 0;
      virtual HRESULT __stdcall put_url (
        /*[in]*/ BSTR p ) = 0;
      virtual HRESULT __stdcall get_mimeType (
        /*[out,retval]*/ BSTR * p ) = 0;
      virtual HRESULT __stdcall get_readyState (
        /*[out,retval]*/ long * pl ) = 0;
      virtual HRESULT __stdcall get_charset (
        /*[out,retval]*/ BSTR * p ) = 0;
      virtual HRESULT __stdcall put_charset (
        /*[in]*/ BSTR p ) = 0;
      virtual HRESULT __stdcall get_version (
        /*[out,retval]*/ BSTR * p ) = 0;
      virtual HRESULT __stdcall get_doctype (
        /*[out,retval]*/ BSTR * p ) = 0;
      virtual HRESULT __stdcall get_dtdURL (
        /*[out,retval]*/ BSTR * p ) = 0;
      virtual HRESULT __stdcall raw_createElement (
        /*[in]*/ VARIANT vType,
        /*[in]*/ VARIANT var1,
        /*[out,retval]*/ struct IXMLElement2 * * ppElem ) = 0;
      virtual HRESULT __stdcall get_async (
        /*[out,retval]*/ VARIANT_BOOL * pf ) = 0;
      virtual HRESULT __stdcall put_async (
        /*[in]*/ VARIANT_BOOL pf ) = 0;
};

struct __declspec(uuid("d4d4a0fc-3b73-11d1-b2b4-00c04fb92596"))
IXMLAttribute : IDispatch
{
    //
    // Property data
    //

    __declspec(property(get=Getname))
    _bstr_t name;
    __declspec(property(get=Getvalue))
    _bstr_t value;

    //
    // Wrapper methods for error-handling
    //

    _bstr_t Getname ( );
    _bstr_t Getvalue ( );

    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_name (
        /*[out,retval]*/ BSTR * n ) = 0;
      virtual HRESULT __stdcall get_value (
        /*[out,retval]*/ BSTR * v ) = 0;
};

#pragma pack(push, 4)

struct _xml_error
{
    unsigned int _nLine;
    BSTR _pchBuf;
    unsigned int _cchBuf;
    unsigned int _ich;
    BSTR _pszFound;
    BSTR _pszExpected;
    unsigned long _reserved1;
    unsigned long _reserved2;
};

#pragma pack(pop)

struct __declspec(uuid("948c5ad3-c58d-11d0-9c0b-00c04fc99c8e"))
IXMLError : IUnknown
{
    //
    // Wrapper methods for error-handling
    //

    HRESULT GetErrorInfo (
        struct _xml_error * pErrorReturn );

    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall raw_GetErrorInfo (
        struct _xml_error * pErrorReturn ) = 0;
};

TagENUM tagXMLEMEM_TYPE
{
    XMLELEMTYPE_ELEMENT = 0,
    XMLELEMTYPE_TEXT = 1,
    XMLELEMTYPE_COMMENT = 2,
    XMLELEMTYPE_DOCUMENT = 3,
    XMLELEMTYPE_DTD = 4,
    XMLELEMTYPE_PI = 5,
    XMLELEMTYPE_OTHER = 6
};

struct __declspec(uuid("3efaa427-272f-11d2-836f-0000f87a7782"))
XMLDOMDocumentEvents : IDispatch
{
    //
    // Wrapper methods for error-handling
    //

    // Methods:
    HRESULT ondataavailable ( );
    HRESULT onreadystatechange ( );
};

struct __declspec(uuid("ed8c108d-4349-11d2-91a4-00c04f7969e8"))
IXMLHTTPRequest : IDispatch
{
    //
    // Property data
    //

    __declspec(property(get=Getstatus))
    long status;
    __declspec(property(get=GetstatusText))
    _bstr_t statusText;
    __declspec(property(get=GetresponseXML))
    IDispatchPtr responseXML;
    __declspec(property(get=GetresponseText))
    _bstr_t responseText;
    __declspec(property(get=GetresponseBody))
    _variant_t responseBody;
    __declspec(property(get=GetresponseStream))
    _variant_t responseStream;
    __declspec(property(get=GetreadyState))
    long readyState;
    __declspec(property(put=Putonreadystatechange))
    IDispatchPtr onreadystatechange;

    //
    // Wrapper methods for error-handling
    //

    HRESULT open (
        _bstr_t bstrMethod,
        _bstr_t bstrUrl,
        const _variant_t & varAsync = vtMissing,
        const _variant_t & bstrUser = vtMissing,
        const _variant_t & bstrPassword = vtMissing );
    HRESULT setRequestHeader (
        _bstr_t bstrHeader,
        _bstr_t bstrValue );
    _bstr_t getResponseHeader (
        _bstr_t bstrHeader );
    _bstr_t getAllResponseHeaders ( );
    HRESULT send (
        const _variant_t & varBody = vtMissing );
    HRESULT abort ( );
    long Getstatus ( );
    _bstr_t GetstatusText ( );
    IDispatchPtr GetresponseXML ( );
    _bstr_t GetresponseText ( );
    _variant_t GetresponseBody ( );
    _variant_t GetresponseStream ( );
    long GetreadyState ( );
    void Putonreadystatechange (
        IDispatch * _arg1 );

    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall raw_open (
        /*[in]*/ BSTR bstrMethod,
        /*[in]*/ BSTR bstrUrl,
        /*[in]*/ VARIANT varAsync = vtMissing,
        /*[in]*/ VARIANT bstrUser = vtMissing,
        /*[in]*/ VARIANT bstrPassword = vtMissing ) = 0;
      virtual HRESULT __stdcall raw_setRequestHeader (
        /*[in]*/ BSTR bstrHeader,
        /*[in]*/ BSTR bstrValue ) = 0;
      virtual HRESULT __stdcall raw_getResponseHeader (
        /*[in]*/ BSTR bstrHeader,
        /*[out,retval]*/ BSTR * pbstrValue ) = 0;
      virtual HRESULT __stdcall raw_getAllResponseHeaders (
        /*[out,retval]*/ BSTR * pbstrHeaders ) = 0;
      virtual HRESULT __stdcall raw_send (
        /*[in]*/ VARIANT varBody = vtMissing ) = 0;
      virtual HRESULT __stdcall raw_abort ( ) = 0;
      virtual HRESULT __stdcall get_status (
        /*[out,retval]*/ long * plStatus ) = 0;
      virtual HRESULT __stdcall get_statusText (
        /*[out,retval]*/ BSTR * pbstrStatus ) = 0;
      virtual HRESULT __stdcall get_responseXML (
        /*[out,retval]*/ IDispatch * * ppBody ) = 0;
      virtual HRESULT __stdcall get_responseText (
        /*[out,retval]*/ BSTR * pbstrBody ) = 0;
      virtual HRESULT __stdcall get_responseBody (
        /*[out,retval]*/ VARIANT * pvarBody ) = 0;
      virtual HRESULT __stdcall get_responseStream (
        /*[out,retval]*/ VARIANT * pvarBody ) = 0;
      virtual HRESULT __stdcall get_readyState (
        /*[out,retval]*/ long * plState ) = 0;
      virtual HRESULT __stdcall put_onreadystatechange (
        /*[in]*/ IDispatch * _arg1 ) = 0;
};

TagENUM _SERVERXMLHTTP_OPTION
{
    SXH_OPTION_URL = -1,
    SXH_OPTION_URL_CODEPAGE = 0,
    SXH_OPTION_ESCAPE_PERCENT_IN_URL = 1,
    SXH_OPTION_IGNORE_SERVER_SSL_CERT_ERROR_FLAGS = 2,
    SXH_OPTION_SELECT_CLIENT_SSL_CERT = 3
};

TagENUM _SXH_SERVER_CERT_OPTION
{
    SXH_SERVER_CERT_IGNORE_UNKNOWN_CA = 256,
    SXH_SERVER_CERT_IGNORE_WRONG_USAGE = 512,
    SXH_SERVER_CERT_IGNORE_CERT_CN_INVALID = 4096,
    SXH_SERVER_CERT_IGNORE_CERT_DATE_INVALID = 8192,
    SXH_SERVER_CERT_IGNORE_ALL_SERVER_ERRORS = 13056
};

TagENUM _SXH_PROXY_SETTING
{
    SXH_PROXY_SET_DEFAULT = 0,
    SXH_PROXY_SET_PRECONFIG = 0,
    SXH_PROXY_SET_DIRECT = 1,
    SXH_PROXY_SET_PROXY = 2
};

struct __declspec(uuid("2e9196bf-13ba-4dd4-91ca-6c571f281495"))
IServerXMLHTTPRequest : IXMLHTTPRequest
{
    //
    // Wrapper methods for error-handling
    //

    HRESULT setTimeouts (
        long resolveTimeout,
        long connectTimeout,
        long sendTimeout,
        long receiveTimeout );
    VARIANT_BOOL waitForResponse (
        const _variant_t & timeoutInSeconds = vtMissing );
    _variant_t getOption (
        SERVERXMLHTTP_OPTION option );
    HRESULT setOption (
        SERVERXMLHTTP_OPTION option,
        const _variant_t & value );

    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall raw_setTimeouts (
        /*[in]*/ long resolveTimeout,
        /*[in]*/ long connectTimeout,
        /*[in]*/ long sendTimeout,
        /*[in]*/ long receiveTimeout ) = 0;
      virtual HRESULT __stdcall raw_waitForResponse (
        /*[in]*/ VARIANT timeoutInSeconds,
        /*[out,retval]*/ VARIANT_BOOL * isSuccessful ) = 0;
      virtual HRESULT __stdcall raw_getOption (
        /*[in]*/ SERVERXMLHTTP_OPTION option,
        /*[out,retval]*/ VARIANT * value ) = 0;
      virtual HRESULT __stdcall raw_setOption (
        /*[in]*/ SERVERXMLHTTP_OPTION option,
        /*[in]*/ VARIANT value ) = 0;
};

struct __declspec(uuid("2e01311b-c322-4b0a-bd77-b90cfdc8dce7"))
IServerXMLHTTPRequest2 : IServerXMLHTTPRequest
{
    //
    // Wrapper methods for error-handling
    //

    HRESULT setProxy (
        SXH_PROXY_SETTING proxySetting,
        const _variant_t & varProxyServer = vtMissing,
        const _variant_t & varBypassList = vtMissing );
    HRESULT setProxyCredentials (
        _bstr_t bstrUserName,
        _bstr_t bstrPassword );

    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall raw_setProxy (
        /*[in]*/ SXH_PROXY_SETTING proxySetting,
        /*[in]*/ VARIANT varProxyServer = vtMissing,
        /*[in]*/ VARIANT varBypassList = vtMissing ) = 0;
      virtual HRESULT __stdcall raw_setProxyCredentials (
        /*[in]*/ BSTR bstrUserName,
        /*[in]*/ BSTR bstrPassword ) = 0;
};

struct __declspec(uuid("c90352f4-643c-4fbc-bb23-e996eb2d51fd"))
IMXNamespacePrefixes : IDispatch
{
    //
    // Property data
    //

    __declspec(property(get=Getitem))
    _bstr_t item[];
    __declspec(property(get=Getlength))
    long length;
    __declspec(property(get=Get_newEnum))
    IUnknownPtr _newEnum;

    //
    // Wrapper methods for error-handling
    //

    _bstr_t Getitem (
        long index );
    long Getlength ( );
    IUnknownPtr Get_newEnum ( );

    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_item (
        /*[in]*/ long index,
        /*[out,retval]*/ BSTR * prefix ) = 0;
      virtual HRESULT __stdcall get_length (
        /*[out,retval]*/ long * length ) = 0;
      virtual HRESULT __stdcall get__newEnum (
        /*[out,retval]*/ IUnknown * * ppUnk ) = 0;
};

struct __declspec(uuid("f6d90f11-9c73-11d3-b32e-00c04f990bb4"))
DOMDocument;
    // [ default ] interface IXMLDOMDocument2
    // [ default, source ] dispinterface XMLDOMDocumentEvents

struct __declspec(uuid("f5078f1b-c551-11d3-89b9-0000f81fe221"))
DOMDocument26;
    // [ default ] interface IXMLDOMDocument2
    // [ default, source ] dispinterface XMLDOMDocumentEvents

struct __declspec(uuid("f5078f32-c551-11d3-89b9-0000f81fe221"))
DOMDocument30;
    // [ default ] interface IXMLDOMDocument2
    // [ default, source ] dispinterface XMLDOMDocumentEvents

struct __declspec(uuid("88d969c0-f192-11d4-a65f-0040963251e5"))
DOMDocument40;
    // [ default ] interface IXMLDOMDocument2
    // [ default, source ] dispinterface XMLDOMDocumentEvents

struct __declspec(uuid("88d96a05-f192-11d4-a65f-0040963251e5"))
DOMDocument60;
    // [ default ] interface IXMLDOMDocument3
    // [ default, source ] dispinterface XMLDOMDocumentEvents

struct __declspec(uuid("f6d90f12-9c73-11d3-b32e-00c04f990bb4"))
FreeThreadedDOMDocument;
    // [ default ] interface IXMLDOMDocument2
    // [ default, source ] dispinterface XMLDOMDocumentEvents

struct __declspec(uuid("f5078f1c-c551-11d3-89b9-0000f81fe221"))
FreeThreadedDOMDocument26;
    // [ default ] interface IXMLDOMDocument2
    // [ default, source ] dispinterface XMLDOMDocumentEvents

struct __declspec(uuid("f5078f33-c551-11d3-89b9-0000f81fe221"))
FreeThreadedDOMDocument30;
    // [ default ] interface IXMLDOMDocument2
    // [ default, source ] dispinterface XMLDOMDocumentEvents

struct __declspec(uuid("88d969c1-f192-11d4-a65f-0040963251e5"))
FreeThreadedDOMDocument40;
    // [ default ] interface IXMLDOMDocument2
    // [ default, source ] dispinterface XMLDOMDocumentEvents

struct __declspec(uuid("88d96a06-f192-11d4-a65f-0040963251e5"))
FreeThreadedDOMDocument60;
    // [ default ] interface IXMLDOMDocument3
    // [ default, source ] dispinterface XMLDOMDocumentEvents

struct __declspec(uuid("373984c9-b845-449b-91e7-45ac83036ade"))
XMLSchemaCache;
    // [ default ] interface IXMLDOMSchemaCollection

struct __declspec(uuid("f5078f1d-c551-11d3-89b9-0000f81fe221"))
XMLSchemaCache26;
    // [ default ] interface IXMLDOMSchemaCollection

struct __declspec(uuid("f5078f34-c551-11d3-89b9-0000f81fe221"))
XMLSchemaCache30;
    // [ default ] interface IXMLDOMSchemaCollection

struct __declspec(uuid("88d969c2-f192-11d4-a65f-0040963251e5"))
XMLSchemaCache40;
    // [ default ] interface IXMLDOMSchemaCollection2

struct __declspec(uuid("88d96a07-f192-11d4-a65f-0040963251e5"))
XMLSchemaCache60;
    // [ default ] interface IXMLDOMSchemaCollection2

struct __declspec(uuid("2933bf94-7b36-11d2-b20e-00c04f983e60"))
XSLTemplate;
    // [ default ] interface IXSLTemplate

struct __declspec(uuid("f5078f21-c551-11d3-89b9-0000f81fe221"))
XSLTemplate26;
    // [ default ] interface IXSLTemplate

struct __declspec(uuid("f5078f36-c551-11d3-89b9-0000f81fe221"))
XSLTemplate30;
    // [ default ] interface IXSLTemplate

struct __declspec(uuid("88d969c3-f192-11d4-a65f-0040963251e5"))
XSLTemplate40;
    // [ default ] interface IXSLTemplate

struct __declspec(uuid("88d96a08-f192-11d4-a65f-0040963251e5"))
XSLTemplate60;
    // [ default ] interface IXSLTemplate

struct __declspec(uuid("f6d90f14-9c73-11d3-b32e-00c04f990bb4"))
DSOControl;
    // [ default ] interface IDSOControl

struct __declspec(uuid("f5078f1f-c551-11d3-89b9-0000f81fe221"))
DSOControl26;
    // [ default ] interface IDSOControl

struct __declspec(uuid("f5078f39-c551-11d3-89b9-0000f81fe221"))
DSOControl30;
    // [ default ] interface IDSOControl

struct __declspec(uuid("88d969c4-f192-11d4-a65f-0040963251e5"))
DSOControl40;
    // [ default ] interface IDSOControl

struct __declspec(uuid("f6d90f16-9c73-11d3-b32e-00c04f990bb4"))
XMLHTTP;
    // [ default ] interface IXMLHTTPRequest

struct __declspec(uuid("f5078f1e-c551-11d3-89b9-0000f81fe221"))
XMLHTTP26;
    // [ default ] interface IXMLHTTPRequest

struct __declspec(uuid("f5078f35-c551-11d3-89b9-0000f81fe221"))
XMLHTTP30;
    // [ default ] interface IXMLHTTPRequest

struct __declspec(uuid("88d969c5-f192-11d4-a65f-0040963251e5"))
XMLHTTP40;
    // [ default ] interface IXMLHTTPRequest

struct __declspec(uuid("88d96a0a-f192-11d4-a65f-0040963251e5"))
XMLHTTP60;
    // [ default ] interface IXMLHTTPRequest

struct __declspec(uuid("afba6b42-5692-48ea-8141-dc517dcf0ef1"))
ServerXMLHTTP;
    // [ default ] interface IServerXMLHTTPRequest

struct __declspec(uuid("afb40ffd-b609-40a3-9828-f88bbe11e4e3"))
ServerXMLHTTP30;
    // [ default ] interface IServerXMLHTTPRequest

struct __declspec(uuid("88d969c6-f192-11d4-a65f-0040963251e5"))
ServerXMLHTTP40;
    // [ default ] interface IServerXMLHTTPRequest2

struct __declspec(uuid("88d96a0b-f192-11d4-a65f-0040963251e5"))
ServerXMLHTTP60;
    // [ default ] interface IServerXMLHTTPRequest2

struct __declspec(uuid("079aa557-4a18-424a-8eee-e39f0a8d41b9"))
SAXXMLReader;
    // [ default ] interface IVBSAXXMLReader
    // interface ISAXXMLReader
    // interface IMXReaderControl

struct __declspec(uuid("3124c396-fb13-4836-a6ad-1317f1713688"))
SAXXMLReader30;
    // [ default ] interface IVBSAXXMLReader
    // interface ISAXXMLReader
    // interface IMXReaderControl

struct __declspec(uuid("7c6e29bc-8b8b-4c3d-859e-af6cd158be0f"))
SAXXMLReader40;
    // [ default ] interface IVBSAXXMLReader
    // interface ISAXXMLReader

struct __declspec(uuid("88d96a0c-f192-11d4-a65f-0040963251e5"))
SAXXMLReader60;
    // [ default ] interface IVBSAXXMLReader
    // interface ISAXXMLReader

struct __declspec(uuid("fc220ad8-a72a-4ee8-926e-0b7ad152a020"))
MXXMLWriter;
    // [ default ] interface IMXWriter
    // interface ISAXContentHandler
    // interface ISAXErrorHandler
    // interface ISAXDTDHandler
    // interface ISAXLexicalHandler
    // interface ISAXDeclHandler
    // interface IVBSAXContentHandler
    // interface IVBSAXDeclHandler
    // interface IVBSAXDTDHandler
    // interface IVBSAXErrorHandler
    // interface IVBSAXLexicalHandler

struct __declspec(uuid("3d813dfe-6c91-4a4e-8f41-04346a841d9c"))
MXXMLWriter30;
    // [ default ] interface IMXWriter
    // interface ISAXContentHandler
    // interface ISAXDeclHandler
    // interface ISAXDTDHandler
    // interface ISAXErrorHandler
    // interface ISAXLexicalHandler
    // interface IVBSAXContentHandler
    // interface IVBSAXDeclHandler
    // interface IVBSAXDTDHandler
    // interface IVBSAXErrorHandler
    // interface IVBSAXLexicalHandler

struct __declspec(uuid("88d969c8-f192-11d4-a65f-0040963251e5"))
MXXMLWriter40;
    // [ default ] interface IMXWriter
    // interface ISAXContentHandler
    // interface ISAXDeclHandler
    // interface ISAXDTDHandler
    // interface ISAXErrorHandler
    // interface ISAXLexicalHandler
    // interface IVBSAXContentHandler
    // interface IVBSAXDeclHandler
    // interface IVBSAXDTDHandler
    // interface IVBSAXErrorHandler
    // interface IVBSAXLexicalHandler

struct __declspec(uuid("88d96a0f-f192-11d4-a65f-0040963251e5"))
MXXMLWriter60;
    // [ default ] interface IMXWriter
    // interface ISAXContentHandler
    // interface ISAXDeclHandler
    // interface ISAXDTDHandler
    // interface ISAXErrorHandler
    // interface ISAXLexicalHandler
    // interface IVBSAXContentHandler
    // interface IVBSAXDeclHandler
    // interface IVBSAXDTDHandler
    // interface IVBSAXErrorHandler
    // interface IVBSAXLexicalHandler

struct __declspec(uuid("a4c23ec3-6b70-4466-9127-550077239978"))
MXHTMLWriter;
    // [ default ] interface IMXWriter
    // interface ISAXContentHandler
    // interface ISAXErrorHandler
    // interface ISAXDTDHandler
    // interface ISAXLexicalHandler
    // interface ISAXDeclHandler
    // interface IVBSAXContentHandler
    // interface IVBSAXDeclHandler
    // interface IVBSAXDTDHandler
    // interface IVBSAXErrorHandler
    // interface IVBSAXLexicalHandler

struct __declspec(uuid("853d1540-c1a7-4aa9-a226-4d3bd301146d"))
MXHTMLWriter30;
    // [ default ] interface IMXWriter
    // interface ISAXContentHandler
    // interface ISAXDeclHandler
    // interface ISAXDTDHandler
    // interface ISAXErrorHandler
    // interface ISAXLexicalHandler
    // interface IVBSAXContentHandler
    // interface IVBSAXDeclHandler
    // interface IVBSAXDTDHandler
    // interface IVBSAXErrorHandler
    // interface IVBSAXLexicalHandler

struct __declspec(uuid("88d969c9-f192-11d4-a65f-0040963251e5"))
MXHTMLWriter40;
    // [ default ] interface IMXWriter
    // interface ISAXContentHandler
    // interface ISAXDeclHandler
    // interface ISAXDTDHandler
    // interface ISAXErrorHandler
    // interface ISAXLexicalHandler
    // interface IVBSAXContentHandler
    // interface IVBSAXDeclHandler
    // interface IVBSAXDTDHandler
    // interface IVBSAXErrorHandler
    // interface IVBSAXLexicalHandler

struct __declspec(uuid("88d96a10-f192-11d4-a65f-0040963251e5"))
MXHTMLWriter60;
    // [ default ] interface IMXWriter
    // interface ISAXContentHandler
    // interface ISAXDeclHandler
    // interface ISAXDTDHandler
    // interface ISAXErrorHandler
    // interface ISAXLexicalHandler
    // interface IVBSAXContentHandler
    // interface IVBSAXDeclHandler
    // interface IVBSAXDTDHandler
    // interface IVBSAXErrorHandler
    // interface IVBSAXLexicalHandler

struct __declspec(uuid("4dd441ad-526d-4a77-9f1b-9841ed802fb0"))
SAXAttributes;
    // [ default ] interface IMXAttributes
    // interface IVBSAXAttributes
    // interface ISAXAttributes

struct __declspec(uuid("3e784a01-f3ae-4dc0-9354-9526b9370eba"))
SAXAttributes30;
    // [ default ] interface IMXAttributes
    // interface IVBSAXAttributes
    // interface ISAXAttributes

struct __declspec(uuid("88d969ca-f192-11d4-a65f-0040963251e5"))
SAXAttributes40;
    // [ default ] interface IMXAttributes
    // interface IVBSAXAttributes
    // interface ISAXAttributes

struct __declspec(uuid("88d96a0e-f192-11d4-a65f-0040963251e5"))
SAXAttributes60;
    // [ default ] interface IMXAttributes
    // interface IVBSAXAttributes
    // interface ISAXAttributes

struct __declspec(uuid("88d969d5-f192-11d4-a65f-0040963251e5"))
MXNamespaceManager;
    // [ default ] interface IVBMXNamespaceManager
    // interface IMXNamespaceManager

struct __declspec(uuid("88d969d6-f192-11d4-a65f-0040963251e5"))
MXNamespaceManager40;
    // [ default ] interface IVBMXNamespaceManager
    // interface IMXNamespaceManager

struct __declspec(uuid("88d96a11-f192-11d4-a65f-0040963251e5"))
MXNamespaceManager60;
    // [ default ] interface IVBMXNamespaceManager
    // interface IMXNamespaceManager

struct __declspec(uuid("cfc399af-d876-11d0-9c10-00c04fc99c8e"))
XMLDocument;
    // [ default ] interface IXMLDocument2

struct __declspec(uuid("2933bf80-7b36-11d2-b20e-00c04f983e60"))
IXMLDOMNode : IDispatch
{
    //
    // Property data
    //

    __declspec(property(get=GetnodeName))
    _bstr_t nodeName;
    __declspec(property(get=GetnodeValue,put=PutnodeValue))
    _variant_t nodeValue;
    __declspec(property(get=GetnodeType))
    DOMNodeType nodeType;
    __declspec(property(get=GetparentNode))
    IXMLDOMNodePtr parentNode;
    __declspec(property(get=GetchildNodes))
    IXMLDOMNodeListPtr childNodes;
    __declspec(property(get=GetfirstChild))
    IXMLDOMNodePtr firstChild;
    __declspec(property(get=GetlastChild))
    IXMLDOMNodePtr lastChild;
    __declspec(property(get=GetpreviousSibling))
    IXMLDOMNodePtr previousSibling;
    __declspec(property(get=GetnextSibling))
    IXMLDOMNodePtr nextSibling;
    __declspec(property(get=Getattributes))
    IXMLDOMNamedNodeMapPtr attributes;
    __declspec(property(get=GetownerDocument))
    IXMLDOMDocumentPtr ownerDocument;
    __declspec(property(get=GetnodeTypeString))
    _bstr_t nodeTypeString;
    __declspec(property(get=Getspecified))
    VARIANT_BOOL specified;
    __declspec(property(get=Getdefinition))
    IXMLDOMNodePtr definition;
    __declspec(property(get=Gettext,put=Puttext))
    _bstr_t text;
    __declspec(property(get=GetnodeTypedValue,put=PutnodeTypedValue))
    _variant_t nodeTypedValue;
    __declspec(property(get=Getxml))
    _bstr_t xml;
    __declspec(property(get=Getparsed))
    VARIANT_BOOL parsed;
    __declspec(property(get=GetnamespaceURI))
    _bstr_t namespaceURI;
    __declspec(property(get=Getprefix))
    _bstr_t prefix;
    __declspec(property(get=GetbaseName))
    _bstr_t baseName;

    //
    // Wrapper methods for error-handling
    //

    _bstr_t GetnodeName ( );
    _variant_t GetnodeValue ( );
    void PutnodeValue (
        const _variant_t & value );
    DOMNodeType GetnodeType ( );
    IXMLDOMNodePtr GetparentNode ( );
    IXMLDOMNodeListPtr GetchildNodes ( );
    IXMLDOMNodePtr GetfirstChild ( );
    IXMLDOMNodePtr GetlastChild ( );
    IXMLDOMNodePtr GetpreviousSibling ( );
    IXMLDOMNodePtr GetnextSibling ( );
    IXMLDOMNamedNodeMapPtr Getattributes ( );
    IXMLDOMNodePtr insertBefore (
        struct IXMLDOMNode * newChild,
        const _variant_t & refChild );
    IXMLDOMNodePtr replaceChild (
        struct IXMLDOMNode * newChild,
        struct IXMLDOMNode * oldChild );
    IXMLDOMNodePtr removeChild (
        struct IXMLDOMNode * childNode );
    IXMLDOMNodePtr appendChild (
        struct IXMLDOMNode * newChild );
    VARIANT_BOOL hasChildNodes ( );
    IXMLDOMDocumentPtr GetownerDocument ( );
    IXMLDOMNodePtr cloneNode (
        VARIANT_BOOL deep );
    _bstr_t GetnodeTypeString ( );
    _bstr_t Gettext ( );
    void Puttext (
        _bstr_t text );
    VARIANT_BOOL Getspecified ( );
    IXMLDOMNodePtr Getdefinition ( );
    _variant_t GetnodeTypedValue ( );
    void PutnodeTypedValue (
        const _variant_t & typedValue );
    _variant_t GetdataType ( );
    void PutdataType (
        _bstr_t dataTypeName );
    _bstr_t Getxml ( );
    _bstr_t transformNode (
        struct IXMLDOMNode * stylesheet );
    IXMLDOMNodeListPtr selectNodes (
        _bstr_t queryString );
    IXMLDOMNodePtr selectSingleNode (
        _bstr_t queryString );
    VARIANT_BOOL Getparsed ( );
    _bstr_t GetnamespaceURI ( );
    _bstr_t Getprefix ( );
    _bstr_t GetbaseName ( );
    HRESULT transformNodeToObject (
        struct IXMLDOMNode * stylesheet,
        const _variant_t & outputObject );

    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_nodeName (
        /*[out,retval]*/ BSTR * name ) = 0;
      virtual HRESULT __stdcall get_nodeValue (
        /*[out,retval]*/ VARIANT * value ) = 0;
      virtual HRESULT __stdcall put_nodeValue (
        /*[in]*/ VARIANT value ) = 0;
      virtual HRESULT __stdcall get_nodeType (
        /*[out,retval]*/ DOMNodeType * type ) = 0;
      virtual HRESULT __stdcall get_parentNode (
        /*[out,retval]*/ struct IXMLDOMNode * * parent ) = 0;
      virtual HRESULT __stdcall get_childNodes (
        /*[out,retval]*/ struct IXMLDOMNodeList * * childList ) = 0;
      virtual HRESULT __stdcall get_firstChild (
        /*[out,retval]*/ struct IXMLDOMNode * * firstChild ) = 0;
      virtual HRESULT __stdcall get_lastChild (
        /*[out,retval]*/ struct IXMLDOMNode * * lastChild ) = 0;
      virtual HRESULT __stdcall get_previousSibling (
        /*[out,retval]*/ struct IXMLDOMNode * * previousSibling ) = 0;
      virtual HRESULT __stdcall get_nextSibling (
        /*[out,retval]*/ struct IXMLDOMNode * * nextSibling ) = 0;
      virtual HRESULT __stdcall get_attributes (
        /*[out,retval]*/ struct IXMLDOMNamedNodeMap * * attributeMap ) = 0;
      virtual HRESULT __stdcall raw_insertBefore (
        /*[in]*/ struct IXMLDOMNode * newChild,
        /*[in]*/ VARIANT refChild,
        /*[out,retval]*/ struct IXMLDOMNode * * outNewChild ) = 0;
      virtual HRESULT __stdcall raw_replaceChild (
        /*[in]*/ struct IXMLDOMNode * newChild,
        /*[in]*/ struct IXMLDOMNode * oldChild,
        /*[out,retval]*/ struct IXMLDOMNode * * outOldChild ) = 0;
      virtual HRESULT __stdcall raw_removeChild (
        /*[in]*/ struct IXMLDOMNode * childNode,
        /*[out,retval]*/ struct IXMLDOMNode * * oldChild ) = 0;
      virtual HRESULT __stdcall raw_appendChild (
        /*[in]*/ struct IXMLDOMNode * newChild,
        /*[out,retval]*/ struct IXMLDOMNode * * outNewChild ) = 0;
      virtual HRESULT __stdcall raw_hasChildNodes (
        /*[out,retval]*/ VARIANT_BOOL * hasChild ) = 0;
      virtual HRESULT __stdcall get_ownerDocument (
        /*[out,retval]*/ struct IXMLDOMDocument * * XMLDOMDocument ) = 0;
      virtual HRESULT __stdcall raw_cloneNode (
        /*[in]*/ VARIANT_BOOL deep,
        /*[out,retval]*/ struct IXMLDOMNode * * cloneRoot ) = 0;
      virtual HRESULT __stdcall get_nodeTypeString (
        /*[out,retval]*/ BSTR * nodeType ) = 0;
      virtual HRESULT __stdcall get_text (
        /*[out,retval]*/ BSTR * text ) = 0;
      virtual HRESULT __stdcall put_text (
        /*[in]*/ BSTR text ) = 0;
      virtual HRESULT __stdcall get_specified (
        /*[out,retval]*/ VARIANT_BOOL * isSpecified ) = 0;
      virtual HRESULT __stdcall get_definition (
        /*[out,retval]*/ struct IXMLDOMNode * * definitionNode ) = 0;
      virtual HRESULT __stdcall get_nodeTypedValue (
        /*[out,retval]*/ VARIANT * typedValue ) = 0;
      virtual HRESULT __stdcall put_nodeTypedValue (
        /*[in]*/ VARIANT typedValue ) = 0;
      virtual HRESULT __stdcall get_dataType (
        /*[out,retval]*/ VARIANT * dataTypeName ) = 0;
      virtual HRESULT __stdcall put_dataType (
        /*[in]*/ BSTR dataTypeName ) = 0;
      virtual HRESULT __stdcall get_xml (
        /*[out,retval]*/ BSTR * xmlString ) = 0;
      virtual HRESULT __stdcall raw_transformNode (
        /*[in]*/ struct IXMLDOMNode * stylesheet,
        /*[out,retval]*/ BSTR * xmlString ) = 0;
      virtual HRESULT __stdcall raw_selectNodes (
        /*[in]*/ BSTR queryString,
        /*[out,retval]*/ struct IXMLDOMNodeList * * resultList ) = 0;
      virtual HRESULT __stdcall raw_selectSingleNode (
        /*[in]*/ BSTR queryString,
        /*[out,retval]*/ struct IXMLDOMNode * * resultNode ) = 0;
      virtual HRESULT __stdcall get_parsed (
        /*[out,retval]*/ VARIANT_BOOL * isParsed ) = 0;
      virtual HRESULT __stdcall get_namespaceURI (
        /*[out,retval]*/ BSTR * namespaceURI ) = 0;
      virtual HRESULT __stdcall get_prefix (
        /*[out,retval]*/ BSTR * prefixString ) = 0;
      virtual HRESULT __stdcall get_baseName (
        /*[out,retval]*/ BSTR * nameString ) = 0;
      virtual HRESULT __stdcall raw_transformNodeToObject (
        /*[in]*/ struct IXMLDOMNode * stylesheet,
        /*[in]*/ VARIANT outputObject ) = 0;
};

struct __declspec(uuid("2933bf82-7b36-11d2-b20e-00c04f983e60"))
IXMLDOMNodeList : IDispatch
{
    //
    // Property data
    //

    __declspec(property(get=Getitem))
    IXMLDOMNodePtr item[];
    __declspec(property(get=Getlength))
    long length;
    __declspec(property(get=Get_newEnum))
    IUnknownPtr _newEnum;

    //
    // Wrapper methods for error-handling
    //

    IXMLDOMNodePtr Getitem (
        long index );
    long Getlength ( );
    IXMLDOMNodePtr nextNode ( );
    HRESULT reset ( );
    IUnknownPtr Get_newEnum ( );

    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_item (
        /*[in]*/ long index,
        /*[out,retval]*/ struct IXMLDOMNode * * listItem ) = 0;
      virtual HRESULT __stdcall get_length (
        /*[out,retval]*/ long * listLength ) = 0;
      virtual HRESULT __stdcall raw_nextNode (
        /*[out,retval]*/ struct IXMLDOMNode * * nextItem ) = 0;
      virtual HRESULT __stdcall raw_reset ( ) = 0;
      virtual HRESULT __stdcall get__newEnum (
        /*[out,retval]*/ IUnknown * * ppUnk ) = 0;
};

struct __declspec(uuid("2933bf83-7b36-11d2-b20e-00c04f983e60"))
IXMLDOMNamedNodeMap : IDispatch
{
    //
    // Property data
    //

    __declspec(property(get=Getitem))
    IXMLDOMNodePtr item[];
    __declspec(property(get=Getlength))
    long length;
    __declspec(property(get=Get_newEnum))
    IUnknownPtr _newEnum;

    //
    // Wrapper methods for error-handling
    //

    IXMLDOMNodePtr getNamedItem (
        _bstr_t name );
    IXMLDOMNodePtr setNamedItem (
        struct IXMLDOMNode * newItem );
    IXMLDOMNodePtr removeNamedItem (
        _bstr_t name );
    IXMLDOMNodePtr Getitem (
        long index );
    long Getlength ( );
    IXMLDOMNodePtr getQualifiedItem (
        _bstr_t baseName,
        _bstr_t namespaceURI );
    IXMLDOMNodePtr removeQualifiedItem (
        _bstr_t baseName,
        _bstr_t namespaceURI );
    IXMLDOMNodePtr nextNode ( );
    HRESULT reset ( );
    IUnknownPtr Get_newEnum ( );

    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall raw_getNamedItem (
        /*[in]*/ BSTR name,
        /*[out,retval]*/ struct IXMLDOMNode * * namedItem ) = 0;
      virtual HRESULT __stdcall raw_setNamedItem (
        /*[in]*/ struct IXMLDOMNode * newItem,
        /*[out,retval]*/ struct IXMLDOMNode * * nameItem ) = 0;
      virtual HRESULT __stdcall raw_removeNamedItem (
        /*[in]*/ BSTR name,
        /*[out,retval]*/ struct IXMLDOMNode * * namedItem ) = 0;
      virtual HRESULT __stdcall get_item (
        /*[in]*/ long index,
        /*[out,retval]*/ struct IXMLDOMNode * * listItem ) = 0;
      virtual HRESULT __stdcall get_length (
        /*[out,retval]*/ long * listLength ) = 0;
      virtual HRESULT __stdcall raw_getQualifiedItem (
        /*[in]*/ BSTR baseName,
        /*[in]*/ BSTR namespaceURI,
        /*[out,retval]*/ struct IXMLDOMNode * * qualifiedItem ) = 0;
      virtual HRESULT __stdcall raw_removeQualifiedItem (
        /*[in]*/ BSTR baseName,
        /*[in]*/ BSTR namespaceURI,
        /*[out,retval]*/ struct IXMLDOMNode * * qualifiedItem ) = 0;
      virtual HRESULT __stdcall raw_nextNode (
        /*[out,retval]*/ struct IXMLDOMNode * * nextItem ) = 0;
      virtual HRESULT __stdcall raw_reset ( ) = 0;
      virtual HRESULT __stdcall get__newEnum (
        /*[out,retval]*/ IUnknown * * ppUnk ) = 0;
};

struct __declspec(uuid("2933bf8b-7b36-11d2-b20e-00c04f983e60"))
IXMLDOMDocumentType : IXMLDOMNode
{
    //
    // Property data
    //

    __declspec(property(get=Getname))
    _bstr_t name;
    __declspec(property(get=Getentities))
    IXMLDOMNamedNodeMapPtr entities;
    __declspec(property(get=Getnotations))
    IXMLDOMNamedNodeMapPtr notations;

    //
    // Wrapper methods for error-handling
    //

    _bstr_t Getname ( );
    IXMLDOMNamedNodeMapPtr Getentities ( );
    IXMLDOMNamedNodeMapPtr Getnotations ( );

    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_name (
        /*[out,retval]*/ BSTR * rootName ) = 0;
      virtual HRESULT __stdcall get_entities (
        /*[out,retval]*/ struct IXMLDOMNamedNodeMap * * entityMap ) = 0;
      virtual HRESULT __stdcall get_notations (
        /*[out,retval]*/ struct IXMLDOMNamedNodeMap * * notationMap ) = 0;
};

struct __declspec(uuid("2933bf85-7b36-11d2-b20e-00c04f983e60"))
IXMLDOMAttribute : IXMLDOMNode
{
    //
    // Property data
    //

    __declspec(property(get=Getname))
    _bstr_t name;
    __declspec(property(get=Getvalue,put=Putvalue))
    _variant_t value;

    //
    // Wrapper methods for error-handling
    //

    _bstr_t Getname ( );
    _variant_t Getvalue ( );
    void Putvalue (
        const _variant_t & attributeValue );

    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_name (
        /*[out,retval]*/ BSTR * attributeName ) = 0;
      virtual HRESULT __stdcall get_value (
        /*[out,retval]*/ VARIANT * attributeValue ) = 0;
      virtual HRESULT __stdcall put_value (
        /*[in]*/ VARIANT attributeValue ) = 0;
};

struct __declspec(uuid("2933bf86-7b36-11d2-b20e-00c04f983e60"))
IXMLDOMElement : IXMLDOMNode
{
    //
    // Property data
    //

    __declspec(property(get=GettagName))
    _bstr_t tagName;

    //
    // Wrapper methods for error-handling
    //

    _bstr_t GettagName ( );
    _variant_t getAttribute (
        _bstr_t name );
    HRESULT setAttribute (
        _bstr_t name,
        const _variant_t & value );
    HRESULT removeAttribute (
        _bstr_t name );
    IXMLDOMAttributePtr getAttributeNode (
        _bstr_t name );
    IXMLDOMAttributePtr setAttributeNode (
        struct IXMLDOMAttribute * DOMAttribute );
    IXMLDOMAttributePtr removeAttributeNode (
        struct IXMLDOMAttribute * DOMAttribute );
    IXMLDOMNodeListPtr getElementsByTagName (
        _bstr_t tagName );
    HRESULT normalize ( );

    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_tagName (
        /*[out,retval]*/ BSTR * tagName ) = 0;
      virtual HRESULT __stdcall raw_getAttribute (
        /*[in]*/ BSTR name,
        /*[out,retval]*/ VARIANT * value ) = 0;
      virtual HRESULT __stdcall raw_setAttribute (
        /*[in]*/ BSTR name,
        /*[in]*/ VARIANT value ) = 0;
      virtual HRESULT __stdcall raw_removeAttribute (
        /*[in]*/ BSTR name ) = 0;
      virtual HRESULT __stdcall raw_getAttributeNode (
        /*[in]*/ BSTR name,
        /*[out,retval]*/ struct IXMLDOMAttribute * * attributeNode ) = 0;
      virtual HRESULT __stdcall raw_setAttributeNode (
        /*[in]*/ struct IXMLDOMAttribute * DOMAttribute,
        /*[out,retval]*/ struct IXMLDOMAttribute * * attributeNode ) = 0;
      virtual HRESULT __stdcall raw_removeAttributeNode (
        /*[in]*/ struct IXMLDOMAttribute * DOMAttribute,
        /*[out,retval]*/ struct IXMLDOMAttribute * * attributeNode ) = 0;
      virtual HRESULT __stdcall raw_getElementsByTagName (
        /*[in]*/ BSTR tagName,
        /*[out,retval]*/ struct IXMLDOMNodeList * * resultList ) = 0;
      virtual HRESULT __stdcall raw_normalize ( ) = 0;
};

struct __declspec(uuid("3efaa413-272f-11d2-836f-0000f87a7782"))
IXMLDOMDocumentFragment : IXMLDOMNode
{};

struct __declspec(uuid("2933bf84-7b36-11d2-b20e-00c04f983e60"))
IXMLDOMCharacterData : IXMLDOMNode
{
    //
    // Property data
    //

    __declspec(property(get=Getdata,put=Putdata))
    _bstr_t data;
    __declspec(property(get=Getlength))
    long length;

    //
    // Wrapper methods for error-handling
    //

    _bstr_t Getdata ( );
    void Putdata (
        _bstr_t data );
    long Getlength ( );
    _bstr_t substringData (
        long offset,
        long count );
    HRESULT appendData (
        _bstr_t data );
    HRESULT insertData (
        long offset,
        _bstr_t data );
    HRESULT deleteData (
        long offset,
        long count );
    HRESULT replaceData (
        long offset,
        long count,
        _bstr_t data );

    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_data (
        /*[out,retval]*/ BSTR * data ) = 0;
      virtual HRESULT __stdcall put_data (
        /*[in]*/ BSTR data ) = 0;
      virtual HRESULT __stdcall get_length (
        /*[out,retval]*/ long * dataLength ) = 0;
      virtual HRESULT __stdcall raw_substringData (
        /*[in]*/ long offset,
        /*[in]*/ long count,
        /*[out,retval]*/ BSTR * data ) = 0;
      virtual HRESULT __stdcall raw_appendData (
        /*[in]*/ BSTR data ) = 0;
      virtual HRESULT __stdcall raw_insertData (
        /*[in]*/ long offset,
        /*[in]*/ BSTR data ) = 0;
      virtual HRESULT __stdcall raw_deleteData (
        /*[in]*/ long offset,
        /*[in]*/ long count ) = 0;
      virtual HRESULT __stdcall raw_replaceData (
        /*[in]*/ long offset,
        /*[in]*/ long count,
        /*[in]*/ BSTR data ) = 0;
};

struct __declspec(uuid("2933bf87-7b36-11d2-b20e-00c04f983e60"))
IXMLDOMText : IXMLDOMCharacterData
{
    //
    // Wrapper methods for error-handling
    //

    IXMLDOMTextPtr splitText (
        long offset );

    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall raw_splitText (
        /*[in]*/ long offset,
        /*[out,retval]*/ struct IXMLDOMText * * rightHandTextNode ) = 0;
};

struct __declspec(uuid("2933bf88-7b36-11d2-b20e-00c04f983e60"))
IXMLDOMComment : IXMLDOMCharacterData
{};

struct __declspec(uuid("2933bf8a-7b36-11d2-b20e-00c04f983e60"))
IXMLDOMCDATASection : IXMLDOMText
{};

struct __declspec(uuid("2933bf89-7b36-11d2-b20e-00c04f983e60"))
IXMLDOMProcessingInstruction : IXMLDOMNode
{
    //
    // Property data
    //

    __declspec(property(get=Getdata,put=Putdata))
    _bstr_t data;
    __declspec(property(get=Gettarget))
    _bstr_t target;

    //
    // Wrapper methods for error-handling
    //

    _bstr_t Gettarget ( );
    _bstr_t Getdata ( );
    void Putdata (
        _bstr_t value );

    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_target (
        /*[out,retval]*/ BSTR * name ) = 0;
      virtual HRESULT __stdcall get_data (
        /*[out,retval]*/ BSTR * value ) = 0;
      virtual HRESULT __stdcall put_data (
        /*[in]*/ BSTR value ) = 0;
};

struct __declspec(uuid("2933bf8e-7b36-11d2-b20e-00c04f983e60"))
IXMLDOMEntityReference : IXMLDOMNode
{};

struct __declspec(uuid("2933bf81-7b36-11d2-b20e-00c04f983e60"))
IXMLDOMDocument : IXMLDOMNode
{
    //
    // Property data
    //

    __declspec(property(get=GetvalidateOnParse,put=PutvalidateOnParse))
    VARIANT_BOOL validateOnParse;
    __declspec(property(get=GetresolveExternals,put=PutresolveExternals))
    VARIANT_BOOL resolveExternals;
    __declspec(property(get=GetpreserveWhiteSpace,put=PutpreserveWhiteSpace))
    VARIANT_BOOL preserveWhiteSpace;
    __declspec(property(put=Putonreadystatechange))
    _variant_t onreadystatechange;
    __declspec(property(put=Putondataavailable))
    _variant_t ondataavailable;
    __declspec(property(get=Getdoctype))
    IXMLDOMDocumentTypePtr doctype;
    __declspec(property(get=Getimplementation))
    IXMLDOMImplementationPtr implementation;
    __declspec(property(get=GetdocumentElement,put=PutRefdocumentElement))
    IXMLDOMElementPtr documentElement;
    __declspec(property(put=Putontransformnode))
    _variant_t ontransformnode;
    __declspec(property(get=GetreadyState))
    long readyState;
    __declspec(property(get=GetparseError))
    IXMLDOMParseErrorPtr parseError;
    __declspec(property(get=Geturl))
    _bstr_t url;
    __declspec(property(get=Getasync,put=Putasync))
    VARIANT_BOOL async;

    //
    // Wrapper methods for error-handling
    //

    IXMLDOMDocumentTypePtr Getdoctype ( );
    IXMLDOMImplementationPtr Getimplementation ( );
    IXMLDOMElementPtr GetdocumentElement ( );
    void PutRefdocumentElement (
        struct IXMLDOMElement * DOMElement );
    IXMLDOMElementPtr createElement (
        _bstr_t tagName );
    IXMLDOMDocumentFragmentPtr createDocumentFragment ( );
    IXMLDOMTextPtr createTextNode (
        _bstr_t data );
    IXMLDOMCommentPtr createComment (
        _bstr_t data );
    IXMLDOMCDATASectionPtr createCDATASection (
        _bstr_t data );
    IXMLDOMProcessingInstructionPtr createProcessingInstruction (
        _bstr_t target,
        _bstr_t data );
    IXMLDOMAttributePtr createAttribute (
        _bstr_t name );
    IXMLDOMEntityReferencePtr createEntityReference (
        _bstr_t name );
    IXMLDOMNodeListPtr getElementsByTagName (
        _bstr_t tagName );
    IXMLDOMNodePtr createNode (
        const _variant_t & type,
        _bstr_t name,
        _bstr_t namespaceURI );
    IXMLDOMNodePtr nodeFromID (
        _bstr_t idString );
    VARIANT_BOOL load (
        const _variant_t & xmlSource );
    long GetreadyState ( );
    IXMLDOMParseErrorPtr GetparseError ( );
    _bstr_t Geturl ( );
    VARIANT_BOOL Getasync ( );
    void Putasync (
        VARIANT_BOOL isAsync );
    HRESULT abort ( );
    VARIANT_BOOL loadXML (
        _bstr_t bstrXML );
    HRESULT save (
        const _variant_t & destination );
    VARIANT_BOOL GetvalidateOnParse ( );
    void PutvalidateOnParse (
        VARIANT_BOOL isValidating );
    VARIANT_BOOL GetresolveExternals ( );
    void PutresolveExternals (
        VARIANT_BOOL isResolving );
    VARIANT_BOOL GetpreserveWhiteSpace ( );
    void PutpreserveWhiteSpace (
        VARIANT_BOOL isPreserving );
    void Putonreadystatechange (
        const _variant_t & _arg1 );
    void Putondataavailable (
        const _variant_t & _arg1 );
    void Putontransformnode (
        const _variant_t & _arg1 );

    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_doctype (
        /*[out,retval]*/ struct IXMLDOMDocumentType * * documentType ) = 0;
      virtual HRESULT __stdcall get_implementation (
        /*[out,retval]*/ struct IXMLDOMImplementation * * impl ) = 0;
      virtual HRESULT __stdcall get_documentElement (
        /*[out,retval]*/ struct IXMLDOMElement * * DOMElement ) = 0;
      virtual HRESULT __stdcall putref_documentElement (
        /*[in]*/ struct IXMLDOMElement * DOMElement ) = 0;
      virtual HRESULT __stdcall raw_createElement (
        /*[in]*/ BSTR tagName,
        /*[out,retval]*/ struct IXMLDOMElement * * element ) = 0;
      virtual HRESULT __stdcall raw_createDocumentFragment (
        /*[out,retval]*/ struct IXMLDOMDocumentFragment * * docFrag ) = 0;
      virtual HRESULT __stdcall raw_createTextNode (
        /*[in]*/ BSTR data,
        /*[out,retval]*/ struct IXMLDOMText * * text ) = 0;
      virtual HRESULT __stdcall raw_createComment (
        /*[in]*/ BSTR data,
        /*[out,retval]*/ struct IXMLDOMComment * * comment ) = 0;
      virtual HRESULT __stdcall raw_createCDATASection (
        /*[in]*/ BSTR data,
        /*[out,retval]*/ struct IXMLDOMCDATASection * * cdata ) = 0;
      virtual HRESULT __stdcall raw_createProcessingInstruction (
        /*[in]*/ BSTR target,
        /*[in]*/ BSTR data,
        /*[out,retval]*/ struct IXMLDOMProcessingInstruction * * pi ) = 0;
      virtual HRESULT __stdcall raw_createAttribute (
        /*[in]*/ BSTR name,
        /*[out,retval]*/ struct IXMLDOMAttribute * * attribute ) = 0;
      virtual HRESULT __stdcall raw_createEntityReference (
        /*[in]*/ BSTR name,
        /*[out,retval]*/ struct IXMLDOMEntityReference * * entityRef ) = 0;
      virtual HRESULT __stdcall raw_getElementsByTagName (
        /*[in]*/ BSTR tagName,
        /*[out,retval]*/ struct IXMLDOMNodeList * * resultList ) = 0;
      virtual HRESULT __stdcall raw_createNode (
        /*[in]*/ VARIANT type,
        /*[in]*/ BSTR name,
        /*[in]*/ BSTR namespaceURI,
        /*[out,retval]*/ struct IXMLDOMNode * * node ) = 0;
      virtual HRESULT __stdcall raw_nodeFromID (
        /*[in]*/ BSTR idString,
        /*[out,retval]*/ struct IXMLDOMNode * * node ) = 0;
      virtual HRESULT __stdcall raw_load (
        /*[in]*/ VARIANT xmlSource,
        /*[out,retval]*/ VARIANT_BOOL * isSuccessful ) = 0;
      virtual HRESULT __stdcall get_readyState (
        /*[out,retval]*/ long * value ) = 0;
      virtual HRESULT __stdcall get_parseError (
        /*[out,retval]*/ struct IXMLDOMParseError * * errorObj ) = 0;
      virtual HRESULT __stdcall get_url (
        /*[out,retval]*/ BSTR * urlString ) = 0;
      virtual HRESULT __stdcall get_async (
        /*[out,retval]*/ VARIANT_BOOL * isAsync ) = 0;
      virtual HRESULT __stdcall put_async (
        /*[in]*/ VARIANT_BOOL isAsync ) = 0;
      virtual HRESULT __stdcall raw_abort ( ) = 0;
      virtual HRESULT __stdcall raw_loadXML (
        /*[in]*/ BSTR bstrXML,
        /*[out,retval]*/ VARIANT_BOOL * isSuccessful ) = 0;
      virtual HRESULT __stdcall raw_save (
        /*[in]*/ VARIANT destination ) = 0;
      virtual HRESULT __stdcall get_validateOnParse (
        /*[out,retval]*/ VARIANT_BOOL * isValidating ) = 0;
      virtual HRESULT __stdcall put_validateOnParse (
        /*[in]*/ VARIANT_BOOL isValidating ) = 0;
      virtual HRESULT __stdcall get_resolveExternals (
        /*[out,retval]*/ VARIANT_BOOL * isResolving ) = 0;
      virtual HRESULT __stdcall put_resolveExternals (
        /*[in]*/ VARIANT_BOOL isResolving ) = 0;
      virtual HRESULT __stdcall get_preserveWhiteSpace (
        /*[out,retval]*/ VARIANT_BOOL * isPreserving ) = 0;
      virtual HRESULT __stdcall put_preserveWhiteSpace (
        /*[in]*/ VARIANT_BOOL isPreserving ) = 0;
      virtual HRESULT __stdcall put_onreadystatechange (
        /*[in]*/ VARIANT _arg1 ) = 0;
      virtual HRESULT __stdcall put_ondataavailable (
        /*[in]*/ VARIANT _arg1 ) = 0;
      virtual HRESULT __stdcall put_ontransformnode (
        /*[in]*/ VARIANT _arg1 ) = 0;
};

struct __declspec(uuid("373984c8-b845-449b-91e7-45ac83036ade"))
IXMLDOMSchemaCollection : IDispatch
{
    //
    // Property data
    //

    __declspec(property(get=GetnamespaceURI))
    _bstr_t namespaceURI[];
    __declspec(property(get=Getlength))
    long length;
    __declspec(property(get=Get_newEnum))
    IUnknownPtr _newEnum;

    //
    // Wrapper methods for error-handling
    //

    HRESULT add (
        _bstr_t namespaceURI,
        const _variant_t & var );
    IXMLDOMNodePtr get (
        _bstr_t namespaceURI );
    HRESULT remove (
        _bstr_t namespaceURI );
    long Getlength ( );
    _bstr_t GetnamespaceURI (
        long index );
    HRESULT addCollection (
        struct IXMLDOMSchemaCollection * otherCollection );
    IUnknownPtr Get_newEnum ( );

    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall raw_add (
        /*[in]*/ BSTR namespaceURI,
        /*[in]*/ VARIANT var ) = 0;
      virtual HRESULT __stdcall raw_get (
        /*[in]*/ BSTR namespaceURI,
        /*[out,retval]*/ struct IXMLDOMNode * * schemaNode ) = 0;
      virtual HRESULT __stdcall raw_remove (
        /*[in]*/ BSTR namespaceURI ) = 0;
      virtual HRESULT __stdcall get_length (
        /*[out,retval]*/ long * length ) = 0;
      virtual HRESULT __stdcall get_namespaceURI (
        /*[in]*/ long index,
        /*[out,retval]*/ BSTR * length ) = 0;
      virtual HRESULT __stdcall raw_addCollection (
        /*[in]*/ struct IXMLDOMSchemaCollection * otherCollection ) = 0;
      virtual HRESULT __stdcall get__newEnum (
        /*[out,retval]*/ IUnknown * * ppUnk ) = 0;
};

struct __declspec(uuid("2933bf95-7b36-11d2-b20e-00c04f983e60"))
IXMLDOMDocument2 : IXMLDOMDocument
{
    //
    // Property data
    //

    __declspec(property(get=Getnamespaces))
    IXMLDOMSchemaCollectionPtr namespaces;
    __declspec(property(get=Getschemas,put=PutRefschemas))
    _variant_t schemas;

    //
    // Wrapper methods for error-handling
    //

    IXMLDOMSchemaCollectionPtr Getnamespaces ( );
    _variant_t Getschemas ( );
    void PutRefschemas (
        const _variant_t & otherCollection );
    IXMLDOMParseErrorPtr validate ( );
    HRESULT setProperty (
        _bstr_t name,
        const _variant_t & value );
    _variant_t getProperty (
        _bstr_t name );

    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_namespaces (
        /*[out,retval]*/ struct IXMLDOMSchemaCollection * * namespaceCollection ) = 0;
      virtual HRESULT __stdcall get_schemas (
        /*[out,retval]*/ VARIANT * otherCollection ) = 0;
      virtual HRESULT __stdcall putref_schemas (
        /*[in]*/ VARIANT otherCollection ) = 0;
      virtual HRESULT __stdcall raw_validate (
        /*[out,retval]*/ struct IXMLDOMParseError * * errorObj ) = 0;
      virtual HRESULT __stdcall raw_setProperty (
        /*[in]*/ BSTR name,
        /*[in]*/ VARIANT value ) = 0;
      virtual HRESULT __stdcall raw_getProperty (
        /*[in]*/ BSTR name,
        /*[out,retval]*/ VARIANT * value ) = 0;
};

struct __declspec(uuid("2933bf96-7b36-11d2-b20e-00c04f983e60"))
IXMLDOMDocument3 : IXMLDOMDocument2
{
    //
    // Wrapper methods for error-handling
    //

    IXMLDOMParseErrorPtr validateNode (
        struct IXMLDOMNode * node );
    IXMLDOMNodePtr importNode (
        struct IXMLDOMNode * node,
        VARIANT_BOOL deep );

    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall raw_validateNode (
        /*[in]*/ struct IXMLDOMNode * node,
        /*[out,retval]*/ struct IXMLDOMParseError * * errorObj ) = 0;
      virtual HRESULT __stdcall raw_importNode (
        /*[in]*/ struct IXMLDOMNode * node,
        /*[in]*/ VARIANT_BOOL deep,
        /*[out,retval]*/ struct IXMLDOMNode * * clone ) = 0;
};

struct __declspec(uuid("2933bf8c-7b36-11d2-b20e-00c04f983e60"))
IXMLDOMNotation : IXMLDOMNode
{
    //
    // Property data
    //

    __declspec(property(get=GetpublicId))
    _variant_t publicId;
    __declspec(property(get=GetsystemId))
    _variant_t systemId;

    //
    // Wrapper methods for error-handling
    //

    _variant_t GetpublicId ( );
    _variant_t GetsystemId ( );

    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_publicId (
        /*[out,retval]*/ VARIANT * publicId ) = 0;
      virtual HRESULT __stdcall get_systemId (
        /*[out,retval]*/ VARIANT * systemId ) = 0;
};

struct __declspec(uuid("2933bf8d-7b36-11d2-b20e-00c04f983e60"))
IXMLDOMEntity : IXMLDOMNode
{
    //
    // Property data
    //

    __declspec(property(get=GetpublicId))
    _variant_t publicId;
    __declspec(property(get=GetsystemId))
    _variant_t systemId;
    __declspec(property(get=GetnotationName))
    _bstr_t notationName;

    //
    // Wrapper methods for error-handling
    //

    _variant_t GetpublicId ( );
    _variant_t GetsystemId ( );
    _bstr_t GetnotationName ( );

    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_publicId (
        /*[out,retval]*/ VARIANT * publicId ) = 0;
      virtual HRESULT __stdcall get_systemId (
        /*[out,retval]*/ VARIANT * systemId ) = 0;
      virtual HRESULT __stdcall get_notationName (
        /*[out,retval]*/ BSTR * name ) = 0;
};

struct __declspec(uuid("3efaa425-272f-11d2-836f-0000f87a7782"))
IXTLRuntime : IXMLDOMNode
{
    //
    // Wrapper methods for error-handling
    //

    long uniqueID (
        struct IXMLDOMNode * pNode );
    long depth (
        struct IXMLDOMNode * pNode );
    long childNumber (
        struct IXMLDOMNode * pNode );
    long ancestorChildNumber (
        _bstr_t bstrNodeName,
        struct IXMLDOMNode * pNode );
    long absoluteChildNumber (
        struct IXMLDOMNode * pNode );
    _bstr_t formatIndex (
        long lIndex,
        _bstr_t bstrFormat );
    _bstr_t formatNumber (
        double dblNumber,
        _bstr_t bstrFormat );
    _bstr_t formatDate (
        const _variant_t & varDate,
        _bstr_t bstrFormat,
        const _variant_t & varDestLocale = vtMissing );
    _bstr_t formatTime (
        const _variant_t & varTime,
        _bstr_t bstrFormat,
        const _variant_t & varDestLocale = vtMissing );

    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall raw_uniqueID (
        /*[in]*/ struct IXMLDOMNode * pNode,
        /*[out,retval]*/ long * pID ) = 0;
      virtual HRESULT __stdcall raw_depth (
        /*[in]*/ struct IXMLDOMNode * pNode,
        /*[out,retval]*/ long * pDepth ) = 0;
      virtual HRESULT __stdcall raw_childNumber (
        /*[in]*/ struct IXMLDOMNode * pNode,
        /*[out,retval]*/ long * pNumber ) = 0;
      virtual HRESULT __stdcall raw_ancestorChildNumber (
        /*[in]*/ BSTR bstrNodeName,
        /*[in]*/ struct IXMLDOMNode * pNode,
        /*[out,retval]*/ long * pNumber ) = 0;
      virtual HRESULT __stdcall raw_absoluteChildNumber (
        /*[in]*/ struct IXMLDOMNode * pNode,
        /*[out,retval]*/ long * pNumber ) = 0;
      virtual HRESULT __stdcall raw_formatIndex (
        /*[in]*/ long lIndex,
        /*[in]*/ BSTR bstrFormat,
        /*[out,retval]*/ BSTR * pbstrFormattedString ) = 0;
      virtual HRESULT __stdcall raw_formatNumber (
        /*[in]*/ double dblNumber,
        /*[in]*/ BSTR bstrFormat,
        /*[out,retval]*/ BSTR * pbstrFormattedString ) = 0;
      virtual HRESULT __stdcall raw_formatDate (
        /*[in]*/ VARIANT varDate,
        /*[in]*/ BSTR bstrFormat,
        /*[in]*/ VARIANT varDestLocale,
        /*[out,retval]*/ BSTR * pbstrFormattedString ) = 0;
      virtual HRESULT __stdcall raw_formatTime (
        /*[in]*/ VARIANT varTime,
        /*[in]*/ BSTR bstrFormat,
        /*[in]*/ VARIANT varDestLocale,
        /*[out,retval]*/ BSTR * pbstrFormattedString ) = 0;
};

struct __declspec(uuid("aa634fc7-5888-44a7-a257-3a47150d3a0e"))
IXMLDOMSelection : IXMLDOMNodeList
{
    //
    // Property data
    //

    __declspec(property(get=Getexpr,put=Putexpr))
    _bstr_t expr;
    __declspec(property(get=Getcontext,put=PutRefcontext))
    IXMLDOMNodePtr context;

    //
    // Wrapper methods for error-handling
    //

    _bstr_t Getexpr ( );
    void Putexpr (
        _bstr_t expression );
    IXMLDOMNodePtr Getcontext ( );
    void PutRefcontext (
        struct IXMLDOMNode * ppNode );
    IXMLDOMNodePtr peekNode ( );
    IXMLDOMNodePtr matches (
        struct IXMLDOMNode * pNode );
    IXMLDOMNodePtr removeNext ( );
    HRESULT removeAll ( );
    IXMLDOMSelectionPtr clone ( );
    _variant_t getProperty (
        _bstr_t name );
    HRESULT setProperty (
        _bstr_t name,
        const _variant_t & value );

    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_expr (
        /*[out,retval]*/ BSTR * expression ) = 0;
      virtual HRESULT __stdcall put_expr (
        /*[in]*/ BSTR expression ) = 0;
      virtual HRESULT __stdcall get_context (
        /*[out,retval]*/ struct IXMLDOMNode * * ppNode ) = 0;
      virtual HRESULT __stdcall putref_context (
        /*[in]*/ struct IXMLDOMNode * ppNode ) = 0;
      virtual HRESULT __stdcall raw_peekNode (
        /*[out,retval]*/ struct IXMLDOMNode * * ppNode ) = 0;
      virtual HRESULT __stdcall raw_matches (
        /*[in]*/ struct IXMLDOMNode * pNode,
        /*[out,retval]*/ struct IXMLDOMNode * * ppNode ) = 0;
      virtual HRESULT __stdcall raw_removeNext (
        /*[out,retval]*/ struct IXMLDOMNode * * ppNode ) = 0;
      virtual HRESULT __stdcall raw_removeAll ( ) = 0;
      virtual HRESULT __stdcall raw_clone (
        /*[out,retval]*/ struct IXMLDOMSelection * * ppNode ) = 0;
      virtual HRESULT __stdcall raw_getProperty (
        /*[in]*/ BSTR name,
        /*[out,retval]*/ VARIANT * value ) = 0;
      virtual HRESULT __stdcall raw_setProperty (
        /*[in]*/ BSTR name,
        /*[in]*/ VARIANT value ) = 0;
};

struct __declspec(uuid("310afa62-0575-11d2-9ca9-0060b0ec3d39"))
IDSOControl : IDispatch
{
    //
    // Property data
    //

    __declspec(property(get=GetXMLDocument,put=PutXMLDocument))
    IXMLDOMDocumentPtr XMLDocument;
    __declspec(property(get=GetJavaDSOCompatible,put=PutJavaDSOCompatible))
    long JavaDSOCompatible;
    __declspec(property(get=GetreadyState))
    long readyState;

    //
    // Wrapper methods for error-handling
    //

    IXMLDOMDocumentPtr GetXMLDocument ( );
    void PutXMLDocument (
        struct IXMLDOMDocument * ppDoc );
    long GetJavaDSOCompatible ( );
    void PutJavaDSOCompatible (
        long fJavaDSOCompatible );
    long GetreadyState ( );

    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_XMLDocument (
        /*[out,retval]*/ struct IXMLDOMDocument * * ppDoc ) = 0;
      virtual HRESULT __stdcall put_XMLDocument (
        /*[in]*/ struct IXMLDOMDocument * ppDoc ) = 0;
      virtual HRESULT __stdcall get_JavaDSOCompatible (
        /*[out,retval]*/ long * fJavaDSOCompatible ) = 0;
      virtual HRESULT __stdcall put_JavaDSOCompatible (
        /*[in]*/ long fJavaDSOCompatible ) = 0;
      virtual HRESULT __stdcall get_readyState (
        /*[out,retval]*/ long * state ) = 0;
};

struct __declspec(uuid("c90352f5-643c-4fbc-bb23-e996eb2d51fd"))
IVBMXNamespaceManager : IDispatch
{
    //
    // Property data
    //

    __declspec(property(get=GetallowOverride,put=PutallowOverride))
    VARIANT_BOOL allowOverride;

    //
    // Wrapper methods for error-handling
    //

    void PutallowOverride (
        VARIANT_BOOL fOverride );
    VARIANT_BOOL GetallowOverride ( );
    HRESULT reset ( );
    HRESULT pushContext ( );
    HRESULT pushNodeContext (
        struct IXMLDOMNode * contextNode,
        VARIANT_BOOL fDeep );
    HRESULT popContext ( );
    HRESULT declarePrefix (
        _bstr_t prefix,
        _bstr_t namespaceURI );
    IMXNamespacePrefixesPtr getDeclaredPrefixes ( );
    IMXNamespacePrefixesPtr getPrefixes (
        _bstr_t namespaceURI );
    _variant_t getURI (
        _bstr_t prefix );
    _variant_t getURIFromNode (
        _bstr_t strPrefix,
        struct IXMLDOMNode * contextNode );

    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall put_allowOverride (
        /*[in]*/ VARIANT_BOOL fOverride ) = 0;
      virtual HRESULT __stdcall get_allowOverride (
        /*[out,retval]*/ VARIANT_BOOL * fOverride ) = 0;
      virtual HRESULT __stdcall raw_reset ( ) = 0;
      virtual HRESULT __stdcall raw_pushContext ( ) = 0;
      virtual HRESULT __stdcall raw_pushNodeContext (
        /*[in]*/ struct IXMLDOMNode * contextNode,
        /*[in]*/ VARIANT_BOOL fDeep ) = 0;
      virtual HRESULT __stdcall raw_popContext ( ) = 0;
      virtual HRESULT __stdcall raw_declarePrefix (
        /*[in]*/ BSTR prefix,
        /*[in]*/ BSTR namespaceURI ) = 0;
      virtual HRESULT __stdcall raw_getDeclaredPrefixes (
        /*[out,retval]*/ struct IMXNamespacePrefixes * * prefixes ) = 0;
      virtual HRESULT __stdcall raw_getPrefixes (
        /*[in]*/ BSTR namespaceURI,
        /*[out,retval]*/ struct IMXNamespacePrefixes * * prefixes ) = 0;
      virtual HRESULT __stdcall raw_getURI (
        /*[in]*/ BSTR prefix,
        /*[out,retval]*/ VARIANT * uri ) = 0;
      virtual HRESULT __stdcall raw_getURIFromNode (
        /*[in]*/ BSTR strPrefix,
        /*[in]*/ struct IXMLDOMNode * contextNode,
        /*[out,retval]*/ VARIANT * uri ) = 0;
};

struct __declspec(uuid("c90352f6-643c-4fbc-bb23-e996eb2d51fd"))
IMXNamespaceManager : IUnknown
{
    //
    // Wrapper methods for error-handling
    //

    HRESULT putAllowOverride (
        VARIANT_BOOL fOverride );
    VARIANT_BOOL getAllowOverride ( );
    HRESULT reset ( );
    HRESULT pushContext ( );
    HRESULT pushNodeContext (
        struct IXMLDOMNode * contextNode,
        VARIANT_BOOL fDeep );
    HRESULT popContext ( );
    HRESULT declarePrefix (
        unsigned short * prefix,
        unsigned short * namespaceURI );
    HRESULT getDeclaredPrefix (
        long nIndex,
        unsigned short * pwchPrefix,
        int * pcchPrefix );
    HRESULT getPrefix (
        unsigned short * pwszNamespaceURI,
        long nIndex,
        unsigned short * pwchPrefix,
        int * pcchPrefix );
    HRESULT getURI (
        unsigned short * pwchPrefix,
        struct IXMLDOMNode * pContextNode,
        unsigned short * pwchUri,
        int * pcchUri );

    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall raw_putAllowOverride (
        /*[in]*/ VARIANT_BOOL fOverride ) = 0;
      virtual HRESULT __stdcall raw_getAllowOverride (
        /*[out,retval]*/ VARIANT_BOOL * fOverride ) = 0;
      virtual HRESULT __stdcall raw_reset ( ) = 0;
      virtual HRESULT __stdcall raw_pushContext ( ) = 0;
      virtual HRESULT __stdcall raw_pushNodeContext (
        /*[in]*/ struct IXMLDOMNode * contextNode,
        /*[in]*/ VARIANT_BOOL fDeep ) = 0;
      virtual HRESULT __stdcall raw_popContext ( ) = 0;
      virtual HRESULT __stdcall raw_declarePrefix (
        /*[in]*/ unsigned short * prefix,
        /*[in]*/ unsigned short * namespaceURI ) = 0;
      virtual HRESULT __stdcall raw_getDeclaredPrefix (
        /*[in]*/ long nIndex,
        /*[in,out]*/ unsigned short * pwchPrefix,
        /*[in,out]*/ int * pcchPrefix ) = 0;
      virtual HRESULT __stdcall raw_getPrefix (
        /*[in]*/ unsigned short * pwszNamespaceURI,
        /*[in]*/ long nIndex,
        /*[in,out]*/ unsigned short * pwchPrefix,
        /*[in,out]*/ int * pcchPrefix ) = 0;
      virtual HRESULT __stdcall raw_getURI (
        /*[in]*/ unsigned short * pwchPrefix,
        /*[in]*/ struct IXMLDOMNode * pContextNode,
        /*[in,out]*/ unsigned short * pwchUri,
        /*[in,out]*/ int * pcchUri ) = 0;
};

struct __declspec(uuid("3efaa428-272f-11d2-836f-0000f87a7782"))
IXMLDOMParseError2 : IXMLDOMParseError
{
    //
    // Property data
    //

    __declspec(property(get=GetallErrors))
    IXMLDOMParseErrorCollectionPtr allErrors;
    __declspec(property(get=GeterrorParametersCount))
    long errorParametersCount;
    __declspec(property(get=GeterrorXPath))
    _bstr_t errorXPath;

    //
    // Wrapper methods for error-handling
    //

    _bstr_t GeterrorXPath ( );
    IXMLDOMParseErrorCollectionPtr GetallErrors ( );
    _bstr_t errorParameters (
        long index );
    long GeterrorParametersCount ( );

    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_errorXPath (
        /*[out,retval]*/ BSTR * xpathexpr ) = 0;
      virtual HRESULT __stdcall get_allErrors (
        /*[out,retval]*/ struct IXMLDOMParseErrorCollection * * allErrors ) = 0;
      virtual HRESULT __stdcall raw_errorParameters (
        /*[in]*/ long index,
        /*[out,retval]*/ BSTR * param ) = 0;
      virtual HRESULT __stdcall get_errorParametersCount (
        /*[out,retval]*/ long * count ) = 0;
};

struct __declspec(uuid("3efaa429-272f-11d2-836f-0000f87a7782"))
IXMLDOMParseErrorCollection : IDispatch
{
    //
    // Property data
    //

    __declspec(property(get=Getitem))
    IXMLDOMParseError2Ptr item[];
    __declspec(property(get=Getlength))
    long length;
    __declspec(property(get=Getnext))
    IXMLDOMParseError2Ptr next;
    __declspec(property(get=Get_newEnum))
    IUnknownPtr _newEnum;

    //
    // Wrapper methods for error-handling
    //

    IXMLDOMParseError2Ptr Getitem (
        long index );
    long Getlength ( );
    IXMLDOMParseError2Ptr Getnext ( );
    HRESULT reset ( );
    IUnknownPtr Get_newEnum ( );

    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_item (
        /*[in]*/ long index,
        /*[out,retval]*/ struct IXMLDOMParseError2 * * error ) = 0;
      virtual HRESULT __stdcall get_length (
        /*[out,retval]*/ long * length ) = 0;
      virtual HRESULT __stdcall get_next (
        /*[out,retval]*/ struct IXMLDOMParseError2 * * error ) = 0;
      virtual HRESULT __stdcall raw_reset ( ) = 0;
      virtual HRESULT __stdcall get__newEnum (
        /*[out,retval]*/ IUnknown * * ppUnk ) = 0;
};

struct __declspec(uuid("2933bf93-7b36-11d2-b20e-00c04f983e60"))
IXSLTemplate : IDispatch
{
    //
    // Property data
    //

    __declspec(property(get=Getstylesheet,put=PutRefstylesheet))
    IXMLDOMNodePtr stylesheet;

    //
    // Wrapper methods for error-handling
    //

    void PutRefstylesheet (
        struct IXMLDOMNode * stylesheet );
    IXMLDOMNodePtr Getstylesheet ( );
    IXSLProcessorPtr createProcessor ( );

    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall putref_stylesheet (
        /*[in]*/ struct IXMLDOMNode * stylesheet ) = 0;
      virtual HRESULT __stdcall get_stylesheet (
        /*[out,retval]*/ struct IXMLDOMNode * * stylesheet ) = 0;
      virtual HRESULT __stdcall raw_createProcessor (
        /*[out,retval]*/ struct IXSLProcessor * * ppProcessor ) = 0;
};

struct __declspec(uuid("2933bf92-7b36-11d2-b20e-00c04f983e60"))
IXSLProcessor : IDispatch
{
    //
    // Property data
    //

    __declspec(property(get=Getinput,put=Putinput))
    _variant_t input;
    __declspec(property(get=GetownerTemplate))
    IXSLTemplatePtr ownerTemplate;
    __declspec(property(get=GetstartMode))
    _bstr_t startMode;
    __declspec(property(get=GetstartModeURI))
    _bstr_t startModeURI;
    __declspec(property(get=Getoutput,put=Putoutput))
    _variant_t output;
    __declspec(property(get=GetreadyState))
    long readyState;
    __declspec(property(get=Getstylesheet))
    IXMLDOMNodePtr stylesheet;

    //
    // Wrapper methods for error-handling
    //

    void Putinput (
        const _variant_t & pVar );
    _variant_t Getinput ( );
    IXSLTemplatePtr GetownerTemplate ( );
    HRESULT setStartMode (
        _bstr_t mode,
        _bstr_t namespaceURI );
    _bstr_t GetstartMode ( );
    _bstr_t GetstartModeURI ( );
    void Putoutput (
        const _variant_t & pOutput );
    _variant_t Getoutput ( );
    VARIANT_BOOL transform ( );
    HRESULT reset ( );
    long GetreadyState ( );
    HRESULT addParameter (
        _bstr_t baseName,
        const _variant_t & parameter,
        _bstr_t namespaceURI );
    HRESULT addObject (
        IDispatch * obj,
        _bstr_t namespaceURI );
    IXMLDOMNodePtr Getstylesheet ( );

    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall put_input (
        /*[in]*/ VARIANT pVar ) = 0;
      virtual HRESULT __stdcall get_input (
        /*[out,retval]*/ VARIANT * pVar ) = 0;
      virtual HRESULT __stdcall get_ownerTemplate (
        /*[out,retval]*/ struct IXSLTemplate * * ppTemplate ) = 0;
      virtual HRESULT __stdcall raw_setStartMode (
        /*[in]*/ BSTR mode,
        /*[in]*/ BSTR namespaceURI ) = 0;
      virtual HRESULT __stdcall get_startMode (
        /*[out,retval]*/ BSTR * mode ) = 0;
      virtual HRESULT __stdcall get_startModeURI (
        /*[out,retval]*/ BSTR * namespaceURI ) = 0;
      virtual HRESULT __stdcall put_output (
        /*[in]*/ VARIANT pOutput ) = 0;
      virtual HRESULT __stdcall get_output (
        /*[out,retval]*/ VARIANT * pOutput ) = 0;
      virtual HRESULT __stdcall raw_transform (
        /*[out,retval]*/ VARIANT_BOOL * pDone ) = 0;
      virtual HRESULT __stdcall raw_reset ( ) = 0;
      virtual HRESULT __stdcall get_readyState (
        /*[out,retval]*/ long * pReadyState ) = 0;
      virtual HRESULT __stdcall raw_addParameter (
        /*[in]*/ BSTR baseName,
        /*[in]*/ VARIANT parameter,
        /*[in]*/ BSTR namespaceURI ) = 0;
      virtual HRESULT __stdcall raw_addObject (
        /*[in]*/ IDispatch * obj,
        /*[in]*/ BSTR namespaceURI ) = 0;
      virtual HRESULT __stdcall get_stylesheet (
        /*[out,retval]*/ struct IXMLDOMNode * * stylesheet ) = 0;
};

struct __declspec(uuid("fa4bb38c-faf9-4cca-9302-d1dd0fe520db"))
IMXSchemaDeclHandler : IDispatch
{
    //
    // Wrapper methods for error-handling
    //

    HRESULT schemaElementDecl (
        struct ISchemaElement * oSchemaElement );

    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall raw_schemaElementDecl (
        /*[in]*/ struct ISchemaElement * oSchemaElement ) = 0;
};

struct __declspec(uuid("50ea08b3-dd1b-4664-9a50-c2f40f4bd79a"))
ISchemaItem : IDispatch
{
    //
    // Property data
    //

    __declspec(property(get=Getid))
    _bstr_t id;
    __declspec(property(get=GetitemType))
    SOMITEMTYPE itemType;
    __declspec(property(get=GetunhandledAttributes))
    IVBSAXAttributesPtr unhandledAttributes;
    __declspec(property(get=Getname))
    _bstr_t name;
    __declspec(property(get=GetnamespaceURI))
    _bstr_t namespaceURI;
    __declspec(property(get=Getschema))
    ISchemaPtr schema;

    //
    // Wrapper methods for error-handling
    //

    _bstr_t Getname ( );
    _bstr_t GetnamespaceURI ( );
    ISchemaPtr Getschema ( );
    _bstr_t Getid ( );
    SOMITEMTYPE GetitemType ( );
    IVBSAXAttributesPtr GetunhandledAttributes ( );
    VARIANT_BOOL writeAnnotation (
        IUnknown * annotationSink );

    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_name (
        /*[out,retval]*/ BSTR * name ) = 0;
      virtual HRESULT __stdcall get_namespaceURI (
        /*[out,retval]*/ BSTR * namespaceURI ) = 0;
      virtual HRESULT __stdcall get_schema (
        /*[out,retval]*/ struct ISchema * * schema ) = 0;
      virtual HRESULT __stdcall get_id (
        /*[out,retval]*/ BSTR * id ) = 0;
      virtual HRESULT __stdcall get_itemType (
        /*[out,retval]*/ SOMITEMTYPE * itemType ) = 0;
      virtual HRESULT __stdcall get_unhandledAttributes (
        /*[out,retval]*/ struct IVBSAXAttributes * * attributes ) = 0;
      virtual HRESULT __stdcall raw_writeAnnotation (
        /*[in]*/ IUnknown * annotationSink,
        /*[out,retval]*/ VARIANT_BOOL * isWritten ) = 0;
};

struct __declspec(uuid("50ea08b5-dd1b-4664-9a50-c2f40f4bd79a"))
ISchemaParticle : ISchemaItem
{
    //
    // Property data
    //

    __declspec(property(get=GetmaxOccurs))
    _variant_t maxOccurs;
    __declspec(property(get=GetminOccurs))
    _variant_t minOccurs;

    //
    // Wrapper methods for error-handling
    //

    _variant_t GetminOccurs ( );
    _variant_t GetmaxOccurs ( );

    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_minOccurs (
        /*[out,retval]*/ VARIANT * minOccurs ) = 0;
      virtual HRESULT __stdcall get_maxOccurs (
        /*[out,retval]*/ VARIANT * maxOccurs ) = 0;
};

struct __declspec(uuid("50ea08b2-dd1b-4664-9a50-c2f40f4bd79a"))
ISchemaItemCollection : IDispatch
{
    //
    // Property data
    //

    __declspec(property(get=Getitem))
    ISchemaItemPtr item[];
    __declspec(property(get=Getlength))
    long length;
    __declspec(property(get=Get_newEnum))
    IUnknownPtr _newEnum;

    //
    // Wrapper methods for error-handling
    //

    ISchemaItemPtr Getitem (
        long index );
    ISchemaItemPtr itemByName (
        _bstr_t name );
    ISchemaItemPtr itemByQName (
        _bstr_t name,
        _bstr_t namespaceURI );
    long Getlength ( );
    IUnknownPtr Get_newEnum ( );

    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_item (
        /*[in]*/ long index,
        /*[out,retval]*/ struct ISchemaItem * * item ) = 0;
      virtual HRESULT __stdcall raw_itemByName (
        /*[in]*/ BSTR name,
        /*[out,retval]*/ struct ISchemaItem * * item ) = 0;
      virtual HRESULT __stdcall raw_itemByQName (
        /*[in]*/ BSTR name,
        /*[in]*/ BSTR namespaceURI,
        /*[out,retval]*/ struct ISchemaItem * * item ) = 0;
      virtual HRESULT __stdcall get_length (
        /*[out,retval]*/ long * length ) = 0;
      virtual HRESULT __stdcall get__newEnum (
        /*[out,retval]*/ IUnknown * * ppUnk ) = 0;
};

struct __declspec(uuid("50ea08b4-dd1b-4664-9a50-c2f40f4bd79a"))
ISchema : ISchemaItem
{
    //
    // Property data
    //

    __declspec(property(get=GettargetNamespace))
    _bstr_t targetNamespace;
    __declspec(property(get=Gettypes))
    ISchemaItemCollectionPtr types;
    __declspec(property(get=Getversion))
    _bstr_t version;
    __declspec(property(get=GetmodelGroups))
    ISchemaItemCollectionPtr modelGroups;
    __declspec(property(get=GetattributeGroups))
    ISchemaItemCollectionPtr attributeGroups;
    __declspec(property(get=Getattributes))
    ISchemaItemCollectionPtr attributes;
    __declspec(property(get=Getnotations))
    ISchemaItemCollectionPtr notations;
    __declspec(property(get=Getelements))
    ISchemaItemCollectionPtr elements;
    __declspec(property(get=GetschemaLocations))
    ISchemaStringCollectionPtr schemaLocations;

    //
    // Wrapper methods for error-handling
    //

    _bstr_t GettargetNamespace ( );
    _bstr_t Getversion ( );
    ISchemaItemCollectionPtr Gettypes ( );
    ISchemaItemCollectionPtr Getelements ( );
    ISchemaItemCollectionPtr Getattributes ( );
    ISchemaItemCollectionPtr GetattributeGroups ( );
    ISchemaItemCollectionPtr GetmodelGroups ( );
    ISchemaItemCollectionPtr Getnotations ( );
    ISchemaStringCollectionPtr GetschemaLocations ( );

    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_targetNamespace (
        /*[out,retval]*/ BSTR * targetNamespace ) = 0;
      virtual HRESULT __stdcall get_version (
        /*[out,retval]*/ BSTR * version ) = 0;
      virtual HRESULT __stdcall get_types (
        /*[out,retval]*/ struct ISchemaItemCollection * * types ) = 0;
      virtual HRESULT __stdcall get_elements (
        /*[out,retval]*/ struct ISchemaItemCollection * * elements ) = 0;
      virtual HRESULT __stdcall get_attributes (
        /*[out,retval]*/ struct ISchemaItemCollection * * attributes ) = 0;
      virtual HRESULT __stdcall get_attributeGroups (
        /*[out,retval]*/ struct ISchemaItemCollection * * attributeGroups ) = 0;
      virtual HRESULT __stdcall get_modelGroups (
        /*[out,retval]*/ struct ISchemaItemCollection * * modelGroups ) = 0;
      virtual HRESULT __stdcall get_notations (
        /*[out,retval]*/ struct ISchemaItemCollection * * notations ) = 0;
      virtual HRESULT __stdcall get_schemaLocations (
        /*[out,retval]*/ struct ISchemaStringCollection * * schemaLocations ) = 0;
};

struct __declspec(uuid("50ea08b8-dd1b-4664-9a50-c2f40f4bd79a"))
ISchemaType : ISchemaItem
{
    //
    // Property data
    //

    __declspec(property(get=GettotalDigits))
    _variant_t totalDigits;
    __declspec(property(get=Getlength))
    _variant_t length;
    __declspec(property(get=Getvariety))
    SCHEMATYPEVARIETY variety;
    __declspec(property(get=GetmaxExclusive))
    _bstr_t maxExclusive;
    __declspec(property(get=GetmaxInclusive))
    _bstr_t maxInclusive;
    __declspec(property(get=GetmaxLength))
    _variant_t maxLength;
    __declspec(property(get=GetminExclusive))
    _bstr_t minExclusive;
    __declspec(property(get=GetminInclusive))
    _bstr_t minInclusive;
    __declspec(property(get=GetminLength))
    _variant_t minLength;
    __declspec(property(get=Getwhitespace))
    SCHEMAWHITESPACE whitespace;
    __declspec(property(get=GetbaseTypes))
    ISchemaItemCollectionPtr baseTypes;
    __declspec(property(get=Getpatterns))
    ISchemaStringCollectionPtr patterns;
    __declspec(property(get=GetderivedBy))
    SCHEMADERIVATIONMETHOD derivedBy;
    __declspec(property(get=Getenumeration))
    ISchemaStringCollectionPtr enumeration;
    __declspec(property(get=Getfinal))
    SCHEMADERIVATIONMETHOD final;
    __declspec(property(get=GetfractionDigits))
    _variant_t fractionDigits;

    //
    // Wrapper methods for error-handling
    //

    ISchemaItemCollectionPtr GetbaseTypes ( );
    SCHEMADERIVATIONMETHOD Getfinal ( );
    SCHEMATYPEVARIETY Getvariety ( );
    SCHEMADERIVATIONMETHOD GetderivedBy ( );
    VARIANT_BOOL isValid (
        _bstr_t data );
    _bstr_t GetminExclusive ( );
    _bstr_t GetminInclusive ( );
    _bstr_t GetmaxExclusive ( );
    _bstr_t GetmaxInclusive ( );
    _variant_t GettotalDigits ( );
    _variant_t GetfractionDigits ( );
    _variant_t Getlength ( );
    _variant_t GetminLength ( );
    _variant_t GetmaxLength ( );
    ISchemaStringCollectionPtr Getenumeration ( );
    SCHEMAWHITESPACE Getwhitespace ( );
    ISchemaStringCollectionPtr Getpatterns ( );

    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_baseTypes (
        /*[out,retval]*/ struct ISchemaItemCollection * * baseTypes ) = 0;
      virtual HRESULT __stdcall get_final (
        /*[out,retval]*/ SCHEMADERIVATIONMETHOD * final ) = 0;
      virtual HRESULT __stdcall get_variety (
        /*[out,retval]*/ SCHEMATYPEVARIETY * variety ) = 0;
      virtual HRESULT __stdcall get_derivedBy (
        /*[out,retval]*/ SCHEMADERIVATIONMETHOD * derivedBy ) = 0;
      virtual HRESULT __stdcall raw_isValid (
        /*[in]*/ BSTR data,
        /*[out,retval]*/ VARIANT_BOOL * valid ) = 0;
      virtual HRESULT __stdcall get_minExclusive (
        /*[out,retval]*/ BSTR * minExclusive ) = 0;
      virtual HRESULT __stdcall get_minInclusive (
        /*[out,retval]*/ BSTR * minInclusive ) = 0;
      virtual HRESULT __stdcall get_maxExclusive (
        /*[out,retval]*/ BSTR * maxExclusive ) = 0;
      virtual HRESULT __stdcall get_maxInclusive (
        /*[out,retval]*/ BSTR * maxInclusive ) = 0;
      virtual HRESULT __stdcall get_totalDigits (
        /*[out,retval]*/ VARIANT * totalDigits ) = 0;
      virtual HRESULT __stdcall get_fractionDigits (
        /*[out,retval]*/ VARIANT * fractionDigits ) = 0;
      virtual HRESULT __stdcall get_length (
        /*[out,retval]*/ VARIANT * length ) = 0;
      virtual HRESULT __stdcall get_minLength (
        /*[out,retval]*/ VARIANT * minLength ) = 0;
      virtual HRESULT __stdcall get_maxLength (
        /*[out,retval]*/ VARIANT * maxLength ) = 0;
      virtual HRESULT __stdcall get_enumeration (
        /*[out,retval]*/ struct ISchemaStringCollection * * enumeration ) = 0;
      virtual HRESULT __stdcall get_whitespace (
        /*[out,retval]*/ SCHEMAWHITESPACE * whitespace ) = 0;
      virtual HRESULT __stdcall get_patterns (
        /*[out,retval]*/ struct ISchemaStringCollection * * patterns ) = 0;
};

struct __declspec(uuid("50ea08bc-dd1b-4664-9a50-c2f40f4bd79a"))
ISchemaAny : ISchemaParticle
{
    //
    // Property data
    //

    __declspec(property(get=Getnamespaces))
    ISchemaStringCollectionPtr namespaces;
    __declspec(property(get=GetprocessContents))
    SCHEMAPROCESSCONTENTS processContents;

    //
    // Wrapper methods for error-handling
    //

    ISchemaStringCollectionPtr Getnamespaces ( );
    SCHEMAPROCESSCONTENTS GetprocessContents ( );

    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_namespaces (
        /*[out,retval]*/ struct ISchemaStringCollection * * namespaces ) = 0;
      virtual HRESULT __stdcall get_processContents (
        /*[out,retval]*/ SCHEMAPROCESSCONTENTS * processContents ) = 0;
};

struct __declspec(uuid("50ea08bb-dd1b-4664-9a50-c2f40f4bd79a"))
ISchemaModelGroup : ISchemaParticle
{
    //
    // Property data
    //

    __declspec(property(get=Getparticles))
    ISchemaItemCollectionPtr particles;

    //
    // Wrapper methods for error-handling
    //

    ISchemaItemCollectionPtr Getparticles ( );

    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_particles (
        /*[out,retval]*/ struct ISchemaItemCollection * * particles ) = 0;
};

struct __declspec(uuid("50ea08b9-dd1b-4664-9a50-c2f40f4bd79a"))
ISchemaComplexType : ISchemaType
{
    //
    // Property data
    //

    __declspec(property(get=GetisAbstract))
    VARIANT_BOOL isAbstract;
    __declspec(property(get=GetanyAttribute))
    ISchemaAnyPtr anyAttribute;
    __declspec(property(get=Getattributes))
    ISchemaItemCollectionPtr attributes;
    __declspec(property(get=GetcontentModel))
    ISchemaModelGroupPtr contentModel;
    __declspec(property(get=GetcontentType))
    SCHEMACONTENTTYPE contentType;
    __declspec(property(get=GetprohibitedSubstitutions))
    SCHEMADERIVATIONMETHOD prohibitedSubstitutions;

    //
    // Wrapper methods for error-handling
    //

    VARIANT_BOOL GetisAbstract ( );
    ISchemaAnyPtr GetanyAttribute ( );
    ISchemaItemCollectionPtr Getattributes ( );
    SCHEMACONTENTTYPE GetcontentType ( );
    ISchemaModelGroupPtr GetcontentModel ( );
    SCHEMADERIVATIONMETHOD GetprohibitedSubstitutions ( );

    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_isAbstract (
        /*[out,retval]*/ VARIANT_BOOL * abstract ) = 0;
      virtual HRESULT __stdcall get_anyAttribute (
        /*[out,retval]*/ struct ISchemaAny * * anyAttribute ) = 0;
      virtual HRESULT __stdcall get_attributes (
        /*[out,retval]*/ struct ISchemaItemCollection * * attributes ) = 0;
      virtual HRESULT __stdcall get_contentType (
        /*[out,retval]*/ SCHEMACONTENTTYPE * contentType ) = 0;
      virtual HRESULT __stdcall get_contentModel (
        /*[out,retval]*/ struct ISchemaModelGroup * * contentModel ) = 0;
      virtual HRESULT __stdcall get_prohibitedSubstitutions (
        /*[out,retval]*/ SCHEMADERIVATIONMETHOD * prohibited ) = 0;
};

struct __declspec(uuid("50ea08b7-dd1b-4664-9a50-c2f40f4bd79a"))
ISchemaElement : ISchemaParticle
{
    //
    // Property data
    //

    __declspec(property(get=GetsubstitutionGroupExclusions))
    SCHEMADERIVATIONMETHOD substitutionGroupExclusions;
    __declspec(property(get=GetidentityConstraints))
    ISchemaItemCollectionPtr identityConstraints;
    __declspec(property(get=GetisAbstract))
    VARIANT_BOOL isAbstract;
    __declspec(property(get=GetisNillable))
    VARIANT_BOOL isNillable;
    __declspec(property(get=Gettype))
    ISchemaTypePtr type;
    __declspec(property(get=GetisReference))
    VARIANT_BOOL isReference;
    __declspec(property(get=GetdefaultValue))
    _bstr_t defaultValue;
    __declspec(property(get=GetdisallowedSubstitutions))
    SCHEMADERIVATIONMETHOD disallowedSubstitutions;
    __declspec(property(get=Getscope))
    ISchemaComplexTypePtr scope;
    __declspec(property(get=GetfixedValue))
    _bstr_t fixedValue;
    __declspec(property(get=GetsubstitutionGroup))
    ISchemaElementPtr substitutionGroup;

    //
    // Wrapper methods for error-handling
    //

    ISchemaTypePtr Gettype ( );
    ISchemaComplexTypePtr Getscope ( );
    _bstr_t GetdefaultValue ( );
    _bstr_t GetfixedValue ( );
    VARIANT_BOOL GetisNillable ( );
    ISchemaItemCollectionPtr GetidentityConstraints ( );
    ISchemaElementPtr GetsubstitutionGroup ( );
    SCHEMADERIVATIONMETHOD GetsubstitutionGroupExclusions ( );
    SCHEMADERIVATIONMETHOD GetdisallowedSubstitutions ( );
    VARIANT_BOOL GetisAbstract ( );
    VARIANT_BOOL GetisReference ( );

    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_type (
        /*[out,retval]*/ struct ISchemaType * * type ) = 0;
      virtual HRESULT __stdcall get_scope (
        /*[out,retval]*/ struct ISchemaComplexType * * scope ) = 0;
      virtual HRESULT __stdcall get_defaultValue (
        /*[out,retval]*/ BSTR * defaultValue ) = 0;
      virtual HRESULT __stdcall get_fixedValue (
        /*[out,retval]*/ BSTR * fixedValue ) = 0;
      virtual HRESULT __stdcall get_isNillable (
        /*[out,retval]*/ VARIANT_BOOL * nillable ) = 0;
      virtual HRESULT __stdcall get_identityConstraints (
        /*[out,retval]*/ struct ISchemaItemCollection * * constraints ) = 0;
      virtual HRESULT __stdcall get_substitutionGroup (
        /*[out,retval]*/ struct ISchemaElement * * element ) = 0;
      virtual HRESULT __stdcall get_substitutionGroupExclusions (
        /*[out,retval]*/ SCHEMADERIVATIONMETHOD * exclusions ) = 0;
      virtual HRESULT __stdcall get_disallowedSubstitutions (
        /*[out,retval]*/ SCHEMADERIVATIONMETHOD * disallowed ) = 0;
      virtual HRESULT __stdcall get_isAbstract (
        /*[out,retval]*/ VARIANT_BOOL * abstract ) = 0;
      virtual HRESULT __stdcall get_isReference (
        /*[out,retval]*/ VARIANT_BOOL * reference ) = 0;
};

struct __declspec(uuid("50ea08b0-dd1b-4664-9a50-c2f40f4bd79a"))
IXMLDOMSchemaCollection2 : IXMLDOMSchemaCollection
{
    //
    // Property data
    //

    __declspec(property(get=GetvalidateOnLoad,put=PutvalidateOnLoad))
    VARIANT_BOOL validateOnLoad;

    //
    // Wrapper methods for error-handling
    //

    HRESULT validate ( );
    void PutvalidateOnLoad (
        VARIANT_BOOL validateOnLoad );
    VARIANT_BOOL GetvalidateOnLoad ( );
    ISchemaPtr getSchema (
        _bstr_t namespaceURI );
    ISchemaItemPtr getDeclaration (
        struct IXMLDOMNode * node );

    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall raw_validate ( ) = 0;
      virtual HRESULT __stdcall put_validateOnLoad (
        /*[in]*/ VARIANT_BOOL validateOnLoad ) = 0;
      virtual HRESULT __stdcall get_validateOnLoad (
        /*[out,retval]*/ VARIANT_BOOL * validateOnLoad ) = 0;
      virtual HRESULT __stdcall raw_getSchema (
        /*[in]*/ BSTR namespaceURI,
        /*[out,retval]*/ struct ISchema * * schema ) = 0;
      virtual HRESULT __stdcall raw_getDeclaration (
        /*[in]*/ struct IXMLDOMNode * node,
        /*[out,retval]*/ struct ISchemaItem * * item ) = 0;
};

struct __declspec(uuid("50ea08b6-dd1b-4664-9a50-c2f40f4bd79a"))
ISchemaAttribute : ISchemaItem
{
    //
    // Property data
    //

    __declspec(property(get=Gettype))
    ISchemaTypePtr type;
    __declspec(property(get=GetisReference))
    VARIANT_BOOL isReference;
    __declspec(property(get=Getuse))
    SCHEMAUSE use;
    __declspec(property(get=GetdefaultValue))
    _bstr_t defaultValue;
    __declspec(property(get=Getscope))
    ISchemaComplexTypePtr scope;
    __declspec(property(get=GetfixedValue))
    _bstr_t fixedValue;

    //
    // Wrapper methods for error-handling
    //

    ISchemaTypePtr Gettype ( );
    ISchemaComplexTypePtr Getscope ( );
    _bstr_t GetdefaultValue ( );
    _bstr_t GetfixedValue ( );
    SCHEMAUSE Getuse ( );
    VARIANT_BOOL GetisReference ( );

    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_type (
        /*[out,retval]*/ struct ISchemaType * * type ) = 0;
      virtual HRESULT __stdcall get_scope (
        /*[out,retval]*/ struct ISchemaComplexType * * scope ) = 0;
      virtual HRESULT __stdcall get_defaultValue (
        /*[out,retval]*/ BSTR * defaultValue ) = 0;
      virtual HRESULT __stdcall get_fixedValue (
        /*[out,retval]*/ BSTR * fixedValue ) = 0;
      virtual HRESULT __stdcall get_use (
        /*[out,retval]*/ SCHEMAUSE * use ) = 0;
      virtual HRESULT __stdcall get_isReference (
        /*[out,retval]*/ VARIANT_BOOL * reference ) = 0;
};

struct __declspec(uuid("50ea08ba-dd1b-4664-9a50-c2f40f4bd79a"))
ISchemaAttributeGroup : ISchemaItem
{
    //
    // Property data
    //

    __declspec(property(get=GetanyAttribute))
    ISchemaAnyPtr anyAttribute;
    __declspec(property(get=Getattributes))
    ISchemaItemCollectionPtr attributes;

    //
    // Wrapper methods for error-handling
    //

    ISchemaAnyPtr GetanyAttribute ( );
    ISchemaItemCollectionPtr Getattributes ( );

    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_anyAttribute (
        /*[out,retval]*/ struct ISchemaAny * * anyAttribute ) = 0;
      virtual HRESULT __stdcall get_attributes (
        /*[out,retval]*/ struct ISchemaItemCollection * * attributes ) = 0;
};

struct __declspec(uuid("50ea08bd-dd1b-4664-9a50-c2f40f4bd79a"))
ISchemaIdentityConstraint : ISchemaItem
{
    //
    // Property data
    //

    __declspec(property(get=GetreferencedKey))
    ISchemaIdentityConstraintPtr referencedKey;
    __declspec(property(get=Getfields))
    ISchemaStringCollectionPtr fields;
    __declspec(property(get=Getselector))
    _bstr_t selector;

    //
    // Wrapper methods for error-handling
    //

    _bstr_t Getselector ( );
    ISchemaStringCollectionPtr Getfields ( );
    ISchemaIdentityConstraintPtr GetreferencedKey ( );

    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_selector (
        /*[out,retval]*/ BSTR * selector ) = 0;
      virtual HRESULT __stdcall get_fields (
        /*[out,retval]*/ struct ISchemaStringCollection * * fields ) = 0;
      virtual HRESULT __stdcall get_referencedKey (
        /*[out,retval]*/ struct ISchemaIdentityConstraint * * key ) = 0;
};

struct __declspec(uuid("50ea08be-dd1b-4664-9a50-c2f40f4bd79a"))
ISchemaNotation : ISchemaItem
{
    //
    // Property data
    //

    __declspec(property(get=GetsystemIdentifier))
    _bstr_t systemIdentifier;
    __declspec(property(get=GetpublicIdentifier))
    _bstr_t publicIdentifier;

    //
    // Wrapper methods for error-handling
    //

    _bstr_t GetsystemIdentifier ( );
    _bstr_t GetpublicIdentifier ( );

    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_systemIdentifier (
        /*[out,retval]*/ BSTR * uri ) = 0;
      virtual HRESULT __stdcall get_publicIdentifier (
        /*[out,retval]*/ BSTR * uri ) = 0;
};

//
// Wrapper method implementations
//

} // namespace MSXML2

#pragma pack(pop)
