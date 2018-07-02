#include "stdafx.h"
#include "Cell.h"


Cell::Cell()
{
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
bool Cell::getTerrainFlag() const {
	return terrainFlag;
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
void Cell::setTerrainFlag(bool t) {
	terrainFlag = t;
}

Cell Cell::interpolate(Cell c, float weight) const{
	Cell retVal = Cell();
	retVal.setVelocity = c.getVelocity * weight + velocity * (1 - weight);
	retVal.setLevelSet = c.getLevelSet * weight + levelSet * (1 - weight);
	retVal.setPressure = c.getPressure * weight + pressure * (1 - weight);
	return retVal;
}