//���ݽṹ--˳��ջ

//˳��ջ�Ĵ洢�ṹ
# define MAXSIZE 100
typedef struct
{
	SElemType *base;  //ջ��ָ��
	SElemType *top;   //ջ��ָ��
	int stacksize;	  //ջ���������
}SqStack;

//˳��ջ�ĳ�ʼ��
bool InitStack(SqStack &S)
{
	int SElemType[MAXSIZE];
	S->base = SElemType;
	if(!S->base)
	{
		exit(1);       //�ڴ����ʧ��
	}
	S->top = S->base;
	S->stacksize = MAXSIZE;
	return true;
}

//��ջ
bool push(SqStack &S, int e)
{
	if(S.top - S.base == S.stacksize)   //�ж�ջ��
	{
		return false;
	}
	*S.top++=e;  //��eѹ��ջ����ջ��ָ��+1��
	return true;
}

//��ջ
bool pop(SqStack &S, int e)
{
	if(S.top == S.base)    //�ж�ջ��
	{
		return false;
	}
	e = *(--S.top);   //ջ��ָ��-1����ջ��Ԫ�ظ���e
	return true;
}

//ȡջ��Ԫ�أ���ȡֵ�����ı�ջ��Ԫ�أ�
bool Getpop(Sqstack S,int e)
{
	if(S.top == S.base)
	{
		return false;
	)
	e = *(S.top - 1);
	return true;
}

