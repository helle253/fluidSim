#pragma once

#include "Vec3.h"


class Cell
{
public:
	Cell();
	~Cell();

	Vec3 getVelocity() const;
	Vec3 getLevelSet() const;
	float getPressure() const;

	void setVelocity(Vec3 v);
	void setLevelSet(Vec3 l);
	void setPressure(float p);

	private: 
		Vec3 velocity;
		Vec3 levelSet;
		float pressure;
};

