#include <stdio.h>
#include <stdlib.h>

typedef struct{
	int weight;
	int parent,lchild,rchild;
}HTNode,*HuffmanTree;

int s1 = 1;
int s2 = 2;
int allNode,leafNode;

void InitHuffmanTree(HTNode *HT,int allNode,int leafNode);
void CreateHuffmanTree(HTNode *HT,int allNode,int leafNode);
void NodeSelect(int i,HTNode *HT);

int main(void)
{ 
	printf("����Ҷ�ӽڵ�����");
	scanf("%d",&leafNode);               
	if(leafNode <= 1)
	{
		return 0;
	}
	allNode = 2*leafNode-1; //ǰn��ΪҶ�ӽڵ㣬n+1��2n-1Ϊ����ĺշ���������2n-1������ɵĺշ������ĸ��ڵ�
	HTNode *HT;
	HT = (HTNode *)malloc(sizeof(HTNode)*(allNode + 1));        //�ṹ������
	InitHuffmanTree(HT,allNode,leafNode);
	CreateHuffmanTree(HT,allNode,leafNode);

	return 0;
}

void InitHuffmanTree(HTNode *HT,int allNode,int leafNode)
{
	int i;
	for(i=1; i<=allNode; i++)                //���нڵ��ʼ��
	{
		HT[i].parent = 0;
		HT[i].lchild = 0;
		HT[i].rchild = 0;
		HT[i].weight = 0;
		printf("Init finished!\n");
	}
	for(i=1; i<=leafNode; i++)                //����ǰn��Ҷ�ӽڵ��Ȩ��
	{
		printf("Enter weight:");
		scanf("%d",&HT[i].weight);
	}
	printf("Init finished!\n");
}

void CreateHuffmanTree(HTNode *HT,int allNode,int leafNode)
{
	int i;
	for(i=leafNode+1; i<=allNode; i++)              //����շ�����
	{
		printf("Creating!\n");
		printf("%d,%d,%d,%d\n",HT[i].parent,HT[i].lchild,HT[i].rchild,HT[i].weight);
		NodeSelect(i,HT);                      //��1��i-1��ѡ��parent=0����Ȩֵ��С�������ڵ㣬������index
		HT[s1].parent = HT[s2].parent = i; //��ѡ��������ڵ���Ϊi�ڵ���ӽڵ㣬i�ڵ��Ȩ��Ϊs1s2Ȩ��֮��
		HT[i].lchild = s1;
		HT[i].rchild = s2;
		printf("%d,%d\n",HT[s1].parent,HT[s2].parent);
		HT[i].weight = HT[s1].weight + HT[s2].weight;
		printf("%d,%d,%d,%d\n",HT[i].parent,HT[i].lchild,HT[i].rchild,HT[i].weight);
	}
}

void NodeSelect(int i,HTNode *HT) //�ж�parent�Ƿ���ڣ���parent�����ڵĽڵ�������С��
{
	printf("%d,%d\n",HT[s1].weight,HT[s2].weight);
	int k;
	for(k=1; k<i-1; k++)
	{
		printf("k:%d,%d,%d,%d\n",HT[k].parent,HT[k].lchild,HT[k].rchild,HT[k].weight);
		if(HT[k].parent > 0)
		{
			continue;
		}
		if(HT[s2].weight > HT[k].weight)
		{
			if(HT[s1].weight > HT[k].weight)
			{
				s2 = s1;
				s1 = k;
			}
			if(HT[s1].weight < HT[k].weight)
			{
				s2 = k;
			}
		}
	}
	printf("%d,%d\n",HT[s1].weight,HT[s2].weight);
}