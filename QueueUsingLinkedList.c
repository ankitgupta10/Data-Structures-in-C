/*
This program implements Queue Data Structure,
using Linked list.
*/

#include<stdio.h>
#include<malloc.h>

/*
Create a structure to represent a node.
*/
struct node
{
	int data;
	struct node* next;
};

//These pointers will point to front and rear end of the Queue.
struct node* front;
struct node* rear;

//To create a new node dynamically.
struct node* getNewNode(int);

//Oprerations on Queue
void insert(int);
int removeElement();
int peek();
void display();

void main()
{
	int data, choice;
	
	do
	{
		printf("\n1. Insert. \n2. Delete. \n3. Peek. \n4. Display. \n5. Exit.");
		printf("\nEnter choice: ");
		scanf("%d", &choice);
		
		switch(choice)
		{
			case 1:
				printf("\nEnter value to be inserted: ");
				scanf("%d", &data);
				insert(data);
				printf("\n%d inserted in queue. \n", data);
				break;
				
			case 2:
				data = removeElement();
				
				if(data != -1)
				{
					printf("\n%d removed out from the queue. \n", data);
				}
				
				break;
				
			case 3:
				data = peek();
				
				if(data != -1)
				{
					printf("\nElement at front: %d\n", data);
				}
				
				break;
				
			case 4:
				display();
				break;
				
			case 5:
				printf("\nExit!\n");
				break;
			
			default:
				printf("\nInvalid choice!\n");
		}	
	}
	while(choice != 5);
	
}

struct node* getNewNode(int data)
{
	struct node* newNode = (struct node*) malloc(sizeof(struct node));
	
	newNode->data = data;
	newNode->next = NULL;
	
	return newNode;
	
}

//Insert element from rear end of the Queue.
void insert(int data)
{
	struct node* newNode = getNewNode(data);
	
	//Check if Queue is empty.
	if(front == NULL && rear == NULL)
	{
		front = rear = newNode;
		return;
	}
	
	rear->next = newNode;
	rear = newNode;
	
}

//Remove element from front end of the Queue.
int removeElement()
{
	struct node* removedNode = front;
	int temp;
	
	//Check if Queue is empty, if yes then return.
	if(front == NULL && rear == NULL)
	{
		printf("\nQueue is empty!\n");
		return -1;
	}
	
	temp = front->data;
	
	if(front == rear)
	{
		front = rear = NULL;
		return temp;
	}
	
	front = front->next;
	
	free(removedNode);
	
	return temp;
	
}

//Return element at front in Queue.
int peek()
{
	//Check if Queue is empty, if yes then return.
	if(front == NULL && rear == NULL)
	{
		printf("\nQueue is empty!\n");
		return -1;
	}
	
	return front->data;
	
}

//Display contents of Queue.
void display()
{
	struct node* temp = front;
	
	//Check if Queue is empty, if yes then return.
	if(front == NULL && rear == NULL)
	{
		printf("\nQueue is empty!\n");
		return;
	}
	
	printf("\n");
	
	while(temp!= NULL)
	{
		printf("%d ", temp->data);
		temp = temp-> next;
	}
	
	printf("\n");
	
}
