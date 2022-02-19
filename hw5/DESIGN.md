# HW 5: Strings, Searching, Words

## Purpose

The purpose of this assignment is to recreate the game Wordle and implement it as a text-based game. This will take the user/player's input and will check whether or not their input matches out 5-letter English word. For every guess, the input is compared to the actual word, and then we return a response that shows the letters the players got correct in the places that the letters go. Some of the functions are already given to us, but some need to be filled in.

### Layout/Structure

Some functions were provided, but we have to finish most of them ourselves. The first function we need to finish is score_guess. This function will return True if the guess is a match and False if it doesn't, because its type is bool. It will also fill the result in with x if the letter in the guess does not appear in the word, y if the letter is correct but not in the right spot, and g if the letter is correct and in the correct spot. The valid_guess function is also a bool function that returns True if the guess is one of the strings given in vocabulary.txt and False if it isn't. Load_vocabulary returns a word from the specified file and sets the number of words read. We will need to allocate memory in this function to hold the pointers and this memory must be freed later. The last function we need to finish is free_vocabulary, which frees all of the strings in the vocabulary and the pointer vocabulary as well.
