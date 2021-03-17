#include "iat.h"

int arr_add(int* arr, unsigned int arr_len, int addend) {
    for(int i = 0; i < arr_len; i++) {
        arr[i] += addend; 
    }
    return 0; 
}