/*
This program evaluates a given string in postfix form.
We keep pushing the operands in stack untill an operator is encountered,
if we see an operator, pop last two elements from stack and
perform operation on them and push back the result on the stack.
*/

#include <stdio.h>
#define MAX_SIZE 25

int stack[MAX_SIZE];

int top = -1;

//Operations on stack
void push(int);
int pop();

int evaluatePostfix(char *);
int isOperand(char);
int isOperator(char);
int performOperation(char, int, int);

int main()
{
	int result;
	char expression[MAX_SIZE];

	printf("\nEnter Postfix expression: ");
	gets(expression);

	result = evaluatePostfix(expression);

	printf("\nResult: %d", result);
}

//Push element on stack
void push(int operand)
{
	//Check if the stack is full, if yes then return.
	if (top == MAX_SIZE - 1)
	{
		printf("\nStack overflow!\n");
		return;
	}

	stack[++top] = operand;
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

//Check if character is operand or not and return its decimal equivalent.
int isOperand(char operand)
{
	if (operand >= '0' && operand <= '9')
	{
		//If, operand is a number then convert it into its decimal equivalent.
		return operand - '0';
	}
	else
		return -1;
}

//Check if character is an operator or not.
int isOperator(char oper)
{
	if (oper == '/' || oper == '*' || oper == '+' || oper == '-')
	{
		return 1;
	}

	else
		return 0;
}

//Perform operation on the two recently popped operands.
int performOperation(char oper, int op1, int op2)
{
	if (oper == '/')
	{
		return op1 / op2;
	}

	else if (oper == '*')
	{
		return op1 * op2;
	}

	else if (oper == '+')
	{
		return op1 + op2;
	}

	else
		return op1 - op2;
}

//Evaluate postfix expression
int evaluatePostfix(char *str)
{
	int i = 0, result, operand, operand1, operand2;

	while (str[i] != '\0')
	{
		operand = isOperand(str[i]);

		if (operand != -1)
		{
			push(operand);
		}

		else if (isOperator(str[i]))
		{
			operand2 = pop();
			operand1 = pop();

			result = performOperation(str[i], operand1, operand2);

			push(result);
		}

		i += 1;
	}

	return stack[top];
}
