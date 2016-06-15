#include <stdio.h>
// create two arrays we care about
int ages[] = {23, 43, 12, 89, 2};
char *names[] = {
	"Alan", "Frank",
	"Mary", "John", "Lisa"
};

// setup the pointers to the start of the arrays
int *cur_age = ages;
char **cur_name = names;

// safely get the size of ages
int count = sizeof(ages) / sizeof(int);
int i = 0;


void reversePrint(char** toBeReversedName, int* toBeReversedAge); 

void reversePrint(char** toBeReversedName, int* toBeReversedAge)
{
	printf("---\n");

	for(toBeReversedName = names + count-1, toBeReversedAge = ages + count-1;
			toBeReversedAge > ages- 1;
			toBeReversedName--, toBeReversedAge--)
	{
		printf("%s lived %d years REVERSE.\n",
				*toBeReversedName, *toBeReversedAge);
	}
}

int main(int argc, char *argv[])
{
	// first way using indexing
	for(i =0; i < count; i++){
		printf("%s has %d years alive.\n",
				names[i], ages[i]);
	}

	printf("---\n");


	// second way using pointers
	for (i = 0; i < count; i++){
		printf("%p is %p years old.\n",
				*(cur_name+i), *(cur_age+i));
	}

	printf("---\n");

	// third way, pointers are just arrays
	for(i = 0; i < count; i++){
		printf("%s is %d years old again.\n",
				cur_name[i], cur_age[i]);
	}

	printf("---\n");

	// fourth way with pointers in a stupid complex way
	for(cur_name = names, cur_age = ages;
			(cur_age - ages) < count;
			cur_name++, cur_age++)
	{
		printf("%s lived %d years so far.\n",
				*cur_name, *cur_age);
	}

	reversePrint(cur_name, cur_age);

	printf("---\n");

	return 0;
}
