#include "iat.h"

int arr_rev(int* arr, unsigned int arr_len){
    int *begin = &arr[0]; //first address of first value in array
    int *end = &arr[arr_len - 1]; //address of last value in array
    
    while (begin != end && begin < end){ //while value of begin and end are not the same and begin is less than end
        *begin ^= *end; //Use XOR to flip the values
        *end ^= *begin;
        *begin ^= *end;

        begin++; //move inward from the right by one
        end--; //move inward from the left by one
    }
    return 0; 
}
