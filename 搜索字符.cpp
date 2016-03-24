# include <stdio.h>
# include <ctype.h>
# include <string.h>
int main (void)
{
	char text1[100];
	char text2[40];

	printf("输入用来搜索的字符串（不超过100个字符）\n");
	fgets(text1,sizeof(text1),stdin);
	printf("输入查找字符串（不超过40个字符）\n");
	fgets(text2,sizeof(text2),stdin);

	/*text1[strlen(text1)-1] = '\0';*/ 
	text2[strlen(text2)-1] = '\0';

	printf("用来搜索的字符串为：\n%s\n",text1);
	printf("要查找的字符串为：\n%s\n",text2);

	for(int i = 0;(text1[i] = toupper(text1[i]));i++);
	for(i = 0;(text2[i] = toupper(text2[i]));i++);

	printf("第二段字符%s在第一串字符中找到\n",(strstr(text1,text2) == NULL) ? "不能" : "能");

	return 0;
}
