/*
This Program Reverses a Linked List using Iterative and Recursive approach
Reversal takes place not by swapping data but by adjusting links
Input:A Linked List,
ex: HEAD -> A -> B -> C -> D -> NULL
Output:Reversed Linked List,
ex: NULL <- A <- B <- C <- D <- HEAD
*/

#include <stdio.h>
#include <malloc.h>

//Create a structure tot store node of a Linked List.
struct node
{
	int data;
	struct node *next;
};

//Global variable to hold the address of head node of the Linked List.
struct node *head;

void createLinkedList();
void insertAtEnd(int);
void display();

void reverseWithIteration();
void reverseWithRecursion(struct node *);

void main()
{
	int data, choice;

	//NULL head indicates empty Linked List.
	head = NULL;

	do
	{
		printf("\n1. Create a Linked List. \n2. Reverse the Linked List(Iterative Approach)");
		printf("\n3. Reverse the Linked List(Recursive Approach) \n4. Display. \n5. Exit.");
		printf("\nEnter Choice: ");
		scanf("%d", &choice);

		switch (choice)
		{
		case 1:
			createLinkedList();
			break;

		case 2:
			printf("\nBefore:");
			display();
			reverseWithIteration();
			printf("\nAfter:");
			display();
			break;

		case 3:
			printf("\nBefore:");
			display();
			reverseWithRecursion(head);
			printf("\nAfter:");
			display();
			break;

		case 4:
			display();
			break;

		case 5:
			printf("\nExit!");
			break;

		default:
			printf("\nInvalid Choice!\n");
		}
	} while (choice != 4);

	return 0;
}

//Create a Linked List
void createLinkedList()
{
	int data;

	if (head != NULL)
	{
		printf("\nLinked List is already created!\n");
		return;
	}

	printf("\nEnter the elements of the Linked List, enter -1 to terminate.\n");

	while (1)
	{
		scanf("%d", &data);
		if (data == -1)
		{
			break;
		}
		insertAtEnd(data);
	}

	display();
}

//Insert node at the end of the Linked list.
void insertAtEnd(int data)
{
	//Create a new Node.
	struct node *newNode = (struct node *)malloc(sizeof(struct node));
	newNode->data = data;
	newNode->next = NULL;

	//A temporary pointer to traverse the linked list.
	struct node *temp = head;

	/*
	Check if the Linked List is empty.
	If yes, then point head node to newly created node and return
	*/
	if (head == NULL)
	{
		head = newNode;
		return;
	}

	/*
	If the Linked List is not empty,
	traverse till the end and add newNode in the end
	*/
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	temp->next = newNode;
}

//Reverse the Linked List with iterar=tive approach
void reverseWithIteration()
{
	struct node *previousNode, *currentNode, *nextNode;

	previousNode = NULL;
	currentNode = head;

	while (currentNode != NULL)
	{
		nextNode = currentNode->next;
		currentNode->next = previousNode;
		previousNode = currentNode;
		currentNode = nextNode;
	}

	head = previousNode;
}

//Reverse the Linked List with Recursive approach
void reverseWithRecursion(struct node *temp)
{
	/*
	On reaching the end of the Linked List,
	modify head to point to the last node
	*/
	if (temp->next == NULL)
	{
		head = temp;
		return;
	}

	reverseWithRecursion(temp->next);

	/*
	Point Nth node to (N-1)th node.
	p is Nth node
	temp is (N-1)th node
	(N-1)th node becomes the last node after eevery return.+
	*/
	struct node *p = temp->next;
	p->next = temp;
	temp->next = NULL;
}

//Display the Linked List
void display()
{
	struct node *temp = head;

	/*
	Check if the Linked List is empty.
	If yes, then return.
	*/
	if (head == NULL)
	{
		printf("\nLinked List is empty!\n");
		return;
	}

	printf("\n");
	//Traverse till the end and print the data in the process.
	while (temp != NULL)
	{
		printf("%d ", temp->data);
		temp = temp->next;
	}
	printf("\n");
}
