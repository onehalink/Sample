#include "Framework.h"
#include "header/MessageHandler.h"

INT WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE, PWSTR, INT nCmdShow) {
	const WCHAR* windowCaption = L"Default Window";
	const WCHAR* mainWindowClassName = L"mwcn";

	//register window class
	WNDCLASS wc = {};
	wc.hInstance = hInstance;
	//wc.lpfnWndProc = DefWindowProc;
	wc.lpfnWndProc = MessageHandler;
	wc.lpszClassName = mainWindowClassName;

	RegisterClass(&wc);

	//create window and show it
	HWND hWnd = CreateWindowEx(
		0,//extra window style
		mainWindowClassName,
		windowCaption,
		WS_OVERLAPPEDWINDOW,//window style
		CW_USEDEFAULT, CW_USEDEFAULT, SCREEN_WIDTH, SCREEN_HEIGHT, //position and size of the window
		NULL,//parent window
		0,//window menu
		hInstance,//handle to a module
		NULL//address of which a pointer to data collection
	);

	//fail to create, exit
	if (!hWnd)return -1;

	ShowWindow(hWnd, nCmdShow);

	//main loop
	MSG message = {};
	while (GetMessage(&message, NULL, 0, 0)) {
		TranslateMessage(&message);
		DispatchMessage(&message);
	}

	//exit
	return 0;
}