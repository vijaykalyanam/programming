#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void str_reverse(char *p)
{
	if (*p == '\0')
		return;
	str_reverse(p+1);
	printf("%c", *p);
}

char* reverse_word(char* start, char* end)
{
	char ch = *end;
	if (*(end+1) == ' ' || *(end+1) == '\0') {
		*start = ch;
		return start + 1;
	}

	start = reverse_word(start, end+1);
	*start = ch;
	return start +1;
}

int main(void)
{

	char str[] = "reverse reversed this is a string";
	char *ptr = str;

	while (*ptr != '\0') {

		ptr = reverse_word(ptr, ptr);

		while (*ptr == ' ')
			++ptr;
	}

	puts(str);
	puts(ptr);

	return 0;
}
