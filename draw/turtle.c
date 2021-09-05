#ifndef TURTLE_C
#define TURTLE_C
#include <math.h>
#include "line.c"

typedef struct {
  double x;
  double y;
  double angle;
} Turtle;


void initializeTurtle(Turtle *turtle, double x, double y, double angle);
void turnTurtle(Turtle *turtle, double angle);
Line moveTurtle(Turtle *turtle, double distance);

void initializeTurtle(Turtle *turtle, double x, double y, double angle) {
  turtle->x = x;
  turtle->y = y;
  turtle->angle = angle;
}

void turnTurtle(Turtle *turtle, double angle) {
  turtle->angle += angle;
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


#endif
