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
				insert(r->left, n);
			else
				r->left = n;
			return;
		}
		else
		{
			if(r->right)
				insert(r->right, n);
			else
				r->right = n;
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

	void postOrder(node* n)
	{
		if(n == NULL)
			return;

		std::cout << n->key << std::endl;
		inOrder(n->left);
		inOrder(n->right);
	}

	unsigned int sizeTree(node* node)
	{
		if(node==NULL)
			return 0;

		unsigned int size = 1;
		if(node->left)
			size = size + sizeTree(node->left);

		if(node->right)
			size = size + sizeTree(node->right);

		return size;
	}

	unsigned int maxDepthTree(node* n)
	{
		if(n == NULL)
			return 0;

		unsigned int d = 1;

		if(n->left && n->right)
		{
			unsigned int ld = maxDepthTree(n->left);
			unsigned int rd = maxDepthTree(n->right);
			return ((ld >= rd ) ? d + ld : d + rd);
		}

		else if (n->left && !n->right)
		{
			return (d + maxDepthTree(n->left));
		}
		else if (n->right && !n->left)
		{
			return (d + maxDepthTree(n->right));
		}
		else
			return d;
	}

	
	public:

	BST();
	~BST();

	void add(int key);
	int getMin();
	int getMax();
	void printInOrder();
	void printPostOrder();
	unsigned int size();
	unsigned int maxDepth();

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
		return 0;
	}
	
	node* currentNode = root;

	while(currentNode->left)
	{
		currentNode = currentNode->left;
	}

	return currentNode->key;
}

int BST::getMax()
{ if(root == NULL)
	{
		return 0;
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

void BST::printPostOrder()
{
	if(root == NULL)
		return;
	
	postOrder(root);
}

unsigned int BST::size()
{
	if(root == NULL)
		return 0;

	return sizeTree(root);

}

unsigned int BST::maxDepth()
{
	if(root == NULL)
		return 0;

	return maxDepthTree(root);
}
