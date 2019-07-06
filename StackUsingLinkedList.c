/*
This program implements Stack Data Structure,
using Linked list.
*/

#include <stdio.h>
#include <malloc.h>

/*
Create a structure to represent a node.
*/
struct node
{
	int data;
	struct node *next;
};

//Pointer pointing to tompost element of Stack.
struct node *top;

//Operations on Stack;
void push();
int pop();
int peek();
void display();

int main()
{
	int choice, data;

	//top == NULL represents empty Stack.
	top = NULL;

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
	struct node *newNode = (struct node *)malloc(sizeof(struct node));

	newNode->data = data;
	newNode->next = NULL;

	/*
	Check if the stack is empty, 
	if yes then point top to newly created node and return.
	*/
	if (top == NULL)
	{
		top = newNode;
		return;
	}

	newNode->next = top;
	top = newNode;
}

//Pop element out of the stack
int pop()
{
	struct node *temp = top;

	int popValue;

	//Check if stack is empty, if yes then return.
	if (top == NULL)
	{
		printf("\nStack underflow!\n");
		return -1;
	}

	popValue = top->data;

	top = top->next;
	free(temp);

	return popValue;
}

//Check topmost element on stack
int peek()
{
	//Check if stack is empty, if yes then return.
	if (top == NULL)
	{
		printf("\nStack is empty!\n");
		return -1;
	}

	return top->data;
}

//Display contents of stack.
void display()
{
	struct node *temp = top;

	//Check if stack is empty, if yes then return.
	if (top == NULL)
	{
		printf("\nStack is empty!\n");
		return;
	}

	while (temp != NULL)
	{
		/*
		%3d indicates that the number will be printed with atleast 3 characters wide
		And thus reulting in right alignment.
		*/
		printf("\n|  %3d    |", temp->data);
		printf("\n-----------");

		temp = temp->next;
	}
}
