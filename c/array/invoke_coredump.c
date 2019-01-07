#include <stdio.h>
#include <stdlib.h>

void mergeandprint(int a1[], int a2[], int len1, int len2)
{
	int i,j,k, len3 = len1+len2;
	int (*a3)[len3];
printf("1\n");
	a3 = (int (*)[len3])calloc(1, len3*sizeof(int));

printf("1\n");
	for (i=0,j=0,k=0; i<len1 && j<len2;)
		if (a1[i] < a2[j])
			*a3[k++] = a1[i++];
		else
			*a3[k++] = a2[j++];
printf("1\n");
	while (i<len1)
		*a3[k++] = a1[i++];

printf("1\n");
	while (j<len2)
		*a3[k++] = a2[j++];

printf("1\n");
	for (i =0; i<k-1; i++)
		printf("%d ", *a3[i]);

printf("1\n");
	free(a3);
}

void main(void)
{

	int a1[] = {1, 11,31,51,71};
	int a2[] = {2,22,42,62,82,88,91,92,93,95};

	mergeandprint(a1, a1, sizeof(a1)/sizeof(int), sizeof(a2)/sizeof(int));
}
