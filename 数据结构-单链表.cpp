// 数据结构2.3单链表

//单链表的存储结构
typedef struct LNode
{
	ElemType data;          //结点的数据域
	struct LNode *next;    //结点的指针域
}LNode,*LinkList;         //LinkList指向结构体LNode的指针类型

//单链表结点的初始化
bool init_list_L(LinkList &L)
{
	LNode L;
	L->next = NULL;
	return true;
}

//创建单链表---前插法
void create_list_L(LinkList L, int n)
{
	LNode L;
	L->next = NULL;
	for(i = n; i>0; --i)
	{
		LNode p;
		cin>>p->data;
		p->next = L->next; 
		L->next = p;
	}
}

//创建单链表---后插法
void create_list_L(LinkList &L, int n)
{
	LNode L;
	L->next = NULL;
	r = L;
	for(i = 0; i<n; ++i)
	{
		LNode p;
		cin>>p->data;
		p->next = NULL;
		r->next = p;

		r = p;
	}
}

//单链表按照序号查找
bool getelem_L(LinkList L, int i, ElemType e)
{
	p = L->next;         //p指向第一个结点
	j = 1;
	while(p&&j<i)       //顺链表向后扫描，直到第i个元素或p为空
	{
		p = p->next;
		++j;
	}
	if(!p || j>i)
	{
		return false;
	}
	e = p->data;
	return true;
}

//单链表按值查找
LNode *locate_elem_L(LinkList L, ElemType e)
{
	p = L->next;
	while(p&&(p->data != e))
	{
		p = p->next;
	}
	return p;
}

//单链表插入(插入到第i个结点)
bool List_insert_L(LinkList &L, int i, ElemType e)
{
	p = L;
	j = 0;
	while(p&&j<i-1)            //找到第i个结点
	{
		p = p->next;
		++j;
	}
	if(!p || j>i-1)
	{
		return false;
	}
	LNode s;
	s->data = e;
	s->next = p->next;
	p->next = s;
	return true;
}

//单链表删除(删除第i个结点)
bool List_delete_L(LinkList L, int i, ElemType e)
{
	p = L;
	j = 0;
	while(p->next || j<i-1)  //寻找第i-1个结点
	{
		p = p->next;
	}
	if(!(p->next) || j>i-1)
	{
		return false;
	}
	q = p->next;
	p->next = q->next;
	e = q->data;            //可选择输出第i个结点的值
	delete q;

	return true;
}

