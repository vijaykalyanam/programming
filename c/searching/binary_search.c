#include <stdio.h>

#define SWAP(__a, __b)	do {		\
			typeof(__a) __c = __a;\
			__a = __b;	\
			__b = __c;	\
			} while(0)

int a[] = {9,1,5,6,4,3,8,2,7,0,33,12,34,56,35,67,87,89,11,21,31,53,32,67,89,90,99};
int n = sizeof(a)/sizeof(int);

int binary_search(int *p, int data, int left, int right)
{
	int mid;

	if (left > right)
		return -1;

	mid = (left + right)/2;

	if (data < p[mid])
		right = mid - 1;
	else if (data > p[mid])
		left = mid+1;
	else
		return mid;
	return binary_search(p, data, left, right);
}

int main(int argc, char **argp)
{
	printf("Index of data :%d is at :%d\n", 199, binary_search(a, 199, 0, n));
	return 0;
}
