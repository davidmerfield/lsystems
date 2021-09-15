#ifndef LINE_H
#define LINE_H
#include <stddef.h>


typedef struct {
  double x1;
  double y1;
  double x2;
  double y2;
  int depth;
} Line;

typedef struct {
  Line * array;
  size_t used;
  size_t size;

  double minX;
  double minY;
  double maxX;
  double maxY;
  int maxDepth;
} LineArray;

void initializeLineArray(LineArray *a, size_t initialSize);
void insertLineArray(LineArray *a, Line element);
void freeLineArray(LineArray *a);
void renormalizeLineArray(LineArray *a, double maxX, double maxY);

#endif
