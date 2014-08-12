#include "list.hpp"
#include <iostream>

int main()
{
	list<int> l1;


	l1.pushFront(-1);
	l1.pushFront(-1);
	std::cout << "length l1: " << l1.len() << std::endl;

	//list<int> l2 = l1;
	//std::cout << "length: " << l2.len() << std::endl;

	//list<int> l3(l1);
	//std::cout << "length: " << l3.len() << std::endl;

	//list<int> l4;
	//l4 = l1;

	l1.pushFront(-1);
	l1.pushFront(-1);
	l1.pushFront(-1);
	//l2.pushFront(1);
	//l2.pushFront(1);
	//l3.pushFront(1);
	std::cout << "length l1: " << l1.len() << std::endl;
	//std::cout << "length l2: " << l2.len() << std::endl;
	//std::cout << "length l3: " << l3.len() << std::endl;
	//std::cout << "length l4: " << l4.len() << std::endl;

	l1.pushBack(-2);
	l1.pushBack(-2);
	l1.pushBack(-2);
	l1.pushBack(-2);
	l1.insert(2,2);
	l1.insert(0,0);
	std::cout << "length l1: " << l1.len() << std::endl;

	l1.printList();
}
