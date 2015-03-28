#include "../LinkedListADT/linkedList.h"

typedef struct stack Stack;

struct stack{
	nodePtr* top;
	LinkedList* list;
};

Stack createStack(void);
int push(Stack *, void *);
void * pop(Stack *);
void * lifo(Stack *);
int giveIndex(Stack *, void *);