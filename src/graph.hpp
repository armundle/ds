//Graph implementation using list
#ifndef GRAPH_H_
#define GRAPH_H_

#include <forward_list>

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
		//newV->cEdge = new(e);
		//newV->cEdge->pV = NULL;
		//newV->cEdge->w = 0;

		return newV;
	}

	e* newEdge(v* pV, int w)
	{
		e* newE = new(e);
		newE->pV = pV;
		newE->w = w;

		return newE;
	}

	int _nVertices;
	int _mEdges;

	public:

	Graph();
	~Graph();
	void addVertex(int value);
	int addEdge(int i, int j, int w);
	int getNumberOfVertices();
	int getNumberOfEdges();
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
		root = newVertex(value);
	
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
		vi = vi->next;
		index++;
	}//vj points to the jth vertex

	//since source, target, w
	e* edge = newEdge(vj,w);
	vi->cEdge.push_front(edge);

	_mEdges++;

	return 1;

}

int Graph::getNumberOfVertices()
{
	return _nVertices;
}

int Graph::getNumberOfEdges()
{
	return _mEdges;
}
	
#endif //GRAPH__H
