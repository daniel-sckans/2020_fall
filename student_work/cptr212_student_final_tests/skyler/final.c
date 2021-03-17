#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define end 250

void process(char* txt, char* outtxt, int line_count){
    for(int y = 0; y < line_count; y++) {
        char buf[end +1];
        strcpy (buf, txt);

        char* sub = strstr(buf,"yellow");
        if(sub != NULL){

            // Quotes must be escaped.  
            strcpy(buf, "fprintf(\"A dandelion is yellow\");\r\n");
        }
        strcpy(outtxt, buf);
        
        outtxt += 251;
        txt += 251;
    }
}

int main(int argc, char const *argv[]) {

    if(argc < 2) {
        fprintf(stderr, "Please specify the name of the file"); 
        return 1;
    }

    FILE* txt_file = fopen(argv[1], "r"); 
    if(!txt_file) {
        fprintf(stdout, "No file.\n"); 
        return EXIT_FAILURE; 
    }

    int line_count = 0; 
    char buf[end + 1]; 
    while(!feof(txt_file)) {
        fgets(buf, end + 1, txt_file); 
        line_count++; 
    }
    fseek(txt_file, 0, SEEK_SET); 

    char txt[line_count][end + 1]; 
    for(int y = 0; y < line_count; y++) {
        fgets(txt[y], end + 1, txt_file); 
    }
    fclose(txt_file); 
    
    char outtxt[line_count][end+1];
    process((char*)txt,(char*)outtxt, line_count);
    char filename[256];
    strcpy(filename, argv[1]);
    strcat(filename, ".c");
    
    FILE* outfile = fopen(filename, "w"); 
    for(int y = 0; y < line_count; y++) {
        fputs(outtxt[y], outfile); 
    }
    fclose(outfile); 

    return 0;
}
