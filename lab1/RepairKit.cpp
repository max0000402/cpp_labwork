#include "RepairKit.hpp"

RepairKit::RepairKit(int x, int y, COLORREF color) : ABCFigure(x, y, color) {
	m_width = 100;
	m_height = 80;

	m_brush_box = CreateSolidBrush(get_color());
	m_brush_plus = CreateSolidBrush(RGB(255, 0, 0));
}

void RepairKit::draw(HDC& hdc) {
	draw_dragging_rectangle(hdc);

	if (!is_visible()) {
		return;
	}

	int offset_y = 20;
	SelectObject(hdc, m_brush_box);
	SelectObject(hdc, GetStockObject(BLACK_PEN));
	Rectangle(hdc, get_x(), get_y() + offset_y, get_x() + 100, get_y() + offset_y + 60);

	SelectObject(hdc, m_brush_plus);
	SelectObject(hdc, GetStockObject(NULL_PEN));

	int width = 10;
	int height = 40;
	int center_x = get_x() + 50;
	int center_y = get_y() + 30 + offset_y;
	Rectangle(hdc, center_x - width / 2, center_y - height / 2, center_x + width / 2, center_y + height / 2);

	width = 40;
	height = 10;
	Rectangle(hdc, center_x - width / 2, center_y - height / 2, center_x + width / 2, center_y + height / 2);

	SelectObject(hdc, GetStockObject(BLACK_PEN));
	MoveToEx(hdc, get_x(), get_y() + offset_y, nullptr);
	LineTo(hdc, get_x() + 20, get_y());
	LineTo(hdc, get_x() + 80, get_y());
	LineTo(hdc, get_x() + 100, get_y() + offset_y);
}

void RepairKit::affect(BareTree*& tree) {
	if (!is_figure_intersec(this, tree)) {
		return;
	}

	RepairKitVisitor repair_kit_visitor;
	tree->accept(repair_kit_visitor);
	BareTree* new_tree = repair_kit_visitor.get_result();
	if (tree != new_tree) {
		delete tree;
	}
	tree = new_tree;
}

RepairKit::~RepairKit() {
	DeleteObject(m_brush_box);
	DeleteObject(m_brush_plus);
}