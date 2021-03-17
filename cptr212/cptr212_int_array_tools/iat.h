// This makes sure we don't keep multiple copies of the header.  
#ifndef IAT_H
#define IAT_H

// Implemented by Trevor.  
// Add the addend to each element of the array.  
int arr_add(int* arr, unsigned int arr_len, int addend); 

// Implemented by Jon.  
// Subtract the subtrahend from each element of the array.  
int arr_sub(int* arr, unsigned int arr_len, int subtrahend); 

// Implemented by Santiago.  
// Multiply each element of the array by the multiplier.  
int arr_mul(int* arr, unsigned int arr_len, int multiplier); 

// Implemented by Skyler.  
// Divide each element of the array by the divisor.  
int arr_dvd(int* arr, unsigned int arr_len, int divisor); 

// Implemented by Francis.  
// Set each element of the array equal to the number "set_to".  
int arr_set(int* arr, unsigned int arr_len, int set_to); 

// Implemented by Akito.  
// Multiply each element of the array by -1.  
int arr_neg(int* arr, unsigned int arr_len); 

// Implemented by Ashley.  
// Reverse the order of the array.  
int arr_rev(int* arr, unsigned int arr_rev); 

// Implemented by Nic.  
// Set each element of the array to a new random number.  
int arr_new(int* arr, unsigned int arr_new); 

#endif