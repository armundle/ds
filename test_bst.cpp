#include "bst.hpp"
#include <iostream>

int main()
{
	BST b;
	std::cout << "Instantiated BST." << std::endl;

	b.add(4);
	b.add(5);
	b.add(2);
	b.add(1);
	b.add(3);
	b.add(6);

	std::cout << "min: " << b.getMin() << std::endl;
	std::cout << "max: " << b.getMax() << std::endl;

	std::cout << "In Order traversal of nodes: " << std::endl;
	b.printInOrder();
	std::cout << "Post Order traversal of nodes: " << std::endl;
	b.printPostOrder();

	std::cout << "Tree size = " << b.size() << std::endl;
	std::cout << "Max Depth = " << b.maxDepth() << std::endl;

	std::cout << "Tree has sum 7: " << b.hasPathSum(7) << std::endl;
	std::cout << "Tree has sum 5: " << b.hasPathSum(5) << std::endl;
	std::cout << "Tree has sum 9: " << b.hasPathSum(9) << std::endl;
	std::cout << "Tree has sum 15: " << b.hasPathSum(15) << std::endl;

	std::cout << "All the paths in the tree:" << std::endl;
	b.printAllPaths();
}
