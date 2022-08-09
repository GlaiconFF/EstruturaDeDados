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
    int vetor[T], troca, comp;

    for(int i = 0; i < T; i++)
    {
        vetor[i] = rand() % 10;
    } 

    printVector(vetor);
    printf("\n");

    
    troca, comp = selection(vetor, T);
    
    printVector(vetor);

    printf("%d, %d\n", troca, comp);

    return 0;
}

//salvar em arquivo - github

void swap(int *a, int *b)
{
    int aux = *a;
    *a = *b;
    *b = aux;
}

int selection(int vetor[], int size)
{
    int k = 0, l = 0;

        for(int i = 0; i < T; i++)
        {
            int menor = i;

            for(int j = i; j < T; j++)
            {
                if(vetor[j] < vetor[menor])
                {   
                    menor = j;
                }  
            }
            if(vetor[menor] < vetor[i])
            {
                swap(&vetor[menor], &vetor[i]);
                k++;
                l++;
            }   
        }
        return (k, l);
}

void printVector(const int *vetor)
{
    for(int i = 0; i < T; i++)
    {
        printf("Vetor[%d] = %d\n", i, vetor[i]);
    }
}