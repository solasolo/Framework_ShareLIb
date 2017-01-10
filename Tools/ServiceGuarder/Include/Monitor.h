#pragma once

#include "ThreadWrap.h"
#include "WinService.h"
#include "Synchronization.h"

#include <vector>

using namespace std;
using namespace Win32Lib;

class MonitorThread : public SimpleThread
{
public:
	 MonitorThread(BaseEventLogger* logger);
	~MonitorThread();

	void AddService(wstring name);

protected:
	virtual void RunTask();
	virtual void Notify(wstring& msg, EventType type = etMessage);

private:
	BaseEventLogger* Logger;
	CriticalSection ListLocker;

	vector<ServiceManager*> ServiceList;
	void Check(ServiceManager* service);
};

