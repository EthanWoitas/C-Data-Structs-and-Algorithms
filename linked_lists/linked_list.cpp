#include <iostream>
// This is a demonstration of a building a linked list, adding and deleting nodes

// ADVANTAGES
// Dynamic, can grow or shrink as needed
// Can insert a node at the start, at the end, and after a given node

// DIS-ADVANTAGES
// Can not randomly access elements, must start from the head of the list (Fixed time complexity)
// Memory intensive since each node contains two values

class node {
public:
	int value;	
	node* nextNode;
};

// Insertions
void insertAtHead(node**); // Add a new node at the start of the list 
void insertAtEnd(node**); // Add a new node at the end of a list 
void insertAfterChosen(node*); // Adds a node after the node defined in the argument list

// Deletions
void deleteAtHead(node**); // Delete a node at the start of the list
void deleteAtEnd(node**); // Delete a node at the end of a list
void deleteAfterChosen(node*); // Deletes a node after the node defined in the argument list 
void deleteList(node*); // Delete whole list

// Linked list visualizations
void printList(node*); // Printing current list
int  countNodes(node*); // Counts how many elements are in the list

int main()
{
	// Allocate memory for nodes
	node* head = new node();
	node* second = new node();
	node* third = new node();

	// Populate nodes
	std::cout << "Type value number 1" << std::endl;
	std::cin >> head->value;
	head->nextNode = second;

	std::cout << "Type value number 2" << std::endl;
	std::cin >> second->value;
	second->nextNode = third;

	std::cout << "Type value number 3" << std::endl;
	std::cin >> third->value;
	third->nextNode = NULL;

	// Print off the current linked list
	std::cout << std::endl << "There are currently " << countNodes(head) << " nodes in the linked list. The current list is..." << std::endl;
	printList(head);

	// Prepend a node in the linked list
	insertAtHead(&head);

	// Append a node
	insertAtEnd(&head);

	// Insert after a given node (Node 2)
	insertAfterChosen(second);

	std::cout << std::endl << "There are currently " << countNodes(head) << " nodes in the linked list. The current list is..." << std::endl;
	printList(head);

	// Delete a node at the start of the list 
	deleteAtHead(&head);
	
	// Delete a node at the end of a list
	deleteAtEnd(&head);

	// Delete after a given node
	deleteAfterChosen(second);
	
	std::cout << std::endl << "There are currently " << countNodes(head) << " nodes in the linked list. The current list is..." << std::endl;
	printList(head);
	
	// Delete the whole list
	deleteList(head);

	return 0;
}

// Insertions 
void insertAtHead(node** head)
{
	node* prependNode = new node();
	std::cout << "Type a value to add at the start of a linked list" << std::endl;
	std::cin >> prependNode->value;

	if (*head == NULL) // Start a list if there is none
	{
		*head = prependNode;
		return;
	}

	prependNode->nextNode = *head;
	*head = prependNode;

	return;
}
void insertAtEnd(node** head)
{
	node* appendNode = new node();
	appendNode->nextNode = NULL;
	std::cout << "Type a value to add at the end of a linked list" << std::endl;
	std::cin >> appendNode->value;

	if (*head == NULL) // Start a list if there is none
	{
		*head = appendNode;
		return;
	}

	node* temp = *head;
	while (temp->nextNode != NULL)
	{
		temp = temp->nextNode;
	}
	temp->nextNode = appendNode;
}
void insertAfterChosen(node* previous)
{
	if (previous == NULL)
	{
		std::cout << "The chosen node can not be NULL" << std::endl;
		return;
	}

	node* afterChosen = new node();
	std::cout << "Type a value to add after a given node in a linked list" << std::endl;
	std::cin >> afterChosen->value;

	afterChosen->nextNode = previous->nextNode;
	previous->nextNode = afterChosen;

}

// Deletions
void deleteAtHead(node** head)
{
	if (*head == NULL)
	{
		std::cout << "There is no node to delete." << std::endl;
		return;
	}
	
	node* temp = *head;
	*head = (*head)->nextNode;

	delete temp;
}
void deleteAtEnd(node** head)
{
	if (*head == NULL)
	{
		std::cout << "There is no node to delete." << std::endl;
		return;
	}

	node* temp = *head;

	while (temp->nextNode->nextNode != NULL)
	{
		temp = temp->nextNode;
	}

	delete temp->nextNode;
	temp->nextNode = NULL;
}
void deleteAfterChosen(node* previous)
{
	if (previous == NULL)
	{
		std::cout << "The chosen node can not be NULL" << std::endl;
		return;
	}

	node* temp = previous->nextNode;
	previous->nextNode = previous->nextNode->nextNode;
	delete temp;
}
void deleteList(node* head) 
{
	while (head != NULL) {
		node* temp = head;
		head = head->nextNode;
		delete temp;
	}
}

// Linked list visualizations
void printList(node* x)
{
	while (x != NULL)
	{
		std::cout << x->value << std::endl;
		x = x->nextNode;
	}
}
int  countNodes(node* x)
{
	int nodeCount = 0;

	while (x != NULL)
	{
		nodeCount++;
		x = x->nextNode;
	}

	return nodeCount;
}