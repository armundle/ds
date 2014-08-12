//List implementation
#ifndef LIST_H
#define LIST_H

#include <iostream>

template <typename T>
class list{
	
	private:

	struct node{
	T data;
	node* next;
	};

	public:
	
	list();
	~list();

	list(const list& rhs);

	void pushFront(T value);
	void pushBack(T value);

	unsigned int len();

	bool insert(T data, unsigned int pos);

	void printList();

	private:

	node* head;
	node* tail;
	unsigned int length;

};
#endif

template <typename T>
list<T>::list()
{
	head = NULL;
	tail = head;
	length = 0;
	std::cout << "list constructed" << std::endl;
}

template <typename T>
list<T>::list(const list& rhs)
{
	head = rhs.head;
	std::cout << "copy list constructed" << std::endl;
}

template <typename T>
list<T>::~list()
{
	node* delNode;

	unsigned int count = 0;
	while(head != NULL)
	{
		count ++;
		std::cout << "delIter: " << count << std::endl;
		delNode = head;
		head = delNode->next;
		delete delNode;
	}
}

template <typename T>
void list<T>::pushFront(T value)
{
	node* newNode = new(node);
	newNode->data = value;
	newNode->next = head;
	head = newNode;
	length++;

	if(length==1)
		tail = newNode;
}

template <typename T>
void list<T>::pushBack(T value)
{
	node* newNode = new(node);
	newNode->data = value;
	tail->next = newNode;
	tail = newNode;
	newNode->next = NULL;
	length++;
}

template <typename T>
unsigned int list<T>::len()
{
	return length;
}

template <typename T>
bool list<T>::insert(T data, unsigned int pos)
{
	if(pos > length)
		return false;

	if(length == 0 || pos == 0)
	{
		pushFront(data);
		return true;
	}

	node* currentNode=head;
	for(unsigned int i = 0; i < (pos-1); i++)
	{
		currentNode = currentNode->next;
	}
	node* newNode = new(node);
	newNode->data = data;
	newNode->next = currentNode->next;
	currentNode->next = newNode;

	if(pos==length)
		tail = newNode;

	length++;

	return true;
	
}

template <typename T>
void list<T>::printList()
{
	node* currentNode = head;
	unsigned int i = 0;
	while(currentNode !=NULL)
	{

		std::cout << "[" << i << "]: " << currentNode->data << std::endl;
		currentNode = currentNode->next;
		i++;
	}
}
