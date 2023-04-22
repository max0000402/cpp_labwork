#include "BareTree.hpp"

BareTree::BareTree(int x, int y, COLORREF color) : Point(x, y, color) {
	m_is_dragging = false;

	m_brush = CreateSolidBrush(get_color());
	m_pen = CreatePen(PS_SOLID, 2, get_color());
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

void BareTree::draw_dragging_rectangle(HDC& hdc) {
	if (m_is_dragging) {
		SelectObject(hdc, GetStockObject(BLACK_PEN));
		SelectObject(hdc, GetStockObject(NULL_BRUSH));
		Rectangle(hdc, get_x(), get_y(), get_x() + get_width(), get_y() + get_height());
	}
}

int BareTree::get_width() {
	return 40;
}

int BareTree::get_height() {
	return 130;
}

void BareTree::process_left_mouse_down(POINT& p) {
	if (p.x >= get_x() && p.x <= get_x() + get_width() && p.y >= get_y() && p.y <= get_y() + get_height()) {
		m_is_dragging = !m_is_dragging;
	}
}

void BareTree::process_key_down(WPARAM key) {
	if (!m_is_dragging) {
		return;
	}

	if (key == 'S') {
		show();
	}

	if (key == 'H') {
		hide();
	}

	if (key == VK_RIGHT) {
		move(10, 0);
	}

	if (key == VK_LEFT) {
		move(-10, 0);
	}

	if (key == VK_UP) {
		move(0, -10);
	}

	if (key == VK_DOWN) {
		move(0, 10);
	}
}

BareTree::~BareTree() {
	DeleteObject(m_pen);
	DeleteObject(m_brush);
}