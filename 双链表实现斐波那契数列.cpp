# include <stdio.h>
# include <stdlib.h>

typedef struct DuLNode
{
	int data;
	struct DuLNode *prior;
	struct DuLNode *next;
}DuLNode,*LinkList;

void creat_DuList(LinkList *pL);
void Fibonacci(LinkList *pL);
void show_DuList(LinkList pL);

int main(void)
{
	LinkList pL;
	creat_DuList(&pL);
	Fibonacci(&pL);
	//printf("%d\n",pL->data);
	show_DuList(pL);
	
	return 0;
}

void creat_DuList(LinkList *pL)
{
	*pL = NULL;
	printf("˫���������ɹ���\n");
}

void Fibonacci(LinkList *pL)
{	
	int m,i;
	DuLNode *A,*B;
	
	A=B=(DuLNode *)malloc(sizeof(DuLNode));
	if(!A || !B)
	{
		printf("�ڴ����ʧ��\n");
		exit(1);
	}
	A->data = B->data = 1;
	*pL = A;
	A->prior = *pL;
	A->next = B;
	B->prior = A;
	B->next = NULL;
	
	printf("����쳲��������е�λ����");
	scanf("%d",&m);
	if(m<=0)
	{
		printf("������������λ����\n");
		exit(1);
	}
	else
	{
		for(i = 2; i<m; i++)
		{
			DuLNode *S;
			S = (DuLNode *)malloc(sizeof(DuLNode));
			if(!S)
			{
				printf("�ڴ����ʧ��\n");
			}
			S->data = A->data + B->data;
			B->next = S;
			S->prior = B;
			A = B;
			B = S;
			B->next = NULL;
		}
		
	}
}

void show_DuList(LinkList pL)
{
	do
	{
		printf("%d\n",pL->data);
		pL = pL->next;
	}while(pL);
}