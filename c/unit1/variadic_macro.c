#include <stdio.h>

/* This has to be 3 dots otherwise it is an error */
#define variadic_macro(...)  printf(__VA_ARGS__)

int main(void)
{
  variadic_macro("STRING :%s INT :%d BOOL :%d\n", "VIJAY", 1, 2);
  
  return 0;
}
