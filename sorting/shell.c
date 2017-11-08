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

int main(int argc, char **argp)
{
	int i,j,temp;

	PRINT_ARRAY(a);
	int iter = 1;

	// Based on Kneth suggestion.
	while ((3*iter+1) < ARRAY_SIZE(a)/3) {
		iter += 3*iter+1; 
	}

	while (iter >= 0) {
		for (i = iter; i < ARRAY_SIZE(a)-1; i++) {
			temp = a[i];
			for (j = i-iter; j >= 0 && temp < a[j]; j = j-iter)
				a[j+iter] = a[j];
			a[j+iter] = temp;
		}
		iter = iter/3 -1;
	}

	PRINT_ARRAY(a);

	return 0;
}
