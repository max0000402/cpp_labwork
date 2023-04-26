#pragma once

#include "BareTree.hpp"

class Fir : public BareTree {
private:
	HBRUSH m_brush;
public:
	Fir(int x, int y, COLORREF color);
	void draw(HDC& hdc) override;
	void accept(ITreeVisitor& visitor) override;
	~Fir() override;
};