#include <stdio.h>
#include <string.h>
#include <sys/mman.h>
#include <fcntl.h>
#include "server.h"

void sample(FILE* socket_stream, char uri[128]) {

    if(strstr(uri, "sample/bb.jpg")) {
        fprintf(stdout, "Send sample image.\n"); 

        FILE* bb = fopen("assets/bb.jpg", "r"); 
        fseek(bb, 0, SEEK_END); 
        int file_size = ftell(bb); 
        fseek(bb, 0, SEEK_SET); 
        fprintf(stdout, "jpg size: %d, currently at position: %ld\n", file_size, ftell(bb)); 

        fprintf(socket_stream, "HTTP/1.1 200 OK"); 
        fprintf(socket_stream, "Content-length: %d\n", file_size); 
        fprintf(socket_stream, "\n"); 

        while(!feof(bb)) {
            fputc(fgetc(bb), socket_stream); 
        }

        // for(int i = 0; i < file_size; i++) {
        //     char c = fgetc(bb); 
        //     fputc(c, socket_stream);
        // }
        fflush(socket_stream); 
        fclose(bb); 

        return; 
    }  

    char* response_payload = "<!DOCTYPE html><html><head><title>Test Server</title></head><body><style>* { background-color: #00f; }</style><h1>Headline!</h1><script>document.querySelector('h1').innerText = 'This is the sample page!!';</script><img src='sample/bb.jpg' width='500' height='300'></body></html>";     
    fprintf(socket_stream, "HTTP/1.1 200 OK"); 
    fprintf(socket_stream, "Content-length: %lu\n", strlen(response_payload)); 
    fprintf(socket_stream, "\n"); 

    // This is the body of our response.  
    fprintf(socket_stream, "%s", response_payload); 
    fflush(socket_stream); 
}