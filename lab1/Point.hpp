#pragma once

#include <windows.h>
#include "Location.hpp"

class Point : public Location {
private:
	bool m_is_visible;
	COLORREF m_color;
public:
	Point(int x, int y, COLORREF color);

	virtual void draw(HDC& hdc);

	virtual void process_key_down(WPARAM key);

	virtual void process_left_mouse_down(POINT& p);

	virtual void process_right_mouse_down(POINT& p);

	bool is_visible();

	void hide();

	void show();

	COLORREF get_color();

	virtual ~Point() = default;
};