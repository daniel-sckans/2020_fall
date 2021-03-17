#include "iat.h"

int arr_set(int* arr, unsigned int arr_len, int set_to) {
    for(int i = 0; i < arr_len; i++) {
        arr[i] = set_to; 
    }
    return 0; 
}