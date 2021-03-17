// Write your random_array code definitions here, to be used inside of main.c.  

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "random_array.h"

typedef struct random_array_t {
    int* array; 
    unsigned int size; 
    int min; 
    int max; 
} random_array_t; 

random_array_t* random_array_ctor(unsigned int size, int min, int max) {
    random_array_t* random_array = malloc(sizeof(random_array_t)); 
    random_array->size = size; 
    random_array->min = min; 
    random_array->max = max; 
    random_array->array = malloc(sizeof(int) * size); 
    srand(time(NULL)); 
    for(int i = 0; i < size; i++) {
        random_array->array[i] = rand() % (max - min) + min; 
    }
    return random_array; 
}

void random_array_sort(random_array_t* random_array) {
    for(int i = 0; i < random_array->size - 1; i++) {
        if(random_array->array[i + 1] < random_array->array[i]) {
            random_array->array[i] ^= random_array->array[i + 1]; 
            random_array->array[i + 1] ^= random_array->array[i]; 
            random_array->array[i] ^= random_array->array[i + 1]; 
            i = -1; 
        }
    }
}

int random_array_get_median(random_array_t* random_array) {
    random_array_t buffer_array = *random_array; 
    buffer_array.array = malloc(sizeof(int) * random_array->size); 
    for(int i = 0; i < random_array->size; i++) {
        buffer_array.array[i] = random_array->array[i]; 
    }
    random_array_sort(&buffer_array); 
    return buffer_array.array[buffer_array.size / 2]; 
}

void random_array_print(random_array_t* random_array) {
    for(int i = 0; i < random_array->size; i++) {
        printf("%5d", random_array->array[i]); 
        if(i % 8 == 7) {
            printf("\n"); 
        }
    }
    printf("\n"); 
}

void random_array_dtor(random_array_t* random_array) {
    free(random_array->array); 
    free(random_array); 
}