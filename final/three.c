#include "final.h"

#include <stdio.h>

int depth_of_value(int value, BinaryTree *tree) {
  // Your code here!
  // Remember -- return 0 if the value is found at the root node, and -1 if the
  // value is not found in the tree at all.
  // You don't have to handle trees where the same value occurs more than once,
  // but if it does happen, you ought to return the shallowest depth of that
  // value.
  // Also remember that this is just a binary tree, not a binary *search* tree.
  if(tree == NULL){
	  return -1;
  }
  if(tree->val == value){
	 return 0;
  }
  int depth = -1;
  if(tree->val != value){
	  if(tree->left != NULL){
		  int depth = depth_of_value(value, tree->left);
		  if(depth >= 0){
		     return depth + 1;
		  }
	  }
	  if(tree->right != NULL){
		 int depth = depth_of_value(value, tree->right);
	 	 if (depth >= 0){
		     return depth + 1;
		  }
 	}
  }
  return depth;
}
