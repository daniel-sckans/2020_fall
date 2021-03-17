#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]){
    int i=0;
    int numLines=0;
    char* buffer[200];
    char line[100];

    //Lets the user know they must enter a second argument
    if(argc < 2){
        printf("Enter a second argument when running the program.");
        printf("'Help' for a description and anything else to continue the program\n");
        return EXIT_SUCCESS;
    }

    /*int counter; 
    printf("Program Name Is: %s",argv[0]); 
    if(argc==1) 
        printf("\nNo Extra Command Line Argument Passed Other Than Program Name"); 
    if(argc>=2) 
    { 
        printf("\nNumber Of Arguments Passed: %d",argc); 
        printf("\n----Following Are The Command Line Arguments Passed----"); 
        for(counter=0;counter<argc;counter++) 
            printf("\nargv[%d]: %s",counter,argv[counter]); 
    } */

    //Help argument
    if(strcmp(argv[1], "Help") == 0){
        printf("This is a programming language that reflects reading a story book or fairy tale.\n");
        printf("Hence, it starts out with Once Upon a Time and ends with The End.\n");
        printf("This language is called Story.\n");
    }

    //read final.yes
    FILE* in_file = fopen("final.yes", "r");

    //Check if file is availble
    if (in_file == NULL) {
      fprintf(stderr, "\nError to open the file\n");
      return EXIT_SUCCESS;
    }

    //Get file contents and add into an array
    while(fgets(line, sizeof line, in_file)!=NULL) {
        buffer[i]=malloc(sizeof(line));
        strcpy(buffer[i], line);
        i++;
        numLines++;
    }

    //Ignore these variables, used to test changing the buffer before I figured out how to compare them
    //int d = 93;
    //int e = 92;
    //int f = 6;
    //int l = 20;
    for(int i = 0; i < numLines; i++){
        //Check when Story language matches the lines in the buffer and changes them to C language
        if(strcmp(buffer[i], "Once_Upon_A_Time\n") == 0){ //f == i
            buffer[i] = "int main(int argc, char** argv){\n";
            //f = 1000;
        }
        if(strcmp(buffer[i], "The_End\n") == 0){ //e == i
            buffer[i] = "   return EXIT_SUCCESS;\n";
            //e = 2000;
        }
        if(strcmp(buffer[i], "Close_Book") == 0){ // d == i
            buffer[i] = "}\n";
            //d = 1000;
        }
        if(strcmp(buffer[i], "        Read\n") == 0){
            buffer[i] = "        scanf(\"%d\", &n);\n"; //Fix quotes
        }
        if(strcmp(buffer[i], "    Read\n") == 0){
            buffer[i] = "    scanf(\"%d\", &n);\n"; //Fix quotes
        }
        if(strcmp(buffer[i], "            BlankN\n") == 0){
            buffer[i] = "            n=0;\n";
        }
        if(strcmp(buffer[i], "    Shut\n") == 0){ //l == i
            buffer[i] = "   fclose(in_file);\n";
            //l = 1000;
        }
    }

    //print it to new .c file

    FILE* out_file = fopen("final.c","w");      
    for (int i=0; i<numLines; i++){
        fprintf(out_file,"%s", buffer[i]);
    }

    for(int i = 0; i < numLines; i++){
        free(buffer[i]);
    }
    

    //Close files and end
    fclose(in_file);
    fclose(out_file);
    return EXIT_SUCCESS;
}
