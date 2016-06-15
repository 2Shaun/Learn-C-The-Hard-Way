#include <stdio.h>
// allows for assert() functions
#include <assert.h>
// allows malloc(), sizeof() and free()
#include <stdlib.h>
// allows strdup()
#include <string.h>

// reserves bytes in memory for a class-like structure
// which holds a "Person"'s name, age, height, weight
struct Person {
	char *name;
	int age;
	int height;
	int weight;
};

struct Person *Person_create(char *name, int age, int height, int weight)
{
	// malloc asks the OS to reserve a piece of raw memory
	// the size of the Person struct with all the fields inside
	// then returns it
	struct Person *who = malloc(sizeof(struct Person));
	// making sure malloc didn't return a NULL invalid pointer
	assert(who != NULL);

	// -> allows us to set different parts of the struct
	// strdup duplicates the string for the name
	// it copies the original string into the memory it creates
	who->name = strdup(name);
	// gets the age field from who and assigns the argument
	who->age = age;
	// gets the height field from who and assigns the argument
	who->height = height;
	// gets the weight field from who and assigns the argument
	who->weight = weight;

	// returns the new struct
	return who;
}

// every create needs a destroy function
void Person_destroy(struct Person *who)
{
	// makes sure who isn't already empty
	assert(who != NULL);

	// frees the memory space used by the name field
	// which was returned by strdup
	free(who->name);
	// frees the memory space used by the who struct
	// which was returned by malloc
	free(who);
}

void Person_print(struct Person *who)
{
	printf("Name: %s\n", who->name);
	printf("\tAge: %d\n", who->age);
	printf("\tHeight: %d\n", who->height);
	printf("\tWeight: %d\n", who->weight);
}

int main(int argc, char *argv[])
{
	// make two people structures
	struct Person *joe = Person_create(
			"Joe Alex", 32, 64, 140);

	struct Person *frank = Person_create(
			"Frank Blank", 20, 72, 180);

	// print them out and where they are in memory
	printf("Joe is at memory location %p:\n", joe);
	Person_print(joe);

	// note that the locations are 11 units apart
	printf("Frank is at memory location %p:\n", frank);
	Person_print(frank);

	//Person_print(NULL);
	
	// make everyone age 20 years and print them again
	joe->age += 20;
	joe->height -= 2;
	joe->weight += 40;
	Person_print(joe);

	frank->age += 20;
	frank->weight += 20;
	Person_print(frank);

	// destroy them both so we clean up
	Person_destroy(joe);
	Person_destroy(frank);

	return 0;
}
