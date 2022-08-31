#include <stdlib.h>
#include <stdio.h>  
#include <time.h>
#define T 50000

int main()
{
    double tempo = 0.0;
    clock_t inicio = clock();

    int vetor[T];
    unsigned long int comp, troca;
    
    for(int i = 0; i < T; i++)
    {
        vetor[i] = rand() % T;
    } 

    selection(vetor, T, &troca, &comp); 

    printf("Numero de trocas: %u\n", troca);
    printf("Numero de comparacoes: %u\n", comp);

    clock_t final = clock();
    tempo += (double)(final - inicio) / CLOCKS_PER_SEC;
    printf("O tempo decorrido foi de %f segundos", tempo);

    return 0;
}

void swap(int *a, int *b)
{
    int aux = *a;
    *a = *b;
    *b = aux;
}

void selection(int vetor[], int size, int *troca, long int *comp)
{
    unsigned long int k = 0, l = 0;

    for(int i = 0; i < T; i++)
    {
        int menor = i;

        for(int j = i; j < T; j++)
        {
            if(vetor[j] < vetor[menor])
            {   
                menor = j;
                l++;
            } 
        }

        if(vetor[menor] < vetor[i])
        {
            swap(&vetor[menor], &vetor[i]);
            k++; 
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
