#include "Value.h"
#include <iostream>

int main()
{
	Value v(3.5);
	Value w(2);
	Value x = v + w;
	Value y = v * w;
	Value o = x + y;
	std::cout << o << x+y << std::endl;

	for (Value const& v : o.prev) { std::cout << v;}
	std::cout << std::endl;
}
