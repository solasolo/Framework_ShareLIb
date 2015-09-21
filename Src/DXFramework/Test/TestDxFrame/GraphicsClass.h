#pragma once

#include <windows.h>

#include "DxGraphic.h"

#include "ModelTarget.h"

using namespace GLEO;


class GraphicsClass
{
public:
	GraphicsClass(void);
	~GraphicsClass(void);

	bool Initialize(int screenWidth, int screenHeight, HWND hwnd);

	bool Frame();

	void Shutdown();

	GraphicsDevice* getDevice();	

private:

	GraphicsDevice* graphicsDevice;

	ModelTarget* modelTarget;

	void FillRes();
	void Render();
};

