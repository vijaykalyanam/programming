#include <stdio.h>

int count(char *p)
{
	unsigned int c = 0, t;

	if (*p == '\0')
		return 0;
	//To make case Insensitive:
	//toupper(__ch) (__ch >= 90 && __ch <= 122) ? (__ch = __ch - ('a'-'A')) : (__ch) )
	if (*p == 'a' || *p == 'e' || *p == 'i'
			|| *p == 'o' || *p == 'u')
		c = 1;

	t = count(p+1);

	return c+t;
}


int main(void)
{

	char *p = "aeiou";

	printf("No of %d\n", noofvowels(p));

	return 0;
}
