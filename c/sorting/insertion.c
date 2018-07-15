/*
 * Insertion Sort:  Divide array into two parts : sorted and unsorted.
 * Single element is always sorted. So, 0th element is reference for us.
 * array starting from arr[1] is unsorted.
 * outer loop is picking unsorted array.
 * Inner loop is for sorted array.
 */

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
	int unsorted; 

	for (i = 1; i < n; i++) {
		unsorted = a[i];
		j = i-1;
	for (k = 0; k < n; k++)
                printf("%d ", a[k]);
        printf("\n");

		while(a[j] > unsorted && j >= 0) {
			a[j+1] = a[j];
			j--;
		}
		a[j+1] = unsorted; 
	}

	for (i = 0; i < n; i++)
		printf("%d ", a[i]);

	return 0;
}
