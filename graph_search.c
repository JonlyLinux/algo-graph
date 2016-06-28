#include "graph_search.h"
#include "list.h"
#include <stdlib.h>
#include <stdio.h>

void graph_bfs(struct list_head *graph_adjlist, int num, int index)
{
	struct list_head queue;
	INIT_LIST_HEAD(&queue);

	int i = 0;
	for (; i < VERTEX_NUM; i++) {
		graph_vertexs[i].color = WHITE;
		graph_vertexs[i].dist = -1;
	}

	int dist = 0;
	graph_vertexs[index].dist = dist;
	graph_vertexs[index].color = GRAY;
	
	struct list_head *curr = NULL;
	struct list_head *adjnode = NULL;
	vertex_t *vertex = NULL;
	list_add_tail(&graph_vertexs[index].entry, &queue);
	while (!list_empty(&queue)) {
		curr = list_get_first(&queue);	
		vertex = list_entry(curr, vertex_t, entry);
		vertex->color = BLACK;
		printf("visit: %d, %c, %d\n", 
				vertex->index, 
				graph_vertexs[vertex->index].data,
				graph_vertexs[vertex->index].dist);
		list_del(curr);

		list_for_each(adjnode, &graph_adjlist[vertex->index]) {
			adjnode_t *tmp = list_entry(adjnode, adjnode_t, entry);
			if (graph_vertexs[tmp->index].color == WHITE) {
				graph_vertexs[tmp->index].dist = vertex->dist + 1;	
				graph_vertexs[tmp->index].color = GRAY;
				list_add_tail(&graph_vertexs[tmp->index].entry, &queue);
				//printf("add: %d	", tmp->index);
			}
			//printf("\n");
		}
	}

	return ;
}

void graph_dfs(struct list_head *graph_adjlist, int num, int index)
{
	struct list_head stack;	
	INIT_LIST_HEAD(&stack);

	int i = 0;
	for (i = 0; i < VERTEX_NUM; i++) {
		graph_vertexs[i].color = WHITE;
	}

	graph_vertexs[index].color = GRAY;
	list_add(&graph_vertexs[index].entry, &stack);
	while (!list_empty(&stack)) {
		struct list_head * stack_entry = list_get_first(&stack);
		vertex_t *vertex = list_entry(stack_entry, vertex_t, entry);

		struct list_head * adjnode_entry = NULL;
		adjnode_t *adjnode = NULL;
		int terminal_node = 1;
		list_for_each(adjnode_entry, &graph_adjlist[vertex->index]) {
			adjnode = list_entry(adjnode_entry, adjnode_t, entry);
			if (graph_vertexs[adjnode->index].color == WHITE) {
				graph_vertexs[adjnode->index].color = GRAY;
				list_add(&graph_vertexs[adjnode->index].entry, &stack);
				terminal_node = 0;
			}
		}
		
		if (terminal_node) {
			vertex->color = BLACK;
			list_del(stack_entry);
			printf("dfs visit: %d, %c, %d\n", 
				vertex->index, 
				graph_vertexs[vertex->index].data,
				graph_vertexs[vertex->index].dist);
		}
	}

	return ;
}

