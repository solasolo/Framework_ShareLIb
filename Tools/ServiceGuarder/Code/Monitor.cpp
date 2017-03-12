#include "Monitor.h"

MonitorThread::MonitorThread(BaseEventLogger* logger)
	: SimpleThread(L"Service Guarder")
{
	this->SleepTimer = 10000;
	this->Logger = logger;
}

MonitorThread::~MonitorThread()
{
}

void MonitorThread::AddService(wstring name)
{
	CriticalGuard CG(this->ListLocker);

	this->ServiceList.push_back(new ServiceManager(name));

	CG.Close();
}

void MonitorThread::Check(ServiceManager* service)
{
	if (!service->IsRunning())
	{
		service->Start();

		this->Logger->Log(EventType::etMessage, service->getName() + L" Restarted");
	}
}

void MonitorThread::RunTask()
{
		CriticalGuard CG(this->ListLocker);

		vector<ServiceManager*>::iterator it;

		for (it = this->ServiceList.begin(); it != this->ServiceList.end(); it++) 
		{
			this->Check(*it);
		}

		CG.Close();
}

void MonitorThread::Notify(wstring& msg, EventType type)
{
	this->Logger->Log(type, msg);
}