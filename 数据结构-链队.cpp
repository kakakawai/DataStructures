/*===========================
  数据结构 3.4.3 链队
===========================*/

//链队的定义
typedef struct QNode   //定义节点
{
	QElemType data;
	struct QNode *next;
}QNode,*QueuePtr;
typedef struct        //定义头指针和尾指针 
{
	QueuePtr front;
	QueuePtr rear;
}LinkQueue;


//初始化
bool InitQueue(LnkQueue &Q)
{
	Q.front = Q.rear = new QNode;   //为新队列的头节点分配空间，并给头指针和尾指针赋值
	if(!Q.front)                    //存储分配失败
	{
		exit(1);
	}
	Q.front->next = NULL;           
	return true;
}

//入队
bool EnQueue(LinkQueue &Q,QElemType e) //队列地址和新加入的值
{
	p = new QNode;               //声明新节点，并分配内存
	if(!p)                       //节点内存为空？
	{
		exit(1);
	}
	p->data = e;                 //赋值给新节点
	p->next = NULL;              //新节点的下一地址为空（等价为Q.front->next = NULL;）
	Q.rear = p;                  //新节点加入队列

	return true;
}

//出队
bool DeQueue(LinkQueue &Q,QElemType &e) //队列地址和暂存变量的地址
{
	if(Q.front == Q.rear) //若队列空，报错
	{
		return error;
	}
	p = Q.front->next;
	e = p->data;
	Q.front->next = p->next;  //Q.front->next = Q.front->next->next
	if(Q.rear == p)           //当最后一个元素被删除后，尾指针消失，此时将头指针赋给尾指针，此时队列为空 
	{
		Q.rear = Q.front;
	}
	delete p;
	return true;
}