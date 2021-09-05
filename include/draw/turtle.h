#ifndef TURTLE_H
#define TURTLE_H
#include "line.h"


typedef struct {
  double x;
  double y;
  double angle;
} Turtle;


void initializeTurtle(Turtle *turtle, double x, double y, double angle);
void turnTurtle(Turtle *turtle, double angle);
Line moveTurtle(Turtle *turtle, double distance);

#endif
