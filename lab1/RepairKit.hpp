#pragma once

#include "Point.hpp"

class RepairKit : public Point {
private:
	HBRUSH m_brush_plus;
	HBRUSH m_brush_box;
public:
	RepairKit(int x, int y, COLORREF color);
	void draw(HDC& hdc) override;
	~RepairKit() override;
};