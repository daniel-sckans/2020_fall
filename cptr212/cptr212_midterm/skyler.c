#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "contrib.h"

typedef struct skyler_class{
    int significant_property;
    char id;
    int random;
    char name [128];
    char* last_name;
    

} skyler_class;

skyler_class* skyler_ctor() {
    skyler_class* mt = malloc(sizeof(skyler_class)); 

    mt->significant_property = 20; 
    mt->id = 'c'; 
    mt->random = 706154; 
    strcpy(mt->name, "skyler"); 
    mt->last_name = malloc(sizeof(char) * 16); 
    strcpy(mt->last_name, "espinoza"); 
    return mt; 
} 

int skyler_get(skyler_class* mt) {
    printf("\nEnter an ID : ");
    mt->id = fgetc(stdin);
    printf("You entered: %c", mt->id);

   return(0);
}

void skyler_set(skyler_class* mt, int id) {
    mt->id = id; 
}

void* skyler_custom(skyler_class* mt) {
    int i = 183; 
    printf("custom number: %d\n", i); 
    return NULL; 
}

void skyler_print(skyler_class* mt) {
    printf("Significant property: \033[38;2;0;255;255m%d\033[0m\n", mt->significant_property); 
    printf("ID: %c\n", mt->id); 
    printf("Name: %s\n", mt->name);
    printf("Lastname: %s\n", mt->last_name);
}

void skyler_dtor(skyler_class* mt) {
    free(mt->last_name); 
    free(mt);
}