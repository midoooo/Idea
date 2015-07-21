#include <stdio.h>
#include <malloc.h>
#include <math.h>
#include <string.h>
char* int2binary(long b,long n)
{
    long a;
    char *aa=(char*)calloc(100,sizeof(char));
    while(b>0)
    {
        a=b%2;
        b=b/2;
    char *bb=(char*)calloc(100,sizeof(char));
    bb[0]=(a==0)?'0':'1';
    strcat(aa,bb);
    }
    char *cc=(char*)calloc(100,sizeof(char));
     long i,j=strlen(aa)-1;
    for (i = 0; i < strlen(aa); ++i)
    {
      cc[j]=aa[i];
      j--;
    }
   // 
    return cc;
}
int main()
{
	long n,m;
	scanf("%ld",&n);
	long array[100];
	m=pow(2,n);
	//printf("%d\n",m);
	long i;
	for(i=0;i<n;i++)
        scanf("%ld",&array[i]);
	char buffer[200];
	long setarray[100];
	long j=0;
    long r;

	for(i=0;i<m;i++)
    {
        //itoa(i,buffer,2);
        char *buff=(char*)malloc(200*sizeof(char));;
        sprintf(buff,"%0*s\n",n,int2binary(i,n));
        //printf("%s\n",buff);
        r=0;
        for(j=0;j<n;j++)
        {
            if(buff[j]=='1')
                r^=array[j];
              //printf("%d ",array[j]);
        }
        setarray[i]=r;
        //printf("%d\n",r);
    }
    long count=0;
     for(i=0;i<n;i++)
     {
         for(j=i;j<n;j++)
         {
             if(setarray[i]==setarray[j])
                count=count++;
         }
     }
     printf("%ld\n",count);
	return 0;
}
