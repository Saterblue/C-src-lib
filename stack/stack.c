#include "stack.h"

#define NULL_POINT		100
#define STACK_IS_FULL		101
#define STACK_NOT_EMPTY 	102

STACK* createStack(){
	STACK *st = malloc(sizeof(STACK));
	st->length = 0;
	st->max = 128;
	st->object = calloc( st->max, sizeof(void*));
	return st;
}

int deleteStack(STACK* del) {
	if(del == NULL)
		return NULL_POINT;
	if( del->length != 0 ) 
		return STACK_NOT_EMPTY;
	free(del->object);
	free(del);
	del = NULL;
	return 0;
}

int push(STACK* st,void* obj){
	if(st == NULL) 
		return NULL_POINT;
	if(obj == NULL)
		return NULL_POINT;
	if(st->length == st->max)
		return STACK_IS_FULL;
	*(st->object) = obj ;
	st->object++;
	st->length++; 
	return 0;
}

void* pop(STACK* st) {
	if(st == NULL)
		return NULL;
	if(st->length == 0)
		return NULL;		
	st->object--;
	st->length--;
	return *(st->object);
}
