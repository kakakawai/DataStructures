/*=================================
   数据结构3.3 递归计算斐波那契数列
                          By Mirror
=================================*/

/*===================================
  单向递归->有一处一上递归语句  但每
 个递归语句的参数只与主参数（n）有关
===================================*/

//斐波那契数列

# include<stdio.h>

 long Fib(unsigned long n);
int main (void)
{
	unsigned long n,num;
	printf("输入斐波那契数列的项数：");
	scanf("%d",&n);
	num = Fib(n);
	printf("%d\n",num);

	return 0;
}

long Fib(unsigned long n)
{
	if( n==1 || n==2)
	{
		return 1;
	}
	else
	{
		return Fib( n-1 ) + Fib( n-2 );
	}
}



