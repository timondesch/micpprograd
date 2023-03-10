#include <iostream>
#include "Value.h"

#pragma execution_character_set( "utf-8" )

// modified code from https://stackoverflow.com/users/1091436/vasilinovikov
void printBT(const std::string& prefix, const Value* node, bool isLeft)
{
	if (node != nullptr)
	{
		std::cout << prefix;

		std::cout << node->operation << (isLeft ? "├──" : "└──");

		// print the value of the node
		std::cout << *node << std::endl;

		// enter the next tree level - left and right branch
		printBT(prefix + (isLeft ? " │   " : "    "), node->prev.first, (node->prev.second != nullptr));
		printBT(prefix + (isLeft ? " │   " : "    "), node->prev.second, false);

	}
}

void printBT(const Value* node)
{
	printBT("", node, false);
}