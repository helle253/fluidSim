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
	bool getTerrainFlag() const;

	void setVelocity(Vec3 v);
	void setLevelSet(Vec3 l);
	void setPressure(float p);
	void setTerrainFlag(bool t);

	/*
	Interpolates between the cells, where cell c is given a weight, and the called 
	cell is weighted 1 - weight
	*/
	Cell interpolate(Cell c, float weight) const;

	private: 
		Vec3 velocity;
		Vec3 levelSet;
		float pressure;
		bool terrainFlag;
};

