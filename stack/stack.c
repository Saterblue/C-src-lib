#include "stack.h"

STACK* createStack(){
	STACK *st = malloc(sizeof(STACK));
	st->length = 0;
	st->max = 128;
	st->object = calloc( st->max, sizeof(void*));
	return st;
}

void deleteStack(STACK* del) {
	if(del == NULL)
		return ;
	if( del->length != 0 ) {
		return ;
	}
	free(del->object);
	free(del);
	del = NULL;
}

void push(STACK* st,void* obj){
	if(st == NULL) 
		return;
	if(obj == NULL)
		return;
	if(st->length == st->max)
		return;
	*(st->object) = obj ;
	st->object++;
	st->length++; 
}

void* pop(STACK* st) {
	if(st == NULL)
		return;
	if(st->length == 0)
		return;		
	st->object--;
	st->length--;
	return *(st->object);
}
