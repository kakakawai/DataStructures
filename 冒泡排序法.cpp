# include <stdio.h>
# include <stdlib.h>
# include <windows.h>
# include <string.h>

# define BUFFER_LEN 100
# define NUM_P 100

int main (void)
{
	char buffer[BUFFER_LEN];
	char *pS[NUM_P] = {NULL};
	char *pTemp = NULL;
	bool sorted = false;
	int NUM_S = 0;
	int LastString = 0;
	
	printf("输入不大于100字符的信息，以回车结束输入:\n");
	while((*fgets(buffer,BUFFER_LEN,stdin) != '\n') && (NUM_S < NUM_P))
	{
		pS[NUM_S] = (char *)malloc(sizeof(buffer) + 1);
		if(pS[NUM_S] == NULL)
		{
			printf("你TM真是个大傻逼！！\n");
		}
		strcpy(pS[NUM_S++],buffer);
	}
	LastString = NUM_S;
/*
===========================================================
	冒泡排序法
===========================================================
*/
	while(!sorted)
	{
		sorted = true;
		for(NUM_S = 0; NUM_S < LastString-1; NUM_S++)
		{
			if(strcmp(pS[NUM_S],pS[NUM_S+1]) > 0)
			{
				sorted = false;
				pTemp = pS[NUM_S];
				pS[NUM_S] = pS[NUM_S+1];
				pS[NUM_S+1] = pTemp;
			}
		}
	}
//===========================================================
//===========================================================
	printf("你错过了这么多好东西：\n");
	for(NUM_S = 0; NUM_S < LastString; NUM_S++)
	{
		printf("%s",pS[NUM_S]);
	}
	
	
	return 0;
}