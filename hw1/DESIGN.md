# HW 1: Pass the Pigs

## Purpose

 The purpose of this assignment is to create a game where k number of players each get a turn to roll the die, called the "pig", and the player who rolls gets a number of points based on the result of their roll. For example, a player who rolls a razorback would earn 10 points, whereas a player who rolls a side earns 0 points. A player who rolls a side doesn't get any points and their turn also ends immediately. Each position has a different probability of being rolled. There is a 2/7 probability that rolls a die yields a side, 1/7 for a razorback, 1/7 chance for a trotter, 1/7 for a snouter, and 2/7 chance for a jowler. Each position represents a different position that "the pig" could land in. The order of players goes consectuively, from player 0 to player 1, and loops back to the beginning after the last player. The first player to reach 100 points wins and the game ends.

### Layout/Structure and Pseudocode

enumerations{List of positions} Position;
constant Position pig[7] = {
	list of positions		
}
 
main function(void){
	for (int i = 0; i < 3; i += 1){
	   print statement to set the seed
	   call srandom with seed to generate pseudorandom numbers
	   for (int i = 0; i < 7; i += 1){
	      print the generated numbers
           }
        }
        Set input to zero
	Receive user input to determine number of players

	If input is not between 2 and 10 inclusive:
	   print statement saying output is invalid and use default value for number of players
	Else:
	   Set user input as number of players

	Receive user input to determine random seed
	If input is invalid:
	   print statement saying output is invalid and use default value of seed
	   set random seed
	Else:
	   Set user input as seed
	
	Set each player's points to 0 in array
	While player's points < 100{
	   Print name of player currently rolling starting with player 0
           Roll the pig using previously generated pseudorandom numbers
	   If roll is razorback or trotter:
		add 10 points to player total
	   If roll is snouter:
		add 15 points to player total
	   If roll is jowler:
		add 5 points to player total
	   If roll is side:
		move to next player
	   If player has 100 points or more:
		print congratulatory message stating player won
		break
	}
}

This program is going to consist of a series of if-then statements within the main function that decide who the current player is, figures out the result of their roll, and then assigns points to that player based on their roll.

The beginning section of the code, before the main function, creates enumerations for the different positions of the pig so that they can be assigned to integer constants. This allows us to create an array consisting of the positions of the pig, which is important because it allows for randomized access to the different elements. This part was provided in the instructions for this assignment.

The next part consists of the actual main function. This function will hold the rest of the code for this assignment. The first part of this function uses a pseudo-random number generator to generate a random number for the position that the die returns. After that, the function allows for user input to determine the number of player, which stores the number if it is a valid input and returns a statement if the input is invalid. The next part sets each player's points to zero; this is where the points for each player will be stored and updated for the rest of the game.

Now, the game begins with player 0. This part of the code prints out which player is currently playing. Then, the pig is rolled and points are added to each player as they roll the die, unless the pig lands on one of its sides. This part checks to make sure that if a player rolls a zero and the pig lands on its side, their turn ends and the next player goes. This part also checks if the count has reached zero for any of the players, and if it does, then the game ends and the function prints a message congratulating the player who won. 
