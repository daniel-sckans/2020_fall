#include <stdlib.h>
#include <stdio.h>

void print_bits(char c) {
    char buffer[9] = {0}; 
    for(int i = 1, j = 0; j < 8; i *= 2, j++) {
        buffer[j] = c & i ? 49 : 48; 
    }
    printf("Bits: %s\n", buffer); 
}

int main(int argc, char** argv) {

    return EXIT_SUCCESS; 
}