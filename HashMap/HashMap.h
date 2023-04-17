#pragma once

#ifndef HASHMAP_H
#define HASHMAP_H

typedef struct Element Element;
struct Element {
  unsigned long key;
  char *value;
};

typedef struct HashMap HashMap;
struct HashMap {
  int size;
  int maxSize;
  Element elements[];
};

HashMap *h_generateHashMap(const int);
void h_add(HashMap *, char *, char *);
void h_remove(HashMap *, char *);
char *h_get(HashMap *, char *);
unsigned long h_hash(char *);
int h_capacity(HashMap *);

#endif