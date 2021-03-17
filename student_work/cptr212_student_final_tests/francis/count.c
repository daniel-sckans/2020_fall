#include <stdio.h>
#include <stdlib.h>
#include "m.c"

FRANCIS
START
    POPE gamescore[10] = {0, 2, 3, 5, -1, 7};
    POPE totalgoals = 0;
    POPE i;
    float avg;
    for(POPE i=6; i<10; i++)
    START
        SHOW("what did the player score in game %d? ", i+1);
        scanf(" %d", &gamescore[i]);
    FINISH
    for(POPE i =0; i<10; i++)
    START
        totalgoals += gamescore[i];
    FINISH

    avg = ((float)totalgoals/10);

    SHOW("\n\nThe Player's goal average is %.1f.\n", avg);

    return 0;
FINISH
