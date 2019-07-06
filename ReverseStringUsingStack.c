/*
This program reverses the input string using Stack data structure.
Input  ex: hello world
Output ex: dlro olleh
*/

#include <stdio.h>
#define MAX_SIZE 50

char stack[MAX_SIZE];

//top = -1 represents empty stack.
int top = -1;

void reverseString(char *);

//Operations on Stack.
void push(char);
char pop();

int main()
{
	char string[50];

	printf("\nEnter source string(max 50 characters): \n");
	gets(string);

	reverseString(string);

	printf("\nReverted String is: \n");
	puts(string);
}

//Push element on stack
void push(char letter)
{
	//Check if the stack is full, if yes then return.
	if (top == MAX_SIZE - 1)
	{
		printf("\nStack overflow!\n");
		return;
	}

	stack[++top] = letter;
}

//Pop element out of the stack
char pop()
{
	//Check if stack is empty, if yes then return.
	if (top == -1)
	{
		printf("\nStack underflow!\n");
		return -1;
	}

	return stack[top--];
}

void reverseString(char *string)
{
	int i = 0;

	while (*(string + i) != '\0')
	{
		push(*(string + i));
		i += 1;
	}

	i = 0;

	while (top != -1)
	{
		*(string + i) = pop();
		i += 1;
	}
}
