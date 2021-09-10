#include <stdio.h>
#include "svg.h"


void printLine(const Line line, const int maxDepth) {
  
  double strokeWidth = 1 + ((double)maxDepth - (double)line.depth);

  const double maxWidth = 2.0;
  const double minWidth = 1.0;

  const double scaleFactor = maxWidth / (double)maxDepth;

  strokeWidth = (scaleFactor * strokeWidth) + 1;

  printf("<line x1=\"%f\" y1=\"%f\" x2=\"%f\" y2=\"%f\" stroke=\"black\" stroke-width=\"%f\" />\n",
      line.x1,
      line.y1,
      line.x2,
      line.y2,
      strokeWidth);
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

