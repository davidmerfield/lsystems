#include <stdio.h>
#include "evolve.h"
#include "rules_parser.h"


int main(int argc, char *argv[]) {
  if (argc != 4) {
    printf("Usage: ./l_system <axiom> <.rule file> <iterations>\n");
    return 1;
  }

  char * axiom = argv[1];
  char * rulefilename = argv[2];
  int iterations;
  sscanf(argv[3], "%d", &iterations);

  RuleArray list_of_rules = parse_rules(rulefilename);
  for (int i = 0; i < iterations; i++)
    axiom = evolve(axiom, list_of_rules);
  printf("%s\n", axiom);
  freeRuleArray(&list_of_rules);

  return 0;
}
