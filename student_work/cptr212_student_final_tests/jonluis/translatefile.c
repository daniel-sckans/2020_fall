#include <stdio.h>
#include <stdlib.h>
#include <string.h> 


int main (int argc, char* argv[]) {
  
   FILE* fp = fopen("final.test","r");
   int a = 0;
   int c;
   int getlines = 0;
   char* buffer[200];
   char numline[100];
   
   //if (strcmp(argv[1], "-help") == 0){

       //printf("This program will calculate the factorial of a number.");

   //}

    while(fgets(numline, sizeof numline, fp)!=NULL) {

        buffer[a]=malloc(sizeof(numline));
        strcpy(buffer[a], numline);
        a++;
        getlines++;
        
    }

    for( int a = 0; a < getlines; a++){

        // Strings terminate with "\r\n", Windows-line endings (carriage return, newline).  
        // TODO: allow for arbitrary amount of whitespace at the beginning of the line.  
        // Use strcpy: the buffer is an array of pointers.  
        // If you set them equal to a string, the pointer points to a string literal, which sits in the data section of the program; it cannot be freed, and so causes the program to crash later, while the malloced memory is leaked.  
        // Instead, use strcpy, which just copies in the characters.  
        if (strcmp(buffer[a] , "Starting\r\n") == 0){
            strcpy(buffer[a], "int main(int argc, char* argv[]) {\r\n");
        }
        if (strcmp(buffer[a], "  Declaring_first_variable\r\n") == 0){
            strcpy(buffer[a], " int a = 1;\r\n");
        }
        if (strcmp(buffer[a], "  Declaring_second_variable\r\n") == 0){
            strcpy(buffer[a], " int b = 1;\r\n");
        }
        if (strcmp(buffer[a], "  Declaring_third_variable\r\n") == 0){
            strcpy(buffer[a], " int c = 1;\r\n");
        }
        if (strcmp(buffer[a], "  EXIT_PROGRAM\r\n") == 0){
            strcpy(buffer[a], "  return EXIT_SUCCESS;\r\n");
        }
        if (strcmp(buffer[a], "  Loop_numbers\r\n") == 0){
            strcpy(buffer[a], "  for (a = 1; a <= b; a++)\r\n");
        }
    }

    FILE* fo = fopen("final.c","w");      
    for (int a = 0; a < getlines; a++){
        
        fprintf(fo,"%s", buffer[a]);

    }

    for (int a = 0; a <getlines; a++){

        free(buffer[a]);

    }

    fclose(fp);
    fclose(fo);
   
    return EXIT_SUCCESS;   


}