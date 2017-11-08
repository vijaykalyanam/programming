#include <stdio.h>

void display(unsigned int); //Ultimate bug
void printbinary(unsigned int);

int main(void) {

	unsigned int x=0x12345678;

	printbinary(x);
	printf("Rotate Left: 3\n",x=rotateleft(x,3));
	printbinary(x);
	printf("Rotate Right:7\n",x=rotateright(x,7));
	printbinary(x);

	printf("Reverse Bits:\n", x=reversebits(x));
	printbinary(x);

	unsigned int mask;
	mask = manipulatebits(x, 7, 5);
	puts("unset:");
	printbinary(x&(~mask));
	puts("set:");
	printbinary(x|mask);

	puts("inverse:");
	printbinary(x^mask);


	puts("copy bits from another variable:\n");
	printbinary(0x12345678);
	x=copybits(x, 0x12345678, 7, 5);
	printbinary(x);

	puts("clear rightmost 5 bits\n");
	printbinary(((x<<5)>>5));

	puts("reverse portion of bits from pos 4 to 7\n");
	printbinary(0x12345678);
	x=reverseportionofbits(0x12345678, 8,15);
	printbinary(x);

	printf("revesebytes :\n");
	printbinary(0x12345678);
	x=reversebytes(0x12345678);
	printbinary(x);

	int y=0x1;
	printf("Count bits :\n");
	printbinary(x);
	printbinary(y);
	printbinary(x^y);
	printf("count :%d\n", countbits(x^y));

	unsigned int a=0x80000000, b=0x80000000;
	puts("a :"); printbinary(a);
	for(int i=0; i<3; i++) {
		printf("increment :%u\n", a=increment(a));
		printbinary(a);
	}
//b=0x80;
	puts("b :"); printbinary(b);
	for(int i=0; i<3; i++) {
		printf("decrement :%u\n", b=decrement(b));
		printbinary(b);
	}

	return 0;
}
