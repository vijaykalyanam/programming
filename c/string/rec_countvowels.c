#include <stdio.h>

int noofvowels(char *p)
{
	unsigned int c = 0, t;

	if (*p == '\0')
		return 0;

	if (*p == 'a' || *p == 'e' || *p == 'i'
			|| *p == 'o' || *p == 'u')
		c = 1;

	t = noofvowels(p+1);

	return c+t;
}


int main(void)
{

	char *p = "aeiou";

	printf("No of %d\n", noofvowels(p));

	return 0;
}
