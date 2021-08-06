#include <stdio.h>
#include "algae.c"

int main( int argc, char *argv[] ) {

  if ( argc == 2 ) {
    int iterations;
    sscanf(argv[1], "%d", &iterations);
    hello(iterations);
  } else if ( argc > 2 ) {
    printf("Too many arguments supplied.\n");
  } else {
    printf("One argument expected.\n");
  }

  return 0;
}