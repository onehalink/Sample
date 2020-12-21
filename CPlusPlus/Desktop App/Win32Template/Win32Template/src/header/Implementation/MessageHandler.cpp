#include "../MessageHandler.h"

LRESULT CALLBACK MessageHandler(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) {
	switch (message) {
	case WM_PAINT:
	{
		PAINTSTRUCT ps = {};
		RECT clientRect = {};
		GetClientRect(hWnd, &clientRect);

		HDC hdc = BeginPaint(hWnd, &ps);
		FillRect(hdc, &clientRect, CreateSolidBrush(RGB(255, 255, 255)));//RGB(255, 255, 255) is same as "(0b11111111 << 16) | (0b11111111 << 8) | (0b11111111)"
		EndPaint(hWnd, &ps);
	}
		return 0;
	case WM_CLOSE:
		PostQuitMessage(0);
		return 0;
	}
	return DefWindowProc(hWnd, message, wParam, lParam);
}