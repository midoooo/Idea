#include<stdio.h>
#include<conio.h>
#include<string.h>
int count=0;

void permutation(int index,int n,int* a)
{
	if(index==n)
	{
      
		int j=0;
		for(j=1;j<=n;j++)
		{
			printf("%d ",a[j]);
		}
		printf("\n");
		count++;
	}
	else
	{
		int i;
		for(i=1;i<=n;i++)
		{
	     a[index]=i;
	     permutation(index+1,n,a);
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
	int a[10];
	int n=4,k=0;
	permutation(k,3,a);
    printf("%d\n", count);
    return 0;
}
