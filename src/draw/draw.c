#include <stdio.h>
#include <unistd.h>
#include "math.h"
#include "turtle.h"
#include "line.h"
#include "svg.h"
#include "turtleState.h"


const double FORWARD = 1;
const double ANGLE_L = -1*M_PI_2;
const double ANGLE_R = M_PI_2;

int main(int argc, char *argv[]) {

  if (argc != 3) {
    printf("Usage: ./draw_koch <max-width> <max_height> < input\n");
    return 1;
  }
  double maxWidth;
  double maxHeight;
  sscanf(argv[1], "%lf", &maxWidth);
  sscanf(argv[2], "%lf", &maxHeight);

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
      turnTurtle(&turtle, ANGLE_L);
    } else if (instr == '-') {
      turnTurtle(&turtle, ANGLE_R);
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
  for (int i = 0; i < lines.used; i++) {
    printLine(lines.array[i]);
  }
  printViewBoxClose();
  printHtmlClose();

  freeLineArray(&lines);

  return 0;
}
