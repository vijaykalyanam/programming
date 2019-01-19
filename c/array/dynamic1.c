#include <stdio.h>
#include <stdlib.h>

static void dynamic_alloc(int (**p)[], int n)
{
	if (*p)
		free(*p);
	*p = (int (*)[])malloc(sizeof(int)*n);
}

int main(void)
{

	unsigned int n, i;
	int (*p)[] = NULL;

	printf("Enter array len:");
	scanf("%d", &n);

	printf("\n");
	p = (int (*)[])malloc(sizeof(int) * n);

	for (i = 0; i < n; i++)
		printf("%d ",*(*p + i));
	printf("\n");

	for (i = 0; i < n; i++)
		*(*p + i) = i;


	for (i = 0; i < n; i++)
		printf("%d ",*(*p + i));
	printf("\n");


	int (*q)[] = NULL;
	n = 10;
	dynamic_alloc(&q, n);
	for (i = 0; i < n; i++)
		printf("%d ",*(*q + i));
	printf("\n");


	return 0;
}
