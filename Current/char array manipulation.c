#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    //////////////////////
    char str[] = "ABCDEFG";
    char *ps ;
    ps= memchr(str,'D',strlen(str));
    if (ps != NULL)
       printf ("search character found:  %s\n", ps);
    else
       printf ("search character not found\n");

  //////////////////////
    char a1[] = "abc";
    char a2[] ="acb";
    printf("'abc' vs 'abd': %2d\n", memcmp(a1, a2, sizeof a1));
    printf("'abd' vs 'abc': %2d\n", memcmp(a2, a1, sizeof a1));
    printf("'abc' vs 'abc': %2d\n", memcmp(a1, a1, sizeof a1));
    printf("a is  %s\n",a1);
//////////////////////////////
    memcpy(a1, a2, sizeof a2);
    printf("%s\n",a1);
///////////////////////

    puts(str);
    memset(str,'a',5);
    puts(str);
//////////////////////

  strcpy(str ,"ABCDEFGHIJKLMNOPQRSTUVWXYZ");
    puts (str);
    memmove (str+6,str+3,7);
    puts (str);
    return 0;

     return 0;
}
