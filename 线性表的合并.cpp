//���ݽṹ--2.4.1���Ա�ĺϲ�

//���Ա�ĺϲ�
void union(List &LA, List LB)
{
	LA_len = ListLength(LA);   //���Ա���
	LB_len = ListLength(LB);
	for(i = 1; i<=LB_len; i++)
	{
		GetElem(LB,e);
		if(!locate_Elem(LA,e))    //��LA�в�����e�������LA
		{
			List_insert(LA, ++LA, e);
		}
	}
}

//˳�������ĺϲ�
void MergeList_Sq(SqList LA, SqList LB, SqList &LC)
{
	pa = LA.elem;                            //pa��pb�ֱ�ָ��������ĵ�һ��Ԫ��
	pb = LB.elem;

	LC.length = LA.length + LB.length;     //�±���ΪLALB֮��
	LC.elem = new ElemType[LC.length];     //Ϊ�±����ռ�
	pc = LC.elem;						  //ָ���±��ͷ
	pa_last = LA.elem + LA.length - 1;    //ָ���β���һ��Ԫ��
	pb_last = LB.elem + LA.length - 1;
	while(pa<=pa_last && pb<=pb_last)     //�������ǿ�
	{
		if(*pa <= *pb)
		{
			*pc++ = *pa++;
		}
		else
		{
			*pc++ = *pb++;
		}
	}
	while(pa<=pa_last)             //LB�����β
	{
		*pc++ = *pa++;
	}
	while(pb<=pb_last)			//LA�����β
	{
		*pc++ = *pb++;
	}
}

//��ʽ�����ĺϲ�(�Ӵ�С)
void MergeList_L(LinkList &LA, LinkLIst LB, LinkList LC)
{
	pa = LA->next;                  //pa pb pc ��λ��LA LB LC ��ͷ���
	pb = LB->next;                  //LA��ͷ�����ΪLC��ͷ���
	LC = LA;
	pc = LC;
	while(pa && pb)                 //��LA LB����Ϊ��
	{
		if(pa->data <= pb->data)    //paֵС��pb
		{
			pc->next = pa;
			pc = pa;
			pa = pa->next;
		}
		else                        //paֵ����pb
		{
			pc->next = pb;
			pc = pb;
			pb = pb->next;
		}
	}
	pc->next = (pa ? pa : pb);      //pa��pbΪ��ʱ��LCָ��ʣ����
	delete LB;
}