#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[]) {
  
 int a = 1;
 int b = 1;
 int c = 1;

  printf("Enter a number to calculate its factorial\n");
  
  scanf("%d", &b);
  for (a = 1; a <= b; a++)
    c = c * a;
 
  printf("Factorial of %d = %d\n", b, c);
 
  return EXIT_SUCCESS;
}
