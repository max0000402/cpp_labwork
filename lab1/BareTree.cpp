#include "BareTree.hpp"

BareTree::BareTree(int x, int y, COLORREF color) : ABCFigure(x, y, color) {
	m_brush = CreateSolidBrush(color);
	m_pen = CreatePen(PS_SOLID, 2, color);

	m_width = 40;
	m_height = 130;
}

void BareTree::draw(HDC& hdc) {
	draw_dragging_rectangle(hdc);

	if (!is_visible()) {
		return;
	}

	SelectObject(hdc, m_brush);
	SelectObject(hdc, GetStockObject(NULL_PEN));

	POINT poly[3];

	poly[0].x = get_x() + 10 + 8;
	poly[0].y = get_y() + 50;

	poly[1].x = get_x() + 8;
	poly[1].y = get_y() + 100 + 30;

	poly[2].x = get_x() + 20 + 8;
	poly[2].y = get_y() + 100 + 30;

	Polygon(hdc, poly, 3);


	SelectObject(hdc, m_pen);

	MoveToEx(hdc, get_x() + 18, get_y() + 60, nullptr);
	LineTo(hdc, get_x() + 4, get_y() + 20);

	MoveToEx(hdc, get_x() + 18, get_y() + 60, nullptr);
	LineTo(hdc, get_x() + 24, get_y() + 20);

	MoveToEx(hdc, get_x() + 23, get_y() + 30, nullptr);
	LineTo(hdc, get_x() + 30, get_y() + 40);

	MoveToEx(hdc, get_x() + 20, get_y() + 40, nullptr);
	LineTo(hdc, get_x() + 10, get_y() + 4);

	MoveToEx(hdc, get_x() + 16, get_y() + 20, nullptr);
	LineTo(hdc, get_x() + 24, get_y() + 4);
}

void BareTree::accept(ITreeVisitor& visitor) {
	visitor.VisitBareTree(this);
}

BareTree::~BareTree() {
	DeleteObject(m_pen);
	DeleteObject(m_brush);
}