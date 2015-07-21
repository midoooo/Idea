#include <stdio.h>
#include <malloc.h>
int xoroperations(int array[100],int i,int j)
{
	int k=0,r=0;
	for (k = i; k < j; ++k)
	{
		//r^=array[k];
		 printf("%d ",array[k]);
	}
	  printf("\n");
	return r;
}
int main()
{
	int n;
    scanf("%d",&n);
    int *array=(int *)malloc(sizeof(int)*n);
    int i,j;
    for(i=0;i<n;i++)
    {
    	scanf("%d",&array[i]);
    }

    for(i=0;i<n;i++)
    {
    	for(j=i+1;j<=n;j++)
    	{
    	// int k=0;
    	  // for(k=i;k<j;k++)
    	   // printf("%d ",array[k]);
    	  xoroperations(array,i,j);
    	 printf("\n");
    	}
    }
    return 0;
}
