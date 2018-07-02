#pragma once
#include "Cell.h"
class TallCell
{
public:
	TallCell();
	~TallCell();

protected:
	int height;

	Vec3 topVelocity;
	Vec3 topLevelSet;
	float topPressure;

	Vec3 bottomVelocity;
	Vec3 bottomLevelSet;
	float bottomPressure;
};

