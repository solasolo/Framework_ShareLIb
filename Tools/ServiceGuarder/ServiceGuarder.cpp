// ServiceGuarder.cpp : Defines the entry point for the console application.
//
#include "BaseException.h"
#include "ServiceApplication.h"
#include "WinException.h"
#include "ThreadLogger.h"
#include "Monitor.h"
#include "XMLConfig.h"
#include "XMLReader.h"
#include "WinFuncs.h"

#include <conio.h>

using namespace GLEO;
using namespace Win32Lib;


class MorintorServiceMoudle : public ServiceModule
{
protected:
	void NotifyFunc(void* sender, wstring& msg, EventType type)
	{
		this->Log(type, msg);
	}
	
	BaseEventLogger* BuildLogger()
	{
		ThreadEventLogger* Logger = new ThreadEventLogger();
		Logger->AddLoggerObject(new TextEventLogger(BasePath + L"..\\LOG\\", L"SCM"));

		return Logger;
	}

private:
	MonitorThread* WorkThread;

public:
	MorintorServiceMoudle(void)
		: ServiceModule(L"ServiceGuarder", L"ServiceGuarder")
	{
		this->WorkThread = NULL;
	}

	~MorintorServiceMoudle(void)
	{
		if (this->WorkThread)
		{
			this->WorkThread->Shutdown();
		}

		DESTROY(this->WorkThread);
	}

	void StartProcess()
	{
		this->WorkThread = new MonitorThread(this->Logger);

		wstring BasePath = GetStartupPath();
		XMLReader Reader;

		Reader.Load(BasePath + L"..\\Data\\Service.xml");
		
		vector<MSXML2::IXMLDOMNodePtr> ServiceNodes;
		MSXML2::IXMLDOMNodePtr RootNode = Reader.GetRoot();
		Reader.GetChildNodes(RootNode, ServiceNodes);
		
		vector<MSXML2::IXMLDOMNodePtr>::iterator iter;
		for (iter = ServiceNodes.begin(); iter != ServiceNodes.end(); iter++)
		{
			wstring name = Reader.GetAttributeString(*iter, L"Name");
			this->WorkThread->AddService(name);
		}
	}

	void StopProcess()
	{
	}
};


MorintorServiceMoudle ServiceMoudle;

int _tmain(int argc, _TCHAR* argv[])
{
	SException::Install();

	try
	{
		ServiceApplication Application(&ServiceMoudle);
		Application.Run(argc, argv);
	}
	catch (Exception& ex)
	{
		wprintf(L"%x", ex.why());
	}

	return 0;
}

