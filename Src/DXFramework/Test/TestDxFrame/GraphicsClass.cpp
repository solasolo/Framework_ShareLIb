#include "stdafx.h"
#include "GraphicsClass.h"


const bool VSYNC_ENABLED = false;
const bool FULL_SCREEN = false;

GraphicsClass::GraphicsClass(void)
{
	graphicsDevice = NULL;
}


GraphicsClass::~GraphicsClass(void)
{
}

bool GraphicsClass:: Initialize(int screenWidth, int screenHeight, HWND hwnd)
{
	graphicsDevice = new GraphicsDevice();

	graphicsDevice->Initialize(screenWidth, screenHeight, hwnd, VSYNC_ENABLED, FULL_SCREEN, 1000.0f, 0.1f);

	BaseCamera* camera = new ProjectCamera(8, 3, 50);
	camera->SetScreen(screenWidth, screenHeight);
	camera->SetPosition(D3DXVECTOR3(0, 0, -50));
	graphicsDevice->SetCamera(camera);

	BasicPipeline* Respack = new BasicPipeline(graphicsDevice);

	modelTarget = new ModelTarget(Respack);
	modelTarget->Move(0, 0, 0.2);

	modelTarget->Initial();

	return true;
}

bool GraphicsClass::Frame()
{
	try
	{
		this->Render();

	}
	catch(DXException& ex)
	{
		MessageBox(NULL, ex.GetDescription().c_str(), L"", 0);
	}

	return true;
}

void GraphicsClass::Render()
{
	this->graphicsDevice->BeginScene();

	this->modelTarget->Render();

	this->graphicsDevice->EndScene();
}

void GraphicsClass::FillRes()
{

}

void GraphicsClass::Shutdown()
{

}

GraphicsDevice* GraphicsClass::getDevice()
{
	return this->graphicsDevice;
}
