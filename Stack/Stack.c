#include "Stack.h"
#include <stdlib.h>

Stack* s_generate(int maxSize){
	Stack* stack = malloc(sizeof(Stack) + sizeof(S_Frame[maxSize]));

	stack->maxSize = maxSize;
	stack->size = 0;
	stack->leadingNode = &stack->frames[0];
	return stack;
}

void s_push(Stack* stack, char* data) {
	if(s_capacity(stack) == 0){
		return;
	}
	S_Frame* frame = malloc(sizeof(S_Frame));
	frame->index = stack->size;
	frame->value = data;

	stack->leadingNode = frame;
	stack->leadingNode++;
	stack->size++;
}

char* s_pop(Stack* stack) {
	if(stack->size == 0) {
		return NULL;
	}

	S_Frame* frame = stack->leadingNode;
	char* data = frame->value;
	stack->leadingNode--;
	stack->size--;
	free(frame);
	return data;
}

char* s_peek(Stack* stack){
	if(stack->size == 0){
		return NULL;
	}

	return stack->leadingNode->value;
}

int s_capacity(Stack* stack) {
	return (stack->maxSize - stack->size);
}