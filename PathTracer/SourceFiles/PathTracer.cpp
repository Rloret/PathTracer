#include "..\HeaderFiles\PathTracer.h"
#include "..\HeaderFiles\Image.h"
#include "..\HeaderFiles\Camera.h"
#include "..\HeaderFiles\Ray.h"

#include <iostream>
PathTracer::PathTracer()
{
	m_Img = new Image(100, 50);
	m_Camera = new Camera(60);


}

void PathTracer::TraceRays()
{
	float width = m_Img->GetWidth();
	float height = m_Img->GetHeight();
	float AR = width/height;
	for (size_t row = 0; row < height; row++)
	{
		for (size_t col = 0; col < width; col++)
		{
			//We want 0 to width steps normalized in NDC: in range [-1,1]
			//We also want height to 0 steps normalized into NDC.
			// Meaning that we are traversing the image pixels from top left to down right
			float i =	 ((col+0.5 ) / (width)) * 2 - 1;
			float j = 1- ((row+0.5 ) / (height)) * 2;
			
			Ray R(m_Camera->GetCOP(), m_Camera->GetCameraRayDirection(i, j, AR));


		}
	}
}
