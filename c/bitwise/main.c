#include <stdio.h>

void display(unsigned int); //Ultimate bug
void printbinary(unsigned int);

int main(void) {

	unsigned int x=0x12345678;

	printbinary(x);
	printf("\nRotate Left: 3",x=rotateleft(x,3));
	printbinary(x);

	printbinary(x);
	printf("\nRotate Right:7",x=rotateright(x,7));
	printbinary(x);

	printf("Bits ->\n");
	printbinary(x);
	printf("\nReverse Bits:", x=reversebits(x));

	printf("\nBits -> RightPropage rightmost set bit\n");
	x = x>>5|x<<5;
	printbinary(x);
	printbinary(x-1);
	printbinary(x+1);
return 0;

	printbinary(x);
	unsigned int mask;
	printbinary(x);
	printf("\nBitmanipulations:\n");
	mask = manipulatebits(x, 7, 5);
	printf("\nmask:");
	printbinary(mask);
	puts("unset: 7 th and 5th");
	printbinary(x&(~mask));
	puts("set: 7th and 5th");
	printbinary(x|mask);

	puts("inverse:");
	printbinary(x^mask);


	puts("copy bits from another variable:\n");
	printbinary(0x12345678);
	x=copybits(x, 0x12345678, 7, 5);
	printbinary(x);

	puts("clear rightmost 5 bits\n");
	printbinary(((x<<5)>>5));

	puts("Reverse portion of bits from pos 8 to 15\n");
	printbinary(0x12345678);
	x=reverseportionofbits(0x12345678, 8,15);
	printbinary(x);

	printf("\nRevesebytes :\n");
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

printf("UNDERSTANDING OF INCREMENT AND DECREMENT:\n");
a =0x80;
	puts("a :"); printbinary(a);
	printf("increment :%u\n", a=decrement(a));
	printbinary(a);
printf("---------\n");
b=0x80;
	puts("b :"); printbinary(b);
	printf("decrement :%u\n", b=decrement(b));
	printbinary(b);

	return 0;
}
