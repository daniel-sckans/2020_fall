#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "contrib.h"


typedef struct trevor_class
{
    char name[200];
    int jersey_number;
    char height[100];
    int weight;
    char grade;
    char position;
    char* homeTown;
    char* pastSchool;
    int gp;
    

} trevor_class; 

trevor_class* trevor_ctor()
{
    // sets memory aside 
    trevor_class* sc = malloc(sizeof(trevor_class));

    strcpy(sc->name, "Trevor Avila");
    strcpy(sc->height, "5ft 9in");
    sc->jersey_number = 92;
    sc->weight = 147;
    sc->grade = 'j';
    sc->position = 'M'; 
    sc->gp = 0;
    sc->pastSchool = malloc(sizeof(char) * 200);
    strcpy(sc->pastSchool, "Hesston College");
    sc->homeTown = malloc(sizeof(char)* 200);
    strcpy(sc->homeTown, "El Paso, Texas");

    return sc; 
}

int trevor_get(trevor_class* sc)
{
    return sc->jersey_number;
}

void trevor_set(trevor_class* sc, int gp)
{
    sc->gp = gp;
} 

void* trevor_custom(trevor_class* sc)
{
    sc->jersey_number *= 8;
    return NULL;
} 

void trevor_print(trevor_class* sc)
{
    printf("Trevor is from %s\n", sc->homeTown);
    printf("Trevor also played for a year at %s", sc->pastSchool);

} 
void trevor_dtor(trevor_class* sc)
{
    free(sc->pastSchool);
    free(sc->homeTown);
    free(sc);
}
