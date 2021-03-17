#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main(int argc, char** argv) {

    // int[] = 1 2 3 4 5
    // char c = 'c'; 
    // bitwise operator: xor 
    // c: 00100110 
    // d: 11110000
    // c ^= d
    // c: 11010110

    int a = 5; 
    int b = 71; 
    // 1010
    // 1110
    
    a ^= b;
    // 0100
    // 1110 

    b ^= a; 
    // 0100
    // 1010

    a ^= b; 
    // 1110
    // 1010

    // Sort an array: insertion sort

    srand(time(NULL)); 
    int arr[128] = {0}; 
    for(int i = 0; i < sizeof(arr) / sizeof(int); i++) {
        arr[i] = rand() % 300; 
        printf("%d\t", arr[i]); 
    }

    // Sorting algorithm
    for(int i = 0; i < sizeof(arr) / sizeof(int) - 1; i++) {
        if(arr[i] > arr[i + 1]) {
            arr[i] ^= arr[i + 1]; 
            arr[i + 1] ^= arr[i]; 
            arr[i] ^= arr[i + 1]; 
            i = -1; 
        }
    }



    // Print again
    printf("\n\n"); 
    for(int i = 0; i < sizeof(arr) / sizeof(int); i++) {
        printf("%d\t", arr[i]); 
    }


    return EXIT_SUCCESS; 
}