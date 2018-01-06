#include <stdio.h>

int main(void)
{
 printf("%lu ", 8*sizeof(char));
 printf("%lu ", 8*sizeof(unsigned char));
 printf("%lu ", 8*sizeof(int));
 printf("%lu ", 8*sizeof(unsigned int));
 printf("%lu ", 8*sizeof(long));
 printf("%lu ", 8*sizeof(unsigned long));
 printf("%lu ", 8*sizeof(float));
 printf("%lu ", 8*sizeof(double));
 printf("%lu\n", 8*sizeof(long double));
 return 0;

}
