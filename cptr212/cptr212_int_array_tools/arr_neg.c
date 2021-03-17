#include "iat.h"

int arr_neg(int* arr, unsigned int arr_len) {
    for (int i = 0; i < arr_len; i++) {
        arr[i] *= -1;
    }
    return 0;
}