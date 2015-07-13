#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdbool.h>
int count=0;

void permutation(int index,int n,int* a,bool *used)
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
			if(!used[i])
				used[i]=true;
	     a[index]=i;
	     permutation(index+1,n,a,used);
	     used[i]=false;
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
	int a[2];
	int n=4,k=0;
	bool used[3];
	permutation(k,3,a,used);
    printf("%d\n", count);
    return 0;
}
