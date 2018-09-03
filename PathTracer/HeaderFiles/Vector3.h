#pragma once
#include <math.h>
class Vector3 {


public:
	float X, Y, Z;
	inline Vector3() {}

	inline Vector3(double  x, double y, double z) {
		X = x; Y = y; Z = z;
	}
	inline Vector3(Vector3 & v) {
		X = v.X;
		Y = v.Y;
		Z = v.Z;
	}

	inline Vector3 operator+ (const Vector3& v) const {
		return Vector3(X + v.X, Y + v.Y, Z + v.Z);
	}
	inline Vector3 operator+= (const Vector3& v){
		X += v.X;
		Y += v.Y; 
		Z += v.Z;
	}
	inline Vector3 operator- (const Vector3& v) const {
		return Vector3(X - v.X, Y - v.Y, Z - v.Z);
	}
	inline Vector3 operator-= (const Vector3& v) {
		X -= v.X;
		Y -= v.Y;
		Z -= v.Z;
	}
	inline Vector3 operator- () const {
		return Vector3(-X ,-Y,-Z);
	}
	inline Vector3 operator^(const Vector3 &v) const
	{
		return Vector3((Y*v.Z - Z*v.Y), (Z*v.X - X*v.Z), (X*v.Y - Y*v.X));
	}
	inline double operator*(const Vector3 &v) const {
		return X*v.X + Y*v.Y + Z*v.Z;
	}
	inline Vector3 operator*(const double &v) const {
		return Vector3(X*v , Y*v,Z*v);
	}
	inline Vector3 operator*= (double v) {
		X *= v;
		Y *= v;
		Z *= v;
	}
	inline Vector3 operator/= (double v) {
		X /= v;
		Y /= v;
		Z /= v;
	}
	inline Vector3 cross(const Vector3 &v) const
	{
		return Vector3((Y*v.Z - Z*v.Y), (Z*v.X - X*v.Z), (X*v.Y - Y*v.X));
	}

	inline double normalize()
	{
		double mod = sqrt(X*X + Y*Y + Z*Z);
		if (mod == 0)
			return 0;

		double imod = 1.0 / mod;
		this->X *= imod;
		this->Y *= imod;
		this->Z *= imod;
		return mod;
	}

	inline Vector3 normalized()
	{
		double mod = sqrt(X*X + Y*Y + Z*Z);
		if (mod == 0)
			return Vector3(0,0,0);

		double imod = 1.0 / mod;
		float x =X*imod;
		float y =Y*imod;
		float z =Z*imod;
		return Vector3(x, y, z);
		
	}
	inline double module() const
	{
		return double(sqrt(X*X + Y*Y + Z*Z));
	}
	inline double module2() const
	{
		return (X*X + Y*Y + Z*Z);
	}
};