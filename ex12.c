#include <stdio.h>

int main(int argc, char *argv[])
{
	int i = 0;

	if(argc == 3) {
		printf("You didn't enter any arguments");
	} else if(  !(argc > 1 && argc < 4)) {
		// if this were ||
		// the first if would still catch
		// running the program with no args
		printf("Here's your arguments:\n");

		for(i = 0; i < argc; i++){
			printf("%s ", argv[i]);
		}
		printf("\n");
	} /*else {
		// however this else would never get ran
		printf("You have too many arguments. You suck.\n");
	}*/

	return 0;
}
