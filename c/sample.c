


int main(int argc, char **argp) {

#define PISQUARE PI*PI
#define PI VALUE
#define VALUE 3 
{
//define VALUE 4    >> ERROR : MACRO Redeclaration macro handling will done before compliling. no scope
//#define . ;    >> HAS TO BE C IDENTIFIER
}
#include <stdio.h>
	printf("PISQUARE :%d\n", PISQUARE);
#include <stdio.h>
	return 0;
}
