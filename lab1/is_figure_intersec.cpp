#include "is_figure_intersec.hpp"

bool is_figure_intersec(ABCFigure* f1, ABCFigure* f2) {
	int x0 = f1->get_x();
	int y0 = f1->get_y();
	int x1 = f1->get_x() + f1->get_width();
	int y1 = f1->get_y() + f1->get_height();

	int x2 = f2->get_x();
	int y2 = f2->get_y();
	int x3 = f2->get_x() + f2->get_width();
	int y3 = f2->get_y() + f2->get_height();

	return !(x0 > x3 || x1 < x2 || y0 > y3 || y1 < y2);
}