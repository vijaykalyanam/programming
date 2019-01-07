#include <stdio.h>
#include <stdlib.h>

void mergeandprint(int a1[], int a2[], int len1, int len2)
{
	int i=0,j=0,k=0, len3 = len1+len2;
	int (*a3)[len3] = NULL;

	a3 = malloc(len3*sizeof(int));
	int *p = *a3;
#if 1 
	for (i=0,j=0,k=0; i<len1 && j<len2;)
		if (a1[i] < a2[j])
//			*a3[k++] = a1[i++];
			p[k++] = a1[i++];
		else
//			*a3[k++] = a2[j++];
			p[k++] = a2[j++];


	while (i<len1)
		//*a3[k++] = a1[i++];
		p[k++] = a1[i++];


	while (j<len2)
		//*a3[k++] = a2[j++];
		p[k++] = a2[j++];
#endif
#if 1 
	for (i =0; i<k; i++)
		printf("%d ",((int *)(*a3))[i]);

#endif
	/* Causing core dump level issue */
	free(a3);
}

void main(void)
{

	int a1[] = {1,11,31,51,71};
	int a2[] = {2,22,42,62,82,88,91,92,93,95};

	mergeandprint(a1, a2, sizeof(a1)/sizeof(int), sizeof(a2)/sizeof(int));
}
