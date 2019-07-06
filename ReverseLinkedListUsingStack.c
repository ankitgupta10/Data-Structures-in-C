/*
This Program Reverses a Linked List using Stack Data Structure
Reversal takes place not by swapping data but by adjusting links
Input:A Linked List,
ex: HEAD -> A -> B -> C -> D -> NULL
Output:Reversed Linked List,
ex: NULL <- A <- B <- C <- D <- HEAD
*/

#include <stdio.h>
#include <malloc.h>
#define MAX_SIZE 25

//Create a structure to represent a node of a Linked List.
struct node
{
	int data;
	struct node *next;
};

//Global variable to hold the address of head node of the Linked List.
struct node *head;

/*
We want to store pointers to nodes in stack,
so datatype of stack would be struct node*.
*/
struct node *stack[MAX_SIZE];

int top = -1;

//Operations on Stack.
void push(struct node *);
struct node *pop();

//Operations on Linked List.
void createLinkedList();
void insertAtEnd(int);
void display();

void reverseUsingStack();

int main()
{
	int data, choice;

	//NULL head indicates empty Linked List.
	head = NULL;

	do
	{
		printf("\n1. Create a Linked List. \n2. Reverse the Linked List \n3. Display. \n4. Exit.");
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
			reverseUsingStack();
			printf("\nAfter:");
			display();
			break;

		case 3:
			display();
			break;

		case 4:
			printf("\nExit!");
			break;

		default:
			printf("\nInvalid Choice!\n");
		}
	}

	while (choice != 4);

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

//Push element on stack
void push(struct node *temp)
{
	//Check if the stack is full, if yes then return.
	if (top == MAX_SIZE - 1)
	{
		printf("\nStack overflow!\n");
		return;
	}

	stack[++top] = temp;
}

//Pop element out of the stack
struct node *pop()
{
	//Check if stack is empty, if yes then return.
	if (top == -1)
	{
		printf("\nStack underflow!\n");
		return NULL;
	}

	return stack[top--];
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

//Reverse the Linked List using Stack.
void reverseUsingStack()
{
	struct node *temp = head;

	while (temp != NULL)
	{
		push(temp);
		temp = temp->next;
	}

	head = pop();
	temp = head;

	while (top != -1)
	{
		temp->next = pop();
		temp = temp->next;
	}

	temp->next = NULL;
}
