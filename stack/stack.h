	
#include <stdlib.h>
	
#define NULL_POINT		-1
#define STACK_IS_FULL		-2
#define STACK_NOT_INIT 		-3
#define STACK_INIT_FAIL		-4
#define null_ptr 		NULL

typedef struct Stack_protype {
	int  length;
	int  maxLength;		
	int* head;	
}Stack;

int InitStack(Stack* stack,int max);
int push(Stack* stack,void* obj);
void* pop(Stack *stack);
int freeStack(Stack *stack);

