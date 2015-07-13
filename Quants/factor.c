#include<stdio.h>
#include<math.h>
int main()
{
	int n=100;
	while((n%2)==0)
	{
		printf("%d\n",2);
		n=n/2;
	}
    int f=3;
    while(f<=sqrt(n))
    {
    printf("%d\n",f);
    f=f+2;
    }
	return 0;
}