#ifndef __GRAPH_PRESENT_H__
#define __GRAPH_PRESENT_H__
#include "list.h"

#define VERTEX_NUM 8

unsigned char graph_data[VERTEX_NUM] = {'r', 's', 't', 'u', 'v', 'w', 'x', 'y'};

typedef enum vertex_color_e {
	WHITE,
	GRAY,
	BLACK,
} vertex_color_t;

typedef struct vertex_s {
	int index;
	vertex_color_t color;
	/* vertex data */
	int id;
	int data;
} vertex_t;

vertex_t graph_vertexs[VERTEX_NUM];
unsigned int graph_vertexs_num;
extern void init_vertexs(void);

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

typedef struct adjnode_s {
	int index;
	struct list_head entry;
} adjnode_t;

struct list_head graph_adjlist[VERTEX_NUM];

void init_adjlist(void);
#endif
