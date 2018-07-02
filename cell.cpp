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

void Cell::setVelocity(Vec3 v) {
	velocity = v;
}
void Cell::setLevelSet(Vec3 l) {
	levelSet = l;
}
void Cell::setPressure(float p) {
	pressure = p;
}