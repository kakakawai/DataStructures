/*===================
 数据结构 3.4.2 顺序队列
====================*/

//队列定义
# define MAXQSIZE 100
typedef struct
{
	QElemType *base; //初始化的动态分配空间
	int front;       //头位置-》当删除头元素时，头元素+1
	int rear;        //尾位置-》当加入新队尾元素时，尾位置+1
}SqQueue;


//队列初始化

bool InitQueue(SqQueue &Q)
{
	Q.base = new QElemtype [MAXQSIZE]; //赋值内存地址
	if(!Q.base)
	{
		exit(1);
	}
	Q.front = Q.rear = 0;
	return true;
}

//求队列长度
//非循环队列-》尾位置-头位置
//循环队列-》差值可能为负数，所以将差值加上MAXQSIZE，然后与MAXQSIZE求余
int QueueLength(SqQueue Q)
{
	return(Q.rear - Q.front + MAXQSIZE)%MAXQSIZE;
}

//入队
bool EnQueue(SqQueue &Q,QElemType e)    //队列地址和插入值
{
	if((Q.rear+1)%MAXQSIZE == Q.front)  //若队列满，则报错
	{
		return error;
	}
	Q.base[Q.rear] = e;                 //赋值
	Q.rear = (Q.rear + 1)%MAXQSIZE;     //尾位置移至下一地址
	return true;
}

//出队
bool DeQueue(SqQueue &Q, QElemType &e)  //队列地址和【暂存删除节点值的变量地址】
{
	if(Q.rear== Q.front)    //队列空？
	{
		return error;
	}
	e = Q.base[Q.front];                 //将删除节点值赋给暂存变量（根据需求增删）
	Q.front = ( Q.front + 1 ) % MAXQSIZE;//头位置移至下一个

	return true;
}

