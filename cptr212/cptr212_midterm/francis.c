#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "contrib.h"

    // francis class
typedef struct francis_class {
    int significant_property;
    char id;
    int random;
    char name[128];
    char* last_name;
    float f;
} francis_class; 
francis_class* francis_ctor(){
    francis_class* fw = malloc(sizeof(francis_class));

    fw ->significant_property=100;
    fw->id='P';
    fw->random = 237;
    strcpy(fw->name,"Francis");
    fw->last_name=malloc(sizeof(char) * 128);
    strcpy(fw->last_name, "Watson");
    fw->f = 0;
    return fw;
}
int francis_get(francis_class* fw){
    return fw->random;
}
void francis_set(francis_class* fw, double f){
    fw->f = f;
}
//void* francis_custom(); 
void francis_print(francis_class* fw){
    printf("");
} 
void francis_dtor(francis_class* fw){
    free(fw->last_name);
    free(fw);
}
