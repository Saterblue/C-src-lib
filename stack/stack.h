	
#include <stdlib.h>

typedef struct stack_protype{
	int length;
	int max;
	void** object;
}STACK;

STACK* createStack();
void deleteStack(STACK* del);
void push(STACK* st,void* obj);
void* pop(STACK* st);
