#include <stdio.h>
#include "svg.h"


void printLine(const Line line) {
  printf("<line x1=\"%f\" y1=\"%f\" x2=\"%f\" y2=\"%f\" stroke=\"black\" />\n",
      line.x1,
      line.y1,
      line.x2,
      line.y2);
}

void printViewBoxOpen(double minX, double minY, double xSpan, double ySpan) {
  printf("<svg viewBox=\"%f %f %f %f\" width=\"50%%\">\n", minX, minY, xSpan, ySpan);
}

void printViewBoxClose() {
  printf("</svg>\n");
}

void printHtmlOpen() {
  printf("<!DOCTYPE html>\n<html>\n<body>\n");
}
void printHtmlClose() {
  printf("</body>\n</html>\n");
}

