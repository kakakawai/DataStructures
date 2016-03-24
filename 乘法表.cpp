# include <stdio.h>
# include <ctype.h>
int main (void)
{
	int again = 0;

	do
	{
	int row = 1;
	int column = 1;
	int i = 0;

	printf("输入乘法表大小：");
	scanf("%d",&i);

	printf(" ");
	for(;column<=i;column++)
	{
		printf("  %d",column);
	}
	for(;row<=i;row++)
	{
		printf("\n%d",row);
		for(column = 1;column<=i;column++)
		{
			printf("  %d",row * column);
		}
	}
	printf("\nagain?\n");
	scanf(" %c",&again);
	}
	while(tolower(again)=='y');
	return 0 ;
}