/*=================================
   ���ݽṹ3.3 �ݹ����쳲���������
                          By Mirror
=================================*/

/*===================================
  ����ݹ�->��һ��һ�ϵݹ����  ��ÿ
 ���ݹ����Ĳ���ֻ����������n���й�
===================================*/

//쳲���������

# include<stdio.h>

 long Fib(unsigned long n);
int main (void)
{
	unsigned long n,num;
	printf("����쳲��������е�������");
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



