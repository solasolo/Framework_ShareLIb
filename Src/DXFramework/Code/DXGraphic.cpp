#include "stdafx.h"

#include "DXGraphic.h"
#include "DXException.h"

#include <dxgitype.h>

namespace GLEO
{
	GraphicsDevice::SemanticDesc SemanticList[] = { 
		{"BINORMAL", DXGI_FORMAT_R32G32B32_FLOAT, 12},
		{"BLENDINDICES", DXGI_FORMAT_R8_UINT, 1},
		{"BLENDWEIGHT", DXGI_FORMAT_R32_FLOAT, 4},
		{"COLOR", DXGI_FORMAT_R32G32B32_FLOAT, 12},
		{"NORMAL", DXGI_FORMAT_R32G32B32_FLOAT, 12},
		{"POSITION", DXGI_FORMAT_R32G32B32_FLOAT, 12},
		{"POSITIONT", DXGI_FORMAT_R32G32B32_FLOAT, 12},
		{"PSIZE", DXGI_FORMAT_R32_FLOAT, 4},
		{"TANGENT", DXGI_FORMAT_R32G32B32_FLOAT, 12},
		{"TEXCOORD", DXGI_FORMAT_R32G32_FLOAT, 8}
	};

	GraphicsDevice::GraphicsDevice()
	{
		// ��������󻺳���ɫ.
		this->BackgroundColor[0] = 0.0f;//red;
		this->BackgroundColor[1] = 0.0f;//green;
		this->BackgroundColor[2] = 0.8f;//blue;
		this->BackgroundColor[3] = 1.0f;//alpha;

		//�������������
		Camera = new AircraftCamera();
	}

	GraphicsDevice::~GraphicsDevice()
	{
		DESTROY(Camera);
	}

	void GraphicsDevice::Initialize(int screenWidth, int screenHeight, HWND _hwnd, bool vsync, bool full_screen, float screenDepth, float screenNear)
	{
		HRESULT hr;
		unsigned int numModes, i, numerator=0, denominator=1, stringLength;
		DXGI_MODE_DESC* displayModeList;

		ScreenWidth = screenWidth;
		ScreenHeight = screenHeight;
		ScreenDepth = screenDepth;
		ScreenNear = screenNear;

		VsyncEnabled = vsync;
		IsFullScreen = full_screen;
		hwnd = _hwnd;


		// �õ���������.
		this->Adapter = GraphicDeviceManager::GetAdapter(0);

		// �õ��������������.
		IDXGIOutput* pOutput;
		hr = this->Adapter->EnumOutputs(0, &pOutput);
		DXException::Check(hr, L"EnumOutputs");

		this->Output << pOutput;

		// �õ��Կ�����
		DXGI_ADAPTER_DESC adapterDesc;
		hr = this->Adapter->GetDesc(&adapterDesc);
		DXException::Check(hr, L"GetAdapterDesc");

		this->CreateDevice(0); // Main Device
		this->GetRefreshRate(); 
		this->CreateSwapChain();
		this->CreateTargetView();
		this->CreateDepthStencilView();
		this->CreateRasterizer();
		this->SetViewPort();

		this->Camera->SetScreen(screenWidth, screenHeight);

		this->CreateBlendState();
	}

	void GraphicsDevice::SetBackgroundColor(float color[4])
	{
		this->BackgroundColor[0] = color[0];
		this->BackgroundColor[1] = color[1];
		this->BackgroundColor[2] = color[2];
		this->BackgroundColor[3] = color[3];
	}

