/*======================================
  β�ݹ�-������ĵ���ݹ飬�ݹ�������
  ֻ��һ���Ҵ����㷨�����
======================================*/

//�׳�

# include <stdio.h>

long Fact(long n);

int main (void)
{
	long n,num;
	printf("����׳˽�����");
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
