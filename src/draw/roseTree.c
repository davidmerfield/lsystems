#include <stdlib.h>

typedef struct DirectedGraphNodeArray DirectedGraphNodeArray;
typedef struct DirectedGraph DirectedGraph;
typedef struct DirectedGraphNode DirectedGraphNode; 

struct DirectedGraphNodeArray {
  DirectedGraphNode * * array;
  size_t used;
  size_t size;
};

struct DirectedGraph {
  DirectedGraphNodeArray allNodes;
};

struct DirectedGraphNode {
  DirectedGraphNodeArray children;
  double x;
  double y;
  int trunkiness;
};

void addEdge (DirectedGraph * graph, double x1, double y1, double x2, double y2);
DirectedGraphNode * getNodeAtPosition (DirectedGraph * graph, double x, double y);
void initializeDirectedGraphNodeArray(DirectedGraphNodeArray *a, size_t initialSize);
void freeDirectedGraphNodeArray(DirectedGraphNodeArray *a, int freeElements);
void insertDirectedGraphNodeArray(DirectedGraphNodeArray *a, DirectedGraphNode * element);
DirectedGraphNode * createDirectedGraphNode(DirectedGraph * graph, double x, double y);

DirectedGraphNode * getNodeAtPosition (DirectedGraph * graph, double x, double y) {
  for (int i = 0;i < graph->allNodes.used; i++) {
    if (graph->allNodes.array[i]->x == x && graph->allNodes.array[i]->y == y)
      return graph->allNodes.array[i];
  }

  return NULL;
}

void addEdge (DirectedGraph * graph, double x1, double y1, double x2, double y2) {
  DirectedGraphNode * nodeAtStart = getNodeAtPosition(graph, x1, y1);  
  DirectedGraphNode * nodeAtEnd = getNodeAtPosition(graph, x2, y2);

  if (nodeAtStart == NULL) nodeAtStart = createDirectedGraphNode(graph, x1, y1);
  if (nodeAtEnd == NULL) nodeAtEnd = createDirectedGraphNode(graph, x2, y2);

  insertDirectedGraphNodeArray(&nodeAtStart->children, nodeAtEnd);
}


DirectedGraphNode * createDirectedGraphNode(DirectedGraph * graph, double x, double y) {
  DirectedGraphNode * a = malloc(sizeof (DirectedGraphNode));
  insertDirectedGraphNodeArray(&graph->allNodes, a);
  initializeDirectedGraphNodeArray(&a->children, 0);
  a->x = x;
  a->y = y;
  a->trunkiness = 0;
  return a;
}

void initializeDirectedGraphNodeArray(DirectedGraphNodeArray *a, size_t initialSize) {
  a->array = malloc(initialSize * sizeof(DirectedGraphNode *));
  a->used = 0;
  a->size = initialSize;
}

void freeDirectedGraphNodeArray(DirectedGraphNodeArray *a, int freeElements) {
  if (freeElements) {
    for (int i = 0; i < a->used;i++) {
      free(&a->array[i]);
    }
  }
  free(a->array);
  a->array = NULL;
  a->used = a->size = 0;
}

void insertDirectedGraphNodeArray(DirectedGraphNodeArray *a, DirectedGraphNode * element) {
  if (a->used == a->size) {
    if (a->size == 0) {
      a->size = 1;
    } else {
      a->size *= 2;
    }
    a->array = realloc(a->array, a->size * sizeof(DirectedGraphNode *));
  }
  a->array[a->used++] = element;
}

