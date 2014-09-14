#include "nlang.h"

typedef struct _node{
  int index;
  Data data;
} Node;

typedef struct __linkedlist {
  Node *node;
  Node *next;
  Node *prev;
} _linkedlist;

typedef void (*fptrEachFunc)(Data);

LinkedList linkedlist_initialize();
Data linkedlist_get_next(LinkedList);
void linkedlist_free(LinkedList);
void linkedlist_add(LinkedList, Data);
void linkedlist_move_pos(LinkedList, int);
void linkedlist_validate(LinkedList);
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
  return node;
}

void linkedlist_add(LinkedList list, Data data) {
	linkedlist_validate(list);
	Node* node = node_initialize(list->node->index + 1);
	node->data = data;
	list->prev = list->node;
	list->next = node;
	list->node = node;
}

void linkedlist_each_function(LinkedList list, fptrEachFunc func) {
	//int save = list->node->index;
	linkedlist_move_pos(list, 0);
	while(list->node != NULL) {
		
	}
}

void linkedlist_move_pos(LinkedList list, int index) {
	bool isNext = true;
  
	if(list->node->index == index) return;
  if(list->node->index > index) isNext = false;
  
	while(1) {
		if((isNext ? list->next : list->prev) == NULL) {
      debug_log("Error: Index Overflow: %d", index);
      abort();
    }
    list->node = isNext ? list->next : list->prev;
    
    if(list->node->index == index) return;
	}
}

void linkedlist_free(LinkedList list) {
	linkedlist_validate(list);
	node_free(list->node);
	free_s(list);
}


void linkedlist_validate(LinkedList list) {
  // insert check code...
}
