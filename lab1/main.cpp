#include <stdlib.h>
#include <string.h>
#include <tchar.h>
#include <windows.h>
#include <string>

#include "Point.hpp"
#include "BareTree.hpp"
#include "Tree.hpp"
#include "AppleTree.hpp"
#include "Axe.hpp"
#include "RepairKit.hpp"
#include "Fir.hpp"
#include "Stump.hpp"

#include "AxeVisitor.hpp"
#include "RepairKitVisitor.hpp"

//static BareTree* tree = new AppleTree(0, 0, RGB(150, 75, 0), RGB(0, 255, 0), RGB(255, 0, 0));
static BareTree* tree = new Fir(0, 0, RGB(150, 75, 0));
//static BareTree* tree = new Tree(0, 0, RGB(150, 75, 0), RGB(0, 255, 0));
static Point* axe = new Axe(100, 0, RGB(150, 75, 0));
static Point* repair_kit = new RepairKit(200, 0, RGB(200, 200, 200));

static TCHAR szWindowClass[] = _T("DesktopApp");

static TCHAR szTitle[] = _T("Labwork 1");

HINSTANCE hInst;

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

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
		MessageBox(NULL, _T("Call to RegisterClassEx failed!"),
			_T("Windows Desktop Guided Tour"), NULL);

		return 1;
	}

	hInst = hInstance;

	HWND hWnd = CreateWindowEx(WS_EX_OVERLAPPEDWINDOW, szWindowClass, szTitle,
		WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT,
		800, 600, NULL, NULL, hInstance, NULL);

	if (!hWnd) {
		MessageBox(NULL, _T("Call to CreateWindow failed!"),
			_T("Windows Desktop Guided Tour"), NULL);

		return 1;
	}

	ShowWindow(hWnd, nCmdShow);

	// Main message loop:
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
		tree->process_key_down(wParam);

		if (wParam == 'W') {
			AxeVisitor axe_visitor;
			tree->accept(axe_visitor);
			BareTree* new_tree = axe_visitor.get_result();
			if (tree != new_tree) {
				delete tree;
			}
			tree = new_tree;
		}

		if (wParam == 'S') {
			RepairKitVisitor repair_kit_visitor;
			tree->accept(repair_kit_visitor);
			BareTree* new_tree = repair_kit_visitor.get_result();
			if (tree != new_tree) {
				delete tree;
			}
			tree = new_tree;
		}

		InvalidateRect(hWnd, NULL, TRUE);
		break;
	case WM_LBUTTONDOWN:
		POINT p;
		GetCursorPos(&p);
		ScreenToClient(hWnd, &p);

		tree->process_left_mouse_down(p);

		InvalidateRect(hWnd, NULL, TRUE);

		break;
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);

		tree->draw(hdc);
		axe->draw(hdc);
		repair_kit->draw(hdc);

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