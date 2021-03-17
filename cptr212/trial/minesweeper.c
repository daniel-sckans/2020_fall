#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/ioctl.h>
#include <time.h>
#include "get_char_raw.h"



int main(int argc, char* argv[argc + 1]) {
    struct winsize ws; 
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &ws); 

    srand(time(NULL)); 
    int buffer[ws.ws_row][ws.ws_col]; 
    for(int y = 0; y < ws.ws_row; y++) {
        for(int x = 0; x < ws.ws_col; x++) {
            buffer[y][x] = rand() % 25 == 0; 
            printf(" "); 
        }
    }
    printf("\033[H"); 

    char c = '\0'; 
    int cursor_x = 0, cursor_y = 0; 
    while((c = get_char_raw()) != 'q') {
        switch(c) {
            case CHAR_RAW__ARROW_UP: 
                if(0 < cursor_y) {
                    cursor_y--; 
                }
                break; 
            case CHAR_RAW__ARROW_DOWN: 
                if(cursor_y < ws.ws_row - 1) {
                    cursor_y++; 
                }
                break; 
            case CHAR_RAW__ARROW_RIGHT: 
                if(cursor_x < ws.ws_col - 1) {
                    cursor_x++; 
                }
                break; 
            case CHAR_RAW__ARROW_LEFT: 
                if(0 < cursor_x) {
                    cursor_x--; 
                }
                break; 
            case 'f': 
                if(buffer[cursor_y][cursor_x] == 1) {
                    printf("\033[2JThat was a loss.\n"); 
                    return EXIT_SUCCESS; 
                }
                int bombs_nearby = 0; 
                for(int y = cursor_y - 1; y < cursor_y + 2; y++) {
                    for(int x = cursor_x - 1; x < cursor_x + 2; x++) {
                        if(y < 1 || ws.ws_row - 1 < y) {
                            break; 
                        } 
                        if(x < 1 || ws.ws_col - 1 < x) {
                            continue; 
                        }
                        bombs_nearby += buffer[y][x]; 
                    }
                }
                printf("%d", bombs_nearby); 
                break; 
        }
        printf("\033[%d;%dH", cursor_y + 1, cursor_x + 1); 
        
    }
    
    return EXIT_SUCCESS; 
}