#include "turtleState.h"


void initializeTurtleStateStack(TurtleStateStack * a, size_t initialSize) {
  a->array = malloc(initialSize * sizeof(TurtleState));
  a->used = 0;
  a->size = initialSize;
}

void freeTurtleStateStack(TurtleStateStack * a) {
  free(a->array);
  a->array = NULL;
  a->used = a->size = 0;
}

void pushTurtleStateStack(TurtleStateStack * a, TurtleState element) {
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
    a->array = realloc(a->array, a->size * sizeof(TurtleState));
  }
  a->array[a->used++] = element;
}

TurtleState popTurtleStateStack(TurtleStateStack * a) {
  if (!a->used) {
    exit(1);
  }
  return a->array[--a->used];
}

