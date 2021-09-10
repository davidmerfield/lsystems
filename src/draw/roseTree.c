
typedef struct {
  

} RoseTree;
typedef struct {
  

} TreeNode;
typedef struct {
  TreeNode * array;
  size_t used;
  size_t size;
} TreeNodeArray;

void initializeTreeNodeArray(TreeNodeArray *a, size_t initialSize);
void freeTreeNodeArray(TreeNodeArray *a);
void insertTreeNodeArray(TreeNodeArray *a, TreeNode element);

void initializeTreeNodeArray(TreeNodeArray *a, size_t initialSize) {
  a->array = malloc(initialSize * sizeof(TreeNode));
  a->used = 0;
  a->size = initialSize;
  a->maxDepth = 0;
}

void freeTreeNodeArray(TreeNodeArray *a) {
  free(a->array);
  a->array = NULL;
  a->used = a->size = 0;
}

void insertTreeNodeArray(TreeNodeArray *a, TreeNode element) {
  if (a->used == a->size) {
    if (a->size == 0) {
      a->size = 1;
    } else {
      a->size *= 2;
    }
    a->array = realloc(a->array, a->size * sizeof(TreeNode));
  }
  a->array[a->used] = element;
}

