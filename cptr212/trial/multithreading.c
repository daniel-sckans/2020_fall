#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>

typedef struct {
    char payload; 
    pthread_mutex_t mtx; 
    pthread_cond_t cv; 
} shared_state_t; 

void* thread_printf(void* arg) {
    shared_state_t * shared_state = (shared_state_t*)arg; 
    if(!shared_state->payload) {
        pthread_mutex_lock(&shared_state->mtx); 
        pthread_cond_wait(&shared_state->cv, &shared_state->mtx); 
        pthread_mutex_unlock(&shared_state->mtx); 
        printf("This is the variable: %c\n", shared_state->payload); 
    }
    return NULL; 
}

int main(int argc, char* argv[argc+1]) {

    // Shared state init.  
    shared_state_t shared_state; 
    shared_state.payload = '\0'; 
    pthread_mutex_init(&shared_state.mtx, NULL); 
    pthread_cond_init(&shared_state.cv, NULL); 

    // POSIX threads init.  
    pthread_t pthreads[2]; 
    int err = pthread_create(&pthreads[0], NULL, thread_printf, &shared_state); 
    err += pthread_create(&pthreads[1], NULL, thread_printf, &shared_state); 
    
    // Output when the main function continues.  
    printf("Please now input the thing: "); 
    shared_state.payload = getchar(); 
    // pthread_cond_signal(&shared_state.cv); 
    // pthread_cond_signal(&shared_state.cv); 
    pthread_cond_broadcast(&shared_state.cv); 

    // Wait for the pthreads.  
    err += pthread_join(pthreads[0], NULL); 
    err += pthread_join(pthreads[1], NULL); 

    // Release the shared state memory.  
    pthread_mutex_destroy(&shared_state.mtx); 
    pthread_cond_destroy(&shared_state.cv); 

    // Hallelujah.  
    return err; 
}