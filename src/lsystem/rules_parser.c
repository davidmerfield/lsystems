#include <stdio.h>
#include <stdlib.h>
#include "rules_parser.h"
#include "rules.h"


int handle_line(char line[256], Rule * new_rule);

RuleArray parse_rules(const char * fileName) {
  FILE* file = fopen(fileName, "r");
  char line[256];

  RuleArray list_of_rules;

  initRuleArray(&list_of_rules, 1);

  while (fgets(line, sizeof(line), file)) {

    Rule new_rule;

    int result = handle_line(line, &new_rule);

    if (result) {
      insertRuleArray(&list_of_rules, new_rule);
    } 
  }

  fclose(file);

  return list_of_rules;
}

int handle_line(char line[256], Rule * new_rule) {

  char key = line[0];

  if (key == EOF || key == '\n' || key == '\r') {
    return 0;
  }

  if (line[1] != ':') {
    return 0;
  }

  int value_len = 0;

  for (int i = 2; i < 256; i++) {
    if (line[i] == '\n' || line[i] == '\r' || line[i] == EOF) {
      break;
    } else if (i < 255) {
      value_len++;
    } else {
      return 0;
    }
  }

  if (value_len == 0){
    return 0;
  }

  char * value = malloc(value_len + 1);

  for (int x = 0; x < value_len; x++) {
    value[x] = line[x + 2];
  }

  value[value_len] = '\0';
  
  new_rule->key = key;
  new_rule->value = value;

  return 1;
}

