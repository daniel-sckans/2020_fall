#include "iat.h"

int arr_mul(int* arr, unsigned int arr_len, int multiplier){

    for (int i=0; i<arr_len; i++){ 
        arr[i] *= multiplier;
    }
    return 0;
} 
