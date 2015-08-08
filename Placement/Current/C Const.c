#include <stdio.h>
 
int main(void)
{
    int i = 10;
     const int *ptr = &i;
    //  *ptr=30;
    ///*ptr = 100;
    printf("i = %d\n", *ptr);

    // const int *ptr - we can change only pointer
    // int const *ptr - we can change only value 
    return 0;
}