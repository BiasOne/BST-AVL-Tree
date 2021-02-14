#pragma once
#include <vector>
#include <exception>
#include <memory>
#include <iostream>

int main()
{
	cop3530::bst <int, int>myTree;
	if (myTree.empty())
		std::cout << "hello" << std::endl;
	myTree.insert(5, 8);
	myTree.insert(6, 22);
	myTree.insert(3, 76);
	return 0;
}