#pragma once

#include "IDrawable.hpp"
#include "IControllable.hpp"
#include "Location.hpp"

class ABCFigure : public Location, public IDrawable, public IControlable {
private:
	bool m_is_visible;
	COLORREF m_color;
protected:
	bool m_is_dragging;
	int m_width;
	int m_height;
	virtual void draw_dragging_rectangle(HDC& hdc);
public:
	ABCFigure(int x, int y, COLORREF color);
	void process_key_down(WPARAM key) override;
	void process_left_mouse_down(POINT& p) override;
	bool is_visible() override;
	void hide() override;
	void show() override;
	int get_width() override;
	int get_height() override;
	COLORREF get_color() override;
	virtual ~ABCFigure() = default;
};