#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main(int argc, char** argv) {

    int arr[128] = {0}; 
    srand(time(NULL)); 
    int i = 0; 
    for(; i < sizeof(arr) / sizeof(arr[0]); i++) {
        arr[i] = rand() % 200; 
        fprintf(stdout, "%d\t", arr[i]); 
        if(i % 21 == 20) {
            fprintf(stdout, "\n"); 
        }
    }
    fprintf(stdout, "\n%d\n", i); 


    for(int i = 0; i < sizeof(arr) / sizeof(arr[0]) - 1; i++) {
        if(arr[i + 1] < arr[i]) {
            arr[i] ^= arr[i + 1]; 
            arr[i + 1] ^= arr[i]; 
            arr[i] ^= arr[i + 1]; 
            i = -1; 
        }
    }

    fprintf(stdout, "\n\n"); 
    for(i = 0; i < sizeof(arr) / sizeof(arr[0]); i++) {
        fprintf(stdout, "%d\t", arr[i]); 
        if(i % 21 == 20) {
            fprintf(stdout, "\n"); 
        }
    }
    fprintf(stdout, "\n%d\n", i); 
    fflush(stdout); 

    return EXIT_SUCCESS; 
}