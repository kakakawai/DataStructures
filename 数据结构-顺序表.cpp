//数据结构 2.1顺序表

//顺序表存储结构
# define MAXSIZE 100
typedef struct
{
	Elemtype *elem; //存储空间的基地址
	int length;     //当前长度
}SqList;

//顺序表初始化
bool init_list_Sq(SqList &L)
{
	L.elem = ElemType[MAXSIZE];
	if(!L.elem)
	{
		exit(1);
	}
	L.length = 0;
	return true;
}

//顺序表按值查找
int locate_elem_Sq(SqList L,float e)
{
	for(i = 0; i<L.length; i++)
	{
		if(L.elem[i] == e)
		{
			return i+1;
		}
	}
	return 0;
}

//顺序表插入
bool list_insert_Sq(Sqlist &L, int i, float e)
{
	if(i<1||i>L.length+1)           //i值的合法范围为1~L.length
	{
		return false;
	}
	else if(L.length == MAXSIZE)
	{
		return false;
	}
	for(j = L.length-1; j>=i-1; j--)
	{
		L.elem[j+1] = L.elem[j];
	}
	L.elem[i-1] = e;
	++L.length;
	return true;
}

//顺序表删除
float list_delete_Sq(Sqlist &L, int i, float e)
{
	if(i<1||i>L.length)
	{
		return false;
	}
	e = L.elem[i-1];
	for(j = i; j<=L.length; j++)
	{
		L.elem[j-1] = L.elem[j];
	}
	--L.length;
	return e;
}

