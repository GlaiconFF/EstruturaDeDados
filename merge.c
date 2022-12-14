#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define T 50000

int main (){

    double tempo = 0.0;
    clock_t inicio = clock();

    int arr[T], troca = 0, var, comp;

    for(int i = 0; i < T; i++)
    {
        arr[i] = rand() % 100;
    } 

    mergesort(arr, 0, T-1);

    clock_t final = clock();
    tempo += (double)(final - inicio) / CLOCKS_PER_SEC;
    printf("O tempo decorrido foi de %f segundos", tempo);
    
    return 0;
}

int mergesort(int arr[], int inicio, int fim)
{
    if(inicio < fim)
    {
        int meio = inicio + (fim - inicio) / 2;
        mergesort(arr, inicio, meio);
        mergesort(arr, meio + 1, fim);
        merge(arr, inicio, meio, fim);
    }
}

void merge(int arr[], int inicio, int meio, int fim)
{
    int n1 = meio - inicio + 1;
    int n2 = fim - meio;

    int L[n1];
    int R[n2];

    for (int i = 0; i < n1; i++)
    {
        L[i] = arr[inicio + i];
    }
    for (int j = 0; j < n2; j++)
    {
        R[j] = arr[meio + 1 + j];
    }

    int i = 0, j = 0, k = inicio;
    
    while(i < n1 && j < n2)
    {
        if(L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        
        else
        {
            arr[k] = R[j];
            j++;
        }

        k++;
    }

    while( i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;

    }

    while( j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void printVector(const int *arr)
{
    for(int i = 0; i < T; i++)
    {
        printf("Vetor[%d] = %d\n", i, arr[i]);
    }
}
