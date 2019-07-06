/*
Implementation of Binary Search Tree or BST.
BST is a special type of tree in which,
all nodes in the Left sub tree
will be less than or equal to the root node
AND all nodes in the Right sub tree
will be greater than to the root node.
*/
#include <stdio.h>
#include <malloc.h>

//MAXSIZE OF QUEUE
#define MAXSIZE 50

/*
To perform level order traversal or BFS,
we use Queue (FIFO) Data Structure.
the Queue will store the nodes.
*/
struct node *queueOfNodes[MAXSIZE];
int front = -1;
int rear = -1;

//These are the functions we want to perform on queue.
void insertNodeInQueue(struct node *);
int queueNotEmpty();
void popNodeOffQueue();

//Create a structure for the node
struct node
{
	int data;

	//Pointer to left child.
	struct node *left;
	//Pointer to Right child.
	struct node *right;
};

//Operations on BST
struct node *getNewNode(int);
struct node *insertNode(struct node *, int);
struct node *deleteNode(struct node *, int);
int heightOfTree(struct node *);
int findMin(struct node *);
int findMax(struct node *);
int searchNode(struct node *, int);
void levelOrderDisplay(struct node *);
void inOrderDisplay(struct node *);
void preOrderDisplay(struct node *);
void postOrderDisplay(struct node *);

void main()
{
	int data, min, max, height, searchResult, choice;

	/*
	Create a root node of BST.
	root = NULL indicates empty BST
	*/
	struct node *root = NULL;

	do
	{
		printf("\n1. Insert element. \n2. Delete Node \n3. Level order Traversal."
			   "\n4. In order Traversal. \n5. Pre order Traversal. \n6. Post order Traversal."
			   "\n7. Search. \n8. Find Minimum. \n9. Find Maximum. \n10. Find Height of tree."
			   "\n11. Exit \n");
		printf("\nEnter Choice: ");
		scanf("%d", &choice);

		switch (choice)
		{
		case 1:
			printf("\nEnter node value: ");
			scanf("%d", &data);
			insertNode(root, data);
			break;

		case 2:
			printf("\nEnter node value: ");
			scanf("%d", &data);
			deleteNode(root, data);
			break;

		case 3:
			printf("\nLevel Order Traversal:\n");
			levelOrderDisplay(root);
			break;

		case 4:
			printf("\nIn Order Traversal:\n");
			inOrderDisplay(root);
			break;

		case 5:
			printf("\nPre Order Traversal:\n");
			preOrderDisplay(root);
			break;

		case 6:
			printf("\nPost Order Traversal:\n");
			postOrderDisplay(root);
			break;

		case 7:
			printf("\nEnter node value to be searched: ");
			scanf("%d", data);
			searchResult = searchNode(root, data);
			if (searchResult == 1)
			{
				printf("\n%d found int the BST.\n", data);
			}
			else
			{
				printf("\n%d NOT found int the BST.", data);
			}

			break;

		case 8:
			min = findMin(root);
			printf("\nMinimum value in the BST is: %d\n", min);
			break;

		case 9:
			max = findMax(root);
			printf("\nMaximum value in the BST is: %d\n", max);
			break;

		case 10:
			height = heightOfTree(root);
			printf("\nHeight of the tree is: %d\n", height);
			break;

		case 11:
			printf("\nExit!");
			break;

		default:
			printf("\nInvalid Chioice!\n");
		}
	} while (choice != 11);
}

//Create a new Node in memory.
struct node *getNewNode(int data)
{
	struct node *newNode = (struct node *)malloc(sizeof(struct node));

	newNode->data = data;
	newNode->left = NULL;
	newNode->right = NULL;

	return newNode;
}

//Insert a new node in the tree.
struct node *insertNode(struct node *root, int data)
{
	struct node *newNode = getNewNode(data);

	/*
	If root node of the tree(or subtree) is NULL,
	make the root point to the newly created node
	This is also the base case of recursion.
	*/
	if (root == NULL)
	{
		root = newNode;
	}

	/*
	Call insertNode() on left subtree,
	passing root->left as the root of the left subtree.
	it will return the parent node of the newly created node,
	and the root->left will get updated.
	call this function recursively on left subtree.
	*/
	else if (data < root->data)
	{
		root->left = insertNode(root->left, data);
	}

	/*
	Call insertNode() on right subtree,
	passing root->right as the root of the right subtree.
	it will return the parent node of the newly created node,
	and the root->right will get updated.
	call this function recursively on right subtree.
	*/
	else if (data > root->data)
	{
		root->right = insertNode(root->right, data);
	}

	return root;
}

struct node *deleteNode(struct node *root, int data)
{
	if (root == NULL)
	{
		return root;
	}

	//Find the node with value 'data'
	else if (data < root->data)
	{
		root->left = deleteNode(root->left, data);
	}
	else if (data > root->data)
	{
		root->right = deleteNode(root->right, data);
	}

