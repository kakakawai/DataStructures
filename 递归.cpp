# include <stdio.h>
# define ulong unsigned long

ulong factorial(ulong);

void main ()
{
	ulong num = 0L;

	printf("����׳���Ŀ:");
	scanf("%lu",&num);
	printf("%lu�Ľ׳˽��Ϊ��%lu\n",num,factorial(num));
}

ulong factorial(ulong n)
{
	if(n<2)
	{
		return n;
	}
	return n*factorial(n-1);
}
