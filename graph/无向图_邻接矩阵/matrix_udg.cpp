#include"matrix_udg.h"
#include<stdlib.h>
#include<malloc.h>

#define isLetter(a) (((a)>='a')&&((a)<='z')) || (((a)>='A') && ((a)<='Z'))
#define LENGTH(a) (sizeof(a)/sizeof(a[0]))  //sizeof 是编译阶段进行计算的，数组名并不等于地址

static int get_position(Graph* graph, char vertex);

pGraph create_example_graph()
{
	char vexs[] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H' };
	char edges[][2] = {
		{'A', 'D'},
		{'A', 'E'},
		{'A', 'H'},

		{'D', 'H'},
		{'E', 'H'},
		
		{'H', 'C'},
		{'H', 'G'},
		{'H', 'B'},

		{'F', 'C'},
		{'F', 'B'},
		{'F', 'G'},
	};
	int vlen = LENGTH(vexs);
	int elen = LENGTH(edges);

	Graph* pG = (Graph*)calloc(1, sizeof(Graph));
	if (pG == nullptr)
	{
		return 0;
	}
	pG->edgnum = elen;
	pG->vexnum = vlen;
	for (int i = 0; i < pG->vexnum; ++i)
	{
		pG->vexs[i] = vexs[i];
	}
	for (int i = 0; i < pG->edgnum; ++i)
	{
		
		int p1 = get_position(pG, edges[i][0]);
		int p2 = get_position(pG, edges[i][1]);

		pG->matrix[p1][p2] = 1;
		pG->matrix[p2][p1] = 1;
	}

	return pG;
}

void dfs_traverse(Graph* g)
{
	int visited[MAX]; //顶点访问标记 ,
	int stack[MAX];
	int topIndex = 0;
	//初始化所有的顶点都没有被访问过
	for (int i = 0; i < g->vexnum; i++)
	{
		visited[i] = 0;
	}
	
	if (g->vexnum <= 0)
		return;

	//从第一个顶点开始遍历
	stack[topIndex++] = g->vexs[0];

	while (topIndex > 0)
	{
		char curVertex = stack[--topIndex];
		int curVertexIndex = get_position(g, curVertex);
		if (visited[curVertexIndex] == 1)
			continue;
		printf("%c  ", curVertex);
		visited[curVertexIndex] = 1;
		for (int i = g->vexnum - 1; i >= 0; --i)
		{
			if (g->matrix[curVertexIndex][i] == 1 && visited[i] == 0)
				stack[topIndex++] = g->vexs[i];
		}
	}
	printf("\n");
}


/**
	BFS广度优先搜索
*/
void bfs_traverse(Graph* g)
{
	int visited[MAX]; //顶点访问标记 ,
	int queue[MAX];
	int front = 0;
	int rear = 0;

	//初始化所有的顶点都没有被访问过
	for (int i = 0; i < g->vexnum; i++)
	{
		visited[i] = 0;
	}

	if (g->vexnum <= 0)
		return;

	//从第一个顶点开始遍历
	queue[rear++] = g->vexs[0];

	while (front != rear)
	{
		char curVertex = queue[front++];
		int curVertexIndex = get_position(g, curVertex);
		if (visited[curVertexIndex] == 1)
			continue;
		printf("%c  ", curVertex);
		visited[curVertexIndex] = 1;
		for (int i = 0; i < g->vexnum; ++i)
		{
			if (g->matrix[curVertexIndex][i] == 1 && visited[i] == 0)
				queue[rear++] = g->vexs[i];
		}
	}
	printf("\n");
}

/*
	得到顶点在顶点数组中的索引
*/
static int get_position(Graph* graph, char vertex)
{
	for (int i = 0; i < graph->vexnum; ++i)
		if (graph->vexs[i] == vertex)
			return i;
	return -1;
}

void print_graph(Graph* g)
{
	for (int i = 0; i < g->vexnum; ++i)
	{
		for (int j = 0; j < g->vexnum; ++j)
		{
			printf("%d   ", g->matrix[i][j]);
		}
		printf("\n");
	}
}