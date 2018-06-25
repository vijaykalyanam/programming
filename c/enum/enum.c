/*
 * No matter what sizeof(n) is sizeof(int)
 * This is compile time replacement.
 * They can report Meaningful errors.
 * But, #define is done in preprocessing state and they do not do 
 *      Any type checking, which can be more error prone. 
 */

#include <stdio.h>

int main() {

	enum count {
		one,
		two,
		three,
		four,
		five,
		six,
		seven,
		eight,
		nine,
		ten
	}n;
	printf("size of :%d %d\n", sizeof n, n); 
	int *p = &n;
	printf("%d\n", *p);
n=4;
n=356;
printf("n value assigned :%d\n", n);
int i;
for(i=0; i<20; i++) if (i%2 == 0) if (i == four) printf("four");
for(i=0; i<20; i++) if (i%2 == 0) if (i == n) printf("n value :%d\n", n);
	return 0;
}
