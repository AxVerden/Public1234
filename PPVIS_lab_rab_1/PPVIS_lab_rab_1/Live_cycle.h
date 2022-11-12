#include <iostream>
#include <vector>
#include "Herbivores.h"
#include "Predator.h"
#include "Cretures.h"
#pragma once

using namespace std;

class Live_cycle
{
public:
	bool reproduction(vector<Herbivores>& a, int x, int y)
	{
		for (int i = 0; i < a.size(); i++)
		{
			if (a[i].get_x() == x && a[i].get_y() == y)
			{
				cout << "breeding happened" << endl;
			}
		}
		return 0;
	}

	bool reproduction(vector<Predator>& a, int x, int y)
	{
		for (int i = 0; i < a.size(); i++)
		{
			if (a[i].get_x() == x && a[i].get_y() == y)
			{
				cout << "Breedin happend" << endl;
			}
		}
	}

	void can_eat(vector<Herbivores>& herb)
	{
		for (int i = 0; i < herb.size(); i++)
		{
			if (herb[i].get_type() == 3 && herb[i].get_type() == 3)
			{
				hunger = herb[i].get_hunger();
				herb[i].set_hunger(hunger);
				cout << "Eat happened" << endl;
			}
		}
	}

	void can_eat(vector<Predator>& pred)
	{
		for (int i = 0; i < pred.size(); i++)
		{
			if (pred[i].get_type() == 2 && pred[i].get_type() == 2)
			{
				hunger = pred[i].get_hunger();
				pred[i].set_hunger(hunger);
				cout << "Eat happened" << endl;
			}
		}
	}

private:
	int hunger;
};

