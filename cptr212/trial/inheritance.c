#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct color_printer_t color_printer_t; 
color_printer_t* color_printer_new(); 
void color_printer_set_color(); 
void color_printer_print(); 

typedef struct letter_color_printer_t letter_color_printer_t; 
letter_color_printer_t* letter_color_printer_new(); 
void letter_color_printer_print(); 

int main(int argc, char** argv) {

    color_printer_t* color_printer = color_printer_new(); 
    color_printer_set_color(color_printer, 255, 0, 255); 
    color_printer_print(color_printer); 

    letter_color_printer_t* letter_color_printer = letter_color_printer_new(); 
    color_printer_set_color((color_printer_t*)letter_color_printer, 255, 255, 0); 
    letter_color_printer_print(letter_color_printer); 

    printf("\n"); 
    return EXIT_SUCCESS; 
}

typedef struct color_printer_t {
    int r; 
    int g; 
    int b; 
} color_printer_t; 

color_printer_t* color_printer_new() {
    color_printer_t* color_printer = malloc(sizeof(color_printer_t)); 
    color_printer->r = 0; 
    color_printer->g = 0; 
    color_printer->b = 0; 
    return color_printer; 
}

void color_printer_set_color(color_printer_t* color_printer, int r, int g, int b) {
    color_printer->r = r; 
    color_printer->g = g; 
    color_printer->b = b; 
}

void color_printer_print(color_printer_t* color_printer) {
    fprintf(stdout, "\033[48;2;%d;%d;%dm ", color_printer->r, color_printer->g, color_printer->b); 
}

typedef struct letter_color_printer_t {
    color_printer_t color_printer; 
    char letter; 
} letter_color_printer_t; 

letter_color_printer_t* letter_color_printer_new() {
    letter_color_printer_t* letter_color_printer = malloc(sizeof(letter_color_printer_t)); 
    letter_color_printer->color_printer.r = 0; 
    letter_color_printer->color_printer.g = 0; 
    letter_color_printer->color_printer.b = 0; 
    letter_color_printer->letter = 'a'; 
    return letter_color_printer; 
}

void letter_color_printer_print(letter_color_printer_t* letter_color_printer) {
    fprintf(stdout, "\033[48;2;%d;%d;%dm%c", letter_color_printer->color_printer.r, letter_color_printer->color_printer.g, letter_color_printer->color_printer.b, letter_color_printer->letter); 
}