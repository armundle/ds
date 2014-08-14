//Binary Search Tree implemenation
#ifndef BST_H_
#define BST_H_

#include <iostream>

		struct node{
		int key;
		node* left;
		node* right;
		};

class BST{
	
	private:

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

	bool hasPathSumTree(node* node, int sum)
	{
		if(node->left == NULL && node->right == NULL)
		{
			if(node->key == sum)
			{
				return true;
			}
			else
				return false;
		}
		if(node->left)
		{
			if(hasPathSumTree(node->left, sum - node->key))
				return true;
		}
		if(node->right)
		{
				return hasPathSumTree(node->right, sum - node->key);
		}
		
		return false;
	}

	void printPaths(node* node, int path[], int length)
	{
		 path[length] = node->key;
		 length++;

		 //Leaf node
		 if(!node->left && !node->right)
		 {
		 	printArray(path, length);
			return;
		 }

		if(node->left)
		{
			printPaths(node->left, path, length);
		}
		if(node->right)
		{
			printPaths(node->right, path, length);
		}

		return;
	}

	void printArray(int path[], int length)
	{
		for(int i = 0; i < length; i++)
		{
			std::cout << path[i] << " ->";
		}
		std::cout << std::endl;
	}

	void mirrorBST(node* n)
	{
		if(n == NULL)
			return;

		node* nSwap = NULL;
		nSwap = n->left;
		n->left = n->right;
		n->right = nSwap;

		mirrorBST(n->left);
		mirrorBST(n->right);

		return;
	}

	void duplicateBST(node* n)
	{
		if(n == NULL)
			return;

		duplicateBST(n->left);
		duplicateBST(n->right);

		node* nDuplicate = createNode(n->key);
		node* nTemp = n->left;
		n->left = nDuplicate;
		nDuplicate->left = nTemp;

		return;
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
	bool hasPathSum(int sum);
	void printAllPaths();
	void mirror();
	void duplicate();

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

bool BST::hasPathSum(int sum)
{
	if(root == NULL)
		return false;

	return hasPathSumTree(root,sum);
}

void BST::printAllPaths()
{
	if(root == NULL)
		return;

	int path[1000];
	int length = 0;
	
	printPaths(root, path, length);
}

void BST::mirror()
{
	if(root == NULL)
		return;

	mirrorBST(root);
}

void BST::duplicate()
{
	if(root == NULL)
		return;

	duplicateBST(root);

}
