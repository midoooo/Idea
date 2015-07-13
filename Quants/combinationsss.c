#include<stdio.h>

void combinations(int arr[],int data[],int start,int end,int index,int r)
{
	if(index==r)
	{
		for (int i = 0; i < r; ++i)
		printf("%d\t",data[i]);
	  printf("\n");
	}

	for (int i = start; i<=end && end-i+1>=r-index; ++i)
	{
		data[index]=arr[i];
		combinations(arr,data,i+1,end,index+1,r);
	}
}
int main()
{
	int arr[]={1,2,3,4,5};
	int r=5;
	int n=sizeof(arr)/sizeof(arr[0]);
	int data[r];
	printf("%d\n",n);
	combinations(arr,data,0,n-1,0,r);
	return 0;
}