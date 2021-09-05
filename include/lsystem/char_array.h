#ifndef CHAR_ARRAY_H
#define CHAR_ARRAY_H


typedef struct {
  char * array;
  size_t used;
  size_t size;
} CharArray;

void initCharArray(CharArray *a, size_t initialSize);
void insertCharArray(CharArray *a, char element);
void freeCharArray(CharArray *a);

#endif
