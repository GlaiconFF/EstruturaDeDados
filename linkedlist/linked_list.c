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

// inserir ordenado
// pesquisa (se num existe, print posicao)
// remover algum elemento
// implementar na linkedlist fim lista



void pesquisar(LinkedList *L, int find)
{
    SNode *p = L->begin;
    printf("\nPesquisando numero %d na lista:", find);

    while(p != NULL)
    {
        if(p->val == find)
        {
            printf("\nNumero %d foi encontrado\n", p->val);
            break;
        }
        p = p->next;
    }
        if(p == NULL)
        printf("\nNumero %d nao foi encontrado\n", find);
}


void remover(LinkedList *L, int find)
{
    SNode *p = L->begin;
    SNode *aux;
    SNode *remover = NULL;

    printf("\nRemovendo numero %d da lista\n", find);

    while(p != NULL)
    {
        if(p->val == find && p->next == NULL)
        {
            free(p->val);
            break;
        }

        if(find == L->begin)
        {
            printf("as");
            free(p->val);
            break;
        }

        else
        {
            aux = p->next;
            break;
        }
        p = p->next;
    }

    p = aux;
    p->next = NULL;

}




//aux = aux->next; 

//aux->next = p;

//aux = p->next;

//p->next = aux;


void teste(LinkedList *L)
{
    SNode *p = L->begin;
    int i = 0;
    printf("\nL ");

    while(i < 5)
    {
        printf("-> %d ", p->val);
        p = p->next;
        i++;
    }
    printf("-> NULL\n");
}




void print_LL(LinkedList *L)
{
    SNode *p = L->begin;
    printf("\nL -> ");

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

    // pesquisar(lista, 0);
    // pesquisar(lista, 1);
    // pesquisar(lista, 2);
    // pesquisar(lista, 3);

    remover(lista, 0);
    pesquisar(lista, 0);
    pesquisar(lista, 2);

    teste(lista);


    return 0;
}