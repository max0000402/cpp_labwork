#pragma once
#include "Tree.hpp"

class AppleTree : public Tree {
private:
	COLORREF m_color_apple;
	HBRUSH m_brush_apple;
public:
	AppleTree(int x, int y, COLORREF color, COLORREF color_lead, COLORREF color_apple);
	void draw(HDC& hdc) override;
	void accept(ITreeVisitor& visitor) override;
	~AppleTree() override;
};