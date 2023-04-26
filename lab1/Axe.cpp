#include "Axe.hpp"

Axe::Axe(int x, int y, COLORREF color) : ABCFigure(x, y, color) {
	m_width = 30;
	m_height = 80;

	m_brush_stick = CreateSolidBrush(get_color());
	m_brush_axe = CreateSolidBrush(RGB(127, 127, 127));
	m_pen_string = CreatePen(PS_SOLID, 1, RGB(252, 218, 191));
}

void Axe::draw(HDC& hdc) {
	draw_dragging_rectangle(hdc);

	if (!is_visible()) {
		return;
	}

	SelectObject(hdc, m_brush_stick);
	SelectObject(hdc, GetStockObject(BLACK_PEN));
	Rectangle(hdc, get_x(), get_y(), get_x() + 10, get_y() + 80);

	SelectObject(hdc, m_brush_axe);

	POINT poly[3];

	poly[0].x = get_x();
	poly[0].y = get_y() + 20;

	poly[1].x = get_x() + 30;
	poly[1].y = get_y();

	poly[2].x = get_x() + 30;
	poly[2].y = get_y() + 40;

	Polygon(hdc, poly, 3);

	SelectObject(hdc, m_pen_string);
	MoveToEx(hdc, get_x(), get_y() + 13, nullptr);
	LineTo(hdc, get_x() + 10, get_y() + 28);

	MoveToEx(hdc, get_x() + 10, get_y() + 13, nullptr);
	LineTo(hdc, get_x(), get_y() + 28);
}

Axe::~Axe() {
	DeleteObject(m_brush_axe);
	DeleteObject(m_brush_stick);
	DeleteObject(m_pen_string);
}

void Axe::affect(BareTree*& tree) {
	if (!is_figure_intersec(this, tree)) {
		return;
	}

	AxeVisitor axe_visitor;
	tree->accept(axe_visitor);
	BareTree* new_tree = axe_visitor.get_result();
	if (tree != new_tree) {
		delete tree;
	}
	tree = new_tree;
}