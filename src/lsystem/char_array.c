#include <stdlib.h>
#include <string.h>
#include "char_array.h"


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
    if (a->size == 0) {
      a->size = 1;
    } else {
      a->size *= 2;
    }
    a->array = realloc(a->array, a->size * sizeof(char));
  }
  a->array[a->used++] = element;
}

void freeCharArray(CharArray *a) {
  free(a->array);
  a->array = NULL;
  a->used = a->size = 0;
}

