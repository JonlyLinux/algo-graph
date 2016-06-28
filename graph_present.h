#ifndef __GRAPH_PRESENT_H__
#define __GRAPH_PRESENT_H__
#include "list.h"

#define VERTEX_NUM 8

extern unsigned char graph_data[VERTEX_NUM];

typedef enum vertex_color_e {
	WHITE,
	GRAY,
	BLACK,
} vertex_color_t;

typedef struct vertex_s {
	unsigned int index;
	vertex_color_t color;
	unsigned int dist;
	/* vertex data */
	unsigned int id;
	int data;

	struct list_head entry;
} vertex_t;

extern vertex_t graph_vertexs[VERTEX_NUM];
extern unsigned int graph_vertexs_num;
extern void init_vertexs(void);

extern unsigned int  graph_adjmtrx[VERTEX_NUM][VERTEX_NUM];

typedef struct adjnode_s {
	int index;
	struct list_head entry;
} adjnode_t;

extern struct list_head graph_adjlist[VERTEX_NUM];

extern void init_adjlist(void);
#endif
