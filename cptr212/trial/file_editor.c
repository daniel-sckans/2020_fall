#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <termios.h>

char get_char() {
    struct termios original_term, new_term; 
    tcgetattr(STDIN_FILENO, &original_term); 
    new_term = original_term; 
    new_term.c_lflag &= ~ICANON; 
    new_term.c_lflag &= ~ECHO; 
    tcsetattr(TCSANOW, STDIN_FILENO, &new_term); 
    char c = getchar(); 
    tcsetattr(TCSANOW, STDIN_FILENO, &original_term); 
    return c; 
}

int main(int argc, char* argv[argc+1]) {
    struct winsize ws; 
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &ws); 

    FILE* txt_file = fopen(argv[1], "r"); 
    if(!txt_file) {
        fprintf(stderr, "That was a mistaken file opening session.\n"); 
        return EXIT_FAILURE; 
    }
    
    int lines_in_file = 0; 
    while(!feof(txt_file)) {
        char buf[ws.ws_col+1]; 
        fgets(buf, ws.ws_col, txt_file); 
        lines_in_file++; 
    }
    fseek(txt_file, 0, SEEK_SET); 
    char* txt[lines_in_file]; 
    for(int y = 0; y < lines_in_file; y++) {
        txt[y] = (char*)malloc(ws.ws_col * sizeof(char) + 1); 
        fgets(txt[y], ws.ws_col + 1, txt_file); 
    }

    for(int y = 0; y < ws.ws_row; y++) {
        printf("%s", txt[y]); 
    }

    char c = 0; 
    int x = 1; 
    int y = 1; 
    printf("\033[1;1H"); 
    while((c = get_char()) != 'q') {
        if(c == '\033') {
            getchar(); 
            switch(getchar()) {
                case 'A': 
                    if(1 < y) {
                        y--; 
                    }
                    break; 
                case 'B': 
                    if(y < ws.ws_row) {
                        y++; 
                    }
                    break; 
                case 'C': 
                    if(x < ws.ws_col) {
                        x++; 
                    }
                    break; 
                case 'D': 
                    if(1 < x) {
                        x--; 
                    }
                    break; 
                }
        } else {
            printf("\033[38;2;0;255;255m%c", c); 
            txt[y - 1][x++ - 1] = c; 
        }

        printf("\033[%d;%dH", y, x);
        fflush(stdout); 
    }

    FILE* txt_out = fopen("assets/ATaleOfThreeCities.txt", "w"); 
    if(!txt_out) {
        fprintf(stderr, "That was a no no no no no file.\n"); 
        return EXIT_FAILURE; 
    }
    for(int y = 0; y < lines_in_file; y++) {
        fprintf(txt_out, "%s", txt[y]); 
    }
    fflush(txt_out); 
    
    return EXIT_SUCCESS; 
}