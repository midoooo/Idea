#include<stdio.h>
#include<conio.h>
#include<string.h>
int count=0;
void swap(int *a,int *b)
{
	int t;
	t=*a;
	*a=*b;
	*b=t;
}
void permutation(int k,int n,int* a)
{
	if(k==n)
	{
      //printf("%s\n",a);
		int j=0;
		for(j=0;j<n;j++)
		{
			printf("%d ",a[j]);
		}
		printf("\n");
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
	/*
	int myarray[20];
	int rr[20];
    memcpy(myarray, (int[]) { 1, 2, 3, 4 ,5,6,7,8,9,0 }, sizeof myarray);
    memcpy(rr, myarray, sizeof rr);
    */
	int a[10]={1,2,3,4};
	printf("%d\n",sizeof(a) );
	int n=4,k=0;
	permutation(k,n,a);
    printf("%d\n", count);
    return 0;
}
