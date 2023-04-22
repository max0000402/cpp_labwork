#pragma once

#include "BareTree.hpp"

class Tree : public BareTree {
private:
	COLORREF m_color_leaf;
	HBRUSH m_brush_leaf;
public:
	Tree(int x, int y, COLORREF color, COLORREF color_leaf);
	void draw(HDC& hdc) override;
	void accept(ITreeVisitor& visitor) override;
	virtual COLORREF get_leaf_color();
	~Tree() override;
};