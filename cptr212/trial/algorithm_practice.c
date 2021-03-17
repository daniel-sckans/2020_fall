#include <stdlib.h>
#include <stdio.h>

#define ARRAY_SIZE 64

void merge_sort(); 

int main(int argc, char** argv) {

    int array[ARRAY_SIZE] = {0}; 
    srand(time(NULL)); 
    for(int i = 0; i < ARRAY_SIZE; i++) {
        array[i] = rand() % 200 - 100; 
        printf("%4d", array[i]); 
    }
    printf("\n\n"); 

    merge_sort(array, array + ARRAY_SIZE - 1); 

    for(int i = 0; i < ARRAY_SIZE; i++) {
        printf("%4d", array[i]); 
    }
    printf("\n"); 

    return EXIT_SUCCESS; 
}

void swap_two(int* a, int* b) {
    *a ^= *b; 
    *b ^= *a; 
    *a ^= *b; 
}

void merge_sort(int* beginning, int* end) {
    if(beginning == end) {
        return; 
    } 

    int size = end - beginning; 
    merge_sort(beginning, beginning + size / 2); 
    merge_sort(beginning + size / 2 + 1, end); 
    int* cursor = beginning; 

    while()
}