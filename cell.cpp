#include "stdafx.h"
#include "Cell.h"


Cell::Cell()
{
}

Cell::Cell(Vec3 velocity, Vec3 levelSet, float pressure) {
	this->velocity = velocity;
	this->levelSet = levelSet;
	this->pressure = pressure;
	terrainType = TERRAIN_WATER;
}

Cell::Cell(Vec3 velocity, Vec3 levelSet, float pressure, int terrainType) {
	this->velocity = velocity;
	this->levelSet = levelSet;
	this->pressure = pressure;
	this->terrainType = terrainType;
}

Cell::Cell(int terrainType) {
	this->terrainType = terrainType;
}
Cell::~Cell()
{
}

Vec3 Cell::getVelocity() const {
	return velocity;
}
Vec3 Cell::getLevelSet() const {
	return levelSet;
}
float Cell::getPressure() const {
	return pressure;
}
int Cell::getTerrainType() const {
	return terrainType;
}

void Cell::setVelocity(Vec3 v) {
	velocity = v;
}
void Cell::setLevelSet(Vec3 l) {
	levelSet = l;
}
void Cell::setPressure(float p) {
	pressure = p;
}
void Cell::setTerrainType(int t) {
	terrainType = t;
}

Cell Cell::interpolate(Cell c, float weight) const{
	Vec3 v = c.getVelocity() * weight + velocity * (1 - weight);
	Vec3 l = c.getLevelSet() * weight + levelSet * (1 - weight);
	float p = c.getPressure() * weight + pressure * (1 - weight);
	return Cell(v, l, p);
}