/*
This program implements a Doubly Linked List.
a Doubly Linked List has two pointer cariables in each node,
one pointing to next node and the other one pointing to next node
and other pointing to previous node.
*/

#include<stdio.h>
#include<malloc.h>

/*
Create a structure to represent a node in memory.
data can be of any datatype.
next and previous are pointers of struct node type,
they will point to the next and previous node in the list respectively.
*/
struct node
{
	int data;
	struct node* next;
	struct node* previous;
};

//Create a global pointer head, pointing to the first node in the Doubly Linked List
struct node* head;

//Operations performed on the Doubly Linked List
void insertAtBegining(int);
void insertAtEnd(int);
void insertAtNthPosition(int, int);
void deleteNode(int);
int searchNode(int);
void display();

/*
This funtion will create an node in the memory dynamically,
and it will will return the starting adress of that node to calling function
*/
struct node* getNewNode(int);

int main()
{
	int choice, data, n, searchResult;
	
	//A Null value in head pointer represents empty List.
	head = NULL;
	
	//Give choice to user.
	do
	{
		printf("\n1. Insert at Begining. \n2. Insert at End. \n3. Insert at Nth position.");
		printf("\n4. Delete a Node. \n5. Search a Node. \n6. Display. \n7. Exit\n");
		printf("\nEnter your choice: ");
		scanf("%d", &choice);
		
		switch(choice)
		{
			case 1:
				printf("\nEnter the value to be inserted: ");
				scanf("%d", &data);
				insertAtBegining(data);
				break;
				
			case 2:
				printf("\nEnter the value to be inserted: ");
				scanf("%d", &data);
				insertAtEnd(data);
				break;
				
			case 3:
				printf("\nEnter the value to be inserted: ");
				scanf("%d", &data);
				printf("\nEnter the position: ");
				scanf("%d", &n);
				insertAtNthPosition(data, n);
				break;
				
			case 4:
				printf("\nEnter the value to be deleted: ");
				scanf("%d", &data);
				deleteNode(data);
				break;
				
			case 5:
				printf("\nEnter the value to be searched: ");
				scanf("%d", &data);
				searchResult = searchNode(data);
				
				if(searchResult != -1)
				{
					printf("\n%d Found at position %d\n", data, searchResult);
				}
				else
				{
					printf("\n%d not found int the List\n", data);
				}
				
				break;
				
			case 6:
				printf("\n");
				display();
				printf("\n");
				break;
				
			case 7:
				printf("\nExit!");
				break;
				
			default:
				printf("\nInvalid Choice!\n");
		}
	}
	while(choice != 7);
	
	return -1;
}

//Create a new Node and return it's address.
struct node* getNewNode(int data)
{
	/*
	malloc() returns a void pointer which can't be dereferenced, 
	so we need to typecast it in order to dereference and access values.
	*/
	struct node* newNode = (struct node*) malloc(sizeof(struct node));
	
	newNode->data = data;
	newNode->next = NULL;
	newNode->previous = NULL;
	
	return newNode;
}

//Insert node at the begining
void insertAtBegining(int data)
{
	struct node* newNode = getNewNode(data);
	
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
	head->previous = newNode;
	newNode->next = head;
	head = newNode;
	
}

//Insert node at the end
void insertAtEnd(int data)
{
	struct node* newNode = getNewNode(data);
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
	newNode->previous = temp;
	
}

//Insert node at Nth position
void insertAtNthPosition(int data, int pos)
{
	struct node* newNode = getNewNode(data);
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
	traverse till the Nth position
	*/
	while(i < (pos - 1))
	{
		temp = temp->next;
		i++;
	}
	
	newNode->next = temp->next;
	newNode->previous = temp;
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
	temp->next->previous = prePtr;
	
	//Once the links are set, Deallocate the Node from the memory.
	free(temp);
}

/*
Returns the position of the search element,
returns -1 if the element is not present int he Linked List
*/
int searchNode(int data)
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
