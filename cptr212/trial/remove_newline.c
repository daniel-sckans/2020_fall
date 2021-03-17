#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[argc+1]) {
    FILE* in_file = fopen("assets/_ATaleOfTwoCities.txt", "r"); 
    FILE* out_file = fopen("assets/ATaleOfTwoCities.txt", "w"); 

    char buffer[4096] = {'\0'}; 
    int result; 
    while(!feof(in_file)) {
        fgets(buffer, 4096, in_file); 
        char _last_char = '\0'; 
        for(int x = 0; x < strlen(buffer); x++) {
            if((x != 1 && buffer[x] == '\n') || buffer[x] == '\r') {
                if(buffer[x] == '\n' && _last_char != ' ') {
                    fprintf(out_file, "%c", ' '); 
                    _last_char = ' '; 
                }
                continue; 
            } 
            fprintf(out_file, "%c", buffer[x]); 
            _last_char = buffer[x]; 
        }
    }
    
    fclose(in_file); 
    fclose(out_file); 

    return EXIT_SUCCESS; 
}