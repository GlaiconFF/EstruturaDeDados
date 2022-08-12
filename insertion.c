//qtd.trocas
//qtd.variacao
//qtd.comparacao
//tempo.execucao

//calcular com vetor de 50k, 100k e 500k

#include <stdlib.h>
#include <stdio.h>  
#include <time.h>
#define T 50000

int main()
{
    double tempo = 0.0;
    clock_t inicio = clock();

    int vetor[T], troca = 0, var, comp;

    for(int i = 0; i < T; i++)
    {
        vetor[i] = rand() % 50000;
    } 

    //printVector(vetor);

    //printf("\n");
    printVector(vetor);
    printf("\n");
    insertion(vetor, T, &troca, &comp); 

    //troca = bubble(vetor, T, troca);

    //printVector(vetor);
    
    printf("Numero de trocas: %d\n", troca);
    printf("Numero de comparacoes: %d\n", comp);

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

void insertion(int vetor[], int size, int *troca, int *comp)
{
    int k = 0, l = 0, j, e;
    
    for (int i = 1; i < size; i++)
    {
        e = vetor[i];
        j = i - 1;

        //while (j >= 0 && vetor[j] > e)

        while (vetor[j] > e)
        {
            swap(&vetor[j], &vetor[j+1]);
            k++;
            j--;
        }
        vetor[j + 1] = e; 
        l++;
    }
        printVector(vetor);
        printf("\n");
    
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
