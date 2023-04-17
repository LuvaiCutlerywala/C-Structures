#pragma once

#ifndef STACK_H
#define STACK_H

typedef struct S_Frame S_Frame;

struct S_Frame {
  int index;
  char *value;
};

typedef struct Stack Stack;

struct Stack {
  int size;
  int maxSize;
  S_Frame *leadingNode;
  S_Frame frames[];
};

Stack *s_generate(int);
void s_push(Stack *, char *);
char *s_pop(Stack *);
char *s_peek(Stack *);
int s_capacity(Stack *);

#endif