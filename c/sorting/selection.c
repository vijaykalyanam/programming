#include <stdio.h>

#define SWAP(__a, __b)	do {		\
			typeof(__a) __c = __a;\
			__a = __b;	\
			__b = __c;	\
			} while(0)

int a[] = {9,1,5,6,4,3,8,2,7,0};
int n = sizeof(a)/sizeof(int);

int main(int argc, char **argp)
{
	int i;
	int j;
	int k;
	int min; 

	for (i = 0; i < n-1; i++) {
	for (k = 0; k < n; k++)
		printf("%d ", a[k]);
	printf("\n");
		min = i;
		for (j = i+1; j < n; j++) {
			if (a[j] < a[min]) {
				min = j;
			}
			SWAP(a[i], a[min]);
		}
	}

	for (i = 0; i < n; i++)
		printf("%d ", a[i]);

	return 0;
}
