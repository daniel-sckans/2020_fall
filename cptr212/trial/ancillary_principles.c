#include <stdlib.h>
#include <stdio.h>

void print_bits(char c) {
    for(int i = 1; i < 256; i *= 2) {
        printf("%c", c & i ? 49 : 48); 
    }
}

int main(int argc, char** argv) {

    print_bits(127); 
    print_bits(127 | 255); 

    return EXIT_FAILURE; 
}