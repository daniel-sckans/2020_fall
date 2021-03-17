#include <stdlib.h>
#include <stdio.h>
#include <string.h>

enum {
    FRESHMAN = 1, 
    SOPHOMORE, 
    JUNIOR, 
    SENIOR
}; 

struct student {
    int age; 
    char name[25]; 
    char id[16]; 
    int year; 
}; 

void student_ctor(struct student* s) {
    s->age = 15; 
    strcpy(s->name, "Phlegm Foolish"); 
    strcpy(s->id, "This and that"); 
    s->year = JUNIOR; 
}

int main(int argc, char* argv[argc + 1]) {
    struct student jesse; 
    student_ctor(&jesse); 
    printf("Jesse: %d : %s : %s : %d\n", jesse.age, jesse.name, jesse.id, jesse.year); 

    return EXIT_SUCCESS; 
}