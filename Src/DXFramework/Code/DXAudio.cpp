#include "stdafx.h"
#include "DXAudio.h"

#include "DXException.h"
#include "WinFuncs.h"
#include "CommonFuncs.h"

//
//
//
int CHANNELS_MAP = 1;
int CHANNELS_NUM = 1;

SoundDevice::SoundDevice(GUID guid, HWND hWnd, DWORD PrimaryChannels, DWORD PrimaryFreq, DWORD PrimaryBitRate)
{
	this->DirectSound = NULL;
	this->PrimaryBuffer = NULL;

	this->DeviceID = guid;
	this->CreatDirectSound(hWnd);
	this->CreatPrimaryBuffer(PrimaryChannels, PrimaryFreq, PrimaryBitRate);
}

void SoundDevice::CreatDirectSound(HWND hWnd)
{
	HRESULT hr;
	IDirectSound8* pDirectSound = NULL;
	
	hr = DirectSoundCreate8(&this->DeviceID, &pDirectSound, NULL);
	DXException::Check(hr,"Create DirectSound");

	this->DirectSound << pDirectSound;

	hr = DirectSound->SetCooperativeLevel( hWnd , DSSCL_PRIORITY);
	DXException::Check(hr,"Set Cooperative Level");
}

void SoundDevice::CreatPrimaryBuffer(DWORD PrimaryChannels, DWORD PrimaryFreq, DWORD PrimaryBitRate)
{
	HRESULT hr;

	DSBUFFERDESC dsbd;
	ZeroMemory(&dsbd, sizeof(DSBUFFERDESC));
	dsbd.dwSize = sizeof(DSBUFFERDESC);
	dsbd.dwFlags = DSBCAPS_PRIMARYBUFFER;
	dsbd.dwBufferBytes = 0;
	dsbd.lpwfxFormat = NULL;

	IDirectSoundBuffer* pBuffer;
	hr = this->DirectSound->CreateSoundBuffer(&dsbd, &pBuffer, NULL);
	DXException::Check(hr,"Create Primary Sound Buffer");

	this->PrimaryBuffer << pBuffer;

	ZeroMemory(&SoundFormat, sizeof(SoundFormat));

	SoundFormat.nSamplesPerSec	= PrimaryFreq;
	SoundFormat.wBitsPerSample	= (WORD)PrimaryBitRate;
	SoundFormat.wFormatTag = WAVE_FORMAT_PCM;
	SoundFormat.nChannels = (WORD)PrimaryChannels;
	SoundFormat.nBlockAlign = (WORD)(SoundFormat.wBitsPerSample / 8 * SoundFormat.nChannels);
	SoundFormat.nAvgBytesPerSec = (DWORD)(SoundFormat.nSamplesPerSec * SoundFormat.nBlockAlign);

	hr = this->PrimaryBuffer->SetFormat(&SoundFormat);
	DXException::Check(hr, "Set Primary Buffer Format");
}

IDirectSoundBuffer8Ptr SoundDevice::CreateBuffer(int len)
{
	HRESULT hr;

	IDirectSoundBuffer* pBuffer = NULL;

	WAVEFORMATEXTENSIBLE wfextensb;
	ZeroMemory(&wfextensb, sizeof(WAVEFORMATEXTENSIBLE) );

	wfextensb.Format = SoundFormat;

	wfextensb.Format.cbSize = 22;
	wfextensb.Format.wFormatTag  =(DWORD) WAVE_FORMAT_EXTENSIBLE;

	wfextensb.SubFormat = KSDATAFORMAT_SUBTYPE_PCM;
	wfextensb.Samples.wValidBitsPerSample = wfextensb.Format.wBitsPerSample;
	wfextensb.dwChannelMask = CHANNELS_MAP;

	DSBUFFERDESC seconddsbd;
	ZeroMemory(&seconddsbd, sizeof(seconddsbd));
	seconddsbd.dwSize = sizeof(seconddsbd);
	seconddsbd.dwFlags = DSBCAPS_GLOBALFOCUS | DSBCAPS_CTRLPOSITIONNOTIFY | DSBCAPS_GETCURRENTPOSITION2 | DSBCAPS_CTRLVOLUME;
	seconddsbd.dwBufferBytes = len * 2 * CHANNELS_NUM;
	seconddsbd.lpwfxFormat = (LPWAVEFORMATEX)&wfextensb;

	CriticalGuard CG(DeviceSection);

	hr = DirectSound->CreateSoundBuffer(&seconddsbd, &pBuffer, NULL);
	DXException::Check(hr, "Create Sencondary SoundBuffer");

	CG.Close();

	IDirectSoundBufferPtr Result;
	Result << pBuffer;

	return Result.Query<IDirectSoundBuffer8>(IID_IDirectSoundBuffer8);
}

#pragma region DeviceManager

bool AudioDeviceManager::DSEnumCallback(LPGUID lpGuid, LPCSTR lpcstrDescription, LPCSTR lpcstrModule, LPVOID lpContext)
{
	AudioDeviceManager* me = (AudioDeviceManager*)lpContext;

	if (lpGuid != NULL)
	{
		me->DeviceGUIDs.push_back(*lpGuid);
	}

	return(TRUE);
}


AudioDeviceManager::AudioDeviceManager()
{
	this->HidenWindows = NULL;
}

AudioDeviceManager::~AudioDeviceManager()
{
	this->ClearAll();

	if(this->HidenWindows != NULL)
	{
		CloseWindow(this->HidenWindows);
	}
}

void AudioDeviceManager::Build()
{
	this->HidenWindows = CreateHiddenWindow();
	this->CreateAll(HidenWindows);
}

void AudioDeviceManager::GetDeviceList(vector<GUID>& devices)
{
	devices = this->DeviceGUIDs;
}

SoundDevice* AudioDeviceManager::getDevice(GUID guid)
{
	SoundDevice* Result = NULL;

	map<GUID, SoundDevice*>::iterator hinter = this->Devices.find(guid);
	if(hinter != Devices.end())
	{
		Result = hinter->second;
	}

	return Result;
}

void AudioDeviceManager::CreateAll(HWND hWnd)
{
	HRESULT hr;
	int Device_no = 0;

	EnumerateDevices();

	vector<GUID>::iterator iter = DeviceGUIDs.begin();
	while(iter != DeviceGUIDs.end())
	{
		try
		{
			Devices[*iter] = new SoundDevice(*iter, hWnd, CHANNELS_NUM, 44100L, 16);
			iter++;
		}
		catch(DXException ex)
		{
			iter = DeviceGUIDs.erase(iter);
		}

	}
}

void AudioDeviceManager::EnumerateDevices()
{
	DeviceGUIDs.clear();

	HRESULT hr = DirectSoundEnumerate((LPDSENUMCALLBACK)DSEnumCallback, (void*)this);	
	DXException::Check(hr, "Enumerate Devices");
}

void AudioDeviceManager::ClearAll()
{
	map<GUID, SoundDevice*>::iterator iter = Devices.begin();
	while(iter != Devices.end())
	{
		DESTROY(iter->second);

		iter++;
	}
}

#pragma endregion

