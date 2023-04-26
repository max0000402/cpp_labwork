#pragma once

#include "IAffectable.hpp"
#include "RepairKitVisitor.hpp"
#include "is_figure_intersec.hpp"

class RepairKit : public ABCFigure, public IAffectable<BareTree> {
private:
	HBRUSH m_brush_plus;
	HBRUSH m_brush_box;
public:
	RepairKit(int x, int y, COLORREF color);
	void draw(HDC& hdc) override;
	void affect(BareTree*& tree) override;
	~RepairKit() override;
};