#include <stdio.h>
#include <stdbool.h>

#define ARRAY_SIZE(__a) sizeof(__a)/sizeof(__a[0])

#define PRINT_ARRAY(__a) do {						\
				printf("=>");				\
				for(i=0; i < ARRAY_SIZE(__a); i++)	\
					printf("%d ", __a[i]);		\
				printf("\n");				\
			} while(0)

#define SWAP(__a, __b) do { 				\
				int __t = __a;		\
				__a = __b;		\
				__b = __t;		\
			} while(0)

int a[] = {31,23,34,54,2,3,8,99,34,56,67,65,55,123};
int b[] = {3,2,134,5,2,3,81,19,14,15,16,75,11};

int main(int argc, char **argp)
{
	int i,j,temp;
	int *m = NULL;

	PRINT_ARRAY(a);

	return 0;
}
