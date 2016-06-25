#include "graph_present.h"
#include <stdlib.h>

void init_vertexs(void)
{
	int i = 0;

	for (i = 0; i < (int)(sizeof(graph_data)/sizeof(graph_data[0])); i++) {
		graph_vertexs[i].index = i;
		graph_vertexs[i].data = graph_data[i];
		graph_vertexs_num ++;
	}
}

void init_adjlist(void)
{
	int i = 0;
	int j = 0;
	adjnode_t *new_adjnode = NULL;

	for (i = 0; i < VERTEX_NUM; i++) {
		INIT_LIST_HEAD(&graph_adjlist[i]);
	}
	
	for (i = 0; i < VERTEX_NUM; i++) {
		for (j = 0; j < VERTEX_NUM; j++) {
			if (graph_adjmtrx[i][j] > 0) {
				new_adjnode = calloc(1, sizeof(adjnode_t));
				new_adjnode->index = j;
				list_add(&new_adjnode->entry, &graph_adjlist[i]);
			}
		}
	}

	return ;
}

