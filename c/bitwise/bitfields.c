#include <stdio.h>
#include <string.h>
#include <limits.h>

#include <unistd.h> //for sleep
#define SIZE (sizeof(unsigned int)*CHAR_BIT-1)

void display(unsigned int x) {
	unsigned int i;     //unsigned int never become negative number. loop will never ends.
	for(i=31; i>=0; i--)
		if(x&(1<<i)) printf("1"); else printf("0");
	printf("\n");
	return;
}

void printbinary(unsigned int x) {
	int i;
	for (i=31; i>=0; i--) {
		if (x&(1<<i)) printf("1"); else printf("0");
		if (i%8==0) printf(" ");
	}
	printf("\n");
	return;
}

void printbinary64(unsigned long int x)
{
	int i;
	unsigned long int shift=1;
	for (i=63; i>=0; i--) {
		if (x & (shift<<i))
			printf("1");
		else
			printf("0");
		if (i%8==0) printf(" ");
/*
		printf("i:%lu shift<<i :%lu\n", i, shift<<i);
		sleep(2);
*/
	}
	printf("\n");
	return;
}

int main(void) {

#if 1 
	union pack {
#else
		struct pack {
#endif
		unsigned int c1:8;
		unsigned int c2:8;
		unsigned int c3:8;
		unsigned int c4:8;
#if 1 
		unsigned int p;
#else
#endif
	};
#if 1 
	union pack data;
	data.p = 0x60616263;
#else
	struct pack data;
	data = 0x60616263;
#endif
	printf(" %c %c %c %c %x\n", data.c1, data.c2, data.c3, data.c4, data);

	return 0;
}
