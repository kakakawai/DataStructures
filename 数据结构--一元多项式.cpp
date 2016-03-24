//数据结构2.4.3一元多项式

//一元多项式的表示：长度为m，每个元素有两个数据项（系数项和指数项）的线性表
typedef struct PNode
{
	float coef;
	int expn;
	struct PNode *next;
}PNode,*Polynomial;

//一元多项式的创建
void creat_polyn(Polynomial &P, int m)
{
	p->next = NULL;                         //建立一个带头结点的单链表
	for(i = 1; i<=m; ++i)                   //依次输入m个非零项
	{
		PNode s;
		cin>>s->coef;                       //赋值给s的系数
		cin>>s->expn;						//复制给s的指数
		pre = p;
		q = q->next;
		while(q && q->expn < s->expn)       //当s指数值小于q指数值时，将s结点插入q结点之前
		{
			pre = q;
			q = q->next;
		}
		s->next = q;
		pre->next = s;
	}
}

//一元多项式的相加（将p2插入p1作为p3）
void add_polyn(Polynomial &Pa,Polynmial &Pb)
{
	p1 = Pa->next;								//将p1 p2 p3 定位到Pa Pb 第一个元素
	p2 = Pb->next;
	p3 = Pa;									//将Pa第一个元素作为p3头结点
	while(P1 && P2)                             //当p1p2不为空
	{
		if(p1->expn == p2->expn)				//当p1指数等于p2指数
		{
			sum = p1->coef + p2->coef;          //求p3系数和
			if(!sum)							//当系数和不为零
			{
				p1->coef = sum;
				p3->next = p1;
				p3 = p1;
				p1 = p1->next;

				r = p2;                        //删除p2结点
				p2 = p2->next;
				delete r;
			}
			else                               //系数和为零
			{
				r = p1;                        
				p1 = p1->next;
				delete r;

				r = p2;
				p2 = p2->next;
				delete r;
			}
		}
		else if(p1->expn < p2->expn)           //当p1系数小于p2系数时
		{
			p3->next = p1;
			p3 = p1;
			p1 = p1->next;
		}
		else								   //当p1系数大于p2系数时
		{
			p3->next = p2;
			p3 = p2;
			p2 = p2->next;
		}
		
	}
	p3->next = (p1 ? p1 : p2);				  //插入非空表的剩余段
	delete Pb;
}