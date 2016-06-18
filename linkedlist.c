#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

struct Node
{
	// pointer to a node struct called next
	struct Node *next;
	// int data to be printed
	int data;
};

struct Node *node_create(int data)
{
	// new node must be allocated from the heap
	struct Node *new = malloc(sizeof(struct Node));
	// next will always be null for the last node created
	new->next = 0;
	new->data = data;

	return new;
}

struct List
{
	// pointer to a node struct called head
	struct Node *head;
};

// create the list with data for first head node as a parameter
struct List *list_create(int headData)
{
	struct List *linkedList = malloc(sizeof(struct List));
	linkedList->head = node_create(headData);

	return linkedList;
};

void List_destroy(struct List *list)
{
	
}

void print(struct List *list)
{
	while(list->head->next != 0)
		printf("%d\n", list->head->data);
}

int main()
{
	struct List *newList = list_create(3);
	print(newList);
	return 0;
}
