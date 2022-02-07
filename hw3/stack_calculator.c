#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "stack_calculator.h"

int top;

// Allocate a new Stack struct and return a pointer to it.
Stack *stack_create(void) {
  // this one is complete, no need to change it!
  Stack *out;
  out = (Stack *)calloc(1, sizeof(Stack));
  return out;
}

// Add a new node at the front of the stack. Return false if we are unable to do
// so (eg, if memory allocation fails).
bool stack_push(Stack *s, CalculatorItem item) {
  // your code here
  // Used code from demos given
  Node *front = (Node *)calloc(1, sizeof(Node));
  if (front == NULL) {
    printf("Memory Allocation Failed\n");
    return false;
  }
  front->item = item;
  front->next = s->top;
  s->top = front;
  return true;

}
// Pop the stack and put the result into the output pointer.
// return false if the stack is NULL or if it is empty.
bool stack_pop(Stack *s, CalculatorItem *output) {
  // your code here
  // Used code from demos given
  if (s == NULL || s->top == NULL) {
    return false;
  }
  CalculatorItem result = s->top->item;
  *output = result;

  Node *delete_this = s->top;
  s->top = s->top->next;

  free(delete_this);
  return true;
}

// Returns true if the specified stack is empty.
bool stack_empty(Stack *s) {
  // your code here
  if(s->top == NULL){
  	return true;
	}
  else{
	return false;
  }
}

// Free all of the memory used by this stack, including its linked list.
// When you are done, set the pointer to NULL.
void stack_delete(Stack **s) {
  // your code here
  free(*s);
  *s = NULL;
}

// Returns true if we were able to successfully perform the computation step,
// and false if there was an error of some kind.
bool stack_compute_step(Stack *s, CalculatorItem item) {
  // your code here
  if(item.type ==  NUMBER){
	stack_push(s, item);
	return true;
  }
  if(item.type ==  ADD){
	CalculatorItem result;
	stack_pop(s, &item);
	stack_pop(s, &item);
	result.value = item.value + item.value;
	stack_push(s, result);
	return true;
  }
  if(item.type ==  SUBTRACT){
	CalculatorItem result;
        float val1 = stack_pop(s, &item);
        float val2 = stack_pop(s, &item);
        result.value = val1 - val2;
	stack_push(s, result);
	return true;
  }
  if(item.type ==  MULTIPLY){
	CalculatorItem result;
        float val1 = stack_pop(s, &item);
        float val2 = stack_pop(s, &item);
        result.value = val1 * val2;
	stack_push(s, result);
	return true;
  }
  if(item.type ==  DIVIDE){
	CalculatorItem result;
        float val1 = stack_pop(s, &item);
        float val2 = stack_pop(s, &item);
	if(val2 != 0){
		result.value = val1/val2;
		stack_push(s, result);
		return true;
	}
	else{
		return false;
	}
  }
  else{
       return false;
  }
}
