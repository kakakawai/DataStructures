//1��1�η�+2��2�η�+.....+n��n�η�

# include<stdio.h>
int main(void)
{
	unsigned int n,i,j,temp;//i:���� j:�η�
	unsigned int s = 0;

	printf("����n��ֵΪ:");
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
	printf("���Ϊ��%d\n",s);

	return 0;
}