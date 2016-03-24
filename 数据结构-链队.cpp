/*===========================
  ���ݽṹ 3.4.3 ����
===========================*/

//���ӵĶ���
typedef struct QNode   //����ڵ�
{
	QElemType data;
	struct QNode *next;
}QNode,*QueuePtr;
typedef struct        //����ͷָ���βָ�� 
{
	QueuePtr front;
	QueuePtr rear;
}LinkQueue;


//��ʼ��
bool InitQueue(LnkQueue &Q)
{
	Q.front = Q.rear = new QNode;   //Ϊ�¶��е�ͷ�ڵ����ռ䣬����ͷָ���βָ�븳ֵ
	if(!Q.front)                    //�洢����ʧ��
	{
		exit(1);
	}
	Q.front->next = NULL;           
	return true;
}

//���
bool EnQueue(LinkQueue &Q,QElemType e) //���е�ַ���¼����ֵ
{
	p = new QNode;               //�����½ڵ㣬�������ڴ�
	if(!p)                       //�ڵ��ڴ�Ϊ�գ�
	{
		exit(1);
	}
	p->data = e;                 //��ֵ���½ڵ�
	p->next = NULL;              //�½ڵ����һ��ַΪ�գ��ȼ�ΪQ.front->next = NULL;��
	Q.rear = p;                  //�½ڵ�������

	return true;
}

//����
bool DeQueue(LinkQueue &Q,QElemType &e) //���е�ַ���ݴ�����ĵ�ַ
{
	if(Q.front == Q.rear) //�����пգ�����
	{
		return error;
	}
	p = Q.front->next;
	e = p->data;
	Q.front->next = p->next;  //Q.front->next = Q.front->next->next
	if(Q.rear == p)           //�����һ��Ԫ�ر�ɾ����βָ����ʧ����ʱ��ͷָ�븳��βָ�룬��ʱ����Ϊ�� 
	{
		Q.rear = Q.front;
	}
	delete p;
	return true;
}