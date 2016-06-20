#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

struct node
{
	int data;
	int key;
	// the self-referencing aspect which makes linked lists possible
	// the node itself has a node pointer to the next node
	struct node *next;
};

// a NULL pointer which is ready to hold a list
struct node *head = NULL;
// a NULL pointer which is ready to hold the last node
struct node *current = NULL;

void printList()
{
	// a copy of the head node that
	struct node *ptr = head;
}
