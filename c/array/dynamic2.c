#include <stdio.h>
#include <stdlib.h>
#if 0
static void dynamic_alloc(int (*p)[][10], int n) {
}
#endif

static void dynamic_alloc(int m, int n, int (**p)[m][n]) {
}

int main(void)
{

	unsigned int m,n,i,j;
	int (*p)[m][n] = NULL;
	printf("Enter No of 1D arrays:");
	scanf("%d", &m);
	printf("\nEnter No of 1D arrays elements:");
	scanf("%d", &n);
	printf("\n");
	p = malloc(sizeof(int)*m*n);
	int (*q)[n] = *p;

	printf(" p :%p *p :%p **p :%p ***p :%d\n", p, *p, **p, ***p);
	printf(" p :%p p+1 :%p *p+1 :%p\n", p, p+1, *p+1);

	/* p - pointer to entire 2D array. *p will give you 1D array */ 
	/* Performing operations like *p+1 - > will lead invalid memory access */
	/* int (*q)[n] = *p; */

	for (i = 0; i < m; i++)
	for (j = 0; j < n; j++)
		printf("%d ",*(*(q + i)+j));
	printf("\n");

	for (i = 0; i < m; i++)
	for (j = 0; j < n; j++)
		*(*(q + i)+j) = i*j+i+j;

	for (i = 0; i < m; i++, printf("\n"))
	for (j = 0; j < n; j++)
		printf("%d ",*(*((int (*)[n])(*p) + i)+j));
	printf("\n");
#if 0
		/* SEG FAULT : *p+1 */
		printf("%d ",*(*(*p + i)+j));
#endif

		int (*a)[] = NULL;
		a = (int (*)[]) calloc(1, sizeof(int)*10);

		/* This will give compile time error as Sizeof 1D array is not known */
		//int (*b)[][] = NULL;
		int (*b)[][n] = NULL;
		dynamic_alloc(5, 10, &b);
	return 0;
}
