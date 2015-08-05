#include<stdio.h>
#include<string.h>
int main()
{
	char str[30]={"singh king"};
	char *a;
	char *b=strtok(str," ");
       int count=0;
	while(b!=NULL)
	{
		if(strstr(b,"ng"))
			count++;
		b=strtok(NULL," ");
	}
	printf("%d",count);
	return 0;
}
