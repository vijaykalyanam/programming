#include <stdio.h>
#include <stdlib.h>

void print(int (*p)[], int n)
{

	int i;
	for (i =0; i < n; i++)
		printf("%d ", *(*p+i));
}

int allocate(int n)
{
	int i;
	int (*p)[n];

	p = malloc(sizeof(int)*n);
	for (i = 0; i < n; i++)
		*(*p + i) = i;
	return 0;
}

int main(void)
{
	unsigned int n;
	int a1[4] = {0,1,2,3};
	int a2[3][4] = {
		10,11,12,13,
		20,21,22,23,
		30,31,32,33
	};
	int *p;
	int **pp;
	int *ap[4];

	int (*arp)[4] = &a1;

	int (*ararp[3])[4];
	ararp[0] = &a1;

	ararp[0] = a2;
	ararp[1] = a2+1;
	ararp[2] = a2+2;

	int i,j;

	/* Access 2D using single pointer */
	p = (int *)a2;
	arp = a2;
	print(arp, 4);


	int (*arr)[n] = NULL;
	printf(" Address :%p Value :%p\n", &arr, arr);
/*
	for (i=0; i<3; i++) {
		for (j=0; j<4; j++)
			printf("%d ", *ararp[i][j]);
		printf("\n");
	}
*/
	return 0;
}
