#include "Graph.h"
#include <stdio.h>
#include <stdlib.h>
#include<memory.h>
#include<malloc.h>

PtrGraph create_graph(const char* path)
{
	FILE* fp;
	if (fopen_s(&fp, path, "r") != 0)
	{
		printf("���ļ�ʧ�� path == %s\n", path);
		exit(1);
	}

	PtrGraph p_graph = (PtrGraph)malloc(sizeof(Graph));
	if (p_graph == nullptr)
	{
		puts("memory out\n");
		exit(1);
	}
	memset(p_graph, 0, sizeof(Graph));

	char ch;
	//��ȡ�ļ���һ�еĶ���
	while ((ch = fgetc(fp)) != EOF && ch != '\n')
	{
		if (p_graph->vertexNum >= MAX_VERTEX_NUM)
		{
			printf("������� %d ��\n", MAX_VERTEX_NUM);
			break;
		}
		if (ch != ' ')
		{
			p_graph->vertex[p_graph->vertexNum] = ch;
			p_graph->vertexNum++;
		}
	}
	//��ȡ�ļ��е��ڽӾ���
	for (int i = 0; i < p_graph->vertexNum; i++)
	{
		for (int j = 0; j < p_graph->vertexNum;j++)
		{
			while ((ch = fgetc(fp)) == ' ');
			if (ch == EOF || ch == '\n')
			{
				printf("���ݲ���");
				exit(1);
			}
			if (ch == '0')
				p_graph->matrix[i][j] = 0;
			else if(ch == '1')
			{
				p_graph->matrix[i][j] = 1;
				p_graph->edgeNum++;
			}

		}
		while ((ch = fgetc(fp)) != '\n' && ch != EOF);
	}

	if (fclose(fp) != 0)
	{
		printf("�ر��ļ�ʧ�� path == %s\n", path);
		exit(1);
	}



	return p_graph;
}


void destroy_graph(PtrGraph p_graph)
{
	if(p_graph)
		free(p_graph);
}