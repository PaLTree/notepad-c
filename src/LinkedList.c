#include "nlang.h"

typedef struct {
  int index;
  Data data;
  Node *next;
  Node *prev;
} Node;

struct _linkedlist {
  int current;
  Node *node;
};

LinkedList linkedlist_initialize();
Data linkedlist_get_from_index(LinkedList, int);
Data linkedlist_get_next(LinkedList);
void linkedlist_free(LinkedList);
void linkedlist_set_index(LinkedList, int, Data);
void linkedlist_set(LinkedList, Data);
Node* node_initialize(int);

int linkedlist_errno;

LinkedList linkedlist_initialize() {
  LinkedList *list;
  list = (LinkedList) malloc(sizeof(_linkedlist));
  list->current = 0;
  list->node = node_initialize(0);
  return list;
}

Node* node_initialize(int index) {
  Node* node;
  node = (Node*) malloc(sizeof(Node));
  node->index = index;
  node->data = NULL;
  node->next = NULL;
  node->prev = NULL;
  return node;
}

void linkedlist_validate(LinkedList list) {
  assert(list->current != list->node->index);
}
