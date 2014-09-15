#include "nlang.h"

typedef struct __linkedlist {
  Node *node;
} _linkedlist;

LinkedList linkedlist_initialize();
Data linkedlist_get_next(LinkedList);
void linkedlist_free(LinkedList);
void linkedlist_add(LinkedList, Data);
void linkedlist_move_pos(LinkedList, int);
void linkedlist_validate(LinkedList);
void linkedlist_each_function(LinkedList, fptrEachFunc);
Node* node_initialize(int);
void node_free(Node*);

LinkedList linkedlist_initialize() {
  INIT_PTR(_linkedlist, list)
  malloc_s(list, _linkedlist, 1);
  list->node = node_initialize(0);
  return (LinkedList)list;
}

Node* node_initialize(int index) {
  INIT_PTR(Node, node)
  malloc_s(node, Node, 1);
  node->index = index;
  node->data = NULL;
  node->next = NULL;
  node->prev = NULL;
  return node;
}


Data linkedlist_get_next(LinkedList list) {
  if(list->node->next != NULL) {
    list->node = list->node->next;
    return list->node;
  } else {
    linkedlist_move_pos(list, 0);
    return NULL;
  }
}

void node_free(Node *node) {
  if(node == NULL) return;
  if(node->next != NULL) {
    node_free(node->next);
  }
  free_s(node);
}

void linkedlist_add(LinkedList list, Data data) {
	linkedlist_validate(list);
	Node* node = node_initialize(list->node->index + 1);
	node->data = data;
	node->prev = list->node;
	list->node->next = node;
	list->node = node;
}

void linkedlist_each_function(LinkedList list, fptrEachFunc func) {
	int save = list->node->index;
	linkedlist_move_pos(list, 0);
	while(1) {
		func(list->node);
    if(list->node->next == NULL) break;
    list->node = list->node->next;
	}
  linkedlist_move_pos(list, save);
}

void linkedlist_move_pos(LinkedList list, int index) {
	bool isNext = true;
	if(list->node->index == index) return;
  if(list->node->index > index) {
    isNext = false;
  }
  
	while(1) {
		if((isNext ? list->node->next : list->node->prev) == NULL) {
      debug_log("Error: Index Overflow: %d\n", index);
      abort();
    }
    list->node = isNext ? list->node->next : list->node->prev;
    if(list->node->index == index) return;
	}
}

void linkedlist_free(LinkedList list) {
	linkedlist_validate(list);
  linkedlist_move_pos(list, 0);
	node_free(list->node);
	free_s(list);
}


void linkedlist_validate(LinkedList list) {
  // insert check code...
}
