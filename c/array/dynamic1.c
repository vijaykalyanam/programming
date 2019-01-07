#include <stdio.h>
#include <stdlib.h>

int main(void)
{

	unsigned int n, i;
	int (*p)[n] = NULL;

	printf("Enter array len:");
	scanf("%d", &n);

	printf("\n");
	p = malloc(sizeof(int) * n);

	for (i = 0; i < n; i++)
		printf("%d ",*(*p + i));
	printf("\n");

	for (i = 0; i < n; i++)
		*(*p + i) = i;
	for (i = 0; i < n; i++)
		printf("%d ",*(*p + i));
	printf("\n");
	return 0;
}
