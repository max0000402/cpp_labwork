#include "AppleTree.hpp"

AppleTree::AppleTree(int x, int y, COLORREF color, COLORREF color_leaf, COLORREF color_apple) : Tree(x, y, color, color_leaf) {
	m_color_apple = color_apple;
	m_brush_apple = CreateSolidBrush(m_color_apple);
}

void AppleTree::draw(HDC& hdc) {
	if (!is_visible()) {
		return;
	}

	Tree::draw(hdc);

	SelectObject(hdc, m_brush_apple);
	SelectObject(hdc, GetStockObject(NULL_PEN));

	int offset_x, offset_y;

	offset_x = 10;
	offset_y = 12;
	Ellipse(hdc, get_x() + offset_x, get_y() + offset_y, get_x() + offset_x + 8, get_y() + offset_y + 8);

	offset_x = 24;
	offset_y = 22;
	Ellipse(hdc, get_x() + offset_x, get_y() + offset_y, get_x() + offset_x + 8, get_y() + offset_y + 8);

	offset_x = 12;
	offset_y = 28;
	Ellipse(hdc, get_x() + offset_x, get_y() + offset_y, get_x() + offset_x + 8, get_y() + offset_y + 8);

	offset_x = 28;
	offset_y = 36;
	Ellipse(hdc, get_x() + offset_x, get_y() + offset_y, get_x() + offset_x + 8, get_y() + offset_y + 8);
}

void AppleTree::accept(ITreeVisitor& visitor) {
	visitor.VisitAppleTree(this);
}

AppleTree::~AppleTree() {
	DeleteObject(m_brush_apple);
}