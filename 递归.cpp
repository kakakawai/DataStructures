# include <stdio.h>
# define ulong unsigned long

ulong factorial(ulong);

void main ()
{
	ulong num = 0L;

	printf("输入阶乘数目:");
	scanf("%lu",&num);
	printf("%lu的阶乘结果为：%lu\n",num,factorial(num));
}

ulong factorial(ulong n)
{
	if(n<2)
	{
		return n;
	}
	return n*factorial(n-1);
}
