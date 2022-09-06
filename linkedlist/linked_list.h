#ifndef LINKED_LIST_H
#define LINKED_LIST_H

typedef struct _snode SNode;
typedef struct _slinked_list LinkedList;

SNode *SNode_create(int val);

LinkedList *LinkedList_create();

void add_first(LinkedList *L, int val);

void add_last(LinkedList *L, int val);

void print_LL(LinkedList *L);

#endif // !LINKED_LIST_H