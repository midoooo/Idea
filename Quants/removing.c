#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdbool.h>
void main()
{
	int n=10;
	int a[5]={3,7,8};
	bool b[n];
	int i,j;
	//for ( i = 0; i < 3; ++i)
	{
	//  scanf("%d",&a[i]);
	}
	for ( i = 1; i <=n; ++i)
	{
		b[i]=true;
		for ( j = 0; j < 3; ++j)
		{
          if(i==a[j])
          {
          	b[i]=false;
          }
		}
	}
	for ( i = 1; i <=n; ++i)
	{
	    if(b[i])
		printf("%d\n",i);
	}
	return 0;
}
