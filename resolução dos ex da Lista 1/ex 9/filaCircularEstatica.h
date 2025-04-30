#ifndef FILA_CIRCULAR_ESTATICA_H
#define FILA_CIRCULAR_ESTATICA_H

#define TAM_MAX 1000

#include <stdlib.h>
#include <stdio.h>

typedef int TipoItem;

// Fila Estática Circular
typedef struct {
    TipoItem vet[TAM_MAX];
    int inicio, fim;  // índices: início aponta ao próximo elemento a desenfileirar, fim ao próximo a enfileirar
} FilaCircularEstatica;

FilaCircularEstatica* cria_fila_circular_estatica();
int vazia_circular_estatica(FilaCircularEstatica* f);
int cheia_circular_estatica(FilaCircularEstatica* f);
void enqueue_circular_estatica(FilaCircularEstatica* f, TipoItem x);
TipoItem* dequeue_circular_estatica(FilaCircularEstatica* f);
void imprimir_fila_circular_estatica(FilaCircularEstatica* f);

#endif
