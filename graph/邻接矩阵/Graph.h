#pragma once

#define MAX_VERTEX_NUM 100
typedef struct _graph
{
	int vertexNum;
	int edgeNum;
	char vertex[MAX_VERTEX_NUM];
	int matrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
}Graph, *PtrGraph;

PtrGraph create_graph(const char* path);
void destroy_graph(PtrGraph p_graph);

