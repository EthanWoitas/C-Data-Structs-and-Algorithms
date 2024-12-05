#include <iostream>
// This is a demonstration of a building a doubly linked list, adding and deleting nodes

// ADVANTAGES
// Dynamic, can grow or shrink as needed
// Can insert a node at the start, at the end, and before/after a given node

// DIS-ADVANTAGES
// Can not randomly access elements, must start from the head of the list (Fixed time complexity)
// Memory intensive since each node contains three values, even bigger than a singly linked list

class node {
public:
	int value;
	node* nextNode;
	node* prevNode;
};

// Insertions
void insertAtHead(node**, node**);
void insertAtEnd(node**, node**);

// Deletions
void deleteAtHead(node**);
void deleteAtEnd(node**);
void deleteList(node*);

// Linked list visualizations
void printList(node*);

int main()
{
	// Define head and tail of the list 
	node* head = NULL;
	node* tail = NULL;

	// Allocate memory for a single node
	node* newNode = new node();
	newNode->value = 5;
	newNode->nextNode = NULL;
	newNode->prevNode = NULL;

	// Make this node be both the head and the tail since there is only one node
	head = newNode;
	tail = newNode;

	// Prepend a node (func at line 67)
	insertAtHead(&head, &tail);

	// Append a node (func at line 88)
	insertAtEnd(&head, &tail);

	printList(head);

	// Delete a head (func at line 110)
	deleteAtHead(&head);

	// Delete a tail (func at line 126)
	deleteAtEnd(&tail);

	printList(head);
	
	return 0;
}

// Insertions
void insertAtHead(node** head, node** tail)
{
	node* prependNode = new node();
	std::cout << "Type a value to add at the start of a linked list: ";
	std::cin >> prependNode->value;

	if (*head == NULL) // Start a list if there is none
	{
		prependNode->nextNode = NULL;
		prependNode->prevNode = NULL;
		*head = prependNode;
		*tail = prependNode;
		
		return;
	}

	prependNode->prevNode = NULL;
	prependNode->nextNode = *head;
	(*head)->prevNode = prependNode;
	*head = prependNode;
}
void insertAtEnd(node** head, node** tail)
{
	node* appendNode = new node();
	std::cout << "Type a value to add to the list: ";
	std::cin >> appendNode->value;

	if ((*tail)->prevNode == NULL) // Start a list if there in none
	{
		appendNode->nextNode = NULL;
		appendNode->prevNode = NULL;
		*head = appendNode;
		*tail = appendNode;
		return;
	}

	appendNode->prevNode = *tail;
	appendNode->nextNode = NULL;
	(*tail)->nextNode = appendNode;
	*tail = appendNode;
}

// Deletions
void deleteAtHead(node** head)
{
	if (*head == NULL)
	{
		std::cout << "No list currently exists." << std::endl;
		return;
	}

	node* temp = *head;
	*head = (*head)->nextNode;
	if ((*head)->prevNode != NULL)
	{
		(*head)->prevNode = NULL;
	}
	delete temp;
}
void deleteAtEnd(node** tail)
{
	if (*tail == NULL)
	{
		std::cout << "No list currently exists." << std::endl;
		return;
	}

	node* temp;
	temp = *tail;
	*tail = (*tail)->prevNode;
	if ((*tail)->nextNode != NULL)
	{
		(*tail)->nextNode = NULL;
	}
	delete temp;
}

// Linked list visualization 
void printList(node* head)
{
	if (head == NULL)
	{
		std::cout << "No list currently exists.";
		return;
	}

	std::cout << "The current list is.." << std::endl;
	while (head != NULL)
	{
		std::cout << head->value << std::endl;
		head = head->nextNode;
	}
}