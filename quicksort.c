#include <stdio.h>
#include <stdlib.h>
#define T 100

void swap(int *a, int *b)
{
    int aux = *a;
    *a = *b;
    *b = aux;
}

void quicksort(int *vet, int first, int final)
{
    int pi;
    if(final > first)
    {
        pi = part(vet, first, final);
        quicksort(vet, first, pi - 1);
        quicksort(vet, pi + 1, final);
    }    
}

// adicionar ultima parte

void printVector(const int *vetor)
{
    for(int i = 0; i < T; i++)
    {
        printf("Vetor[%d] = %d\n", i, vetor[i]);
    }

    for(int i = 0; i < T; i++)
    {
        printf("Vetor[%d] = %d\n", i, vetor[i]);
    }
}

int main ()
{

    int vet[T];
    
    for (int i = 0; i < T; i++)
    {
        vet[i] = rand() %100;
    }
    
    quicksort(vet, 0, T);
    printVector(&vet);

    return 0;
}
