#include "stack.h"

int InitStack(Stack* stack,int max) {
	stack->length=0;
	stack->maxLength = max;
	stack->head = (int*)malloc(sizeof(int*)*max);	
	if(stack->head == NULL )
		return STACK_INIT_FAIL;
	return 0;
}
	
int push(Stack* stack,void* obj) {		
	if( obj == null_ptr || obj == 0 || obj== NULL )
		return NULL_POINT;
	if( stack->head == NULL )
		return STACK_NOT_INIT;				
	if( stack->length ==  stack->maxLength )
		return STACK_IS_FULL;
	*(int*)((int) stack->head + sizeof(int*)*stack->length) = (int)obj;
	 stack->length++;
	return 0;
}

void* pop(Stack *stack) {
	if( stack->head == NULL )
		return NULL;
	if(  stack->length == 0 )
		return NULL;
	int address = (int)stack->head + sizeof(int*)*(stack->length - 1);
	int* point = (int*)*(int*)(address);
	stack->length--;
	return (void*)point;
}

int freeStack(Stack *stack) {
	if( stack->head == NULL )
		return 0;
	free(stack->head);
	stack->head=NULL;
	return 0;
}
