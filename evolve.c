#ifndef EVOLVE_C
#define EVOLVE_C 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "rules_parser.c"

typedef struct {
  char * array;
  size_t used;
  size_t size;
} CharArray;

void initCharArray(CharArray *a, size_t initialSize);
void insertCharArray(CharArray *a, char element);
void freeCharArray(CharArray *a);

char * evolve ( char * axiom, RuleArray list_of_rules) {

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


void initCharArray(CharArray *a, size_t initialSize) {
  a->array = malloc(initialSize * sizeof(char));
  a->used = 0;
  a->size = initialSize;
}

void insertCharArray(CharArray *a, char element) {
  // a->used is the number of used entries, because 
  // a->array[a->used++] updates a->used only *after* 
  // the array has been accessed.
  // Therefore a->used can go up to a->size
  if (a->used == a->size) {
    a->size *= 2;
    a->array = realloc(a->array, a->size * sizeof(char));
  }
  a->array[a->used++] = element;
}

void freeCharArray(CharArray *a) {
  free(a->array);
  a->array = NULL;
  a->used = a->size = 0;
}


#endif
