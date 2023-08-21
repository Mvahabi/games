#include "names.h"

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define SEED 2021

int main(void) {

    typedef enum { SIDE, RAZORBACK, TROTTER, SNOUTER, JOWLER } Position;
    const Position pig[7]
        = { SIDE, SIDE, RAZORBACK, TROTTER, SNOUTER, JOWLER, JOWLER }; // Enumerating the Positions
    int points[7] = { 0, 0, 10, 10, 15, 5,
        5 }; // an integer array for the amount of points per each 7 possible landing positions
    char *landing[7] // a string array for when it prints the position the pig lands on
        = { "on side", "on side", "on back", "upright", "on snout", "on ear", "on ear" };

    int num_players, i = 0; // initializing num players, initialized  index of every arrays to 0
    int seed; // initialized variable seed for the random sequence generator for srandom()

    /* for the next two steps the user is asked to input numers 
      of players and random number for srandom(); additionally
      it checks to see if there are erroneous user inputs
      and defaults them to 2 players and 2021 seed if any errors occur. */

    printf("How many players? ");
    scanf("%d", &num_players);

    if (num_players < 2 || num_players > 10) {
        fprintf(stderr, "Invalid number of players. Using 2 instead.\n");
        num_players = 2;
    }

    while (getchar() != '\n')
        ;

    printf("Random seed: ");
    scanf("%d", &seed);

    if (seed < 0 || seed > (uint32_t) UINT32_MAX) {
        fprintf(stderr, "Invalid random seed . Using 2021 instead .\n");
        seed = SEED;
    }
    srandom(seed); // sets srandom to user input for seed

    int random_num; // setting a variable for the dice roll
    int score[10] = {
        0
    }; // integer array, 10 elements initalized to 0, keeps track of points per person in names.h

    /*  this next sextion contains an infinite while loop:
        it prints out the name of the current player then it
        goes through a do-while loop: it rolls the die and uses
	that number to assign to the landing index in accordance 
	of the pig position index. It also adds the points of that
	certain position to the score array (the same index in the 
	names array. This keeps going until a user either rolls a
       	side or gets more than 100 points. If they roll a side and
	their score is less than 100 it moves on to the next player 
	(i+1).In addition, if it reaches the last person (i == num_players)
	and the game isn't over, it returns back to the first player (i = 0) */

    while (1) {
        printf("%s rolls the pig...", names[i]);
        do {
            random_num = random() % 7;
            printf(" pig lands %s", landing[random_num]);
            score[i] += points[random_num];
        } while (pig[random_num] != SIDE && score[i] < 100);
        printf("\n");
        if (score[i] >= 100) {
            printf("%s wins with %d points!\n", names[i], score[i]);
            break;
        }
        i++;
        if (i == num_players) {
            i = 0;
        }
    }

    return 0;
}
