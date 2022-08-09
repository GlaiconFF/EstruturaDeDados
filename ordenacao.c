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
#include <string.h>
#define TAM 8

int main()
{
    int vetor[TAM] = {7, 3, 0, 1, 3, 8, 2, 9};

    bubble(vetor, 8);

    for(int i = 0; i < 8; i++)
        {
            printf("vetor[%d]", vetor[i]);
        }

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

}










