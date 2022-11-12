#pragma once
#include <iostream>
using namespace std;

class Plants
{
public:
	Plants()
	{
		satiety = 2;
		type = 0;
		cultivation = 1;
		
	}

	int set_x(int x){return this->x = x;}
	int set_y(int y){return this->y = y;}
	int get_satiety(){return satiety;}
	int get_type(){return type;}
	int get_x() { return x; }
	int get_y() { return y; }


	void cultivation_plant()
	{
		cultivation++;
	}

	void seed_plant(int cultivation)
	{
		if (this->cultivation > 8)
		{
			cout << "Plant droped seeds";
		}
	}

private:
	int cultivation;
	int x;
	int y;
	int satiety;
	int type;
};

