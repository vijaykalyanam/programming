#include <stdio.h>
#include <stdlib.h>

void allocateandfree(int len)
{
	int (*p)[len] = NULL;
	p = malloc(sizeof(int)*len);
	free(p);
}

int main(void)
{

	int (*p)[5] = NULL;

	p = malloc(sizeof(int)*5);
	free(p);

	allocateandfree(10);
	allocateandfree(12);
	allocateandfree(120);
	allocateandfree(130);
	allocateandfree(140);

	return 0;
}
