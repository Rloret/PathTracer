#include <iostream>
#include "../HeaderFiles/PathTracer.h"

int main() {
	std::cout << "Hello World" << std::endl;
	PathTracer PT = PathTracer();
	PT.TraceRays();

	std::cin.get();
}