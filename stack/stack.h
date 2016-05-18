	
#include <stdlib.h>

#define NULL_POINT		100
#define STACK_IS_FULL		101
#define STACK_NOT_EMPTY		102

typedef struct stack_protype{
	int length;
	int max;
	void** object;
}STACK;

STACK* createStack();
int deleteStack(STACK* del);
int push(STACK* st,void* obj);
void* pop(STACK* st);
