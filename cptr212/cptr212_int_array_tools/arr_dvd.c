#include "iat.h"

int arr_dvd(int* arr, unsigned int arr_len, int divisor) {
    for(int i = 0; i < arr_len; i++) {
        arr[i] /= divisor; 
    }
    return 0; 
}