//���ݽṹ-2.3.4˫������
//˫������洢�ṹ
typedef struct DuLNode
{
	ElemType data;
	struct DuLNode *prior;
	struct DuLNode *next;
}DuLNode,*DuLinkList;

//˫������Ĳ��뵽��i��ǰ��
bool List_insert_DuL(DuLinkList &L, int i, ElemType e)
{
	if(!(P = get_elem_DuL(L,i))) //��λ������ĵ�i��
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

//˫�������ɾ��
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