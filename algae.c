#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char * evolve ( char * axiom);

void hello(int iterations) {

  char *axiom = "A";
  char *result = malloc((strlen(axiom) + 1) * sizeof(char));

  strcpy(result, axiom);

  for (int i = 0; i < iterations; i++) {
    char * tmp = evolve(result);
    free(result);
    result = tmp;
  }

  printf("result: %s\n", result);

}

char * evolve ( char * axiom) {

  int numAs = 0;
  int numBs = 0;

  for (char *character = axiom; *character != '\0'; character++) {
    if (*character == 'A') {
      numAs++;
    } else if (*character == 'B') {
      numBs++;
    }
  }

  int newLen = 2 * numAs + numBs;

  char * newAxiom = malloc((newLen + 1) * sizeof(char));
  int charsAdded = 0;
  for (char *character = axiom; *character != '\0'; character++)
  {
    if (*character == 'A') {
      newAxiom[charsAdded] = 'A';
      charsAdded++;
      newAxiom[charsAdded] = 'B';
      charsAdded++;
    } else if (*character == 'B') {
      newAxiom[charsAdded] = 'A';
      charsAdded++;
    }

  }

  newAxiom[charsAdded] = '\0';

  return newAxiom;
}