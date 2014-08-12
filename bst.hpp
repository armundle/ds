//Binary Search Tree implemenation
#ifndef BST_H_
#define BST_H_

#include <iostream>

class BST{
	
	private:
		struct node{
		int key;
		node* left;
		node* right;
		};

	node* root;

	node* createNode(int key)
	{
		node* newNode = new(node);
		newNode->key = key;
		newNode->left = NULL;
		newNode->right = NULL;

		return newNode;
	}

	void insert(node* r, node* n)
	{

		if(r == NULL)
		{
			r = n;
			return;
		}
		
		if(r->key > n->key)
		{
			if(r->left)
			{
				insert(r->left, n);
			}
			else
			{
				r->left = n;
			}
			return;
		}
		else
		{
			if(r->right)
			{
				insert(r->right, n);
			}
			else
			{
				r->right = n;
				
			}
			return;
		}

	}

	void inOrder(node* n)
	{
		if(n == NULL)
			return;

		inOrder(n->left);
		std::cout << n->key << std::endl;
		inOrder(n->right);
	}
	
	public:

	BST();
	~BST();

	void add(int key);
	int getMin();
	int getMax();
	void printInOrder();

};
#endif //BST_H_

BST::BST()
{
	root = NULL;
}

BST::~BST()
{
	root = NULL;
}

void BST::add(int key)
{
	if(root==NULL)
	{
		root = createNode(key);
		return;
	}
	
	node* n = createNode(key);

	insert(root, n);

	return;
	
}

int BST::getMin()
{
	if(root == NULL)
	{
		return INT_MIN;
	}
	
	node* currentNode = root;

	while(currentNode->left)
	{
		currentNode = currentNode->left;
	}

	return currentNode->key;
}

int BST::getMax()
{
	if(root == NULL)
	{
		return INT_MAX;
	}
	
	node* currentNode = root;

	while(currentNode->right)
	{
		currentNode = currentNode->right;
	}

	return currentNode->key;
}

void BST::printInOrder()
{
	if(root == NULL)
		return;
	
	inOrder(root);
	
}
