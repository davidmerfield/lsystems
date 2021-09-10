#include <stdio.h>
#include <unistd.h>
#include "math.h"
#include "turtle.h"
#include "line.h"
#include "svg.h"
#include "turtleState.h"


const double FORWARD = 1;

int main(int argc, char *argv[]) {

  if (argc != 4) {
    printf("Usage: ./draw <max-width> <max_height> <angle> < input\n");
    return 1;
  }
  double maxWidth;
  double maxHeight;
  double angle;
  sscanf(argv[1], "%lf", &maxWidth);
  sscanf(argv[2], "%lf", &maxHeight);
  sscanf(argv[3], "%lf", &angle);

  double angle_r = (angle / 360) * (2 * M_PI);
  double angle_l = -1 * angle_r;

  Turtle turtle;
  LineArray lines;
  initializeLineArray(&lines, 0);
  initializeTurtle(&turtle, 0, 0, 0);

  char buf[1];
  while(read(0, buf, sizeof(buf))>0) {
    const char instr = buf[0];

    if (instr == 'F') {
      insertLineArray(&lines, moveTurtle(&turtle, FORWARD));
    } else if (instr == '+') {
      turnTurtle(&turtle, angle_l);
    } else if (instr == '-') {
      turnTurtle(&turtle, angle_r);
    } else if (instr == '[') {
      pushTurtleState(&turtle);
    } else if (instr == ']') {
      popTurtleState(&turtle);
    }
  }

  renormalizeLineArray(&lines, maxWidth, maxHeight);

  printHtmlOpen();
  /* If we don't add a bit of padding around the edges, our curve gets cut off. */
  printViewBoxOpen(-2, -2, lines.maxX + 4, lines.maxY + 4);
  // printf("%d\n", lines.maxDepth);
  for (int i = 0; i < lines.used; i++) {
    printLine(lines.array[i], lines.maxDepth);
  }
  printViewBoxClose();
  printHtmlClose();

  freeLineArray(&lines);

  return 0;
}
