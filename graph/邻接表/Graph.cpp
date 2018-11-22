#include "Graph.h"
#include <stdio.h>
#include <stdlib.h>
#include<memory.h>
#include<malloc.h>

PtrGraph create_graph(const char* path)
{
	FILE* fp;
	if (fopen_s(&fp, path, "r") == 1)
	{
		printf("打开文件失败");
		exit(1);
	}
	PtrGraph p_graph = (PtrGraph)calloc(1, (int)((Graph*)0)->vertexts + sizeof(VertexNode)*INIT_CAPACITY);//第一次使用初始化容量，容量不够再倍数扩充
	if (p_graph == 0)
	{
		puts("memory out");
		exit(1);
	}
	p_graph->capacity = INIT_CAPACITY;
	//读取顶点
	char ch;
	while ((ch = fgetc(fp)) != '\n')
	{
		if (ch == ' ')
			continue;
		if (p_graph->vertexNum >= p_graph->capacity)
		{
			PtrGraph tp_graph = (PtrGraph)realloc(p_graph, (int)((Graph*)0)->vertexts + p_graph->capacity * 2 * sizeof(VertexNode));
			if (tp_graph == nullptr)
			{
				puts("memory out\n");
				exit(1);
			}
			p_graph = tp_graph;
			p_graph->capacity *= 2;
		}
		p_graph->vertexts[p_graph->vertexNum].vertex = ch;
		p_graph->vertexNum++;
	}

	//读取边
	for (int i = 0; i < p_graph->vertexNum; i++)
	{
		int index = 0;
		VertexLink link = nullptr;
		VertexNode* node = link;
		while (true)
		{
			ch = fgetc(fp);
			if (ch == '\n')
				break;
			if (ch == '<')
			{
				ch = fgetc(fp);
				index = ch - 48;
				continue;
			}
			if (ch == ',' || ch == '{' || ch == '}' || ch == '>')
				continue;
			//p_graph->vertexts[index].vertex = ch;
			if (link == nullptr)
			{
				link = (VertexLink)calloc(1, sizeof(VertexNode));
				node = link;
				node->vertex = ch;
				node->link_vertex = nullptr;
			}
			else
			{
				node->link_vertex = (VertexLink)calloc(1, sizeof(VertexNode));
				node = node->link_vertex;
				node->vertex = ch;
				node->link_vertex = nullptr;
			}
		}
		p_graph->vertexts[index].link_vertex = link;
	}

	return p_graph;
}





