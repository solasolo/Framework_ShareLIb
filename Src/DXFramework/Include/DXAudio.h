#pragma once

#include <windows.h>
#include <guiddef.h>
#include <comdef.h>
#include <comip.h>
#include <mmsystem.h>
#include <mmreg.h>
#include <ks.h>
#include <KSMEDIA.h>
#include <dsound.h>

#include <vector>
#include <map>

#include "SmartPointer.h"
#include "Synchronization.h"

using namespace std;
using namespace Win32Lib;
using namespace GLEO;

COMPtr(IDirectSound8);
COMPtr(IDirectSoundBuffer);
COMPtr(IDirectSoundBuffer8);

class SoundDevice
{
private:
	GUID DeviceID;
	WAVEFORMATEX SoundFormat;

	IDirectSound8Ptr DirectSound;
	IDirectSoundBufferPtr PrimaryBuffer;
	
	CriticalSection DeviceSection;

	void CreatDirectSound(HWND hWnd);	
	void CreatPrimaryBuffer(DWORD PrimaryChannels, DWORD PrimaryFreq, DWORD PrimaryBitRate);

public:
	SoundDevice(GUID guid, HWND hWnd, DWORD PrimaryChannels, DWORD PrimaryFreq, DWORD PrimaryBitRate);

	IDirectSoundBuffer8Ptr CreateBuffer(int len);
};

class __declspec(dllexport) AudioDeviceManager
{
private:
	static bool CALLBACK DSEnumCallback(LPGUID lpGuid, LPCSTR lpcstrDescription, LPCSTR lpcstrModule, LPVOID lpContext);

private:
	HWND HidenWindows;

	vector<GUID> DeviceGUIDs;
	map<GUID, SoundDevice*> Devices;

	void EnumerateDevices();
	void CreateAll(HWND hWnd);
	void ClearAll();

public:
	AudioDeviceManager();
	~AudioDeviceManager();

	void Build();

	void GetDeviceList(vector<GUID>& devices);
	SoundDevice* getDevice(GUID guid);
};
