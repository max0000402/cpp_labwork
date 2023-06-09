#include <stdlib.h>
#include <string.h>
#include <tchar.h>
#include <windows.h>

#include "ABCFigure.hpp"
#include "BareTree.hpp"
#include "Tree.hpp"
#include "AppleTree.hpp"
#include "Axe.hpp"
#include "RepairKit.hpp"
#include "Fir.hpp"
#include "Stump.hpp"

static Axe* axe = new Axe(100, 200, RGB(150, 75, 0));
static RepairKit* repair_kit = new RepairKit(200, 200, RGB(200, 200, 200));
static BareTree* trees[] = { new Fir(0, 0, RGB(150, 75, 0)), new AppleTree(100, 0, RGB(150, 75, 0), RGB(0, 255, 0), RGB(255, 0, 0))};

static ABCFigure** figures[] = { (ABCFigure**)&axe, (ABCFigure**)& repair_kit, (ABCFigure**)& trees[0], (ABCFigure**)& trees[1] };

static IAffectable<BareTree>* affectable_on_tree_objects[] = { axe, repair_kit };

static TCHAR szWindowClass[] = _T("DesktopApp");

static TCHAR szTitle[] = _T("Labwork 1");

HINSTANCE hInst;

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
bool intersec(int x0, int y0, int x1, int y1, int x2, int y2, int x3, int y3);

int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance,
	_In_ LPSTR lpCmdLine, _In_ int nCmdShow) {

	WNDCLASSEX wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);
	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = WndProc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = hInstance;
	wcex.hIcon = LoadIcon(wcex.hInstance, IDI_APPLICATION);
	wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wcex.lpszMenuName = NULL;
	wcex.lpszClassName = szWindowClass;
	wcex.hIconSm = LoadIcon(wcex.hInstance, IDI_APPLICATION);

	if (!RegisterClassEx(&wcex)) {
		MessageBox(NULL, _T("Call to RegisterClassEx failed!"), szTitle, NULL);
		return 1;
	}

	hInst = hInstance;

	HWND hWnd = CreateWindowEx(WS_EX_OVERLAPPEDWINDOW, szWindowClass, szTitle,
		WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT,
		800, 600, NULL, NULL, hInstance, NULL);

	if (!hWnd) {
		MessageBox(NULL, _T("Call to CreateWindow failed!"), szTitle, NULL);
		return 1;
	}

	ShowWindow(hWnd, nCmdShow);

	MSG msg;
	while (GetMessage(&msg, NULL, 0, 0)) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return (int)msg.wParam;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam,
	LPARAM lParam) {
	PAINTSTRUCT ps;
	HDC hdc;
	TCHAR greeting[] = _T("Hello, Windows desktop!");

	switch (message) {
	case WM_KEYDOWN:
	{
		
		for (auto figure : figures) {
			(*figure)->process_key_down(wParam);
		}

		if (wParam == 'C') {
			for (auto& tree : trees) {
				for (auto affectable : affectable_on_tree_objects) {
					affectable->affect(tree);
				}
			}
		}

		InvalidateRect(hWnd, NULL, TRUE);
		break;
	}
	case WM_LBUTTONDOWN:
		POINT p;
		GetCursorPos(&p);
		ScreenToClient(hWnd, &p);

		for (auto figure : figures) {
			(*figure)->process_left_mouse_down(p);
		}

		InvalidateRect(hWnd, NULL, TRUE);

		break;
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);

		for (auto figure : figures) {
			(*figure)->draw(hdc);
		}

		EndPaint(hWnd, &ps);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
		break;
	}

	return 0;
}