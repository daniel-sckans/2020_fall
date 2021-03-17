#ifndef GET_CHAR_RAW_H
#define GET_CHAR_RAW_H

// Extending the ASCII characters.  
// These are passed in via ANSI escape characters (beginning with "\033[").  
enum {
    CHAR_RAW__ARROW_UP = -128, 
    CHAR_RAW__ARROW_DOWN, 
    CHAR_RAW__ARROW_RIGHT, 
    CHAR_RAW__ARROW_LEFT, 
    CHAR_RAW__END = -123, 
    CHAR_RAW__HOME = -121
}; 

char get_char_raw(); 

#endif