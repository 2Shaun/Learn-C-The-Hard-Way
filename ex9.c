#include <stdio.h>

int numbers[4] = {1}; // C fills the rest of the elements with 0

int main(int argc, char *argv[])
{
	char *name = "H";

	// first, print them out raw
	printf("numbers: %d %d %d %d\n",
			numbers[0], numbers[1],
			numbers[2], numbers[3]);

	printf("name each: %c %c %c %c\n",
			name[0], name[1],
			name[2], name[3]);

	printf("name: %s\n", name);

	// setup the numbers
	numbers[0] = 'x';
	numbers[1] = 'x';
	numbers[2] = 3;
	numbers[3] = 4;

	// setup the name
	name[0] = 'T';
	name[1] = 'o';
	name[2] = 'm';
	name[3] = 'm';
	name[4] = 'y';
	name[5] = '\0';

	// then print them out intialized
	printf("numbers: %d %d %d %d\n",
			numbers[0], numbers[1],
			numbers[2], numbers[3]);

	printf("name each: %c %c %c %c %c %c\n",
			name[0], name[1],
			name[2], name[3],
			name[4], name[5]);

	// print the name like a string
	printf("name: %s\n", name);

	// another way to use name
	char *another = "Tommy";

	printf("another: %s\n", another);

	printf("another each: %c %c %c %c %c\n",
			another[0], another[1],
			another[2], another[3],
			another[4]); 

	return 0;
}
