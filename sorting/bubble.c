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

int a[] = {31, 23, 34, 54, 2, 3, 8, 99, 123, 44, 56, 7, 11, 19};

int main(int argc, char **argp)
{
	int i,j,temp;

	PRINT_ARRAY(a);

	for (i = 0; i < ARRAY_SIZE(a)-1; i++) {
		temp = false;
		for (j = 0; j < ARRAY_SIZE(a)-i-1; j++)
			if (a[j] > a[j+1]) {
				SWAP(a[j], a[j+1]);
				temp = true;
			}
		if (!temp)
			break;
	}

	PRINT_ARRAY(a);

	return 0;
}
