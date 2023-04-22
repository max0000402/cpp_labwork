#include "Axe.hpp"

Axe::Axe(int x, int y, COLORREF color) : Point(x, y, color) {
	m_brush_stick = CreateSolidBrush(get_color());
	m_brush_axe = CreateSolidBrush(RGB(127, 127, 127));
	m_pen_string = CreatePen(PS_SOLID, 1, RGB(252, 218, 191));
}

void Axe::draw(HDC& hdc) {
	if (!is_visible()) {
		return;
	}

	SelectObject(hdc, m_brush_stick);
	SelectObject(hdc, GetStockObject(BLACK_PEN));
	Rectangle(hdc, get_x(), get_y(), get_x() + 10, get_y() + 80);


	SelectObject(hdc, m_brush_axe);

	POINT poly[3];

	poly[0].x = get_x();
	poly[0].y = get_y() + 20;

	poly[1].x = get_x() + 30;
	poly[1].y = get_y();

	poly[2].x = get_x() + 30;
	poly[2].y = get_y() + 40;

	Polygon(hdc, poly, 3);



	SelectObject(hdc, m_pen_string);
	MoveToEx(hdc, get_x(), get_y() + 13, nullptr);
	LineTo(hdc, get_x() + 10, get_y() + 28);

	MoveToEx(hdc, get_x() + 10, get_y() + 13, nullptr);
	LineTo(hdc, get_x(), get_y() + 28);
}

Axe::~Axe() {
	DeleteObject(m_brush_axe);
	DeleteObject(m_brush_stick);
	DeleteObject(m_pen_string);
}

//void Axe::process_left_mouse_down(POINT& p) {
//	int width = 30;
//	int height = 80;
//
//	if (p.x >= get_x() && p.x <= get_x() + width && p.y >= get_y() && p.y <= get_y() + height) {
//		move(0, 10);
//	}
//}