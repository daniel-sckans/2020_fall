#include<stdio.h>
#include<stdlib.h>

int main()
{
    in ch;
    FILE *fp,*fq;
    fp=fopen("calculator.c")
    fq=fopen("backup.c","w");
    if(fp==NULL)
        printf("file does not exist..");
    else
        while((ch=fgetc(fp))!=EOF)
        {
                fputc(ch,fq);
        }
    printf("File Copied...:");
    return 0;
}
