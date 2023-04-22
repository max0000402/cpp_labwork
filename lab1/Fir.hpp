#pragma once

#include "BareTree.hpp"

class Fir : public BareTree {
private:
	HBRUSH m_brush;
public:
	Fir(int x, int y, COLORREF color);
	void draw(HDC& hdc) override;
	int get_width() override;
	int get_height() override;
	void accept(ITreeVisitor& visitor) override;
	~Fir() override;
};