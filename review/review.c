#include "review.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Functions for you to implement. Most of the work for this homework will be
// done in here, but you'll also need to make changes to review.h and yelling.c.

// Problem 1
void sum_and_difference(int a, int b, int *sum, int *difference) {
  //  Your code goes here!
  printf("a: %d\n", a);
  printf("b: %d\n", b);
  *sum = a + b;
  *difference = a - b;
}

// Problem 2

// This one ought to be recursive.
size_t ll_length(LLint *node){
  // change this, clearly
  if (node == NULL){
        return 0;
  }
  else{
    return 1 + ll_length(node->next);
  }
}  
	
// Do this one iteratively.
size_t ll_length_iterative(LLint *node) {
  // These are just default return values; they're for you to change.
  int total = 0;
  while(node != NULL){
	  total++;
	  node = node->next;
  }
  return total;
}

// Problem 3.

void reverse_doubles_with_stack(double *array, size_t array_len) {
  // This function will reverse the order of the array pointed to by *array.
  // Make sure to define your linked list data structure in review.h, and use
  // stack behavior (LIFO) to get the numbers in the reversed order.
  // There is a way to do this without a stack data structure, I know. But this
  // is for practice with data structures.
  LLdouble *root = NULL;
  LLdouble *node = NULL;
  LLdouble *other = NULL;
  int total = 0;
  do{
	  node = malloc(sizeof(LLdouble));
	  node->val = array[total];
	  node->next = NULL;
	  if(root == NULL){
		  root = node;
	  }
	  else{
		  other = root;
		  while(other->next != NULL){
			  other = other->next;
		  }
		  other->next = node;
	  }
	  total += 1;
  }while(total <= array_len);
  total = 0;
  while(root->next != NULL){
	  other = root;
	  while(other->next->next != NULL){
		  other = other->next;
	  }
	  array[total] = other->val;
	  other->next = NULL;
	  total += 1;
}
}
// Problem 4.

tnode *word_observe(char *word, tnode *node) {
  // This function returns a pointer to a tnode because you may have to allocate
  // a new one. You might take a NULL pointer to start with.
  // Also, this means that you can very cleanly do this with recursion.
  if (node == NULL){
	  tnode *output = calloc(1, sizeof(tnode));
	  output->word = strdup(word);
	  output->count = 1;
	  output->left = NULL;
	  output->right = NULL;
	  return output;
  }
  int comparison = strcmp(word, node->word);
  if(comparison == 0){
	  node->count += 1;
  }
  else if(comparison < 0){
	  node->left = word_observe(word, node->left);
  }
  else if(comparison > 0){
	  node->right = word_observe(word, node->right);
  }
  return node;
}

int word_count(char *word, tnode *node) {
  // Default return values; here for you to change.
  int count = 0;
  if(node == NULL){
	  count = 0;
  }
  if(node->left == NULL && node->right == NULL){
	  if (strcmp(node->word, word) != 0){
	  	count = 0;
	  }
  }
  if(strcmp(node->word, word) == 0){
	  if(node->right == NULL && node->left == NULL){
	  	count += 1;
	  }
	  if(node->right != NULL){
		  count += 1;
		  return word_count(word, node->right);
	  }
	  if(node->left != NULL){
	  	  count += 1;
		  return word_count(word, node->left);
          }
  }
  if(strcmp(node->word, word) < 0){
	  if (node->left != NULL){
	  	return word_count(word, node->left);
	  }
  }
  if(strcmp(node->word, word) > 0){
	  if(node->right != NULL){
	  	return word_count(word, node->right);
	  }
  }
  return count;
}

void delete_tree(tnode *node) {
  // Free the whole tree and all associated memory. This can be recursive or
  // not, your choice!
  if(node != NULL){
  	if(node->left != NULL){
  		delete_tree(node->left);
		free(node->left);
		node->left = NULL;
	  }
        if(node->right != NULL){
		  delete_tree(node->right);
		  free(node->right);
		  node->right = NULL;
	  }
	else{
	  	free(node);
	  	node = NULL;
	  }
}
}
