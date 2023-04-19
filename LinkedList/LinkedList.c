#include "./LinkedList.h"

// Constructor function to allocate memory and set linked list pointers
LinkedList *l_generate(const int maxSize) {
  LinkedList *list = malloc(sizeof(LinkedList));
  list->maxSize = maxSize;
  list->size = 0;
  list->start = NULL;
  list->end = NULL;

  return list;
}

char *l_get(LinkedList *list, const int index) {
  // Early return for outside bounds
  printf("Getting list item");
  printf(list->size);
  if (index < 0 || index >= list->size) {
    printf("Index outside bounds of LinkedList");
    return NULL;
  }

  // Faster early return if getting last value
  if (index + 1 == list->size) {
    return list->end->value;
  }

  // Traverse linked list
  L_Node *curr = list->start;
  for (int i = 0; i < index; ++i) {
    curr = curr->next;
  }

  return curr->value;
}

void l_add(LinkedList *list, char *string) {
  L_Node *node = malloc(sizeof(L_Node));
  node->value = string;
  node->next = NULL;

  if (list->size == 0) {
    node->prev = NULL;
    list->start = node;
  } else {
    L_Node *last = list->end;
    last->next = node;
    node->prev = last;
  }

  list->end = node;
  list->size++;
}

void l_remove(LinkedList *list, const int index) {
  if (index < 0 || index >= list->size) {
    return;
  }

  L_Node *curr = list->start;
  for (int i = 0; i < index; ++i) {
    curr = curr->next;
  }

  L_Node *next = curr->next;
  L_Node *prev = curr->prev;

	if (list->size == 1) {
    list->end = NULL;
    list->start = NULL;
  } else if (curr == list->start) {
    next->prev = NULL;
    list->start = next;
  } else if (curr == list->end) {
    prev->next = NULL;
    list->end = prev;
  } else {
    next->prev = prev;
    prev->next = next;
  }

  list->size--;

  free(curr);
}

int l_capacity(LinkedList *list) { 
  return (list->maxSize - list->size); 
}