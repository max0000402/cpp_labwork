#include "Location.hpp"

Location::Location(int x, int y) {
	m_x = x;
	m_y = y;
}

void Location::move(int x, int y) {
	m_x += x;
	m_y += y;
}

int Location::get_x() {
	return m_x;
}

int Location::get_y() {
	return m_y;
}