#include <stdio.h>
/* To get Multiple of 4, 2 Bytes required. 2 Bytes added in padding */
#define	OFFSETOF((type_t), (member))	do { \
						typeof(type_t) *t = NULL; \
						(char *)t->member - (char *)&t;
					} while(0)
struct s1 {
	char ch;
	short int i;
};

/* 3 Byte added in padding. 1+4+(3) */
struct s2 {
	struct s1 s1;
	char ch;
	int i;
};

struct __attribute__((packed)) s3 {
	struct s1 s1;
	char ch;
	int i;
};

int main(char argc, char **argp)
{
printf("Size of structure S1: %d S2 :%d S3 :%d\n",
		sizeof(struct s1),
		sizeof(struct s2),
		sizeof(struct s3));
printf("Size of Void Pointer :%u\n", sizeof(void*));
//printf("offsetof :%d\n", OFFSETOF(S1, i));
return 0;
}
