#include <stdio.h>
#include "evolve.c"
#include "rules_parser.c"

int main( int argc, char *argv[] ) {

  if ( argc == 4 ) {
    char * axiom = argv[1];
    char * rulefilename = argv[2];
    int iterations;
    sscanf(argv[3], "%d", &iterations);
    RuleArray list_of_rules = parse_rules(rulefilename);
    for (int i = 0; i < iterations; i++)
      axiom = evolve(axiom, list_of_rules);
    printf("%s\n", axiom);
    freeRuleArray(&list_of_rules);

  } else if ( argc > 4 ) {
    printf("Too many arguments supplied.\n");
  } else {
    printf("Two arguments expected.\n");
  }

  return 0;
}