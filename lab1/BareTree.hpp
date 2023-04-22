#pragma once

#include "Point.hpp"

class BareTree : public Point {
private:
	HBRUSH m_brush;
	HPEN m_pen;
protected:
	bool m_is_dragging;
	virtual void draw_dragging_rectangle(HDC& hdc);
public:
	BareTree(int x, int y, COLORREF color);
	void draw(HDC& hdc) override;
	void process_left_mouse_down(POINT &p) override;
	void process_key_down(WPARAM key) override;
	virtual int get_width();
	virtual int get_height();
	~BareTree() override;
};