/*
This program implements Queue Data Structure,
Using array
*/

#include<stdio.h>

//Define Max Size of Queue
#define MAX_SIZE 25

//Declare a global Queue
int queue[MAX_SIZE];

int front = -1;
int rear = -1;

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

//Insert element in Queue.
void insert(int data)
{
	//Check if the Queue is full, if yes then return.
	if(rear == MAX_SIZE-1)
	{
		printf("\nQueue is full!\n");
		return;
	}
	
	//Check if the Queue is empty
	if(front == -1 && rear == -1)
	{
		front = rear = 0;
		queue[rear] = data;
		return;
	}
	
	queue[++rear] = data;
	
}

//Remove element from Queue.
int removeElement()
{
	int temp;
	
	//Check if Queue is empty, if yes then return.
	if(front == -1 && rear == -1)
	{
		printf("\nQueue is empty!\n");
		return -1;
	}
	
	temp = queue[front];
	
	if(front == rear)
	{
		front = rear = -1;
		return temp;
	}
	
	front++;
	return temp;
	
}

//Return element at front in Queue.
int peek()
{
	//Check if Queue is empty, if yes then return.
	if(front == -1 && rear == -1)
	{
		printf("\nQueue is empty!\n");
		return -1;
	}
	
	return queue[front];
	
}

//Display contents of Queue.
void display()
{
	int i = front;
	
	//Check if Queue is empty, if yes then return.
	if(front == -1 && rear == -1)
	{
		printf("\nQueue is empty!\n");
		return;
	}
	
	printf("\n");
	
	while(i <= rear)
	{
		printf("%d ", queue[i++]);
	}
	
	printf("\n");
	
}
