#include "Cretures.h"
#pragma once

class Predator : public Cretures
{
public:

	Predator()
	{
		time_of_live = 10;
		hunger = 5;
		type = 2;
	}
};

