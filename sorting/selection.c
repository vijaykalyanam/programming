#include <stdio.h>

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

int a[] = {31,23,34,54,2,3,8,99,123};

int main(int argc, char **argp)
{
	int i,j,temp;

	PRINT_ARRAY(a);

	for (i = 0; i < ARRAY_SIZE(a)-1; i++) {
		temp = i;
		for (j = i+1; j < ARRAY_SIZE(a); j++)
			if (a[temp] > a[j])
				temp = j;
		if (temp != i)
			SWAP(a[i], a[temp]);
	}

	PRINT_ARRAY(a);

	return 0;
}
