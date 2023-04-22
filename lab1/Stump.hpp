#pragma once
#include "BareTree.hpp"

class Stump : public BareTree {
private:
	HBRUSH m_brush;
public:
	Stump(int x, int y, COLORREF color);
	void draw(HDC& hdc) override;
	int get_width() override;
	int get_height() override;
	~Stump() override;
};