#include "SystemClass.h"


SystemClass::SystemClass(void)
{
	m_Graphics = 0;

	FULL_SCREEN = false;
}

SystemClass::SystemClass(const SystemClass &)
{

}

SystemClass::~SystemClass(void)
{
}

//调用窗口初始化函数和其它一些类的初始化函数
bool SystemClass::Initialize()
{
	bool result;
	int screenWidth = 1024, screenHeight = 256;	// 从配置文件读取


	// 初始化窗口
	InitializeWindows(screenWidth, screenHeight);


	// 创建图形对象，这个对象将渲染应用程序中的所有物体
	m_Graphics = new GraphicsClass;
	if(!m_Graphics)
	{
		return false;
	}
	// 初始化图形对象
	result = m_Graphics->Initialize(screenWidth, screenHeight, m_hwnd);
	if(!result)
	{
		return false;
	}


	return true;
}

void SystemClass::Shutdown()
{
	//其它类的一些销毁工作
	// 释放计时器对象.


	if(m_Graphics)
	{
		m_Graphics->Shutdown();
		delete m_Graphics;
		m_Graphics = 0;
	}


	// 执行一些销毁工作.
	ShutdownWindows();

}

//处理消息
void  SystemClass::Run()
{
	MSG msg;
	bool done, result ;


	// 初始化消息结构.
	ZeroMemory(&msg, sizeof(MSG));

	// 循环进行消息处理，如果接收到WM_QUIT.
	done = false;
	while(!done)
	{
		// 处理windows消息.
		if(PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);

			// 接收到WM_QUIT消息，退出程序.
			if(msg.message == WM_QUIT)
			{
				done = true;
			}
			else if(msg.message == WM_KEYDOWN)
			{
				GraphicsDevice* dev = m_Graphics->getDevice();
				BaseCamera* cemera = dev->GetCamera();

				switch (msg.wParam)
				{
				case VK_LEFT:
					cemera->Walk(-0.1, 0, 0);
					break;

				case VK_RIGHT:
					cemera->Walk(0.1, 0, 0);
					break;

				case VK_UP:
					cemera->Walk(0, 0, 0.1);
					break;

				case VK_DOWN:
					cemera->Walk(0, 0, -0.1);
					break;

				default:
					break;
				}

			}
		}

		result = Frame();
		if(!result)
		{
			done = true;
		}
	}

	return;
}

bool SystemClass::Frame()
{
	bool result;

	// 执行帧渲染函数.
	result = m_Graphics->Frame();
	if(!result)
	{
		return false;
	}
	return true;
}

