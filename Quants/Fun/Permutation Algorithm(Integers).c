#include<stdio.h>
#include<stdlib.h>
void swap(int *a,int *b)
{
int *t;
t=*a;
*a=*b;
*b=t;
}
int count=0;
void permutation(int k,int n,int *a)
{
if(k==n)
{
  count=count+1;
}
else
{
 int i=0;
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
 int a[10]={1,2,3,4.5,6,7,8,9,10};
 permutation(0,10,a);
printf("\n%d\n",count);
return 0;
}
