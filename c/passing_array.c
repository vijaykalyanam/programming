#include <stdio.h>
void print_array(int a[]);

int arr[] = {1,2,3,3,4,5,6,7,8,9};

void print_array(int p[])
{
	(void)p;
}

int main(void)
{

	print_array(arr);

	return 0;
}
