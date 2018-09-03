#pragma once
#include "..\HeaderFiles\Vector3.h"
class Ray
{
	Vector3 m_O;
	Vector3 m_D;
public:
	Ray(Vector3 Origin, Vector3 Direction);
	~Ray();
	Vector3 GetPoint(float t);
private:

};

