#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void appendFiles(char source[], char destination[])
{
    //pointers
    FILE *fp1, *fp2;
    
    // open files
    fp1 = fopen("final.txt", "r");
    fp2 = fopen("final_new_language.c", "w" );

    // file not found
    // Check for the case that either file was not found
    if(!fp1 || !fp2)
    {
        printf("Unable to open/" "detect file(s)\n");
        return;
    }

    char buf[100];

    //writing to new file
    fprintf(fp2, "\n");

    // writing from source file to new file
    while(!feof(fp1))
    {
        if(fgets(buf,sizeof(buf), fp1)) {
            fprintf(fp2, "%s", buf);
        }
    }
}

int main(int argc, char* argv[argc+1])
{

    char source[] = "final.txt";
    char destination[] = "final_new_language.c";

    appendFiles(source, destination);

    return 0;
    

}
