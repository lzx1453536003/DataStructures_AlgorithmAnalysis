/**
	C:邻接矩阵图表的“无向图”(Matrix Undirected Graph)
	@author  liuzhanxiong
	@data 2019/2/11
*/

#include<stdio.h>

#define MAX 100

/*
	邻接矩阵表示的无向图
*/
typedef struct _graph
{
	char vexs[MAX];		  //顶点	
	int vexnum;			  //顶点总数
	int edgnum;			  //边总数	
	int matrix[MAX][MAX]; //邻接矩阵
}Graph, *pGraph;

///*
//	返回ch在graph中顶点集合中的位置
//*/
//static int get_position(Graph g, char ch);

/*
	创建图(自己输入)
*/
pGraph create_graph();
/**
	创建图使用已经提供的图的数据
*/
pGraph create_example_graph();

/**
	DFS深度优先搜索遍历图
*/
void dfs_traverse(Graph* g);


/**
	BFS广度优先搜索
*/
void bfs_traverse(Graph* g);

/**
	打印矩阵图
*/
void print_graph(Graph* g);