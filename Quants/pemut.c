#include<stdio.h>
#include<conio.h>
#include<string.h>
int count=0;
void swap(char *a,char *b)
{
	char t;
	t=*a;
	*a=*b;
	*b=t;
}
void permutation(int k,int n,char* a)
{
	if(k==n)
	{
      printf("%s\n",a);
      count=count+1;
	}
	else
	{
	int i;
	for(i=k;i<n;i++)
	{
     swap(&a[k],&a[i]);
     permutation(k+1,n,a);
     swap(&a[k],&a[i]);
	}
    }
} 

int main()
{
	char a[100]={"012"};
	int n=strlen(a),k=0;
	permutation(k,n,a);
    printf("%d\n", count);
    return 0;
}