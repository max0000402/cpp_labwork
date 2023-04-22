#pragma once

#include "Point.hpp"

class Axe : public Point {
private:
	HBRUSH m_brush_axe;
	HBRUSH m_brush_stick;
	HPEN m_pen_string;
public:
	Axe(int x, int y, COLORREF color);
	void draw(HDC& hdc) override;
	~Axe() override;
};