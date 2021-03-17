#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include "iat.h"

#define MAX_ARR_LEN 256

// Declare enumerated values for the operations we'll use.   
// See Gustedt's Modern C 5.6.2 "Enumerations" for info on this technique.  
enum { 
    add, sub, mul, dvd, set, neg, rev, new, op_num,
}; 
char const*const ops[op_num] = {
    [add] = "add", [sub] = "sub", [mul] = "mul", [dvd] = "dvd", [set] = "set", [neg] = "neg", [rev] = "rev", [new] = "new",
}; 
int (*ops_def[op_num])() = {
    [add] = &arr_add, [sub] = &arr_sub, [mul] = &arr_mul, [dvd] = &arr_dvd, [set] = &arr_set, [neg] = &arr_neg, [rev] = &arr_rev, [new] = &arr_new,
}; 

int main(int argc, char* argv[argc + 1]) {

    // Check an arg was passed.  
    if(argc != 2) {
        fprintf(stderr, "Accepts one argument indicating the length of the array, between 0 and %d.\n", MAX_ARR_LEN); 
        return 1; 
    }

    // Check it was the right type with strtoul (string to unsigned long).  
    // This function is considered safer than stoi, and in this case we need a positive number less than MAX_ARR_LEN.  
    char* end_of_conversion; 
    unsigned int arr_len = strtoul(argv[1], &end_of_conversion, 10); 
    if(!arr_len || MAX_ARR_LEN < arr_len) {
        fprintf(stderr, "The array length must be a number greater than zero and less than %d.\n", MAX_ARR_LEN); 
        return 2; 
    }

    // We'll create an array using malloc to allocate space for each integer in the array (in the first line).  
    // Then we'll seed rand() with the current time.  
    // Lastly, we'll iterate through the array and set each element to a random int, and print it.  
    int* arr = (int*)malloc(arr_len * sizeof(int)); 
    srand(time(NULL)); 
    printf("\nInitial array: \n"); 
    for(int i = 0; i < arr_len; i++) {
        arr[i] = rand() % 199 - 99; 
        printf("\t#%3d: %4d", i, arr[i]); 
        if(i % 5 == 4) {
            printf("\n"); 
        }
    }

    // Get user input.  
    char str[3] = {'\0'}; 
    do {
        printf("\nAvailable operations (or 'q' to quit):"); 
        printf("\n\tadd n \tsub n \tmul n \tdiv n"); 
        printf("\n\tneg \tset n \trev \tnew\n"); 

        // Here we'll take in a string of three chars.  
        scanf("%3s", str); 

        // Next we check it against the string associated with each op_num (see the enumerated values above).  
        // If it matches, we'll call the function we want in the switch.  
        // If needed, we'll also get an argument for operations like "add".  
        for(int i = 0; i < op_num; i++) {
            if(strncmp(str, ops[i], 3) == 0) {
                int op_arg = 0; 
                int err = 0; 
                if(i < neg) {
                    scanf("%d", &op_arg); 
                    err = ops_def[i](arr, arr_len, op_arg); 
                } else {
                    err = ops_def[i](arr, arr_len); 
                }

                // If an error occurred, return.  
                if(err) {
                    fprintf(stderr, "Operation resulted in error.\n"); 
                    return 3; 
                }

                // Print the array again, after changes have been made.  
                for(int i = 0; i < arr_len; i++) {
                    printf("\t#%3d: %4d", i, arr[i]); 
                    if(i % 5 == 4) {
                        printf("\n"); 
                    }
                }
                break; 
            }
        }

        // Clean up any characters still waiting in stdin.  
        while(getchar() != '\n'); 
    } while(str[0] != 'q'); 
    return EXIT_SUCCESS; 
}