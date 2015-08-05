#include <stdio.h>
 
int main(void)
{
    int i = 10;
    const int *ptr = &i;
    *ptr = 100;
    printf("i = %d\n", i);

    // const int *ptr - we can change only pointer
    // int const *ptr - we can change only value 
    return 0;
}