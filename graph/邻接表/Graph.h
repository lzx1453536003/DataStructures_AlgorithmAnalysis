#pragma once

#define INIT_CAPACITY 4

typedef struct _vertex_node
{
	char vertex;
	_vertex_node* link_vertex;
}VertexNode, * VertexLink;

typedef struct _graph
{
	int capacity;
	int vertexNum;
	int edgeNum;
	VertexNode vertexts[1];
}Graph, *PtrGraph;

PtrGraph create_graph(const char* path);

void destroy_graph(PtrGraph p_graph);

