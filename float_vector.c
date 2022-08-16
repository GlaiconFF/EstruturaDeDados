//ARQUIVO IMPLEMENTACOES
#include "float_vector.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct float_vector {
    int capacity; // numero maximo de elementos
    int size; // quantidade atual de elementos
    float *data; // vetor de floats
};

/**
 * @brief Cria (aloca) um vetor de float com uma dada capacidade
 * 
 * @param capacity Capacidade do vetor
 * @return FloatVector* ponteiro de um vetor de floats
 */

FloatVector *create (int tam){

    FloatVector *vet = (FloatVector *)calloc(1, sizeof(FloatVector));
    vet->capacity = tam;
    vet->size = 0;
    vet->data = (float*) calloc(vet->capacity, sizeof(float));

    return vet;
}

void destroy(FloatVector **vet_ref){
    FloatVector *vet = *vet_ref;
    free(vet->data);
    free(vet);
    *vet_ref = NULL;
}

int size(const FloatVector *vector){
    return vector->size;
}

int capacity(const FloatVector *vector){
    return vector->capacity;
}

float at(const FloatVector *vector, int pos){
    if(pos < 0 || pos >= vector->size){
        fprintf(stderr, "Error: Invalid position!\n");
        fprintf(stderr, "Error: Index [%d] is out of bounds", pos);
        exit(EXIT_FAILURE);
    }
    
    return vector->data[pos];
}

float get(const FloatVector *vector, int index){
    return vector->data[index];
}

bool _isFull(const FloatVector *vector)
{
    return vector->size == vector->capacity;
}

void append(FloatVector *vector, float n){
    if(_isFull(vector)){
        fprintf(stderr, "Error: Vector in append!\nVector is full!");
        exit(EXIT_FAILURE);
    }
    vector->data[vector->size++] = n;
}   

//void print(const FloatVector *vector){}

