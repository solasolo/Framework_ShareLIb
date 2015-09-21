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
		// 设置清除后缓冲颜色.
		this->BackgroundColor[0] = 0.0f;//red;
		this->BackgroundColor[1] = 0.0f;//green;
		this->BackgroundColor[2] = 0.8f;//blue;
		this->BackgroundColor[3] = 1.0f;//alpha;

		//创建摄像机对象
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


		// 得到主适配器.
		this->Adapter = GraphicDeviceManager::GetAdapter(0);

		// 得到主适配器的输出.
		IDXGIOutput* pOutput;
		hr = this->Adapter->EnumOutputs(0, &pOutput);
		DXException::Check(hr, L"EnumOutputs");

		this->Output << pOutput;

		// 得到显卡描述
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

		//得到适合 DXGI_FORMAT_R8G8B8A8_UNORM 的显示模式.
		hr = this->Output->GetDisplayModeList(DXGI_FORMAT_R8G8B8A8_UNORM, DXGI_ENUM_MODES_INTERLACED, &numModes, NULL);
		DXException::Check(hr, L"GetDisplayModeList");

		DXGI_MODE_DESC* displayModeList = new DXGI_MODE_DESC[numModes];	//显示模式列表

		// 保存显示模式到displayModeList中
		hr = this->Output->GetDisplayModeList(DXGI_FORMAT_R8G8B8A8_UNORM, DXGI_ENUM_MODES_INTERLACED, &numModes, displayModeList);
		DXException::Check(hr, L"GetDisplayModeList");


		//遍历所有显示模式，得到刷新率两个参数值numerator 和 denominato
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

		// 得到显卡描述
		DXGI_ADAPTER_DESC adapterDesc;
		hr = this->Adapter->GetDesc(&adapterDesc);
		DXException::Check(hr, L"Get adapterDesc");

		// 保存显存大小.
		VideoCardMemory = (int)(adapterDesc.DedicatedVideoMemory / 1024 / 1024);
	}

	void GraphicsDevice::CreateSwapChain()
	{
		HRESULT hr;
		//如果屏幕高度或者宽度为0，则会创建深度缓冲失败，当窗口最小化时候，会出现窗口为0的情况。
		if(ScreenWidth < 1)
			ScreenWidth = 1;
		if(ScreenHeight <1)
			ScreenHeight = 1;

		// 初始化交换链描述
		DXGI_SWAP_CHAIN_DESC swapChainDesc;
		ZeroMemory(&swapChainDesc, sizeof(swapChainDesc));

		// 用1个后缓冲
		swapChainDesc.BufferCount = 1;

		//帧缓冲的大小和应用程序窗口大小相等.
		swapChainDesc.BufferDesc.Width = this->ScreenWidth;
		swapChainDesc.BufferDesc.Height = ScreenHeight;

		// 后缓冲的surface的格式为DXGI_FORMAT_R8G8B8A8_UNORM.
		// surface的每个像素用4个无符号的8bit[映射到0-1]来表示。NORM表示归一化。
		swapChainDesc.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;

		// 如果使用垂直同步，设置后缓冲的刷新率。.
		//刷新率就是一秒钟把后缓冲内容在屏幕上画出的次数。
		//如果开启垂直同步，则锁定刷新率，则fps是固定的
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

		// 设置后缓冲的用途
		// 我们的渲染目标缓冲为后缓冲。
		swapChainDesc.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;

		// 后缓冲输出的窗口句柄.
		swapChainDesc.OutputWindow = hwnd;

		// 不使用多重采样
		swapChainDesc.SampleDesc.Count = 1;
		swapChainDesc.SampleDesc.Quality = 0;

		// 设置全屏或者窗口模式.
		if(IsFullScreen)
		{
			swapChainDesc.Windowed = false;
		}
		else
		{
			swapChainDesc.Windowed = true;
		}

		// 设定扫描线ordering以及缩放为unspecified.
		swapChainDesc.BufferDesc.ScanlineOrdering = DXGI_MODE_SCANLINE_ORDER_UNSPECIFIED;
		swapChainDesc.BufferDesc.Scaling = DXGI_MODE_SCALING_UNSPECIFIED;

		// 后缓冲内容呈现到屏幕后，放弃其内容
		swapChainDesc.SwapEffect = DXGI_SWAP_EFFECT_DISCARD;

		//不设置标志
		swapChainDesc.Flags = DXGI_SWAP_CHAIN_FLAG_ALLOW_MODE_SWITCH ;

		//创建交换链
		this->SwapChain = GraphicDeviceManager::CreateSwapChain(this->Device, swapChainDesc, hwnd);
	}

	void GraphicsDevice::CreateTargetView()
	{
		HRESULT hr;

		ID3D11RenderTargetView* pView; //渲染目标视图
		ID3D11Texture2D* backBufferPtr;

		// 得到交换链中的后缓冲指针.
		hr = SwapChain->GetBuffer(0, __uuidof(ID3D11Texture2D), (LPVOID*)&backBufferPtr);
		DXException::Check(hr, L"GetBuffer BackBuffer");

		// 用后缓冲创建渲染目标视图.
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

		// 创建深度模版视图
		// 初始化深度缓冲描述.
		ZeroMemory(&depthBufferDesc, sizeof(depthBufferDesc));

		//设置深度缓冲描述
		depthBufferDesc.Width = ScreenWidth;
		depthBufferDesc.Height = ScreenHeight;
		depthBufferDesc.MipLevels = 1;//对于深度缓冲为1
		depthBufferDesc.ArraySize = 1;//对于深度缓冲为1，对于纹理，这2个参数有更多用途
		depthBufferDesc.Format = DXGI_FORMAT_D24_UNORM_S8_UINT;
		depthBufferDesc.SampleDesc.Count = 1;
		depthBufferDesc.SampleDesc.Quality = 0;
		depthBufferDesc.Usage = D3D11_USAGE_DEFAULT;
		depthBufferDesc.BindFlags = D3D11_BIND_DEPTH_STENCIL;
		depthBufferDesc.CPUAccessFlags = 0;
		depthBufferDesc.MiscFlags = 0;

		// 创建深度缓冲
		ID3D11Texture2D* depthStencilBuffer = NULL;
		hr = Device->CreateTexture2D(&depthBufferDesc, NULL, &depthStencilBuffer);
		DXException::Check(hr, L"CreateTexture2D");

		this->DepthStencilBuffer = depthStencilBuffer;
		SafeRelease(depthStencilBuffer);

		// 初始化深度模版状态描述.
		ZeroMemory(&depthStencilDesc, sizeof(depthStencilDesc));

		// 设置深度模版状态描述.
		depthStencilDesc.DepthEnable = true;
		depthStencilDesc.DepthWriteMask = D3D11_DEPTH_WRITE_MASK_ALL;//D3D11_DEPTH_WRITE_MASK_ZERO禁止写深度缓冲
		depthStencilDesc.DepthFunc = D3D11_COMPARISON_LESS;

		depthStencilDesc.StencilEnable = true;
		depthStencilDesc.StencilReadMask = 0xFF;
		depthStencilDesc.StencilWriteMask = 0xFF;

		// 对于front face 像素使用的模版操作操作.
		depthStencilDesc.FrontFace.StencilFailOp = D3D11_STENCIL_OP_KEEP;
		depthStencilDesc.FrontFace.StencilDepthFailOp = D3D11_STENCIL_OP_INCR;
		depthStencilDesc.FrontFace.StencilPassOp = D3D11_STENCIL_OP_KEEP;
		depthStencilDesc.FrontFace.StencilFunc = D3D11_COMPARISON_ALWAYS;

		// 对于back face像素使用的模版操作模式.
		depthStencilDesc.BackFace.StencilFailOp = D3D11_STENCIL_OP_KEEP;
		depthStencilDesc.BackFace.StencilDepthFailOp = D3D11_STENCIL_OP_DECR;
		depthStencilDesc.BackFace.StencilPassOp = D3D11_STENCIL_OP_KEEP;
		depthStencilDesc.BackFace.StencilFunc = D3D11_COMPARISON_ALWAYS;

		// 创建深度模版状态，使其生效
		ID3D11DepthStencilState* depthStencilState = NULL;
		hr = Device->CreateDepthStencilState(&depthStencilDesc, &depthStencilState);
		DXException::Check(hr, L"CreateDepthStencilState");

		this->DepthStencilState = depthStencilState;
		SafeRelease(depthStencilState);

		// 设置深度模版状态.
		//Context->OMSetDepthStencilState(DepthStencilState, 1);
		Context->OMSetDepthStencilState(0, 0);


		// 初始化深度模版视图.
		ZeroMemory(&depthStencilViewDesc, sizeof(depthStencilViewDesc));

		// 设置深度模版视图描述.
		depthStencilViewDesc.Format = DXGI_FORMAT_D24_UNORM_S8_UINT;
		depthStencilViewDesc.ViewDimension = D3D11_DSV_DIMENSION_TEXTURE2D;
		depthStencilViewDesc.Texture2D.MipSlice = 0;

		// 创建深度模版视图
		ID3D11DepthStencilView* depthStencilView = NULL;
		hr = Device->CreateDepthStencilView(&DepthStencilBuffer, &depthStencilViewDesc, &depthStencilView);
		DXException::Check(hr, L"CreateDepthStencilView");

		this->DepthStencilView = depthStencilView;
		SafeRelease(depthStencilView);

		// 绑定渲染目标视图和深度缓冲到渲染管线.
		ID3D11RenderTargetView* view = &RenderTargetView;
		Context->OMSetRenderTargets(1,  &view, &DepthStencilView);
	}

	void GraphicsDevice::CreateRasterizer()
	{
		// 设置光栅化描述，指定多边形如何被渲染
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

		// 创建光栅化状态
		ID3D11RasterizerState* rasterState;
		hr = Device->CreateRasterizerState(&rasterDesc, &rasterState);
		DXException::Check(hr, L"CreateRasterizerState");

		this->RasterState = rasterState;
		SafeRelease(rasterState);

		//设置光栅化状态，使其生效
		Context->RSSetState(&RasterState);
	}

	void GraphicsDevice::SetViewPort()
	{
		// 设置视口，显示全部后缓冲内容
		D3D11_VIEWPORT viewport;
		viewport.Width = ScreenWidth;
		viewport.Height = ScreenHeight;
		viewport.MinDepth = 0.0f;
		viewport.MaxDepth = 1.0f;
		viewport.TopLeftX = 0.0f;
		viewport.TopLeftY = 0.0f;

		// 创建视口
		Context->RSSetViewports(1, &viewport);
	}

	void GraphicsDevice::CreateBlendState()
	{
		// 初始化blend描述符
		HRESULT hr;
		D3D11_BLEND_DESC blendStateDescription;
		ZeroMemory(&blendStateDescription, sizeof(D3D11_BLEND_DESC));

		// 创建一个alpha blend状态.
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

		// 用描述符创建一个alpha blend状态
		hr = Device->CreateBlendState(&blendStateDescription, &alphaEnableBlendingState);
		DXException::Check(hr, L"CreateBlendState Enable");

		this->AlphaEnableBlendingState = alphaEnableBlendingState;
		SafeRelease(alphaEnableBlendingState);

		//修改描述符.
		blendStateDescription.RenderTarget[0].BlendEnable = FALSE;

		//创建一个新的blend状态.
		hr = Device->CreateBlendState(&blendStateDescription, &alphaDisableBlendingState);
		DXException::Check(hr, L"CreateBlendState Disable");

		this->AlphaDisableBlendingState = alphaDisableBlendingState;
		SafeRelease(alphaDisableBlendingState);
	}

	void GraphicsDevice::BeginScene()
	{
		//清除后缓冲
		Context->ClearRenderTargetView(&RenderTargetView, this->BackgroundColor);

		//清除深度缓冲
		Context->ClearDepthStencilView(&DepthStencilView, D3D11_CLEAR_DEPTH|D3D11_CLEAR_STENCIL, 1.0f, 0);
	}

	void GraphicsDevice::EndScene()
	{
		HRESULT hr;
		//渲染完成后，把后缓冲内容present到前缓冲
		if(VsyncEnabled)
		{
			// 锁定屏幕刷新率.
			hr = SwapChain->Present(1, 0);
		}
		else
		{
			// 尽可能快的present后缓冲.
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

		// 设置blend因子
		blendFactor[0] = 0.0f;
		blendFactor[1] = 0.0f;
		blendFactor[2] = 0.0f;
		blendFactor[3] = 0.0f;
		// 打开alpha blend
		Context->OMSetBlendState(&AlphaEnableBlendingState, blendFactor, 0xffffffff);
	}

	void GraphicsDevice::TurnOffAlphaBlending()
	{
		float blendFactor[4];

		// 设置blend因子
		blendFactor[0] = 0.0f;
		blendFactor[1] = 0.0f;
		blendFactor[2] = 0.0f;
		blendFactor[3] = 0.0f;

		// 关闭alpha blend
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
		loadInfo.MipLevels = D3DX11_DEFAULT; //这时会产生最大的mipmaps层
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
		// 设置顶点缓冲描述
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
		// 设置索引缓冲描述.
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

		// 创建纹理采样描述符
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

		// 创建纹理采样状态
		ID3D11SamplerState* pSampleState;

		HRESULT hr = this->Device->CreateSamplerState(&samplerDesc, &pSampleState);
		DXException::Check(hr, L"Create Sampler State");

		Result << pSampleState;

		return Result;
	}

	void GraphicsDevice::Resize(int screenWidth, int screenHeight)
	{
		HRESULT hr;

		//窗口最小化时候为0，会创建缓冲失败
		if(screenHeight < 1)
			screenHeight = 1;
		if(screenWidth < 1)
			screenWidth = 1;

		this->ScreenWidth = screenWidth;
		this->ScreenHeight = screenHeight;

		//改变交换链中后后缓冲大小后，重新创建渲染目标视图
		hr = SwapChain->ResizeBuffers(1, screenWidth, screenHeight, DXGI_FORMAT_R8G8B8A8_UNORM, 0);

		// 得到交换链中的后缓冲指针
		ID3D11RenderTargetView* pRenderTargetView; //渲染目标视图
		ID3D11Texture2D* pBackBuffer;

		hr = SwapChain->GetBuffer(0, __uuidof(ID3D11Texture2D), (LPVOID*)&pBackBuffer);

		// 用后缓冲创建渲染目标视图.
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

		//在input assemberl阶段绑定顶点缓冲，以便能够被渲染
		Context->IASetVertexBuffers(0, 1, &buff, &width, &offiset);

		//在input assemberl阶段绑定索引缓冲，以便能够被渲染
		Context->IASetIndexBuffer(resource->GetIndexBuffer(), DXGI_FORMAT_R32_UINT, 0);

		// 设置体元语义，渲染线段
		//Context->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_LINELIST);

		// 设置体元语义，渲染三角形列表.
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

		// 传入shader前，确保矩阵转置，这是D3D11的要求.
		D3DXMatrixTranspose(&worldMatrix, &worldMatrix);
		D3DXMatrixTranspose(&Matrixes.View, &Matrixes.View);
		D3DXMatrixTranspose(&Matrixes.Projection, &Matrixes.Projection);
		Matrixes.World = worldMatrix;

		this->Device->UpdateConstBuffer(this->MatrixBuffer, &Matrixes, sizeof(Matrixes));

		// 用更新后的值设置常量缓冲.
		ID3D11Buffer* temp = &MatrixBuffer;
		Context->VSSetConstantBuffers(0, 1, &temp);
	}

	void BasicPipeline::LoadTexture(BasicPipelineResource* resource)
	{
		ID3D11ShaderResourceView* view = resource->GetTextureBuffer();

		if(view)
		{
			// 设置ps shader资源.
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

			// 绑定顶点布局.
			Context->IASetInputLayout(&InputLayout);

			// 设置渲染使用vs和ps.
			Context->VSSetShader(&VertexShader, NULL, 0);
			Context->PSSetShader(&PixelShader, NULL, 0);

			//设置采样状态
			ID3D11SamplerState* temp = &SampleState;
			Context->PSSetSamplers(0, 1, &temp);

			// 渲染三角形
			Context->DrawIndexed(resource->GetIndexCount(), 0, 0);
		}
	}

	GraphicsDevice* BasicPipeline::GetDevice()
	{
		return this->Device;
	}
}