#include "../src/graph.hpp"
#include <iostream>

int main(void)
{
	Graph g;
	std::cout << "Graph instantiated." << std::endl;

	g.addVertex(2);
	g.addVertex(3);
	g.addVertex(4);
	g.addEdge(0,1,1);
	
	return 0;
}