	void GraphicsDevice::GetRefreshRate()
	{
		HRESULT hr;

		//�õ��ʺ� DXGI_FORMAT_R8G8B8A8_UNORM ����ʾģʽ.
		hr = this->Output->GetDisplayModeList(DXGI_FORMAT_R8G8B8A8_UNORM, DXGI_ENUM_MODES_INTERLACED, &numModes, NULL);
		DXException::Check(hr, L"GetDisplayModeList");

		DXGI_MODE_DESC* displayModeList = new DXGI_MODE_DESC[numModes];	//��ʾģʽ�б�

		// ������ʾģʽ��displayModeList��
		hr = this->Output->GetDisplayModeList(DXGI_FORMAT_R8G8B8A8_UNORM, DXGI_ENUM_MODES_INTERLACED, &numModes, displayModeList);
		DXException::Check(hr, L"GetDisplayModeList");


		//����������ʾģʽ���õ�ˢ������������ֵnumerator �� denominato
		for(int i=0; i<numModes; i++)
		{
			if(displayModeList[i].Width == (unsigned int)ScreenWidth)
			{
				if(displayModeList[i].Height == (unsigned int)ScreenHeight)
				{
					numerator = displayModeList[i].RefreshRate.Numerator;
					denominator = displayModeList[i].RefreshRate.Denominator;
				}
			}
		}

		DESTROY(displayModeList);

		// �õ��Կ�����
		DXGI_ADAPTER_DESC adapterDesc;
		hr = this->Adapter->GetDesc(&adapterDesc);
		DXException::Check(hr, L"Get adapterDesc");

		// �����Դ��С.
		VideoCardMemory = (int)(adapterDesc.DedicatedVideoMemory / 1024 / 1024);
	}

	void GraphicsDevice::CreateSwapChain()
	{
		HRESULT hr;
		//�����Ļ�߶Ȼ��߿��Ϊ0����ᴴ����Ȼ���ʧ�ܣ���������С��ʱ�򣬻���ִ���Ϊ0�������
		if(ScreenWidth < 1)
			ScreenWidth = 1;
		if(ScreenHeight <1)
			ScreenHeight = 1;

		// ��ʼ������������
		DXGI_SWAP_CHAIN_DESC swapChainDesc;
		ZeroMemory(&swapChainDesc, sizeof(swapChainDesc));

		// ��1���󻺳�
		swapChainDesc.BufferCount = 1;

		//֡����Ĵ�С��Ӧ�ó��򴰿ڴ�С���.
		swapChainDesc.BufferDesc.Width = this->ScreenWidth;
		swapChainDesc.BufferDesc.Height = ScreenHeight;

		// �󻺳��surface�ĸ�ʽΪDXGI_FORMAT_R8G8B8A8_UNORM.
		// surface��ÿ��������4���޷��ŵ�8bit[ӳ�䵽0-1]����ʾ��NORM��ʾ��һ����
		swapChainDesc.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;

		// ���ʹ�ô�ֱͬ�������ú󻺳��ˢ���ʡ�.
		//ˢ���ʾ���һ���ӰѺ󻺳���������Ļ�ϻ����Ĵ�����
		//���������ֱͬ����������ˢ���ʣ���fps�ǹ̶���
		if(VsyncEnabled)
		{
			swapChainDesc.BufferDesc.RefreshRate.Numerator = 0;//numerator;
			swapChainDesc.BufferDesc.RefreshRate.Denominator = 0;//denominator;
		}
		else
		{
			swapChainDesc.BufferDesc.RefreshRate.Numerator = 0;
			swapChainDesc.BufferDesc.RefreshRate.Denominator = 1;
		}

		// ���ú󻺳����;
		// ���ǵ���ȾĿ�껺��Ϊ�󻺳塣
		swapChainDesc.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;

		// �󻺳�����Ĵ��ھ��.
		swapChainDesc.OutputWindow = hwnd;

		// ��ʹ�ö��ز���
		swapChainDesc.SampleDesc.Count = 1;
		swapChainDesc.SampleDesc.Quality = 0;

		// ����ȫ�����ߴ���ģʽ.
		if(IsFullScreen)
		{
			swapChainDesc.Windowed = false;
		}
		else
		{
			swapChainDesc.Windowed = true;
		}

		// �趨ɨ����ordering�Լ�����Ϊunspecified.
		swapChainDesc.BufferDesc.ScanlineOrdering = DXGI_MODE_SCANLINE_ORDER_UNSPECIFIED;
		swapChainDesc.BufferDesc.Scaling = DXGI_MODE_SCALING_UNSPECIFIED;

		// �󻺳����ݳ��ֵ���Ļ�󣬷���������
		swapChainDesc.SwapEffect = DXGI_SWAP_EFFECT_DISCARD;

		//�����ñ�־
		swapChainDesc.Flags = DXGI_SWAP_CHAIN_FLAG_ALLOW_MODE_SWITCH ;

		//����������
		this->SwapChain = GraphicDeviceManager::CreateSwapChain(this->Device, swapChainDesc, hwnd);
	}

