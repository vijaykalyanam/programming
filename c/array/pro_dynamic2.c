#include <stdio.h>
#include <stdlib.h>

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
		printf("%d ", *(*(q + i)+j));
	printf("\n");


	return 0;
}
