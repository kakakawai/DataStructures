//1的1次方+2的2次方+.....+n的n次方

# include<stdio.h>
int main(void)
{
	unsigned int n,i,j,temp;//i:底数 j:次方
	unsigned int s = 0;

	printf("输入n的值为:");
	scanf("%d",&n);

	for(i = 1; i<=n; i++)
	{
		temp = i;

		for(j = 1; j< i; j++)
		{
			temp *= i;
		}
		
		s += temp;
	}
	printf("结果为：%d\n",s);

	return 0;
}