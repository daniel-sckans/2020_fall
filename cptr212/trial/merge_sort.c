#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define ARRAY_LENGTH 1024

void print_array(int* array); 

void merge_sort(int* array, int array_length); 

int main(int argc, char* argv[argc + 1]) {

    srand(time(NULL)); 
    int array[ARRAY_LENGTH] = {0}; 
    for(int i = 0; i < ARRAY_LENGTH; i++) {
        array[i] = rand() % 200 - 99; 
    }
    
    print_array(array); 

    merge_sort(array, ARRAY_LENGTH); 

    print_array(array); 

    return EXIT_SUCCESS; 
}

void print_array(int* array) {
    for(int i = 0; i < ARRAY_LENGTH; i++) {
        printf("%4d", array[i]); 
        if(i % 32 == 31) {
            printf("\n"); 
        }
    }
    printf("\n"); 
}

void merge_sort(int* array, int array_length) {
    if(array_length == 1) {
        return; 
    }

    int offset = array_length / 2; 
    merge_sort(array, offset); 
    merge_sort(array + offset, offset); 

    int work_array[array_length]; 
    int* left_cursor = array; 
    int* right_cursor = array + offset; 
    for(int i = 0; i < array_length; i++) {
        if(array + array_length <= right_cursor || (left_cursor < array + offset && *left_cursor < *right_cursor)) {
            work_array[i] = *left_cursor++; 
        } else {
            work_array[i] = *right_cursor++; 
        }
    }

    for(int i = 0; i < array_length; i++) {
        array[i] = work_array[i]; 
    }
}