#include "Value.h"
#include <iostream>

int main()
{
	std::cout << "Hello CMake." << std::endl;
	Value v(3.5);
	Value w(2);
	Value x = v + w;
	Value y = v * w;
	std::cout << (v + w) * w << std::endl;
	return 0;
}
