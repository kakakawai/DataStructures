/*======================================
  尾递归-》特殊的单向递归，递归调用语句
  只有一个且处于算法的最后
======================================*/

//阶乘

# include <stdio.h>

long Fact(long n);

int main (void)
{
	long n,num;
	printf("输入阶乘阶数：");
	scanf("%d",&n);
	num = Fact(n);
	printf("%d\n",num);

	return 0;
}

long Fact(long n)
{
	if( n==0 )
	{
		return 1;
	}
	else
	{
		return n*Fact( n-1 );
	}
}
