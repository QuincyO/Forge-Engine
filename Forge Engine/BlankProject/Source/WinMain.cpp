#include "pch.h"

/*-------------------------------------------------------------------*/
/*	Filename: WinMain.cpp											 */
/*-------------------------------------------------------------------*/

/*-------------------------------------------------------------------*/
/*	Global Variables												*/
/*------------------------------------------------------------------*/
#pragma region Global Variables

WCHAR WindowClass[MAX_NAME_STRING];
WCHAR WindowTitle[MAX_NAME_STRING];


INT WindowWidth;
INT WindowHeight;

HICON hIcon;
#pragma endregion




/*-------------------------------------------------------------------*/
/*	Pre Declarations												*/
/*------------------------------------------------------------------*/

#pragma region Pre Declarations

VOID InitializeVariables();
VOID CreateWindowClass();
LRESULT CALLBACK WindowProcess(HWND hWnd, UINT message, WPARAM wparam, LPARAM lparm);
VOID InitializeWindow();
VOID MessageLoop();

#pragma endregion

/*-------------------------------------------------------------------*/
/*	Operations														*/
/*------------------------------------------------------------------*/

#pragma region Operations
int CALLBACK WinMain(HINSTANCE, HINSTANCE, LPSTR, INT)
{
	InitializeVariables();	
	CreateWindowClass();
	InitializeWindow();
	MessageLoop();
	return 0;
}

LRESULT CALLBACK WindowProcess(HWND hWnd, UINT message, WPARAM wparam, LPARAM lparm)
{
	switch (message)
	{
	case WM_DESTROY:

		PostQuitMessage(0);
		break;
	}
	return DefWindowProc(hWnd, message, wparam, lparm);
}
#pragma endregion
/*-------------------------------------------------------------------*/
/*	Functions														*/
/*------------------------------------------------------------------*/
#pragma region Functions

VOID InitializeWindow()
{
	HWND hWnd = CreateWindow(WindowClass, WindowTitle, WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, 0, WindowWidth, WindowHeight, nullptr, nullptr, HInstance(), nullptr);

	if (!hWnd)
	{
		MessageBox(NULL, L"Failed to create window", L"Error", MB_OK);
	}

	ShowWindow(hWnd, SW_SHOW);
}

VOID MessageLoop()
{
	//Main message loop

	MSG msg = { 0 };
	while (msg.message != WM_QUIT)
	{
		if (PeekMessage(&msg, 0, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}
}

VOID InitializeVariables()
{
	LoadString(HInstance(), IDS_PERGAMENAME, WindowTitle, MAX_NAME_STRING);
	LoadString(HInstance(), IDS_WINDOWCLASS, WindowClass, MAX_NAME_STRING);
	WindowWidth = 800;
	WindowHeight = 600;
	hIcon = LoadIcon(HInstance(), MAKEINTRESOURCE(IDI_MAINICON));
}

VOID CreateWindowClass()
{
	WNDCLASSEX wcex;
	wcex.cbSize = sizeof(WNDCLASSEX);
	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wcex.hIcon = hIcon;
	wcex.hIconSm = hIcon;
	wcex.lpszClassName = WindowClass;
	wcex.lpszMenuName = nullptr;
	wcex.hInstance = HInstance();
	wcex.lpfnWndProc = WindowProcess;
	RegisterClassEx(&wcex);
}

#pragma endregion

//The WinMain function is the entry point for a Windows application.It is the equivalent of the main function in a console application.The WinMain function is called by the operating system when the application is started.The function takes four parameters :
//
//hInstance  ? A handle to the current instance of the application.
//hPrevInstance  ? A handle to the previous instance of the application.This parameter is always NULL.
//lpCmdLine  ? The command line for the application, excluding the program name.
//nCmdShow  ? An integer value that specifies how the window is to be shown.
//
//The WinMain function returns an integer value that is used as the exit code for the application.In this case, the function simply returns 0.
//The WinMain function is defined with the CALLBACK macro, which is a Windows - specific calling convention that is used to specify how functions are called.The CALLBACK macro is defined in the Windows header files.
//The WinMain function is defined in the Windows header files, so we don?t need to define it ourselves.We simply need to include the Windows.h header file, which contains the definition of the WinMain function.
//The WinMain function is the entry point for a Windows application.It is called by the operating system when the application is started.The function takes four parameters :
//
//hInstance  ? A handle to the current instance of the application.
//hPrevInstance  ? A handle to the previous instance of the application.This parameter is always NULL.
//lpCmdLine  ? The command line for the application, excluding the program name.
//nCmdShow  ? An integer value that specifies how the window is to be shown.
//
//The WinMain function returns an integer value that is used as the exit code for the application.In this case, the function simply returns 0.
//The WinMain function is defined with the CALLBACK macro, which is a Windows - specific calling convention that is used to specify how functions are called.The CALLBACK macro is defined in the Windows header files.
//The WinMain function is defined in the Windows header files, so we don?t need to define it ourselves.We simply need to include the Windows.h header file, which contains the definition of the WinMain function.
//The WinMain function is the entry point for a Windows application.It is called by the operating system when the application is started.The function takes four parameters :
//
//hInstance  ? A