// Two goals: see why containing functionality in an object is powerful for creating software, and see why we need pointers to do it.  

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <time.h>

typedef struct {
	int x; 
	int y; 
	int r; 
	int g; 
	int b; 
} enemy; 

void enemy_maybe_move(enemy* e) {
	if(rand() % 2 == 0) {
		e->x++; 
	}
}

int main(int argc, char* argv[argc + 1]) {
	struct winsize ws; 
	ioctl(STDOUT_FILENO, TIOCGWINSZ, &ws); 

	for(int i = 0; i < ws.ws_col * ws.ws_row; i++) {
		printf("."); 
	}

	enemy* enemies[ws.ws_row]; 
	for(int i = 0; i < ws.ws_row; i++) {
		enemies[i] = (enemy*)malloc(sizeof(enemy)); 
		enemies[i]->x = 1; 
		enemies[i]->y = i + 1; 
		enemies[i]->r = i * 255 / ws.ws_row; 
		enemies[i]->g = 250 - i * 255 / ws.ws_row; 
		enemies[i]->b = 0; 
	}

	srand(time(NULL)); 

	while(1) {
		for(int i = 0; i < ws.ws_row; i++) {
			printf("\033[%d;%dH\033[48;2;%d;%d;%dm \033[0m", enemies[i]->y, enemies[i]->x, enemies[i]->r, enemies[i]->g, enemies[i]->b); 
			enemy_maybe_move(enemies[i]); 
		}

		fflush(stdout); 
		usleep(200000); 
	}; 

	return EXIT_SUCCESS; 
}