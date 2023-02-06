#include "Value.h"
#include "helper.h"
#include <iostream>
#include <Windows.h>


int main()
{
	// For tree pretty printing on Windows
	SetConsoleOutputCP(CP_UTF8);

	Value v(3.5);
	Value w(2);
	Value x = v + w;
	Value y = v * w;
	Value o = x + y;
	std::cout << o.prev.first->data << std::endl;

	printBT("", &o, false);
}
