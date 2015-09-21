#include "stdafx.h"

#include "GraphicBaseDevice.h"

#include <D3DX11async.h>

namespace GLEO
{
	ShaderCompileExcepton::ShaderCompileExcepton(int code, ID3DBlob* msg)
		: DXException(code, L"Complie Shader")
	{
		if(msg)
		{
			this->ComplieError.append((char*)msg->GetBufferPointer(), msg->GetBufferSize());
		}
	}

	wstring ShaderCompileExcepton::GetErrorDescription()
	{
		wstring Result = DXException::GetErrorDescription();

		Result += L"\r\n" + ~this->ComplieError;

		return Result;
	}
}

namespace GLEO
{
	vector<IDXGIAdapter1Ptr> GraphicDeviceManager::AdapterList; 
	vector<wstring> GraphicDeviceManager::AdapterNames;
	IDXGIFactory1Ptr GraphicDeviceManager::DXGIFactory;

	const D3D_FEATURE_LEVEL FeatureLevelList[] = { D3D_FEATURE_LEVEL_11_0, D3D_FEATURE_LEVEL_10_1, D3D_FEATURE_LEVEL_10_0 };

	GraphicDeviceManager::GraphicDeviceManager()
	{
	}

	void GraphicDeviceManager::Init()
	{
		if(!DXGIFactory)
		{
			CreateFactory();
			GetAdapters();
		}
	}

	void GraphicDeviceManager::CreateFactory()
	{
		HRESULT hr;

		IDXGIFactory1*  pFactory = NULL;
		hr = CreateDXGIFactory1(__uuidof(IDXGIFactory1), (void**)&pFactory);
		DXException::Check(hr, L"Create DXGI Factory");

		DXGIFactory << pFactory;
	}

	void GraphicDeviceManager::GetAdapters()
	{
		HRESULT hr;
		IDXGIAdapter1* pAdapter; 

		int i = 0;
		while(DXGIFactory->EnumAdapters1(i, &pAdapter) != DXGI_ERROR_NOT_FOUND) 
		{ 
			DXGI_ADAPTER_DESC1 desc;

			hr = pAdapter->GetDesc1(&desc);
			DXException::Check(hr, L"Get Adapter Description");

			AdapterList.push_back(pAdapter); 
			AdapterNames.push_back(desc.Description);

			SafeRelease(pAdapter);

			++i; 
		} 
	}

	int GraphicDeviceManager::GetAdapterCount()
	{
		return AdapterList.size();
	}

	IDXGIAdapter1Ptr GraphicDeviceManager::GetAdapter(int index)
	{
		IDXGIAdapter1Ptr Result;

		Init();

		if(index < AdapterList.size())
		{
			Result = AdapterList[index];
		}

		return Result;
	}

	IDXGISwapChainPtr GraphicDeviceManager::CreateSwapChain(ID3D11DevicePtr device, DXGI_SWAP_CHAIN_DESC desc, HWND hwnd)
	{
		HRESULT hr;
		IDXGISwapChainPtr Result;

		Init();	

		IDXGISwapChain* pSwapChain;
		hr = DXGIFactory->CreateSwapChain(&device, &desc, &pSwapChain);
		DXException::Check(hr, L"CreateSwapChain");

		Result << pSwapChain;

		//禁止DXGI监视消息队列，捕捉ALT+ENTER，在全屏和窗口模式之间切换
		DXGIFactory->MakeWindowAssociation(hwnd, DXGI_MWA_NO_WINDOW_CHANGES|DXGI_MWA_NO_ALT_ENTER);

		return Result;
	}

	wstring GraphicDeviceManager::GetName(int index)
	{
		wstring Result;

		Init();

		if(index < AdapterList.size())
		{
			Result = AdapterNames[index];
		}

		return Result;
	}
}

namespace GLEO
{
	void GraphicBaseDevice::CreateDevice(int index)
	{
		HRESULT hr;

		IDXGIAdapter1Ptr adapt;

		if(index >= 0)
		{
			adapt = GraphicDeviceManager::GetAdapter(index);
		}


		ID3D11Device* pDevice = NULL;
		ID3D11DeviceContext* pContext = NULL;

		UINT CreationFlags = 0;
		//CreationFlags |= D3D11_CREATE_DEVICE_SINGLETHREADED;

#if defined(DEBUG) || defined(_DEBUG)
		CreationFlags |= D3D11_CREATE_DEVICE_DEBUG;
#endif

		bool bNeedRefDevice = FALSE;
		hr = D3D11CreateDevice(&adapt, D3D_DRIVER_TYPE_UNKNOWN, NULL, CreationFlags, FeatureLevelList, sizeof(FeatureLevelList) / sizeof(D3D_FEATURE_LEVEL), D3D11_SDK_VERSION, &pDevice, &this->FeatureLevels, &pContext);       
		DXException::Check(hr, L"Create Device");

		this->Device = pDevice;
		this->Context = pContext;

		SafeRelease(pContext);
		SafeRelease(pDevice);
	}

