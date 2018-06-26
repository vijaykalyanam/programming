/*
 * Rule 1: Shifting R/L to N times, => Bits upto Nth are vanished(Not the Nth Bit).
 *         Take the Reference always from 0 to 31.
 *         Interpret : '31-n+1' --> SHIFTING
 * Rule 2: Reverse Bits: SIZE-i only.
 * Rule 3: Decrement 
 * b :
 * 00000000 00000000 00000000 10000000 
 * i :7
 * 11111111 11111111 11111111 10000000 
 * 00000000 00000000 00000000 01111111 
 * 00000000 00000000 00000000 11111111 
 * mask : 00000000 00000000 00000000 11111111 
 * decrement :127
 * 00000000 00000000 00000000 01111111 
 */

#include <stdio.h>
#include <string.h>
#include <limits.h>

#define SIZE (sizeof(unsigned int)*CHAR_BIT-1)

void display(unsigned int x) {
	unsigned int i;
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

void printbinary64(unsigned long int x) {
	// unsigned long int i; This will lead to infinite loop
	int i;
	unsigned long int mask = 0x1;

	for (i=63; i>=0; i--) {
		if (x & (mask << i))
			printf("1");
		else
			printf("0");
		if (i%8==0)
			printf(" ");
	}
	printf("\n");
	return;
}

unsigned int countbits(unsigned int x) {
	unsigned int count = 0;
//	while(x=x&(x-1)) count++;
	if(!x) return count;

	do {
		count++; 
	}while(x=x&(x-1));

	return count;
}

unsigned int rotateleft(unsigned int x, unsigned int i) {
	return (x<<i)|(x>>(SIZE-i+1));
}

unsigned int rotateright(unsigned int x, unsigned int i) {
	return (x>>i)|(x<<(SIZE-i+1));
}

unsigned int reversebits(unsigned int x) {

	unsigned int val=0;

	for(int i=0; i<=SIZE; i++)
		if(x&(1<<i))
			val |= 1<<SIZE-i;
	return val;
}

unsigned int manipulatebits(unsigned int x, unsigned int pos, unsigned int n) {
	unsigned int mask;
	mask = ~((~0)<<n)<<pos;
	mask = ~((~0)<<n)<<(pos-n+1);
return mask;
}

unsigned int copybits(unsigned int x, unsigned int y, unsigned int pos,
		unsigned int n) {

	unsigned int mask = ~((~0)<<n)<<pos-n+1;

	x &= ~mask;
	mask = mask&y;
	x |= mask;
	return x;
}

unsigned int reverseportionofbits(unsigned int x, int i, int j) {

i = 0, j = 31;
	for(;i<j; i++,j--)
#if 1 
		if( !!(x&(1<<i)) != !!(x&(1<<j)) )
			x^=(1<<i)|(1<<j);
#elif 1 
		if( !!(x&(1<<i)) != !!(x&(1<<(31-i))) )
			x^=(1<<i)|(1<<(31-i));
#else
		if( ((x&(1<<i)) && !(x&(1<<j))) ||
				(!(x&(1<<i)) && (x&(1<<j)))  )
			x^=(1<<i)|(1<<j);
#endif
	return x;
}

unsigned int reversebytes(unsigned int x) {
	return (x>>24|x<<24|(x&0x00FF0000)>>8|(x&0x0000FF00)<<8);
}

unsigned int increment(unsigned int x) {
	unsigned int mask, i;

	for(i=0; i<=sizeof(unsigned int)*CHAR_BIT-1; i++)
		if(!(x&(1<<i))) break;

	printf("i :%d\n", i);
	mask = ~(~0<<i+1);
printbinary(~0<<i+1);
printbinary(~(~0<<i+1));
	printbinary(mask);

	return x^mask;
}

unsigned int decrement(unsigned int x) {
	unsigned int mask, i;
	for(i=0; i<=sizeof(unsigned int)*CHAR_BIT-1; i++)
		if(x&(1<<i)) break;
	mask = (~(~0<<i))^(1<<i);
	printf("i :%d\n", i);
printbinary(~0<<i);
printbinary(~(~0<<i));
printbinary(mask);
	printf("mask : "); printbinary(mask);
	return x^mask;
}
