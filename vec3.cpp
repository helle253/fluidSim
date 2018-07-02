#include "stdafx.h"
#include "Vec3.h"
#include <cmath>

Vec3::Vec3()
{
	x = 0;
	y = 0;
	z = 0;
}

Vec3::Vec3(float x, float y, float z) {
	this->x = x;
	this->y = y;
	this->z = z;
}

Vec3::~Vec3()
{
}

float Vec3::getX() const {
	return x;
}
float Vec3::getY() const {
	return y;
}
float Vec3::getZ() const {
	return z;
}

void Vec3::setX(float x) {
	this->x = x;
}
void Vec3::setY(float y) {
	this->y = y;
}
void Vec3::setZ(float z) {
	this->z = z;
}

float Vec3::length() const {
	return sqrt(x * x + y * y + z * z);
}

Vec3 Vec3::operator+ (Vec3 const& v) const {
	return Vec3(x + v.x, y + v.y, z + v.z);
}
Vec3 Vec3::operator- (Vec3 const& v) const {
	return Vec3(x - v.x, y - v.y, z - v.z);
}
Vec3 Vec3::operator* (float const f) const {
	return Vec3(x * f, y * f, z * f);
}
Vec3 Vec3::operator/ (float const f) const {
	return Vec3(x / f, y / f, z / f);
}

Vec3 Vec3::normalize() const {
	float len = length();
	return Vec3(x / len, y / len, z / len);
}
Vec3 Vec3::normalize(const Vec3& v) const {
	float len = v.length();
	return Vec3(v.x / len, v.y / len, v.z / len);
}
void Vec3::normalized() {
	float len = length();
	x /= len;
	y /= len;
	z /= len;
}

float Vec3::dot(const Vec3& v) const{
	return x * v.x + y * v.y + z * v.z;
}

Vec3 Vec3::cross(const Vec3& v) const {
	float x = this->y * v.z - this->z * v.y;
	float y = this->z * v.x - this->x - v.z;
	float z = this->x * v.y - this->y - v.x;
	return Vec3(x, y, z);
}