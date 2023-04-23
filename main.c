#include "HashMap/HashMap.h"
#include "LinkedList/LinkedList.h"
#include "Queue/Queue.h"
#include "Stack/Stack.h"
#include "utils.h"
#include <stdio.h>
#include <stdlib.h>

void demoQueue();
void demoLinkedList();
void demoStacks();

int main() { 
  demoStacks();
  //demoLinkedList(); 
  //demoQueue();
  return 0;
}

void demoQueue() {
  char *strings[] = {"Apple",     "Banana", "Orange",    "Grapes",
                     "Jackfruit", "Cherry", "Pineapple", "Kiwi Fruit"};
  Queue *queue = q_generate(length(strings, char *));
  printf("Queue size: %d\n", queue->size);
  printf("Queue max size: %d\n", queue->maxSize);
  for (int i = 0; i < length(strings, char *); ++i) {
    printf("Appending %s to queue...\n", strings[i]);
    printf("Capacity remaining: %d\n", q_capacity(queue));
    q_append(queue, strings[i]);
  }

  printf("The top item in the queue is: %s\n", q_peek(queue));

  printf("Reading items from list...\n");
  for (int j = 0; j < queue->size; ++j) {
    printf("%s\n", q_pop(queue));
  }
}

void demoLinkedList() {
  char *strings[] = {"Apple",     "Banana", "Orange",    "Grapes",
                     "Jackfruit", "Cherry", "Pineapple", "Kiwi Fruit"};
  LinkedList *list = l_generate(length(strings, char *));
  printf("Linked List size: %d\n", list->size);
  printf("Linked List max size: %d\n", list->maxSize);
  for (int i = 0; i < length(strings, char *); ++i) {
    printf("Appending %s to queue...\n", strings[i]);
    l_add(list, strings[i]);
    printf("Capacity remaining: %d\n", l_capacity(list));
  }

  printf("List size: %d\n", list->size);

  printf("Reading items from list...\n");
  for (int j = 0; j < list->size; ++j) {
    printf("%s\n", l_get(list, j));
  }

  // Test out of bounds (will cause an exit)
  printf("Reading items out of bounds from list...\n");
  //printf(l_get(list, -1));

  printf("Removing items from list...\n");
  for (int j = list->size - 1; j >= 0; --j) {
    printf("Removing %s from list\n", l_get(list, j));
    l_remove(list, j);
    printf("Capacity remaining: %d\n", l_capacity(list));
  }

  printf("List size: %d\n", list->size);
}

void demoStacks() {
  char *strings[] = {"Apple",     "Banana", "Orange",    "Grapes",
                     "Jackfruit", "Cherry", "Pineapple", "Kiwi Fruit"};

  Stack *stack = s_generate(8);
  printf("Stack size: %d\n", stack->size);
  printf("Stack max size: %d\n", stack->maxSize);

  printf("Pushing items onto stack.\n");
  for(int i = 0; i < length(strings, char*); ++i){
    printf("Pushing %s onto stack.\n", strings[i]);
    s_push(stack, strings[i]);
    printf("Stack size: %d\n", stack->size);
    printf("Stack capacity remaining: %d\n", s_capacity(stack));
  }

  printf("Popping items from the stack...\n");
  for(int i = stack->size; i >= 0; i--){
    printf("Popping %s from the stack.", s_pop(stack));
    printf("Stack size: %d\n", stack->size);
    printf("Stack capacity remaining: %d\n", s_capacity(stack));
  }
}