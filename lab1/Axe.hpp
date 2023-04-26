#pragma once

#include "IAffectable.hpp"
#include "AxeVisitor.hpp"
#include "is_figure_intersec.hpp"

class Axe : public ABCFigure, public IAffectable<BareTree> {
private:
	HBRUSH m_brush_axe;
	HBRUSH m_brush_stick;
	HPEN m_pen_string;
public:
	Axe(int x, int y, COLORREF color);
	void draw(HDC& hdc) override;
	void affect(BareTree*& tree) override;
	~Axe() override;
};