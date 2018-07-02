#pragma once

#include "Vec3.h"


class Cell
{
public:
	Cell();
	~Cell();

	protected: 
		float dim;
		Vec3 velocity;
};

