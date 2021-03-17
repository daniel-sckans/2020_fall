#include <unistd.h>
#include <stdio.h>
#include <termios.h>

#include "get_char_raw.h"

char get_char_raw() {

    // Get the old terminal settings.  
    // Copy them to a "new_terminal".  
    // In that copy, turn off the "ICANON" and "ECHO" flags, to disable buffered input and echoing, respectively.  
    struct termios old_terminal, new_terminal; 
    tcgetattr(STDOUT_FILENO, &old_terminal); 
    new_terminal = old_terminal; 
    new_terminal.c_lflag &= ~ICANON; 
    new_terminal.c_lflag &= ~ECHO; 
    
    // Activate the new settings, get one character, and go back to the old settings.  
    // We only get one character to minimize the chance of influencing the terminal's settings outside the program.  
    tcsetattr(TCSANOW, STDOUT_FILENO, &new_terminal); 
    char c = getchar(); 
    tcsetattr(TCSANOW, STDOUT_FILENO, &old_terminal); 

    // Special cases for ANSI-escaped characters.  
    // These return the enumerated characters above.  
    // We look for special characters codes and throw away unneeded characters.  
    // If we can't match anything, return '\0', the NULL char.  
    char output_char = c; 
    if(c == '\033') {
        getchar(); 
        char char_escaped = getchar(); 
        if('A' <= char_escaped && char_escaped <= 'D') {
            output_char = char_escaped - 'A' + 128; 
        } else if(char_escaped == 'F') {
            output_char = CHAR_RAW__END; 
        } else if(char_escaped == 'H') {
            output_char = CHAR_RAW__HOME; 
        } else {
            output_char = '\000'; 
        }
    }

    return output_char; 
}
