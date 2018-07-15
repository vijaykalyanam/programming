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

int strtoint(char *p, int sum)
{
if (*p == '\0') return sum;
return strtoint(p+1, sum*10 + *p-'0');
}

int toint(char *p)
{

	int sum = 0;
	return strtoint(p, sum);
}

int main(void)
{

	char *p = "12345";
	unsigned int n;

	printf(" Int val: %d\n", toint(p));

	return 0;
}
