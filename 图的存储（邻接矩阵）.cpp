#include <stdio.h>

#define MaxInt 32767
#define MVNum 100

typedef struct{
	char vexs[MVNum];       //顶点表
	int arcs[MVNum][MVNum]; //邻接数组
	int vexnum,arcnum;   //顶点数和边数
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

	printf("\n输入顶点数：");
	scanf("%d",&(*G).vexnum);
	
	printf("\n输入总边数：");
	scanf("%d",&(*G).arcnum);

	int i = 0;
	int j = 0;
	int k = 0;
	for(; i<(*G).vexnum; i++)
	{
		printf("\n输入各顶点信息：");
		scanf("%d",&(*G).vexs[i]);
	}
	for(i=0; i<(*G).arcnum; i++)
	{
		for(j=0; j<(*G).arcnum; j++)
		{
			(*G).arcs[i][j] = MaxInt;
		}

		printf("\n输入第%d条边起点的顶点号：",i+1);
		scanf("%d",&startNode);

		printf("\n输入第%d条边终点的顶点号：",i+1);
		scanf("%d",&endNode);

		printf("\n输入第%d条边的权重："，i+1);
		scanf("%d",&nodeWeight);

		(*G).arcs[startNode][endNode] = (*G).arcs[endNode][startNode] = nodeWeight;
	}
	printf("OK!\n");
}