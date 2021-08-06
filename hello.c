#include <stdio.h>
#include "algae.c"

int main( int argc, char *argv[] ) {

  if ( argc == 3 ) {
    int iterations;
    sscanf(argv[1], "%d", &iterations);
    hello(iterations, argv[2]);
  } else if ( argc > 3 ) {
    printf("Too many arguments supplied.\n");
  } else {
    printf("Two arguments expected.\n");
  }

  return 0;
}