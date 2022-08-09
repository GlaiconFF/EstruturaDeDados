//qtd.trocas
//qtd.variacao
//qtd.comparacao
//tempo.execucao

//calcular com vetor de 50k, 100k e 500k

//ordenacao.c
//ordenacao.h

//random number
//bubble sort
//selection sort

#include <stdlib.h>
#include <stdio.h>  
#include <string.h>
#define T 10

int main()
{
    int vetor[T], troca = 0, var = 0, comp = 0;

    for(int i = 0; i < T; i++)
    {
        vetor[i] = rand() % 1000;
    } 

    printVector(vetor);
    printf("\n");
    bubble(vetor, T);   

    printVector(vetor);

    return 0;
}

//salvar em arquivo - github

void swap(int *a, int *b)
{
    int aux = *a;
    *a = *b;
    *b = aux;
}

void bubble(int vetor[], int size)
{
    for (int i = 0; i < size-1; i++)
    {
        for(int j = 0; j < size-1; j++)
        {
            if(vetor[j] > vetor[j+1])
            {   
                swap(&vetor[j], &vetor[j+1]);
            }  
        }
    }
}

void printVector(const int *vetor)
{
    for(int i = 0; i < T; i++)
    {
        printf("Vetor[%d] = %d\n", i, vetor[i]);
    }
}
