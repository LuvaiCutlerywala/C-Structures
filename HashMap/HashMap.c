#include "HashMap.h"
#include <stdlib.h>

HashMap *h_generateHashMap(const int maxSize) {
  HashMap *map = malloc(sizeof(HashMap) + sizeof(Element[maxSize]));
  map->size = 0;
  map->maxSize = maxSize;

  return map;
}

void h_add(HashMap *map, char *key, char *value) {
  if (h_capacity(map) == 0) {
    return;
  }

  Element *element = malloc(sizeof(Element));
  element->key = h_hash(key);
  element->value = value;

  Element *arr = &map->elements[0];
  while (arr != NULL) {
    arr++;
  }

  arr = element;
  map->size++;
}

void h_remove(HashMap *map, char *key) {
  unsigned long hashedKey = h_hash(key);
  Element *arr;
  for (int i = 0; i < map->size; ++i) {
    arr = &map->elements[i];
    if (arr == NULL || arr->key != hashedKey) {
      continue;
    }
    break;
  }

  free(arr);
  map->size--;
}

char *h_get(HashMap *map, char *key) {}

unsigned long h_hash(char* content){
	unsigned long hash = 4888;
	int c;
	
	while(0 != (c = *content++)) hash = ((hash << 5) + hash) + c;
	
	return hash;
}

int h_capacity(HashMap *map) { return (map->maxSize - map->size); }