#include <stdio.h>

#define SWAP(__a, __b)	do {		\
			typeof(__a) __c = __a;\
			__a = __b;	\
			__b = __c;	\
			} while(0)

int a[] =
#if 1 
{9,1,5,6,4,3,8,2,7,0};
#else
{1,11,22,33,44,55,66,77,88};
#endif
int n = sizeof(a)/sizeof(int);

int main(int argc, char **argp)
{
	int i;
	int j;
	int k;
#if 0
	int swapped;
#else
	int swapped = !0;
#endif
	for (i = 0; i < n-1 && swapped; i++) {
#if 1 
		for (k = 0; k < n; k++)
			printf("%d ", a[k]);
		printf("\n");
#endif
		swapped = 0;
		for (j = i+1; j < n; j++) {
			if (a[j] < a[i]) {
				SWAP(a[j], a[i]);
				swapped = 1;
			}
		}
#if 0
		if (!swapped)
			break;
#endif
	}
	for (i = 0; i < n; i++)
		printf("%d ", a[i]);

	return 0;
}
