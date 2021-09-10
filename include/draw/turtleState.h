#ifndef TURTLE_STATE_H
#define TURTLE_STATE_H
#include <stdlib.h>

typedef struct {
  double x;
  double y;
  double angle;
  int depth;
} TurtleState;

typedef struct {
  int size;
  int used;
  TurtleState * array;
} TurtleStateStack;

void initializeTurtleStateStack(TurtleStateStack * turtle, size_t initialSize);
void freeTurtleStateStack(TurtleStateStack * turtleStateStack);

void pushTurtleStateStack(TurtleStateStack * turtle, TurtleState turtleState);
TurtleState popTurtleStateStack(TurtleStateStack * turtle);


#endif
