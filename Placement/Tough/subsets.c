#include <stdio.h>
#include <malloc.h>
#include <math.h>
#include <string.h>
char* int2binary(int b,int n)
{
    int a;
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
    int i,j=strlen(aa)-1;
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
	int n,m;
	scanf("%d",&n);
    int array[100];
    //={63,17,21,34,92,92,78,6,37,100};
	m=pow(2,n);
	//printf("%d\n",m);
	int i;
	for(i=0;i<n;i++)
        scanf("%d",&array[i]);
	char buffer[200];
	int setarray[100];
	int j=0;
    int r;

    int subcount=0;
	while(m--)
    {

        //itoa(i,buffer,2);
        char *buff=(char*)malloc(200*sizeof(char));
        sprintf(buff,"%0*s\n",n,int2binary(m,n));
        printf("%s\n",buff);
        r=0;
        for(j=0;j<n;j++)
        {
            if(buff[j]=='1')
                r^=array[j];
              //printf("%d ",array[j]);
        }
        if(r!=0)
        {
	        setarray[subcount]=r;
	        subcount++;
            printf("%d\n",r);
        }
        
        
    
    }
    printf(" sub count %d\n",subcount);
    int count=0;
     for(i=0;i<subcount;i++)
     {
         for(j=0;j<subcount;j++)
         {
             if(setarray[i]==setarray[j])
                count=count++;
         }
     }
     printf("%d\n",count);
	return 0;
}
