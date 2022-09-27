#include "LL_dupla.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct _double_node 
{
    int val;
    struct _double_node *next;
    struct _double_node *prev;
}DoubleNode, Node;

typedef struct _double_linked_list
{
    Node *begin;
    Node *end;
    size_t size;
}DoubleLinkedList, List;

Node *Node_create(int val)
{
    Node *node = (Node *) calloc (1, sizeof (Node));
    node->next = NULL;
    node->prev = NULL;
    node->val = val;
    return node; 
}

List *List_create()
{
    List *list = (List *) calloc (1, sizeof (List));
    list->begin = NULL;
    list->end = NULL;
    list->size = 0;
    return list;
}

bool List_is_empty(const DoubleLinkedList *list)
{
    return list->size == 0;
}

void List_Destroy(DoubleLinkedList **list)
{
    List *l = *list;

    Node *p = l->begin;
    Node *aux = NULL;

    while(p != NULL)
    {
        aux = p;
        p = p->next;
        free(aux);
    }
    free(l);

    *list = NULL;
}

void List_add_first(DoubleLinkedList *list, int val)
{
    Node *p = Node_create(val);

    if(List_is_empty(list))
    {
        list->end = p;
    }

    else
    {
        p->next = list->begin;
        list->begin->prev = p;
    }

    list->begin = p;
    list->size++;
}

