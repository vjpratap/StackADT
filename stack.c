#include <stdlib.h>
#include "expr_assert.h"
#include "stack.h"


Stack createStack(void){
	LinkedList *list = calloc(1, sizeof(LinkedList));
	Stack newStack;// = {list, &list->tail};
	newStack.list = list;
	newStack.top = &list->tail;
	return newStack;
};

int push(Stack *newStack, void *data){
	Node * newNode = create_node(data);
	add_to_list(newStack->list, newNode);
	newStack->top = newNode;
	return newStack->list->count;
}

void * pop(Stack *newStack){
	return deleteElementAt(newStack->list, newStack->list->count - 1);
}