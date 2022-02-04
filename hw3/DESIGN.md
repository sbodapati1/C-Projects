# Homework 3: Dynamic Memory, Linked Lists, and Stacks

## Purpose

The purpose of this assignment is to create a stack-based calculator that reads "numbers and operations from a text file to perform some computation" and we will be using stack data structures to complete this task.

### Layout/Structure and Pseudocode

The structure of this code was given already. The functions were given and we follow and finish the given functions. The pseudocode that I added was minimal because I simply changed the commented description into pseudocoe.

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
  Add a new node to front of stack
  if memory allocation fails:
	return False;
}

// Pop the stack and put the result into the output pointer.
// return false if the stack is NULL or if it is empty.
bool stack_pop(Stack *s, CalculatorItem *output) {
  // your code here
  output pointer = stack popped
  if stack is NULL or empty:
	return false;
}

// Returns true if the specified stack is empty.
bool stack_empty(Stack *s) {
  if stack is empty:
      return true;
}

// Free all of the memory used by this stack, including its linked list.
// When you are done, set the pointer to NULL.
void stack_delete(Stack **s) {
  // your code here
  free memory
  set pointer to NULL
}

// Returns true if we were able to successfully perform the computation step,
// and false if there was an error of some kind.
bool stack_compute_step(Stack *s, CalculatorItem item) {
  // your code here
  if computation was successful:
        return true;
  if there was an error:
	return false;
}
