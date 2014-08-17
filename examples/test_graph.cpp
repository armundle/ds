#include "../src/graph.hpp"
#include <iostream>

int main(void)
{
	Graph g;
	std::cout << "Graph instantiated." << std::endl;

	g.addVertex(2);
	g.addVertex(3);
	g.addVertex(4);
	g.addVertex(1);
	g.addVertex(9);
	g.addVertex(20);
	g.addEdge(0,1,1);
	g.addEdge(0,2,1);
	g.addEdge(1,2,1);
	g.addEdge(3,4,1);
	g.addEdge(4,3,1);
	g.addEdge(1,5,1);
	g.addEdge(2,5,1);
	
	return 0;
}

