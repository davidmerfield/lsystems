#ifndef RULES_PARSER_C
#define RULES_PARSER_C 

#include <stdio.h>
#include <stdlib.h>

typedef struct Rule {
  char key;
  char * value;
} Rule;

typedef struct {
  Rule * array;
  size_t used;
  size_t size;
} RuleArray;


Rule handle_line(char line[256]);
void initRuleArray(RuleArray *a, size_t initialSize);
void insertRuleArray(RuleArray *a, Rule element);
void freeRuleArray(RuleArray *a);

RuleArray parse_rules(const char * fileName) {
  FILE* file = fopen(fileName, "r");
  char line[256];

  RuleArray list_of_rules;

  initRuleArray(&list_of_rules, 1);

  while (fgets(line, sizeof(line), file)) {
    insertRuleArray(&list_of_rules, handle_line(line));
  }

  fclose(file);

  return list_of_rules;
}

Rule handle_line(char line[256]) {
  char key = line[0];
  int value_len = 0;

  for (int i = 2; i < 256; i++) {
    if (line[i] == '\n') {
      break;
    } else {
      value_len++;
    }
  }

  char * value = malloc(value_len);

  for (int x = 0; x < value_len; x++) {
    value[x] = line[x + 2];
  }

  Rule new_rule;
  new_rule.key = key;
  new_rule.value = value;

  return new_rule;
}

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


#endif
