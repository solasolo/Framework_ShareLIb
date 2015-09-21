#include "stdafx.h"
#include "ModelTarget.h"

#include "WinFuncs.h"

using namespace Win32Lib; 

ModelTarget::ModelTarget(BasicPipeline* piple)
	: BaseGraphicObject()
{
	this->Resource = NULL;
	this->Resource = new BasicPipelineResource(piple->GetDevice()); 
	this->Piple = piple;

	this->ResPath = GetStartupPath() + L"..\\Res\\";
}


ModelTarget::~ModelTarget(void)
{
}

void ModelTarget::Initial()
{
	this->InitialBuffer();

	this->InitialShader();
}

void ModelTarget::InitialBuffer()
{
	const int vertexCount = 4;
	const int indexCount = 6;

	VertexType vertices[vertexCount];

	//创建顺时针方向的三角形，左手规则
	// (-1,1)		(1,1)
	//				0
	// (-1,-1)		(1,-1)

	float targetWidth = 1.0f;
	float targetHeight = 1.0f;

	float w = 0.5f * targetWidth, h = 0.5f * targetHeight, z = 0.0f;	// 靶子显示在屏幕中心

	vertices[0].position = D3DXVECTOR3(-w, h, z);	// left, top
	vertices[0].texture = D3DXVECTOR2(0.0f, 0.0f);

	vertices[1].position = D3DXVECTOR3(w, h, z);	// right, top
	vertices[1].texture = D3DXVECTOR2(1.0f, 0.0f);

	vertices[2].position = D3DXVECTOR3(-w, -h, z);	// left, bottom
	vertices[2].texture = D3DXVECTOR2(0.0f, 1.0f);

	vertices[3].position = D3DXVECTOR3(w, -h, z);	// right, bottom
	vertices[3].texture = D3DXVECTOR2(1.0f, 1.0f);

	// 设置索引缓冲数据.
	unsigned long indices[] = {
		0, 1, 3,
		0, 3, 2
	};

	// 创建顶点缓冲.
	this->Resource->CreateVertexBuffer(vertices, vertexCount, sizeof(VertexType));

	// 创建索引缓冲.
	this->Resource->CreateIndexBuffer(indices, indexCount);
}

void ModelTarget::InitialShader()
{
	wstring path_vs = ResPath + L"targetcolor.vs";
	wstring path_ps = ResPath + L"targetcolor.ps";

	SemanticType lays[] = {SemanticType::POSITION, SemanticType::TEXCOORD};
	this->Piple->CreateVSShader(path_vs, lays, 2);
	this->Piple->CreatePSShader(path_ps);
}

void ModelTarget::Render()
{
	this->Resource->UpdateTexture(ResPath + L"胸环靶.png");
	this->Piple->Render(this->WorldMatrix, this->Resource);
}