#include "stdafx.h"
#include "vec3.h"
#include <cmath>

vec3::vec3()
{
	x = 0;
	y = 0;
	z = 0;
}

vec3::vec3(float x, float y, float z) {
	this->x = x;
	this->y = y;
	this->z = z;
}

vec3::~vec3()
{
}

float vec3::getX() const {
	return x;
}
float vec3::getY() const {
	return y;
}
float vec3::getZ() const {
	return z;
}

void vec3::setX(float x) {
	this->x = x;
}
void vec3::setY(float y) {
	this->y = y;
}
void vec3::setZ(float z) {
	this->z = z;
}

float vec3::length() const {
	return sqrt(x * x + y * y + z * z);
}

vec3 vec3::operator+ (vec3 const& v) const {
	return vec3(x + v.x, y + v.y, z + v.z);
}
vec3 vec3::operator- (vec3 const& v) const {
	return vec3(x - v.x, y - v.y, z - v.z);
}
vec3 vec3::operator* (float const f) const {
	return vec3(x * f, y * f, z * f);
}
vec3 vec3::operator/ (float const f) const {
	return vec3(x / f, y / f, z / f);
}

vec3 vec3::normalize() const {
	float len = length();
	return vec3(x / len, y / len, z / len);
}
vec3 vec3::normalize(const vec3& v) const {
	float len = v.length();
	return vec3(v.x / len, v.y / len, v.z / len);
}
void vec3::normalized() {
	float len = length();
	x /= len;
	y /= len;
	z /= len;
}

float vec3::dot(const vec3& v) const{
	return x * v.x + y * v.y + z * v.z;
}

vec3 vec3::cross(const vec3& v) const {
	float x = this->y * v.z - this->z * v.y;
	float y = this->z * v.x - this->x - v.z;
	float z = this->x * v.y - this->y - v.x;
	return vec3(x, y, z);
}