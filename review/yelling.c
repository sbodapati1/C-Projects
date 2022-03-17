#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main(int argc, char **argv) {
  // You're going to have to use argc to decide whether to open up a file, or to
  // read from stdin.
  // If you haven't seen them before, you will likely want to use the functions
  // `fgetc()` and `fputc()`.
  char word[] = "";
  char letter;
  char letters;
  if(argc > 1){
          FILE *fp = fopen(*argv, "r");
	 	 letter = fgetc(fp);
	         letters = toupper(letter);
		 printf("%c", letters);
  	 	 fclose(fp);
  }
  if(argc <= 1){
	printf("Enter input: ");
	scanf("%s", word);
	char words[] = "";
	for(size_t t = 0; t < strlen(word); t++){
        	words[t] = word[t];
	}
	for(size_t j = 0; j < strlen(word); j++){
		  if(words[j] >= 'a' && words[j] <= 'z'){
		  	words[j] = toupper(words[j]);
		  }
	}
	printf("%s\n", words);
  }
  return 0;
}
