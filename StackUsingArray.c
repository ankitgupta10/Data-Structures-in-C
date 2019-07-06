/*
This programs implements a Stack Data Structure,
using an array.
*/

#include <stdio.h>

//Define max size for stack.
#define MAX_SIZE 25

//Declare a global Stack array.
int stack[MAX_SIZE];

//top = -1 represents empty stack.
int top = -1;

//Operations on Stack.
void push(int);
int pop();
int peek();
void display();

int main()
{
	int choice, data;

	do
	{
		printf("\n1. Push. \n2. Pop. \n3. Top. \n4. Display. \n5. Exit.");
		printf("\nEnter choice: ");
		scanf("%d", &choice);

		switch (choice)
		{
		case 1:
			printf("\nEnter value to be pushed: ");
			scanf("%d", &data);
			push(data);
			printf("\n%d pushed on stack. \n", data);
			break;

		case 2:
			data = pop();

			if (data != -1)
			{
				printf("\n%d popped out of the stack. \n", data);
			}

			break;

		case 3:
			data = peek();

			if (data != -1)
			{
				printf("\nTopmost element on stack: %d\n", data);
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
	} while (choice != 5);
}

//Push element on stack
void push(int data)
{
	//Check if the stack is full, if yes then return.
	if (top == MAX_SIZE - 1)
	{
		printf("\nStack overflow!\n");
		return;
	}

	stack[++top] = data;
}

//Pop element out of the stack
int pop()
{
	//Check if stack is empty, if yes then return.
	if (top == -1)
	{
		printf("\nStack underflow!\n");
		return -1;
	}

	return stack[top--];
}

//Check topmost element on stack
int peek()
{
	//Check if stack is empty, if yes then return.
	if (top == -1)
	{
		printf("\nStack is empty!\n");
		return -1;
	}

	return stack[top];
}

//Display contents of stack.
void display()
{
	int i = top;

	//Check if stack is empty, if yes then return.
	if (top == -1)
	{
		printf("\nStack is empty!\n");
		return;
	}

	while (i >= 0)
	{
		/*
		%3d indicates that the number will be printed with atleast 3 characters wide
		And thus reulting in right alignment.
		*/
		printf("\n|  %3d    |", stack[i--]);
		printf("\n-----------");
	}
}
