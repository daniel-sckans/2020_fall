# include "iat.h"

// Implemented by Jon.  
// Subtract the subtrahend from each element of the array.  
int arr_sub(int* arr, unsigned int arr_len, int subtrahend){
    for (int i = 0; i < arr_len; i++){

        arr[i] -= subtrahend;

    }

    return 0;

}
