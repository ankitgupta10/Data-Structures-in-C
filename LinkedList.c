/*
This program implements a Linked List.
a Linked List is a collection of nodes,
where each node points to the next node int the List.
the last node points to NULL.
*/

#include<stdio.h>
#include<malloc.h>

/*
Create a structure to represent a node in memory.
data can be of any datatype.
next is a pointer of struct node type,
it will point to the next node in the list.
*/
struct node
{
	int data;
	struct node* next;
};

//Declare o global variable for head node, pointing to 1st node in list.
struct node* head;

//This function creates a new node and returs it's starting adrees to the caller.
struct node* getNewNode(int);

//Operations to be performed on Linked List.
void insertAtBegining(int);
void insertAtEnd(int);
void insertAtNth(int, int);
void deleteNode(int);
int search(int);
void display();
void displayReverse(struct node*);
void printNthLast(struct node*);

int n1;

int main()
{
	int choice, data, n, searchResult;
	
	//head is NULL indicating the list is empty
	head = NULL;
	
	//Give choice to user.
	do
	{
		printf("\n1. Insert at begining \n2. Insert at end \n3. Insert at Nth position");
		printf("\n4. Delete \n5. Search \n6. Display \n7. Display in Reverse \n8. Exit\n");
 
		printf("\nEnter choice: ");
		scanf("%d", &choice);
	
		switch(choice)
		{
			case 1:
				printf("\nEnter Value to be inserted: ");
				scanf("%d", &data);
				insertAtBegining(data);
				break;
			
			case 2:
				printf("\nEnter Value to be inserted: ");
				scanf("%d", &data);
				insertAtEnd(data);
				break;
		
			case 3:
				printf("\nEnter Value to be inserted: ");
				scanf("%d", &data);
				printf("\nEnter the position. ");
				scanf("%d", &n);
				insertAtNth(data, n);
				break;
				
			case 4:
				printf("\nEnter Value to be deleted: ");
				scanf("%d", &data);
				deleteNode(data);
				break;
				
			case 5:
				printf("\nEnter Value to be searched: ");
				scanf("%d", &data);
				searchResult = search(data);
			
				if(searchResult != -1)
				{
					printf("%d present at position %d.\n", data, searchResult);
				}
				else
				{
					printf("%d not found in Linked List!\n", data);
				}
				break;
				
			case 6:
				printf("\n");
				display();
				break;
			
			case 7:
				printf("\n");
				displayReverse(head);
				printf("\n");
				break;
			
			case 8:
				//printf("\nExit!");
				printf("\n enter n");
				scanf("%d", &n1);
				printNthLast(head);
				break;
						
			default:
				printf("\nIvalid choice!\n");
		}
	}
	while(choice != 9);
	
	return 0;
}

//Create a new node dynamically.
struct node* getNewNode(int data)
{
	/*
	malloc() returns a void pointer which can't be dereferenced, 
	so we need to typecast it in order to dereference and access values.
	*/
	struct node* newNode = (struct node*) malloc(sizeof(struct node));
	newNode->data = data;
	newNode->next = NULL;
	return newNode;
}

//Insert node at the first position in the Linked List.
void insertAtBegining(int data)
{
	//Create a new Node.
	struct node* newNode = getNewNode(data);
	
	//A temporary pointer to traverse the linked list.
	struct node* temp = head;
	
	/*
	Check if the Linked List is empty.
	If yes, then point head node to newly created node and return
	*/
	if(head == NULL)
	{
		head = newNode;
		return;
	}
	
	/*
	If the Linked List is not empty,
	insert node at the begining.
	*/
	newNode->next = head;
	head = newNode;	
}

//Insert node at the end of the Linked list.
void insertAtEnd(int data)
{
	//Create a new Node.
	struct node* newNode = getNewNode(data);
	
	//A temporary pointer to traverse the linked list.
	struct node* temp = head;
	
	/*
	Check if the Linked List is empty.
	If yes, then point head node to newly created node and return
	*/
	if(head == NULL)
	{
		head = newNode;
		return;
	}
	
	/*
	If the Linked List is not empty,
	traverse till the end and add newNode in the end
	*/
	while(temp->next != NULL)
	{
		temp = temp->next;
	}
	temp->next = newNode;
}

//Insert node at Nth position.
void insertAtNth(int data, int pos)
{
	//Create a new Node.
	struct node* newNode = getNewNode(data);
	
	//A temporary pointer to traverse the linked list.
	struct node* temp = head;
	
	int i = 1;
	
	/*
	Check if the Linked List is empty.
	If yes, then point head node to newly created node and return
	*/
	if(head == NULL)
	{
		head = newNode;
		return;
	}
	
	//If pos = 1, means insert at the begining.
	if(pos == 1)
	{
		insertAtBegining(data);
		return;
	}
	
	/*
	If the Linked List is not empty,
	traverse till the Nth position and add newNode.
	*/
	while(i < (pos-1))
	{
		temp = temp->next;
		i++;
	}
	newNode->next = temp->next;
	temp->next = newNode;	
}

//Delete a node with particular value
void deleteNode(int data)
{
	struct node* temp = head;
	
	//prePtr will point to the previous node of the node to be deleted.
	struct node* prePtr = NULL;
	
	//Traverse the Linked List untill the node with the data is not found.
	while(temp->data != data)
	{
		prePtr = temp;
		temp = temp->next;
	}
	
	prePtr->next = temp->next;
	
	//Once the links are set, Deallocate the Node from the memory.
	free(temp);
}

/*
Returns the position of the search element,
returns -1 if the element is not present int he Linked List
*/
int search(int data)
{
	struct node* temp = head;
	int position = 1;
	
	/*
	Check if the Linked List is empty.
	If yes, return -1.
	*/
	if(head == NULL)
	{
		return -1;
	}
	
	//Traverse the Linked List untill the node with the data is not found.
	while(temp != NULL)
	{
		if(temp->data == data)
		{
			return position;
		}
		
		temp = temp->next;
		position = position + 1;	
	}
	
	return -1;
}

//Display the Linked List
void display()
{
	struct node* temp = head;
	
	/*
	Check if the Linked List is empty.
	If yes, then return.
	*/
	if(head == NULL)
	{
		printf("\nLinked List is empty!\n");
		return;
	}
	
	//Traverse till the end and print the data in the process.
	while(temp != NULL)
	{
		printf("%d ", temp->data);
		temp = temp->next;
	}
	printf("\n");
}


//print nth last element in linked list
void printNthLast(struct node* temp)
{
	if(temp == NULL)
	{
		printf("code reaches here");
		return;
	}
	
	
	printNthLast(temp->next);
	
	n1--;
	
	if(n1 == 0)
	{
		printf("\n nth last is %d ", temp->data);
	}
	
}
//Display the Linked List in reverse order using Recursion;
void displayReverse(struct node* temp)
{
	if(temp == NULL)
	{
		return;
	}
	
	displayReverse(temp->next);
	printf("%d ", temp->data);
}
