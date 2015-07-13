#include<stdio.h>

void combinations(int arr[],int start,int n,int k,int ksize)
{
	int i;
	if(ksize==start)
	{
		for ( i = 0; i < ksize; ++i)
			printf("%d\t",arr[i]);
		printf("\n");
		return;
	}
	for (i = k; i <n; ++i)
	{
    arr[k]=i;
	combinations(arr,start+1,n,k+1,ksize);
    }
}
int main()
{
	int arr[3];
	combinations(arr,0,3,0,2);
	return 0;
}
