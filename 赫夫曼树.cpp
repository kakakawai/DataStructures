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
	printf("输入叶子节点数：");
	scanf("%d",&leafNode);               
	if(leafNode <= 1)
	{
		return 0;
	}
	allNode = 2*leafNode-1; //前n个为叶子节点，n+1到2n-1为构造的赫夫曼树，第2n-1个是完成的赫夫曼树的根节点
	HTNode *HT;
	HT = (HTNode *)malloc(sizeof(HTNode)*(allNode + 1));        //结构体数组
	InitHuffmanTree(HT,allNode,leafNode);
	CreateHuffmanTree(HT,allNode,leafNode);

	return 0;
}

void InitHuffmanTree(HTNode *HT,int allNode,int leafNode)
{
	int i;
	for(i=1; i<=allNode; i++)                //所有节点初始化
	{
		HT[i].parent = 0;
		HT[i].lchild = 0;
		HT[i].rchild = 0;
		HT[i].weight = 0;
		printf("Init finished!\n");
	}
	for(i=1; i<=leafNode; i++)                //输入前n个叶子节点的权重
	{
		printf("Enter weight:");
		scanf("%d",&HT[i].weight);
	}
	printf("Init finished!\n");
}

void CreateHuffmanTree(HTNode *HT,int allNode,int leafNode)
{
	int i;
	for(i=leafNode+1; i<=allNode; i++)              //构造赫夫曼树
	{
		printf("Creating!\n");
		printf("%d,%d,%d,%d\n",HT[i].parent,HT[i].lchild,HT[i].rchild,HT[i].weight);
		NodeSelect(i,HT);                      //从1到i-1中选择parent=0，且权值最小的两个节点，并返回index
		HT[s1].parent = HT[s2].parent = i; //将选择的两个节点作为i节点的子节点，i节点的权重为s1s2权重之和
		HT[i].lchild = s1;
		HT[i].rchild = s2;
		printf("%d,%d\n",HT[s1].parent,HT[s2].parent);
		HT[i].weight = HT[s1].weight + HT[s2].weight;
		printf("%d,%d,%d,%d\n",HT[i].parent,HT[i].lchild,HT[i].rchild,HT[i].weight);
	}
}

void NodeSelect(int i,HTNode *HT) //判断parent是否存在，从parent不存在的节点中找最小的
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