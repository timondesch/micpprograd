#include "Value.h"
#include <iostream>
#include <Windows.h>
#pragma execution_character_set( "utf-8" )


void printBT(const std::string& prefix, const Value* node, bool isLeft)
{
	if (node != nullptr)
	{
		std::cout << prefix;

		std::cout << node->operation << (isLeft ? "├──" : "└──");

		// print the value of the node
		std::cout << *node << std::endl;

		// enter the next tree level - left and right branch
		printBT(prefix + (isLeft ? " │   " : "    "), node->prev.first, true);
		printBT(prefix + (isLeft ? " │   " : "    "), node->prev.second, false);
	}
}

void printBT(const Value* node)
{
	printBT("", node, false);
}


int main()
{
	// For tree pretty printing on Windows
	SetConsoleOutputCP(CP_UTF8);

	Value v(3.5);
	Value w(2);
	Value x = v + w;
	Value y = v * w;
	Value o = x + y;
	//std::cout << o.prev.first->data << std::endl;


	printBT("", &o, false);
}
