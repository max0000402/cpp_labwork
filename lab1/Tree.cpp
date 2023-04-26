#include "Tree.hpp"

Tree::Tree(int x, int y, COLORREF color, COLORREF color_leaf) : BareTree(x, y, color) {
	m_color_leaf = color_leaf;
	m_brush_leaf = CreateSolidBrush(m_color_leaf);
}

void Tree::draw(HDC& hdc) {
	draw_dragging_rectangle(hdc);

	if (!is_visible()) {
		return;
	}

	SelectObject(hdc, m_brush_leaf);
	SelectObject(hdc, GetStockObject(NULL_PEN));

	Ellipse(hdc, get_x(), get_y(), get_x() + 40, get_y() + 60);

	BareTree::draw(hdc);
}

void Tree::accept(ITreeVisitor& visitor) {
	visitor.VisitTree(this);
}

COLORREF Tree::get_leaf_color() {
	return m_color_leaf;
}

Tree::~Tree() {
	DeleteObject(m_brush_leaf);
}