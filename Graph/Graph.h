#pragma once

#include "../utils.h"
#include <stdlib.h>

#ifndef GRAPH_H
#define GRAPH_H

/*
	Each graph node has an ID, which can be used to access the value. 
 	When querying a graph, the ID has to be known. 
	*/
typedef struct G_Node G_Node;
struct G_Node {
	unsigned int id;
	char* value;
	G_Node connections[];
};

G_Node* g_generateNode(char* , const unsigned int, G_Node* , const int);

typedef struct Graph Graph;
struct Graph {
	int size;
	int maxSize;
	G_Node* start;
};

Graph* g_generate(const int);
void g_add(const unsigned int, )

#endif