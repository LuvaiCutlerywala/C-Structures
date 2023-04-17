#pragma once

#ifndef QUEUE_H
#define QUEUE_H

// Internal representation of the data.
typedef struct Q_Node Q_Node;
struct Q_Node {
  char *value;
};

// The actual data structure is composed of Nodes, which each hold the actual
// data.
typedef struct Queue Queue;
struct Queue {
  int size;
  int maxSize;
  Q_Node *front;
  Q_Node *rear;
  Q_Node nodes[];
};

char *q_pop(Queue *);
void q_append(Queue *, char *);
char *q_peek(Queue *);
Queue *q_generate(int);
int q_capacity(Queue *queue);

#endif