	ID3DBlobPtr GraphicBaseDevice::ComplieShader(wstring file, string entry, ShaderType type)
	{
		HRESULT hr;

		ID3DBlobPtr Result;
		ID3DBlob* pErrorBlob = NULL;
		ID3DBlob* pBinary = NULL;

		DWORD dwShaderFlags = D3DCOMPILE_ENABLE_STRICTNESS;

		LPCSTR pProfile;
		
		switch(type)
		{
		case GLEO::GraphicBaseDevice::CS:
			pProfile = this->FeatureLevels >= D3D_FEATURE_LEVEL_11_0 ? "cs_5_0" : "cs_4_0";
			break;
		case GLEO::GraphicBaseDevice::VS:
			pProfile = this->FeatureLevels >= D3D_FEATURE_LEVEL_11_0 ? "vs_5_0" : "vs_4_0";
			break;
		case GLEO::GraphicBaseDevice::PS:
			pProfile = this->FeatureLevels >= D3D_FEATURE_LEVEL_11_0 ? "ps_5_0" : "ps_4_0";
			break;
		default:
			pProfile = this->FeatureLevels >= D3D_FEATURE_LEVEL_11_0 ? "cs_5_0" : "cs_4_0";
			break;
		}
		
		D3D10_SHADER_MACRO* Macros = NULL;

		try
		{
			hr = D3DX11CompileFromFile(file.c_str(), Macros, NULL, entry.c_str(), pProfile, dwShaderFlags, NULL, NULL, &pBinary, &pErrorBlob, NULL );
			if(FAILED(hr))
			{
				char buf[1024];

				if(pErrorBlob)
				{
					throw ShaderCompileExcepton(hr, pErrorBlob);
				}
				else
				{
					DXException::Check(hr, "Compile Shader");
				}
			}

			Result = pBinary;
				
			DESTROY(Macros);
			SafeRelease(pErrorBlob);
			SafeRelease(pBinary);   
		}
		catch(...)
		{
			DESTROY(Macros);
			SafeRelease(pErrorBlob);
			SafeRelease(pBinary);

			throw;
		}

		return Result;
	}

	ID3D11BufferPtr GraphicBaseDevice::CreateBuffer(D3D11_BUFFER_DESC& desc, void* data)
	{
		ID3D11BufferPtr Result;
		
		HRESULT hr;
		ID3D11Buffer* pBuffer;
		if(data)
		{
			D3D11_SUBRESOURCE_DATA InitData;
			InitData.pSysMem = data;
			InitData.SysMemPitch = 0;
			InitData.SysMemSlicePitch = 0;

			hr = this->Device->CreateBuffer(&desc, &InitData, &pBuffer);
			DXException::Check(hr, L"Create Const Buffer");
		}
		else
		{
			hr = this->Device->CreateBuffer(&desc, NULL, &pBuffer);
			DXException::Check(hr, L"Create Const Buffer");
		}

		Result << pBuffer;

		return Result;
	}


	ID3D11BufferPtr GraphicBaseDevice::CreateConstBuffer(void* data, int size)
	{

		D3D11_BUFFER_DESC BufferDesc;

		BufferDesc.BindFlags = D3D11_BIND_CONSTANT_BUFFER;
		BufferDesc.Usage = D3D11_USAGE_DYNAMIC;
		BufferDesc.CPUAccessFlags = D3D11_CPU_ACCESS_WRITE;
		BufferDesc.ByteWidth = size;
		BufferDesc.MiscFlags = 0;
		BufferDesc.StructureByteStride = 0;

		// 创建const buffer指针，以便访问shader常量.


		return this->CreateBuffer(BufferDesc, data);
	}

	void GraphicBaseDevice::UpdateConstBuffer(ID3D11BufferPtr buffer, void* data, int len)
	{
		D3D11_MAPPED_SUBRESOURCE mappedResource;
		ID3D11Buffer* pBuffer = &buffer;

		HRESULT hr = this->Context->Map(pBuffer, 0, D3D11_MAP_WRITE_DISCARD, 0, &mappedResource);
		DXException::Check(hr, L"Map Const Buffer");

		memcpy(mappedResource.pData, data, len);

		// 解锁常量缓冲.
		this->Context->Unmap(pBuffer, 0);
	}

}