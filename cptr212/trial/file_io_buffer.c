#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <string.h>
#include <termios.h>

char get_char() {
    struct termios old, new; 
    tcgetattr(0, &old); 
    new = old; 
    new.c_lflag &= ~ICANON; 
    new.c_lflag &= ~ECHO; 
    tcsetattr(0, 0, &new); 
    char c = getchar(); 
    tcsetattr(0, 0, &old); 
    return c; 
}

int main(int argc, char* argv[argc+1]) {
    struct winsize ws; 
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &ws); 

    char _[ws.ws_col]; 
    FILE* in_file = fopen(argv[1], "r"); 
    int line_count = 0; 
    while(!feof(in_file)) {
        fgets(_, ws.ws_col, in_file); 
        line_count++; 
    }
    printf("length: %d\n", line_count); 
    fseek(in_file, 0, SEEK_SET); 
    char buf[line_count][ws.ws_col]; 
    for(int y = 0; y < line_count; y++) {
        fgets(buf[y], ws.ws_col, in_file); 
    }

    char c = '\0'; 
    int line_number = 0; 
    do {
        if(c == '\n') {
            continue; 
        }
        if(c == 's') {
            line_number++; 
        }
        if(c == 'w' && 0 < line_number) {
            line_number--; 
        }

        for(int y = 0; y < ws.ws_row - 1; y++) {
            printf("%s", buf[y + line_number]); 
            if(buf[y + line_number][strlen(buf[y + line_number]) - 1] != '\n') {
                printf("\n"); 
            }
        }
    } while((c = get_char()) != 'q'); 

    fclose(in_file); 

    return EXIT_SUCCESS; 
}