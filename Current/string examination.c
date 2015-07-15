#include <stdio.h>

#include <string.h>

int main()
{
/*
	strlen returns the length of a given string 
    strcmp compares two strings 
    strncmp compares a certain amount of characters of two strings 
    strchr finds the first occurrence of a character 
    strrchr finds the last occurrence of a character 
    strspn returns the length of the maximum initial segment that consists 
of only the characters found in another byte string 
    strcspn returns the length of the maximum initial segment that consists 
of only the characters not found in another byte string 
   strpbrk finds the first location of any character in one string, in another string 
   strstr finds the first occurrence of a substring of characters 
   strtok finds the next token in a byte string 
*/
   char a[100]="qwertyuiopasdfghjklzxcvbnm";
   printf("%d\n",strlen(a));

   printf("%d\n",strcmp(a,"z"));

   printf("%d\n",strncmp(a,"zel",3));

   printf("%s\n",strchr(a,'b'));

   printf("%s\n",strrchr(a,'e'));

  

  // strspn(find str, const str)
    char string_find[50] = "snob";
    char low_alpha[50]= "qwertyuipasdfghjklzxcvnm";
    printf("Length of initial segment matching  %d\n", strspn(string_find, low_alpha));

   const char str1[] = "dEABCDEF4960910deal";
   const char str2[] = "dECBDA";
   int len = strcspn(str1, str2);
   printf("First matched character is at %d\n", len );


   char *ret;
   ret = strpbrk(str1, str2);
   if(ret) 
   {
      printf("First matching character: %c\n", *ret);
   }

   char s1 [] = "My House is small";
   printf ("Returned String 1: %s\n", strstr (s1, "is"));
   
   char *tok;
   tok= strtok(s1, " ");
    while (tok) {
        printf("Token: %s\n", tok);
        tok = strtok(NULL, " ");
    }  

   return 0;
}