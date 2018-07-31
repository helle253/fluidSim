#pragma once
#include "Vec3.h"


class Cell
{
public:
	Cell();
	Cell(Vec3 velocity, Vec3 levelSet, float pressure);
	Cell(Vec3 velocity, Vec3 levelSet, float pressure, int terrainType);
	~Cell();

	Vec3 getVelocity() const;
	Vec3 getLevelSet() const;
	float getPressure() const;

	void setVelocity(Vec3 v);
	void setLevelSet(Vec3 l);
	void setPressure(float p);

	/*
	Interpolates between the cells, where cell c is given a weight, and the called 
	cell is weighted 1 - weight
	*/
	Cell interpolate(Cell c, float weight) const;

	private: 
		Vec3 velocity;
		Vec3 levelSet;
		float pressure;
};

