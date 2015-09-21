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

//���ô��ڳ�ʼ������������һЩ��ĳ�ʼ������
bool SystemClass::Initialize()
{
	bool result;
	int screenWidth = 1024, screenHeight = 256;	// �������ļ���ȡ


	// ��ʼ������
	InitializeWindows(screenWidth, screenHeight);


	// ����ͼ�ζ������������ȾӦ�ó����е���������
	m_Graphics = new GraphicsClass;
	if(!m_Graphics)
	{
		return false;
	}
	// ��ʼ��ͼ�ζ���
	result = m_Graphics->Initialize(screenWidth, screenHeight, m_hwnd);
	if(!result)
	{
		return false;
	}


	return true;
}

void SystemClass::Shutdown()
{
	//�������һЩ���ٹ���
	// �ͷż�ʱ������.


	if(m_Graphics)
	{
		m_Graphics->Shutdown();
		delete m_Graphics;
		m_Graphics = 0;
	}


	// ִ��һЩ���ٹ���.
	ShutdownWindows();

}

//������Ϣ
void  SystemClass::Run()
{
	MSG msg;
	bool done, result ;


	// ��ʼ����Ϣ�ṹ.
	ZeroMemory(&msg, sizeof(MSG));

	// ѭ��������Ϣ����������յ�WM_QUIT.
	done = false;
	while(!done)
	{
		// ����windows��Ϣ.
		if(PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);

			// ���յ�WM_QUIT��Ϣ���˳�����.
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

	// ִ��֡��Ⱦ����.
	result = m_Graphics->Frame();
	if(!result)
	{
		return false;
	}
	return true;
}

//��ʼ�������࣬����Ӧ�ó��򴰿�
void SystemClass::InitializeWindows(int& screenWidth, int& screenHeight)
{
	WNDCLASSEX wc;
	DEVMODE dmScreenSettings;
	int posX, posY;

	//�õ�Ӧ�ó������ָ��
	ApplicationHandle = this;

	// �õ�Ӧ�ó���ʵ�����
	m_hinstance = GetModuleHandle(NULL);

	// Ӧ�ó�������
	m_applicationName = L"Test Engine";

	// ���ô��������.
	wc.style         = CS_HREDRAW | CS_VREDRAW | CS_OWNDC;
	wc.lpfnWndProc   = WndProc; //ָ���ص�����
	wc.cbClsExtra    = 0;
	wc.cbWndExtra    = 0;
	wc.hInstance     = m_hinstance;
	wc.hIcon		 = LoadIcon(NULL, IDI_WINLOGO);
	wc.hIconSm       = wc.hIcon;
	wc.hCursor       = LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH); //Ĭ�Ϻ�ɫ���ں�ɫ����
	wc.lpszMenuName  = NULL;
	wc.lpszClassName = m_applicationName;
	wc.cbSize        = sizeof(WNDCLASSEX);

	// ע�ᴰ����
	RegisterClassEx(&wc);

	// �õ�windows����ֱ���
	int _screenWidth  = GetSystemMetrics(SM_CXSCREEN);
	int _screenHeight = GetSystemMetrics(SM_CYSCREEN);

	// �����Ƿ�ȫ�����ò�ͬ�ķֱ���.
	if(FULL_SCREEN)
	{
		//ȫ��ģʽ�£����ô��ڴ�СΪwindows����ֱ���.
		memset(&dmScreenSettings, 0, sizeof(dmScreenSettings));
		dmScreenSettings.dmSize       = sizeof(dmScreenSettings);
		dmScreenSettings.dmPelsWidth  = (unsigned long)screenWidth;
		dmScreenSettings.dmPelsHeight = (unsigned long)screenHeight;
		dmScreenSettings.dmBitsPerPel = 32;			
		dmScreenSettings.dmFields     = DM_BITSPERPEL | DM_PELSWIDTH | DM_PELSHEIGHT;

		// ��ʱ������ʾ�豸Ϊȫ��ģʽ��ע�⣺Ӧ�ó����˳�ʱ�򣬽��ָ�ϵͳĬ�����á�
		ChangeDisplaySettings(&dmScreenSettings, CDS_FULLSCREEN);

		// ���ô��ڵ�Ĭ��λ��Ϊ(0,0).
		posX = posY = 0;
	}
	else
	{
		// ����ģʽ��800*600.
		//screenWidth  = 800;
		//screenHeight = 600;
		RECT rect = { 0, 0, screenWidth, screenHeight };	// �ޱ߿򴰿�
		AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, FALSE);	// ���ھ��δ�С

		// ����λ��,posX, posY�������Ͻ�����
		posX = (GetSystemMetrics(SM_CXSCREEN) - screenWidth)  / 2;
		posY = (GetSystemMetrics(SM_CYSCREEN) - screenHeight) / 2;
	}

	// ȫ���ʹ���ʹ�ò�ͬ�Ĳ���.
	if( FULL_SCREEN)
	{
		m_hwnd = CreateWindowEx(WS_EX_APPWINDOW, m_applicationName, m_applicationName, 
			WS_CLIPSIBLINGS | WS_CLIPCHILDREN | WS_POPUP,
			posX, posY, screenWidth, screenHeight, NULL, NULL, m_hinstance, NULL);
	}
	else
	{
		// WS_POPUP: �ޱ߿�, WS_OVERLAPPEDWINDOW: �б߿�
		m_hwnd = CreateWindowEx(WS_EX_APPWINDOW, m_applicationName, m_applicationName, 
			WS_POPUP,
			posX, posY, screenWidth, screenHeight, NULL, NULL, m_hinstance, NULL);
	}

	// ��ʾ���ڲ�������Ϊ����.
	ShowWindow(m_hwnd, SW_SHOW);
	SetForegroundWindow(m_hwnd);
	SetFocus(m_hwnd);

	// �������.
	//ShowCursor(false);


}

void SystemClass::ShutdownWindows()
{
	//��ʾ���.
	//ShowCursor(true);

	// �ָ�Ĭ����ʾ����.
	if(FULL_SCREEN)
	{
		ChangeDisplaySettings(NULL, 0);
	}

	// ���ٴ���
	DestroyWindow(m_hwnd);
	m_hwnd = NULL;

	// ����Ӧ�ó���ʵ��.
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
		//�κ�������Ϣ���͵�windowsȱʡ����.

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

		// ����������Ϣ.
	case WM_DESTROY:
		PostQuitMessage(0);
		break;

		// ���ڹر���Ϣ.
	case WM_CLOSE:
		PostQuitMessage(0);		
		break;

		//MessageHandle���̴�������������Ϣ.
	default:
		{
			return ApplicationHandle->MessageHandler(hwnd, umessage, wparam, lparam);
		}
	}
}