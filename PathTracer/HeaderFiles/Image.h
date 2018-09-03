#pragma once
#include "Vector3.h"
#include <vector>
#include <string>
class Image
{
public:
	Image();
	Image(unsigned int width, unsigned int height);
	void SaveImage(const char* filename);
	int ShowImage();
	void SetPixel(int row, int column,Vector3& Color);
	unsigned int GetWidth();
	unsigned int GetHeight();
	double GetAR();
	~Image();

private:
	unsigned int m_Width;
	unsigned int m_Height;
	std::string LastSave;
	std::vector<std::vector<Vector3>> m_PixelValues;

};

