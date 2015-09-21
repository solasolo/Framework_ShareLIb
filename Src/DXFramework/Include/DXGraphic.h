#pragma once

#include <dxgi.h>
#include <d3dcommon.h>
#include <d3d11.h>
#include <d3dx10math.h>
#include <d3dx11tex.h>
#include <cstdio>
#include <vector>

#include "SmartPointer.h"
#include "CameraClass.h"
#include "GraphicBaseDevice.h"
#include "DXException.h"

using namespace GLEO;

COMPtr(IDXGIFactory1);
COMPtr(IDXGIFactory);
COMPtr(IDXGIAdapter1);
COMPtr(IDXGIAdapter);
COMPtr(IDXGIOutput);

COMPtr(IDXGISwapChain);
COMPtr(ID3D11Device);
COMPtr(ID3D11DeviceContext);
COMPtr(ID3D11RenderTargetView);
COMPtr(ID3D11Texture2D);
COMPtr(ID3D11DepthStencilState);
COMPtr(ID3D11DepthStencilView);
COMPtr(ID3D11RasterizerState);
COMPtr(ID3D11BlendState);
COMPtr(ID3D11Buffer);
COMPtr(ID3D11ShaderResourceView);

COMPtr(ID3D11VertexShader);
COMPtr(ID3D11PixelShader);
COMPtr(ID3D11InputLayout);
COMPtr(ID3D11SamplerState);

namespace GLEO
{
	enum SemanticType
	{
		BINORMAL = 0,
		BLENDINDICES, 
		BLENDWEIGHT, 
		COLOR, 
		NORMAL, 
		POSITION, 
		POSITIONT, 
		PSIZE, 
		TANGENT, 
		TEXCOORD,
		_COUNT
	};

	// 封装D3D类实现画面渲染
	class __declspec(dllexport) GraphicsDevice : public GraphicBaseDevice
	{
	public:
		struct SemanticDesc
		{
			char* Name;
			DXGI_FORMAT Format;
			int Size;
		};

	private:
		HWND hwnd;
		bool IsFullScreen;

		float ScreenDepth, ScreenNear;
		int ScreenWidth, ScreenHeight;

		bool VsyncEnabled; //是否启用垂直同步
		int VideoCardMemory; //显存大小
		float BackgroundColor[4];	// 用于后缓冲颜色

		BaseCamera* Camera;

		unsigned int numModes, numerator, denominator;

		IDXGIAdapter1Ptr Adapter;
		IDXGIOutputPtr Output;
		IDXGISwapChainPtr SwapChain; 
		ID3D11RenderTargetViewPtr RenderTargetView; //渲染目标视图
		ID3D11Texture2DPtr DepthStencilBuffer;
		ID3D11DepthStencilStatePtr DepthStencilState;
		ID3D11DepthStencilViewPtr DepthStencilView; //深度目标视图
		ID3D11RasterizerStatePtr RasterState; //渲染状态
		ID3D11DepthStencilStatePtr DepthStencilStateCube;

		ID3D11BlendStatePtr	AlphaEnableBlendingState;
		ID3D11BlendStatePtr	AlphaDisableBlendingState;

		void GetRefreshRate();
		void CreateSwapChain();
		void CreateTargetView();
		void CreateDepthStencilView();
		void CreateRasterizer();
		void SetViewPort();
		void CreateBlendState();

		D3D11_INPUT_ELEMENT_DESC* BuildLayout(SemanticType laylist[], int count);

	public:
		GraphicsDevice();
		~GraphicsDevice();

		void Initialize(int screenWidth, int screenHeight, HWND hwnd, bool vsync, bool fullscreen, float screenDepth, float screenNear);
		void SetBackgroundColor(float color[4]);

		void BeginScene();
		void EndScene();
		void ShutDown();

		ID3D11DevicePtr GetDevice();
		ID3D11DeviceContextPtr GetContext();

		BaseCamera* GetCamera();
		void SetCamera(BaseCamera* camera);

		ID3D11ShaderResourceViewPtr CreateTexture(wstring file);
		ID3D11BufferPtr CreateVertexBuffer(void* data, int count, int width);
		ID3D11BufferPtr CreateIndexBuffer(void* data, int count);
		ID3D11VertexShaderPtr CreateVertexShader(wstring file, SemanticType laylist[], int count, ID3D11InputLayoutPtr& layout, string entry="VSMain");
		ID3D11PixelShaderPtr CreatePixelShader(wstring file, string entry="PSMain");
		ID3D11SamplerStatePtr CreateSamplerState();

		void Resize(int screenWidth, int screenHeight);
		void GetProjectionMatrix(D3DXMATRIX& projectionMatrix);

	private:

		void TurnOnAlphaBlending();
		void TurnOffAlphaBlending();

	};

	class _declspec(dllexport) BasicPipelineResource
	{
	private:
		int VertexCount;
		int IndexCount;
		unsigned int VertexWidth;
		unsigned int VertexOffset;

		GraphicsDevice*	Device;

		//顶点缓冲和顶点索引缓冲
		ID3D11BufferPtr	VertexBuffer;
		ID3D11BufferPtr	IndexBuffer;

		// Texture
		ID3D11ShaderResourceViewPtr TextureView;

	protected:
		ID3D11ShaderResourceViewPtr CreateTexture(wstring filename);

	public:
		BasicPipelineResource(GraphicsDevice* device);	

		//
		void CreateVertexBuffer(void* vertices, int vertexCount, unsigned int byteWidth);
		void CreateIndexBuffer(unsigned long* indices, int indexCount);
		void UpdateTexture(wstring path);

		ID3D11Buffer* GetVectexBuffer();
		ID3D11Buffer* GetIndexBuffer();
		ID3D11ShaderResourceView* GetTextureBuffer();

		int GetIndexCount();
		int GetVertexCount();
		unsigned int GetVertexWidth();
		unsigned int GetVertexOffset();
	};

	// 封装D3D资源类
	class _declspec(dllexport) BasicPipeline
	{
		//和shader中const buffer结构一致，主要用来给这些shader参数赋值。
		struct MatrixBufferType
		{
			D3DXMATRIX World;
			D3DXMATRIX View;
			D3DXMATRIX Projection;
		};

	private:
		ID3D11BufferPtr	MatrixBuffer;

		GraphicsDevice*	Device;
		ID3D11DeviceContextPtr Context;

		// Shader相关属性
		ID3D11InputLayoutPtr InputLayout;
		ID3D11VertexShaderPtr VertexShader;
		ID3D11PixelShaderPtr PixelShader;
		
		ID3D11SamplerStatePtr SampleState;

		void CreateMatrixBuffer();
		void LoadVertex(BasicPipelineResource* resource);
		void LoadMatrix(D3DXMATRIX& worldMatrix);
		void LoadTexture(BasicPipelineResource* resource);

	public:
		BasicPipeline(GraphicsDevice* graphicsDevice);
		~BasicPipeline();

		//
		void CreatePSShader(wstring file);
		void CreateVSShader(wstring file, SemanticType laylist[], int count);

		//
		ID3D11ShaderResourceViewPtr CreateTexture(wstring texFile);
		//
		void Render(D3DXMATRIX worldMatrix, BasicPipelineResource* resource);

		GraphicsDevice* GetDevice();
	};
}