#include "graph_present.h"
#include <stdlib.h>


unsigned char graph_data[VERTEX_NUM] = {'r', 's', 't', 'u', 'v', 'w', 'x', 'y'};


vertex_t graph_vertexs[VERTEX_NUM];
unsigned int graph_vertexs_num;

unsigned int  graph_adjmtrx[VERTEX_NUM][VERTEX_NUM] = {
//	 r  s  t  u  v  w  x  y
	{0, 1, 0, 0, 1, 0, 0, 0}, //r
	{1, 0, 0, 0, 0, 1, 0, 0}, //s
	{0, 0, 0, 1, 0, 1, 1, 0}, //t
	{0, 0, 1, 0, 0, 0, 1, 1}, //u
	{1, 0, 0, 0, 0, 0, 0, 0}, //v
	{0, 1, 1, 0, 0, 0, 1, 0}, //w
	{0, 0, 1, 1, 0, 1, 0, 1}, //x
	{0, 0, 0, 1, 0, 0, 1, 0}, //y
};
/*
0: 4 1 
1: 5 0 
2: 6 5 3 
3: 7 6 2 
4: 0 
5: 6 2 1 
6: 7 5 3 2 
7: 6 3 
*/

struct list_head graph_adjlist[VERTEX_NUM];

void init_vertexs(void)
{
	unsigned int i = 0;

	for (i = 0; i < (int)(sizeof(graph_data)/sizeof(graph_data[0])); i++) {
		graph_vertexs[i].index = i;
		graph_vertexs[i].data = graph_data[i];
		graph_vertexs_num ++;
	}

#if 1
	for (i = 0; i < graph_vertexs_num; i++) {
		printf("vertex (%d, %c)\n", graph_vertexs[i].index, graph_vertexs[i].data);
	}
#endif
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
				list_add_tail(&new_adjnode->entry, &graph_adjlist[i]);
			}
		}
	}

#if 1
	struct list_head *curr = NULL;
	adjnode_t *vertex = NULL;
	for (i = 0; i < VERTEX_NUM; i++) {
		if (!list_empty(&graph_adjlist[i])) {
			printf("%d: ", i);
			list_for_each(curr, &graph_adjlist[i]) {
				vertex = list_entry(curr, adjnode_t, entry);
				printf("%d ", vertex->index);
			}
			printf("\n");
		}
	}

#endif

	return ;
}

