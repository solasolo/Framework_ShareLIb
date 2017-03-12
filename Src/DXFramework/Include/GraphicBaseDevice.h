#pragma once

#include <d3d11.h>
#include <d3dcommon.h>
#include <d3dcompiler.h>

#include "SmartPointer.h"
#include "DXException.h"

using namespace std;

namespace GLEO
{
	COMPtr(ID3D11Device);
	COMPtr(ID3D11DeviceContext);
	COMPtr(IDXGIAdapter1);
	COMPtr(IDXGIAdapter);
	COMPtr(IDXGIFactory1);
	COMPtr(IDXGIFactory);
	COMPtr(IDXGISwapChain);
	COMPtr(ID3DBlob);
	COMPtr(ID3D11Buffer);

	class __declspec(dllexport) ShaderCompileExcepton : public DXException
	{
	private:
		string ComplieError;

	public:
		ShaderCompileExcepton(int code, ID3DBlob* error);

	protected:
		virtual wstring GetErrorDescription();
	};

	class __declspec(dllexport) GraphicDeviceManager
	{
	private:
		static vector<IDXGIAdapter1Ptr> AdapterList; 
		static vector<wstring> AdapterNames;
		static IDXGIFactory1Ptr DXGIFactory;

		static void CreateFactory();
		static void GetAdapters();

		static void Init();

	public:
		GraphicDeviceManager();

		static int GetAdapterCount();
		static IDXGIAdapter1Ptr GetAdapter(int index);
		static IDXGISwapChainPtr CreateSwapChain(ID3D11DevicePtr device, DXGI_SWAP_CHAIN_DESC desc, HWND hwnd);

		static wstring GetName(int index);
	};

	class __declspec(dllexport) GraphicBaseDevice
	{
	protected:
		enum ShaderType
		{
			CS,
			VS,
			PS
		};

		D3D_FEATURE_LEVEL FeatureLevels;

		ID3D11DevicePtr Device;
		ID3D11DeviceContextPtr Context;

		void CreateDevice(int index);
		ID3DBlobPtr ComplieShader(wstring file, string entry, ShaderType type);
		ID3D11BufferPtr CreateBuffer(D3D11_BUFFER_DESC& desc, void* data);

	public:
		ID3D11BufferPtr CreateConstBuffer(void* data, int size);
		void UpdateConstBuffer(ID3D11BufferPtr buffer, void* data, int len);
	};
}