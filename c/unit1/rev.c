#include <stdio.h>

static inline void print(char *p)
//void print(char *p)
{

	if (*p != '\0')
		print(p+1);
	else
		return;
	printf("%c", *p);
}

int main(int argc, char **argp)
{

	char s[] = "VIJAY";

	print(s);

	return 0;
}
