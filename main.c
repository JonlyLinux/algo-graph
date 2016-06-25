
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "graph_present.h"
#include "graph_search.h"


int main(int argc, char *argv[])
{
	printf("%d, %s\n", argc, argv[0]);
	init_adjlist();
	graph_bfs(graph_adjlist, VERTEX_NUM, 1);
	graph_dfs(graph_adjlist, VERTEX_NUM, 1);

	return 0;
}
