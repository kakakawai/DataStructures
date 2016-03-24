# include <stdlib.h>
# include <stdio.h>
int main (void)
{
	int *p = (int *)malloc(5*sizeof(int));
	int *o = (int *)calloc(5,sizeof(int));
/*
    p = (int *)malloc(5*sizeof(int));
	o = (int *)calloc(5,sizeof(int));
*/
	for(int i = 0;i<5;i++)
	{
 		printf("%d\n",*(p + i));
	}

	for(i = 0;i<5;i++)
	{
		printf("%d\n",*(o + i));
	}

	return 0;
}