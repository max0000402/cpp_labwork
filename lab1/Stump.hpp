#pragma once
#include "BareTree.hpp"

class Stump : public BareTree {
private:
	HBRUSH m_brush;
public:
	Stump(int x, int y, COLORREF color);
	void draw(HDC& hdc) override;
	void accept(ITreeVisitor& visitor) override;
	~Stump() override;
};