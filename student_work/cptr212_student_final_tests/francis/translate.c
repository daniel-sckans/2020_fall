#include <stdio.h>
#include <stdlib.h>

void appendFiles(char src[], char dest[])
{
    FILE *ffp, *sfp;
 
    // We only want to read this file.  
    ffp = fopen(src, "r");

    // Rewrite the file from scratch, also able to read.  
    sfp = fopen(dest, "w+");
 
    // Or operator because either failure should cause the program to fail.  
    if (!ffp || !sfp) {
        printf("Unable to open/" "detect file(s)\n");
        return;
    }
 
    char buf[32] = {0}; 
 
    while(!feof(ffp)) {

        // If fgets doesn't get anything, we shouldn't print the output (fgets returns the number of characters it wrote).  
        if(fgets(buf, sizeof(buf), ffp)) {
            fprintf(sfp, "%s", buf);
        }
    }
 
    rewind(sfp);
 
    // Stop if we're at the end of file, or if fgets got no characters.  
    while (!feof(sfp) && fgets(buf, sizeof(buf), sfp)) {
        printf("%s", buf);
    }
}
 

int main(int argc, char* argv[argc + 1])
{
    char src[] = "file.wat", dest[] = "count.c";
 
    appendFiles(src, dest);
 
    return EXIT_SUCCESS;
}
