#include "static_stack.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct _static_stack
{
    int *data;
    long capacity;
    long top
} StaticStack;

// alocar espaço da pilha e iniciar os parametros
StaticStack *StaticStack_create(long capacity)
{
    StaticStack *S = (StaticStack *)calloc(1, sizeof(StaticStack));

    S->capacity = capacity;
    S->top = -1; // lista vazia

    S->data = (int *)calloc(S->capacity, sizeof(int));

    return S;
}

void StaticStack_destroy(StaticStack **s_stack)
{
    StaticStack *S = *s_stack;
    
    free(S->data); // free no vetor
    free(S);
    s_stack = NULL; // retira o valor do ponteiro no programa main
}

bool StaticStack_isEmpty(StaticStack *S)
{
    return S->top == -1;
}

bool StaticStack_isFull(StaticStack *S)
{
    return S->top == S->capacity;
}

void StaticStack_push(StaticStack *S, long value)
{
    // verificar se está cheio
    // printar a msg de erro
    S->top++;
    S->data[S->top] = value;
}

int StaticStack_pop(StaticStack *S)
{
    // verificar se está vazio
    // printar msg de erro

    int aux = S->data[S->top]; // o elemento do topo da pilha
    S->top--;

    return aux;
}

long StaticStack_size(StaticStack *S)
{
    
}

int StaticStack_peek(StaticStack *S)
{

}

void StaticStack_print(const StaticStack *S)
{

}