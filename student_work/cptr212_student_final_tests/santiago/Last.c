#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void newlang(){    

    //open the files to use further in the prorgam.
    FILE *wrd1 = fopen("newLang.mex","r");
    FILE *wrd2 = fopen("destino.c","w");

    // If either file failed to open, return.  
    if (!wrd1 || !wrd2){
        printf("File not able to open, pls retry");
        return;
    }

    //THIS will write
    char path[100];   
    while(!feof(wrd1)) {

        // fgets returns the number of characters read; only proceed if some characters were read.  
        if(fgets(path, sizeof(path), wrd1)) {

            // If the test string is present in the buffer, print the replacement text; if not, print the buffer.  
            fprintf(wrd2, "%s", strstr(path, "/paste/") ? "printf(\"This is an example of replacing source code\");" : path);
        }
    }
}

int main(){
    newlang();

    return 0;
}


