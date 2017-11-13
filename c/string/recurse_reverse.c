#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SWAP(type, __a, __b)    do {    \
                                type __t;       \
                                __t = __a;      \
                                __a = __b;      \
                                __b = __t;      \
                                } while(0)

//void reverse_string(char *ptr)
void reverse_sentence(char *ptr)
{
        if (!ptr)
                return;

        unsigned int i,j;

        for(i = 0, j = strlen(ptr)-1; i < j; i++, j--)
                SWAP(char, ptr[i], ptr[j]);

        return;
}

void str_reverse(char *p)
{
	if (*p == '\0' || *p == '.')
		return;
	str_reverse(p+1);
	printf("%c", *p);
}

char* reverse_word(char* start, char* end)
{
	char ch = *end;
	if (*(end+1) == ' ' || *(end+1) == '.' ||
		*(end+1) == ',' || *(end+1) == '\0') {
		*start = ch;
		return start + 1;
	}

	start = reverse_word(start, end+1);
	*start = ch;

	return start +1;
}

int main(void)
{

	char str[] = "reverse reversed, this is a string.";
	char *ptr = str;

	reverse_string(str);
	puts(str);

	while (*ptr != '\0') {

		ptr = reverse_word(ptr, ptr);

		while (*ptr == ' ' || *ptr == ',')
			++ptr;
	}

	puts(str);

	return 0;
}
