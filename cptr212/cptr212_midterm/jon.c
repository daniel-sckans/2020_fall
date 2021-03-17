#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ioctl.h>
#include <termios.h>
#include <time.h>
#include "contrib.h"


typedef struct jon_class {
    
    char player_name[200];
    char* current_team;
    char height;
    int jersey_num;
    float career_goals;
    char position;

}jon_class; 


jon_class* jon_ctor(){
    jon_class* ga = malloc(sizeof(jon_class)); 

    strcpy(ga->player_name, "LeBron James");
    ga-> current_team = malloc(sizeof(char) *200);
    strcpy(&ga-> height, "6ft 9in");
    ga-> jersey_num = 23;
    ga-> career_goals = 1265;
    ga-> position = 'P';
        
    return ga; 
} 


char* jon_get(jon_class* ga){
    
    return ga->player_name;

}

void jon_set(jon_class* ga, double position){

    ga-> position = position;

} 


void* jon_custom(jon_class* ga){
    
    ga->career_goals +=100;
    return NULL;

} 
void jon_print(jon_class* ga){

    printf("\033[0;33mName: %s\n", ga->player_name);
    printf("\033[0m"); 

    printf("\033[0;36mPosition: %c\n", ga->position);
    printf("\033[0m"); 
    
    printf("\033[0;36mCareer Goals: %f\n", ga->career_goals);
    printf("\033[0m"); 

    printf("\033[0;35mJersey Number: %d\n", ga->jersey_num);
    printf("\033[0m"); 

}

void jon_dtor(jon_class* ga){

    free(ga->current_team);
    free(ga);

} 