	void GraphicsDevice::CreateTargetView()
	{
		HRESULT hr;

		ID3D11RenderTargetView* pView; //��ȾĿ����ͼ
		ID3D11Texture2D* backBufferPtr;

		// �õ��������еĺ󻺳�ָ��.
		hr = SwapChain->GetBuffer(0, __uuidof(ID3D11Texture2D), (LPVOID*)&backBufferPtr);
		DXException::Check(hr, L"GetBuffer BackBuffer");

		// �ú󻺳崴����ȾĿ����ͼ.
		hr = Device->CreateRenderTargetView(backBufferPtr, NULL, &pView);
		DXException::Check(hr, L"CreateRenderTargetView");

		this->RenderTargetView = pView;

		SafeRelease(pView);

		SafeRelease(backBufferPtr);
	}

	void GraphicsDevice::CreateDepthStencilView()
	{
		HRESULT hr;
		D3D11_TEXTURE2D_DESC depthBufferDesc;
		D3D11_DEPTH_STENCIL_DESC depthStencilDesc;
		D3D11_DEPTH_STENCIL_VIEW_DESC depthStencilViewDesc;

		float fieldOfView, screenAspect;

		// �������ģ����ͼ
		// ��ʼ����Ȼ�������.
		ZeroMemory(&depthBufferDesc, sizeof(depthBufferDesc));

		//������Ȼ�������
		depthBufferDesc.Width = ScreenWidth;
		depthBufferDesc.Height = ScreenHeight;
		depthBufferDesc.MipLevels = 1;//������Ȼ���Ϊ1
		depthBufferDesc.ArraySize = 1;//������Ȼ���Ϊ1������������2�������и�����;
		depthBufferDesc.Format = DXGI_FORMAT_D24_UNORM_S8_UINT;
		depthBufferDesc.SampleDesc.Count = 1;
		depthBufferDesc.SampleDesc.Quality = 0;
		depthBufferDesc.Usage = D3D11_USAGE_DEFAULT;
		depthBufferDesc.BindFlags = D3D11_BIND_DEPTH_STENCIL;
		depthBufferDesc.CPUAccessFlags = 0;
		depthBufferDesc.MiscFlags = 0;

		// ������Ȼ���
		ID3D11Texture2D* depthStencilBuffer = NULL;
		hr = Device->CreateTexture2D(&depthBufferDesc, NULL, &depthStencilBuffer);
		DXException::Check(hr, L"CreateTexture2D");

		this->DepthStencilBuffer = depthStencilBuffer;
		SafeRelease(depthStencilBuffer);

		// ��ʼ�����ģ��״̬����.
		ZeroMemory(&depthStencilDesc, sizeof(depthStencilDesc));

		// �������ģ��״̬����.
		depthStencilDesc.DepthEnable = true;
		depthStencilDesc.DepthWriteMask = D3D11_DEPTH_WRITE_MASK_ALL;//D3D11_DEPTH_WRITE_MASK_ZERO��ֹд��Ȼ���
		depthStencilDesc.DepthFunc = D3D11_COMPARISON_LESS;

		depthStencilDesc.StencilEnable = true;
		depthStencilDesc.StencilReadMask = 0xFF;
		depthStencilDesc.StencilWriteMask = 0xFF;

		// ����front face ����ʹ�õ�ģ���������.
		depthStencilDesc.FrontFace.StencilFailOp = D3D11_STENCIL_OP_KEEP;
		depthStencilDesc.FrontFace.StencilDepthFailOp = D3D11_STENCIL_OP_INCR;
		depthStencilDesc.FrontFace.StencilPassOp = D3D11_STENCIL_OP_KEEP;
		depthStencilDesc.FrontFace.StencilFunc = D3D11_COMPARISON_ALWAYS;

		// ����back face����ʹ�õ�ģ�����ģʽ.
		depthStencilDesc.BackFace.StencilFailOp = D3D11_STENCIL_OP_KEEP;
		depthStencilDesc.BackFace.StencilDepthFailOp = D3D11_STENCIL_OP_DECR;
		depthStencilDesc.BackFace.StencilPassOp = D3D11_STENCIL_OP_KEEP;
		depthStencilDesc.BackFace.StencilFunc = D3D11_COMPARISON_ALWAYS;

		// �������ģ��״̬��ʹ����Ч
		ID3D11DepthStencilState* depthStencilState = NULL;
		hr = Device->CreateDepthStencilState(&depthStencilDesc, &depthStencilState);
		DXException::Check(hr, L"CreateDepthStencilState");

		this->DepthStencilState = depthStencilState;
		SafeRelease(depthStencilState);

		// �������ģ��״̬.
		//Context->OMSetDepthStencilState(DepthStencilState, 1);
		Context->OMSetDepthStencilState(0, 0);


		// ��ʼ�����ģ����ͼ.
		ZeroMemory(&depthStencilViewDesc, sizeof(depthStencilViewDesc));

		// �������ģ����ͼ����.
		depthStencilViewDesc.Format = DXGI_FORMAT_D24_UNORM_S8_UINT;
		depthStencilViewDesc.ViewDimension = D3D11_DSV_DIMENSION_TEXTURE2D;
		depthStencilViewDesc.Texture2D.MipSlice = 0;

		// �������ģ����ͼ
		ID3D11DepthStencilView* depthStencilView = NULL;
		hr = Device->CreateDepthStencilView(&DepthStencilBuffer, &depthStencilViewDesc, &depthStencilView);
		DXException::Check(hr, L"CreateDepthStencilView");

		this->DepthStencilView = depthStencilView;
		SafeRelease(depthStencilView);

		// ����ȾĿ����ͼ����Ȼ��嵽��Ⱦ����.
		ID3D11RenderTargetView* view = &RenderTargetView;
		Context->OMSetRenderTargets(1,  &view, &DepthStencilView);
	}

