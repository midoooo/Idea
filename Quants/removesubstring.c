#include<stdio.h>
#include<conio.h>
#include<string.h>
void removeSubstring(char *s,const char *toremove);
int main(int argc, char const *argv[])
{
	/* code */
	char a[100]="monkey on the building";
	removeSubstring(a,"the");
	printf("%s\n", a);
	return 0;
}
void removeSubstring(char *s,const char *toremove)
{
  while( s=strstr(s,toremove) )
    memmove(s,s+strlen(toremove),1+strlen(s+strlen(toremove)));
}
