# include<stdio.h>
# include<ctype.h>
# include<stdlib.h>

struct Node *createnode(long value);
struct Node *addnode(long value,struct Node *pNode);

void listnodes(struct Node *pNode);//����������
void freenodes(struct Node *pNode);//�ͷ��ڴ�

/*=============================================
               �����ڵ�
 =============================================*/
struct Node
{
	long item;
	int count;
	struct Node *pleft;
	struct Node *pright;
};

/*============================================
			      ������
 ============================================*/
int main(void)
{
	long newvalue = 0;
	struct Node *pRoot = NULL;
	char answer = 'n';

	do
	{
		printf("Enter the node value:");
		scanf(" %ld",&newvalue);

		if(pRoot == NULL)
		{
			pRoot = createnode(newvalue);
		}
		else
		{
			addnode(newvalue,pRoot);
		}

		printf("\nDo you want to enter another value (Y or N)?");
		scanf(" %c",&answer);
	}while(tolower(answer) == 'y');

	printf("\nThe value in ascending sequence are:\n");
	listnodes(pRoot);
	freenodes(pRoot);


	return 0;
}
/*============================================
			����һ���ڵ㲢�����ڴ�
 ============================================*/
struct Node *createnode(long value)
{
	struct Node *pNode = (struct Node *)malloc(sizeof(struct Node));
	pNode->item = value;
	pNode->count = 1;
	pNode->pleft = pNode->pright = NULL;
	return pNode;
}

/*===========================================
			 ����ڵ㣨����
 ===========================================*/
struct Node *addnode(long value,struct Node *pNode)
{
	if(pNode == NULL)
	{
		return createnode(value);
	}
	if(value == pNode->item)
	{
		++pNode->count;
		return pNode;
	}
	if(value > pNode->item)
	{
		if(pNode->pright == NULL)
		{
			pNode->pright = createnode(value);
			return pNode->pright;
		}
		else
		{
			return addnode(value,pNode->pright);
		}
	}
	else
	{
		if(pNode->pleft == NULL)
		{
			pNode->pleft = createnode(value);
			return pNode->pleft;
		}
		else
		{
			return addnode(value,pNode->pleft);
		}
	}
}
/*==========================================
			���������������
 ==========================================*/
void listnodes(struct Node *pNode)
{
	if(pNode->pleft != NULL)               //�ú�����Ϊʲô
	{printf("\n1\n");
		listnodes(pNode->pleft);
	}

	for(int i = 0; i<pNode->count; i++)
	{printf("\n2\n");
		printf("%10ld\n",pNode->item);
	}

	if(pNode->pright != NULL)
	{printf("\n3\n");
		listnodes(pNode->pright);
	}
}
/*=========================================
			�������������ͷ��ڴ�
 =========================================*/
void freenodes(struct Node *pNode)
{
	if(pNode == NULL)
		return;
	if(pNode->pleft != NULL)         
	{
		freenodes(pNode->pleft);
	}
	if(pNode->pright != NULL)
	{
		freenodes(pNode->pright);
	}

	free(pNode);
}