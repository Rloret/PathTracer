#include "..\HeaderFiles\Camera.h"

#define _USE_MATH_DEFINES
#include <math.h>
#define DEG2RAD(Deg) ((Deg) * M_PI / 180.0)

Camera::Camera(float FOVy)
{
	m_FOVy = DEG2RAD(FOVy);
	Move(Vector3(0, 0, 0));
	LookAt(Vector3(0, 0, -1));
	generateBasis();
}

void Camera::Move(Vector3 NewPosition)
{
	m_COP = NewPosition;
	generateBasis();
}

void Camera::LookAt(Vector3 Target)
{
	m_Target = Target;
	generateBasis();
}

Vector3 Camera::GetCameraRayDirection(int i, int j,float AR)
{
	//We scale the basis vectors to accomodate to FOV + Aspect Ratio
	return  m_Right * (i * atan(m_FOVy / 2) * AR) + m_Up * (i * atan(m_FOVy / 2));
}

Vector3 Camera::GetCOP()
{
	return m_COP;
}

Vector3 Camera::GetForward()
{
	return m_Forward;
}

Vector3 Camera::GetRight()
{
	return m_Right;
}

Vector3 Camera::GetUp()
{
	return m_Up;
}

void Camera::generateBasis()
{
	m_Forward = (m_COP - m_Target).normalized();
	Vector3 tmpUp = Vector3(0, 1, 0);

	m_Right = (tmpUp.cross(m_Forward)).normalized();
	m_Up = (m_Forward.cross(m_Right)).normalized();
}
