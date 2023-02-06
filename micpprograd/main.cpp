#include "Value.h"
#include "helper.h"
#include <iostream>
#include <Windows.h>


int main()
{
	// For tree pretty printing on Windows
	SetConsoleOutputCP(CP_UTF8);

	Value v(3.5, 'v');
	Value w(2, 'w');
	Value x = v + w; x.label = 'x';
	Value y = v * w; y.label = 'y';
	Value o = x + y; o.label = 'o';
	Value p = o.relu();

	printBT("", &p, false);
}
