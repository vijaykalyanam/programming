#include <stdio.h>

int main(int argc, char **argp) {

	char *p = "vijay";
	char str[64] = "string";
	char *q = "another";
	char *r;

	r = p;
	puts(p);
	p=q;
	puts(q); puts(p); puts(str);
//p[2] = 'z'; puts(p);
str[2] = 'z'; puts(str);
	return 0;
}
