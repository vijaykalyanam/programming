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
	int len, len1, len2; 
	int a1[5], a2[5];

	/* Get array Length */
	len = sizeof(a)/sizeof(a[0]);
	len1 = len/2;
	/* If odd number of elements, then we miss one */
	len2 = len - len1;

	for (k = 0; k < n; k++)
		printf("%d ", a[k]);
	printf("\n");
	int min, max;
	if (a[0] < a[1]) {
		min = a[0];
		max = a[1];
		a1[0] = a[0];
		a2[0] = a[1];
	} else {
		min = a[1];
		min = a[0];
		a1[0] = a[1];
		a2[0] = a[0];
	}

	for (i = 2; i < n; i++) {

		if (a[2] <= a1[j]) {
			a[j] = a[2];
			j++;
		} else if (a[2] <= a1[k]) {
			a[k] = a[2];
			k++;
		}
	}

	for (i = 0; i < n; i++)
		printf("%d ", a[i]);

	return 0;
}
