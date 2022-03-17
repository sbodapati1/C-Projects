#include "review.h"

#include <stdio.h>
#include <stdlib.h>

// Helper for Problem Three Tests

void print_tnode(tnode* node){
	printf("%s: %d\n", node->word, node->count);
}

int main(void) {
  // Your code for testing your functions in review.c goes here.

  // Test Cases for Problem One
  printf("Problem 1 Tests\n");  
  int a = 987987;
  int b = 87;
  int sum = 0;
  int difference = 0;
  sum_and_difference(a, b, &sum, &difference);
  printf("Sum: %d\n", sum);
  printf("Difference: %d\n", difference);

  // Test Cases for Problem Two
  printf("\nProblem 2 Tests (Recursive)\n");
  struct LLint* root = malloc(sizeof(struct LLint));
  struct LLint* new = malloc(sizeof(struct LLint));
  struct LLint* new1 = malloc(sizeof(struct LLint));
  struct LLint* new2 = malloc(sizeof(struct LLint));
  struct LLint* new3 = malloc(sizeof(struct LLint));
  root->val = 1;
  root->next = new;
  new->val = 4;
  new->next = new1;
  new1->val = 8;
  new1->next = new2;
  new2->val = 13;
  new2->next = new3;
  new3->val = 17;
  new3->next = NULL;
  int length = ll_length(root);
  printf("Length of linked list: %d\n", length);

  printf("\nProblem 2 Tests (Iterative)\n");
  int it_length = ll_length_iterative(root);
  printf("Length of linked list (Iteratively): %d\n", it_length);
  free(root);
  root = NULL;
  free(new);
  new = NULL;
  free(new1);
  new1 = NULL;
  free(new2);
  new2 = NULL;
  free(new3);
  new3 = NULL;

  // Test Cases for Problem Three
  printf("\nProblem 3 Tests\n");
  double array[] = {0};
  int i;
  for(i = 0; i < 8; i++){
	  array[i] = i + 1;
  }
  for(i = 0; i < 8; i++){
	  printf("array: %f \n", array[i]);
  }
  reverse_doubles_with_stack(array, i);
  for(i=0; i < 8; i++){
  	printf("reversed: %f \n", array[i]);
  }

  // Test Cases for Problem Four
  printf("\nProblem 4 Tests\n");
  tnode* counts = NULL;
  tnode* counts1 = NULL;
  tnode* counts2 = NULL;
  tnode* counts3 = NULL;
  counts = word_observe("dog", counts);
  counts1 = word_observe("cat", counts1);
  counts2 = word_observe("dog", counts2);
  counts3 = word_observe("elephant", counts3);
  int total_count = word_count("dog", counts);
  print_tnode(counts);
  print_tnode(counts1);
  print_tnode(counts2);
  print_tnode(counts3);
  printf("Total count: %d\n", total_count);
  delete_tree(counts);
  delete_tree(counts1);
  delete_tree(counts2);
  delete_tree(counts3);
}
