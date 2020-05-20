/*
* Just a simple stack data structure for integer and double data types. Can be easily modified for more data types.
* Used by calling 'DATA TYPE'_'DATA STRUCTURE'. For example, a stack for integers is an INT_STACK. The double version is DOUBLE_STACK.
* Naming style works with functions too. 'data type'_'data structure'_'action'. For example, int_stack_push() and double_stack_pop().
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct INT_NODE{
	int value;
	struct INT_NODE* next;
}INT_NODE;

typedef struct INT_STACK{
	INT_NODE* next;
}INT_STACK;

typedef struct DOUBLE_NODE{
	int value;
	struct DOUBLE_NODE* next;
}DOUBLE_NODE;

typedef struct DOUBLE_STACK{
	DOUBLE_NODE* next;
}DOUBLE_STACK;

void int_stack_push(int value, INT_STACK* stack);
int int_stack_pop(INT_STACK* stack);
void double_stack_push(double value, DOUBLE_STACK* stack);
double double_stack_pop(DOUBLE_STACK* stack);

/*int main(){
	INT_STACK stack;
	stack.next = NULL;
	
	int k;
	for(int j = 0; j < 100; j++){
		for(int i = 0; i < 10000000; i++){
			int_stack_push(i, &stack);
		}

		for(int i = 0; i < 10000000; i++){
			//printf("%d\n", stack_pop(&stack));
			k = int_stack_pop(&stack);
		}
	}
	printf("No memory leak");
	return 0;
}*/


//Push to the stack. Provide an integer and stack as input to funtion. 
//Stack is asked for as a way to prevent global variables.
void int_stack_push(int value, INT_STACK* stack){
	INT_NODE* temp = (INT_NODE*)malloc(sizeof(INT_NODE));
	temp->value = value;
	//If there is nothing on the stack, do this.
	if(stack->next == NULL){
		temp->next = NULL;
		stack->next = temp;
	}else{ //Otherwise, do this.
		temp->next = stack->next;
		stack->next = temp;
	}
	return;
}


int int_stack_pop(INT_STACK* stack){
	int value;
	//Make sure there is something on the stack
	if(stack->next == NULL){
		//Return 0 so the program does not crash. Error message should bring awareness to mistake. 
		printf("Error: The stack is empty. Returning 0");
		return 0;
	}
	//Set value then remove the top of the stack
	value = stack->next->value;
	INT_NODE* temp = stack->next;
	stack->next = stack->next->next;
	free(temp); //No memory leaks here
	return value;
}

//Push to the stack. Provide a double and stack as input to funtion. 
//Stack is asked for as a way to prevent global variables.
void double_stack_push(double value, DOUBLE_STACK* stack){
	DOUBLE_NODE* temp = (DOUBLE_NODE*)malloc(sizeof(DOUBLE_NODE));
	temp->value = value;
	//If there is nothing on the stack, do this.
	if(stack->next == NULL){
		temp->next = NULL;
		stack->next = temp;
	}else{ //Otherwise, do this.
		temp->next = stack->next;
		stack->next = temp;
	}
	return;
}


double double_stack_pop(DOUBLE_STACK* stack){
	double value;
	//Make sure there is something on the stack
	if(stack->next == NULL){
		//Return 0.0 so the program does not crash. Error message should bring awareness to mistake. 
		printf("Error: The stack is empty. Returning 0");
		return 0.0;
	}
	//Set value then remove the top of the stack
	value = stack->next->value;
	DOUBLE_NODE* temp = stack->next;
	stack->next = stack->next->next;
	free(temp); //No memory leaks here
	return value;
}