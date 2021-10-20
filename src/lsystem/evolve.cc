#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "evolve.h"
#include "char_array.h"
#include "rules_parser.h"


char * evolve (char * axiom, RuleArray list_of_rules) {
  CharArray result;
  initCharArray(&result, 0);

  for (char * axiom_char = axiom; *axiom_char != '\0'; axiom_char++) {
    for (int rule_i = 0; rule_i < list_of_rules.used; rule_i++) {
      if (list_of_rules.array[rule_i].key == *axiom_char) {
        for (
          char * rule_char = list_of_rules.array[rule_i].value;
          *rule_char != '\0'; 
          rule_char++) {
          insertCharArray(&result, *rule_char);
        }
      }
    }
  }
  insertCharArray(&result, '\0');
  return result.array;
}

