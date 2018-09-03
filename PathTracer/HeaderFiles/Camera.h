#pragma once
#include "../HeaderFiles/Vector3.h"

class Ray;
class Camera {

public:
	float m_FOVy;
	///@FOVY: the FOV measured in angles in the  
	Camera(float FOVy);
	
	void Move(Vector3 NewPosition);
	void LookAt(Vector3 Target);

	Vector3 GetCameraRayDirection(int i, int j, float AR);
	Vector3 GetCOP();
	Vector3 GetForward();
	Vector3 GetRight();
	Vector3 GetUp();

private:
	Vector3 m_Forward, m_Right,m_Up,m_COP,m_Target;
	void generateBasis();
};