//���ݽṹ2.4.3һԪ����ʽ

//һԪ����ʽ�ı�ʾ������Ϊm��ÿ��Ԫ�������������ϵ�����ָ��������Ա�
typedef struct PNode
{
	float coef;
	int expn;
	struct PNode *next;
}PNode,*Polynomial;

//һԪ����ʽ�Ĵ���
void creat_polyn(Polynomial &P, int m)
{
	p->next = NULL;                         //����һ����ͷ���ĵ�����
	for(i = 1; i<=m; ++i)                   //��������m��������
	{
		PNode s;
		cin>>s->coef;                       //��ֵ��s��ϵ��
		cin>>s->expn;						//���Ƹ�s��ָ��
		pre = p;
		q = q->next;
		while(q && q->expn < s->expn)       //��sָ��ֵС��qָ��ֵʱ����s������q���֮ǰ
		{
			pre = q;
			q = q->next;
		}
		s->next = q;
		pre->next = s;
	}
}

//һԪ����ʽ����ӣ���p2����p1��Ϊp3��
void add_polyn(Polynomial &Pa,Polynmial &Pb)
{
	p1 = Pa->next;								//��p1 p2 p3 ��λ��Pa Pb ��һ��Ԫ��
	p2 = Pb->next;
	p3 = Pa;									//��Pa��һ��Ԫ����Ϊp3ͷ���
	while(P1 && P2)                             //��p1p2��Ϊ��
	{
		if(p1->expn == p2->expn)				//��p1ָ������p2ָ��
		{
			sum = p1->coef + p2->coef;          //��p3ϵ����
			if(!sum)							//��ϵ���Ͳ�Ϊ��
			{
				p1->coef = sum;
				p3->next = p1;
				p3 = p1;
				p1 = p1->next;

				r = p2;                        //ɾ��p2���
				p2 = p2->next;
				delete r;
			}
			else                               //ϵ����Ϊ��
			{
				r = p1;                        
				p1 = p1->next;
				delete r;

				r = p2;
				p2 = p2->next;
				delete r;
			}
		}
		else if(p1->expn < p2->expn)           //��p1ϵ��С��p2ϵ��ʱ
		{
			p3->next = p1;
			p3 = p1;
			p1 = p1->next;
		}
		else								   //��p1ϵ������p2ϵ��ʱ
		{
			p3->next = p2;
			p3 = p2;
			p2 = p2->next;
		}
		
	}
	p3->next = (p1 ? p1 : p2);				  //����ǿձ��ʣ���
	delete Pb;
}