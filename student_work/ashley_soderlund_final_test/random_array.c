// Write your random_array code definitions here, to be used inside of main.c.  
#include "random_array.h"

typedef struct random_array_t random_array_t;

random_array_t* random_array_ctor(unsigned int size, int min, int max){
    int* random_array = (int*)malloc(size * sizeof(int)); 
    srand(time(NULL)); 
    for(int i = 0; i < size; i++) {
        random_array[i] = rand() % max - min; 
    }
    return random_array;
}

void random_array_print(random_array_t* random_array){
    for(int i = 0; i < sizeof(random_array); i++){
        printf("\t#%3d: %4d", i, random_array[i]); //confused on pointer use
        if(i % 5 == 4) {
            printf("\n"); 
        }
    }

    return 0; 
}

void random_array_sort(random_array_t* random_array){
    int *left = &random_array[0]; //confused on pointer use while also using memory addresses
    int *right = &random_array[sizeof(random_array) - 1]; 

    while (left != right && left < right){ //while memory address of left doesn't equal right and left isn't greater than right
        *left ^= *right; 
        *right ^= *left; 
        *left ^= *right; 

        left++;
        right--;
    }
    return 0;
}

int random_array_get_median(random_array_t* random_array){
    int y;
    int median;
    int end = sizeof(random_array);

    if(end % 2 == 0){ //If half of the array is an even number
        y = end / 2;
        median = (random_array[y] + random_array[y-1]) / 2;     
    }
    else{ //If half the array is not an even number
        y = (end /2) - 0.5;
        median = random_array[y];
    }
    return median;
}

void random_array_dtor(random_array_t* random_array){
    for(int i = 0; i < sizeof(random_array); i++){
        free(random_array);
    }
    return 0;
}
