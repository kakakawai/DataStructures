// ���ݽṹ2.3������

//������Ĵ洢�ṹ
typedef struct LNode
{
	ElemType data;          //����������
	struct LNode *next;    //����ָ����
}LNode,*LinkList;         //LinkListָ��ṹ��LNode��ָ������

//��������ĳ�ʼ��
bool init_list_L(LinkList &L)
{
	LNode L;
	L->next = NULL;
	return true;
}

//����������---ǰ�巨
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

//����������---��巨
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

//����������Ų���
bool getelem_L(LinkList L, int i, ElemType e)
{
	p = L->next;         //pָ���һ�����
	j = 1;
	while(p&&j<i)       //˳�������ɨ�裬ֱ����i��Ԫ�ػ�pΪ��
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

//������ֵ����
LNode *locate_elem_L(LinkList L, ElemType e)
{
	p = L->next;
	while(p&&(p->data != e))
	{
		p = p->next;
	}
	return p;
}

//���������(���뵽��i�����)
bool List_insert_L(LinkList &L, int i, ElemType e)
{
	p = L;
	j = 0;
	while(p&&j<i-1)            //�ҵ���i�����
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

//������ɾ��(ɾ����i�����)
bool List_delete_L(LinkList L, int i, ElemType e)
{
	p = L;
	j = 0;
	while(p->next || j<i-1)  //Ѱ�ҵ�i-1�����
	{
		p = p->next;
	}
	if(!(p->next) || j>i-1)
	{
		return false;
	}
	q = p->next;
	p->next = q->next;
	e = q->data;            //��ѡ�������i������ֵ
	delete q;

	return true;
}

