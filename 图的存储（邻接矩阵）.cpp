#include <stdio.h>

#define MaxInt 32767
#define MVNum 100

typedef struct{
	char vexs[MVNum];       //�����
	int arcs[MVNum][MVNum]; //�ڽ�����
	int vexnum,arcnum;   //�������ͱ���
}AMGraph;

void CreateUDN(AMGraph *G);

int main(void)
{
	AMGraph G;
	CreateUDN(&G);
	int i,j;
	for(i=0; i<G.arcnum; i++)
	{
		for(j=0; j<G.arcnum; j++)
		{
			printf("%d",G.arcs[i][j]);
		}
	}

	return 0;
}

void CreateUDN(AMGraph *G)
{
	int startNode;
	int endNode;
	int nodeWeight;

	printf("\n���붥������");
	scanf("%d",&(*G).vexnum);
	
	printf("\n�����ܱ�����");
	scanf("%d",&(*G).arcnum);

	int i = 0;
	int j = 0;
	int k = 0;
	for(; i<(*G).vexnum; i++)
	{
		printf("\n�����������Ϣ��");
		scanf("%d",&(*G).vexs[i]);
	}
	for(i=0; i<(*G).arcnum; i++)
	{
		for(j=0; j<(*G).arcnum; j++)
		{
			(*G).arcs[i][j] = MaxInt;
		}

		printf("\n�����%d�������Ķ���ţ�",i+1);
		scanf("%d",&startNode);

		printf("\n�����%d�����յ�Ķ���ţ�",i+1);
		scanf("%d",&endNode);

		printf("\n�����%d���ߵ�Ȩ�أ�"��i+1);
		scanf("%d",&nodeWeight);

		(*G).arcs[startNode][endNode] = (*G).arcs[endNode][startNode] = nodeWeight;
	}
	printf("OK!\n");
}