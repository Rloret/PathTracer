#include "../HeaderFiles/Ray.h"

Ray::Ray(Vector3 Origin, Vector3 Direction)
{
	m_O = Origin;
	m_D = Direction;
}

Ray::~Ray()
{
}

Vector3 Ray::GetPoint(float t)
{
	return m_O + m_D*t;
}
