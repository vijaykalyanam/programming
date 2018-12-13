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
		one = 100,
		two,
		three,
		four,
		five,
		six,
		seven,
		eight,
		nine,
		ten
	} n;

	printf("size of :%d %d\n", sizeof n, n); 
	enum count t;
	printf("default value of enum t :%d\n", t);
	int *p = &t;
	printf(" -> %d\n", *p);
	n=4;
	printf("n value assigned :%d\n", n);
	int i;

	for(i=0; i<20; i++) if (i%2 == 0) if (i == four) printf("four"); //No output.
	for(i=0; i<20; i++) if (i == four) printf("four");//No outut
	for(i=0; i<20; i++) if (i%2 == 0) if (i == n) printf("n value :%d\n", n); //Value is 4
	return 0;
}
