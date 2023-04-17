#include "./Queue.h"
#include <stdlib.h>
#include <string.h>

char *q_pop(Queue *queue) {
  if (q_capacity(queue) == queue->maxSize) {
    return NULL;
  }

  char *data = queue->front->value;
  queue->front++;
  return data;
}

void q_append(Queue *queue, char *string) {
  if (q_capacity(queue) == 0) {
    return;
  }
  Q_Node node;
  node.value = string;

  *(queue->rear) = node;
  queue->rear++;
  queue->size++;
}

char *q_peek(Queue *queue) {
  if (queue->size > 0) {
    return queue->nodes[0].value;
  }
  return NULL;
}

Queue *q_generate(int maxSize) {
  Queue *queue = malloc(sizeof(Queue) + sizeof(Q_Node[maxSize]));
  queue->maxSize = maxSize;
  queue->size = 0;
  queue->front = &queue->nodes[0];
  queue->rear = &queue->nodes[0];
  return queue;
}

int q_capacity(Queue *queue) {
  return (queue->maxSize - queue->size);
}