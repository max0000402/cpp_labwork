#include "ABCFigure.hpp"

ABCFigure::ABCFigure(int x, int y, COLORREF color) : Location(x, y) {
	m_is_visible = true;
	m_is_dragging = false;

	m_width = 0;
	m_height = 0;

	m_color = color;
}

void ABCFigure::draw_dragging_rectangle(HDC& hdc) {
	if (m_is_dragging) {
		SelectObject(hdc, GetStockObject(BLACK_PEN));
		SelectObject(hdc, GetStockObject(NULL_BRUSH));
		Rectangle(hdc, get_x(), get_y(), get_x() + m_width, get_y() + m_height);
	}
}

void ABCFigure::process_left_mouse_down(POINT& p) {
	if (p.x >= get_x() && p.x <= get_x() + m_width && p.y >= get_y() && p.y <= get_y() + m_height) {
		m_is_dragging = !m_is_dragging;
	}
}

void ABCFigure::process_key_down(WPARAM key) {
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

int ABCFigure::get_width() {
	return m_width;
}

int ABCFigure::get_height() {
	return m_height;
}

bool ABCFigure::is_visible() {
	return m_is_visible;
}

void ABCFigure::hide() {
	m_is_visible = false;
}

void ABCFigure::show() {
	m_is_visible = true;
}

COLORREF ABCFigure::get_color() {
	return m_color;
}