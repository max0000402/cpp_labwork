#include "Fir.hpp"

Fir::Fir(int x, int y, COLORREF color) : BareTree(x, y, color) {
	m_brush = CreateSolidBrush(color);
}

void Fir::draw(HDC& hdc) {
	draw_dragging_rectangle(hdc);

	if (!is_visible()) {
		return;
	}

	SelectObject(hdc, GetStockObject(NULL_PEN));
	SelectObject(hdc, m_brush);

	POINT poly[11];

	poly[0].x = get_x() + 30;
	poly[0].y = get_y();

	poly[1].x = get_x() + 50;
	poly[1].y = get_y() + 25;

	poly[2].x = get_x() + 40;
	poly[2].y = get_y() + 20;

	poly[3].x = get_x() + 60;
	poly[3].y = get_y() + 50;

	poly[4].x = get_x() + 40;
	poly[4].y = get_y() + 40;

	poly[5].x = get_x() + 40;
	poly[5].y = get_y() + 70;

	poly[6].x = get_x() + 20;
	poly[6].y = get_y() + 70;

	poly[7].x = get_x() + 20;
	poly[7].y = get_y() + 40;

	poly[8].x = get_x();
	poly[8].y = get_y() + 50;

	poly[9].x = get_x() + 20;
	poly[9].y = get_y() + 20;

	poly[10].x = get_x() + 10;
	poly[10].y = get_y() + 25;

	Polygon(hdc, poly, 11);
}

int Fir::get_width() {
	return 60;
}

int Fir::get_height() {
	return 70;
}

void Fir::accept(ITreeVisitor& visitor) {
	visitor.VisitFir(this);
}

Fir::~Fir() {
	DeleteObject(m_brush);
}