#include "final.h"

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

size_t word_count(char *text) {
  // Your code here!
  // Count up all the words that occur in the given string. A new word starts
  // when you see a letter a-z or A-Z.
  if(text == NULL){
	return 0;
  }
  size_t num_words = 0;
  bool isletter = false;
  for(int i = 0; text[i]!='\0'; i++){
	if((text[i] <= 'z' && text [i] >= 'a') || (text[i] >= 'A' && text[i] <= 'Z')){
			isletter = true;
	  }
	else if((!(text[i] <= 'z' && text [i] >= 'a') || !(text[i] >= 'A' && text[i] <= 'Z')) && (isletter == true)){
	  		num_words += 1;
	  		isletter = false;
	}
  }
	if(isletter == true){
	       num_words += 1;	
	}
  return num_words;
}
