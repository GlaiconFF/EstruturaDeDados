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
#include <time.h>
#define T 50000

int main()
{
    int vetor[T], troca, comp, var, cloc;

    double tempo = 0.0;
    clock_t inicio = clock();
    
    for(int i = 0; i < T; i++)
    {
        vetor[i] = rand() % 500000;
    } 

    //printVector(vetor);

    //printf("\n");

    troca = selection(vetor, T);

    printVector(vetor);

    printf("Numero de trocas: %d\n", troca);

    clock_t final = clock();
    tempo += (double)(final - inicio) / CLOCKS_PER_SEC;
    printf("O tempo decorrido foi de %f segundos", tempo);

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

    int k = 0;

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
            }   
        }
    return (k);
}

void printVector(const int *vetor)
{
    for(int i = 0; i < T; i++)
    {
        printf("Vetor[%d] = %d\n", i, vetor[i]);
    }
}
