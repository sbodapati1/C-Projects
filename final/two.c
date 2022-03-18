#include "final.h"

#include <stdio.h>

void find_two_biggest(LLint *linkedlist, int *biggest, int *nextbiggest) {
  // Your code here!
  int current;
  do{
	  current = linkedlist->val;
	  if(linkedlist->val == *biggest){
                  *nextbiggest = *biggest;
          }
	  else if(linkedlist->val >= *biggest){
		  *biggest = current;
	  }
	  else if(current < *biggest && current > *nextbiggest){
		  *nextbiggest = linkedlist->val;
	  }
	  linkedlist = linkedlist->next;
  }while(linkedlist != NULL);
}
