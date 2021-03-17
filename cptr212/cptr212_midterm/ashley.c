#include "contrib.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include "contrib.h"

//Had no idea how to run code to test if it worked or not, also all my stuff was named using ashley instead of ashley 
//so I went with it because otherwise it wouldn't match up and I assumed that would mess things up.

typedef struct ashley_class{
    char name[128];
    int strength;
    int intelligence;
    int agility;
    int magic;
    float luck;
}ashley_class; 

ashley_class* ashley_ctor(){
    ashley_class* hero = malloc(sizeof(ashley_class));
    strcpy(hero->name, "Iron Man"); 
    hero->luck = 0.00;
    hero->strength = 88;
    hero->intelligence = 120;
    hero->agility = 60;
    hero->magic = 10;
    
    return hero;
} 

int ashley_get(ashley_class* hero){ //Needs to be changed in the contrib.h master from void to int!!!
    return hero->agility;
}

void ashley_set(ashley_class* hero, int intelligence, int magic){
    hero->intelligence = intelligence;
    hero->magic = magic;
}

void* ashley_custom(ashley_class* hero){
    srand(time(NULL)); 
    hero->luck = (rand() % (81 - 0)) * 0.5; //randomish value of luck
    return NULL;
}

void ashley_print(ashley_class* hero){
    printf("Hero: %s\n", hero->name); //Either %s or %c couldn't figure out how to run code to test it
    printf("Strength- %d\n", hero->strength);
    printf("Intelligence- %d\n", hero->intelligence);
    printf("Agility- %d\n", hero->agility);
    printf("Magic- %d\n", hero->magic);
    printf("Luck- %f\n", hero->luck);
}

void ashley_dtor(ashley_class* hero){
    free(hero);
}