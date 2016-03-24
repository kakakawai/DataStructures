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
		printf("队列内存分配错误！\n");
		exit(1);
	}
	Q->front = Q->rear = 0;
	printf("队列初始化成功!\n");
}

void EnQueue(SqQueue *Q,int e)
{
	if((Q->rear + 1) % MAXSIZE == Q->front)
	{
		printf("队列已满！\n");
	}
	Q->base[Q.rear] = e;
	Q->rear = (Q->rear + 1) % MAXSIZE;
	printf("入队成功!\n");
}

void DeQueue(SqQueue *Q, int *e)
{
	if(Q.rear == Q.front)
	{
		printf("队列为空!\n");
	}
	e = Q->base[Q->front];
	Q->front = ( Q->front + 1 ) % MAXSIZE;
	printf("出队成功!\n");
}