#include "bst.hpp"
#include <iostream>

int main()
{
	BST b;
	std::cout << "Instantiated BST." << std::endl;

	b.add(4);
	b.add(3);
	b.add(5);
	b.add(1);
	b.add(2);
	b.add(6);

	std::cout << "min: " << b.getMin() << std::endl;
	std::cout << "max: " << b.getMax() << std::endl;

	b.printInOrder();
	b.printPostOrder();

	std::cout << "Tree size = " << b.size() << std::endl;
	std::cout << "Max Depth = " << b.maxDepth() << std::endl;
}
