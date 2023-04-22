#include "Point.hpp"

Point::Point(int x, int y, COLORREF color) : Location(x, y) {
	m_is_visible = true;
	m_color = color;
}

void Point::draw(HDC& hdc) {
	if (is_visible()) {
		SetPixel(hdc, get_x(), get_y(), m_color);
		SetPixel(hdc, get_x() + 1, get_y(), m_color);
		SetPixel(hdc, get_x(), get_y() + 1, m_color);
		SetPixel(hdc, get_x() + 1, get_y() + 1, m_color);
	}
}

void Point::process_key_down(WPARAM key) {
	if (key == 'S') {
		show();
	}

	if (key == 'H') {
		hide();
	}

	if (key == VK_RIGHT) {
		move(10, 0);
	}
}

bool Point::is_visible() {
	return m_is_visible;
}

void Point::hide() {
	m_is_visible = false;
}

void Point::show() {
	m_is_visible = true;
}

COLORREF Point::get_color() {
	return m_color;
}

void Point::process_left_mouse_down(POINT& p) {

}

void Point::process_right_mouse_down(POINT& p) {

}