#pragma once
class vec3
{
public:
	vec3();
	vec3(float x, float y, float z);
	~vec3();
	
	float getX() const;
	float getY() const;
	float getZ() const;
	
	void setX(float x);
	void setY(float y);
	void setZ(float z);
	
	float length() const;

	vec3 operator+ (const vec3&) const;
	vec3 operator- (const vec3&) const;
	vec3 operator* (const float) const;
	vec3 operator/ (const float) const;

	vec3 normalize() const;
	vec3 normalize(const vec3&) const;
	void normalized();

	float dot(const vec3&) const;

	vec3 cross(const vec3&) const;

protected:
	float x;
	float y;
	float z;
};

