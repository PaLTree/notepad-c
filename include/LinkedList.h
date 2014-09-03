typedef void *Data;

typedef struct _linkedlist *LinkedList;

extern LinkedList linkedlist_initialize();
extern Data linkedlist_get_from_index(LinkedList, int);
extern Data linkedlist_get_next(LinkedList);
extern void linkedlist_free(LinkedList);
extern void linkedlist_set_index(LinkedList, int, Data);
extern void linkedlist_set(LinkedList, Data);

extern int linkedlist_errno;