	void GraphicsDevice::CreateRasterizer()
	{
		// ���ù�դ��������ָ���������α���Ⱦ
		HRESULT hr;
		D3D11_RASTERIZER_DESC rasterDesc;
		rasterDesc.AntialiasedLineEnable = false;
		rasterDesc.CullMode = D3D11_CULL_BACK;
		rasterDesc.DepthBias = 0;
		rasterDesc.DepthBiasClamp = 0.0f;
		rasterDesc.DepthClipEnable = true;
		rasterDesc.FillMode = D3D11_FILL_SOLID; //D3D11_FILL_SOLID
		rasterDesc.FrontCounterClockwise = false;
		rasterDesc.MultisampleEnable = false;
		rasterDesc.ScissorEnable = false;
		rasterDesc.SlopeScaledDepthBias = 0.0f;

		// ������դ��״̬
		ID3D11RasterizerState* rasterState;
		hr = Device->CreateRasterizerState(&rasterDesc, &rasterState);
		DXException::Check(hr, L"CreateRasterizerState");

		this->RasterState = rasterState;
		SafeRelease(rasterState);

		//���ù�դ��״̬��ʹ����Ч
		Context->RSSetState(&RasterState);
	}

	void GraphicsDevice::SetViewPort()
	{
		// �����ӿڣ���ʾȫ���󻺳�����
		D3D11_VIEWPORT viewport;
		viewport.Width = ScreenWidth;
		viewport.Height = ScreenHeight;
		viewport.MinDepth = 0.0f;
		viewport.MaxDepth = 1.0f;
		viewport.TopLeftX = 0.0f;
		viewport.TopLeftY = 0.0f;

		// �����ӿ�
		Context->RSSetViewports(1, &viewport);
	}

	void GraphicsDevice::CreateBlendState()
	{
		// ��ʼ��blend������
		HRESULT hr;
		D3D11_BLEND_DESC blendStateDescription;
		ZeroMemory(&blendStateDescription, sizeof(D3D11_BLEND_DESC));

		// ����һ��alpha blend״̬.
		blendStateDescription.RenderTarget[0].BlendEnable = TRUE;
		//blendStateDescription.RenderTarget[0].SrcBlend = D3D11_BLEND_ONE;
		blendStateDescription.RenderTarget[0].SrcBlend = D3D11_BLEND_SRC_ALPHA;//D3D11_BLEND_BLEND_FACTOR;
		blendStateDescription.RenderTarget[0].DestBlend = D3D11_BLEND_INV_SRC_ALPHA;//D3D11_BLEND_INV_BLEND_FACTOR;
		blendStateDescription.RenderTarget[0].BlendOp = D3D11_BLEND_OP_ADD;
		blendStateDescription.RenderTarget[0].SrcBlendAlpha = D3D11_BLEND_ONE;
		blendStateDescription.RenderTarget[0].DestBlendAlpha = D3D11_BLEND_ZERO;
		blendStateDescription.RenderTarget[0].BlendOpAlpha = D3D11_BLEND_OP_ADD;
		blendStateDescription.RenderTarget[0].RenderTargetWriteMask = D3D11_COLOR_WRITE_ENABLE_ALL;//0x0f;

		ID3D11BlendState* alphaEnableBlendingState;
		ID3D11BlendState* alphaDisableBlendingState;

		// ������������һ��alpha blend״̬
		hr = Device->CreateBlendState(&blendStateDescription, &alphaEnableBlendingState);
		DXException::Check(hr, L"CreateBlendState Enable");

		this->AlphaEnableBlendingState = alphaEnableBlendingState;
		SafeRelease(alphaEnableBlendingState);

		//�޸�������.
		blendStateDescription.RenderTarget[0].BlendEnable = FALSE;

		//����һ���µ�blend״̬.
		hr = Device->CreateBlendState(&blendStateDescription, &alphaDisableBlendingState);
		DXException::Check(hr, L"CreateBlendState Disable");

		this->AlphaDisableBlendingState = alphaDisableBlendingState;
		SafeRelease(alphaDisableBlendingState);
	}

