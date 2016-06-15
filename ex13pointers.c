#include <stdio.h>

int main(int argc, char *argv[])
{
	if(argc != 2){
		printf("ERROR: You need one argument.\n");
		// this is how you abort a program
		return 1; // returning a non-zero indicates error
	}

	int i, o  = 0;
	char** argvPointer = argv;
	char* argvPointer2 = argvPointer[0];
	
	for (i = 0; i < 10; i++){
		printf("pointer: %c", argvPointer+i);
		printf("\n");
		for (o = 0; o < 10; o++)
			printf("%c", (*argvPointer)[o]);
		printf("\n");
	}


	for(i = 0; argv[1][i] != '\0'; i++) {
		char letter = argv[1][i];

		// each case is a jump
		switch(letter) { // Y
			case 'a':
			case 'A': // Y + 'A'
				printf("%d: 'A'\n", i);
				break; 	// so we need to break out
					// to keep 'E' from running

			case 'e':
			case 'E': // Y + 'E'
				printf("%d: 'E'\n", i);
				break;

			case 'i':
			case 'I':
				printf("%d: 'I'\n", i);
				break;

			case 'u':
			case 'U':
				printf("%d: 'U'\n", i);
				break;

			case 'y':
			case 'Y':
				if(i > 2) {
					// it's only sometimes Y
					printf("%d: 'Y'\n", i);
					break;
				}

			default: // Y + default
				printf("%d: %c is not a vowel\n", i, letter);
				// no need to break here since the code
				// continues to run from here
				// "fallthrough" comment
				// would be added if this were a case
		}
	}

	return 0;
}
