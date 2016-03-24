# include <stdio.h>
# include <stdlib.h>
# define MAXSIZE 100

typedef struct 
{
	int *elem;
	int length;
}SqList;
int ElemType[MAXSIZE];

void creat_Sq(SqList &L);
void FB(SqList &L);
void show_Sq(SqList &L);

int main(void)
{
	SqList L;
	creat_Sq(L);
	FB(L);
	show_Sq(L);
	
	return 0;
} 

void creat_Sq(SqList &L)
{
	L.elem = ElemType;
	if(!L.elem)
	{
		printf("�ڴ�������.\n");
		exit(1);
	}
	L.length = 0;
}

void FB(SqList &L)
{
	L.elem[0] = L.elem[1] = 1;
	int locate;
	printf("����쳲��������е�λ����");
	scanf("%d",&locate);

	if(locate <= 0)
	{
		printf("������������λ��.\n");
	}
	else if(locate == 1)
	{
		printf("%d\n",L.elem[0]);
	}
	else if(locate == 2)
	{
		printf("%d\n",L.elem[1]);
	}
	else
	{
		for(L.length = 2; L.length<locate; L.length++)
		{
			L.elem[L.length] = L.elem[L.length-1] + L.elem[L.length-2];
		}
	}
    
}

void show_Sq(SqList &L)
{
	int i = 0;
	for(; i<L.length; i++)
	{
		printf("%d\n",L.elem[i]);
	}
}