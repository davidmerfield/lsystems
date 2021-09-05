#include <stdio.h>
#include <stdlib.h>
#include "rules_parser.h"
#include "rules.h"


Rule handle_line(char line[256]);

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

