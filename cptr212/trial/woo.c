#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char** argv) {

    FILE* f_in = fopen(argv[1], "r"); 

    char output_file_name[32] = {0}; 
    strcpy(output_file_name, argv[1]); 
    char* extension_index = strstr(output_file_name, ".woo"); 
    extension_index[1] = 'c'; 
    extension_index[2] = '\0'; 
    FILE* f_out = fopen(output_file_name, "w"); 

    while(!feof(f_in)) {
        char buffer[256] = {0}; 
        fgets(buffer, 256, f_in); 
        if(strstr(buffer, "TEN")) {
            int cursor = 0; 
            while(buffer[cursor++] == 32) {
                fprintf(f_out, " "); 
            }
            
            if(strstr(buffer, "\\TEN")) {
                fprintf(f_out, "}\n"); 
            } else {
                fprintf(f_out, "for(int i = 0; i < 10; i++) {\n"); 
            }
        } else {
            fprintf(f_out, "%s", buffer); 
        }
    }

    fclose(f_in); 
    fclose(f_out); 

    return EXIT_SUCCESS; 
}