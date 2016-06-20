struct Test
{
	int core;
	int *ptr;
};

int main()
{
	int key = 1;
	int *p = &key;
	//int *pp = &p;
	//int **pp = &p;
	//char **pp = &p;
	struct Test teststruct;
	struct Test *teststructP;
	teststruct.core = 0;
	teststructP->core = 0;
	
	return 0;
}
