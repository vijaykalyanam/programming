#include <stdio.h>
int isrepeated(char *str, char ch)
{
	int count = 0;
	while(*str) {
		if (*str == ch) {
			++count;
		}
		if (count > 1)
			return count;
		str++;
	}
	return 0;
}
void removechar(char *str, char ch)
{
	char *p = str;
	while(*p) {
		if (*p == ch) {
			p++;
		} else {
			*str = *p;
			str++;
			p++;
		}
	}
	*str = '\0';
}
void main(void)
{

	char str[] = "anagrams";

	int i,j;
	char *p,*s;

#if 1 
	/* Remove Duplicate Characters */
	for (i=0; str[i]; i++)
		for (j=i+1; str[j]; j++)
			if (str[i] == str[j]) {
#if 0
				p = str+j;
				while(*p) {
					*p = *(p+1);
					p++;
				}
#else
				removechar(str+j, str[j]);
#endif
			}
	puts(str);

#else
	s = p = str;
	while (*p) {
		if (isrepeated(str, *p)) {
			removechar(str, *p);
		} else
			p++;
	}
	puts(str);
#endif
}
