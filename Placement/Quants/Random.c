#include <stdio.h>
#include <stdbool.h>

int main()
{
    long long i,j,t,n,k,kk,p;
    scanf("%lld",&t);
    for(i=0;i<t;i++)
    {
      scanf("%lld%lld%lld",&n,&k,&p);
      long long arr[k],brr[n];
      for(j=0;j<k;j++)
      {
        scanf("%lld",&arr[j]);
      }
      long long count=1;
      bool boo=true;
      for(kk=1;kk<=n;kk++)
      {
        for(j=0;j<k;j++)
        {
        	if(arr[j]==kk)
        	boo=false;
        }
        if(boo)
        {  
        	brr[count]=kk;
        	count++;
        }
		boo=true;
      }
      if((n>=1)&&(n-k)>=p)
      printf("%lld\n",brr[p]);
      else
         printf("-1\n");
         
         count=0;
    }
    return 0;
}
