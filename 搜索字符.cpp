# include <stdio.h>
# include <ctype.h>
# include <string.h>
int main (void)
{
	char text1[100];
	char text2[40];

	printf("���������������ַ�����������100���ַ���\n");
	fgets(text1,sizeof(text1),stdin);
	printf("��������ַ�����������40���ַ���\n");
	fgets(text2,sizeof(text2),stdin);

	/*text1[strlen(text1)-1] = '\0';*/ 
	text2[strlen(text2)-1] = '\0';

	printf("�����������ַ���Ϊ��\n%s\n",text1);
	printf("Ҫ���ҵ��ַ���Ϊ��\n%s\n",text2);

	for(int i = 0;(text1[i] = toupper(text1[i]));i++);
	for(i = 0;(text2[i] = toupper(text2[i]));i++);

	printf("�ڶ����ַ�%s�ڵ�һ���ַ����ҵ�\n",(strstr(text1,text2) == NULL) ? "����" : "��");

	return 0;
}
