#include <stdio.h>
#include <stdbool.h>
#pragma (5)
int main(void)
{

	struct __attribute__((__packed__)) data {
		char buf[64];
		int a;
		unsigned int b;
		bool flag;
	};

struct info {
int index;
char name[32];
struct data d[0];
};

printf("size of data :%d size of info :%d\n", sizeof(struct data), sizeof(struct info));

return 0;
}
