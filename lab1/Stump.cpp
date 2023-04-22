#include "Stump.hpp"

Stump::Stump(int x, int y, COLORREF color) : BareTree(x, y, color) {
	m_brush = CreateSolidBrush(color);
}

void Stump::draw(HDC& hdc) {
	draw_dragging_rectangle(hdc);

	if (!is_visible()) {
		return;
	}

	SelectObject(hdc, GetStockObject(NULL_PEN));
	SelectObject(hdc, m_brush);

	POINT poly[13];

	poly[0].x = get_x() + 20;
	poly[0].y = get_y() + 10;

	poly[1].x = get_x() + 20;
	poly[1].y = get_y() + 40;

	poly[2].x = get_x();
	poly[2].y = get_y() + 55;

	poly[3].x = get_x() + 20;
	poly[3].y = get_y() + 60;

	poly[4].x = get_x() + 17;
	poly[4].y = get_y() + 70;

	poly[5].x = get_x() + 30;
	poly[5].y = get_y() + 63;

	poly[6].x = get_x() + 40;
	poly[6].y = get_y() + 63;

	poly[7].x = get_x() + 48;
	poly[7].y = get_y() + 73;

	poly[8].x = get_x() + 55;
	poly[8].y = get_y() + 71;

	poly[9].x = get_x() + 52;
	poly[9].y = get_y() + 65;

	poly[10].x = get_x() + 82;
	poly[10].y = get_y() + 65;

	poly[11].x = get_x() + 68;
	poly[11].y = get_y() + 50;

	poly[12].x = get_x() + 60;
	poly[12].y = get_y() + 10;

	Polygon(hdc, poly, 13);
}

int Stump::get_width() {
	return 82;
}

int Stump::get_height() {
	return 73;
}

void Stump::accept(ITreeVisitor& visitor) {
	visitor.VisitStump(this);
}

Stump::~Stump() {
	DeleteObject(m_brush);
}