#include <stdlib.h>
#include <math.h>
#include "line.h"


void initializeLineArray(LineArray *a, size_t initialSize) {
  a->array = malloc(initialSize * sizeof(Line));
  a->used = 0;
  a->size = initialSize;
}

void insertLineArray(LineArray *a, Line element) {
  if (a->used == a->size) {
    if (a->size == 0) {
      a->size = 1;
    } else {
      a->size *= 2;
    }
    a->array = realloc(a->array, a->size * sizeof(Line));
  }
  a->array[a->used] = element;

  double elementMinX = fmin(element.x1, element.x2);
  double elementMinY = fmin(element.y1, element.y2);
  double elementMaxX = fmax(element.x1, element.x2);
  double elementMaxY = fmax(element.y1, element.y2);

  a->minX = a->used ? fmin(a->minX, elementMinX) : elementMinX;
  a->minY = a->used ? fmin(a->minY, elementMinY) : elementMinY;
  a->maxX = a->used ? fmax(a->maxX, elementMaxX) : elementMaxX;
  a->maxY = a->used ? fmax(a->maxY, elementMaxY) : elementMaxY;

  a->used++;
}

/* Translate all lines in `a` such that the bottom-left coordinate is <0,0>. */
void renormalizeLineArray(LineArray *a, double maxX, double maxY) {
  if (!a->used) {
    return;
  }

  double aSpanX = a->maxX - a->minX;
  double aSpanY = a->maxY - a->minY;
  double scaleFactor =
    (maxY / maxX) < (aSpanY / aSpanX)
      ? maxY / aSpanY
      : maxX / aSpanX;

  for (int i = 0; i < a->size; i++) {
    a->array[i].x1 = scaleFactor * (a->array[i].x1 - a->minX);
    a->array[i].y1 = scaleFactor * (a->array[i].y1 - a->minY);
    a->array[i].x2 = scaleFactor * (a->array[i].x2 - a->minX);
    a->array[i].y2 = scaleFactor * (a->array[i].y2 - a->minY);
  }

  a->maxX = scaleFactor * (a->maxX - a->minX);
  a->maxY = scaleFactor * (a->maxY - a->minY);
  a->minX = 0;
  a->minY = 0;
}

void freeLineArray(LineArray *a) {
  free(a->array);
  a->array = NULL;
  a->used = a->size = 0;
}

