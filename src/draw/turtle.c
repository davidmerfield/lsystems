#include <math.h>
#include <stdio.h>
#include "turtle.h"
#include "turtleState.h"


void initializeTurtle(Turtle * turtle, double x, double y, double angle) {
  turtle->x = x;
  turtle->y = y;
  turtle->angle = angle;
  initializeTurtleStateStack(&turtle->stateStack, 0);
}

void freeTurtle(Turtle * turtle) {
  freeTurtleStateStack(&turtle->stateStack);
}

Line moveTurtle(Turtle *turtle, double distance) {
  Line line;
  line.x1 = turtle->x;
  line.y1 = turtle->y;
  turtle->x += distance*cos(turtle->angle);
  turtle->y += distance*sin(turtle->angle);
  line.x2 = turtle->x;
  line.y2 = turtle->y;
  return line;
}

void turnTurtle(Turtle *turtle, double angle) {
  turtle->angle += angle;
}

void setTurtleState(Turtle * turtle, TurtleState turtleState) {
  turtle->x = turtleState.x;
  turtle->y = turtleState.y;
  turtle->angle = turtleState.angle;
}

TurtleState getTurtleState(Turtle * turtle) {
  TurtleState state;
  state.x = turtle->x;
  state.y = turtle->y;
  state.angle = turtle->angle;
  return state;
}

void pushTurtleState(Turtle * turtle) {
  pushTurtleStateStack(&turtle->stateStack, getTurtleState(turtle));
}

void popTurtleState(Turtle * turtle) {
  setTurtleState(turtle, popTurtleStateStack(&turtle->stateStack));
}

