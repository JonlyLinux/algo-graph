#ifndef __GRAPH_SEARCH_H__
#define __GRAPH_SEARCH_H__

#include "list.h"
#include "graph_present.h"

void graph_bfs(struct list_head *graph_adjlist, int num, int index);
void graph_dfs(struct list_head *graph_adjlist, int num, int index);

#endif
