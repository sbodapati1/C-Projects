#include <stdio.h>
#include <stdlib.h>
#include "names.h"
#include <limits.h>
#define SEED 2022

int player_score;
const char* player1;
char roll;

typedef enum { SIDE, RAZORBACK, TROTTER, SNOUTER, JOWLER } Position;
const Position pig[8] = {
        SIDE,
        SIDE,
        RAZORBACK,
        TROTTER,
        SNOUTER,
        JOWLER,
        JOWLER,
};

int main(void){

        for(int i = 0; i < 1; i += 1){
          puts("Set the random seed.");
          srandom(SEED);
          for (int i = 0; i < 5; i += 1){
              printf(" - generated %lu\n", random());}
        }

        int input = 0;
        printf("Enter number of players: ");
        scanf("%d", &input);
        if((input < 2) || (input > 10)){
                fprintf(stderr, "Invalid number of players. Using 2 instead.\n");
                input = 2;}
        //else{input = input;}

        int seed = 0;
        printf("Enter random seed: ");
        scanf("%d", &seed);
        if ((seed > INT_MAX) || (seed < 0)){
            fprintf(stderr, "Invalid random seed. Using 2022 instead.\n");
            seed = SEED;}
      
        printf("Number of players is %d. \n", input);
        printf("Seed is %d. \n", seed);
        srandom(SEED);
        int i = 0;

        player_score = 0;
        player1 = names[i];
        while(player_score <= 100){
          printf("%s rolls the pig ... ", player1);
          int roll = random() % 7;
          if((roll == RAZORBACK) || (roll == TROTTER)){
                printf("pig lands upright or on back \n");
                player_score += 10;
                printf("Player Score is %d \n", player_score);
                continue;
          }
          if(roll == SNOUTER){
                printf("pig lands on snout \n");
                player_score += 15;
                printf("Player Score is %d \n", player_score);
                continue;
          }
          if(roll == JOWLER){
                printf("pig lands on ear \n");
                player_score += 5;
                printf("Player Score is %d \n", player_score);
                continue;
          }
          else{
              printf("pig lands on side \n");
              player1 = names[i+1];
              continue;
          }
        }  
      printf("Congratulations! %s is the winner! \n", player1);   
}