	void GraphicsDevice::BeginScene()
	{
		//����󻺳�
		Context->ClearRenderTargetView(&RenderTargetView, this->BackgroundColor);

		//�����Ȼ���
		Context->ClearDepthStencilView(&DepthStencilView, D3D11_CLEAR_DEPTH|D3D11_CLEAR_STENCIL, 1.0f, 0);
	}

	void GraphicsDevice::EndScene()
	{
		HRESULT hr;
		//��Ⱦ��ɺ󣬰Ѻ󻺳�����present��ǰ����
		if(VsyncEnabled)
		{
			// ������Ļˢ����.
			hr = SwapChain->Present(1, 0);
		}
		else
		{
			// �����ܿ��present�󻺳�.
			hr = SwapChain->Present(0, 0);
		}

		DXException::Check(hr, L"EndScene");
	}

	void GraphicsDevice::ShutDown()
	{

	}

	BaseCamera* GraphicsDevice::GetCamera()
	{
		return this->Camera;
	}

	void GraphicsDevice::SetCamera(BaseCamera* camera)
	{
		DESTROY(this->Camera);
		this->Camera = camera;
	}

	ID3D11DevicePtr GraphicsDevice::GetDevice()
	{
		return this->Device;
	}

	ID3D11DeviceContextPtr GraphicsDevice::GetContext()
	{
		return this->Context;
	}

	void GraphicsDevice::TurnOnAlphaBlending()
	{
		float blendFactor[4];

		// ����blend����
		blendFactor[0] = 0.0f;
		blendFactor[1] = 0.0f;
		blendFactor[2] = 0.0f;
		blendFactor[3] = 0.0f;
		// ��alpha blend
		Context->OMSetBlendState(&AlphaEnableBlendingState, blendFactor, 0xffffffff);
	}

	void GraphicsDevice::TurnOffAlphaBlending()
	{
		float blendFactor[4];

		// ����blend����
		blendFactor[0] = 0.0f;
		blendFactor[1] = 0.0f;
		blendFactor[2] = 0.0f;
		blendFactor[3] = 0.0f;

		// �ر�alpha blend
		Context->OMSetBlendState(&AlphaDisableBlendingState, blendFactor, 0xffffffff);
	}

	D3D11_INPUT_ELEMENT_DESC* GraphicsDevice::BuildLayout(SemanticType laylist[], int count)
	{
		D3D11_INPUT_ELEMENT_DESC* Result = new D3D11_INPUT_ELEMENT_DESC[count];

		int pos = 0;
		for(int i = 0; i < count; i++)
		{
			SemanticDesc sd = SemanticList[laylist[i]];
			D3D11_INPUT_ELEMENT_DESC& item = Result[i];

			item.SemanticName = sd.Name; 
			item.SemanticIndex = 0;
			item.Format = sd.Format;
			item.InputSlot = 0;
			item.AlignedByteOffset = pos;
			item.InputSlotClass = D3D11_INPUT_PER_VERTEX_DATA;
			item.InstanceDataStepRate = 0;

			pos += sd.Size;
		}

		return Result;
	}

