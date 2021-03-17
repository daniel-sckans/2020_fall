#ifndef RANDOM_ARRAY_H
#define RANDOM_ARRAY_H

// Define the following items in the file "random_array_test.c".  

// Base this definition on its constructor (see immediately below).  
// (HINT: you will also need to store your array here.)
typedef struct random_array_t random_array_t; 

// Constructor for the random_array class.  
// The random array should have the assigned size, and each value should fulfill "min <= i < max".  
random_array_t* random_array_ctor(unsigned int size, int min, int max); 

// Sort the random array from lowest to highest using any algorithm you want.  
void random_array_sort(random_array_t* random_array); 

// Return the median value of the array; this should work even if the array has not been sorted yet.  
int random_array_get_median(random_array_t* random_array); 

// Print the array.  
void random_array_print(random_array_t* random_array); 

// Release memory.  
void random_array_dtor(random_array_t* random_array); 

#endif