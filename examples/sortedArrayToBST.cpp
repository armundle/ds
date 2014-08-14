#include <iostream>

struct node{
	int key;
	node* left;
	node* right;
}

node* sArrayToBST(int path[], int length);

int main()
{
	int arr[] = {1,2,3,4,5,6};
	int length = 6;

	node* root = sArrayToBST(path, 0, length);

	return 0;

}


node* sArrayToBST(int path[], int first, int length)
{
	if(length == 0)
		return NULL;

	int mid = (length - first)/2;
	int value = path[mid];

	node* root = new(node);
	root->key = value;
	
	root->left = sArrayToBST(path, 0, mid);//elements in the left half 
	root->right = sArrayToBST(path, mid, length)//elements in the right half
		
	return root;
}
