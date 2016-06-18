#include <stdio.h>

// a struct of pointers
struct pointers
{
	int *pt;
};

// a struct of pointers to structs of pointers
struct pointersToStructs
{
	struct pointers *pts;
};

// a struct of pointers to structs of pointers to structs of pointers
struct pointersToPointersToStructs
{
	struct pointersToStructs *ptpts;
};

int main()
{
	// int pointer
	int *p;
	// int double pointer
	int **pp;
	// int triple pointer
	int ***ppp;
	int x;

	x = 8;
	p = &x;
	pp = &p;
	ppp = &pp;

	printf("%d\n", *p);
	printf("%d\n", **pp);
	printf("%d\n", ***ppp);

	// Named PointerStruct because it's a Structure of Pointers
	struct pointers testPointerStructs;
	testPointerStructs.pt = &x;
	printf("%d\n", *testPointerStructs.pt);

	struct pointersToStructs testStructPointers;
	testStructPointers.pts = &testPointerStructs;
	// dereferences pts to receive the structure
	// then dereferences the final int pointer pt
	// in other words, success
	printf("%d\n", *(*testStructPointers.pts).pt);
	// this dereferences pt as a member of the address of pts (nonsensical)
	// printf("%d\n", *testStructPointers.pts.pt);
	// this dereferences pts but
	// never dereferences the final int pointer pt
	// printf("%d\n", (*testStructPointers.pts).pt)
		
	struct pointersToPointersToStructs testStructPointerPointers;
	testStructPointerPointers.ptpts = &testStructPointers;
	printf("%d\n", *(*(*testStructPointersPointers.ptpts.)pts.)pt);
	printf("%d\n", *(*(*testStructPointerPointers.ptpts).pts).pt);
	
	return 0;
}
