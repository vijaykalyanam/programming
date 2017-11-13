#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SWAP(type, __a, __b)	do {	\
				type __t;	\
				__t = __a;	\
				__a = __b;	\
				__b = __t;	\
				} while(0)

char* find_word(char *str)
{
	if (!str || *str == '\0')
		return NULL;

	if (*str == ' ')
		return str;

	while (*(str+1) != ' ' || *(str+1) != '\0')
		str++;
	return str;
}

void reverse_string(char *ptr)
{
	if (!ptr)
		return;

	unsigned int i,j;

	for(i = 0, j = strlen(ptr)-1; i < j; i++, j--)
		SWAP(char, ptr[i], ptr[j]);

	return;
}

void reverse_word(char *p, char *q)
{
	unsigned int i,j;

	for(i = 0, j = strlen(ptr)-1; i < j; i++, j--)
		SWAP(char, ptr[i], ptr[j]);

	return;
}

int main(void)
{

	char str[256] = "this is a sentence";
	char *p, *q;

	reverse_string(str);
	p = str;

	while ((q = find_word(p)) != '\0') {
	}
	puts(str);

	return 0;
}
