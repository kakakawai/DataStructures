//数据结构--2.4.1线性表的合并

//线性表的合并
void union(List &LA, List LB)
{
	LA_len = ListLength(LA);   //线性表长度
	LB_len = ListLength(LB);
	for(i = 1; i<=LB_len; i++)
	{
		GetElem(LB,e);
		if(!locate_Elem(LA,e))    //当LA中不包含e，则插入LA
		{
			List_insert(LA, ++LA, e);
		}
	}
}

//顺序有序表的合并
void MergeList_Sq(SqList LA, SqList LB, SqList &LC)
{
	pa = LA.elem;                            //pa和pb分别指向两个表的第一个元素
	pb = LB.elem;

	LC.length = LA.length + LB.length;     //新表长度为LALB之和
	LC.elem = new ElemType[LC.length];     //为新表分配空间
	pc = LC.elem;						  //指向新表表头
	pa_last = LA.elem + LA.length - 1;    //指向表尾最后一个元素
	pb_last = LB.elem + LA.length - 1;
	while(pa<=pa_last && pb<=pb_last)     //两个表都非空
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
	while(pa<=pa_last)             //LB到达表尾
	{
		*pc++ = *pa++;
	}
	while(pb<=pb_last)			//LA到达表尾
	{
		*pc++ = *pb++;
	}
}

//链式有序表的合并(从大到小)
void MergeList_L(LinkList &LA, LinkLIst LB, LinkList LC)
{
	pa = LA->next;                  //pa pb pc 定位到LA LB LC 的头结点
	pb = LB->next;                  //LA的头结点作为LC的头结点
	LC = LA;
	pc = LC;
	while(pa && pb)                 //当LA LB都不为空
	{
		if(pa->data <= pb->data)    //pa值小于pb
		{
			pc->next = pa;
			pc = pa;
			pa = pa->next;
		}
		else                        //pa值大于pb
		{
			pc->next = pb;
			pc = pb;
			pb = pb->next;
		}
	}
	pc->next = (pa ? pa : pb);      //pa或pb为空时，LC指向剩余结点
	delete LB;
}