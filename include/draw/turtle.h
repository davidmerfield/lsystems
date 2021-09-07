#ifndef TURTLE_H
#define TURTLE_H
#include "line.h"
#include "turtleState.h"

typedef struct {
  double x;
  double y;
  double angle;
  TurtleStateStack stateStack;
} Turtle;

void initializeTurtle(Turtle * turtle, double x, double y, double angle);
void freeTurtle(Turtle * turtle);

Line moveTurtle(Turtle * turtle, double distance);
void turnTurtle(Turtle * turtle, double angle);

void setTurtleState(Turtle * turtle, TurtleState turtleState);
TurtleState getTurtleState(Turtle * turtle);
void pushTurtleState(Turtle * turtle);
TurtleState popTurtleState(Turtle * turtle);

#endif
