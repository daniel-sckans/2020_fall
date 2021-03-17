#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "contrib.h"

typedef struct akito_class {
    int id; 
    char* name;
    int age;
} akito_class;


akito_class* akito_ctor() {
    akito_class* ac = malloc(sizeof(akito_class));

    ac->id = 111232486;
    ac->name = malloc(sizeof(char) * 128);
    strcpy(ac->name, "Akito Fujisawa");
    ac->age = 23;
    return ac;
}


int akito_get(akito_class* ac) {
    return ac->age;
}


void akito_set(akito_class* ac, int i) {
    ac->age = i;
}


void* akito_custom(akito_class* ac) {
    akito_set(ac, akito_get(ac) + 1);
    printf("My birthday is October 15. I will be %d years old!\n", akito_get(ac));
    return NULL;
}


void akito_print(akito_class* ac) {
    printf("ID: %d\n", ac->id);
    printf("Name: %s\n", ac->name);
    printf("Age: %d\n", ac->age);
}

void akito_dtor(akito_class* ac) {
    free(ac->name);
    free(ac);
}