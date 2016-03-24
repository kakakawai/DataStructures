//���ݽṹ 2.1˳���

//˳���洢�ṹ
# define MAXSIZE 100
typedef struct
{
	Elemtype *elem; //�洢�ռ�Ļ���ַ
	int length;     //��ǰ����
}SqList;

//˳����ʼ��
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

//˳���ֵ����
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

//˳������
bool list_insert_Sq(Sqlist &L, int i, float e)
{
	if(i<1||i>L.length+1)           //iֵ�ĺϷ���ΧΪ1~L.length
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

//˳���ɾ��
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