	ID3D11ShaderResourceViewPtr GraphicsDevice::CreateTexture(wstring filename)
	{
		HRESULT hr;
		ID3D11ShaderResourceViewPtr Result;

		D3DX11_IMAGE_LOAD_INFO loadInfo;
		ZeroMemory( &loadInfo, sizeof(D3DX11_IMAGE_LOAD_INFO) );
		loadInfo.BindFlags = D3D11_BIND_SHADER_RESOURCE;
		loadInfo.Format = DXGI_FORMAT_BC3_UNORM;
		loadInfo.MipLevels = D3DX11_DEFAULT; //��ʱ���������mipmaps��
		loadInfo.MipFilter = D3DX11_FILTER_LINEAR;

		ID3D11ShaderResourceView* pResourceView = 0;
		hr = D3DX11CreateShaderResourceViewFromFile(&Device, filename.c_str(), &loadInfo, NULL, &pResourceView, NULL);
		DXException::Check(hr, L"Create Texture");

		Result << pResourceView;

		return Result;
	}

	ID3D11BufferPtr GraphicsDevice::CreateVertexBuffer(void* data, int count, int width)
	{
		D3D11_BUFFER_DESC vertexBufferDesc;
		// ���ö��㻺������
		vertexBufferDesc.Usage = D3D11_USAGE_DEFAULT;
		vertexBufferDesc.ByteWidth = width * count;
		vertexBufferDesc.BindFlags = D3D11_BIND_VERTEX_BUFFER;
		vertexBufferDesc.CPUAccessFlags = 0;
		vertexBufferDesc.MiscFlags = 0;
		vertexBufferDesc.StructureByteStride = 0;

		return this->CreateBuffer(vertexBufferDesc, data);
	}

	ID3D11BufferPtr  GraphicsDevice::CreateIndexBuffer(void* data, int count)
	{
		D3D11_BUFFER_DESC indexBufferDesc;
		// ����������������.
		indexBufferDesc.Usage = D3D11_USAGE_DEFAULT;
		indexBufferDesc.ByteWidth = sizeof(unsigned long) * count;
		indexBufferDesc.BindFlags = D3D11_BIND_INDEX_BUFFER;
		indexBufferDesc.CPUAccessFlags = 0;
		indexBufferDesc.MiscFlags = 0;
		indexBufferDesc.StructureByteStride = 0;

		return this->CreateBuffer(indexBufferDesc, data);
	}

	ID3D11VertexShaderPtr GraphicsDevice::CreateVertexShader(wstring file, SemanticType laylist[], int count, ID3D11InputLayoutPtr& layout, string entry)
	{
		HRESULT hr;
		ID3D11VertexShaderPtr Result;

		ID3DBlobPtr ShaderBinary = this->ComplieShader(file, entry.c_str(), ShaderType::VS);

		ID3D11VertexShader* pVertexShader = NULL;
		hr = this->Device->CreateVertexShader(ShaderBinary->GetBufferPointer(), ShaderBinary->GetBufferSize(), NULL, &pVertexShader);
		DXException::Check(hr, L"Create Vertex Shader");

		Result << pVertexShader;


		D3D11_INPUT_ELEMENT_DESC* InputDesc = this->BuildLayout(laylist, count);

		ID3D11InputLayout* pLayout = NULL;
		hr = this->Device->CreateInputLayout(InputDesc, count, ShaderBinary->GetBufferPointer(), ShaderBinary->GetBufferSize(), &pLayout);
		DXException::Check(hr, L"Create Input Layout");

		DESTROY(InputDesc);

		layout = pLayout;

		return Result;
	}
	
	ID3D11PixelShaderPtr GraphicsDevice::CreatePixelShader(wstring file, string entry)
	{
		HRESULT hr;
		ID3D11PixelShaderPtr Result;

		ID3DBlobPtr ShaderBinary = this->ComplieShader(file, entry.c_str(), ShaderType::PS);

		ID3D11PixelShader* pPixelShader = NULL;
		hr = this->Device->CreatePixelShader(ShaderBinary->GetBufferPointer(), ShaderBinary->GetBufferSize(), NULL, &pPixelShader);
		DXException::Check(hr, L"CreatePixelShader");

		Result << pPixelShader;

		return Result;
	}

