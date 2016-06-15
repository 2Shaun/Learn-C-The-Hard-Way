#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

// same as heap struct
struct Person {
	char *name;
	int age;
	int height;
	int weight;
};

// no dereference
struct Person Person_create(char *name, int age, int height, int weight)
{
	// no need to use malloc
	// or assert that it doesn't receive a NULL parameter
	struct Person who;
	// no need for -> operator
	who.name = strdup(name);
	who.age = age;
	who.height = height;
	who.weight = weight;

	return who;
}

// no need for deconstructor

void Person_print(struct Person who)
{
	printf("Name: %s\n", who.name);
	printf("\tAge: %d\n", who.age);
	printf("\tHeight: %d\n", who.height);
	printf("\tWeight: %d\n", who.weight);
}

int main(int argc, char *argv[])
{
	struct Person joe = Person_create(
			"Joe Alex", 32, 64, 140);

	struct Person frank = Person_create(
			"Frank Blank", 20, 72, 180);

	printf("Joe is at memory location %p:\n", joe);
	Person_print(joe);

	printf("Frank is at memory location %p:\n", frank);
	Person_print(frank);

	joe.age += 20;
	joe.height -= 2;
	joe.weight += 40;
	Person_print(joe);

	frank.age += 20;
	frank.weight += 20;
	Person_print(frank);

	free(joe.name);
	free(frank.name);

	return 0;
}
