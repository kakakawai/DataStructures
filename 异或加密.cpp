# include <stdio.h>
int main (void)
{
	char c;
	int key = 9999;
	printf("�����ַ�.");
	scanf("%c",&c);

	//����
	c ^= key;
	printf("%c\n",c);
	//����
	c ^= key;
	printf("%c\n",c);
	printf("%d\n",8/4*(int)2.5/(int)(1.25*(3.7+2.3)));

	return 0;
}