	ID3D11SamplerStatePtr GraphicsDevice::CreateSamplerState()
	{
		ID3D11SamplerStatePtr Result;
		D3D11_SAMPLER_DESC samplerDesc;

		// �����������������
		samplerDesc.Filter = D3D11_FILTER_MIN_MAG_MIP_POINT;
		samplerDesc.AddressU = D3D11_TEXTURE_ADDRESS_WRAP;
		samplerDesc.AddressV = D3D11_TEXTURE_ADDRESS_WRAP;
		samplerDesc.AddressW = D3D11_TEXTURE_ADDRESS_WRAP;
		samplerDesc.MipLODBias = 0.0f;
		samplerDesc.MaxAnisotropy = 1;
		samplerDesc.ComparisonFunc = D3D11_COMPARISON_ALWAYS;
		samplerDesc.BorderColor[0] = 1.0;
		samplerDesc.BorderColor[1] = 0;
		samplerDesc.BorderColor[2] = 0;
		samplerDesc.BorderColor[3] = 1.0;
		samplerDesc.MinLOD = 0;
		samplerDesc.MaxLOD = D3D11_FLOAT32_MAX;

		// �����������״̬
		ID3D11SamplerState* pSampleState;

		HRESULT hr = this->Device->CreateSamplerState(&samplerDesc, &pSampleState);
		DXException::Check(hr, L"Create Sampler State");

		Result << pSampleState;

		return Result;
	}

	void GraphicsDevice::Resize(int screenWidth, int screenHeight)
	{
		HRESULT hr;

		//������С��ʱ��Ϊ0���ᴴ������ʧ��
		if(screenHeight < 1)
			screenHeight = 1;
		if(screenWidth < 1)
			screenWidth = 1;

		this->ScreenWidth = screenWidth;
		this->ScreenHeight = screenHeight;

		//�ı佻�����к�󻺳��С�����´�����ȾĿ����ͼ
		hr = SwapChain->ResizeBuffers(1, screenWidth, screenHeight, DXGI_FORMAT_R8G8B8A8_UNORM, 0);

		// �õ��������еĺ󻺳�ָ��
		ID3D11RenderTargetView* pRenderTargetView; //��ȾĿ����ͼ
		ID3D11Texture2D* pBackBuffer;

		hr = SwapChain->GetBuffer(0, __uuidof(ID3D11Texture2D), (LPVOID*)&pBackBuffer);

		// �ú󻺳崴����ȾĿ����ͼ.
		hr = Device->CreateRenderTargetView(pBackBuffer, NULL, &pRenderTargetView);
		DXException::Check(hr, L"CreateRenderTargetView");

		this->RenderTargetView << pRenderTargetView;

		SafeRelease(pBackBuffer);

		this->CreateDepthStencilView();
		this->CreateRasterizer();
		this->SetViewPort();
		
		this->Camera->SetScreen(screenWidth, screenHeight);
	}
}

namespace GLEO
{
	BasicPipelineResource::BasicPipelineResource(GraphicsDevice* device)
	{
		this->Device = device;
	}

	void BasicPipelineResource::CreateVertexBuffer(void* vertices, int count, unsigned int width)
	{
		this->VertexCount = count;
		this->VertexWidth = width; // = sizeof(VertexType);
		this->VertexOffset = 0;

		this->VertexBuffer = this->Device->CreateVertexBuffer(vertices, count, width);
	}

	void BasicPipelineResource::CreateIndexBuffer(unsigned long* indices, int count)
	{
		this->IndexCount = count;

		this->IndexBuffer = this->Device->CreateIndexBuffer(indices, count);
	}

	ID3D11ShaderResourceViewPtr BasicPipelineResource::CreateTexture(wstring filename)
	{
		ID3D11ShaderResourceViewPtr Result;

		Result = this->Device->CreateTexture(filename);

		return Result;
	}

	void BasicPipelineResource::UpdateTexture(wstring path)
	{
		this->TextureView = this->CreateTexture(path);
	}

	ID3D11Buffer* BasicPipelineResource::GetVectexBuffer()
	{
		return &this->VertexBuffer;
	}

	ID3D11Buffer* BasicPipelineResource::GetIndexBuffer()
	{
		return &this->IndexBuffer;
	}

	ID3D11ShaderResourceView* BasicPipelineResource::GetTextureBuffer()
	{
		return &this->TextureView;
	}

	int BasicPipelineResource::GetIndexCount()
	{
		return this->IndexCount;
	}

	int BasicPipelineResource::GetVertexCount()
	{
		return this->VertexCount;
	}

	unsigned int BasicPipelineResource::GetVertexWidth()
	{
		return this->VertexWidth;
	}
		
