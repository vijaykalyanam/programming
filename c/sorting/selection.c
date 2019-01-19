#include <stdio.h>

#define SWAP(__a, __b)	do {		\
			typeof(__a) __c = __a;\
			__a = __b;	\
			__b = __c;	\
			} while(0)

int a[] = {9,1,5,6,4,3,8,2,7,0};
int n = sizeof(a)/sizeof(int);
/* Not a stable sorting tech */
int main(int argc, char **argp)
{
	int i;
	int j;
	int k;
	int min; 

	for (i = 0; i < n-1; i++) {
#if 1 
		for (k = 0; k < n; k++)
			printf("%d ", a[k]);
		printf("\n");
#endif	
		min = i;
		//for (j = i+1; j < n-1; j++) {
		for (j = i+1; j < n; j++) {
			if (a[j] < a[min]) {
				min = j;
			}
		}
		if (min != i)
		    SWAP(a[i], a[min]);
	}

	for (i = 0; i < n; i++)
		printf("%d ", a[i]);

	return 0;
}
