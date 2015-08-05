#include<stdio.h>
void combinations(int n,int c,int index,int combs[])
{
	if(c==0)
	{
		int i;
		for ( i = 0; i < index; ++i)
			printf("%d\t",combs[i]);
		printf("\n");
		return;
	}
	if(n==0)return;
	combs[index]=n;
	combinations(n-1,c-1,index+1,combs);
	combinations(n-1,c,index,combs);
}
int main()
{
	int arr[3];
	combinations(3,3,0,arr);
	return 0;
}