	unsigned int BasicPipelineResource::GetVertexOffset()
	{
		return this->VertexOffset;
	}
}

namespace GLEO
{
	BasicPipeline::BasicPipeline(GraphicsDevice* _Device)
	{
		this->Device = _Device;

		this->Context = this->Device->GetContext();

		this->CreateMatrixBuffer();
		this->SampleState = this->Device->CreateSamplerState();
	}

	BasicPipeline::~BasicPipeline()
	{
	}

	void BasicPipeline::CreatePSShader(wstring file)
	{
		this->PixelShader = this->Device->CreatePixelShader(file);	
	}
	
	void BasicPipeline::CreateVSShader(wstring file, SemanticType laylist[], int count)
	{
		this->VertexShader = this->Device->CreateVertexShader(file, laylist, count, this->InputLayout);
	}

	void BasicPipeline::CreateMatrixBuffer()
	{
		this->MatrixBuffer = this->Device->CreateConstBuffer(NULL, sizeof(MatrixBufferType));
	}

	void BasicPipeline::LoadVertex(BasicPipelineResource* resource)
	{
		ID3D11Buffer* buff = resource->GetVectexBuffer();

		unsigned int offiset = resource->GetVertexOffset();
		unsigned int width = resource->GetVertexWidth();

		//��input assemberl�׶ΰ󶨶��㻺�壬�Ա��ܹ�����Ⱦ
		Context->IASetVertexBuffers(0, 1, &buff, &width, &offiset);

		//��input assemberl�׶ΰ��������壬�Ա��ܹ�����Ⱦ
		Context->IASetIndexBuffer(resource->GetIndexBuffer(), DXGI_FORMAT_R32_UINT, 0);

		// ������Ԫ���壬��Ⱦ�߶�
		//Context->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_LINELIST);

		// ������Ԫ���壬��Ⱦ�������б�.
		Context->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);
	}

	void BasicPipeline::LoadMatrix(D3DXMATRIX& worldMatrix)
	{
		HRESULT result;
		MatrixBufferType* dataPtr;
		unsigned int bufferNumber;

		D3D11_MAPPED_SUBRESOURCE mappedResource;
		MatrixBufferType Matrixes;

		BaseCamera* Camera = this->Device->GetCamera();

		Matrixes.View = Camera->GetViewMatrix();
		Matrixes.Projection = Camera->GetProjectionMatrix();

		// ����shaderǰ��ȷ������ת�ã�����D3D11��Ҫ��.
		D3DXMatrixTranspose(&worldMatrix, &worldMatrix);
		D3DXMatrixTranspose(&Matrixes.View, &Matrixes.View);
		D3DXMatrixTranspose(&Matrixes.Projection, &Matrixes.Projection);
		Matrixes.World = worldMatrix;

		this->Device->UpdateConstBuffer(this->MatrixBuffer, &Matrixes, sizeof(Matrixes));

		// �ø��º��ֵ���ó�������.
		ID3D11Buffer* temp = &MatrixBuffer;
		Context->VSSetConstantBuffers(0, 1, &temp);
	}

	void BasicPipeline::LoadTexture(BasicPipelineResource* resource)
	{
		ID3D11ShaderResourceView* view = resource->GetTextureBuffer();

		if(view)
		{
			// ����ps shader��Դ.
			Context->PSSetShaderResources(0, 1, &view);
		}
	}

	void BasicPipeline::Render(D3DXMATRIX worldMatrix, BasicPipelineResource* resource)
	{
		if(resource && InputLayout && VertexShader && PixelShader)
		{
			this->LoadVertex(resource);
			this->LoadMatrix(worldMatrix);
			this->LoadTexture(resource);

			// �󶨶��㲼��.
			Context->IASetInputLayout(&InputLayout);

			// ������Ⱦʹ��vs��ps.
			Context->VSSetShader(&VertexShader, NULL, 0);
			Context->PSSetShader(&PixelShader, NULL, 0);

			//���ò���״̬
			ID3D11SamplerState* temp = &SampleState;
			Context->PSSetSamplers(0, 1, &temp);

			// ��Ⱦ������
			Context->DrawIndexed(resource->GetIndexCount(), 0, 0);
		}
	}

	GraphicsDevice* BasicPipeline::GetDevice()
	{
		return this->Device;
	}
}