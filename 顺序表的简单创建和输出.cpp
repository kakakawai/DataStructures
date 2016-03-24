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
	printf("长度为%d的顺序表创建成功。\n",MAXSIZE);

	printf("输入要输入元素的个数:");
	scanf("%d",&num);
	if(num>MAXSIZE)
	{
		printf("输入数据超出容量\n");
		return false;
	}
	for(; L.length<num; L.length++)
	{
		if(L.length == MAXSIZE)
		{
			printf("\n超出顺序表容量\n");
			return false;
		}
		printf("输入元素值:");
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