#pragma once

#include "../utils.h"

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

// Internal representation of data.
typedef struct L_Node L_Node;
struct L_Node {
  char *value;
  L_Node *next;
  L_Node *prev;
};

// The actual data structure is composed of nodes, each which is aware of the
// previous and next node.
typedef struct LinkedList LinkedList;
struct LinkedList {
  int size;
  int maxSize;
  L_Node *start;
  L_Node *end;
};

// The methods defined on a LinkedList.
char *l_get(LinkedList *, const int);
void l_add(LinkedList *, char *string);
void l_remove(LinkedList *, const int);
LinkedList *l_generate(const int);
int l_capacity(LinkedList *);

#endif