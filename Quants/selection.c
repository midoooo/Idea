#include<stdio.h>
void MakeSelection(int index,int num_of_choices,int* selection)
{
	
	
	int i;
	if(index==sizeof(selection))
	{
		
		for (i = 0; i < sizeof(selection); ++i)
		{
			/* code */
			printf("%d",selection[i]);
		}
		printf("\n");
		
	}
	else
	{
		int start=1;
	    if(index>0)start=selection[index-1]+1;
	    for (i = start; i < num_of_choices; ++i)
	    {
	        selection[index]=i;
	        MakeSelection(index+1,num_of_choices,selection);
	    }

    }
}
 int main()
{
	int aa[5]={4,5,6,7,8};
	MakeSelection(0,3,aa);
	return 0;
}