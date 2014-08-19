//Graph implementation using list
#ifndef GRAPH_H_
#define GRAPH_H_

#include <forward_list>
#include <iostream>

class Graph{

	private:

	struct v;

	struct e{
		struct v* pV;
		int w;
		//do you need a link to the next edge?
		};

	struct v{
		int value;
		std::forward_list<struct e*> cEdge;
		//e* cEdge;
		v* next;
		int visited;
		};

	typedef struct e e;
	typedef struct v v;

	v* root;

	v* newVertex(int value)
	{
		v* newV = new(v);
		newV->value = value;
		newV-> next = NULL;
		newV->visited = 0;

		return newV;
	}

	e* newEdge(v* pV, int w)
	{
		e* newE = new(e);
		newE->pV = pV;
		newE->w = w;

		return newE;
	}

	void unmarkAllVisited()
	{
		if(root == NULL)
			return;
		v* current = root;

		while(current)
		{
			current->visited = 0;
			current = current->next;
		}

	}

	int DFSSearch(v* vi, int i)
	{
		std::cout << "Visiting node " << vi->value << std::endl;
		if(vi->visited)
			return 0;
		
		vi->visited = 1;

		if(vi->value == i)
			return 1;

		std::forward_list<e*>::iterator it;

		for ( it = vi->cEdge.begin(); it != vi->cEdge.end(); it++ )
		{
			std::cout << "Might visit " << ((*it)->pV)->value << std::endl;
			if(!((*it)->pV)->visited){
				std::cout << "Going to visit " << ((*it)->pV)->value << std::endl;
				if(DFSSearch((*it)->pV, i))
					return 1;
				}
		}

		return 0;
	}
			


	int isReachableGraph(v* i, v* j);

	int _nVertices;
	int _mEdges;

	public:

	Graph();
	~Graph();
	void addVertex(int value);
	int addEdge(int i, int j, int w);
	int isReachable(int j);
	int getNumberOfVertices();
	int getNumberOfEdges();
	void printAllVertices();
	int DFS(int i);
	int BFS(int i);
};

//Implementation

Graph::Graph()
{
	root = NULL;
	_nVertices = 0;
	_mEdges = 0;
}

Graph::~Graph()
{
	root = NULL;
}

void Graph::addVertex(int value)
{
	if(root == NULL)
	{
		root = newVertex(value);
		_nVertices++;
		return;
	}
	
	v* currentVertex = root;
	while(currentVertex->next)
	{
		currentVertex = currentVertex->next;
	}

	currentVertex->next = newVertex(value);

	_nVertices++;
}

int Graph::addEdge(int i, int j, int w)
{
	if(i >= _nVertices || j >= _nVertices)
		return 0;

	//temp counter for finding vertices
	int index = 0;
	
	v* vi = root;
	v* vj = root;

	while(index < i)
	{
		vi = vi->next;
		index++;
	}//vi now points to the ith vertex

	//reset index for vertex j
	index = 0;
	while(index < j)
	{
		vj = vj->next;
		index++;
	}//vj points to the jth vertex
	
	//since source, target, w
	e* edge = newEdge(vj,w);
	vi->cEdge.push_front(edge);

	_mEdges++;

	return 1;

}

int Graph::isReachable(int j)
{
	if(j >= _nVertices)
		return 0;

	unmarkAllVisited();

	int index = 0;
	v* vj = root;

	while(index < j)
	{
		vj = vj->next;
		index++;
	}

	return isReachableGraph(root, vj);

}

int Graph::isReachableGraph(v* vi, v* vj)
{
	//if the vertex has already been visited, fail
	if(vi->visited)
		return 0;
	vi->visited = 1;
	//if this is the vertex we are looking for, return success
	if(vi == vj)
		return 1;
	//if this vertex does not have any edge, return fail
	if(vi->cEdge.empty())
		return 0;
	
	
	std::forward_list<e*>::iterator it;

	for ( it = vi->cEdge.begin(); it != vi->cEdge.end(); it++ )
	{
		if(isReachableGraph((*it)->pV, vj))
			return 1;
	}
	return 0;

}

void Graph::printAllVertices()
{
	v* current = root;
	while(current)
	{
		std::cout << current->value << std::endl;
		current = current->next;
	}
}

int Graph::getNumberOfVertices()
{
	return _nVertices;
}

int Graph::getNumberOfEdges()
{
	return _mEdges;
}

int Graph::DFS(int i)
{
	if(root == NULL)
		return 0;

	unmarkAllVisited();

	v* current = root;
	while(current)
	{
		if(DFSSearch(current, i))
			return 1;

		current = current->next;
	}

	return 0;


}
	
#endif //GRAPH__H
