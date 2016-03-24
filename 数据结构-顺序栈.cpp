//数据结构--顺序栈

//顺序栈的存储结构
# define MAXSIZE 100
typedef struct
{
	SElemType *base;  //栈底指针
	SElemType *top;   //栈顶指针
	int stacksize;	  //栈的最大容量
}SqStack;

//顺序栈的初始化
bool InitStack(SqStack &S)
{
	int SElemType[MAXSIZE];
	S->base = SElemType;
	if(!S->base)
	{
		exit(1);       //内存分配失败
	}
	S->top = S->base;
	S->stacksize = MAXSIZE;
	return true;
}

//入栈
bool push(SqStack &S, int e)
{
	if(S.top - S.base == S.stacksize)   //判断栈满
	{
		return false;
	}
	*S.top++=e;  //将e压入栈顶，栈顶指针+1。
	return true;
}

//出栈
bool pop(SqStack &S, int e)
{
	if(S.top == S.base)    //判断栈空
	{
		return false;
	}
	e = *(--S.top);   //栈顶指针-1，将栈顶元素赋给e
	return true;
}

//取栈顶元素（仅取值，不改变栈顶元素）
bool Getpop(Sqstack S,int e)
{
	if(S.top == S.base)
	{
		return false;
	)
	e = *(S.top - 1);
	return true;
}

