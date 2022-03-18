#include "final.h"

#include <stdio.h>
#include <stdlib.h>

LLint *push(int value, LLint *node) {
  LLint *out = calloc(1, sizeof(LLint));
  out->val = value;
  out->next = node;

  return out;
}

int main(void) {
  LLint *list = NULL;
  LLint *list2 = NULL;
  int biggest = 0;
  int nextbiggest = 0;

  // make a list with some numbers in it.
  list = push(10, list);
  list = push(1, list);
  list = push(15, list);
  list = push(-15, list);

  find_two_biggest(list, &biggest, &nextbiggest);
  printf("biggest should be 15, got: %d\n", biggest);
  printf("nextbiggest should be 10, got: %d\n", nextbiggest);
  //return 0;

  list2 = push(10, list2);
  list2 = push(1, list2);
  list2 = push(20, list2);
  list2 = push(20, list2);
  find_two_biggest(list2, &biggest, &nextbiggest);
  printf("biggest should be 20, got: %d\n", biggest);
  printf("nextbiggest should be 20, got: %d\n", nextbiggest);
  return 0;

}
