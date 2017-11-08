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

printf("->\n");
	for(;i<j; i++,j--)
		if( ((x&(1<<i)) && !(x&(1<<j))) ||
				(!(x&(1<<i)) && (x&(1<<j)))  )
			x^=(1<<i)|(1<<j);
printf("<-\n");
	return x;
}

unsigned int reversebytes(unsigned int x) {
	return (x>>24|x<<24|(x&0x00FF0000)>>8|(x&0x0000FF00)<<8);
}

int main(void) {

	unsigned long int i=32;
	unsigned long int shift=1;
	unsigned long int sum; 

	unsigned int n = 0xabcd03;

	printbinary(n);
	n = reverseportionofbits(n, 0, 31);
	printbinary(n);

n = 12;
printbinary(n);
printbinary(-n);
printbinary(n-1);
printbinary(n+1);

	return 0;
}
