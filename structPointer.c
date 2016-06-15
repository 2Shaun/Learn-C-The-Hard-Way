#include <stdio.h>
#include <limits.h>

struct Person
{
	//int age;
};

int main()
{
	struct Person tommy;
	//tommy.age = 24;
	struct Person* ptr = &tommy;
	printf("size of char: %d\n", CHAR_BIT);
	printf("size of Person: %d\n", sizeof(struct Person));
	//printf("ptr->age: %d\n", ptr->age);
	
}
