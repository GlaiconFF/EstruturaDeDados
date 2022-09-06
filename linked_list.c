#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

// exercicio fim do mes: lista ordenada

typedef struct _snode
{
    int val;
    struct _snode *next;
} SNode;

typedef struct _slinked_list
{
    SNode *begin;
    int size; // qts elementos existem na linkedlist
} LinkedList;

SNode *SNode_create(int val)
{ 
    SNode *snode = (SNode*) calloc(1, sizeof(SNode));
    snode->val = val;
    snode->next = NULL;
    return snode;
}

LinkedList *LinkedList_create()
{
    LinkedList *linked_list = (LinkedList*) calloc(1, sizeof(LinkedList));
    linked_list->begin = NULL;
    return linked_list;
}

void add_first(LinkedList *L, int val)
{
    SNode *p = SNode_create(val);
    p->next = L->begin;
    L->begin = p;
    L->size++;
}

void add_last(LinkedList *L, int val)
{
    SNode *p = SNode_create(val);
    // se a linkedlist estiver vazia
    if(L->begin == NULL)
    {
        L->begin = p;
    }
    else
    {
        // enquanto o p n for o ultimo elemento, prox
        SNode *aux = L->begin;
        while(aux->next != NULL)
        {
            aux = aux->next; 
        }
        // neste momento o aux aponta para o ultimo elemento da linkedlist
        // corrige o encadeamento
        aux->next = p;
    }
    L->size++;
}

void print_LL(LinkedList *L)
{
    SNode *p = L->begin;
    printf("L -> ");

    while(p != NULL)
    {
        printf("%d -> ", p->val);
        p = p->next;
    }
    printf("NULL\n");
}

int main()
{
    LinkedList *lista;
    LinkedList_create(lista);
    add_first(lista, 1);
    add_first(lista, 0);
    add_last(lista, 2);

    print_LL(lista);


    return 0;
}
