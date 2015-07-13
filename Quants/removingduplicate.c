#include<stdio.h>
void removes(int *array,int Length)
{
    int i, j;

/* new length of modified array */
int NewLength = 1;

for(i=1; i< Length; i++){

   for(j=0; j< NewLength ; j++)
   {

      if(array[i] == array[j])
      break;
   }

   /* if none of the values in index[0..j] of array is not same as array[i],
      then copy the current value to corresponding new position in array */

  if (j==NewLength )
      array[NewLength++] = array[i];
}
  for(i=0;i<New;i++)
    {
     printf("%d\n",array[i]);
    }
}
void rmdup(int *array, int length)
{
    int *current , *end = array + length - 1;
    int i=0;

    for ( current = array + 1; array < end; array++, current = array + 1 )
    {
        while ( current <= end )
        {
            if ( *current == *array )
            {
                *current = *end--;
            }
            else
            {
                current++;
            }
        }
    }
     for(i=0;i<length;i++)
    {
     printf("%d\n",array[i]);
    }
   *end;
}
int main()
{
    int a[10]={1,2,3,4,5,7,7,8,8,0};
    removes(a,10);
}
