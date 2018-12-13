#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>

#define PRINT_STRING(__ch) 	do { 				\
				while(*__ch != '\0') {		\
				write(0, (void *)__ch, 1);	\
				__ch++;				\
				}				\
				} while(0)

#define	SWAP(x, y)	do {			\
			typeof((x)) __t = y;	\
			y = x;			\
			x = __t;		\
			} while(0)		

static void reverse(char **s)
{

	int i = 0;
	int j = 0;
	char *rev = *s;
	while (rev[j]) ++j;
	j--;

	for (i = 0; i < j; i++, j--)
		SWAP(rev[i], rev[j]);
}

static char *converttostring(int d)
{
	int i = 0, j;
	int n;
	int rem;
	n = d;

	char *s = (char *) calloc(1, 7);

	while (n > 0) {
		rem = n%10;
		n = n/10;
		s[i++] = rem + '0';
	}

	reverse(&s);
	return  s;
}

unsigned int print2(char *string,...)
{
	int ret;
	char *p, *arg;
	va_list ap;

	int d;

	p = string;
	if (string) {
		va_start(ap,string);
		while(*p != '\0') {
			if (*p != '%') {
				write(0, (void *) p, 1);
			} else {
				p++;
				if (*p == 'c') {
					int ch = va_arg(ap, int);
					write(0, (void *) &ch, 1);
				} else if (*p == 's') {
					arg = va_arg(ap, char *);
					PRINT_STRING(arg);
				} else if (*p == 'd') {
					d = va_arg(ap, int);
/*
					if (d >> (sizeof(int)-1))
						write(0, "-", 1);
*/
					arg = converttostring(d);
					PRINT_STRING(arg);
				}
				p++;
			}
			p++;
		}
		va_end(ap);
	}

	return 0;
}
unsigned int print(char *string,...)
{
	int ret;
	char *p, *arg;
	va_list ap;

	int d;

	p = string;
	if (string) {
		va_start(ap,string);
		while(*p != '\0') {
			if (*p == '%' && *(p+1) == 'c') {
				arg=va_arg(ap, char *);
				PRINT_STRING(arg);
				p = p+2;
				continue;
			} else if (*p == '%' && *(p+1) == 's') {
				arg=va_arg(ap, char *);
				PRINT_STRING(arg);
				p = p+2;
				continue;
			} else if (*p == '%' && *(p+1) == 'd') {
				d = va_arg(ap, int);
/*
				if (d >> (sizeof(int)-1))
					write(0, "-", 1);
*/
				arg = converttostring(d);
				PRINT_STRING(arg);
//				free(arg);
				p = p+2;
				continue;
			}
			write(0, (void *) p, 1);
			p++;
		}
		va_end(ap);
	}

	return 0;
}

int main(void)
{
	char *str="READONLY MEM";
	int t = 1234;
	print2("this is string encoded :%s-- Int %d\n", str, t);
	return 0;
}
