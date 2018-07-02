#pragma once
class Vec3
{
public:
	Vec3();
	Vec3(float x, float y, float z);
	~Vec3();
	
	float getX() const;
	float getY() const;
	float getZ() const;
	
	void setX(float x);
	void setY(float y);
	void setZ(float z);
	
	float length() const;

	Vec3 operator+ (const Vec3&) const;
	Vec3 operator- (const Vec3&) const;
	Vec3 operator* (const float) const;
	Vec3 operator/ (const float) const;

	Vec3 normalize() const;
	Vec3 normalize(const Vec3&) const;
	void normalized();

	float dot(const Vec3&) const;

	Vec3 cross(const Vec3&) const;

protected:
	float x;
	float y;
	float z;
};

