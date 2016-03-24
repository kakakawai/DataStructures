/*===================
 ���ݽṹ 3.4.2 ˳�����
====================*/

//���ж���
# define MAXQSIZE 100
typedef struct
{
	QElemType *base; //��ʼ���Ķ�̬����ռ�
	int front;       //ͷλ��-����ɾ��ͷԪ��ʱ��ͷԪ��+1
	int rear;        //βλ��-���������¶�βԪ��ʱ��βλ��+1
}SqQueue;


//���г�ʼ��

bool InitQueue(SqQueue &Q)
{
	Q.base = new QElemtype [MAXQSIZE]; //��ֵ�ڴ��ַ
	if(!Q.base)
	{
		exit(1);
	}
	Q.front = Q.rear = 0;
	return true;
}

//����г���
//��ѭ������-��βλ��-ͷλ��
//ѭ������-����ֵ����Ϊ���������Խ���ֵ����MAXQSIZE��Ȼ����MAXQSIZE����
int QueueLength(SqQueue Q)
{
	return(Q.rear - Q.front + MAXQSIZE)%MAXQSIZE;
}

//���
bool EnQueue(SqQueue &Q,QElemType e)    //���е�ַ�Ͳ���ֵ
{
	if((Q.rear+1)%MAXQSIZE == Q.front)  //�����������򱨴�
	{
		return error;
	}
	Q.base[Q.rear] = e;                 //��ֵ
	Q.rear = (Q.rear + 1)%MAXQSIZE;     //βλ��������һ��ַ
	return true;
}

//����
bool DeQueue(SqQueue &Q, QElemType &e)  //���е�ַ�͡��ݴ�ɾ���ڵ�ֵ�ı�����ַ��
{
	if(Q.rear== Q.front)    //���пգ�
	{
		return error;
	}
	e = Q.base[Q.front];                 //��ɾ���ڵ�ֵ�����ݴ����������������ɾ��
	Q.front = ( Q.front + 1 ) % MAXQSIZE;//ͷλ��������һ��

	return true;
}

