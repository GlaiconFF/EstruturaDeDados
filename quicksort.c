#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define T 50000

int main ()
{
    double tempo = 0.0;
    clock_t inicio = clock();

    int vetor[T], troca = 0, var, comp;
    
    for (int i = 0; i < T; i++)
    {
        vetor[i] = rand() %100;
    }
    
    quicksort(vetor, 0, T);

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

void quicksort(int *vetor, int inicio, int final)
{
    int pi;
    if(final > inicio)
    {
        pi = part(vetor, inicio, final);
        quicksort(vetor, inicio, pi - 1);
        quicksort(vetor, pi + 1, final);
    }    
}

int part(int *vetor, int inicio, int final)
{
    int esq = inicio, dir = final, pi = vetor[inicio];

    while(dir > esq)
    {
        while(vetor[esq] <= pi && esq <= final)
        {
            esq++;
        }
        while(vetor[dir] > pi && dir >= inicio)
        {
            dir--;
        }

        if(esq < dir)
        {
            swap(&vetor[dir], &vetor[esq]);
        }
    }
    vetor[inicio] = vetor[dir];
    vetor[dir] = pi;
    return dir;
}

void printVector(const int *vetor)
{
    for(int i = 0; i < T; i++)
    {
        printf("Vetor[%d] = %d\n", i, vetor[i]);
    }
}
