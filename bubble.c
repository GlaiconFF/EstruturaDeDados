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
    double tempo = 0.0;
    clock_t inicio = clock();

    int vetor[T], troca, var;
    unsigned long int comp;

    for(int i = 0; i < T; i++)
    {
        vetor[i] = rand() % 50000;
    } 

    bubble(vetor, T, &troca, &comp); 
    
    printf("Numero de trocas: %d\n", troca);
    printf("Numero de comparacoes: %ld\n", comp);

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

void bubble(int vetor[], int size, int *troca, unsigned long int *comp)
{
    int k = 0;
    unsigned long int l = 0;

    for (int i = 0; i < size-1; i++)
    {
        for(int j = 0; j < size-1; j++)
        {
            if(vetor[j] > vetor[j+1])
            {   
                swap(&vetor[j], &vetor[j+1]);
                k++;
            }
            l++;
        }
    }
    *troca = k;
    *comp = l;
}

void printVector(const int *vetor)
{
    for(int i = 0; i < T; i++)
    {
        printf("Vetor[%d] = %d\n", i, vetor[i]);
    }
}
