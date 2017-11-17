#include <stdio.h>

int count(char *p)
{
	unsigned int t;

	if (*p == '\0')
		return 0;
	t = count(p+1);

	return t+1;
}

void count2(char *p, int *c)
{
	if (*p == '\0') {
		*c = 0;
		return;
	}
	count2(p+1, c);
	//*c++; Value is not incrementing.
	++*c;
}

int main(void)
{

	char *p = "aeiou";
	unsigned int n;

	count2(p, &n);

	printf("No of count: %d count2 :%d\n", count(p), n);

	return 0;
}
