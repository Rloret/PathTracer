#include "..\HeaderFiles\Image.h"

#include <string>
#include <fstream>
#include <iostream>
Image::Image()
{
}

Image::Image(unsigned int width, unsigned int height)
{
	m_Width = width;
	m_Height = height;
	LastSave = "";
	m_PixelValues = std::vector<std::vector<Vector3>>(m_Height);
	m_PixelValues.reserve(m_Height);

	for (size_t row = 0; row < m_Height; row++){
		m_PixelValues[row] = std::vector<Vector3>();
		m_PixelValues[row].reserve(m_Width);
	
		for (size_t col = 0; col < m_Width; col++) {
			
			m_PixelValues[row].push_back( Vector3(1,0,0));
		
		}
	}
}

void Image::SaveImage(const char * filepath)
{
	//Lets create a simple ppm
	std::string file = filepath;//"../Results/Result";
	std::string num = std::to_string(0);
	std::string format = ".ppm";
	std::string filename = file + num + format;
	std::ofstream outstream(filename.c_str());
	LastSave = filename;
	outstream.clear();
	outstream << "P3\n" << m_Width << " " << m_Height << "\n255\n";
	for (int row = m_Height - 1; row >= 0; row--)
	{
		for (int col = 0; col < m_Width; col++)
		{
			//Gamma correction
			
			int r = sqrt(m_PixelValues[row][col].X)*255.99;
			int g = sqrt(m_PixelValues[row][col].X)*255.99;
			int b = 0;//sqrt(Color.Z)*255.99;
			outstream << r << " " << g << " " << b << "\n";
		}
	}
	outstream.close();
}

int Image::ShowImage()
{
	std::string viewcmd = "E:/GIMP_2/bin/gimp-2.10.exe";
	std::string cmd = viewcmd + " " + LastSave;
	std::cout << "Executing external command: " << cmd << std::endl;
	return system(cmd.c_str());
}

void Image::SetPixel(int row, int column,Vector3& Colour)
{
	m_PixelValues[row][column] = Colour;
}

unsigned int Image::GetWidth()
{
	return m_Width;
}

unsigned int Image::GetHeight()
{
	return m_Height;
}

double Image::GetAR()
{
	return double(m_Width/m_Height);
}

Image::~Image()
{

}