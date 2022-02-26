# HW 6: Strings, Searching, Pointers!

## Purpose

The purpose of this assignment is to implement a solver for Wordle, which we created last week. Using the provided heuristic, we start off with the word "irate" and then move on to other words based on the feedback from the user. 'x' replaces letters that aren't in the word at all, 'y' replaces letters that are in the word but not in the correct place, and 'g' replaces letters that are in the word and in the correct spot. With every guess and every input from the user, the program cuts down the vocabulary list to include only words that fit our requirement. For example, if a guess is "irate", which is the first word that we guessed based on our heuristic, and the user gives us "xgxyg", we know that 'r' and 'e' are in the correct place, 't' is in the word but not in the right spot, and 'i' and 'a' aren't in the word at all. We then cut out all the words in our vocabulary list that don't have 'r' and 'e' in the given spots, that either don't have 't' or have 't' in the given spot, and the words that have 'i' and 'a'. We do this because we know that these words cannot be the word we are trying to guess.

### Layout/Structure

The function names for this program were given and we need to fill them in. The pseudocode along with the explanations for these functions can be seen below. The code for the functions that were already filled out was removed because it isn't pseudocode and isn't a part of my plans.

#### Pseudocode


// This function loops over the vocabulary and returns the number of words in which that particular letter occurs. So if there are 15 words containing the letter 'x' for the particular vocabulary, then this function will return 15.

```

int score_letter(char letter, char **vocabulary, size_t num_words) {

  initialize count;
  for loop to iterate through vocabulary{
	  if word in vocab equals letter{
		  increase count by one;
	  }
  }
  return count;
}

```

// This function calculates the score for a given word, where the letter_scores array has already been filled out and has a length of 26. Slot 0 contains the score for 'a', and slot 25 contains the score for 'z'. The score for a word is the sum of all of the letter scores for unique letters in the word. So if the letter 'e' occurs three times, it only contributes to the score once.

```

int score_word(char *word, int *letter_scores) {

  initialize count;
  create array of letters with a length of 5;
  for loop to iterate through the letters of the word{
	  letter = letter in word at position i;
	  put letter into array of letters at the position i;
  }
  for loop to iterate through letters{
	  another for loop to iterate through letters{
	  	check if letter at position i and position j are the same{
			for loop to iterate through letters{
				remove letter;
			}
			decrease size of letters;
			decrease j;
		}
		}
  }
	  for loop to iterate through letters again{
		   if letter in letters does not equal letter in word{
			for loop to loop through letter_scores{
				if letter in letter scores equals letter in word{
					increase count with the score of that letter;
				}	
			}
	  }
  }
  return count;
  }

```

// This functions returns the optimum guess, based on our heuristic. This one was given and doesn't need to be changed.

```
char *get_guess(char **vocabulary, size_t num_words) {
	
	GIVEN FUNCTION;

}

```

// This function filters down the vocabulary based on the knowledge that the specified letter *does not occur* in the secret word. So for any of the words in the vocabulary that do contain that letter, their pointers are freed and set to NULL. It returns the number of words that have been filtered from the vocabulary.

```
	
size_t filter_vocabulary_gray(char letter, char **vocabulary,
                              size_t num_words) {

  for loop to iterate through vocabulary{
          for loop to iterate through word{
		  if word in vocabulary is not NULL{
                  	if letter in word equals letter{
				free word;
                         	word = NULL;
                          	decrease num_words by 1;
			}
                  }
          }
  }
  return num_words;

}

```

// This function filters down the vocabulary based on the knowledge that the specified letter occurs in the word, but not at this particular position. It removes any words that either don't contain the letter at all, or do contain it, but not at the specified position. It returns the number of words that have been filtered from the vocabulary.

```

size_t filter_vocabulary_yellow(char letter, int position, char **vocabulary,
                                size_t num_words) {

    for loop to iterate through vocabulary{
          for loop{
                  if letter in position doesn't equal letter{
			  free word;
                          word = NULL;
                          decrease num_words by 1;
                  }
                  if letter in word equals letter{
                  	  free word;
                          word = NULL;
                          decrease num_words by 1;
                  }
          }
  }
  return num_words;

}

```

// This function filters down the vocabulary based on the knowledge that the specified letter *definitely* occurs as the specified position. So remove any word that does not contain, for the specified position, the specified letter. It returns the number of words that have been filtered from the vocabulary.

```

size_t filter_vocabulary_green(char letter, int position, char **vocabulary,
                               size_t num_words) {

  for loop to iterate through vocabulary{
	  if letter in the given position in word is not the letter{
		  word = NULL;
		  decrease num_words by 1; 
	  }
  }      				
  return num_words;

}

```

// This function frees each of the strings in the vocabulary, as well as the pointer vocabulary (which points to an array of char *).

```

void free_vocabulary(char **vocabulary, size_t num_words) {
	GIVEN FUNCTION
  }
