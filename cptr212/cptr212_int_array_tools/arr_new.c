#include <stdlib.h>
#include <time.h>
#include "iat.h"

int arr_new(int* arr, unsigned int arr_new) {
    srand(time(NULL)); 
    for(int i = 0; i < arr_new; i++) {
        arr[i] = rand() % 199 - 99; 
    }
    return 0; 
}