	//The node with value 'data' is found.
	else
	{
		//Case 1: the node to be deleted is having no child.
		if ((root->left == NULL) && (root->right == NULL))
		{
			free(root);
			root = NULL; //so that the parent of this node will now point to NULL.
			return root;
		}

		//Case 2: the node to be deleted is having a child.

		//Case 2A: node has only right child.
		else if (root->left == NULL)
		{
			//Make a temporary pointer to root, in order to delete it.
			struct node *temp = root;

			//Make the node point to its right child
			root = root->right;

			//Delete the node from Memory.
			free(temp);
			return root;
		}

		//Case 2B: node has only left child.
		else if (root->right == NULL)
		{
			//Make a temporary pointer to root, in order to delete it.
			struct node *temp = root;

			//Make the node point to its right child
			root = root->left;

			//Delete the node from Memory.
			free(temp);
			return root;
		}

		/*
		Case 3: the node to be deleted is having @ Children.
		We convert this case to Case 1.
		FIRST, find minimum from the right SubTree,
		minimum from the right SubTree will always be greater than
		all the nodes of the left SubTree.
		SECOND, Replace the node to be deleted with the minimum
		of Right SubTree.
		THIRD, Delete the Minimum element, i.e. Rightmost
		node of Right SubTree so as to remove the duplicate.
		*/
		else
		{
			//FIRST:
			int min = findMin(root);
			//SECOND:
			root->data = min;
			//THIRD:
			root->right = deleteNode(root->right, min);

			return root;
		}
	}
}

//Find Height of the BST
int heightOfTree(struct node *root)
{
	int leftHeight, rightHeight;

	//If the root node is null, reurn -1 as height.
	if (root == NULL)
	{
		return -1;
	}

	leftHeight = heightOfTree(root->left);
	rightHeight = heightOfTree(root->right);

	return ((leftHeight > rightHeight) ? leftHeight : rightHeight) + 1;
}

//Find minimum value in BST. min value is leftmost node in the tree.
int findMin(struct node *root)
{
	//If tree is empty, return 0;
	if (root == NULL)
	{
		return 0;
	}

	/*
	If root->left is null,
	it means there is no node to its left;
	*/
	if (root->left == NULL)
	{
		return root->data;
	}

	return findMin(root->left);
}

//Find maximum value in BST. max value is rightmost node in the tree.
int findMax(struct node *root)
{
	//If tree is empty, return 0;
	if (root == NULL)
	{
		return 0;
	}

	/*
	If root->right is null,
	it means there is no node to its right;
	*/
	if (root->right == NULL)
	{
		return root->data;
	}

	return findMax(root->right);
}

int searchNode(struct node *root, int searchValue)
{
	if (root == NULL)
	{
		return 0;
	}

	if (root->data == searchValue)
	{
		return 1;
	}

	if (searchValue < root->data)
	{
		return searchNode(root->left, searchValue);
	}

	else
	{
		return searchNode(root->right, searchValue);
	}
}

//Level Order Display of Binary Search Tree, Breadth First Search.
void levelOrderDisplay(struct node *root)
{
	if (root == NULL)
	{
		return;
	}

	//Insert the root in the Queue.
	insertNodeInQueue(root);

	while (queueNotEmpty())
	{
		struct node *current = queueOfNodes[front];
		printf("%d ", current->data);

		if (root->left != NULL)
		{
			insertNodeInQueue(root->left);
		}

		if (root->right != NULL)
		{
			insertNodeInQueue(root->right);
		}

		popNodeOffQueue();
	}
}

//In Order Display of Binary Search Tree, Depth First Search.
void inOrderDisplay(struct node *root)
{
	if (root == NULL)
	{
		return;
	}

	inOrderDisplay(root->left);
	printf("%d ", root->data);
	inOrderDisplay(root->right);
}

//Pre Order Display of Binary Search Tree, Depth First Search.
void preOrderDisplay(struct node *root)
{
	if (root == NULL)
	{
		return;
	}

	printf("%d ", root->data);
	preOrderDisplay(root->left);
	preOrderDisplay(root->right);
}

//Post Order Display of Binary Search Tree, Depth First Search.
void postOrderDisplay(struct node *root)
{
	if (root == NULL)
	{
		return;
	}

	postOrderDisplay(root->left);
	postOrderDisplay(root->right);
	printf("%d ", root->data);
}

//Queue functions

//To insert a node in the queue
void insertNodeInQueue(struct node *data)
{
	if (rear == MAXSIZE - 1)
	{
		printf("\nQueue is full!\n");
		return;
	}

	//Check if the Queue is empty
	if (front == -1 && rear == -1)
	{
		front = rear = 0;
		queueOfNodes[rear] = data;
		return;
	}

	queueOfNodes[++rear] = data;
}

//Returns 1 if queue is not empty
int queueNotEmpty()
{
	if (rear > -1 && rear < MAXSIZE)
	{
		return 1;
	}

	if (front > rear || front > MAXSIZE)
	{
		return 0;
	}
}

//Pop a node off the queue.
void popNodeOffQueue()
{

	//Check if Queue is empty, if yes then return.
	if (front == -1 && rear == -1)
	{
		printf("\nQueue is empty!\n");
		return;
	}

	if (front == rear)
	{
		front = rear = -1;
	}

	front++;
}