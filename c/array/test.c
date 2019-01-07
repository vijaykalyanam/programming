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
	//n = 4;
	printf("\n");
	p = malloc(sizeof(int)*m*n);
	int (*q)[n];
	q = *p;
	printf("1\n");

	for (i = 0; i < m; i++)
	for (j = 0; j < n; j++)
		printf("%d ",*(*(q + i)+j));
	printf("\n");
	printf(" q :%p q+1 :%p\n", q, q+1); 
	printf(" p :%p *p :%p **p :%p ***p :%d\n", p, *p, **p, ***p);

	printf(" p :%p p+1 :%p *p+1 :%p\n", p, p+1, *p+1);
	for (i = 0; i < m; i++)
		printf("p = %p\n", *p + i); 

	return 0;
}
