#pragma once

class Location {
private:
	int m_x;
	int m_y;
public:
	Location(int x, int y);

	void move(int x, int y);

	int get_x();

	int get_y();
};