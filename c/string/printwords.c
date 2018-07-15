#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *words[][20] = {
	{ "", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Ninteen" },
	{ "", "Ten", "Twenty", "Thirty", "Fourty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninty", "Hundred"},

	{ "Hundred"},
        { "Thousand"}
};

int main(void)
{

	unsigned short int num[4] = {1,2,3,4};
	const char str[8] = "1014";
	int i, j;

	int len = strlen(str);
	for (i = 0; i < strlen(str); i++, len--) {
			//if (str[i] == '0') continue;
		if (str[i] == '0') {
		} else if (len > 2) {
			printf("%s %s ", words[0][str[i]-'0'], words[len-1][0]);
		} else if (len == 2) {
			if (str[i] == '1')  {
				printf("%s ", words[0][str[i]-'0' + 9 + str[i+1]-'0']);
				break;
			} else {
				printf("%s ", words[len-1][str[i]-'0']);
			}	
		} else {
			printf("%s", words[0][str[i]-'0']);
		}
	}
	return 0;
}
