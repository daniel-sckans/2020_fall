#include <stdlib.h>
#include <stdio.h>

void print_bits(char c) {
    for(int i = 1; i < 256; i *= 2) {
        printf("%c", c & i ? 49 : 48); 
    }
    printf("\n"); 
}

int main(int argc, char** argv) {

    char c = 10; 
    print_bits(c); 

    return EXIT_SUCCESS; 
}