// Write your random_array code definitions here, to be used inside of main.c.  
#include <stdio.h>
#include <stdlib.h>
#include "random_array.h"


typedef struct random_array_t {
    int i = 0;
    int a = 0;
    int b = 0;
    int c = 0;
    float getmedian = 0;
    unsigned int size = 0;
    int min = 0;
    int max = 0;

} random_array_t; 
 
// Constructor for the random_array class.  
// The random array should have the assigned size, and each value should fulfill "min <= i < max".  
random_array_t* random_array_ctor(unsigned int size, int min, int max){
    
    random_array_t* random_array_ctor = malloc(sizeof(random_array_t));
    random_array_t->size = 0;
    random_array_t->min = 0;
    random_array_t->max = 0;
    return random_array_t;
}

// Sort the random array from lowest to highest using any algorithm you want.  
void random_array_sort(random_array_t* random_array){
    
    if (random_array = 1){
        return;
    }
    for(int a = 0; a <= size_t - 1, a++){
        c = random_array[a];
        for(int b = a -1; b >= 0 && random_array[a] > c; b--){
            random_array[b+1] = random_array[b];
        }
        random_array[b+1] = c;
    }
}

// Return the median value of the array; this should work even if the array has not been sorted yet.  
int random_array_get_median(random_array_t* random_array){
    random_array-> getmedian = 0;
    //for even numbers
    if (random_array%2 == 0){
        getmedian = (random_array_t[(random_array - 1)/2] +random_array_t[random_array/2])/2.0;
    }
    //for odd numbers
    else{
        getmedian = random_array_t[random_array/2];
    }
    return getmedian;
}

// Print the array.  
void random_array_print(random_array_t* random_array){
    for (int i = 0; i < random_array; i++){
        printf("Array1[%d] : %d", i, random_array[i])
    }
}

// Release memory.  
void random_array_dtor(random_array_t* random_array){
    for (int i = 0; i <random_array; i++){

        free(random_array_t[random_array]);

    }

}