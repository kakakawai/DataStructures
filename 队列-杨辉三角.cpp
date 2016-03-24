# include <stdio.h>
# include <stdlib.h>
# define MAXSIZE 100

typedef struct
{
	int *base;
	int front;
	int rear;
}SqQueue;

void InitQueue(SqQueue *Q);
void EnQueue(SqQueue *Q);
void DeQueue(SqQueue *Q);

int main(void)
{
	SqQueue Q;
	InitQueue(&Q);

	return 0;
}

void InitQueue(SqQueue *Q)
{
	Q->base = (int *)malloc(MAXSIZE);
	if(!Q->base)
	{
		printf("�����ڴ�������\n");
		exit(1);
	}
	Q->front = Q->rear = 0;
	printf("���г�ʼ���ɹ�!\n");
}

void EnQueue(SqQueue *Q,int e)
{
	if((Q->rear + 1) % MAXSIZE == Q->front)
	{
		printf("����������\n");
	}
	Q->base[Q.rear] = e;
	Q->rear = (Q->rear + 1) % MAXSIZE;
	printf("��ӳɹ�!\n");
}

void DeQueue(SqQueue *Q, int *e)
{
	if(Q.rear == Q.front)
	{
		printf("����Ϊ��!\n");
	}
	e = Q->base[Q->front];
	Q->front = ( Q->front + 1 ) % MAXSIZE;
	printf("���ӳɹ�!\n");
}