#include"matrix_udg.h"

int main()
{
	Graph* pG = create_example_graph();
	dfs_traverse(pG);
	bfs_traverse(pG);
	print_graph(pG);
	getchar();
	return 0;
}