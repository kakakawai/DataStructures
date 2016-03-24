# include <stdio.h>
int main (void)
{
	char c;
	int key = 9999;
	printf("ÊäÈë×Ö·û.");
	scanf("%c",&c);

	//¼ÓÃÜ
	c ^= key;
	printf("%c\n",c);
	//½âÃÜ
	c ^= key;
	printf("%c\n",c);
	printf("%d\n",8/4*(int)2.5/(int)(1.25*(3.7+2.3)));

	return 0;
}
