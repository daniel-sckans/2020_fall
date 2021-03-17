#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <string.h>
#include <errno.h>

int main(int argc, char* argv[argc+1]) {

    // Get the terminal window size.  
    struct winsize _winsize; 
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &_winsize); 

    // Check that one argument was supplied.  
    if(argc != 2) {
        fprintf(stderr, "You must enter exactly one argument naming the file.\n"); 
        return EXIT_FAILURE; 
    }

    // Get the file supplied as an argument.  
    FILE* txt_file = fopen(argv[1], "r"); 
    if(!txt_file) {
        fprintf(stderr, "The argument you entered does not correspond to a correct file.\n"); 
        return EXIT_FAILURE; 
    }

    // Main loop.  
    long past_position = 0; 
    char c = '\0'; 
    do {
        char buf[1024] = {'\0'}; 

        // Respond to characters.  
        switch(c) {
            case '\n': 
                continue; 
                break; 
            case 's': 
                fseek(txt_file, past_position, SEEK_SET); 
                fgets(buf, _winsize.ws_col, txt_file); 
                past_position = ftell(txt_file); 
                break; 
            case 'w': 
                fseek(txt_file, past_position - _winsize.ws_col, SEEK_SET); 
                past_position = ftell(txt_file); 
                break; 
        }

        for(int y = 0; y < _winsize.ws_row; y++) {
            printf("%s", fgets(buf, _winsize.ws_col, txt_file)); 
        }
    } while((c = getchar()) != 'q'); 

    // Hallelujah.  
    printf("Goodbye.\n"); 
    return EXIT_SUCCESS; 
}