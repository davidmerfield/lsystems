#include <stdlib.h>
#include "rules.h"


void initRuleArray(RuleArray *a, size_t initialSize) {
  a->array = malloc(initialSize * sizeof(Rule));
  a->used = 0;
  a->size = initialSize;
}

void insertRuleArray(RuleArray *a, Rule element) {
  // a->used is the number of used entries, because 
  // a->array[a->used++] updates a->used only *after* 
  // the array has been accessed.
  // Therefore a->used can go up to a->size
  if (a->used == a->size) {
    if (a->size == 0) {
      a->size = 1;
    } else {
      a->size *= 2;
    }
    a->array = realloc(a->array, a->size * sizeof(Rule));
  }
  a->array[a->used++] = element;
}

void freeRuleArray(RuleArray *a) {
  free(a->array);
  a->array = NULL;
  a->used = a->size = 0;
}

