#pragma once

class Cretures
{
public:
	int get_type() { return type; }
	int get_time_of_live() { return time_of_live; }
	int get_hunger() { return hunger; }
	int get_x() { return x; }
	int get_y() { return y; }

	void set_type(int type) { this->type = type; }
	void set_x(int x) { this->x = x; }
	void set_y(int y) { this->y = y; }
	void set_hunger(int hunger) { this->hunger = hunger + 1; }

protected:
	int time_of_live;
	int hunger;
	int type;
	int x;
	int y;
};

