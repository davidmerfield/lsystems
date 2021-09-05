#ifndef RULES_H
#define RULES_H


typedef struct Rule {
  char key;
  char * value;
} Rule;

typedef struct {
  Rule * array;
  size_t used;
  size_t size;
} RuleArray;

void initRuleArray(RuleArray *a, size_t initialSize);
void insertRuleArray(RuleArray *a, Rule element);
void freeRuleArray(RuleArray *a);


#endif
