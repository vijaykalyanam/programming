#include <unistd.h>
#include <stdarg.h>

#define PRINT_STRING(__ch) 	do { 				\
				while(*__ch != '\0') {		\
				write(0, (void *)__ch, 1);	\
				__ch++;				\
				}				\
				} while(0)

unsigned int print(char *string,...)
{
	int ret;
	char *p, *arg;
	va_list ap;

	p = string;
	if (string) {
		va_start(ap,string);
		while(*p != '\0') {
			if (*p == '%' && *(p+1) == 's') {
				arg=va_arg(ap, char *);
				PRINT_STRING(arg);
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
	print("this is string encoded :%s\n", str);
	return 0;
}
