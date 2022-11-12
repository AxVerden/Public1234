#include "Cretures.h"
#pragma once

class Herbivores : public Cretures
{
public:

	Herbivores()
	{
		time_of_live = 15;
		hunger = 7;
		type = 1;
	}
};

