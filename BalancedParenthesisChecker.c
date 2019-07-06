/*
This program checks for balances parenthesis in a given string.
Parenthesis are balenced if each opening brace has an corresponding closing brace.
*/

#include <stdio.h>
#define MAX_SIZE 25

char stack[MAX_SIZE];

int top = -1;

//Operations on stack
void push(char);
char pop();

int checkBalancedParenthesis(char *);
int validPairOfParenthesis(char, char);
int isOpeningBrace(char);
int isClosingBrace(char);

int main()
{
	char str[MAX_SIZE];
	int result;

	printf("\nEnter Source String: \n");
	gets(str);

	result = checkBalancedParenthesis(str);

	if (result == 1)
	{
		printf("\nParenthesis are balanced.");
	}

	else
	{
		printf("\nParenthesis are NOT balanced.");
	}
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

//Check if the character is opening Brace.
int isOpeningBrace(char opening)
{
	if (opening == '(' || opening == '[' || opening == '{')
	{
		return 1;
	}

	else
		return 0;
}

//Check if the character is closing Brace.
int isClosingBrace(char closing)
{
	if (closing == ')' || closing == ']' || closing == '}')
	{
		return 1;
	}

	else
		return 0;
}

int validPairOfParenthesis(char opening, char closing)
{
	if ((opening == '(' && closing == ')') ||
		(opening == '[' && closing == ']') ||
		(opening == '{' && closing == '}'))
	{
		return 1;
	}

	else
		return 0;
}

int checkBalancedParenthesis(char *str)
{
	int i;

	while (str[i] != '\0')
	{
		if (isOpeningBrace(str[i]))
		{
			push(str[i]);
		}

		if (isClosingBrace(str[i]))
		{
			if (validPairOfParenthesis(stack[top], str[i]))
			{
				pop();
			}

			else
			{
				return 0;
			}
		}

		i += 1;
	}

	//If stack is empty, means parenthesis are balanced, return 1.
	if (top == -1)
	{
		return 1;
	}

	else
	{
		return 0;
	}
}