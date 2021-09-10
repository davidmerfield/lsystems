#ifndef SVG_H
#define SVG_H
#include "line.h"


void printLine(const Line line, const int maxDepth);
void printViewBoxOpen(double minX, double minY, double xSpan, double ySpan);
void printViewBoxClose();
void printHtmlOpen();
void printHtmlClose();

#endif
