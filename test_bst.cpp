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

	std::cout << "min: " << b.getMin() << std::endl;
	std::cout << "max: " << b.getMax() << std::endl;

	b.printInOrder();
	b.printPostOrder();
}