//初始化窗口类，创建应用程序窗口
void SystemClass::InitializeWindows(int& screenWidth, int& screenHeight)
{
	WNDCLASSEX wc;
	DEVMODE dmScreenSettings;
	int posX, posY;

	//得到应用程序对象指针
	ApplicationHandle = this;

	// 得到应用程序实例句柄
	m_hinstance = GetModuleHandle(NULL);

	// 应用程序名字
	m_applicationName = L"Test Engine";

	// 设置窗口类参数.
	wc.style         = CS_HREDRAW | CS_VREDRAW | CS_OWNDC;
	wc.lpfnWndProc   = WndProc; //指定回调函数
	wc.cbClsExtra    = 0;
	wc.cbWndExtra    = 0;
	wc.hInstance     = m_hinstance;
	wc.hIcon		 = LoadIcon(NULL, IDI_WINLOGO);
	wc.hIconSm       = wc.hIcon;
	wc.hCursor       = LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH); //默认黑色窗口黑色背景
	wc.lpszMenuName  = NULL;
	wc.lpszClassName = m_applicationName;
	wc.cbSize        = sizeof(WNDCLASSEX);

	// 注册窗口类
	RegisterClassEx(&wc);

	// 得到windows桌面分辨率
	int _screenWidth  = GetSystemMetrics(SM_CXSCREEN);
	int _screenHeight = GetSystemMetrics(SM_CYSCREEN);

	// 根据是否全屏设置不同的分辨率.
	if(FULL_SCREEN)
	{
		//全屏模式下，设置窗口大小为windows桌面分辨率.
		memset(&dmScreenSettings, 0, sizeof(dmScreenSettings));
		dmScreenSettings.dmSize       = sizeof(dmScreenSettings);
		dmScreenSettings.dmPelsWidth  = (unsigned long)screenWidth;
		dmScreenSettings.dmPelsHeight = (unsigned long)screenHeight;
		dmScreenSettings.dmBitsPerPel = 32;			
		dmScreenSettings.dmFields     = DM_BITSPERPEL | DM_PELSWIDTH | DM_PELSHEIGHT;

		// 临时设置显示设备为全屏模式，注意：应用程序退出时候，将恢复系统默认设置。
		ChangeDisplaySettings(&dmScreenSettings, CDS_FULLSCREEN);

		// 设置窗口的默认位置为(0,0).
		posX = posY = 0;
	}
	else
	{
		// 窗口模式：800*600.
		//screenWidth  = 800;
		//screenHeight = 600;
		RECT rect = { 0, 0, screenWidth, screenHeight };	// 无边框窗口
		AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, FALSE);	// 窗口矩形大小

		// 窗口位置,posX, posY窗口左上角坐标
		posX = (GetSystemMetrics(SM_CXSCREEN) - screenWidth)  / 2;
		posY = (GetSystemMetrics(SM_CYSCREEN) - screenHeight) / 2;
	}

	// 全屏和窗口使用不同的参数.
	if( FULL_SCREEN)
	{
		m_hwnd = CreateWindowEx(WS_EX_APPWINDOW, m_applicationName, m_applicationName, 
			WS_CLIPSIBLINGS | WS_CLIPCHILDREN | WS_POPUP,
			posX, posY, screenWidth, screenHeight, NULL, NULL, m_hinstance, NULL);
	}
	else
	{
		// WS_POPUP: 无边框, WS_OVERLAPPEDWINDOW: 有边框
		m_hwnd = CreateWindowEx(WS_EX_APPWINDOW, m_applicationName, m_applicationName, 
			WS_POPUP,
			posX, posY, screenWidth, screenHeight, NULL, NULL, m_hinstance, NULL);
	}

	// 显示窗口并设置其为焦点.
	ShowWindow(m_hwnd, SW_SHOW);
	SetForegroundWindow(m_hwnd);
	SetFocus(m_hwnd);

	// 隐藏鼠标.
	//ShowCursor(false);


}

void SystemClass::ShutdownWindows()
{
	//显示光标.
	//ShowCursor(true);

	// 恢复默认显示设置.
	if(FULL_SCREEN)
	{
		ChangeDisplaySettings(NULL, 0);
	}

	// 销毁窗口
	DestroyWindow(m_hwnd);
	m_hwnd = NULL;

	// 销毁应用程序实例.
	UnregisterClass(m_applicationName, m_hinstance);
	m_hinstance = NULL;
	ApplicationHandle = NULL;

	return;

}

LRESULT CALLBACK SystemClass::MessageHandler(HWND hwnd, UINT umsg, WPARAM wparam, LPARAM lparam)
{

	POINT mousePos;
	int dx = 0;
	int dy = 0;

	switch(umsg)
	{
	case WM_LBUTTONDOWN:
		if( wparam & MK_LBUTTON )
		{
			SetCapture(hwnd);

			m_OldMousePos.x = LOWORD(lparam);
			m_OldMousePos.y = HIWORD(lparam);
		}
		return 0;

	case WM_LBUTTONUP:
		ReleaseCapture();
		return 0;
		//任何其它消息发送到windows缺省处理.

	default:
		{
			return DefWindowProc(hwnd, umsg, wparam, lparam);
		}
	}
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT umessage, WPARAM wparam, LPARAM lparam)
{
	switch(umessage)
	{

		// 窗口销毁消息.
	case WM_DESTROY:
		PostQuitMessage(0);
		break;

		// 窗口关闭消息.
	case WM_CLOSE:
		PostQuitMessage(0);		
		break;

		//MessageHandle过程处理其它所有消息.
	default:
		{
			return ApplicationHandle->MessageHandler(hwnd, umessage, wparam, lparam);
		}
	}
}