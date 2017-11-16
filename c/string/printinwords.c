#include <stdio.h>
#include <stdlib.h>


char *tens2[] = { "", "Ten", "Hundred", "Thousand"};
char *tens[] = { "", "", "Ten", "Twenty", "Thirty", "Fourty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninty", "Hundred"};
char *ones[] = { "", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten"}; 

int main(void)
{

	unsigned short int num[4] = {1,2,3,4};
	int i, j;

	j = 3;

	for (i = 0; i < sizeof(num) / sizeof(num[0]); i++, j--)
		if (j >= 2)
			printf("%s %s ", ones[num[i]], tens2[j]);
		else
			printf("%s %s ", tens[num[i]], ones[num[++i]]);


	return 0;
}
