# include <stdio.h>
# include <windows.h>
# define MAXSIZE 4

float ElemType[MAXSIZE];
typedef struct
	{
		float *elem;
		int length;
	}SqList;

bool init_list_Sq(SqList &L);
void show(SqList &L);

int main(void)
{
	
	SqList L;
	init_list_Sq(L);
	show(L);	

	return 0;
}

bool init_list_Sq(SqList &L)
{
	int num;
	L.elem = ElemType;

	if(!L.elem)
	{
		return false;
	}
	L.length = 0;
	printf("����Ϊ%d��˳������ɹ���\n",MAXSIZE);

	printf("����Ҫ����Ԫ�صĸ���:");
	scanf("%d",&num);
	if(num>MAXSIZE)
	{
		printf("�������ݳ�������\n");
		return false;
	}
	for(; L.length<num; L.length++)
	{
		if(L.length == MAXSIZE)
		{
			printf("\n����˳�������\n");
			return false;
		}
		printf("����Ԫ��ֵ:");
		scanf("%f",&L.elem[L.length]);
	}
}

void show(SqList &L)
{
	int i = 0;
	for(; i<L.length; i++)
	{
		printf("%.2f\n",L.elem[i]);
	}
}