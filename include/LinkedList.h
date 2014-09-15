#ifndef __LINKEDLIST_H__
#define __LINKEDLIST_H__
typedef void *Data;

typedef struct _node{
  int index;
  Data data;
  void *next;
  void *prev;
} Node;
typedef struct __linkedlist *LinkedList;
typedef void (*fptrEachFunc)(Node*);

extern LinkedList linkedlist_initialize();
extern Data linkedlist_get_next(LinkedList);
extern void linkedlist_free(LinkedList);
extern void linkedlist_add(LinkedList, Data);
extern void linkedlist_move_pos(LinkedList, int);
extern void linkedlist_each_function(LinkedList, fptrEachFunc);
extern int linkedlist_errno;

#endif
