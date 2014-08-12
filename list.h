//List implementation
#ifndef LIST_H
#define LIST_H

#define NULL 0


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

	void pushFront(T value);

	unsigned int len();

	private:

	node* head;

};
#endif

template <typename T>
list<T>::list()
{
	head = NULL;
	std::cout << "list constructed" << std::endl;
}

template <typename T>
list<T>::~list()
{
}

template <typename T>
void list<T>::pushFront(T value)
{
	node* newNode = new(node);
	newNode->data = value;
	newNode->next = head;
	head = newNode;
}

template <typename T>
unsigned int list<T>::len()
{
	if (head==NULL)
		return 0;
	
	node* currentNode = head;
	unsigned int count = 0;

	while(currentNode !=NULL)
	{
		count ++;
		currentNode = currentNode->next;
	}

	return count;
}
		
