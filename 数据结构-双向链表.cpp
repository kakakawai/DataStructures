//数据结构-2.3.4双向链表
//双向链表存储结构
typedef struct DuLNode
{
	ElemType data;
	struct DuLNode *prior;
	struct DuLNode *next;
}DuLNode,*DuLinkList;

//双向链表的插入到第i个前面
bool List_insert_DuL(DuLinkList &L, int i, ElemType e)
{
	if(!(P = get_elem_DuL(L,i))) //定位到链表的第i个
	{
		return false;
	}
	DuLNode s;
	s->data = e;
	s->prior = p->prior;
	p->prior->next = s;
	s->next = p;
	p->prior = s;

	return true;
}

//双向链表的删除
bool list_delete_DuL(DuLlinklist &L, int i, ElemType e)
{
	if(!(p = GetElemp_DuL(L,i)))
	{
		return false;
	}
	e = p->data;
	p->prior->next = p->next;
	p->next->prior = p->prior;

	delete p;

	return true;
}