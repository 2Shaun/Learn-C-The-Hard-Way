#include <stdio.h>


int main(int argc, char *argv[])
{
	char full_name[] = {
		'T', 'o', 'm', 'm', 'y',
		' ', 'W', '.', ' ',
		'O', '\'', 
		'S', 'h', 'a', 'u', 'g', 'h', 'n', 'e', 's', 's', 'y', '\0'
	};
	unsigned int cap = 4294967295;
	int areas[] = {'T', 12, 13, 14, 20};
	char name[] = "Tommy";
/*	char full_name[] = {
		'T', 'o', 'm', 'm', 'y',
		' ', 'W', '.', ' ',
		'O', '\'', 
		'S', 'h', 'a', 'u', 'g', 'h', 'n', 'e', 's', 's', 'y', '\0'
	};*/

	// WARNING: On some systems you may have to change the
	// %ld in this code to a %u since it will use unsigned ints
	printf("The size of an int: %ld\n", sizeof(int));
	printf("The size of areas (int[]): %ld\n", sizeof(areas));
	printf("The number of ints in areas: %ld\n", 
			sizeof(areas) / sizeof(int));
	printf("The first area is %c, the 2nd %c.\n",
			areas[0], full_name[1]);

	printf("The size of a char: %ld\n", sizeof(char));
	printf("The size of name (char[]): %ld\n", sizeof(name));
	printf("The number of chars: %ld\n",
			sizeof(name) / sizeof(char));

	printf("The size of full_name (char[]): %ld\n",
			sizeof(full_name));
	printf("The number of chars: %ld\n",
			sizeof(full_name) / sizeof(char));

	printf("name=\"%s\" and full_name=\"%s\"\n",
			name, full_name);

	printf("%d\n", cap);

	return 0;
}

