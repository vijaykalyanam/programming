#include <stdio.h>

int main(int argc, char **argp) {
	unsigned int a=0,b=1,c,n;

	printf("enter n:");
	scanf("%d", &n);

	do {
		c = a+b;
		a=b;
		b=c;
	} while(c<n);

	if (c == n) printf("yes"); 
	else printf("no");

	return 0;
}
