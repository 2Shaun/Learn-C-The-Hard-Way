#include <stdio.h>
#include <stdlib.h>
#define MAX_DATA 512

int lastElement = -1;

struct Stack {
	int stackArray[MAX_DATA];
};

void push(struct Stack *stack, int element) {
	if (lastElement >= MAX_DATA-1){
		printf("Stack is full");
		return;
	}
	++lastElement;
	stack->stackArray[lastElement] = element;
}

int pop(struct Stack *stack){
	if (lastElement == -1){
		printf("Stack is empty");
		return -1;
	}
	int retVal = stack->stackArray[lastElement];
	--lastElement;
	return retVal;
}

int main()
{
	struct Stack *s = malloc(sizeof(struct Stack));
	push(s, 1);
	push(s, 2);
	push(s, 3);
	push(s, 4);
	push(s, 5);
	printf("%d\n", pop(s));
	printf("%d\n", pop(s));
	printf("%d\n", pop(s));
	printf("%d\n", pop(s));
	printf("%d\n", pop(s));
	printf("%d\n", pop(s));
	free(s);
	return 0;
}
