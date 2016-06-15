#include <stdio.h>

int main(int argc, char *argv[])
{
	int i = 0;
	
	// go through each string in argv
	// why am I skipping argv[0]?
	char *states[] = {
		"Pennsylvania", "Oregon",
		"Washington", "Texas"
	};
	
	argv[0] = states[0];
	
	for (i = 0; i < argc; i++){
		printf("arg %d: %s\n", i, argv[i]);
		if (i == 3)
			break;
	}

	states[0] = argv[1];

	// let's make our own array of strings
	// this array is two dimensional
	// each string is one element
	// each character being another
	int num_states = 4;

	for(i = 0; i < num_states; i++){
		printf("state %d: %s\n", i, states[i])	;
		printf("state %d: %c\n", i, states[0][i]);
	}

	return 0;
}

/* for(INTIALIZER; TEST; INCREMENTER) {
 * 	CODE;
 * }
 *
 * INTIALIZER code that is run to setup loop
 * TEST if false loop doesn't run
 * CODE does what it do
 * INCREMENTER is run
 * TEST...
 */
